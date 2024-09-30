// gcc -W -Wall -std=c99 liste-chainee.c liste-chainee-main.c -o liste-chaine-main
// gcc -W -Wall -Wno-unused-parameter -std=c99 liste-chainee.c liste-chainee-main.c -o liste-chaine-main

#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

// tu dois redéfinir 3 fonctions externes dans le main

int main(void){
	Liste l, p;

	l = NULL;
	printf("estVide(l) = %s\n",estVide(l)?"TRUE":"FALSE");

	l = ajoutTete(1,l);
	l = ajoutTete(2,l);
	l = ajoutTete(4,l);
	l = ajoutTete(1,l);
	l = ajoutTete(5,l);
	l = ajoutTete(6,l);
	l = ajoutTete(2,l);
	l = ajoutTete(4,l);
	l = ajoutTete(1,l);

	afficheListe_i(l);
	detruire_r(l);

	return EXIT_SUCCESS;
}