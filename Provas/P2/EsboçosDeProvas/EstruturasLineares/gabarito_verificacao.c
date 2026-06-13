// Verificação do gabarito — Prova Esboço: Estruturas Lineares
// Parâmetros: matrícula 232037937 | nome "italo alves sampaio de oliveira"
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// ---------- Lista sequencial ----------
typedef struct { int v[MAX]; int n; } Lista;

int inserir(Lista *l, int x, int p) {
    if (l->n == MAX || p < 0 || p > l->n) return 0;
    for (int i = l->n; i > p; i--)
        l->v[i] = l->v[i - 1];
    l->v[p] = x;
    l->n++;
    return 1;
}
int removerSeq(Lista *l, int p) {
    if (p < 0 || p >= l->n) return 0;
    for (int i = p; i < l->n - 1; i++)
        l->v[i] = l->v[i + 1];
    l->n--;
    return 1;
}
void printLista(Lista *l) {
    printf("[");
    for (int i = 0; i < l->n; i++) printf("%d%s", l->v[i], i < l->n-1 ? "," : "");
    printf("], n=%d\n", l->n);
}

// ---------- Lista encadeada ----------
typedef struct no { int info; struct no *prox; } No;

void inserirInicio(No **l, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->info = valor;
    novo->prox = *l;
    *l = novo;
}
void inserirFim(No **l, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->info = valor;
    novo->prox = NULL;
    if (*l == NULL) { *l = novo; return; }
    No *atu = *l;
    while (atu->prox != NULL) atu = atu->prox;
    atu->prox = novo;
}
int removerVal(No **l, int valor) {
    No *ant = NULL, *atu = *l;
    while (atu != NULL && atu->info != valor) { ant = atu; atu = atu->prox; }
    if (atu == NULL) return 0;
    if (ant == NULL) *l = atu->prox;
    else ant->prox = atu->prox;
    free(atu);
    return 1;
}
void percorrer(No *l) {
    while (l != NULL) { printf("%d ", l->info); l = l->prox; }
    printf("\n");
}
// Q9 — versão ERRADA (No* em vez de No**)
void inserirErrado(No *l, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->info = valor;
    novo->prox = l;
    l = novo;   // só muda a cópia local!
}

// ---------- Pilha (vetor) ----------
typedef struct { int v[MAX]; int topo; } Pilha;   // topo = índice do topo, -1 vazia
void push(Pilha *p, int x) { p->v[++p->topo] = x; }
int pop(Pilha *p) { return p->v[p->topo--]; }

// ---------- Fila circular (vetor) ----------
typedef struct { int v[MAX]; int ini, fim, qtd; } Fila;
void enq(Fila *f, int x) { f->v[f->fim] = x; f->fim = (f->fim+1)%MAX; f->qtd++; }
int deq(Fila *f) { int x = f->v[f->ini]; f->ini = (f->ini+1)%MAX; f->qtd--; return x; }

// ---------- Lista duplamente encadeada ----------
typedef struct dno { int info; struct dno *ant, *prox; } DNo;
void dInserirFim(DNo **l, int valor) {
    DNo *novo = (DNo*) malloc(sizeof(DNo));
    novo->info = valor; novo->prox = NULL; novo->ant = NULL;
    if (*l == NULL) { *l = novo; return; }
    DNo *atu = *l;
    while (atu->prox != NULL) atu = atu->prox;
    atu->prox = novo; novo->ant = atu;
}
int dRemover(DNo **l, int valor) {
    DNo *atu = *l;
    while (atu != NULL && atu->info != valor) atu = atu->prox;
    if (atu == NULL) return 0;
    if (atu->ant != NULL) atu->ant->prox = atu->prox;
    else *l = atu->prox;
    if (atu->prox != NULL) atu->prox->ant = atu->ant;
    free(atu);
    return 1;
}

