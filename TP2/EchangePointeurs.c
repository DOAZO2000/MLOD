#include <stdio.h>
void echangeContenu (int *a, int *b){
    int a1 = *a;
    int b1 = *b;
    *a = b1;
    *b = a1;
}

int main (){
    int a = 10;
    int b = 20;
    echangeContenu(&a, &b);
    printf("valeur de a: %d\n", a);
    printf("valeur de b: %d\n", b);
    return 0;
}