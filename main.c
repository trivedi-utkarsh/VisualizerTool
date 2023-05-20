#include <gtk/gtk.h>
#include "headers/main/window.h"
#include "headers/css/load.h"
#include "headers/headings/titlebar.h"
#include "headers/sidebar/sidebar.h"

// static void destroy(GtkWidget * widget , gpointer data){
// 	gtk_main_quit();
// }

// writing here to define

int main(int argc, char* argv[])
{
	// Initialize GTK
	gtk_init(&argc, &argv);

	//creating a window
	GtkWidget *window = createWindow();

	//creating title bar
	designTitleBar(window);

	//loading css
	load_CSS();

	//create sidebar
	GtkWidget *sidebar = createSideBar(window);

	//show the main window
	gtk_widget_show_all(window);
	
	//start the main gtk loop
	gtk_main();

	return 0;
}