#include <stdio.h>

void intercalacao(int *v1, int *v2, int *v3, int tamanho){
    int i = 0, j = 0;

    //Intercala os vetores v1 e v2 em v3 enquanto ambos tiverem elementos
    while(i < tamanho && j < tamanho){
        if(*v1 < *v2){
            *v3 = *v1;
            v1++;
            i++;
        } else // Se o elemento de v2 for menor ou igual ao de v1
        {
            *v3 = *v2;
            v2++;
            j++;
        }
        v3++; // Avança o ponteiro de v3 para a próxima posição
    }

    //Se restar em v1
    while(i < tamanho){
        *v3 = *v1; //Copia o valor de v1 para v3
        v1++;
        v3++;
        i++;
    }


    //Se restar em v2
    while(j < tamanho){
        *v3 = *v2; //Copia o valor de v2 para v3
        v2++;
        v3++;
        j++;
    }

}

int main(void){
    int v1[] = {1,3,5,7,9};
    int v2[] = {2,4,6,8,10};
    // v3 2 vezes o tamanho de v1 ou v2 para armazenar os elementos intercalados
    int v3 = (sizeof(v1) / sizeof(v1[0]) + sizeof(v2) / sizeof(v2[0])); // Calcula o tamanho de v3 com base no tamanho de v1 e v2
    int v3_array[v3];
    intercalacao(v1, v2, v3_array, sizeof(v1) / sizeof(v1[0]));

    printf("Vetor intercalado: ");

    for(int i = 0; i < v3; i++){
        printf("%d ", v3_array[i]);
    }
    printf("\n");
    return 0;
}