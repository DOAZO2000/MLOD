//DaSilva

#include<stdio.h>
#include<stdlib.h>


unsigned int sizeRepeat (int t1[], int t2[], unsigned int sizet1, unsigned int sizet2){
    if(sizet1==sizet2){
        unsigned int sizeTr =0;
        for(int i =0; i<sizet1; i++){
            sizeTr += t1[i]*sizeof(1);
        }
        return sizeTr;
    }
    
}
int* repeat (int t1[], int t2[], unsigned int sizet1, unsigned int sizet2){
    if(sizet1==sizet2){
        unsigned int sizeTr = sizeRepeat(t1,t2,sizet1,sizet2);
        int* tr = malloc(sizeTr);
        int k=0;
        for(int i =0; i<sizet1; i++){
            for(int j=0; j<t1[i];j++){
                *(tr+k+j)=t2[i];
            }
        }

    }
    }


void main(){
    int t1 [] = {1,2,4};
    int t2 [] = {10,3,8};
    unsigned sizet1 = sizeof(t1);
    unsigned sizet2 = sizeof(t2);
    unsigned int sizeTr = sizeRepeat(t1,t2,sizet1,sizet2);
    int* tr = malloc(sizeTr);
    tr = repeat(t1,t1, sizet1, sizet2);
    for(int i=0; i<(sizeTr/sizeof(1)); i++){
        printf("%n ", tr[i]); 
    }

}