#include <gtk/gtk.h>

void on_combo_box_changed(GtkComboBox *combo_box, gpointer data)
{
    GtkWidget *entryBox = GTK_WIDGET(data); // parent widget

    GList *children = gtk_container_get_children(GTK_CONTAINER(entryBox));
    GList *iter;
    GtkWidget *entry_grid = GTK_WIDGET(children->data);
    g_list_free(children);

    gtk_widget_destroy(GTK_WIDGET(entry_grid)); // destroying the grid inside

    gint active = gtk_combo_box_get_active(combo_box);
    if (active >= 0)
    {
        int numBoxes = 0;
        gchar *labelText = NULL;

        char *arr[6]; // contains label
        char *placeholder_texts[6]; // contains placeholder texts

        switch (active)
        {
        case 1: // Circle
            numBoxes = 3;
            labelText = "Circle";
            arr[0] = "X:";
            placeholder_texts[0] = "x-coordinate";
            arr[1] = "Y:";
            placeholder_texts[1] = "y-coordinate";
            arr[2] = "R:";
            placeholder_texts[2] = "Radius";
            break;
        case 2: // Rectangle
            numBoxes = 4;
            labelText = "Rectangle";
            arr[0] = "X:";
            placeholder_texts[0]="x-coordinate";
            arr[1] = "Y:";
            placeholder_texts[1]="y-coordinate";
            arr[2] = "W:";
            placeholder_texts[2]="Width";
            arr[3] = "H:";
            placeholder_texts[3]="Height";
            break;
        case 3: // Triangle
            numBoxes = 6;
            labelText = "Triangle";
            arr[0] = "X1:";
            placeholder_texts[0] = "x1-coordinate";
            arr[1] = "Y1:";
            placeholder_texts[1] = "y1-coordinate";
            arr[2] = "X2:";
            placeholder_texts[2] = "x2-coordinate";
            arr[3] = "Y2:";
            placeholder_texts[3] = "y2-coordinate";
            arr[4] = "X3:";
            placeholder_texts[4] = "x3-coordinate";
            arr[5] = "Y3:";
            placeholder_texts[5] = "y3-coordinate";
            break;
        case 4: // Line
            numBoxes = 4;
            labelText = "Line";
            arr[0] = "X1:";
            placeholder_texts[0] = "x1-coordinate";
            arr[1] = "Y1:";
            placeholder_texts[1] = "y1-coordinate";
            arr[2] = "X2:";
            placeholder_texts[2] = "x2-coordinate";
            arr[3] = "Y2:";
            placeholder_texts[3] = "y2-coordinate";
            break;
        // Add more cases for other shapes
        default:
            break;
        }

        ;
        GtkWidget *newGrid = gtk_grid_new();
        gtk_grid_set_row_spacing(GTK_GRID(newGrid), 10);
        gtk_grid_set_column_spacing(GTK_GRID(newGrid), 10);
        gtk_container_set_border_width(GTK_CONTAINER(newGrid), 10);

        for (int i = 0; i < numBoxes; i++)
        {
            // Create a label
            GtkWidget *label = gtk_label_new((gchar *)arr[i]);
            gtk_grid_attach(GTK_GRID(newGrid), label, 0, i, 1, 1);
            // Create an entry box
            GtkEntry *entry = GTK_ENTRY(gtk_entry_new());
            gtk_entry_set_placeholder_text(entry, placeholder_texts[i]); // Set the placeholder text
            gtk_widget_set_name(GTK_WIDGET(entry), "my-entry-box");
            gtk_grid_attach(GTK_GRID(newGrid), GTK_WIDGET(entry), 1, i, 1, 1);
        }

        gtk_container_add(GTK_CONTAINER(entryBox), newGrid);

        gtk_widget_show_all(newGrid);
    }
}

GtkWidget *createComboBox(GtkWidget *window, GtkWidget *entryBox)
{
    GtkListStore *model = gtk_list_store_new(1, G_TYPE_STRING);
    GtkTreeIter iter;

    // Add items to the combo box
    gtk_list_store_append(model, &iter);
    gtk_list_store_set(model, &iter, 0, "Select Figure...", -1);

    gtk_list_store_append(model, &iter);
    gtk_list_store_set(model, &iter, 0, "CIRCLE", -1);

    gtk_list_store_append(model, &iter);
    gtk_list_store_set(model, &iter, 0, "RECTANGLE", -1);

    gtk_list_store_append(model, &iter);
    gtk_list_store_set(model, &iter, 0, "TRIANGLE", -1);

    gtk_list_store_append(model, &iter);
    gtk_list_store_set(model, &iter, 0, "LINE", -1);

    GtkWidget *combo_box = gtk_combo_box_new_with_model(GTK_TREE_MODEL(model));

    // Setting combobox select figure active
     gtk_combo_box_set_active(GTK_COMBO_BOX(combo_box), 0);

    GtkCellRenderer *renderer = gtk_cell_renderer_text_new();
    gtk_cell_layout_pack_start(GTK_CELL_LAYOUT(combo_box), renderer, TRUE);
    gtk_cell_layout_set_attributes(GTK_CELL_LAYOUT(combo_box), renderer, "text", 0, NULL);

    g_signal_connect(combo_box, "changed", G_CALLBACK(on_combo_box_changed), entryBox);

    return combo_box;
}