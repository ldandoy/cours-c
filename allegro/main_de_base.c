#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro.h>

void initialisation_allegro();
int main(int argc, char *argv[])
{
    int i;
    srand(time(NULL));
    // initialisation allegro
    initialisation_allegro();
    //attendre que l'utilisateur appuie sur une touche
    readkey();
    //changer la couleur de la fenêtre graphique

    //attendre que l'utilisateur appuie sur une touche
    readkey();
    //changer la couleur de la fenêtre graphique

    //colorier 15000 pixels

    //attendre que l'utilisateur appuie sur une touche
    readkey();
    //fermer le programme proprement
    allegro_exit();
    return 0;
}END_OF_MAIN();//attention ne pas oublier !

void initialisation_allegro() {
    allegro_init(); // appel obligatoire (var.globales, recup. infos systeme ...)
    install_keyboard(); //pour utiliser le clavier
    install_mouse(); //pour utiliser la souris
    //pour choisir la profondeur de couleurs (8,16,24 ou 32 bits)
    set_color_depth(desktop_color_depth()); //ici : identique à celle du bureau

    //sélection du mode graphique
    // avec choix d'un driver+mode+résolution de l'écran
    /// si échec, le programme s'arrête
    if(set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
    {
        allegro_message("probleme mode graphique");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
}
