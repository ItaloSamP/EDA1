#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int dia, mes, ano;
}Data;

typedef struct{
    char nome[50];
    Data nascimento;
}Pessoa;


int main(void) {
    Pessoa p;

    printf("Digite o nome da pessoa: ");
    fgets(p.nome, sizeof(p.nome), stdin);
    p.nome[strcspn(p.nome, "\n")] = '\0'; // Remove o caractere de nova linha
    printf("Digite a data de nascimento (dd mm aaaa): ");
    scanf("%d/%d/%d", &p.nascimento.dia, &p.nascimento.mes, &p.nascimento.ano);
    while (getchar() != '\n'); // Limpa o buffer de entrada
    
    printf("%s %02d/%02d/%d\n", p.nome, p.nascimento.dia, p.nascimento.mes, p.nascimento.ano);

    return 0;
}