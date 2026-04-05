#include <stdio.h>

void inverte(int *v, int tamanho){
    int temp;
    int *inicio = v;
    int *fim = v + tamanho - 1;

    //Loop de inversão

    while (inicio < fim) {
        temp = *inicio;
        *inicio = *fim;
        *fim = temp;

        //Avança os ponteiros
        inicio++;
        fim--;
    }
    
}

int main(void){
    int i;
    int v[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int tamanho = sizeof(v) / sizeof(v[0]);
    printf("Vetor original: ");
    for (i = 0; i < tamanho; i++){
        printf("%d ", v[i]);
    
    }
    printf("\n");

    inverte(v, tamanho);

    printf("Vetor invertido: ");
    for (i = 0; i < tamanho; i++){
        printf("%d ", v[i]);
    }

    return 0;

}