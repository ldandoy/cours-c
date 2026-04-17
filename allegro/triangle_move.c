#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>

volatile int fermer = 0;

void on_close() {
    fermer = 1;
}

int main(int argc, char *argv[])
{
    int cx = 400, cy = 300;
    int bx1 = 50, by1 =200, bx2 = 100, by2 =250;
    int vitesse = 5;
    int vert;
    int bleu;
    BITMAP *buffer;

    allegro_init();
    install_keyboard();
    set_color_depth(desktop_color_depth());

    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0) != 0) {
        allegro_message("Probleme mode graphique");
        allegro_exit();
        return EXIT_FAILURE;
    }

    set_close_button_callback(on_close);

    buffer = create_bitmap(800, 600);
    vert = makecol(0, 200, 0);
    bleu = makecol(0, 0, 200);

    while (!fermer) {
        if (key[KEY_ESC])
            break;

        if (key[KEY_UP])    cy -= vitesse;
        if (key[KEY_DOWN] && (cy+50+vitesse) < 600)  cy += vitesse;
        if (key[KEY_LEFT])  cx -= vitesse;
        if (key[KEY_RIGHT]) cx += vitesse;

        /* dessiner sur le buffer */
        clear_to_color(buffer, makecol(0, 0, 0));
        
        rectfill(buffer, bx1, by1, bx2, by2, bleu);

        triangle(buffer,
                 cx, cy - 50,      /* sommet haut */
                 cx - 50, cy + 50, /* bas gauche */
                 cx + 50, cy + 50, /* bas droit */
                 vert);

        //rect(buffer, bx1, by1, bx2, by2, bleu);
        
        

        blit(buffer, screen, 0, 0, 0, 0, 800, 600);

        rest(10);
    }

    destroy_bitmap(buffer);
    allegro_exit();
    return 0;
}
END_OF_MAIN();
