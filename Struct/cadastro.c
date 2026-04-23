#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int dia, mes, ano;
} Data;

typedef struct {
    char nome[50];
    float altura;
    Data nascimento;
} Pessoa;

void cadastrarPessoa(Pessoa *p) {
    printf("Nome: ");
    scanf(" %[^\n]s", p->nome); // O %[^\n] é uma alternativa ao fgets para ler espaços
    printf("Altura: ");
    scanf("%f", &p->altura);
    printf("Data de Nascimento (DD/MM/AAAA): ");
    scanf("%d/%d/%d", &p->nascimento.dia, &p->nascimento.mes, &p->nascimento.ano);
}

void listarPessoas(Pessoa lista[], int total) {
    printf("\n--- Lista de Pessoas ---\n");
    for (int i = 0; i < total; i++) {
        printf("%d. %s | Altura: %.2f | Nasc: %02d/%02d/%d\n", 
               i + 1, lista[i].nome, lista[i].altura, 
               lista[i].nascimento.dia, lista[i].nascimento.mes, lista[i].nascimento.ano);
    }
}

void atualizarAltura(Pessoa *p, float novaAltura) {
    p->altura = novaAltura;
    printf("Altura de %s atualizada com sucesso!\n", p->nome);

}


int main(void) {
    Pessoa bancoDeDados[5]; // Capacidade para 5 pessoas
    int qtd = 0;
    int opcao;

    do {
        printf("\n1. Cadastrar\n2. Listar\n3. Atualizar Altura\n0. Sair\nEscolha: ");
        scanf("%d", &opcao);

        if (opcao == 1 && qtd < 5) {
            cadastrarPessoa(&bancoDeDados[qtd]);
            qtd++;
        } else if (opcao == 2) {
            listarPessoas(bancoDeDados, qtd);
        } else if (opcao == 3 && qtd > 0) {
            float h;
            printf("Nova altura para a primeira pessoa: ");
            scanf("%f", &h);
            atualizarAltura(&bancoDeDados[0], h);
        }
    } while (opcao != 0);

    return 0;
}