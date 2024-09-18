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


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// MAIN
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main(){
	char filename[] = "turingWinners.csv";
	//char outputFilename[] = "out.csv";
	FILE* f;
	char test[10];
	int test2;


	f = fopen(filename, "r");
	fgets(test,10,f);
	test2 =fgetc(f);

	char* bloc[10];
	int taillef;




	printf("-----------\n");
	printf("%s\n", test);
	printf("%c\n", test2);
	printf("-----------\n");

    // TODO

	return EXIT_SUCCESS;
}
