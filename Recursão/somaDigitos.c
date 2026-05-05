#include <stdio.h>


long int somaDigitos(int n) {
    if (n == 0) {
        return 0;
    } else if (n < 10) {
        return n;
    } else {
        return (n % 10) + somaDigitos(n / 10);
    }
}


int main(void){
    int numero;

    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    long int resultado = somaDigitos(numero);
    printf("A soma dos dígitos de %d é: %ld\n", numero, resultado);

    return 0;

}