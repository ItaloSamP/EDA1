#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    float preco;
}produto;

int main(void) {
    produto produto1;
    produto produto2;

    strcpy(produto1.nome, "Camiseta");
    produto1.preco = 49.99;
    strcpy(produto2.nome, "Calça");
    produto2.preco = 79.99;

    printf("Produto 1: %s, Preço: %.2f\n", produto1.nome, produto1.preco);
    printf("Produto 2: %s, Preço: %.2f\n", produto2.nome, produto2.preco);

    //Preço do conjunto dos produtos
    float preco_conjunto = produto1.preco + produto2.preco;
    printf("Preço do conjunto dos produtos: %.2f\n", preco_conjunto);

    return 0;


}