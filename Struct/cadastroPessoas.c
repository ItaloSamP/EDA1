#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
} Pessoa;


int main(void){
    Pessoa p;

    printf("Digite a idade da pessoa: ");
    scanf("%d", &p.idade);

    while (getchar() != '\n'); // Limpa o buffer de entrada

    printf("Digite o nome da pessoa: ");
    fgets(p.nome, 50, stdin);
    p.nome[strcspn(p.nome, "\n")] = '\0'; // Remove o caractere de nova linha do final da string

    printf("Pessoas cadastradas:\n");
    printf("Nome: %s, Idade: %d\n", p.nome, p.idade);

    return 0;
    

}