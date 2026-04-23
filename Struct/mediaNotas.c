#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    float nota;
} Aluno;


int main(void){
    Aluno alunos[5];

    alunos[0].nota = 8.5;
    alunos[1].nota = 7.0;
    alunos[2].nota = 9.0;
    alunos[3].nota = 6.5;
    alunos[4].nota = 9.5;

    printf("Calculando a média das notas dos alunos:\n");
    float soma = 0.0;
    for (int i = 0; i < 5; i++){
        soma += alunos[i].nota;
    }
    float media = soma / 5;
    printf("A média das notas é: %.2f\n", media);

    return 0;

}