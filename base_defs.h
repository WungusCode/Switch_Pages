#ifndef _BASE_DEFS_H

#define _BASE_DEFS_H 1

#include <gtk/gtk.h>
#include <gmodule.h>

#define WIN_W 720
#define WIN_H 480

// keep at bottom
typedef struct _hdl_grp {
  GtkWidget *parentWin;
  GtkWidget *vbox_one;
  GtkWidget *vbox_two;
  GtkWidget *vbox_three;
  GtkWidget *vbox_four;

} hdl_grp, *phdl_grp;

#endif
