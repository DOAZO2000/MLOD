#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE 5

void matrix_mult(int64_t Mres[][SIZE], int64_t M1[][SIZE],int64_t M2[][SIZE]){
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            int64_t sum=0;
            for (int k = 0; k < SIZE; k++)
            {
                sum+= M1[i][k]*M2[k][j];
            }
            Mres[i][j]=sum;
        }
    }
}

void matrix_print(int64_t Mres[SIZE][SIZE]){
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf ("%d ",Mres[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    //matrices en ligne * colonne
    int64_t matrice1[][SIZE]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
    int64_t matrice2[][SIZE]={{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10}};
    int64_t matriceResultat[SIZE][SIZE];

    matrix_mult(matriceResultat,matrice1,matrice2);
    matrix_print(matriceResultat);
    return EXIT_SUCCESS;
}