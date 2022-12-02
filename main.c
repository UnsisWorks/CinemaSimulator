#include <gtk/gtk.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "saveData.c"
// #include "Cola.c"

GtkWidget *mainWindow, *initWindow, *box, *initLayout;
// ALLEGRO_DISPLAY *display = NULL;
// ALLEGRO_EVENT_QUEUE *events = NULL;

static void loadData (GtkWidget *widget, GtkWidget *gData) {
    puts("Moving");
    for (size_t i = 11; i < 800; i+=5) {
        gtk_layout_move(GTK_LAYOUT(initLayout), box, i, 40);
        sleep(1);
        gtk_widget_show_all(initLayout);
        // puts("...");
    }
}

/**
 * It creates a window, sets its title, size, and resizability, creates a table, creates two labels,
 * attaches the labels to the table, adds the table to the window, and shows the window
 * 
 * @param X The width of the window.
 * @param Y The number of rows in the table.
 */
static void table() {
    gtk_widget_set_visible(GTK_WIDGET(mainWindow), FALSE);
    GtkWidget *window, *lOrd, *table, *lPeople, *ftPed;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Orden de posiciones");
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 500);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

    table = gtk_grid_new();
    gtk_widget_set_name(GTK_WIDGET(table), "table");
    gtk_grid_set_row_homogeneous(GTK_GRID(table), TRUE);
    lPeople = gtk_label_new("Nombres");
    lOrd = gtk_label_new("Descripcion");
    ftPed = gtk_label_new("juan escutia");

    gtk_grid_set_column_spacing(GTK_GRID(table), 2);
    gtk_grid_attach(GTK_GRID(table), lPeople, 15, 0, 120, 210);
    gtk_grid_attach(GTK_GRID(table), lOrd,200, 0, 120, 210);

    gtk_grid_insert_row(GTK_GRID(table), 1);
    // gtk_grid_set_column_spacing(GTK_GRID(table), 2);
    gtk_grid_attach(GTK_GRID(table), ftPed, 15, 20, 120, 210);

    gtk_container_add(GTK_CONTAINER(window), table);

    // webossss

    gtk_widget_show_all(window);
}

static void initSimulator(GtkWidget *widget, GtkWidget *gData) {
    gtk_widget_set_visible(GTK_WIDGET(mainWindow), FALSE);

    GtkWidget *peoples[10], *images[10];
    initWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size (GTK_WINDOW (initWindow), 800, 450);
    // gtk_window_set_position(GTK_WINDOW(initWindow), GTK_WIN_POS_CENTER);
    // gtk_window_set_title(GTK_WINDOW (initWindow), "LLENANDO COLA");
    // gtk_window_set_resizable(GTK_WINDOW(initWindow), FALSE);

    images[0] = gtk_image_new_from_file("./image/mono.png");

    peoples[0] = gtk_button_new();
    gtk_button_set_image(GTK_BUTTON(peoples[0]), images[0]  );
    box = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);

    initLayout = gtk_layout_new(NULL, NULL);
    gtk_layout_put(GTK_LAYOUT(initLayout), box, 10, 40);

    gtk_container_add(GTK_CONTAINER(box), peoples[0]);
    gtk_container_add(GTK_CONTAINER(initWindow), initLayout);
    g_signal_connect(peoples[0], "clicked", G_CALLBACK(loadData), NULL);
    

    gtk_widget_show_all(initWindow);
    // loadData(initLayout, box);
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

    labelTitle = gtk_label_new("Cinema");
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
    buttonStart = gtk_button_new_with_label("inciar");
    buttonList = gtk_button_new();
    buttonExit = gtk_button_new();

    // gtk_button_set_image(GTK_BUTTON(buttonStart), imagePlay);
    gtk_button_set_image(GTK_BUTTON(buttonList), imageScore);
    gtk_button_set_image(GTK_BUTTON(buttonHelp), imageSett);
    gtk_button_set_image(GTK_BUTTON(buttonAcer), imageAcer);
    gtk_button_set_image(GTK_BUTTON(buttonExit), imageExit);


    // Add signals at buttons
    g_signal_connect(buttonStart, "clicked", G_CALLBACK(table), NULL);

    // Add buttons  at button box
    gtk_container_add(GTK_CONTAINER(buttBoxAcer), buttonAcer);
    gtk_container_add(GTK_CONTAINER(buttBoxHelp), buttonHelp);
    gtk_container_add(GTK_CONTAINER(buttBoxPlay), buttonStart);
    gtk_container_add(GTK_CONTAINER(buttBoxScore), buttonList);
    gtk_container_add(GTK_CONTAINER(buttBoxExit), buttonExit);
    
    // Add buttons at box
    gtk_container_add(GTK_CONTAINER(box), buttBoxPlay);

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
    gtk_window_set_decorated(GTK_WINDOW(mainWindow), FALSE);



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
    system("clear");
    app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}

// Compiler gcc `pkg-config --cflags gtk+-3.0` -o main main.c `pkg-config --libs gtk+-3.0` 

// Compiler: gcc `pkg-config --cflags gtk+-3.0` -o main main.c `pkg-config --libs gtk+-3.0` -I/home/monstruosoft/libs/usr/local/include/ -L/home/monstruosoft/libs/usr/local/lib/ -lallegro -lallegro_audio -lallegro_acodec

// Compiler: gcc `pkg-config --cflags gtk+-3.0` main.c `pkg-config --libs gtk+-3.0` -I/home/monstruosoft/libs/usr/local/include/ -L/home/monstruosoft/libs/usr/local/lib/ -lalleg -o main
