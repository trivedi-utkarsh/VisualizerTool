#include <gtk/gtk.h>
#include "buttons.h"

static void button_clicked(GtkWidget *widget, gpointer data)
{
    g_print("Button clicked!\n");
}

GtkWidget *createDrawButton(GtkWidget *window)
{
    // creating a fixed container
    GtkWidget *fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), fixed);

    // creating a event_box
    GtkWidget *event_box = gtk_event_box_new();
    gtk_fixed_put(GTK_FIXED(fixed), event_box, 50, 50);
    gtk_widget_set_size_request(event_box, 50, 30);

    // creating a button
    GtkWidget *button = gtk_button_new_with_label("Draw");
    gtk_container_add(GTK_CONTAINER(event_box), button);
    g_signal_connect(button, "clicked", G_CALLBACK(button_clicked), NULL);

    // Connect the enter and leave signals to change the cursor
    g_signal_connect(button, "enter-notify-event", G_CALLBACK(on_button_enter), NULL);
    g_signal_connect(button, "leave-notify-event", G_CALLBACK(on_button_leave), NULL);


    // Add a custom CSS class to the button
    gtk_style_context_add_class(gtk_widget_get_style_context(button), "btn");

    return button;
}