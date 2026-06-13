// Verificação do gabarito — Prova Esboço: Algoritmos de Busca
// Parâmetros: matrícula 232037937 | nome "italo alves sampaio de oliveira"
#include <stdio.h>
#include <string.h>

// Q1 — busca linear: posição da PRIMEIRA ocorrência
int Q1(char *s, char chave) {
    int p = 0;
    while (s[p] != '\0') {
        if (s[p] == chave) return p;
        p++;
    }
    return -1;
}

// Q2 — estilo prova 24.1: posição da ÚLTIMA ocorrência da letra derivada da matrícula
char letra(int P) {
    P = P % 26;
    return 'a' + P;
}
int Q2(char *nc, int matricula) {
    int p = 0, posic = -1;
    char chave = letra(matricula % 100);
    while (nc[p] != '\0') {
        if (chave == nc[p])
            posic = p;
        p++;
    }
    return posic;
}

// Q3 — busca linear com contador de comparações (para ao achar)
int Q3(char *s, char chave) {
    int p = 0, c = 0;
    while (s[p] != '\0') {
        c++;
        if (s[p] == chave) break;
        p++;
    }
    return c;
}

// Q4 — busca binária no nome ordenado, conta iterações (estilo Q3 24.1)
int Q4(char *nome, int tamanho, int matricula) {
    int inicio = 0, meio, fim = tamanho - 1, pcont = 0;
    char chave = nome[matricula % 10]; // chave tirada do nome ORIGINAL? não: do ordenado, como na 24.1
    printf("  [Q4] chave = '%c' (nomeOrdenado[%d])\n", chave, matricula % 10);
    while (inicio <= fim) {
        pcont++;
        meio = (inicio + fim) / 2;
        printf("  [Q4] it%d: inicio=%d fim=%d meio=%d nome[meio]='%c'\n", pcont, inicio, fim, meio, nome[meio]);
        if (chave == nome[meio]) break;
        else if (chave < nome[meio]) fim = meio - 1;
        else inicio = meio + 1;
    }
    return pcont;
}

// Q5 — busca binária em vetor de dígitos ordenado, retorna POSIÇÃO
int Q5(int v[], int n, int chave) {
    int inicio = 0, fim = n - 1, meio, it = 0;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        it++;
        printf("  [Q5] it%d: inicio=%d fim=%d meio=%d v[meio]=%d\n", it, inicio, fim, meio, v[meio]);
        if (v[meio] == chave) return meio;
        else if (chave < v[meio]) fim = meio - 1;
        else inicio = meio + 1;
    }
    return -1;
}

// Q6 — busca linear de char inexistente: retorno e nº de comparações
int Q6(char *s, char chave, int *comp) {
    int p = 0;
    *comp = 0;
    while (s[p] != '\0') {
        (*comp)++;
        if (s[p] == chave) return p;
        p++;
    }
    return -1;
}

// Q7 — conta OCORRÊNCIAS de um valor no vetor
int Q7(int v[], int n, int chave) {
    int c = 0;
    for (int i = 0; i < n; i++)
        if (v[i] == chave) c++;
    return c;
}

// Q8 — busca binária RECURSIVA, conta chamadas
int chamadasQ8 = 0;
int Q8(int v[], int inicio, int fim, int chave) {
    chamadasQ8++;
    if (inicio > fim) return -1;
    int meio = (inicio + fim) / 2;
    printf("  [Q8] chamada%d: inicio=%d fim=%d meio=%d v[meio]=%d\n", chamadasQ8, inicio, fim, meio, v[meio]);
    if (v[meio] == chave) return meio;
    if (chave < v[meio]) return Q8(v, inicio, meio - 1, chave);
    return Q8(v, meio + 1, fim, chave);
}

int cmpc(const void *a, const void *b) { return *(char*)a - *(char*)b; }

int main() {
    char nome[] = "italo alves sampaio de oliveira";
    int mat = 232037937;
    int n = (int)strlen(nome);

    // nome ordenado (espaços vão pro início, como no exemplo 24.1)
    char ord[64];
    strcpy(ord, nome);
    for (int i = 1; i < n; i++) {           // insertion sort
        char ch = ord[i]; int j = i - 1;
        while (j >= 0 && ord[j] > ch) { ord[j+1] = ord[j]; j--; }
        ord[j+1] = ch;
    }
    printf("nome ordenado = \"%s\" (len=%d)\n\n", ord, n);

    printf("Q1: primeira ocorrencia de nome[mat%%10]=nome[7]='%c' -> %d\n\n", nome[7], Q1(nome, nome[7]));

    printf("Q2: letra(37) = '%c'; ultima ocorrencia -> %d\n\n", letra(37), Q2(nome, mat));

    printf("Q3: comparacoes ate achar 'p' -> %d\n\n", Q3(nome, 'p'));

    printf("Q4 (binaria no nome ordenado):\n");
    printf("Q4 -> %d iteracoes\n\n", Q4(ord, n, mat));

    int dig[] = {0, 2, 2, 3, 3, 3, 7, 7, 9}; // dígitos da matrícula ordenados
    printf("Q5 (binaria nos digitos ordenados, chave=9):\n");
    printf("Q5 -> posicao %d\n\n", Q5(dig, 9, 9));

    int comp;
    int r6 = Q6(nome, 'z', &comp);
    printf("Q6: buscar 'z' -> retorno %d, comparacoes %d\n\n", r6, comp);

    int dignat[] = {2, 3, 2, 0, 3, 7, 9, 3, 7}; // dígitos na ordem natural
    printf("Q7: ocorrencias de 3 nos digitos -> %d\n\n", Q7(dignat, 9, 3));

    printf("Q8 (binaria recursiva, chave=2):\n");
    int r8 = Q8(dig, 0, 8, 2);
    printf("Q8 -> retorno %d, chamadas %d\n", r8, chamadasQ8);

    return 0;
}
