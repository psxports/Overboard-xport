#ifndef OB_MOVIE_PLAYER_H
#define OB_MOVIE_PLAYER_H
#include "xport.h"
uint32 ob_native_movie_dispatch(uint32 target, uint32 count, const uint32 *args);
uint32 ob_movie_8008E3B4(void);
uint32 ob_movie_8008DFE0(uint32 mode);
uint32 ob_movie_8008DF84(uint32 output, uint32 size);
uint32 ob_movie_8008E1F4(uint32 output, uint32 size);
uint32 ob_movie_8008E31C(void);
uint32 ob_movie_8008E284(void);
uint32 ob_movie_8008E160(uint32 input, uint32 size);
uint32 ob_movie_8008DF08(uint32 input, uint32 flags);
uint32 ob_movie_8008E064(uint32 option);
uint32 ob_movie_8008E3CC(uint32 message);
uint32 ob_movie_8008E530(uint32 input, uint32 output);
uint32 ob_movie_8008E500(uint32 limit);
#endif
