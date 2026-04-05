#include <stdio.h>

int DescobreMaior(int *v, int tamanho){
    int maior = *v;
    int i;
    for(i = 1; i < tamanho; i++){
        if(*(v+i) > maior){
            maior = *(v+i);
        }
        else{
            continue;
        }
    }
    return maior;

    }

int main(){
    int v[7] = {3, 5, 2, 8, 1, 4, 7};
    int size = sizeof(v) / sizeof(v[0]);
    int maior = DescobreMaior(v, size);
    printf("O maior elemento do vetor é: %d\n", maior);
    return 0;

}