#include <stdio.h>
#include<gtk/gtk.h>

#include "base_defs.h"

#include "screen_one.h"
#include "screen_two.h"
#include "screen_three.h"

int two_dbg=0;

static void hide_screen_two ( phdl_grp all_hdls ) {
  gtk_widget_hide( all_hdls->vbox_two );

  gtk_container_remove ( GTK_CONTAINER ( all_hdls->parentWin ) , all_hdls->vbox_two );

}

static void back_to_one ( GtkButton *button , gpointer data ) {
  phdl_grp all_hdls = (phdl_grp)data;

  hide_screen_two( all_hdls );

  create_screen_one ( all_hdls );
}

static void screen_three ( GtkButton *button , gpointer data ) {
  phdl_grp all_hdls = (phdl_grp)data;

  hide_screen_two( all_hdls );

  create_screen_three ( all_hdls );
}

int create_screen_two ( phdl_grp pall_hdls ) {

  GtkWidget *hbox , *hbox2 ;
  GtkWidget *label;
  GtkWidget *button;

  int rc = 0;

  if ( pall_hdls != NULL ) {
    if ( two_dbg ) {
      printf( "  >> E %s \n" , __FUNCTION__ );
      printf( "    dbg       = %d \n" , two_dbg );
      printf( "    parentWin = %p \n" , pall_hdls->parentWin );
    }
  }
  else {
     printf( "  >> E %s  , all_hdls = NULL !!! \n" , __FUNCTION__ );
  }

  if ( pall_hdls->vbox_two == NULL ) {
    pall_hdls->vbox_two = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
    //gtk_container_add (GTK_CONTAINER ( pall_hdls->parentWin ), pall_hdls->vbox_two );

    printf( "    vbox = %p  , %s L%4d \n" , pall_hdls->vbox_two , __FILE__ , __LINE__  );

    hbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 12);

    label = gtk_label_new (" SCREEN TWO");

    gtk_box_pack_start (GTK_BOX (hbox), label, TRUE, FALSE, 0);

    gtk_widget_show_all (hbox);

    gtk_container_add (GTK_CONTAINER ( pall_hdls->vbox_two ), hbox );

    hbox2 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 12);

    // simple button , TODO make a text_view
    button = gtk_button_new_with_label ("Back to 1");
    gtk_widget_set_valign ( button, GTK_ALIGN_CENTER);

    g_object_set ( button , "tooltip-text", "Click to go back One", NULL);
    g_signal_connect (button, "clicked",  G_CALLBACK ( back_to_one ), (gpointer) pall_hdls );

    gtk_box_pack_start (GTK_BOX ( hbox2 ), button, TRUE, FALSE, 0);

    // simple button , TODO make a text_view
    button = gtk_button_new_with_label ("screen 3");
    gtk_widget_set_valign ( button, GTK_ALIGN_CENTER);
    gtk_box_pack_start (GTK_BOX ( hbox2 ), button, TRUE, FALSE, 0);

    g_object_set ( button , "tooltip-text", "Click to go to screen three", NULL);
    g_signal_connect (button, "clicked",  G_CALLBACK ( screen_three ), (gpointer) pall_hdls );

    g_object_ref ( pall_hdls->vbox_two );

    gtk_container_add (GTK_CONTAINER ( pall_hdls->vbox_two ), hbox2 );
  }  // if !all_hdls->vbox_two
  else {
    gtk_container_add (GTK_CONTAINER ( pall_hdls->parentWin ), pall_hdls->vbox_two );
  }
  gtk_widget_show_all ( pall_hdls->vbox_two );

  if ( two_dbg ) {
    printf( "  << Lv %s \n" , __FUNCTION__ );
  }

  return rc;
}  // create_screen_two

int create_screen_two_rtn( phdl_grp *all_hdls ) {
  int rc = 0;
  phdl_grp pall_hdls = *all_hdls;

  printf( "  E   *all_hdls = %p pall_hdls =%p \n" , *all_hdls , pall_hdls );
  rc = create_screen_two( pall_hdls );

  if ( pall_hdls != NULL ) {
    printf( "      pall_hdls->vbox_two = %p \n" , pall_hdls->vbox_two );
  }
  *all_hdls = pall_hdls;

  printf( "  Lv   *all_hdls = %p pall_hdls =%p \n" , *all_hdls , pall_hdls );
  return rc;
}
