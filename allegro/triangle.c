
#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>

volatile int fermer = 0;

void on_close() {
    fermer = 1;
}

int main(int argc, char *argv[])
{
    int vert;

    allegro_init();
    install_keyboard();
    set_color_depth(desktop_color_depth());

    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0) != 0) {
        allegro_message("Probleme mode graphique");
        allegro_exit();
        return EXIT_FAILURE;
    }

    set_close_button_callback(on_close);

    clear_to_color(screen, makecol(0, 0, 0));

    vert = makecol(0, 200, 0);

    /* triangle : sommet haut, bas gauche, bas droit */
    triangle(screen,
             400, 150,   /* sommet haut */
             200, 450,   /* bas gauche */
             600, 450,   /* bas droit */
             vert);

    while (!fermer && !keypressed()) {
        rest(10);
    }

    allegro_exit();
    return 0;
}
END_OF_MAIN();
