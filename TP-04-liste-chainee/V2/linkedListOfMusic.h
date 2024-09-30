#pragma once

#include <stdbool.h>

struct element
{
    char* name;
    char* artist;
    char* album;
    char* genre;
    int discNumber;
    int trackNumber;
    int year;
};


typedef element Element;

typedef struct music {
	Element val;
	struct music* suiv;
} Music;

typedef music* ListeMusic;

// retourne vrai si l est vide et faux sinon
bool estVide(ListeMusic l);

// créer une ListeMusic d'un seul élément contenant la valeur v
ListeMusic creer(Element v);

// ajoute l'élément v en tete de la ListeMusic l
ListeMusic ajoutTete(Element v, ListeMusic l);

void afficheElement(Element e);

// affiche tous les éléments de la ListeMusic l
// Attention, cette fonction doit être indépendante du type des éléments de la ListeMusic
// utiliser une fonction annexe affiche_element
// Attention la ListeMusic peut être vide !
// version itérative
void afficheListeMusic_i(ListeMusic l);

// version recursive
void afficheListeMusic_r(ListeMusic l);

void detruireElement(Element e);

// Détruit tous les éléments de la ListeMusic l
// version itérative
void detruire_i(ListeMusic l);

// version récursive
void detruire_r(ListeMusic l);

// retourne la ListeMusic dans laquelle l'élément v a été ajouté en fin
// version itérative
ListeMusic ajoutFin_i(Element v, ListeMusic l);

// version recursive
ListeMusic ajoutFin_r(Element v, ListeMusic l);

// Retourne un pointeur sur l'élément de la ListeMusic l contenant la valeur v ou NULL
// version itérative
ListeMusic cherche_i(Element v,ListeMusic l);

// version récursive
ListeMusic cherche_r(Element v,ListeMusic l);

// Retourne la ListeMusic modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
ListeMusic retirePremier_i(Element v, ListeMusic l);

// version recursive
ListeMusic retirePremier_r(Element v, ListeMusic l);


void afficheEnvers_r(ListeMusic l);