#include <gtk/gtk.h>

struct ClearBtnArgs
{
    GtkWidget *canvas;
    struct FigureStack *figureStack;
};

static void clear_button_clicked(GtkWidget *widget, gpointer data)
{

    // Cast the data pointer to the CallbackArgs structure
    struct ClearBtnArgs *args = (struct ClearBtnArgs *)data;

    // Accessing the arguments passed to the callback
    GtkWidget * canvas = args->canvas;
    struct FigureStack * figureStack = args->figureStack;

    // deleting all figures
    clear_figures(figureStack);

    //redrawing the canvas for cleared output
    gtk_widget_queue_draw(canvas);

}

GtkWidget *createClearButton(GtkWidget *canvas, struct FigureStack *figureStack)
{
    // creating a button
    GtkWidget *button = gtk_button_new_with_label("Clear");

    // adding arguments to structure;
    struct ClearBtnArgs *args = (struct ClearBtnArgs *)malloc(sizeof(struct ClearBtnArgs));
    args->canvas = canvas;
    args->figureStack = figureStack;

    g_signal_connect(button, "clicked", G_CALLBACK(clear_button_clicked), args);

    // Connect the enter and leave signals to change the cursor
    g_signal_connect(button, "enter-notify-event", G_CALLBACK(on_button_enter), NULL);
    g_signal_connect(button, "leave-notify-event", G_CALLBACK(on_button_leave), NULL);

    // Add a custom CSS class to the button
    gtk_style_context_add_class(gtk_widget_get_style_context(button), "btn");
    gtk_widget_set_size_request(button, 10, 20);
    return button;
}