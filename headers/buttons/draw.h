#include <gtk/gtk.h>
#include "buttons.h"

static void drawing_button_clicked(GtkWidget *widget, gpointer data)
{
    g_print("Button clicked!\n");
}

GtkWidget *createDrawButton()
{
    // creating a button
    GtkWidget *button = gtk_button_new_with_label("Draw");
    g_signal_connect(button, "clicked", G_CALLBACK(drawing_button_clicked), NULL);

    // Connect the enter and leave signals to change the cursor
    g_signal_connect(button, "enter-notify-event", G_CALLBACK(on_button_enter), NULL);
    g_signal_connect(button, "leave-notify-event", G_CALLBACK(on_button_leave), NULL);

    // Add a custom CSS class to the button
    gtk_style_context_add_class(gtk_widget_get_style_context(button), "btn");
    gtk_widget_set_size_request(button, 20, 30);
    return button;
}