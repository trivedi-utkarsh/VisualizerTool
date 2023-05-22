#include <gtk/gtk.h>
#include <math.h>

void draw_circle(cairo_t *cr, double x1, double y1, double r)
{

    cairo_set_source_rgb(cr, 0, 0, 0); // Black color
    cairo_set_line_width(cr, 1);

    // Draw the circle
    cairo_arc(cr, x1, y1, r, 0, 2 * G_PI);
    cairo_stroke(cr);
}

void draw_rectangle(cairo_t *cr, double x1, double y1, double width, double height)
{
    cairo_set_source_rgb(cr, 0, 0, 0); // Black color
    cairo_set_line_width(cr, 1);

    // draw rectangle
    cairo_rectangle(cr, x1, y1, width, height);
    cairo_stroke(cr);
}
void draw_line_two_point_form( cairo_t *cr,double x1, double y1, double x2, double y2)
{
    // Set the drawing color to black
    cairo_set_source_rgb(cr, 0, 0, 0);
    // Move to the first point of the
    cairo_move_to(cr, x1, y1);

    // Draw lines connecting the 
    cairo_line_to(cr, x2, y2);

    // Stroke the path to draw the outline 
    cairo_stroke(cr);
}
void traingle(cairo_t *cr,double x1, double y1, double x2, double y2,double x3,double y3){
     // Set the drawing color to black
    cairo_set_source_rgb(cr, 0, 0, 0);


// Move to the first point of the triangle
    cairo_move_to(cr, x1, y1);

    // Draw lines connecting the three points of the triangle
    cairo_line_to(cr, x2, y2);
    cairo_line_to(cr,x3, y3);
    cairo_line_to(cr, x1,y1);

    // Stroke the path to draw the outline of the triangle
    cairo_stroke(cr);
}
//ELLIPSE
void draw_ellipse(cairo_t *crelp, double xc, double yc, double radius_x, double radius_y)
{
    cairo_save(crelp);
    
    // Set the line width and color
    cairo_set_line_width(crelp, 2.0);
    cairo_set_source_rgb(crelp, 0.0, 0.0, 0.0); // Black color
    
    // Draw the ellipse
    cairo_translate(crelp, xc, yc);
    cairo_scale(crelp, 1.0, radius_y / radius_x);
    cairo_arc(crelp, 0, 0, radius_x, 0, 2 * M_PI);
    cairo_stroke(crelp);
    
    cairo_restore(crelp);
}
gboolean draw_callback(GtkWidget *widget, cairo_t *crelp, gpointer data)
{
    guint width, height;
    
    // Get the size of the widget
    width = gtk_widget_get_allocated_width(widget);
    height = gtk_widget_get_allocated_height(widget);
    
    // Set the ellipse parameters
    double xc = width / 2.0;
    double yc = height / 2.0;
    double radius_x = width / 4.0;
    double radius_y = height / 4.0;
    
    // Call the draw_ellipse function
    draw_ellipse(crelp, xc, yc, radius_x, radius_y);
    
    return FALSE;
}
void draw_half_circle(cairo_t *cr, double x1, double y1, double r)
{

    cairo_set_source_rgb(cr, 0, 0, 0); // Black color
    cairo_set_line_width(cr, 1);

    // Draw the circle
    cairo_arc(cr, x1, y1, r, G_PI, 0);
    cairo_stroke(cr);
}
