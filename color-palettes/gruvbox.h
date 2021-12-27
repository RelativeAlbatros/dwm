/* this time is inspried from the gruvbox theme  */

/* colors, you can define as many as you want */
static const char bg[]               = "#282828";
static const char bg2[]              = "#504945";
static const char bg3[]              = "#665c54";
static const char bg4[]              = "#7c6f64";
static const char green[]            = "#98971a";
static const char blue[]             = "#458588";
static const char aqua[]             = "#689d6a";
static const char yellow[]           = "#d79921";
static const char red[]              = "#cc241d";
static const char fg[]               = "#ebdbb2";
static const char fg2[]              = "#d5c4a1";

/* default colors */
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";

/* scheme */
static const char *colors[][3]      = {
    /*                    fg        bg      border   */
    [SchemeNorm]      = { fg,     bg,     bg3        },
    [SchemeSel]       = { fg,     bg,     yellow     },
    [SchemeStatus]    = { bg,    green,  "#000000"  }, // Statusbar right {text,background,not used but cannot be empty}
    [SchemeTagsSel]   = { fg,     blue,  "#000000"  }, // Tagbar left selected {text,background,not used but cannot be empty}
    [SchemeTagsNorm]  = { fg2,    bg,    "#000000"  }, // Tagbar left unselected {text,background,not used but cannot be empty}
    [SchemeInfoSel]   = { bg,     blue,  "#000000"  }, // infobar middle  selected {text,background,not used but cannot be empty}
    [SchemeInfoNorm]  = { bg,     bg,    "#000000"  }, // infobar middle  unselected {text,background,not used but cannot be empty}
};