int main() {
    // Q1 — inserir 9 (7o dígito) na posição 2 de [2,3,2,0,3] (5 primeiros dígitos)
    Lista l1 = {{2,3,2,0,3}, 5};
    printf("Q1: inserir(9, pos 2) em [2,3,2,0,3]: ");
    inserir(&l1, 9, 2);
    printLista(&l1);

    // Q2 — remover posição 3 de [2,3,2,0,3]
    Lista l2 = {{2,3,2,0,3}, 5};
    printf("Q2: remover(pos 3) em [2,3,2,0,3]: ");
    removerSeq(&l2, 3);
    printLista(&l2);

    // Q3 — inserirInicio com 4 primeiros dígitos 2,3,2,0
    No *li3 = NULL;
    inserirInicio(&li3, 2); inserirInicio(&li3, 3);
    inserirInicio(&li3, 2); inserirInicio(&li3, 0);
    printf("Q3: inserirInicio 2,3,2,0 -> percorrer: ");
    percorrer(li3);

    // Q4 — misto: F(2), I(3), F(2), I(0)
    No *li4 = NULL;
    inserirFim(&li4, 2); inserirInicio(&li4, 3);
    inserirFim(&li4, 2); inserirInicio(&li4, 0);
    printf("Q4: F2,I3,F2,I0 -> percorrer: ");
    percorrer(li4);

    // Q5 — fim 2,3,2,0,3; remover valor 3 (primeira ocorrencia)
    No *li5 = NULL;
    inserirFim(&li5, 2); inserirFim(&li5, 3); inserirFim(&li5, 2);
    inserirFim(&li5, 0); inserirFim(&li5, 3);
    removerVal(&li5, 3);
    printf("Q5: [2,3,2,0,3] remover valor 3 -> percorrer: ");
    percorrer(li5);

    // Q6 — pilha: push 2,3,2,0,3; pop, pop; push 7; pop
    Pilha p = {.topo = -1};
    push(&p, 2); push(&p, 3); push(&p, 2); push(&p, 0); push(&p, 3);
    printf("Q6: pops imprimem: %d ", pop(&p));
    printf("%d ", pop(&p));
    push(&p, 7);
    printf("%d", pop(&p));
    printf(" | topo final = %d\n", p.v[p.topo]);

    // Q7 — fila: enq 2,3,2,0; deq, deq; enq 7; deq
    Fila f = {.ini = 0, .fim = 0, .qtd = 0};
    enq(&f, 2); enq(&f, 3); enq(&f, 2); enq(&f, 0);
    printf("Q7: deqs imprimem: %d %d ", deq(&f), deq(&f));
    enq(&f, 7);
    printf("%d", deq(&f));
    printf(" | frente final = %d\n", f.v[f.ini]);

    // Q8 — circular 2,3,2; do-while começando em inicio->prox
    No *n1 = malloc(sizeof(No)), *n2 = malloc(sizeof(No)), *n3 = malloc(sizeof(No));
    n1->info = 2; n2->info = 3; n3->info = 2;
    n1->prox = n2; n2->prox = n3; n3->prox = n1;
    printf("Q8: circular [2,3,2], do-while a partir de inicio->prox: ");
    No *atu = n1->prox;
    do { printf("%d ", atu->info); atu = atu->prox; } while (atu != n1->prox);
    printf("\n");

    // Q9 — inserirErrado nao modifica a lista
    No *li9 = NULL;
    inserirFim(&li9, 3); inserirFim(&li9, 7);
    inserirErrado(li9, 9);
    printf("Q9: [3,7] + inserirErrado(9) -> percorrer: ");
    percorrer(li9);

    // Q10 — dupla [2,3,7], remover 3, consultar ponteiros
    DNo *ld = NULL;
    dInserirFim(&ld, 2); dInserirFim(&ld, 3); dInserirFim(&ld, 7);
    dRemover(&ld, 3);
    printf("Q10: dupla [2,3,7] remove 3 -> inicio=%d, inicio->prox=%d, inicio->prox->ant=%d\n",
           ld->info, ld->prox->info, ld->prox->ant->info);

    return 0;
}
