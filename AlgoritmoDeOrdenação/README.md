# Algoritmos de Ordenação

> EDA1 — UnB Gama · Material: `algoritmos_ordenacao.html` · Teoria para provas: `teoria_ordenacao_prova.html`

Um conjunto ordenado reduz drasticamente o esforço computacional para buscas e outras operações. Cinco métodos são estudados, com diferentes trocas entre tempo, memória e estabilidade.

**Conceitos-chave:**
- **Estável:** mantém a ordem relativa de elementos com chaves iguais.
- **In-place:** usa apenas memória adicional constante (além do próprio vetor).
- **Recursivo:** se divide o problema em subproblemas menores de si mesmo.

---

## Índice

1. [Selection Sort](#1-selection-sort)
2. [Insertion Sort](#2-insertion-sort)
3. [Bubble Sort](#3-bubble-sort)
4. [QuickSort](#4-quicksort)
5. [Merge Sort](#5-merge-sort)
6. [Como identificar cada tipo](#como-identificar-cada-tipo)
7. [Tabela comparativa](#tabela-comparativa)

---

## 1. Selection Sort

Encontra o **menor elemento** do restante e o coloca na posição correta. Repete até ordenar todo o vetor.

```c
int smallerIndex(int vet[], int tam, int ini) {
    int min = ini;
    for (int j = ini + 1; j < tam; j++)
        if (vet[min] > vet[j])
            min = j;
    return min;
}

void selectionSort(int vet[], int tam) {
    for (int i = 0; i < tam; i++) {
        int min = smallerIndex(vet, tam, i);
        int aux = vet[i]; vet[i] = vet[min]; vet[min] = aux;
    }
}
```

**Complexidade:** melhor **O(n²)** · pior O(n²) · estável: sim · in-place: sim

---

## 2. Insertion Sort

Para cada elemento, **desloca os maiores** à sua esquerda e insere o elemento em sua posição correta na parte já ordenada.

```c
void insertionSort(int list[], int n) {
    for (int i = 1; i < n; i++) {
        int next = list[i];
        int j = i - 1;
        for (; j >= 0 && next < list[j]; j--)
            list[j + 1] = list[j];
        list[j + 1] = next;
    }
}
```

**Complexidade:** melhor **O(n)** (vetor já ordenado) · pior O(n²) · estável: sim · in-place: sim

---

## 3. Bubble Sort

Compara e troca **elementos adjacentes** que estão fora de ordem. A cada passagem, o maior elemento "sobe" até sua posição final.

```c
void bubbleSort(int vet[], int tam) {
    for (int i = tam - 1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (vet[j] > vet[j + 1]) {
                int temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
            }
}
```

**Complexidade:** melhor O(n) · pior O(n²) · estável: sim · in-place: sim

---

## 4. QuickSort

Algoritmo recursivo de **divisão e conquista**. Escolhe um **pivô**, particiona o vetor (menores à esquerda, maiores à direita) e ordena recursivamente cada parte.

```c
// Particiona v[p..r]: retorna j tal que v[p..j-1] <= v[j] < v[j+1..r]
int separa(int v[], int p, int r) {
    int c = v[r];           // pivô = último elemento
    int t, j = p;
    for (int k = p; k < r; ++k)
        if (v[k] <= c) {
            t = v[j]; v[j] = v[k]; v[k] = t;
            ++j;
        }
    t = v[j]; v[j] = v[r]; v[r] = t;
    return j;
}

void quicksort(int v[], int p, int r) {
    if (p < r) {
        int j = separa(v, p, r);
        quicksort(v, p, j - 1);
        quicksort(v, j + 1, r);
    }
}
```

**Complexidade:** melhor O(n log n) · pior O(n²) (vetor ordenado + pivô extremo) · estável: sim · in-place: sim · recursivo: sim

---

## 5. Merge Sort

Recursivo (divisão e conquista). Divide o vetor ao meio até ter subvetores de 1 elemento e depois **intercala** as metades ordenadas. Usa vetor temporário.

```c
void intercala(int p, int q, int r, int v[]) {
    int *w = malloc((r - p) * sizeof(int));
    int i = p, j = q, k = 0;
    while (i < q && j < r)
        w[k++] = (v[i] <= v[j]) ? v[i++] : v[j++];
    while (i < q) w[k++] = v[i++];
    while (j < r) w[k++] = v[j++];
    for (i = p; i < r; ++i) v[i] = w[i - p];
    free(w);
}

void mergesort(int p, int r, int v[]) {
    if (p < r - 1) {
        int q = (p + r) / 2;
        mergesort(p, q, v);
        mergesort(q, r, v);
        intercala(p, q, r, v);
    }
}
```

**Complexidade:** melhor **O(n log n)** · pior **O(n log n)** · estável: sim · in-place: **não** (usa O(n) extra) · recursivo: sim

---

## Como identificar cada tipo

Use estes padrões para reconhecer o algoritmo de ordenação em um código:

### Selection Sort
```
SINAL: loop externo i de 0 a n, loop interno busca o MENOR índice,
       troca vet[i] com vet[min_encontrado]
```
```c
for (i = 0; i < tam; i++) {
    min = i;
    for (j = i + 1; j < tam; j++)    // <--- busca o mínimo
        if (vet[j] < vet[min]) min = j;
    // troca vet[i] com vet[min]
}
// identificador: busca do índice mínimo a cada iteração
```

### Insertion Sort
```
SINAL: loop externo i de 1 a n, salva list[i] em variável (next/temp),
       loop interno j caminha para ESQUERDA enquanto next < list[j],
       desloca list[j] para list[j+1]
```
```c
for (i = 1; i < n; i++) {
    next = list[i];                          // <--- salva o elemento
    for (j = i - 1; j >= 0 && next < list[j]; j--)
        list[j + 1] = list[j];              // <--- desloca para direita
    list[j + 1] = next;                     // <--- insere na posição certa
}
// identificador: desloca elementos para a direita, insere ao final
```

### Bubble Sort
```
SINAL: dois loops aninhados, compara vet[j] com vet[j+1] (ADJACENTES),
       troca se estiver fora de ordem, loop externo decrescente ou crescente
```
```c
for (i = tam - 1; i > 0; i--)
    for (j = 0; j < i; j++)
        if (vet[j] > vet[j + 1]) {    // <--- compara adjacentes
            // troca vet[j] e vet[j+1]
        }
// identificador: sempre compara índices j e j+1
```

### QuickSort
```
SINAL: função separa/particiona que retorna índice do pivô,
       duas chamadas recursivas simétricas: (p, j-1) e (j+1, r),
       pivô geralmente v[r] (último) ou v[(p+r)/2] (meio)
```
```c
void quicksort(int v[], int p, int r) {
    if (p < r) {
        int j = separa(v, p, r);       // <--- particionamento
        quicksort(v, p, j - 1);        // <--- metade esquerda
        quicksort(v, j + 1, r);        // <--- metade direita
    }
}
// identificador: pivot, duas chamadas recursivas com índices complementares
```

### Merge Sort
```
SINAL: função intercala/merge separada, divide ao meio (q = (p+r)/2),
       TRÊS chamadas: mergesort(p,q), mergesort(q,r), intercala(p,q,r),
       usa malloc/vetor auxiliar na intercalação
```
```c
void mergesort(int p, int r, int v[]) {
    if (p < r - 1) {
        int q = (p + r) / 2;           // <--- divide ao meio
        mergesort(p, q, v);            // <--- ordena metade esquerda
        mergesort(q, r, v);            // <--- ordena metade direita
        intercala(p, q, r, v);         // <--- junta as metades
    }
}
// identificador: divide + conquista + intercala, usa memória extra
```

---

## Tabela comparativa

| Algoritmo | Melhor | Pior | Estável | In-place | Recursivo |
|-----------|--------|------|---------|----------|-----------|
| Selection Sort | O(n²) | O(n²) | Sim | Sim | Não |
| Insertion Sort | **O(n)** | O(n²) | Sim | Sim | Não |
| Bubble Sort | O(n) | O(n²) | Sim | Sim | Não |
| QuickSort | O(n log n) | O(n²) | Sim | Sim | Sim |
| Merge Sort | **O(n log n)** | **O(n log n)** | Sim | **Não** | Sim |

**Resumo prático:**
- Vetores pequenos ou quase ordenados → **Insertion Sort** (O(n) no melhor caso).
- Vetores grandes, uso geral → **QuickSort** (O(n log n) médio, constante pequena).
- Desempenho garantido → **Merge Sort** (O(n log n) sempre, mas usa O(n) extra).
- Selection Sort → evitar na prática (sempre O(n²), sem ganho com dados ordenados).
