#include <gtk/gtk.h>
#include "../buttons/draw.h"
#include "../buttons/clear.h"
#include "figureSelect.h"
#include "../canvas/canva.h"
#include "entryBox.h"

GtkWidget *createSideBar(GtkWidget *window)
{
	GtkWidget *contentArea;
	GtkWidget *hpaned;
	GtkCssProvider *cssProvider;

	GtkWidget *sidebar = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_style_context_add_class(gtk_widget_get_style_context(sidebar), "sidebar");
	GtkWidget *tools_Label = gtk_label_new("TOOLS");
	gtk_box_pack_start(GTK_BOX(sidebar),tools_Label , FALSE, FALSE, 0);
	gtk_style_context_add_class(gtk_widget_get_style_context(tools_Label), "head-label");

	
	// creating a select combo box
	GtkWidget *entryBox = createEntryBox();
	GtkWidget *figure_combo = createComboBox(window,entryBox);

	// adding figure combo box and entry box in sidebar
	gtk_box_pack_start(GTK_BOX(sidebar), figure_combo, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(sidebar), entryBox, FALSE, FALSE, 0);


	contentArea = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

	// adding the canvas into content area
	GtkWidget *canvas = createCanvas();
	GtkWidget *canvas_Label = gtk_label_new("CANVAS");
	gtk_style_context_add_class(gtk_widget_get_style_context(canvas_Label), "head-label");
	gtk_box_pack_start(GTK_BOX(contentArea),canvas_Label , FALSE, FALSE, 0);
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




// int main(int argc, char *argv[]) {
//     gtk_init(&argc, &argv);

//     GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
//     g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

//     GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
//     gtk_container_add(GTK_CONTAINER(window), box);

//     GtkWidget *sidebar = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
//     gtk_box_pack_start(GTK_BOX(box), sidebar, FALSE, FALSE, 0);

//     GtkListStore *model = gtk_list_store_new(1, G_TYPE_STRING);
//     GtkTreeIter iter;

//     // Add items to the combo box
//     gtk_list_store_append(model, &iter);
//     gtk_list_store_set(model, &iter, 0, "Circle", -1);

//     gtk_list_store_append(model, &iter);
//     gtk_list_store_set(model, &iter, 0, "Rectangle", -1);

//     GtkWidget *combo_box = gtk_combo_box_new_with_model(GTK_TREE_MODEL(model));
//     GtkCellRenderer *renderer = gtk_cell_renderer_text_new();
//     gtk_cell_layout_pack_start(GTK_CELL_LAYOUT(combo_box), renderer, TRUE);
//     gtk_cell_layout_set_attributes(GTK_CELL_LAYOUT(combo_box), renderer, "text", 0, NULL);

//     gtk_box_pack_start(GTK_BOX(box), combo_box, FALSE, FALSE, 0);
//     g_signal_connect(combo_box, "changed", G_CALLBACK(on_combo_box_changed), sidebar);

//     gtk_widget_show_all(window);
//     gtk_main();

//     return 0;
// }
