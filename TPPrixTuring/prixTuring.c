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


int nombreDeLigne (FILE* f){
	int nombreLigne =0;  
	char buff[1024];	

	while (fgets(buff,1023,f) != NULL) // traitement 
	{
		nombreLigne++;
	}
	rewind(f);
	return nombreLigne;
}

int main(){

	// creation des structs
	char filename[] = "turingWinners.csv";
	char outputFilename[] = "out.csv";
	FILE* fIn;
	// FILE* fOut;
	fIn = fopen(filename, "r");
	// fOut = fopen(outputFilename, "r");

	//creation des tests

	//char test[2000];
	//char test2[2000];
	int nombreLigne;

	nombreLigne = nombreDeLigne(fIn);
	//fgets(test,2000,fIn);
	//fgets(test2,2000,fIn);


	//evaluation des tests

	printf("------7-----\n");
	//printf("%s\n", test);
	//printf("%s\n", test2);
	printf("%d\n", nombreLigne);

	printf("-----------\n");

    // TODO

	return EXIT_SUCCESS;
}
