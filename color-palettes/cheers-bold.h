/* this theme is inspired from firefox cheers */

/* colors, you can define as many as you want */
static const char col_yellow60[]        = "#d7b600";
static const char col_yellow70[]  			= "#a47f00";
static const char col_yellow80[]  			= "#715100";
static const char col_yellow90[]        = "#3e2800";

/* default colors */
static const char col_gray1[]       = "#4a4a4f";
static const char col_gray2[]       = "#38383d";
static const char col_gray3[]       = "#111111";
static const char col_gray4[]       = "#0c0c0d";
static const char col_cyan[]        = "#005577";

/* scheme */
static const char *colors[][3]      = {
	/*                        fg         bg         border   */
	[SchemeNorm]      = { col_gray3,    col_gray1,  col_yellow80},
	[SchemeSel]       = { col_yellow90, col_cyan,   col_yellow70},
	[SchemeStatus]    = { col_yellow70, col_gray3,   "#000000"  }, // Statusbar right {text,background,not used but cannot be empty}
	[SchemeTagsSel]   = { col_yellow70, col_gray4,   "#000000"  }, // Tagbar left selected {text,background,not used but cannot be empty}
  [SchemeTagsNorm]  = { col_yellow80, col_gray3,   "#000000"  }, // Tagbar left unselected {text,background,not used but cannot be empty}
  [SchemeInfoSel]   = { col_yellow60, col_gray3,   "#000000"  }, // infobar middle  selected {text,background,not used but cannot be empty}
  [SchemeInfoNorm]  = { col_yellow70, col_gray3,   "#000000"  }, // infobar middle  unselected {text,background,not used but cannot be empty}
};


