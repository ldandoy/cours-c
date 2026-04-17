#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include <time.h>

#define NB_FRAMES 10

volatile int fermer = 0;

void on_close() {
    fermer = 1;
}

int main(int argc, char *argv[])
{
    BITMAP *buffer;
    BITMAP *frames[NB_FRAMES];
    char filename[100];
    int i;
    int x = 200, y = 500;
    int vitesse = 3, vitesseB = 3;
    int frame = 0;        /* frame courante */
    int compteur = 0;     /* ralentir l'animation */
    int direction = 1;    /* 1 = droite, -1 = gauche */
    int bouge = 0;        /* est-ce qu'on bouge ? */
    int jump = 0;
    int gravity = 0;
    int couleur[3];
    int choix = 0;

    int bleu;
    int bx1 = 700, by1 = 530, bx2 = 750, by2 = 580;

    srand(time(NULL));

    allegro_init();
    install_keyboard();
    set_color_depth(desktop_color_depth());

    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0) != 0) {
        allegro_message("Probleme mode graphique");
        allegro_exit();
        return EXIT_FAILURE;
    }

    set_close_button_callback(on_close);

    /* charger les 10 sprites */
    for (i = 0; i < NB_FRAMES; i++) {
        sprintf(filename, "images/bonhomme/bonh%d.bmp", i);
        frames[i] = load_bitmap(filename, NULL);
        if (!frames[i]) {
            allegro_message("Impossible de charger %s", filename);
            allegro_exit();
            return EXIT_FAILURE;
        }
    }

    bleu = makecol(0, 0, 200);
    couleur[0] = makecol(100, 20, 200);
    couleur[1] = makecol(255, 0, 120);
    couleur[2] = makecol(40, 120, 0);
    
    buffer = create_bitmap(800, 600);

    while (!fermer) {
        if (key[KEY_ESC])
            break;

        bouge = 0;

        if (key[KEY_LEFT]) {
            x -= vitesse;
            direction = -1;
            bouge = 1;
        }
        if (key[KEY_RIGHT]) {
            x += vitesse;
            direction = 1;
            bouge = 1;
        }
        /*if (key[KEY_UP])    y -= vitesse;
        if (key[KEY_DOWN])  y += vitesse;*/

        if (key[KEY_SPACE] && !jump) {
            jump = 1;
            gravity = 1;
        }

        if (jump == 1) {
            if (y > 300 && gravity == 1) {
                y -= vitesse;
            } else if (y < 500) {
                y += vitesse;
                gravity = 0;
            }

            if (y == 500) {
                jump = 0;
            }
            
        }

        /* avancer l'animation seulement si on bouge */
        if (bouge) {
            compteur++;
            if (compteur >= 5) {   /* changer de frame toutes les 5 boucles */
                compteur = 0;
                frame = (frame + 1) % NB_FRAMES;
            }
        } else {
            frame = 0;  /* immobile = premiere frame */
        }

        /* dessin */
        clear_to_color(buffer, makecol(0, 0, 0));

        if (direction == 1) {
            /* vers la droite : dessin normal */
            draw_sprite(buffer, frames[frame], x, y);
        } else {
            /* vers la gauche : dessin miroir horizontal */
            draw_sprite_h_flip(buffer, frames[frame], x, y);
        }

        rectfill(buffer, bx1, by1, bx2, by2, bleu);

        
        if (bx1 > 0) {
            bx1 -= vitesseB;
            bx2 -= vitesseB;
        } else {
            bleu = couleur[rand() % 2 + 0];
            vitesseB = rand() % 9 + 3;
            bx1 = 750;
            bx2 = 800;
        }

        blit(buffer, screen, 0, 0, 0, 0, 800, 600);
        rest(10);
    }

    /* liberer la memoire */
    for (i = 0; i < NB_FRAMES; i++)
        destroy_bitmap(frames[i]);
    destroy_bitmap(buffer);
    allegro_exit();
    return 0;
}
END_OF_MAIN();
