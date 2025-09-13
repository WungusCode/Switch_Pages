#include <stdio.h>
#include<gtk/gtk.h>

#include "base_defs.h"

#include "screen_one.h"
#include "screen_two.h"
#include "screen_three.h"

int four_dbg=0;

static void hide_screen_four ( phdl_grp all_hdls ) {
  gtk_widget_hide( all_hdls->vbox_four );

  gtk_container_remove ( GTK_CONTAINER ( all_hdls->parentWin ) , all_hdls->vbox_four );

}

static void back_to_three ( GtkButton *button , gpointer data ) {
  phdl_grp all_hdls = (phdl_grp)data;

  hide_screen_four( all_hdls );

  create_screen_three ( all_hdls );
}

int create_screen_four ( phdl_grp pall_hdls ) {

  GtkWidget *hbox , *hbox2 ;
  GtkWidget *label;
  GtkWidget *button;

  int rc = 0;

  if ( pall_hdls != NULL ) {
    if ( four_dbg ) {
      printf( "  >> E %s \n" , __FUNCTION__ );
      printf( "    dbg       = %d \n" , four_dbg );
      printf( "    parentWin = %p \n" , pall_hdls->parentWin );
    }
  }
  else {
     printf( "  >> E %s  , all_hdls = NULL !!! \n" , __FUNCTION__ );
  }

  if ( pall_hdls->vbox_four == NULL ) {
    pall_hdls->vbox_four = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);

    printf( "    vbox = %p  , %s L%4d \n" , pall_hdls->vbox_four , __FILE__ , __LINE__  );

    hbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 12);

    label = gtk_label_new (" SCREEN FOUR");

    gtk_box_pack_start (GTK_BOX (hbox), label, TRUE, FALSE, 0);

    gtk_widget_show_all (hbox);

    gtk_container_add (GTK_CONTAINER ( pall_hdls->vbox_four ), hbox );

    hbox2 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 12);

    // simple button , TODO make a text_view
    button = gtk_button_new_with_label ("Back to 3");
    gtk_widget_set_valign ( button, GTK_ALIGN_CENTER);

    g_object_set ( button , "tooltip-text", "Click to go back to Three", NULL);
    g_signal_connect (button, "clicked",  G_CALLBACK ( back_to_three ), (gpointer) pall_hdls );

    gtk_box_pack_start (GTK_BOX ( hbox2 ), button, TRUE, FALSE, 0);

    g_object_ref ( pall_hdls->vbox_four );

    gtk_container_add (GTK_CONTAINER ( pall_hdls->vbox_four ), hbox2 );
  }  // if !all_hdls->vbox_four
  else {
    gtk_container_add (GTK_CONTAINER ( pall_hdls->parentWin ), pall_hdls->vbox_four );
  }
  gtk_widget_show_all ( pall_hdls->vbox_four );

  if ( four_dbg ) {
    printf( "  << Lv %s \n" , __FUNCTION__ );
  }

  return rc;
}  // create_screen_four

int create_screen_four_rtn( phdl_grp *all_hdls ) {
  int rc = 0;
  phdl_grp pall_hdls = *all_hdls;

  printf( "  E   *all_hdls = %p pall_hdls =%p \n" , *all_hdls , pall_hdls );
  rc = create_screen_four( pall_hdls );
  
  if ( pall_hdls != NULL ) {
    printf( "      pall_hdls->vbox_four = %p \n" , pall_hdls->vbox_four );
  } 
  *all_hdls = pall_hdls;
  
  printf( "  Lv   *all_hdls = %p pall_hdls =%p \n" , *all_hdls , pall_hdls );
  return rc;
}
