#include <stdio.h>


typedef struct {
    char nome[50];
    float preco;
} Produto;

void imprimirProduto(Produto p){
    printf("--- Dados do Produto ---\n");
    printf("Nome: %s\n", p.nome);
    printf("Preço, %.2f\n", p.preco);

    p.preco += 10.0; // Modificando o preço dentro da função
    printf("Preço atualizado dentro da função: %.2f\n", p.preco);

}


int main (void) {
    Produto p1 = {"Camiseta", 29.99};

    printf("Preço do produto antes da função: %.2f\n", p1.preco);

    imprimirProduto(p1);

    printf("Preço do produto após a função: %.2f\n", p1.preco); // O preço original permanece inalterado

    return 0;
}
