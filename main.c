#include <gtk/gtk.h>
#include "headers/main/window.h"
#include "headers/buttons/draw.h"
#include "headers/css/load.h"

// static void destroy(GtkWidget * widget , gpointer data){
// 	gtk_main_quit();
// }

int main(int argc, char* argv[])
{
	// Initialize GTK
	gtk_init(&argc, &argv);

	//creating a window
	GtkWidget *window = createWindow();

	//loading css
	load_CSS();

	//creating a button
	GtkWidget *draw_btn = createDrawButton(window);
	
	//show the main window
	gtk_widget_show_all(window);
	
	//start the main gtk loop
	gtk_main();

	return 0;
}

