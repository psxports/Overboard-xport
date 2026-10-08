#include "native_cd_toc.h"
#include "psx.h"
#include <stdio.h>
#include <string.h>

static uint8 toc_bcd(uint32 value)
{
    return (uint8)(((value / 10u) << 4) | (value % 10u));
}

static sint32 toc_position(CdlLOC *position, uint32 frame)
{
    uint32 minute = frame / 4500u;
    if (minute > 99u)
        return 0;
    position->minute = toc_bcd(minute);
    position->second = toc_bcd((frame / 75u) % 60u);
    position->sector = toc_bcd(frame % 75u);
    position->track = 0;
    return 1;
}

sint32 ob_native_cd_toc_init(const char *cue_path)
{
    FILE *cue;
    FILE *raw;
    CdlLOC toc[100];
    char line[1024], filename[768], path[1024], mode[64];
    const char *slash, *backslash;
    size_t directory;
    uint32 cumulative = 150u, file_frames = 0u;
    sint32 tracks = 0, pending_file = 0, have_index = 1;
    sint32 track, index, minute, second, frame;
    long bytes;
    if (!cue_path || !(cue = xport_fopen(cue_path, "rb")))
        return 0;
    slash = strrchr(cue_path, '/');
    backslash = strrchr(cue_path, '\\');
    if (!slash || (backslash && backslash > slash))
        slash = backslash;
    directory = slash ? (size_t)(slash - cue_path + 1) : 0u;
    memset(toc, 0, sizeof(toc));
    while (fgets(line, sizeof(line), cue))
    {
        if (sscanf(line, " FILE \"%767[^\"]\" BINARY", filename) == 1)
        {
            if (pending_file || !have_index || directory + strlen(filename) >= sizeof(path))
                goto invalid;
            cumulative += file_frames;
            memcpy(path, cue_path, directory);
            strcpy(path + directory, filename);
            raw = xport_fopen(path, "rb");
            if (!raw)
                goto invalid;
            if (fseek(raw, 0, SEEK_END) != 0)
            {
                fclose(raw);
                goto invalid;
            }
            bytes = ftell(raw);
            fclose(raw);
            if (bytes <= 0 || bytes % 2352L)
                goto invalid;
            file_frames = (uint32)(bytes / 2352L);
            pending_file = 1;
        }
        else if (sscanf(line, " TRACK %d %63s", &track, mode) == 2)
        {
            /* This disc uses one raw file per track with contained pregaps */
            if (!pending_file || track != tracks + 1 || track >= 100 ||
                (strcmp(mode, "AUDIO") != 0 && strcmp(mode, "MODE2/2352") != 0))
                goto invalid;
            tracks = track;
            pending_file = 0;
            have_index = 0;
        }
        else if (sscanf(line, " INDEX %d %d:%d:%d", &index, &minute, &second, &frame) == 4)
        {
            uint32 offset;
            if (!tracks || pending_file || index < 0 || index > 1 || minute < 0 ||
                second < 0 || second >= 60 || frame < 0 || frame >= 75)
                goto invalid;
            offset = (uint32)minute * 4500u + (uint32)second * 75u + (uint32)frame;
            if (offset >= file_frames)
                goto invalid;
            if (index == 1)
            {
                if (have_index || !toc_position(&toc[tracks], cumulative + offset))
                    goto invalid;
                have_index = 1;
            }
        }
        else
        {
            size_t text = strspn(line, " \t\r\n");
            if (line[text])
                goto invalid;
        }
    }
    if (ferror(cue) || tracks != 31 || pending_file || !have_index ||
        !toc_position(&toc[0], cumulative + file_frames))
        goto invalid;
    fclose(cue);
    return CdSetToc(toc, tracks);
invalid:
    fprintf(stderr, "Native CD TOC: invalid or unavailable original track metadata: %s\n", cue_path);
    fclose(cue);
    return 0;
}

static sint32 audio_track;

sint32 ob_native_cd_audio_track(void)
{
    /* Track identity follows the successful native WAV open */
    /* TODO Observe completion and absolute CD playback position when available */
    return audio_track;
}

sint32 ob_native_cd_audio_call(uint32 command, uint32 parameter, uint32 response, uint32 *result)
{
    static sint32 pending_track;
    if (command == 2u)
    {
        CdlLOC toc[32];
        sint32 tracks = CdGetToc(toc);
        pending_track = 0;
        if (!parameter || tracks != 31) return 0;
        for (sint32 track = 2; track <= tracks; ++track)
        {
            if (r_u8(parameter) == toc[track].minute && r_u8(parameter + 1u) == toc[track].second &&
                (r_u8(parameter + 2u) == 0u || r_u8(parameter + 2u) == toc[track].sector))
            {
                /* Original CdGetToc clears the sector byte; native music uses the converted track */
                /* TODO Preserve subsecond audio position when the native CD API supports seeking */
                pending_track = track;
                if (response) w_u8(response, CdlComplete);
                *result = 1u;
                return 1;
            }
        }
    }
    else if (command == 3u && !parameter && pending_track)
    {
        sint32 track = pending_track;
        *result = (uint32)CdPlay(1, &track, 0);
        if (*result) audio_track = track;
        if (response) w_u8(response, *result ? CdlComplete : CdlDiskError);
        return 1;
    }
    else if (command == 8u)
    {
        pending_track = 0;
        audio_track = 0;
    }
    return 0;
}
