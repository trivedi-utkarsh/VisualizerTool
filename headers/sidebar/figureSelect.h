#include <gtk/gtk.h>

void on_combo_changed(GtkComboBox *widget, gpointer user_data)
{
    GtkComboBoxText *combo = GTK_COMBO_BOX_TEXT(widget);
    gchar *selected_item = gtk_combo_box_text_get_active_text(combo);

    g_print("Selected item: %s\n", selected_item);

    g_free(selected_item);
}

GtkWidget *createComboBox()
{
    // Create a ComboBoxText
    GtkWidget *combo = gtk_combo_box_text_new();

    // Add items to the ComboBoxText
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo), "Circle");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo), "Rectangle");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo), "Line");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo), "Point");

    // Set the active item to the first one 
    gtk_combo_box_set_active(GTK_COMBO_BOX(combo), 0);

    // Connect the "changed" signal of the ComboBox to the callback function
    g_signal_connect(combo, "changed", G_CALLBACK(on_combo_changed), NULL);

    return combo;
}