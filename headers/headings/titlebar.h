#include <gtk/gtk.h>
#include "../loadCss.h"

void designTitleBar(GtkWidget *window)
{
    GtkWidget *header_bar = gtk_header_bar_new();
    gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(header_bar), TRUE);
    gtk_header_bar_set_title(GTK_HEADER_BAR(header_bar), "VISUALISER TOOL");
    gtk_window_set_titlebar(GTK_WINDOW(window), header_bar);
}