#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
} Pessoa;


int main (void) {
    Pessoa Lista[3];

    strcpy(Lista[0].nome, "Joao");
    Lista[0].idade = 25;

    strcpy(Lista[1].nome, "Maria");
    Lista[1].idade = 30;

    strcpy(Lista[2].nome, "Pedro");
    Lista[2].idade = 28;

    printf("Lista de Pessoas:\n");
    for (int i = 0; i < 3; i++) {
        printf("Nome: %s, Idade: %d\n", Lista[i].nome, Lista[i].idade);
    }

    return 0;
}