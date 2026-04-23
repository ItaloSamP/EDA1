#include <stdio.h>
#include <string.h>


struct aluno {
    char nome[60];
    int idade;
    float nota;
};

int main(void) {

    struct aluno dadosAluno;
    strcpy(dadosAluno.nome, "João Silva");
    dadosAluno.idade = 17;
    dadosAluno.nota = 8.5;


    printf("Nome: %s\n", dadosAluno.nome);
    printf("Idade: %d\n", dadosAluno.idade);
    printf("Nota: %.2f\n", dadosAluno.nota);

}