#include "native_cd_toc.h"
#include "psx.h"
#include "psx_spu.h"
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

typedef struct OB_DATA_FILE
{
    const char *path;
    uint32 sector;
    uint32 size;
    uint32 sector_bytes;
    uint32 offset;
} OB_DATA_FILE;

#include "native_cd_files.inc"

static FILE *data_stream;
static const OB_DATA_FILE *data_file;

static void data_close(void *context)
{

    if (data_stream) fclose(data_stream);
    data_stream = NULL;
    data_file = NULL;
}

static sint32 data_open(const OB_DATA_FILE *file)
{
    char path[256];
    if (data_file == file && data_stream) return 1;
    data_close(NULL);
    snprintf(path, sizeof(path), "DATA/%s", file->path);
    data_stream = xport_fopen(path, "rb");
    if (!data_stream) return 0;
    data_file = file;
    return 1;
}

static CdlFILE *data_search(void *context, CdlFILE *result, const char *path)
{
    char name[256];
    size_t length = 0;
    const char *leaf = path;

    while (*path == '/' || *path == '\\') ++path;
    leaf = path;
    while (*path && *path != ';')
    {
        char c = *path++;
        if (length + 1u >= sizeof(name)) return NULL;
        if (c == '\\' || c == '/') { c = '/'; leaf = path; }
        if (c >= 'a' && c <= 'z') c -= 'a' - 'A';
        name[length++] = c;
    }
    if (*path && strcmp(path, ";1") != 0) return NULL;
    name[length] = 0;
    for (size_t i = 0; i < sizeof(ob_data_files) / sizeof(ob_data_files[0]); ++i)
    {
        const OB_DATA_FILE *file = &ob_data_files[i];
        if (strcmp(name, file->path) != 0) continue;
        if (!data_open(file)) return NULL;
        memset(result, 0, sizeof(*result));
        CdIntToPos((sint32)file->sector, &result->pos);
        result->size = file->size;
        snprintf(result->name, sizeof(result->name), "%s", leaf);
        return result;
    }
    return NULL;
}

static sint32 data_read(void *context, uint32 sector, uint8 buffer[2352], uint32 *sector_bytes)
{

    for (size_t i = 0; i < sizeof(ob_data_files) / sizeof(ob_data_files[0]); ++i)
    {
        const OB_DATA_FILE *file = &ob_data_files[i];
        uint32 relative, bytes;
        if (sector < file->sector) continue;
        relative = sector - file->sector;
        if (relative >= (file->size + 2047u) / 2048u) continue;
        if (!data_open(file)) return 0;
        if (fseek(data_stream, (long)(file->offset + relative * file->sector_bytes), SEEK_SET) != 0) return 0;
        bytes = file->sector_bytes;
        if (bytes == 2048u && file->size - relative * 2048u < bytes)
            bytes = file->size - relative * 2048u;
        memset(buffer, 0, 2352u);
        if (xport_fread(buffer + (file->sector_bytes == 2048u ? 24u : 0u), 1u, bytes, data_stream) != bytes) return 0;
        *sector_bytes = file->sector_bytes;
        return 1;
    }
    /* The transport prefetches past file boundaries before Pause completes */
    memset(buffer, 0, 2352u);
    *sector_bytes = 2048u;
    return 1;
}

sint32 ob_native_cd_files_init(void)
{
    const XPORT_CD_SOURCE source = {NULL, 49988u, data_read, data_search, data_close};
    return xport_cd_mount_source(&source);
}

sint32 ob_native_cd_toc_init(void)
{
    CdlLOC toc[100] = {0};
    for (uint32 i = 0; i < sizeof(ob_track_frames) / sizeof(ob_track_frames[0]); ++i)
        if (!toc_position(&toc[i], ob_track_frames[i])) return 0;
    return CdSetToc(toc, 31);
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
