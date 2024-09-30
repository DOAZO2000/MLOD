#include "liste-chainee.h"
#include <stdlib.h>
#include <stdio.h>

#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v){
	Liste l = malloc(sizeof(Element));
	l->val=v;
	l->suiv=NULL;
	return l;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l) {
	Liste listeSuivant = creer(v);
	listeSuivant->suiv=l;
	return listeSuivant;
}

//Mandatory : e is integer
void afficheElement(Element e) {
	printf("%i ",e);
}

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
	while(l!=NULL){
		afficheElement(l->val);
		l=l->suiv;
	}
	printf("\n");
}

// version recursive
void afficheListe_r(Liste l) {
	if(l!=NULL){
		afficheElement(l->val);
		afficheListe_r(l->suiv);
	}
	else{
		printf("\n");
	}
}

void detruireElement(Element e) {}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
	Liste tmp;
	while(l!=NULL){
		tmp=l;
		l=l->suiv;
		detruireElement(tmp->val);
		free(tmp);
		tmp=NULL;
	}
}

// version récursive
void detruire_r(Liste l) {
	if(l!=NULL){
		detruireElement(l->val);
		detruire_r(l->suiv);
		free(l);
		l=NULL;
	}
	

}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l) {
	if(l==NULL){
		return creer(v);
	}
	while(l->suiv!=NULL){
		l=l->suiv;
	}
	Liste listeFin = creer(v);	
	l->suiv= listeFin;
	return listeFin;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	if(estVide(l)){
		return creer(v);
	}
	l->suiv= ajoutFin_r(v,l->suiv);
	return l;
}

// compare deux elements
bool equalsElement(Element e1, Element e2){
	return e1 == e2;
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
	while(l && (l->val!=v)){
		l=l->suiv;
	}
	return l;
}

// version récursive
Liste cherche_r(Element v,Liste l) {
	if(l && (l->val!=v)){
		return cherche_r(v,l->suiv);
	}
	return l;
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
	Liste tmp;
	while(l && l->val!=v){
		l=l->suiv;
	}
	tmp = l;
	l->suiv=l->suiv->suiv;
	free(tmp->suiv);
	detruireElement(tmp->val);

	return l;
}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
	if (l!=NULL && l->val!=v){
		return(v, l->suiv);
	}
	Liste tmp;
	tmp = l;
	l->suiv=l->suiv->suiv;
	free(tmp->suiv);
	detruireElement(tmp->val);
	return l;
}



void afficheEnvers_r(Liste l) {
	TODO;
}



