#include <stdio.h>


int maiorElemento(int *a, int qtde){
    if (qtde == 1) {
        return a[0];
    }
    int maior = maiorElemento(a, qtde - 1);
    if (a[qtde -1] > maior){
        return a[qtde -1]; // retorna o maior elemento encontrado
    } else {
        return maior;
    }
 
}

int main() {
    int a[] = {3, 5, 2, 8, 1};
    int qtde = sizeof(a) / sizeof(a[0]);
    int maior = maiorElemento(a, qtde);
    printf("O maior elemento do array é: %d\n", maior);
    return 0;
}