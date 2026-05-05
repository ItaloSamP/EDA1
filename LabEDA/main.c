#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tipos.h"



void reset(TTemperaturas *temp){
    if (temp->qtde_medidas != NULL){
        free(temp->medidas.temperatura);
    }

    printf("Digite a quantidade máxima de dias:");
    scanf("%d", &temp->qtde_dias);

    temp->medidas.temperatura = (float *) malloc(temp->qtde_dias * sizeof(float));

    if(temp->medidas.temperatura == NULL){
        printf("Erro ao alocar memória!");
        exit(1);
    }

    temp->qtde_medidas = 0;
    printf("Sistema resetado com sucesso para %d dias!\n", temp->qtde_dias);

}



void inserir(TTemperaturas *temp){
    if (temp->qtde_medidas >= temp->qtde_dias){
        printf("Limite de dias atingido! Por favor, reset o sistema para inserir mais medidas.\n");
        return;
    }

    if (temp->qtde_medidas == 0){
        printf("Digite o nome da cidade:");
        scanf("%s", temp->medidas.cidade);
    }

    printf("Digite a temperatura:");
    scanf("%f", &temp->medidas.temperatura[temp->qtde_medidas]);
    temp->qtde_medidas++;
    printf("Temperatura inserida com sucesso!\n");

}


void estatisticas(TTemperaturas *temp){
    if(temp->qtde_medidas == 0){
        printf("Nenhuma medida registrada! Por favor, insira medidas para calcular as estatísticas.\n");
        return;
    }

    float soma = 0, menor, maior;
    menor = maior = temp->medidas.temperatura[0];

    for (int i = 0; i < temp->qtde_medidas; i++){
        float t = temp->medidas.temperatura[i];
        soma += t;
        if (t < menor) menor = t;
        if (t > maior) maior = t;
    }

    printf("\n--- Estatisticas (%s) ---\n", temp->medidas.cidade);
    printf("Media: %.2f\n", soma / temp->qtde_medidas);
    printf("Menor: %.2f\n", menor);
    printf("Maior: %.2f\n", maior);

}



int main(void) {
    TTemperaturas dados;
    dados.medidas.temperatura = NULL; // Inicializa o ponteiro para evitar acesso indevido
    int opcao;

    do {
        printf("\n1. Reset\n2. Inserir Medida\n3. Estatistica\n4. Sair\nEscolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                reset(&dados);
                break;
            case 2:
                inserir(&dados);
                break;
            case 3:
                estatisticas(&dados);
                break;
            case 4:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida! Por favor, escolha uma opcao entre 1 e 4.\n");
        }
    } while (opcao != 4);

    // Libera a memória alocada antes de sair
    if (dados.medidas.temperatura != NULL) {
        free(dados.medidas.temperatura);
    }

    return 0;


}