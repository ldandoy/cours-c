#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <allegro.h>

#define LARGEUR 800
#define HAUTEUR 600
#define RAYON 100

void initialisation_allegro();

int main(int argc, char *argv[])
{
    BITMAP *buffer;
    BITMAP *image;
    int dy, dx, sx, sy, largeur_ligne;

    initialisation_allegro();

    // charger l'image
    image = load_bitmap("images/galaxie-andromede.bmp", NULL);
    if (!image) {
        allegro_message("Impossible de charger images/galaxie-andromede.bmp");
        allegro_exit();
        return 1;
    }

    // creer le double buffer
    buffer = create_bitmap(LARGEUR, HAUTEUR);

    // boucle principale
    while (!key[KEY_ESC]) {
        // fond noir
        clear_bitmap(buffer);

        // dessiner un disque de l'image autour de la souris
        for (dy = -RAYON; dy <= RAYON; dy++) {
            dx = (int)sqrt((double)(RAYON * RAYON - dy * dy));
            sy = mouse_y + dy;
            sx = mouse_x - dx;
            largeur_ligne = 2 * dx;

            // verifier qu'on reste dans les limites
            if (sy < 0 || sy >= HAUTEUR) continue;
            if (sy >= image->h) continue;

            // ajuster si on depasse a gauche
            if (sx < 0) {
                largeur_ligne += sx;
                sx = 0;
            }
            // ajuster si on depasse a droite
            if (sx + largeur_ligne > image->w)
                largeur_ligne = image->w - sx;
            if (sx + largeur_ligne > LARGEUR)
                largeur_ligne = LARGEUR - sx;

            if (largeur_ligne > 0) {
                blit(image, buffer, sx, sy, sx, sy, largeur_ligne, 1);
            }
        }

        // afficher le buffer a l'ecran
        blit(buffer, screen, 0, 0, 0, 0, LARGEUR, HAUTEUR);
    }

    destroy_bitmap(buffer);
    destroy_bitmap(image);
    allegro_exit();
    return 0;
}
END_OF_MAIN();

void initialisation_allegro() {
    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth(desktop_color_depth());

    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, LARGEUR, HAUTEUR, 0, 0) != 0) {
        allegro_message("probleme mode graphique");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    show_mouse(screen);
}
