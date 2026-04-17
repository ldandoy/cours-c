#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>

volatile int fermer = 0;

void on_close() {
    fermer = 1;
}

/* verifie si deux rectangles se chevauchent */
int collision(int ax1, int ay1, int ax2, int ay2,
              int bx1, int by1, int bx2, int by2)
{
    return (ax1 < bx2 && ax2 > bx1 && ay1 < by2 && ay2 > by1);
}

int main(int argc, char *argv[])
{
    int cx = 600, cy = 300;
    int vitesse = 5;

    /* rectangle bleu (obstacle) */
    int bx1 = 200, by1 = 150, bx2 = 350, by2 = 300;

    int vert, bleu, rouge;
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
    vert  = makecol(0, 200, 0);
    bleu  = makecol(0, 0, 200);
    rouge = makecol(200, 0, 0);

    while (!fermer) {
        int nx, ny;

        if (key[KEY_ESC])
            break;

        /* --- mouvement avec collision axe par axe --- */

        /* vertical */
        ny = cy;
        if (key[KEY_UP])    ny = cy - vitesse;
        if (key[KEY_DOWN])  ny = cy + vitesse;

        /* limites ecran */
        if (ny - 50 < 0)    ny = 50;
        if (ny + 50 > 600)  ny = 550;

        /* collision sur Y : on teste la nouvelle position Y avec l'ancien X */
        if (collision(cx - 50, ny - 50, cx + 50, ny + 50, bx1, by1, bx2, by2))
            ny = cy;

        cy = ny;

        /* horizontal */
        nx = cx;
        if (key[KEY_LEFT])  nx = cx - vitesse;
        if (key[KEY_RIGHT]) nx = cx + vitesse;

        if (nx - 50 < 0)    nx = 50;
        if (nx + 50 > 800)  nx = 750;

        /* collision sur X : on teste avec le Y deja mis a jour */
        if (collision(nx - 50, cy - 50, nx + 50, cy + 50, bx1, by1, bx2, by2))
            nx = cx;

        cx = nx;

        /* --- dessin --- */
        clear_to_color(buffer, makecol(0, 0, 0));

        /* obstacle bleu */
        rectfill(buffer, bx1, by1, bx2, by2, bleu);

        /* triangle vert */
        triangle(buffer,
                 cx, cy - 50,
                 cx - 50, cy + 50,
                 cx + 50, cy + 50,
                 vert);

        /* hitbox du triangle en rouge (debug) */
        rect(buffer, cx - 50, cy - 50, cx + 50, cy + 50, rouge);

        blit(buffer, screen, 0, 0, 0, 0, 800, 600);

        rest(10);
    }

    destroy_bitmap(buffer);
    allegro_exit();
    return 0;
}
END_OF_MAIN();
