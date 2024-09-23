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
// strlen
int tailleChaine(char* buff, char marker){
	int taille=0;
		while((buff[taille])!=marker)			//arret au marker
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

Winner *creationWinner (FILE* f){
	Winner *res = malloc(sizeof(Winner));
	char buff[2048];
	
	// read one line
	fgets(buff,2047,f);

	int k=0;					//compteur a travers mon buffer
	while(buff[k]!=';')			//arret au premier point virgule.
	{		
		k++;
	}
	buff[k] = '\0';
	char* next;
	res->year = strtol(buff,&next,10);

	printf("year = %d\n",res->year);

	k++;
// ecriture de name

	int tailleName=tailleChaine(&(buff[k]),';');
	res->name = malloc((tailleName)*sizeof(char));
	// strcpy
	printf("taille Name =%d\n",tailleName);
	for(int i=0;i<tailleName;i++)			
	{		
		res->name[i]=buff[k];
		k++;
	}
	res->name[k]='\0';
	printf("name = %s\n",res->name);

	k++;

// ecriture de achievement

	int tailleAchievement=tailleChaine(&(buff[k]),'\0');
	res->achievement = malloc((tailleAchievement)*sizeof(char));

	for(int i=0;i<tailleAchievement;i++)			
	{		
		res->achievement[i]=buff[k];
		k++;
	}
	res->achievement[k]='\0';
	printf("achievement = %s\n",res->achievement);
	
	return res;
}


Winner** tabWinner(FILE* f)
{
	int nombreLigne = numberOfWinners(f); 
	printf("Total winners = %d\n",nombreLigne);
	Winner** tabWinner = malloc(nombreLigne*sizeof(Winner*));    //allocation dynamic de taille d'un tableau de Winner.
	
	for(int k=0;k<nombreLigne;k++)
	{
		tabWinner[k]=creationWinner(f);					//ecriture du winner actuel dans le tableau.
	}
	return tabWinner;
}

void print1Winner(FILE*f,Winner* winner){
	char buff[2048];

	sprintf(buff,"%d",(*winner).year);
	buff[4] = ';';
	buff[5] = '\0';
	// char* buff1=strcpy(&(buff[5]),(*winner).name);
	// buff1[tailleChaine((*winner).name,'\0')]=';';
	// strcpy(&buff1[1+tailleChaine((*winner).name,'\0')],(*winner).achievement);
	
	// printf("buff1 =%s\n",buff1);
	printf("buffer du print1winnner =%s\n",buff);

	//fwrite(buff,sizeof(char),tailleChaine(buff,'\0'),f);
	int nbSuccess=fwrite(winner->name,sizeof(char),strlen(winner->name),f);
	fwrite(winner->achievement,sizeof(char),tailleChaine(winner->achievement,'\0'),f);
	printf("nombre de caracteres ecris =%d\n",nbSuccess);

}


void printWinners(FILE* fIn, FILE* fOut, Winner** tab){
	int numberWinners = numberOfWinners(fIn);

	for (int i=0; i<numberWinners; i++){
		print1Winner(fOut,tab[i]);
	}

}

void infosAnnee(int annee){

}

void sortTuringWinnersByYear(FILE* f){

}


int main(int argc, char** argv){

	// creation des structs
	char filename[] = "turingWinners.csv";
	char outputFilename[] = "out.csv";
	FILE* fIn;
	FILE* fOut;
	fIn = fopen(filename, "r");
	fOut = fopen(outputFilename, "w");

	Winner *one = creationWinner(fIn);
	print1Winner(fOut,one);
	printf("error ? =%d",ferror(fOut));
	
	//Winner** winners = tabWinner(fIn);
	//rewind(f);
	//printWinners(fIn,fOut,winners);

	//evaluation des tests

	// printf("------testEcriture2-----\n");

	//printf("année =%d\n",testWinner.year);
	//printf("nom(s)=%s\n",testWinner.name);
	//printf("accomplissement(s)=%s\n",testWinner.achievement);d

	// printf("-----------\n");

	return EXIT_SUCCESS;
}
