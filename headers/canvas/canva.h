#include <gtk/gtk.h>

gboolean draw_something(GtkWidget *widget, cairo_t *cr, gpointer data)
{
    guint width, height;
    GdkRGBA color;
    gdk_rgba_parse(&color, "#FFFFFF");
    GtkStyleContext *context;

    context = gtk_widget_get_style_context(widget);

    width = gtk_widget_get_allocated_width(widget);
    height = gtk_widget_get_allocated_height(widget);

    gtk_render_background(context, cr, 0, 0, width, height);
    gdk_cairo_set_source_rgba(cr, &color);
    cairo_paint(cr);

    // creating coordinates lines
    int spacing = 20;
    cairo_set_line_width(cr, 2.0);
    cairo_set_source_rgb(cr, 0.90, 0.90, 0.90); // gray color
    
    // Draw horizontal lines
    for (int i = 0; i < height; i += spacing)
    {
        cairo_move_to(cr, 0.0, i);   // Starting point
        cairo_line_to(cr, width, i); // Ending point
        cairo_stroke(cr);
    }

    // Draw horizontal lines
    for (int i = 0; i < width; i += spacing)
    {
        cairo_move_to(cr, i, 0.0);   // Starting point
        cairo_line_to(cr, i, height); // Ending point
        cairo_stroke(cr);
    }

    // for creating a circle
    // cairo_arc(cr, width / 2.0, height / 2.0, MIN(width, height) / 2.0, 0, 2 * G_PI);

    gtk_style_context_get_color(context, gtk_style_context_get_state(context), &color);
    gdk_cairo_set_source_rgba(cr, &color);

    cairo_fill(cr);

    return FALSE;
}

GtkWidget *createCanvas()
{
    GtkWidget *drawing_area = gtk_drawing_area_new();
    g_signal_connect(G_OBJECT(drawing_area), "draw", G_CALLBACK(draw_something), NULL);
    return drawing_area;
}