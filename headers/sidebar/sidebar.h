#include <gtk/gtk.h>
#include "../buttons/draw.h"
#include "../buttons/clear.h"
#include "figureSelect.h"
#include "../canvas/canva.h"

GtkWidget *createSideBar(GtkWidget *window)
{
	GtkWidget *sidebar;
	GtkWidget *contentArea;
	GtkWidget *hpaned;
	GtkCssProvider *cssProvider;

	sidebar = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_box_pack_start(GTK_BOX(sidebar), gtk_label_new("Tools"), FALSE, FALSE, 0);
	GtkWidget *figure_combo = createComboBox();
	gtk_box_pack_start(GTK_BOX(sidebar), figure_combo, FALSE, FALSE, 0);

	// creating bottom bar
	gtk_style_context_add_class(gtk_widget_get_style_context(sidebar), "sidebox");
	cssProvider = gtk_css_provider_new();
	gtk_css_provider_load_from_data(cssProvider, ".sidebox { border: 1px solid black;border-top:none; font-weight: bold; }\n", -1, NULL);
	gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

	contentArea = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

	// adding the canvas into content area
	GtkWidget *canvas = createCanvas();
	gtk_box_pack_start(GTK_BOX(contentArea), gtk_label_new("Canvas"), FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(contentArea), canvas, TRUE, TRUE, 0);

	// creating the bottom bar
	GtkWidget *bottom_bar = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
	gtk_style_context_add_class(gtk_widget_get_style_context(bottom_bar), "bottom-bar");
	// Set the height of the bottom bar 
    gtk_widget_set_size_request(bottom_bar, -1, 30); // Set the desired height

	// creating the draw button in the bottom bar
	GtkWidget *draw_button = createDrawButton();

	// creating the clear button in the bottom bar
	GtkWidget *clear_button = createClearButton();
	
	gtk_box_pack_start(GTK_BOX(bottom_bar), draw_button, FALSE, FALSE, 0); // Align to the start (left)
    gtk_box_pack_end(GTK_BOX(bottom_bar), clear_button, FALSE, FALSE, 0); // Align to the end (right)

	// Create the paned widget
	hpaned = gtk_paned_new(GTK_ORIENTATION_HORIZONTAL);

	// Add the sidebar and content area to the paned widget
	gtk_paned_pack1(GTK_PANED(hpaned), sidebar, FALSE, FALSE);
	gtk_paned_pack2(GTK_PANED(hpaned), contentArea, TRUE, FALSE);
	gtk_paned_set_position(GTK_PANED(hpaned), 400);

	// Creating another paned widget
	GtkWidget *vpaned = gtk_paned_new(GTK_ORIENTATION_VERTICAL);

	// Add the prev paned widget and bottombar to the new paned widget
	gtk_paned_pack1(GTK_PANED(vpaned), hpaned, TRUE, FALSE);
	gtk_paned_pack2(GTK_PANED(vpaned), bottom_bar, FALSE, FALSE);
	gtk_paned_set_position(GTK_PANED(vpaned), 800);

	// Add the paned widget to the main window
	gtk_container_add(GTK_CONTAINER(window), vpaned);

	return sidebar;
}
