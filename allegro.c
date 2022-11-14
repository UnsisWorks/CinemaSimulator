#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

const float FPS = 60;

int main(int argc, char *argv[])
{
	ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_SAMPLE *acodec = NULL;
    ALLEGRO_SAMPLE_ID *id = NULL;

    acodec = al_load_sample("./sound/sound.wav");
	
    // Initialize allegro
	if (!al_init()) {
		fprintf(stderr, "Failed to initialize allegro.\n");
		return 1;
	}

    // Initialize allegro
    if (!al_init_acodec_addon()) {
        fprintf(stderr, "Failed to initialize acodec.\n");
        return 1;
    }

    // Initialize allegro
    if (!al_install_audio()) {
        fprintf(stderr, "Failed to initialize audio.\n");
        return 1;
    }
    
    
    // Initialize allegro
    if (acodec == NULL) {
        fprintf(stderr, "Failed to play audio.\n");
        return 1;
    }
    al_play_sample(acodec, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
    
	// Create the display
	// display = al_create_display(640, 480);
	// if (!display) {
	// 	fprintf(stderr, "Failed to create display.\n");
	// 	return 1;
	// }

	

	// Clean up
	al_destroy_display(display);

	return 0;
}
// Compiler: gcc allegro.c -I/home/monstruosoft/libs/usr/local/include/ -L/home/monstruosoft/libs/usr/local/lib/ -lallegro -lallegro_primitives -lallegro_audio -lallegro_acodec -o allegro