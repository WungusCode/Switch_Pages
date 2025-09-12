#include <stdio.h>
#include<gtk/gtk.h>

#include "base_defs.h"

#include "screen_one.h"
#include "screen_two.h"

static void destroy( GtkWidget *widget,    gpointer   data );

int main(int argc, char* argv[]) {
  int rc = 0;

  GtkWidget* window;
  hdl_grp   all_hdls;
  phdl_grp  pall_hdls = NULL;

  pall_hdls = &all_hdls;

  gtk_init(&argc, &argv);

    // code
  pall_hdls->vbox_one        = NULL;
  pall_hdls->vbox_two        = NULL;
  pall_hdls->vbox_three      = NULL;
  pall_hdls->vbox_four       = NULL;

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  pall_hdls->parentWin = window;

  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_window_set_default_size (GTK_WINDOW (window), WIN_W, WIN_H );

  g_signal_connect (G_OBJECT (window), "destroy", G_CALLBACK (destroy), NULL);

  create_screen_one_rtn                (  &pall_hdls );
  create_screen_two_rtn                (  &pall_hdls );

  gtk_widget_show_all ( window );

  gtk_main();  // blocks until GTK terminates

  return rc;
} // main

static void destroy( GtkWidget *widget, gpointer   data ) {
  gtk_main_quit ();
}

