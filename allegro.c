// #include <stdio.h>
// #include <allegro5/allegro.h>
// #include <allegro5/allegro_audio.h>
// #include <allegro5/allegro_acodec.h>

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

int main(int argc, char **argv){


    ALLEGRO_DISPLAY *display = NULL;


    if (!al_init()){
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }

    if (!al_install_audio()){
        fprintf(stderr, "failed to initialize audio!\n");
        return -1;
    }

    if (!al_init_acodec_addon()){
        fprintf(stderr, "failed to initialize audio codecs!\n");
        return -1;
    }

    if (!al_reserve_samples(1)){
        fprintf(stderr, "failed to reserve samples!\n");
        return -1;
    }


    al_install_audio();
    al_init_acodec_addon();

    ALLEGRO_SAMPLE *sample = al_load_sample("./sound/sound.wav"); //sample always NULL

    al_reserve_samples(1);

    if (!sample){
        printf("Audio clip sample not loaded!\n");
        return -1;
    }

    display = al_create_display(640, 480);

    if (!display){
        fprintf(stderr, "failed to create display!\n");
        return -1;
    }

    /* Loop the sample until the display closes. */
    al_play_sample(sample, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);

    al_rest(10.0);

    al_destroy_display(display);
    al_destroy_sample(sample);
    return 0;
}

int initSound(){

    // ALLEGRO_DISPLAY *display = NULL;

    // allegro_init();
     install_allegro(SYSTEM_AUTODETECT, &errno, atexit);
    // if (!install_sound()){
    //     fprintf(stderr, "failed to initialize audio!\n");
    //     return -1;
    // }

    puts("Aqui 1");
    if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0) {
        allegro_message("Error: inicializando sistema de sonido\n%s\n", allegro_error);
        return 1;
    }

    puts("Aqui 2");

    SAMPLE *sample = load_sample("./sound/sound.wav");

    // reserve_samples(1);

    puts("Aqui 3");
    if (!sample){
        printf("Audio clip sample not loaded!\n");
        return -1;
    }

    puts("Aqui 4");
    // display = al_create_display(640, 480);

    // if (!display){
    //     fprintf(stderr, "failed to create display!\n");
    //     return -1;
    // }

    /* Loop the sample until the display closes. */
    play_sample(sample, 255, 0, 2000, 0);


    // al_destroy_display(display);
    destroy_sample(sample);
    return 0;
}



// Compiler: gcc allegro.c -I/home/monstruosoft/libs/usr/local/include/ -L/home/monstruosoft/libs/usr/local/lib/ -lallegro -lallegro_primitives -lallegro_audio -lallegro_acodec -o allegro