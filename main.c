#include <stdlib.h>
#include <gtk/gtk.h>

//TODO figure out how to integrate this shit into codeblocks
//gcc -rdynamic -o FeralArchitect ../main.c `pkg-config --cflags --libs gtk+-3.0`
int main(int argc, char *argv[])
{
    GtkBuilder      *builder;
    GtkWidget       *window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "gtklayout.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window1"));
    gtk_builder_connect_signals(builder, NULL);

    g_object_unref(builder);

    gtk_widget_show(window);
    gtk_main();

    return 0;
}

void on_window_main_destroy()
{
    gtk_main_quit();
}
