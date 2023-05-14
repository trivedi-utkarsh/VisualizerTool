#include <gtk/gtk.h>

static void destroy(GtkWidget * widget , gpointer data){
	gtk_main_quit();
}

static void button_clicked(GtkWidget *widget, gpointer data){
	g_print("Button clicked!\n");
}

int main(int argc, char* argv[])
{
	// Initialize GTK
	gtk_init(&argc, &argv);
	GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Visualizer Tool");
	gtk_window_set_default_size(GTK_WINDOW(window), 1920 , 1080);
		
	//connecting the destroy signal to the callback function
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
		
	//creating a fixed container
	GtkWidget *fixed = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(window),fixed);
	
	//creating a event_box
	GtkWidget *event_box = gtk_event_box_new();
	gtk_fixed_put(GTK_FIXED(fixed),event_box , 50 , 50);
	gtk_widget_set_size_request(event_box, 50,30);
	
	//creating a button
	GtkWidget *button = gtk_button_new_with_label("Draw");
	gtk_container_add(GTK_CONTAINER(event_box),button);
	g_signal_connect(button , "clicked" , G_CALLBACK(button_clicked),NULL);
	
	
	//show the main window
	gtk_widget_show_all(window);
	
	//start the main gtk loop
	gtk_main();


	return 0;
}

