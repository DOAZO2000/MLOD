/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring

 Tests
 diff out.csv turingWinners.csv

**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>


typedef struct {
	unsigned short year;
	char *name;
	char *achievement;
} Winner;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// MAIN
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int tailleChaine(char* buff){
	int taille=0;
		while((buff[taille])!='\0')			//arret au \0
		{		
			taille++;
		}
	return taille;
}

int numberOfWinners (FILE* f){
	int nombreLigne =0;  
	char buff[1024];	

	while (fgets(buff,1023,f) != NULL) // traitement 
	{
		nombreLigne++;
	}
	rewind(f);
	return nombreLigne;
}

Winner creationWinner (FILE* f){
	Winner res;
	char buff[2048];
	fgets(buff,2047,f);

	int k=0;					//compteur a travers mon buffer
// ecriture de year -------------
	while(buff[k]!=';')			//arret au premier point virgule.
	{		
		k++;
	}
	buff[k] = '\0';
	char* next;
	res.year = strtol(buff,&next,10);
	k++;
// ecriture de name

	int tailleName=tailleChaine(&(buff[k]));
	res.name = malloc((1+tailleName)*sizeof(char));
	// strcpy
	for(int i=0;i<tailleName;i++)			
	{		
		res.name[i]=buff[k];
		k++;
	}
	k++;
	res.name[k]='\0';
	k++;

// ecriture de achievement

	int tailleAchievement=tailleChaine(&(buff[k]));
	res.achievement = malloc((1+tailleAchievement)*sizeof(char));

	for(int i=0;i<tailleAchievement;i++)			
	{		
		res.achievement[i]=buff[k];
		k++;
	}
	k++;
	res.achievement[k]='\0';
	return res;
}


Winner** tabWinner(FILE* f)
{
	int nombreLigne = numberOfWinners(f);    						  //Nombre de ligne du fichier = nombre de Winner dans le tableau.
	Winner** tabWinner = malloc(nombreLigne*sizeof(Winner*));    //allocation dynamic de taille d'un tableau de Winner.
	
	for(int k=0;k<nombreLigne;k++)
	{
		tabWinner[k] = malloc(sizeof(Winner));
		*(tabWinner[k])=creationWinner(f);					//ecriture du winner actuel dans le tableau.

	}
	rewind(f);
	return tabWinner;

}

void print1Winner(FILE*f,Winner* winner){
	char buff[1024];
	sprintf(buff,"%d",(*winner).year);
	buff[4] = '\n';
	
	fwrite(buff,sizeof(char),tailleChaine(buff),f);
	fwrite((*winner).name,sizeof(char),tailleChaine((*winner).name),f);
	fwrite((*winner).achievement,sizeof(char),tailleChaine((*winner).achievement),f);

}


void printWinners(FILE* fIn, FILE* fOut, Winner** tab){
	int numberWinners = numberOfWinners(fIn);

	for (int i=0; i<numberWinners; i++){
		print1Winner(fOut,tab[i]);
	}

}

void infosAnnee(int annee){

}



int main(int argc, char** argv){

	// creation des structs
	char filename[] = "turingWinners.csv";
	char outputFilename[] = "out.csv";
	FILE* fIn;
	FILE* fOut;
	fIn = fopen(filename, "r");
	fOut = fopen(outputFilename, "w");

	Winner** winners = tabWinner(fIn);

	printWinners(fIn,fOut,winners);

	//evaluation des tests

	printf("------testEcriture2-----\n");

	//printf("année =%d\n",testWinner.year);
	//printf("nom(s)=%s\n",testWinner.name);
	//printf("accomplissement(s)=%s\n",testWinner.achievement);d

	printf("-----------\n");

    // TODO

	return EXIT_SUCCESS;
}
