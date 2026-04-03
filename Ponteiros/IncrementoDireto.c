#include <stdio.h>

int main(void){
    int x = 10, y = 20;
    int *p1, *p2;
    int *temp;
    p1 = &x, p2 = &y;

    printf("Questao 2 - Ponteiros\n\n");
    printf("Valor de x antes da troca: %d\n", x);
    printf("Valor de y antes da troca: %d\n\n", y);
    printf("O valor apontado por p1: %d\n", *p1);
    printf("O valor apontado por p2: %d\n\n", *p2);

    temp = p1;
    p1 = p2;
    p2 = temp;

    printf("Valor de x depois da troca: %d\n", x);
    printf("Valor de y depois da troca: %d\n", y);
    printf("O valor apontado por p1: %d\n", *p1);
    printf("O valor apontado por p2: %d\n\n", *p2);

    return 0;

}