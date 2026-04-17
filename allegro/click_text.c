#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>

volatile int fermer = 0;

void on_close() {
    fermer = 1;
}

int main(int argc, char *argv[])
{
    int texte_x = 400;
    int texte_y = 300;
    int texte_w, texte_h;
    const char *texte_initial = "Hello World";
    const char *texte_apres = "Tu as clique !";
    const char *texte_affiche;
    int clique = 0;

    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth(desktop_color_depth());

    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0) != 0) {
        allegro_message("Probleme mode graphique");
        allegro_exit();
        return EXIT_FAILURE;
    }

    set_close_button_callback(on_close);
    show_mouse(screen);

    BITMAP *buffer = create_bitmap(800, 600);

    texte_affiche = texte_initial;

    while (!fermer && !keypressed()) {
        /* dimensions du texte affiche */
        texte_w = text_length(font, texte_affiche);
        texte_h = text_height(font);

        /* detecter clic gauche sur le texte */
        if ((mouse_b & 1) && !clique) {
            if (mouse_x >= texte_x - texte_w / 2 && mouse_x <= texte_x + texte_w / 2 &&
                mouse_y >= texte_y - texte_h / 2 && mouse_y <= texte_y + texte_h / 2) {
                /* alterner entre les deux textes */
                if (texte_affiche == texte_initial)
                    texte_affiche = texte_apres;
                else
                    texte_affiche = texte_initial;
            }
            clique = 1;
        }

        if (!(mouse_b & 1))
            clique = 0;

        /* dessiner sur le buffer */
        clear_to_color(buffer, makecol(0, 0, 0));
        textout_centre_ex(buffer, font, texte_affiche, texte_x, texte_y, makecol(255, 255, 255), -1);

        /* copier le buffer sur l'ecran d'un coup */
        scare_mouse();
        blit(buffer, screen, 0, 0, 0, 0, 800, 600);
        unscare_mouse();

        rest(10);
    }

    destroy_bitmap(buffer);

    allegro_exit();
    return 0;
}
END_OF_MAIN();
