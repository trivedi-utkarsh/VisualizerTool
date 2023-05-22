#include <gtk/gtk.h>
#include <stdlib.h>
#include "buttons.h"

// Custom structure to hold the drawing callback arguments
struct Draw_CallbackArgs {
    struct FigureNode *canvasFigures;
    GtkWidget *entry_box;
    GtkWidget *figure_combo;
    GtkWidget *canvas;
};

// Callback function to handle the "Draw" button click event
void drawing_button_clicked(GtkButton *button, gpointer data)
{


    // Cast the data pointer to the CallbackArgs structure
    struct Draw_CallbackArgs *args = (struct Draw_CallbackArgs *)data;

    // Accessing the arguments passed to the callback
    struct FigureNode *canvasFigures = args->canvasFigures;
    GtkWidget *entry_box = args->entry_box;
    GtkWidget *figure_combo = args->figure_combo;
    GtkWidget *canvas = args->canvas;

    // Using the passed arguments as needed
    // Retrieve the input dimensions from the text entry widgets
    

    // to insert into canvasFigures the new figure

    // printf("%d \n", GTK_IS_BOX(entry_box));
    printf("%d \n", GTK_IS_COMBO_BOX(figure_combo));
    // printf("%d \n", GTK_IS_COMBO_BOX(figure_combo));

    // // we found out the type of figure
    // gtk_combo_box_set_active(GTK_COMBO_BOX(figure_combo), 1);
    // gint active = gtk_combo_box_get_active(figure_combo);

    // finding the dimensions of figure
    // GList *children = gtk_container_get_children(GTK_CONTAINER(entry_box));
    // GtkWidget *grid = GTK_WIDGET(children->data);
    // g_list_free(children);

    // // for storing figure dimensions
    // int fig_dimensions[6];

    // children = gtk_container_get_children(GTK_CONTAINER(grid));

    // // iterating over children
    // GList *iter;
    // int i =  0;
    // iter = g_list_next(iter);
    // for (iter = children; iter != NULL;)
    // {
    //     GtkWidget *entry_box = GTK_WIDGET(iter->data);
    //     const gchar *entry_text = gtk_entry_get_text(GTK_ENTRY(entry_box));
    //     gint entry_value = atoi(entry_text);
    //     fig_dimensions[i] = (int)entry_value;
    //     printf("%d \n",(int)entry_value);
    //     iter = g_list_next(iter);
    //     iter = g_list_next(iter);
    //     i++;
    // }

    // push_figure(&canvasFigures,fig_dimensions,(int)active);

    // // Force a redraw of the canvas widget
    gtk_widget_queue_draw(canvas);
}

GtkWidget *createDrawButton(GtkWidget *canvas, GtkWidget *figure_combo, GtkWidget *entry_box, struct FigureNode *canvasFigures)
{

    // creating a button
    GtkWidget *button = gtk_button_new_with_label("Draw");
    
    // setting arguments to pass in callback
    struct Draw_CallbackArgs * args = (struct Draw_CallbackArgs *)malloc(sizeof(struct Draw_CallbackArgs));
    args->canvasFigures = canvasFigures;
    args->entry_box = entry_box;
    args->figure_combo = figure_combo;
    args->canvas = canvas;

    g_signal_connect(button, "clicked", G_CALLBACK(drawing_button_clicked), args);

    // Connect the enter and leave signals to change the cursor
    g_signal_connect(button, "enter-notify-event", G_CALLBACK(on_button_enter), NULL);
    g_signal_connect(button, "leave-notify-event", G_CALLBACK(on_button_leave), NULL);

    // Adding a custom CSS class to the button
    gtk_style_context_add_class(gtk_widget_get_style_context(button), "btn");

    // setting button's height width
    gtk_widget_set_size_request(button, 20, 30);

    return button;
}