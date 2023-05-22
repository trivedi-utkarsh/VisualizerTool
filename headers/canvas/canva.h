#include <gtk/gtk.h>
#include <math.h>

void draw_arrow_head(cairo_t *cr, double x1, double y1, double x2, double y2, double arrow_size)
{
    double angle = atan2(y2 - y1, x2 - x1);
    cairo_move_to(cr, x2, y2);
    cairo_rel_line_to(cr, -arrow_size * cos(angle - M_PI / 6), -arrow_size * sin(angle - M_PI / 6));
    cairo_move_to(cr, x2, y2);
    cairo_rel_line_to(cr, -arrow_size * cos(angle + M_PI / 6), -arrow_size * sin(angle + M_PI / 6));
    cairo_stroke(cr);
}

gboolean draw_on_canvas(GtkWidget *widget, cairo_t *cr, gpointer data)
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
        cairo_move_to(cr, i, 0.0);    // Starting point
        cairo_line_to(cr, i, height); // Ending point
        cairo_stroke(cr);
    }

    // locating the center
    int cx = (int)((width / spacing) / 2) * spacing;
    int cy = (int)((height / spacing) / 2) * spacing;

    // creating vertical dark line
    cairo_set_source_rgb(cr, 0.40, 0.40, 0.40);
    cairo_move_to(cr, cx, 20.0);
    cairo_line_to(cr, cx, height - 20);
    cairo_stroke(cr);

    // for down arrow
    draw_arrow_head(cr, cx, 20.0, cx, height - 20, 10);

    // for up arrow
    draw_arrow_head(cr, cx, height - 20, cx, 20.0, 10);

    // creating horizontal dark line
    cairo_move_to(cr, 30.0, cy);
    cairo_line_to(cr, width - 30, cy);
    cairo_stroke(cr);

    // creating left arrow
    draw_arrow_head(cr, width - 30, cy, 30.0, cy, 10);

    // creating right arrow
    draw_arrow_head(cr, 30.0, cy, width - 30, cy, 10);


    gtk_style_context_get_color(context, gtk_style_context_get_state(context), &color);
    gdk_cairo_set_source_rgba(cr, &color);

    cairo_fill(cr);
    
    drawFigures(data,cr,cx,cy);


    return FALSE;
}

GtkWidget *createCanvas(struct FigureStack * figureStack)
{
    GtkWidget *drawing_area = gtk_drawing_area_new();

    g_signal_connect(G_OBJECT(drawing_area), "draw", G_CALLBACK(draw_on_canvas),figureStack);
    return drawing_area;
}