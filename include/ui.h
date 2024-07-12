#ifndef _UIH_
#define _UIH_

#include <stdbool.h>

#include <keys.h>
#include <sessions.h>
#include <users.h>

// should be ansi escape codes under \x1b[...m
// if not prepared accordingly, it might break
struct theme_colors {
    char *bg;
    char *fg;
    char *err;
    char *s_wl;
    char *s_xorg;
    char *s_shell;
    char *f_other;
    char *e_hostname;
    char *e_date;
    char *e_box;
    char *e_header;
    char *e_user;
    char *e_passwd;
    char *e_badpasswd;
    char *e_key;
};

// even if they're multiple bytes long
// they should only take up 1 char size on display
struct theme_chars {
    char *hb;
    char *vb;

    char *ctl;
    char *ctr;
    char *cbl;
    char *cbr;
};

struct theme {
    struct theme_colors colors;
    struct theme_chars chars;
};

struct functions {
    enum keys poweroff;
    enum keys reboot;
    enum keys refresh;
};

struct strings {
    char* f_poweroff;
    char* f_reboot;
    char* f_refresh;
    char* e_user;
    char* e_passwd;
    char* s_xorg;
    char* s_wayland;
    char* s_shell;
};

struct behavior {
    bool include_defshell;
};

struct config {
    struct theme theme;
    struct functions functions;
    struct strings strings;
    struct behavior behavior;
};

void setup(struct config);
int load(struct users_list*, struct sessions_list*);
void print_err(const char*);
void print_errno(const char*);

#endif
