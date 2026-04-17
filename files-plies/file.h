#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED
///type pour les maillons
typedef struct maillonF{
    void *data; //pointeur générique sur la donnée
    struct maillonF *suivant;  //pointeur sur le maillon suivant
}t_maillonF;

///type pour la file
typedef struct file{
    t_maillonF *tete;//ancre de tête : pointeur sur le prochain maillon à défiler
    t_maillonF *fin;//ancre de fin : pointeur sur le dernier maillon (après lequel enfiler)
}t_file;

///prototypes des sous-programmes

/* initialisation d'une file vide
paramètre : l'adresse de la file */
void init_file(t_file*f);

/* test si la file est vide
paramètre : l'adresse de la file
retour : 1 si la file est vide, 0 sinon */
int fileVide(t_file*f);

/* compter le nombre d'éléments
paramètre : l'adresse de la file
retour : taille de la file */
int tailleF(t_file*f);

/* enfiler une nouvelle donnée
paramètres : l'adresse de la file, l'adresse de la donnée */
void enfiler(t_file*f,void*data);

/* défiler le prochain élement
paramètre : l'adresse de la file
retour : l'adresse de la donnee*/
void* defiler(t_file*f);

/* acceder au prochain element (donnée en tête)
paramètre : l'adresse de la file
retour : adresse de la donnée en tête */
void* tete(t_file*f);

#endif // FILE_H_INCLUDED
