#include <gtk/gtk.h>

void load_css_for_widget(GtkWidget * widget,char * css)
{
    GtkCssProvider *cssProvider = gtk_css_provider_new();
    GdkDisplay *display = gdk_display_get_default();
    GdkScreen *screen = gdk_display_get_default_screen(display);
    gtk_style_context_add_provider_for_screen(screen, GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    GtkStyleContext *context = gtk_widget_get_style_context(widget);
    const gchar *cssChar = css;
    gtk_css_provider_load_from_data(cssProvider, cssChar, -1, NULL);
    g_object_unref(cssProvider);
}