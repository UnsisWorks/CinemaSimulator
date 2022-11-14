#include <gtk/gtk.h>
// #include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
// #include "Cola.c"

GtkWidget *mainWindow;
ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *events = NULL;

static void loadData () {

}

static void initSimulator (GtkApplication *app, gpointer user_data) {
    GtkWidget *initWindow;
     al_init();
    al_install_keyboard();
    al_set_new_display_flags(ALLEGRO_RESIZABLE);
    al_set_new_display_option(ALLEGRO_SINGLE_BUFFER, 1, ALLEGRO_REQUIRE);
    display = al_create_display(640, 480);
    al_set_window_title(display, "window");
    al_init_primitives_addon();

    events = al_create_event_queue();
    al_register_event_source(events, al_get_keyboard_event_source());

    while (al_is_event_queue_empty(events)) {
        al_draw_filled_circle(rand() % 640, rand() % 480, rand() % 64, al_map_rgb(rand() % 256, 0, 0));
        al_flip_display();
        al_rest(0.015);
    }
}

/**
 * It creates a window with a vertical box, which contains 5 buttons
 * 
 * @param app The GtkApplication instance.
 * @param user_data This is a pointer to any data you want to pass to the callback function.
 */
static void activate (GtkApplication *app, gpointer user_data) {
    
    GtkWidget *buttBoxAcer, *buttBoxPlay, *buttBoxHelp, *buttBoxScore, *buttBoxExit, *box, *subLine;
    GtkWidget *buttonAcer, *buttonStart, *buttonHelp, *buttonList, *buttonExit;
    GtkWidget *imageExit, *imageAcer, *imagePlay, *imageScore, *imageSett, *labelTitle, *fixed;
    GtkCssProvider *cssProvider;
    // Load images for buttons
    imagePlay = gtk_image_new_from_file("./image/PLAY.png");
    imageScore = gtk_image_new_from_file("./image/SCORE.png");
    imageAcer = gtk_image_new_from_file("./image/CREDITS.png");
    imageExit = gtk_image_new_from_file("./image/EXIT.png");
    imageSett = gtk_image_new_from_file("./image/SETTINGS.png");

    cssProvider = gtk_css_provider_new();
    subLine = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);

    // Create container fixed
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_box_set_homogeneous(GTK_BOX(box), TRUE);

    labelTitle = gtk_label_new("Cinema simulator");
    fixed = gtk_fixed_new();
    gtk_fixed_put(GTK_FIXED(fixed), labelTitle, 0, 0);
    gtk_fixed_put(GTK_FIXED(fixed), subLine, 0, 40);
    gtk_box_pack_start(GTK_BOX(box), fixed, TRUE, FALSE, 30);

    // Create box for buttons
    buttBoxAcer = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
    buttBoxPlay = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
    buttBoxHelp = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
    buttBoxScore = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
    buttBoxExit = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);

    // Create buttons and add at box container
    buttonAcer = gtk_button_new();
    buttonHelp = gtk_button_new();
    buttonStart = gtk_button_new();
    buttonList = gtk_button_new();
    buttonExit = gtk_button_new();

    gtk_button_set_image(GTK_BUTTON(buttonStart), imagePlay);
    gtk_button_set_image(GTK_BUTTON(buttonList), imageScore);
    gtk_button_set_image(GTK_BUTTON(buttonHelp), imageSett);
    gtk_button_set_image(GTK_BUTTON(buttonAcer), imageAcer);
    gtk_button_set_image(GTK_BUTTON(buttonExit), imageExit);


    // Add signals at buttons
    g_signal_connect(buttonStart, "clicked", G_CALLBACK(initSimulator), NULL);
    // g_signal_connect(buttonAcer, "clicked", G_CALLBACK(acercaDe), NULL);
    // g_signal_connect(buttonList, "clicked", G_CALLBACK(windowScore), NULL);
    // g_signal_connect(buttonP, "clicked", G_CALLBACK(windowScore), NULL);

    // Add buttons  at button box
    gtk_container_add(GTK_CONTAINER(buttBoxAcer), buttonAcer);
    gtk_container_add(GTK_CONTAINER(buttBoxHelp), buttonHelp);
    gtk_container_add(GTK_CONTAINER(buttBoxPlay), buttonStart);
    gtk_container_add(GTK_CONTAINER(buttBoxScore), buttonList);
    gtk_container_add(GTK_CONTAINER(buttBoxExit), buttonExit);
    
    // Add buttons at box
    gtk_container_add(GTK_CONTAINER(box), buttBoxPlay);
    // gtk_container_add(GTK_CONTAINER(box), buttBoxScore);
    // gtk_container_add(GTK_CONTAINER(box), buttBoxHelp);
    // gtk_container_add(GTK_CONTAINER(box), buttBoxAcer);
    // gtk_container_add(GTK_CONTAINER(box), buttBoxExit);

    gtk_widget_set_size_request(GTK_WIDGET(buttonAcer), 240, 90);
    gtk_widget_set_size_request(GTK_WIDGET(buttonHelp), 240, 90);
    gtk_widget_set_size_request(GTK_WIDGET(buttonStart), 240, 90);
    gtk_widget_set_size_request(GTK_WIDGET(buttonList), 240, 90);
    
    gtk_style_context_add_class(gtk_widget_get_style_context(buttonAcer), "button");
    gtk_style_context_add_class(gtk_widget_get_style_context(buttonHelp), "button");
    gtk_style_context_add_class(gtk_widget_get_style_context(buttonStart), "button");
    gtk_style_context_add_class(gtk_widget_get_style_context(buttonList), "button");
    gtk_style_context_add_class(gtk_widget_get_style_context(buttonExit), "button");
    gtk_style_context_add_class(gtk_widget_get_style_context(imageExit), "images");
    gtk_style_context_add_class(gtk_widget_get_style_context(labelTitle), "labelTitle");
        
    gtk_widget_set_name(GTK_WIDGET(box), "subLine");
    gtk_widget_set_name(GTK_WIDGET(box), "box");
    // Set properties for winow
    mainWindow = gtk_application_window_new (app);
    gtk_window_set_position(GTK_WINDOW(mainWindow), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW (mainWindow), ".");
    gtk_window_set_default_size (GTK_WINDOW (mainWindow), 800, 450);
    gtk_window_set_resizable(GTK_WINDOW(mainWindow), FALSE);



    gtk_css_provider_load_from_path(cssProvider, "./style.css", NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
                                            GTK_STYLE_PROVIDER(cssProvider),
                                            GTK_STYLE_PROVIDER_PRIORITY_USER);

    gtk_container_add(GTK_CONTAINER(mainWindow), box);
    gtk_widget_show_all (mainWindow);
}

// funtion main
int main (int argc, char **argv) {
    GtkApplication *app;
    int status;
    app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}

// Compiler gcc `pkg-config --cflags gtk+-3.0` -o main main.c `pkg-config --libs gtk+-3.0`     
// Compiler: gcc `pkg-config --cflags gtk+-3.0` -o main main.c `pkg-config --libs gtk+-3.0` -I/home/monstruosoft/libs/usr/local/include/ -L/home/monstruosoft/libs/usr/local/lib/ -lallegro -lallegro_primitives