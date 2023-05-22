#include <gtk/gtk.h>
#include <stdlib.h>
#include "headers/canvas/shapeStructure.h"
#include "headers/main/window.h"
#include "headers/css/load.h"
#include "headers/headings/titlebar.h"
#include "headers/sidebar/sidebar.h"

int main(int argc, char *argv[])
{
	// Initialize GTK
	gtk_init(&argc, &argv);

	// creating a window
	GtkWidget *window = createWindow();

	// creating title bar
	designTitleBar(window);

	// loading css
	load_CSS();

	// creating figure Stack to store figures
	struct FigureStack *figureStack = createFigureStack();

	// create sidebar
	GtkWidget *sidebar = createSideBar(window, figureStack);

	// show the main window
	gtk_widget_show_all(window);

	// start the main gtk loop
	gtk_main();

	return 0;
}