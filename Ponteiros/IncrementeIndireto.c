#include <stdio.h>

int main(void) {
    int x = 10;
    int *ptr = &x;

    printf("Questão 3: Incrementando o valor de x indiretamente usando ponteiros\n");
    printf("Valor de x antes do incremento: %d\n", *ptr);

    *ptr = *ptr + 1;
    printf("Valor de x depois do incremento: %d\n", *ptr);

    *ptr = (*ptr * 2)* *ptr;
    printf("Valor de x depois de multiplicar por 2 e depois por ele mesmo: %d\n", *ptr);



    return 0;
};