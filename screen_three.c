#include <stdio.h>
#include<gtk/gtk.h>

#include "base_defs.h"

#include "screen_one.h"
#include "screen_two.h"
#include "screen_four.h"

int three_dbg=0;

static void hide_screen_three ( phdl_grp all_hdls ) {
  gtk_widget_hide( all_hdls->vbox_three );

  gtk_container_remove ( GTK_CONTAINER ( all_hdls->parentWin ) , all_hdls->vbox_three );

}

static void back_to_two ( GtkButton *button , gpointer data ) {
  phdl_grp all_hdls = (phdl_grp)data;

  hide_screen_three( all_hdls );

  create_screen_two ( all_hdls );
}

static void screen_four ( GtkButton *button , gpointer data ) {
  phdl_grp all_hdls = (phdl_grp)data;

  hide_screen_three( all_hdls );

  create_screen_four ( all_hdls );
}

int create_screen_three ( phdl_grp pall_hdls ) {

  GtkWidget *hbox , *hbox2 ;
  GtkWidget *label;
  GtkWidget *button;

  int rc = 0;

  if ( pall_hdls != NULL ) {
    if ( three_dbg ) {
      printf( "  >> E %s \n" , __FUNCTION__ );
      printf( "    dbg       = %d \n" , three_dbg );
      printf( "    parentWin = %p \n" , pall_hdls->parentWin );
    }
  }
  else {
     printf( "  >> E %s  , all_hdls = NULL !!! \n" , __FUNCTION__ );
  }

  if ( pall_hdls->vbox_three == NULL ) {
    pall_hdls->vbox_three = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);

    printf( "    vbox = %p  , %s L%4d \n" , pall_hdls->vbox_three , __FILE__ , __LINE__  );

    hbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 12);

    label = gtk_label_new (" SCREEN THREE");

    gtk_box_pack_start (GTK_BOX (hbox), label, TRUE, FALSE, 0);

    gtk_widget_show_all (hbox);

    gtk_container_add (GTK_CONTAINER ( pall_hdls->vbox_three ), hbox );

    hbox2 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 12);

    // simple button , TODO make a text_view
    button = gtk_button_new_with_label ("Back to 2");
    gtk_widget_set_valign ( button, GTK_ALIGN_CENTER);

    g_object_set ( button , "tooltip-text", "Click to go back to Two", NULL);
    g_signal_connect (button, "clicked",  G_CALLBACK ( back_to_two ), (gpointer) pall_hdls );

    gtk_box_pack_start (GTK_BOX ( hbox2 ), button, TRUE, FALSE, 0);

    // simple button , TODO make a text_view
    button = gtk_button_new_with_label ("screen four");
    gtk_widget_set_valign ( button, GTK_ALIGN_CENTER);
    gtk_box_pack_start (GTK_BOX ( hbox2 ), button, TRUE, FALSE, 0);

    g_object_set ( button , "tooltip-text", "Click to go to screen four", NULL);
    g_signal_connect (button, "clicked",  G_CALLBACK ( screen_four ), (gpointer) pall_hdls );

    g_object_ref ( pall_hdls->vbox_three );

    gtk_container_add (GTK_CONTAINER ( pall_hdls->vbox_three ), hbox2 );
  }  // if !all_hdls->vbox_three
  else {
    gtk_container_add (GTK_CONTAINER ( pall_hdls->parentWin ), pall_hdls->vbox_three );
  }
  gtk_widget_show_all ( pall_hdls->vbox_three );

  if ( three_dbg ) {
    printf( "  << Lv %s \n" , __FUNCTION__ );
  }

  return rc;
}  // create_screen_three

int create_screen_three_rtn( phdl_grp *all_hdls ) {
  int rc = 0;
  phdl_grp pall_hdls = *all_hdls;

  printf( "  E   *all_hdls = %p pall_hdls =%p \n" , *all_hdls , pall_hdls );
  rc = create_screen_three( pall_hdls );
  
  if ( pall_hdls != NULL ) {
    printf( "      pall_hdls->vbox_three = %p \n" , pall_hdls->vbox_three );
  } 
  *all_hdls = pall_hdls;
  
  printf( "  Lv   *all_hdls = %p pall_hdls =%p \n" , *all_hdls , pall_hdls );
  return rc;
}
