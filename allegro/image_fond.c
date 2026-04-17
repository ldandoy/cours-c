#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>

#define LARGEUR 1024
#define HAUTEUR 600

void initialisation_allegro();

int main(int argc, char *argv[])
{
    BITMAP *image;

    initialisation_allegro();

    // charger l'image
    image = load_bitmap("images/galaxie-andromede.bmp", NULL);
    if (!image) {
        allegro_message("Impossible de charger images/galaxie-andromede.bmp");
        allegro_exit();
        return 1;
    }

    // afficher l'image en fond (etire a la taille de la fenetre)
    stretch_blit(image, screen, 0, 0, image->w, image->h, 0, 0, LARGEUR, HAUTEUR);

    // attendre une touche
    readkey();

    destroy_bitmap(image);
    allegro_exit();
    return 0;
}
END_OF_MAIN();

void initialisation_allegro() {
    allegro_init();
    install_keyboard();
    set_color_depth(desktop_color_depth());

    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, LARGEUR, HAUTEUR, 0, 0) != 0) {
        allegro_message("probleme mode graphique");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
}
