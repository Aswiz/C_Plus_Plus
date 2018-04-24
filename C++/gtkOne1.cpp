#include </usr/include/gtk-3.0/gtk/gtk.h>



int main( int argc, char *argv[])
{
        GtkWidget *window;

        gtk_init(&argc, &argv);

        window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_title(GTK_WINDOW(window), "Введение в GTK");
        gtk_container_set_border_width (GTK_CONTAINER(window), 50);
        gtk_window_set_default_size (GTK_WINDOW (window), 500, 500);

        gtk_widget_show_all(window);

        g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

        gtk_main();
        return 0;
}
