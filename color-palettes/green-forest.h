/* colors, you can define as many as you want */
static const char col_verdo[]       = "#006866";
static const char col_verdo2[]      = "#008e8b";
static const char col_verdo3[]      = "#097e7c";

/* default colors, shouldn't be changed */
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";

/* scheme */
static const char *colors[][3]      = {
	/*                        fg         bg         border   */
	[SchemeNorm]      = { col_gray3,  col_gray1,  col_gray2  },
	[SchemeSel]       = { col_gray4, col_verdo,  col_verdo  },
	[SchemeStatus]    = { col_gray3,  col_verdo,  "#000000"  }, // Statusbar right {text,background,not used but cannot be empty}
	[SchemeTagsSel]   = { col_gray4, col_verdo2, "#000000"  }, // Tagbar left selected {text,background,not used but cannot be empty}
  [SchemeTagsNorm]  = { col_gray4, col_verdo,  "#000000"  }, // Tagbar left unselected {text,background,not used but cannot be empty}
  [SchemeInfoSel]   = { col_gray4, col_verdo,  "#000000"  }, // infobar middle  selected {text,background,not used but cannot be empty}
  [SchemeInfoNorm]  = { col_gray3,  col_verdo,  "#000000"  }, // infobar middle  unselected {text,background,not used but cannot be empty}
};


