#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include<string.h>

#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(ListeMusic l) {
	return l == NULL;
}

// créer une ListeMusic d'un seul élément contenant la valeur v
ListeMusic creer(Element v){
	ListeMusic l = malloc(sizeof(Element));
	l->val=v;
	l->suiv=NULL;
	return l;
}

// ajoute l'élément v en tete de la ListeMusic l
ListeMusic ajoutTete(Element v, ListeMusic l) {
	ListeMusic ListeMusicSuivant = creer(v);
	ListeMusicSuivant->suiv=l;
	return ListeMusicSuivant;
}

//Mandatory : e is integer
void afficheElement(Element e) {
	printf("Name= %s; ",e.name);
    printf("Artist= %s; ",e.artist);
    printf("Album= %s; ",e.album);
    printf("Genre= %s; ",e.genre);
    printf("Disc Number= %i; ",e.discNumber);
    printf("Track Number= %i; ",e.trackNumber);
    printf("year= %i; ",e.year);
}

// affiche tous les éléments de la ListeMusic l
// Attention, cette fonction doit être indépendante du type des éléments de la ListeMusic
// utiliser une fonction annexe affiche_element
// Attention la ListeMusic peut être vide !
// version itérative
void afficheListeMusic_i(ListeMusic l) {
	while(l!=NULL){
		afficheElement(l->val);
		l=l->suiv;
	}
	printf("\n");
}

// version recursive
void afficheListeMusic_r(ListeMusic l) {
	if(l!=NULL){
		afficheElement(l->val);
		afficheListeMusic_r(l->suiv);
	}
	else{
		printf("\n");
	}
}

void detruireElement(Element e) {
    free(e->name);
    free(e->artist);
    free(e->genre);
    free(e->album);
    free(e);
}

// Détruit tous les éléments de la ListeMusic l
// version itérative
void detruire_i(ListeMusic l) {
	ListeMusic tmp;
	while(l!=NULL){
		tmp=l;
		l=l->suiv;
		detruireElement(tmp->val);
		free(tmp);
		tmp=NULL;
	}
}

// version récursive
void detruire_r(ListeMusic l) {
	if(l!=NULL){
		detruireElement(l->val);
		detruire_r(l->suiv);
		free(l);
		l=NULL;
	}
	

}

// retourne la ListeMusic dans laquelle l'élément v a été ajouté en fin
// version itérative
ListeMusic ajoutFin_i(Element v, ListeMusic l) {
	if(l==NULL){
		return creer(v);
	}
	while(l->suiv!=NULL){
		l=l->suiv;
	}
	ListeMusic ListeMusicFin = creer(v);	
	l->suiv= ListeMusicFin;
	return ListeMusicFin;
}

// version recursive
ListeMusic ajoutFin_r(Element v, ListeMusic l) {
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

// Retourne un pointeur sur l'élément de la ListeMusic l contenant la valeur v ou NULL
// version itérative
ListeMusic cherche_i(Element v,ListeMusic l) {
	while(l && (l->val!=v)){
		l=l->suiv;
	}
	return l;
}

// version récursive
ListeMusic cherche_r(Element v,ListeMusic l) {
	if(l && (l->val!=v)){
		return cherche_r(v,l->suiv);
	}
	return l;
}

// Retourne la ListeMusic modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
ListeMusic retirePremier_i(Element v, ListeMusic l) {
	ListeMusic tmp;
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
ListeMusic retirePremier_r(Element v, ListeMusic l) {
	if (l!=NULL && l->val!=v){
		return(v, l->suiv);
	}
	ListeMusic tmp;
	tmp = l;
	l->suiv=l->suiv->suiv;
	free(tmp->suiv);
	detruireElement(tmp->val);
	return l;
}



void afficheEnvers_r(ListeMusic l) {
	TODO;
}


int tailleChaine(char* buff, char marker){
	int taille=0;
		while((buff[taille])!=marker)			//arret au marker
		{		
			taille++;
		}
	return taille;
}

int numberOfListeMusics (FILE* f){
	int nombreLigne =0;  
	char buff[1024];	

	while (fgets(buff,1023,f) != NULL) // traitement 
	{
		nombreLigne++;
	}
	rewind(f);
	return nombreLigne;
}

ListeMusic creationListeMusic (FILE* f){
	ListeMusic res = malloc(sizeof(Music));
	char buff[2048];
	
	// read one line
	fgets(buff,2047,f);
    res->val.name = malloc(sizeof(char*));
    res->val.name;
    res->val.name;
    res->val.name;


	res->val.name = strtok(buff,',');
    					//compteur a travers mon buffer

    res;
	return res;
}


ListeMusic** tabListeMusic(FILE* f)
{
	int nombreLigne = numberOfListeMusics(f); 
	printf("Total ListeMusics = %d\n",nombreLigne);
	ListeMusic** tabListeMusic = malloc(nombreLigne*sizeof(ListeMusic*));    //allocation dynamic de taille d'un tableau de ListeMusic.
	
	for(int k=0;k<nombreLigne;k++)
	{
		tabListeMusic[k]=creationListeMusic(f);					//ecriture du ListeMusic actuel dans le tableau.
	}
	return tabListeMusic;
}

//void print1ListeMusic(FILE*f,ListeMusic* ListeMusic){
	char buff[6];

	sprintf(buff,"%d",ListeMusic->year);
	buff[4] = ';';
	buff[5] = '\0';

	const char* write =buff;
	char buff2[]={';'};
	fwrite(write,sizeof(char),strlen(write),f);
	fwrite(ListeMusic->name,sizeof(char),tailleChaine(ListeMusic->name,'\0'),f);
	fwrite(buff2,sizeof(char),strlen(buff2),f);
	fwrite(ListeMusic->achievement,sizeof(char),tailleChaine(ListeMusic->achievement,'\0'),f);


}


void printListeMusics(int numberListeMusics, FILE* fOut, ListeMusic** tab){

	for (int i=0; i<numberListeMusics; i++){
		print1ListeMusic(fOut,tab[i]);
	}

}


