/* Original file positions and music track boundaries */
static const uint32 ob_track_frames[] = {
    285611u, 150u, 50363u, 59588u, 67783u, 76005u, 84203u, 97197u, 111341u, 120566u, 121167u, 122517u, 135504u, 148519u, 157744u, 158345u, 159696u, 172990u, 186113u, 195337u, 195938u, 197288u, 210078u, 223054u, 232279u, 232880u, 234230u, 247152u, 260167u, 269392u, 269993u, 271344u
};

static const OB_DATA_FILE ob_data_files[] = {
    {"BLANK2.BIN", 271194u, 29218816u, 2048u, 0u},
#if !defined(AP_WEB)
    {"FMV/DOLBY.STR", 47229u, 4470784u, 2352u, 44u},
    {"FMV/INTRO.STR", 24u, 22460416u, 2352u, 44u},
    {"FMV/LOGO.STR", 10991u, 1613824u, 2048u, 0u},
    {"FMV/LOSE.STR", 11779u, 2160640u, 2352u, 44u},
    {"FMV/PSYGLOGO.STR", 12834u, 2828288u, 2352u, 44u},
    {"FMV/WIN.STR", 14215u, 24082432u, 2352u, 44u},
#endif
    {"FRONT.BIN", 49412u, 65600u, 2048u, 0u},
    {"GAME.BIN", 49445u, 300879u, 2048u, 0u},
    {"MOVIE.BIN", 49592u, 76552u, 2048u, 0u},
    {"RES.RDA", 25975u, 24916u, 2048u, 0u},
    {"RES.RDR", 25988u, 76u, 2048u, 0u},
    {"RES.RDT", 25989u, 43498036u, 2048u, 0u},
};
