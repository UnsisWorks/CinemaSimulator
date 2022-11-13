#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *events = NULL;

int main() {
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
// Compiler: gcc allegro.c -I/home/monstruosoft/libs/usr/local/include/ -L/home/monstruosoft/libs/usr/local/lib/ -lallegro -lallegro_primitives -o allegro