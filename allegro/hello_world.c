#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>

volatile int fermer = 0;

void on_close() {
    fermer = 1;
}

int main(int argc, char *argv[])
{
    int mouse_click = 0;
    allegro_init();
    install_keyboard();
    set_color_depth(desktop_color_depth());

    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0) != 0) {
        allegro_message("Probleme mode graphique");
        allegro_exit();
        return EXIT_FAILURE;
    }

    set_close_button_callback(on_close);

    // fond noir
    clear_to_color(screen, makecol(0, 0, 0));

    // texte blanc au centre
    textout_centre_ex(screen, font, "Hello World", 400, 300, makecol(255, 255, 255), -1);

    // attendre une touche ou clic sur le bouton fermer
    while (!fermer && !keypressed()) {
        mouse_click = mouse_b;
        if(mouse_click & 1) {
            textout_centre_ex(screen, font, "toto", 400, 300, makecol(255, 255, 255), -1);
        }
        
        rest(10);
    }

    allegro_exit();
    return 0;
}
END_OF_MAIN();
