#include <stdio.h>


long int produtoSomando(int a, int b){
    if (b == 1) {
        return a;
    }
    if (a == 0 || b == 0){
        return 0;
    } else {
        return a + produtoSomando(a, b - 1);
    }
    
}

int main(void){
    int a, b;

    printf("Digite o primeiro número inteiro: ");
    scanf("%d", &a);
    printf("Digite o segundo número inteiro: ");
    scanf("%d", &b);

    long int resultado = produtoSomando(a, b);
    printf("O produto de %d e %d é: %ld\n", a, b, resultado);

    return 0;
}