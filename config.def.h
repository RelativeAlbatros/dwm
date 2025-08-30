/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;          /* border pixel of windows */
static const unsigned int snap      = 32;         /* snap pixel */
static const unsigned int systraypinning = 0;     /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;      /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 1;     /* systray spacing */
static const int systraypinningfailfirst = 1;     /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;          /* 0 means no systray */
static const int showbar            = 1;          /* 0 means no bar */
static const int topbar             = 1;          /* 0 means bottom bar */
static const int splitstatus        = 1;          /* 1 for split status items */
static const char *splitdelim        = ";";       /* Character used for separating status */
static const int usealtbar          = 0;          /* 1 means use non-dwm status bar */
static const char *altbarclass      = "Polybar";  /* Alternate bar class name */
static const char *alttrayname      = "tray";     /* Polybar tray instance name */
static const char *altbarcmd        = "~/.xbar";  /* Alternate bar launch command */
static const unsigned int gappih    = 15;         /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;         /* vert inner gap between windows */
static const unsigned int gappoh    = 10;         /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;         /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;          /* 1 means no outer gap when there is only one window */
static const char *fonts[]          = { "Hurmit Nerd Font:size=10" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#2e3440";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#d8dee9";
static const char col_gray4[]       = "#e5e9f0";
static const char col_cyan[]        = "#5e81ac";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	// { "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

#include <X11/XF86keysym.h>

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "[@]",      spiral },
	{ "[\\]",     dwindle },
	{ "H[]",      deck },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "HHH",      grid },
	{ "###",      nrowgrid },
	{ "---",      horizgrid },
	{ ":::",      gaplessgrid },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ Mod4Mask,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ Mod4Mask|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ Mod4Mask|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ Mod4Mask|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static char fehbg[64];

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "rofi", "-dmenu", NULL };
static const char *roficmd[] = { "rofi", "-show", "run", NULL };
static const char *filebrowser_cmd[] = { "rofi", "-show", "filebrowser", NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *up_vol[]   = { "pactl", "set-sink-volume", "@DEFAULT_SINK@", "+5%",    NULL };
static const char *down_vol[] = { "pactl", "set-sink-volume", "@DEFAULT_SINK@", "-5%",    NULL };
static const char *mute_vol[] = { "pactl", "set-sink-mute",   "@DEFAULT_SINK@", "toggle", NULL };
static const char *brighter[] = { "brightnessctl", "set", "10%+", NULL };
static const char *dimmer[]   = { "brightnessctl", "set", "10%-", NULL };
static const char *ch_bg[]    = { fehbg, NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "120x34", NULL };

#include "movestack.c"
static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ Mod4Mask,                     XK_r,      spawn,          {.v = roficmd } },
	{ Mod4Mask,                     XK_e,      spawn,          {.v = filebrowser_cmd } },
	{ Mod4Mask,                     XK_Return, spawn,          {.v = termcmd } },
	{ Mod4Mask|ShiftMask,           XK_n,      spawn,          {.v = ch_bg } },
	{ Mod4Mask,                     XK_grave,  togglescratch,  {.v = scratchpadcmd } },
	{ Mod4Mask,                     XK_b,      togglebar,      {0} },
	{ Mod4Mask,                     XK_j,      focusstack,     {.i = +1 } },
	{ Mod4Mask,                     XK_k,      focusstack,     {.i = -1 } },
	{ Mod4Mask,                     XK_i,      incnmaster,     {.i = +1 } },
	{ Mod4Mask,                     XK_u,      incnmaster,     {.i = -1 } },
	{ Mod4Mask,                     XK_h,      setmfact,       {.f = -0.05} },
	{ Mod4Mask,                     XK_l,      setmfact,       {.f = +0.05} },
	{ Mod4Mask|ShiftMask,           XK_h,      setcfact,       {.f = +0.25} },
	{ Mod4Mask|ShiftMask,           XK_l,      setcfact,       {.f = -0.25} },
	{ Mod4Mask|ShiftMask,           XK_o,      setcfact,       {.f =  0.00} },
	{ Mod4Mask|ShiftMask,           XK_j,      movestack,      {.i = +1 } },
	{ Mod4Mask|ShiftMask,           XK_k,      movestack,      {.i = -1 } },
	{ Mod4Mask|ShiftMask,           XK_Return, zoom,           {0} },
	{ MODKEY|Mod4Mask,              XK_u,      incrgaps,       {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_u,      incrgaps,       {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_i,      incrigaps,      {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_i,      incrigaps,      {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_o,      incrogaps,      {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_o,      incrogaps,      {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_6,      incrihgaps,     {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_6,      incrihgaps,     {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_7,      incrivgaps,     {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_7,      incrivgaps,     {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_8,      incrohgaps,     {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_8,      incrohgaps,     {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_9,      incrovgaps,     {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_9,      incrovgaps,     {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_0,      togglegaps,     {0} },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },
	{ Mod4Mask,                     XK_Tab,    view,           {0} },
	{ Mod4Mask,                     XK_c,      killclient,     {0} },
	{ Mod4Mask,                     XK_t,      setlayout,      {.v = &layouts[0]} },
	{ Mod4Mask,                     XK_f,      setlayout,      {.v = &layouts[1]} },
	{ Mod4Mask|ShiftMask,           XK_m,      setlayout,      {.v = &layouts[2]} },
	{ Mod4Mask,                     XK_s,      setlayout,      {.v = &layouts[3]} },
	{ Mod4Mask,                     XK_d,      setlayout,      {.v = &layouts[4]} },
	// { Mod4Mask|ShiftMask,           XK_d,      setlayout,      {.v = &layouts[5]} },
	// stack is just nrowgrid with 1 nmaster
	// { Mod4Mask|ShiftMask,        XK_t,      setlayout,      {.v = &layouts[6]} },
	//{ Mod4Mask,                   XK_m,      setlayout,      {.v = &layouts[7]} },
	{ Mod4Mask,                     XK_g,      setlayout,      {.v = &layouts[8]} },
	{ Mod4Mask,                     XK_n,      setlayout,      {.v = &layouts[9]} },
	// { Mod4Mask,                     XK_g,      setlayout,      {.v = &layouts[10]} },
	// { Mod4Mask,                     XK_g,      setlayout,      {.v = &layouts[11]} },
	{ Mod4Mask,                     XK_m,      setlayout,      {.v = &layouts[12]} },
	// { Mod4Mask,                     XK_g,      setlayout,      {.v = &layouts[13]} },
	{ Mod4Mask,                     XK_space,  setlayout,      {0} },
	{ Mod4Mask|ShiftMask,           XK_space,  togglefloating, {0} },
	{ Mod4Mask,                     XK_0,      view,           {.ui = ~0 } },
	{ Mod4Mask|ShiftMask,           XK_0,      tag,            {.ui = ~0 } },
	{ Mod4Mask,                     XK_comma,  focusmon,       {.i = -1 } },
	{ Mod4Mask,                     XK_period, focusmon,       {.i = +1 } },
	{ Mod4Mask|ShiftMask,           XK_comma,  tagmon,         {.i = -1 } },
	{ Mod4Mask|ShiftMask,           XK_period, tagmon,         {.i = +1 } },
	{ 0,                            XF86XK_AudioMute,        spawn, {.v = mute_vol } },
	{ 0,                            XF86XK_AudioLowerVolume, spawn, {.v = down_vol } },
	{ 0,                            XF86XK_AudioRaiseVolume, spawn, {.v = up_vol } },
	{ 0,                            XF86XK_MonBrightnessDown, spawn, {.v = dimmer } },
	{ 0,                            XF86XK_MonBrightnessUp,   spawn, {.v = brighter } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ Mod4Mask,                     XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         Mod4Mask,       Button1,        movemouse,      {0} },
	{ ClkClientWin,         Mod4Mask,       Button2,        togglefloating, {0} },
	{ ClkClientWin,         Mod4Mask,       Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            Mod4Mask,       Button1,        tag,            {0} },
	{ ClkTagBar,            Mod4Mask,       Button3,        toggletag,      {0} },
};

