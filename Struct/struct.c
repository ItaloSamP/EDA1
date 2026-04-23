#include <stdio.h>

typedef struct {
    char marca[50];
    int ano;
    float preco;
}Carro;

int main() {
    Carro Carro1 = {
        "Hyundai",
        2018,
        70000.00
    };

    printf("Marca: %s\n", Carro1.marca);
    printf("Ano: %d\n", Carro1.ano);
    printf("Preço: %.2f\n", Carro1.preco);

    return 0;
}