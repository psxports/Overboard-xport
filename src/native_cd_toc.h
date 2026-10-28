#ifndef OB_NATIVE_CD_TOC_H
#define OB_NATIVE_CD_TOC_H
#include "xport.h"
sint32 ob_native_cd_files_init(void);
sint32 ob_native_cd_toc_init(void);
sint32 ob_native_cd_audio_call(uint32 command, uint32 parameter, uint32 response, uint32 *result);
sint32 ob_native_cd_audio_track(void);
#endif
