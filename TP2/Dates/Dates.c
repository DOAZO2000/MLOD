#include <stdio.h>
#include <stdlib.h>

enum enumMois {
    Janvier = 1,
    Fevrier,
    Mars,
    Avril,
    Mai,
    Juin,
    Juillet,
    Aout,
    Septembre,
    Octobre,
    Novembre,
    Décembre
};

typedef enum enumMois mois;
struct Date
{
    unsigned short jour;
    mois mois;
    unsigned short annee;
};
typedef struct Date Date;
 


void initialiseDate(Date* d){
    printf("jour :");
    scanf("%hu",&(*d).jour);
    printf("mois :");
    scanf("%d",(int *)&(*d).mois);
    printf("année :");
    scanf("%d",&(*d).annee );
}


void afficheDate (Date *d){
    printf("La date est : %hu/%d/%hu",(*d).jour,(*d).mois,(*d).annee);
} 

Date* newDate(){
    Date *d;
    d = malloc(sizeof(Date));
    initialiseDate(d);
    return d;
}


int main (void){
    printf("version 1\n");
    Date d;
    initialiseDate(&d); //Pourquoi a t-on ajouté un &?
    afficheDate(&d);

    printf("\nversion 3 : allocation dynamique d'une date.\n");
    Date* pDate;
    pDate = newDate();
    afficheDate(pDate);
    free(pDate);
    pDate = NULL;

    // printf("\nversion 3.1 : allocation dynamique d'un tableau de date\n");
    // int nbDates;
    // printf("\nEntrer le nombre de date :\n");
    // scanf("%d", &nbDates);

    // Date* tabDates [nbDates];
    // for(int i=1;i<nbDates;i++){
        
    }





} 

