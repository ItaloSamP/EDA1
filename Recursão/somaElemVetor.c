#include <stdio.h>

long int somavet(int *a, int qtde) {
    // Caso base: se a quantidade for 0, a soma é 0
    if (qtde <= 0) {
        return 0;
    }
    // Passo recursivo: último elemento + soma do restante
    return a[qtde - 1] + somavet(a, qtde - 1);
}

int main(void) {
    int a[] = {1, 2, 3, 4, 5};
    int qtde = sizeof(a) / sizeof(a[0]);

    long int soma = somavet(a, qtde);
    printf("A soma dos elementos do vetor é: %ld\n", soma);

    return 0;
}
