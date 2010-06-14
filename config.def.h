/* settings */
static const int   DEFAULT_WIDTH  = 800;
static const int   DEFAULT_HEIGHT = 600;
static const float ZOOM_STEP      = 10;
static const float ZOOM_MIN       = 10;
static const float ZOOM_MAX       = 400;
static const float SCROLL_STEP    = 40;
static const float TRANSPARENCY   = 0.4;

/* completion */
static const char FORMAT_COMMAND[]     = "<b>%s</b>";
static const char FORMAT_DESCRIPTION[] = "<i>%s</i>";

/* directories and files */
static const char ZATHURA_DIR[]   = ".zathura";
static const char BOOKMARK_FILE[] = "bookmarks";

/* bookmarks */
static const char BM_PAGE_ENTRY[]  = "page";
static const char BM_PAGE_OFFSET[] = "offset";

/* look */
char* font                   = "monospace normal 9";
char* default_bgcolor        = "#000000";
char* default_fgcolor        = "#DDDDDD";
char* inputbar_bgcolor       = "#141414";
char* inputbar_fgcolor       = "#9FBC00";
char* statusbar_bgcolor      = "#000000";
char* statusbar_fgcolor      = "#FFFFFF";
char* completion_fgcolor     = "#DDDDDD";
char* completion_bgcolor     = "#232323";
char* completion_g_fgcolor   = "#DEDEDE";
char* completion_g_bgcolor   = "#FF00FF";
char* completion_hl_fgcolor  = "#232323";
char* completion_hl_bgcolor  = "#9FBC00";
char* notification_e_bgcolor = "#FF1212";
char* notification_e_fgcolor = "#FFFFFF";
char* notification_w_bgcolor = "#FFF712";
char* notification_w_fgcolor = "#000000";
char* recolor_darkcolor      = "#353535";
char* recolor_lightcolor     = "#DBDBDB";

char* search_highlight       = "#9FBC00";
char* select_text            = "#000000";

/* statusbar */
static const char DEFAULT_TEXT[] = "[No Name]";

/* printing */
#define LIST_PRINTER_COMMAND "lpstat -v | sed -n '/^.*device for \\(.*\\): .*$/s//\\1/p'"
#define PRINT_COMMAND "lp -d '%s' -P %s '%s'" /* printer / pages / file */

/* open uri */
#define URI_COMMAND "firefox '%s'" /* uri */

/* additional settings */
#define SHOW_SCROLLBARS 0
#define ADJUST_OPEN ADJUST_BESTFIT
#define RECOLOR_OPEN 0
#define SELECTION_STYLE POPPLER_SELECTION_GLYPH
#define GOTO_MODE GOTO_LABELS /* GOTO_DEFAULT, GOTO_LABELS, GOTO_OFFSET */

