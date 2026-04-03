#include <stdio.h>

int main(void) {
    int numero = 10;
    float real = 5.5f;

    int *p_numero;
    float *p_real;

    p_numero = &numero;
    p_real = &real;

    printf("Questao 1 - Inspecao de memoria\n\n");

    printf("Variavel inteira\n");
    printf("Valor de numero: %d\n", numero);
    printf("Endereco de numero: %p\n", (void *)&numero);
    printf("Endereco guardado em p_numero: %p\n", (void *)p_numero);
    printf("Valor apontado por p_numero: %d\n\n", *p_numero);

    printf("Variavel float\n");
    printf("Valor de real: %.2f\n", real);
    printf("Endereco de real: %p\n", (void *)&real);
    printf("Endereco guardado em p_real: %p\n", (void *)p_real);
    printf("Valor apontado por p_real: %.2f\n\n", *p_real);

    printf("Observacao:\n");
    printf("- &x significa o endereco da variavel x.\n");
    printf("- *p significa o valor armazenado no endereco apontado por p.\n");
    printf("- Nunca use *p antes de fazer o ponteiro apontar para um endereco valido.\n");

    return 0;
}
