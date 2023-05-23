#include <gtk/gtk.h>

struct RedoBtnArgs
{
    GtkWidget *canvas;
    struct FigureStack *figureStack;
    struct FigureStack *redoStack;
};

static void redo_button_clicked(GtkWidget *widget, gpointer data)
{

    // Cast the data pointer to the CallbackArgs structure
    struct RedoBtnArgs *args = (struct RedoBtnArgs *)data;

    // Accessing the arguments passed to the callback
    GtkWidget * canvas = args->canvas;
    struct FigureStack * figureStack = args->figureStack;
    struct FigureStack * redoStack = args->redoStack;

    // performing the redo
    transfer_figure(redoStack,figureStack);

    //redrawing the canvas for cleared output
    gtk_widget_queue_draw(canvas);

}

GtkWidget *createRedoButton(GtkWidget *canvas, struct FigureStack *figureStack,struct FigureStack *redoStack)
{
    // creating a button
    GtkWidget *button = gtk_button_new_with_label("Redo");

    // Create an image widget and load the icon file
    GtkWidget *image = gtk_image_new_from_file("/icons/undo.png");

    // Set the image widget as the button's label
    gtk_button_set_image(GTK_BUTTON(button), image);

    // adding arguments to structure;
    struct RedoBtnArgs *args = (struct RedoBtnArgs *)malloc(sizeof(struct RedoBtnArgs));

    args->canvas = canvas;
    args->figureStack = figureStack;
    args->redoStack = redoStack;

    g_signal_connect(button, "clicked", G_CALLBACK(redo_button_clicked), args);

    // Connect the enter and leave signals to change the cursor
    g_signal_connect(button, "enter-notify-event", G_CALLBACK(on_button_enter), NULL);
    g_signal_connect(button, "leave-notify-event", G_CALLBACK(on_button_leave), NULL);

    // Add a custom CSS class to the button
    gtk_style_context_add_class(gtk_widget_get_style_context(button), "btn");
    gtk_widget_set_size_request(button, 10, 20);
    return button;
}