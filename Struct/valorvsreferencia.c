#include <stdio.h>

typedef struct {
    char name[50];
    float altura;
} Pessoa;


void alteraPorValor(Pessoa p){
    // Alterando a altura dentro da função por valor
    p.altura = 1.96;
    printf("Alterando por valor dentro da função: %.2f\n", p.altura);

}

void alteraPorReferencia(Pessoa *p) {
    p->altura = 1.96;
    printf("Alterando por referência dentro da função: %.2f\n", p->altura);
}


int main(void) {
    Pessoa p1 = {
        "Ítalo",
        1.90
    };

    printf("Altura original: %.2f\n", p1.altura);

    alteraPorValor(p1);
    printf("Altura após alteração por valor: %.2f\n", p1.altura);

    alteraPorReferencia(&p1);
    printf("Altura após alteração por referência: %.2f\n", p1.altura);

    return 0;


}