/* shortcuts */
Shortcut shortcuts[] = {
  /* mask,             key,               function,             mode,       argument */
  {GDK_CONTROL_MASK,   GDK_n,             sc_toggle_statusbar,  NORMAL,     {0} },
  {GDK_CONTROL_MASK,   GDK_m,             sc_toggle_inputbar,   NORMAL,     {0} },
  {0,                  GDK_F5,            sc_toggle_fullscreen, NORMAL,     {0} },
  {GDK_CONTROL_MASK,   GDK_q,             sc_quit,              -1,         {0} },
  {GDK_CONTROL_MASK,   GDK_c,             sc_abort,             -1,         {0} },
  {GDK_CONTROL_MASK,   GDK_i,             sc_recolor,           NORMAL,     {0} },
  {GDK_CONTROL_MASK,   GDK_d,             sc_scroll,            NORMAL,     { HALF_DOWN } },
  {GDK_CONTROL_MASK,   GDK_u,             sc_scroll,            NORMAL,     { HALF_UP } },
  {GDK_CONTROL_MASK,   GDK_f,             sc_scroll,            NORMAL,     { FULL_DOWN } },
  {GDK_CONTROL_MASK,   GDK_b,             sc_scroll,            NORMAL,     { FULL_UP } },
  {0,                  GDK_slash,         sc_focus_inputbar,    NORMAL,     { .data = "/" } },
  {GDK_SHIFT_MASK,     GDK_slash,         sc_focus_inputbar,    NORMAL,     { .data = "/" } },
  {GDK_SHIFT_MASK,     GDK_question,      sc_focus_inputbar,    NORMAL,     { .data = "?" } },
  {0,                  GDK_Tab,           sc_toggle_index,      NORMAL,     {0} },
  {0,                  GDK_Tab,           sc_toggle_index,      INDEX,      {0} },
  {0,                  GDK_J,             sc_navigate,          NORMAL,     { NEXT } },
  {0,                  GDK_K,             sc_navigate,          NORMAL,     { PREVIOUS } },
  {GDK_MOD1_MASK,      GDK_Right,         sc_navigate,          NORMAL,     { NEXT } },
  {GDK_MOD1_MASK,      GDK_Left,          sc_navigate,          NORMAL,     { PREVIOUS } },
  {0,                  GDK_O,             sc_switch_goto_mode,  NORMAL,     {0} },
  {0,                  GDK_space,         sc_navigate,          NORMAL,     { NEXT } },
  {0,                  GDK_Escape,        sc_abort,             -1,         {0} },
  {0,                  GDK_i,             sc_change_mode,       NORMAL,     { INSERT } },
  {0,                  GDK_v,             sc_change_mode,       NORMAL,     { VISUAL } },
  {0,                  GDK_m,             sc_change_mode,       NORMAL,     { ADD_MARKER } },
  {0,                  GDK_apostrophe,    sc_change_mode,       NORMAL,     { EVAL_MARKER } },
  {0,                  GDK_colon,         sc_focus_inputbar,    NORMAL,     { .data = ":" } },
  {0,                  GDK_o,             sc_focus_inputbar,    NORMAL,     { .data = ":open " } },
  {0,                  GDK_f,             sc_follow,            NORMAL,     {0} },
  {0,                  GDK_r,             sc_rotate,            NORMAL,     {0} },
  {0,                  GDK_R,             sc_reload,            NORMAL,     {0} },
  {0,                  GDK_h,             sc_scroll,            NORMAL,     { LEFT } },
  {0,                  GDK_j,             sc_scroll,            NORMAL,     { DOWN } },
  {0,                  GDK_k,             sc_scroll,            NORMAL,     { UP } },
  {0,                  GDK_l,             sc_scroll,            NORMAL,     { RIGHT } },
  {0,                  GDK_Left,          sc_scroll,            NORMAL,     { LEFT } },
  {0,                  GDK_Up,            sc_scroll,            NORMAL,     { UP } },
  {0,                  GDK_Down,          sc_scroll,            NORMAL,     { DOWN } },
  {0,                  GDK_Right,         sc_scroll,            NORMAL,     { RIGHT } },
  {0,                  GDK_n,             sc_search,            NORMAL,     { FORWARD } },
  {0,                  GDK_N,             sc_search,            NORMAL,     { BACKWARD } },
  {0,                  GDK_a,             sc_adjust_window,     NORMAL,     { ADJUST_BESTFIT } },
  {0,                  GDK_s,             sc_adjust_window,     NORMAL,     { ADJUST_WIDTH } },
  {0,                  GDK_BackSpace,     sc_change_buffer,     -1,         { DELETE_LAST } },
  {0,                  GDK_k,             sc_navigate_index,    INDEX,      { UP } },
  {0,                  GDK_j,             sc_navigate_index,    INDEX,      { DOWN } },
  {0,                  GDK_h,             sc_navigate_index,    INDEX,      { COLLAPSE } },
  {0,                  GDK_l,             sc_navigate_index,    INDEX,      { EXPAND } },
  {0,                  GDK_space,         sc_navigate_index,    INDEX,      { SELECT } },
  {0,                  GDK_Return,        sc_navigate_index,    INDEX,      { SELECT } },
  {0,                  GDK_F5,            sc_toggle_fullscreen, FULLSCREEN, {0} },
  {0,                  GDK_Left,          sc_navigate,          FULLSCREEN, { PREVIOUS } },
  {0,                  GDK_Up,            sc_navigate,          FULLSCREEN, { PREVIOUS } },
  {0,                  GDK_Down,          sc_navigate,          FULLSCREEN, { NEXT } },
  {0,                  GDK_Right,         sc_navigate,          FULLSCREEN, { NEXT } },
  {0,                  GDK_space,         sc_navigate,          FULLSCREEN, { NEXT } },
};

/* inputbar shortcuts */
InputbarShortcut inputbar_shortcuts[] = {
  /* mask,             key,               function,                  argument */
  {0,                  GDK_Escape,        isc_abort,                 {0} },
  {0,                  GDK_Up,            isc_command_history,       {0} },
  {0,                  GDK_Down,          isc_command_history,       {0} },
  {0,                  GDK_Tab,           isc_completion,            { NEXT } },
  {GDK_CONTROL_MASK,   GDK_Tab,           isc_completion,            { NEXT_GROUP } },
  {0,                  GDK_ISO_Left_Tab,  isc_completion,            { PREVIOUS } },
  {GDK_CONTROL_MASK,   GDK_ISO_Left_Tab,  isc_completion,            { PREVIOUS_GROUP } },
  {GDK_CONTROL_MASK,   GDK_w,             isc_string_manipulation,   { DELETE_LAST_WORD } },
};

/* mouse settings */
MouseScrollEvent mouse_scroll_events[] = {
  /* direction,      function,  argument */
  {GDK_SCROLL_LEFT,  sc_scroll, { LEFT } },
  {GDK_SCROLL_UP,    sc_scroll, { UP } },
  {GDK_SCROLL_DOWN,  sc_scroll, { DOWN } },
  {GDK_SCROLL_RIGHT, sc_scroll, { RIGHT } },
};

