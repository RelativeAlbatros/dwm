/* this time is inspried from the nord theme 
 * resource:
 * https://www.nordtheme.com/docs/colors-and-palettes */

/* colors, you can define as many as you want */
/* polar night */
static const char col_nord01[]      = "#2e3440"; 
static const char col_nord02[]      = "#3b4252"; 
static const char col_nord03[]      = "#434c5e";
static const char col_nord04[]      = "#4c566a";
/* white storm */
static const char col_nord05[]      = "#d8dee9";
static const char col_nord06[]      = "#e5e9f0";
static const char col_nord07[]      = "#eceff4";
/* frost */
static const char col_nord08[]      = "#8fbcbb";
static const char col_nord09[]      = "#88c0d0";
static const char col_nord10[]      = "#81a1c1";
static const char col_nord11[]      = "#5e81ac";
/* aurore */
static const char col_nord12[]      = "#bf616a"; // red
static const char col_nord13[]      = "#d08770"; // orange
static const char col_nord14[]      = "#ebcb8b"; // yellow
static const char col_nord15[]      = "#a3be8c"; // green
static const char col_nord16[]      = "#b48ead"; // magenta

/* default colors */
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";

/* scheme */
static const char *colors[][3]      = {
	/*                        fg         bg         border   */
	[SchemeNorm]      = { col_nord01, col_nord01,   col_nord01 },
	[SchemeSel]       = { col_nord01, col_nord02,   col_nord11 },
	[SchemeStatus]    = { col_nord10, col_nord02,   "#000000"  }, // Statusbar right {text,background,not used but cannot be empty}
	[SchemeTagsSel]   = { col_nord05, col_nord03,   "#000000"  }, // Tagbar left selected {text,background,not used but cannot be empty}
  [SchemeTagsNorm]  = { col_nord02, col_nord02,   "#000000"  }, // Tagbar left unselected {text,background,not used but cannot be empty}
  [SchemeInfoSel]   = { col_nord11, col_nord02,   "#000000"  }, // infobar middle  selected {text,background,not used but cannot be empty}
  [SchemeInfoNorm]  = { col_nord03, col_nord01,   "#000000"  }, // infobar middle  unselected {text,background,not used but cannot be empty}
};


