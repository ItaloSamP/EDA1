#include <stdio.h>

long int fibonacci(int n) {
    // Casos base
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    // Passo recursivo
    return fibonacci(n - 1) + fibonacci(n - 2);
}


int main(void) {
    int n;
    printf("Digite o valor de n para calcular o n-ésimo número de Fibonacci: ");
    scanf("%d", &n);

    long int result = fibonacci(n);
    printf("O %d-ésimo número de Fibonacci é: %ld\n", n, result);

    return 0;
}