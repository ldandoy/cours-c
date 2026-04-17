#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>

volatile int fermer = 0;

void on_close() {
    fermer = 1;
}

/*
 * Le triangle pointe vers le haut, ses bords sont des lignes droites.
 * Pour un y donne, la largeur du triangle va de :
 *    gauche = cx - (cy+50 - y) / 2
 *    droite = cx + (cy+50 - y) / 2
 *
 * Un point est dans le triangle si il est entre ces deux bords
 * et entre le sommet (cy-50) et la base (cy+50).
 */
int point_dans_triangle(int px, int py, int cx, int cy)
{
    int demi_largeur;

    if (py < cy - 50 || py > cy + 50)
        return 0;

    demi_largeur = (cy + 50 - py) / 2;

    return (px >= cx - demi_largeur && px <= cx + demi_largeur);
}

/* collision : on teste les 4 coins du rectangle dans le triangle
   et les 3 sommets du triangle dans le rectangle */
int collision(int cx, int cy,
              int rx1, int ry1, int rx2, int ry2)
{
    /* coin du rectangle dans le triangle ? */
    if (point_dans_triangle(rx1, ry1, cx, cy)) return 1;
    if (point_dans_triangle(rx2, ry1, cx, cy)) return 1;
    if (point_dans_triangle(rx1, ry2, cx, cy)) return 1;
    if (point_dans_triangle(rx2, ry2, cx, cy)) return 1;

    /* sommet du triangle dans le rectangle ? */
    if (cx >= rx1 && cx <= rx2 && cy - 50 >= ry1 && cy - 50 <= ry2) return 1;
    if (cx - 50 >= rx1 && cx - 50 <= rx2 && cy + 50 >= ry1 && cy + 50 <= ry2) return 1;
    if (cx + 50 >= rx1 && cx + 50 <= rx2 && cy + 50 >= ry1 && cy + 50 <= ry2) return 1;

    return 0;
}

int main(int argc, char *argv[])
{
    int cx = 600, cy = 300;
    int vitesse = 5;

    /* rectangle bleu (obstacle) */
    int bx1 = 200, by1 = 150, bx2 = 350, by2 = 300;

    int vert, bleu;
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
        int nx, ny;

        if (key[KEY_ESC])
            break;

        /* mouvement vertical */
        ny = cy;
        if (key[KEY_UP])    ny = cy - vitesse;
        if (key[KEY_DOWN])  ny = cy + vitesse;
        if (ny - 50 < 0)    ny = 50;
        if (ny + 50 > 600)  ny = 550;

        if (collision(cx, ny, bx1, by1, bx2, by2))
            ny = cy;
        cy = ny;

        /* mouvement horizontal */
        nx = cx;
        if (key[KEY_LEFT])  nx = cx - vitesse;
        if (key[KEY_RIGHT]) nx = cx + vitesse;
        if (nx - 50 < 0)    nx = 50;
        if (nx + 50 > 800)  nx = 750;

        if (collision(nx, cy, bx1, by1, bx2, by2))
            nx = cx;
        cx = nx;

        /* dessin */
        clear_to_color(buffer, makecol(0, 0, 0));
        rectfill(buffer, bx1, by1, bx2, by2, bleu);
        triangle(buffer, cx, cy - 50, cx - 50, cy + 50, cx + 50, cy + 50, vert);
        blit(buffer, screen, 0, 0, 0, 0, 800, 600);

        rest(10);
    }

    destroy_bitmap(buffer);
    allegro_exit();
    return 0;
}
END_OF_MAIN();
