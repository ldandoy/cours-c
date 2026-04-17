#include <stdlib.h>
#include "file.h"

void init_file(t_file*f){
    f->tete=f->fin=NULL;
}

int fileVide(t_file*f){
    if(f->tete==NULL) return 1;
    else return 0;
}

int tailleF(t_file*f){
    int n=0;
    t_maillonF *temp=f->tete;
    while(temp!=NULL){
        n++;
        temp=temp->suivant;
    }
    return n;
}

void enfiler(t_file*f,void*data){
    t_maillonF  *nouveau;
    //creation d'un maillon
    nouveau=malloc(sizeof(t_maillonF));
    nouveau->data=data;
    nouveau->suivant=NULL;
    //si file vide
    if(f->tete==NULL){
        f->tete=f->fin=nouveau;
    }
    //sinon
    else{
        f->fin->suivant=nouveau;
        f->fin=nouveau;
    }
}

void* defiler(t_file*f){
    t_maillonF*temp;
    void *data=NULL;
    //si liste non vide
    if(f->tete!=NULL){
        // si un seul element
        if(f->tete==f->fin){
            data=f->tete->data;
            free(f->tete);
            f->tete=f->fin=NULL;
        }
        //sinon
        else{
            temp=f->tete;
            f->tete=f->tete->suivant;
            data=temp->data;
            free(temp);
        }
    }
    return data;
}

void* tete(t_file*f){
    return f->tete->data;
}