/* commands */
Command commands[] = {
  /* command,   abbreviation,   function,            completion,   description  */
  {"bmark",     "b",            cmd_bookmark,        0,            "Bookmark current page" },
  {"blist",     0,              cmd_open_bookmark,   cc_bookmark,  "List and open bookmark" },
  {"close",     "c",            cmd_close,           0,            "Close current file" },
  {"coffset",   0,              cmd_correct_offset,  0,            "Correct page offset" },
  {"delbmark",  0,              cmd_delete_bookmark, cc_bookmark,  "Bookmark current page" },
  {"export",    "e",            cmd_export,          cc_export,    "Export images or attached files" },
  {"info",      "i",            cmd_info,            0,            "Show information about the document" },
  {"open",      "o",            cmd_open,            cc_open,      "Open a file" },
  {"print",     "p",            cmd_print,           cc_print,     "Print the document" },
  {"rotate",    "r",            cmd_rotate,          0,            "Rotate the page" },
  {"set",       "s",            cmd_set,             cc_set,       "Set an option" },
  {"quit",      "q",            cmd_quit,            0,            "Quit zathura" },
  {"write",     "w",            cmd_save,            0,            "Save the document" },
};

/* buffer commands */
BufferCommand buffer_commands[] = {
  /* regex,        function,       argument */
  {"^gg$",         bcmd_goto,       { TOP } },
  {"^G$",          bcmd_goto,       { BOTTOM } },
  {"^[0-9]+G$",    bcmd_goto,       {0} },
  {"^zI$",         bcmd_zoom,       { ZOOM_IN } },
  {"^zO$",         bcmd_zoom,       { ZOOM_OUT } },
  {"^z0$",         bcmd_zoom,       { ZOOM_ORIGINAL } },
  {"^[0-9]+Z$",    bcmd_zoom,       { ZOOM_SPECIFIC } },
  {"^[0-9]+%$",    bcmd_scroll,     {0} },
};

/* special commands */
SpecialCommand special_commands[] = {
  /* identifier,   function,      a,   argument */
  {'/',            scmd_search,   1,   { DOWN } },
  {'?',            scmd_search,   1,   { UP } },
};

/* settings */
Setting settings[] = {
  /* name,                   variable,                        type,  render,  re-init, description */
  {"recolor",                &(Zathura.Global.recolor),       'b',   TRUE,    FALSE,   "Invert the image" },
  {"offset",                 &(Zathura.PDF.page_offset),      'i',   FALSE,   FALSE,   "Optional page offset" },
  {"font",                   &(font),                         's',   FALSE,   TRUE,    "The used font" },
  {"default_bgcolor",        &(default_bgcolor),              's',   FALSE,   TRUE,    "Default background color"},
  {"default_fgcolor",        &(default_fgcolor),              's',   FALSE,   TRUE,    "Default foreground color"},
  {"inputbar_bgcolor",       &(inputbar_bgcolor),             's',   FALSE,   TRUE,    "Inputbar background color"},
  {"inputbar_fgcolor",       &(inputbar_fgcolor),             's',   FALSE,   TRUE,    "Inputbar foreground color"},
  {"statusbar_bgcolor",      &(statusbar_bgcolor),            's',   FALSE,   TRUE,    "Statusbar background color"},
  {"statusbar_fgcolor",      &(statusbar_fgcolor),            's',   FALSE,   TRUE,    "Statusbar foreground color"},
  {"completion_bgcolor",     &(completion_bgcolor),           's',   FALSE,   TRUE,    "Completion background color"},
  {"completion_fgcolor",     &(completion_fgcolor),           's',   FALSE,   TRUE,    "Completion foreground color"},
  {"completion_g_bgcolor",   &(completion_g_bgcolor),         's',   FALSE,   TRUE,    "Completion (group) background color"},
  {"completion_g_fgcolor",   &(completion_g_fgcolor),         's',   FALSE,   TRUE,    "Completion (group) foreground color"},
  {"completion_hl_bgcolor",  &(completion_hl_bgcolor),        's',   FALSE,   TRUE,    "Completion (highlight) background color"},
  {"completion_hl_fgcolor",  &(completion_hl_fgcolor),        's',   FALSE,   TRUE,    "Completion (highlight) foreground color"},
  {"notification_e_bgcolor", &(notification_e_bgcolor),       's',   FALSE,   TRUE,    "Notification (error) background color"},
  {"notification_e_fgcolor", &(notification_e_fgcolor),       's',   FALSE,   TRUE,    "Notification (error) foreground color"},
  {"notification_w_bgcolor", &(notification_w_bgcolor),       's',   FALSE,   TRUE,    "Notification (warning) background color"},
  {"notification_w_fgcolor", &(notification_w_fgcolor),       's',   FALSE,   TRUE,    "Notification (warning) foreground color"},
  {"recolor_darkcolor",      &(recolor_darkcolor),            's',   FALSE,   TRUE,    "Recoloring (dark color)"},
  {"recolor_lightcolor",     &(recolor_lightcolor),           's',   FALSE,   TRUE,    "Recoloring (light color)"},
  {"search_highlight",       &(search_highlight),             's',   FALSE,   TRUE,    "Highlighted results"},
  {"select_text",            &(select_text),                  's',   FALSE,   TRUE,    "Rectangle of the selected text"},
};
