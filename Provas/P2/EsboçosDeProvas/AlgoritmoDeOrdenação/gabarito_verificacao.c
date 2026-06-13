// Verificação do gabarito — Prova Esboço: Algoritmos de Ordenação
// Parâmetros: matrícula 232037937 | nome "italo alves sampaio de oliveira"
#include <stdio.h>
#include <string.h>

// Q1/Q2/Q3 — estilo Q4 da prova 24.1: troca quando vet[i] < vet[j] (DECRESCENTE)
int Q1(char *vet, int count) {
    int pcont = 0;
    char aux;
    for (int i = 0; i < count; i++)
        for (int j = i + 1; j < count; j++)
            if (vet[i] < vet[j]) {
                aux = vet[i]; vet[i] = vet[j]; vet[j] = aux;
                pcont++;
                printf("  [Q1] troca i=%d j=%d -> %s\n", i, j, vet);
            }
    return pcont;
}

// Q4/Q5 — estilo Q5 da prova 24.1: insertion sort contando deslocamentos
int Q4(char vetor[], int tamanho) {
    int trocas = 0, j, i;
    char chave;
    for (i = 1; i < tamanho; i++) {
        chave = vetor[i];
        j = i - 1;
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--; trocas++;
        }
        vetor[j + 1] = chave;
        printf("  [Q4] i=%d chave=%c -> %s (trocas acum=%d)\n", i, chave, vetor, trocas);
    }
    return trocas;
}

// Q6 — bubble sort com flag: conta PASSADAS em vetor já ordenado
int Q6(int v[], int n) {
    int passes = 0, trocou = 1, aux;
    while (trocou) {
        trocou = 0;
        passes++;
        for (int i = 0; i < n - 1; i++)
            if (v[i] > v[i + 1]) {
                aux = v[i]; v[i] = v[i + 1]; v[i + 1] = aux;
                trocou = 1;
            }
    }
    return passes;
}

// Q7 — selection sort com guarda: conta TROCAS efetivas
int Q7(int v[], int n) {
    int trocas = 0, min, aux;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++)
            if (v[j] < v[min]) min = j;
        if (min != i) {
            aux = v[i]; v[i] = v[min]; v[min] = aux;
            trocas++;
            printf("  [Q7] i=%d troca com min=%d -> ", i, min);
            for (int k = 0; k < n; k++) printf("%d", v[k]);
            printf("\n");
        }
    }
    return trocas;
}

// Q8 — bubble sort: estado após a PRIMEIRA passada
void Q8(int v[], int n) {
    int aux;
    for (int i = 0; i < n - 1; i++)
        if (v[i] > v[i + 1]) { aux = v[i]; v[i] = v[i + 1]; v[i + 1] = aux; }
    printf("  [Q8] apos 1a passada: ");
    for (int k = 0; k < n; k++) printf("%d ", v[k]);
    printf("\n");
}

int main() {
    // Q1/Q2/Q3 — primeiro nome "italo", 5 letras
    char nc1[] = "italo";
    printf("Q1 (decrescente em \"italo\"):\n");
    int r1 = Q1(nc1, 5);
    printf("Q1 -> trocas=%d, string final=\"%s\"\n\n", r1, nc1);

    // Q4 — insertion no último nome "oliveira", 8 letras
    char nc2[] = "oliveira";
    printf("Q4 (insertion em \"oliveira\", tamanho 8):\n");
    int r4 = Q4(nc2, 8);
    printf("Q4 -> trocas=%d, string final=\"%s\"\n\n", r4, nc2);

    // Q5 — PEGADINHA estilo 24.1: tamanho MENOR que a string ("sampaio", 6)
    char nc3[] = "sampaio";
    printf("Q5 (insertion em \"sampaio\" com tamanho 6 — pegadinha!):\n");
    int r5 = Q4(nc3, 6);
    printf("Q5 -> trocas=%d, string final=\"%s\"\n\n", r5, nc3);

    // Q6 — bubble com flag em vetor JA ordenado (digitos ordenados)
    int vord[] = {0, 2, 2, 3, 3, 3, 7, 7, 9};
    printf("Q6 (bubble c/ flag em vetor ordenado) -> passadas=%d\n\n", Q6(vord, 9));

    // Q7 — selection nos dígitos da matrícula
    int dig[] = {2, 3, 2, 0, 3, 7, 9, 3, 7};
    printf("Q7 (selection nos digitos 232037937):\n");
    int r7 = Q7(dig, 9);
    printf("Q7 -> trocas efetivas=%d\n\n", r7);

    // Q8 — bubble 1a passada nos dígitos
    int dig2[] = {2, 3, 2, 0, 3, 7, 9, 3, 7};
    printf("Q8 (bubble 1a passada nos digitos):\n");
    Q8(dig2, 9);

    return 0;
}
