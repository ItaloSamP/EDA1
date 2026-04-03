#include <stdio.h>

int main(void) {
    int v[5] = {10,30,50,70,90};
    int *p = v;
    int soma = 0;
    int i;

    printf("Vetores antes da soma: \n");
    for(i = 0; i < 5; i++){
        printf("%d\n", *(p + i));
        soma += *(p + i);
    }
    printf("\nSoma: %d\n", soma);
    return 0;
}