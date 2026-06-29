# Árvores, Listas Encadeadas, Pilhas e Filas

> EDA1 — UnB Gama · Material: `arvores.html` · Teoria para provas: `teoria_arvores_prova.html` · Simulado: `simulado_arvores.html`

Revisão completa de **árvores binárias**, **árvores binárias de busca (BST)**, **listas encadeadas** (com e sem descritor), **pilhas** e **filas** — com todas as notações Big O de cada operação.

---

## Índice

1. [Árvore Binária — conceitos e propriedades](#1-árvore-binária--conceitos-e-propriedades)
2. [Árvore Binária de Busca (BST)](#2-árvore-binária-de-busca-bst)
3. [Percorrimentos em árvores](#3-percorrimentos-em-árvores)
4. [Lista Encadeada — revisão](#4-lista-encadeada--revisão)
5. [Lista com Descritor](#5-lista-com-descritor)
6. [Pilha — revisão](#6-pilha--revisão)
7. [Fila — revisão](#7-fila--revisão)
8. [Tabela comparativa — Big O completo](#8-tabela-comparativa--big-o-completo)

---

## 1. Árvore Binária — conceitos e propriedades

Uma **árvore binária** é uma estrutura hierárquica onde cada nó tem no máximo **2 filhos** (esquerdo e direito). É definida recursivamente: uma árvore binária é vazia OU um nó raiz com duas subárvores binárias (esquerda e direita).

```c
typedef struct no {
    int         info;
    struct no  *esq;    // filho esquerdo
    struct no  *dir;    // filho direito
} No;
```

**Propriedades:**
- **Nó folha:** nó sem filhos (esq == NULL && dir == NULL)
- **Nível da raiz:** 0 (ou 1, depende da convenção)
- **Altura:** maior nível presente na árvore
- **Árvore cheia:** todo nó tem 0 ou 2 filhos
- **Árvore completa:** todos os níveis exceto o último estão completos
- **Árvore degenerada:** cada nó tem no máximo 1 filho (vira lista encadeada)

| Propriedade | Árvore balanceada | Árvore degenerada |
|-------------|-------------------|-------------------|
| Altura máxima | O(log n) | O(n) |
| Nº máximo de nós no nível k | 2^k | 1 |

---

## 2. Árvore Binária de Busca (BST)

Uma BST impõe a **propriedade de ordem**: para todo nó X, todos os valores na subárvore esquerda são **menores** que X e todos na subárvore direita são **maiores** que X.

```c
// BUSCA em BST — O(log n) balanceada, O(n) degenerada
No* buscar(No *raiz, int x) {
    if (raiz == NULL) return NULL;
    if (raiz->info == x) return raiz;
    if (x < raiz->info) return buscar(raiz->esq, x);
    else                return buscar(raiz->dir, x);
}

// INSERÇÃO em BST — O(log n) balanceada, O(n) degenerada
No* inserir(No *raiz, int x) {
    if (raiz == NULL) {
        No *novo = (No*) malloc(sizeof(No));
        novo->info = x;
        novo->esq = novo->dir = NULL;
        return novo;
    }
    if (x < raiz->info)
        raiz->esq = inserir(raiz->esq, x);
    else if (x > raiz->info)
        raiz->dir = inserir(raiz->dir, x);
    return raiz;  // se igual, não insere duplicata
}
```

### Remoção em BST — os 3 casos

```c
No* remover(No *raiz, int x) {
    if (raiz == NULL) return NULL;
    if (x < raiz->info)
        raiz->esq = remover(raiz->esq, x);
    else if (x > raiz->info)
        raiz->dir = remover(raiz->dir, x);
    else {  // encontrou o nó a remover
        // CASO 1: nó folha (sem filhos)
        if (raiz->esq == NULL && raiz->dir == NULL) {
            free(raiz);
            return NULL;
        }
        // CASO 2: um filho só
        if (raiz->esq == NULL) {
            No *tmp = raiz->dir;
            free(raiz);
            return tmp;
        }
        if (raiz->dir == NULL) {
            No *tmp = raiz->esq;
            free(raiz);
            return tmp;
        }
        // CASO 3: dois filhos — sucessor (menor da direita)
        No *suc = raiz->dir;
        while (suc->esq != NULL)
            suc = suc->esq;
        raiz->info = suc->info;
        raiz->dir = remover(raiz->dir, suc->info);
    }
    return raiz;
}
```

| Caso | Descrição | Ação |
|------|-----------|------|
| Caso 1 | Nó folha (0 filhos) | Remove direto, retorna NULL |
| Caso 2 | 1 filho | Retorna o filho no lugar |
| Caso 3 | 2 filhos | Substitui pelo sucessor, remove sucessor recursivamente |

**Complexidade BST:**
- Busca: **O(log n)** balanceada / **O(n)** degenerada
- Inserção: **O(log n)** balanceada / **O(n)** degenerada
- Remoção: **O(log n)** balanceada / **O(n)** degenerada

---

## 3. Percorrimentos em árvores

Três tipos clássicos de percorrimento (DFS):

```c
// PRÉ-ORDEM: raiz → esquerda → direita  (RED)
void preOrdem(No *raiz) {
    if (raiz == NULL) return;
    printf("%d ", raiz->info);    // visita raiz PRIMEIRO
    preOrdem(raiz->esq);
    preOrdem(raiz->dir);
}

// EM-ORDEM: esquerda → raiz → direita  (ERD)
void emOrdem(No *raiz) {
    if (raiz == NULL) return;
    emOrdem(raiz->esq);
    printf("%d ", raiz->info);    // visita raiz NO MEIO
    emOrdem(raiz->dir);
}

// PÓS-ORDEM: esquerda → direita → raiz  (EDR)
void posOrdem(No *raiz) {
    if (raiz == NULL) return;
    posOrdem(raiz->esq);
    posOrdem(raiz->dir);
    printf("%d ", raiz->info);    // visita raiz POR ÚLTIMO
}
```

| Percorrimento | Abrev. | Resultado em BST | Uso típico |
|---------------|--------|------------------|------------|
| Pré-ordem | RED | Raiz primeiro | Copiar árvore, expressão prefixa |
| Em-ordem | ERD | **Ordem crescente** | Listar ordenado |
| Pós-ordem | EDR | Raiz por último | Deletar árvore, expressão posfixa |

**Complexidade dos percorrimentos:** O(n) — visita todos os nós.

---

## 4. Lista Encadeada — revisão

### Sem descritor (referência direta ao primeiro nó)

```c
typedef struct no {
    int         info;
    struct no  *prox;
} No;

No *inicio = NULL;  // lista vazia: inicio == NULL
```

### Com descritor (struct que encapsula metadados)

```c
typedef struct no {
    int         info;
    struct no  *prox;
} No;

typedef struct {
    No   *inicio;   // ponteiro para o primeiro nó
    No   *fim;      // ponteiro para o último nó
    int   tam;      // quantidade de nós (opcional)
} Descritor;

Descritor d;
d.inicio = NULL;
d.fim = NULL;
d.tam = 0;
```

**Vantagens do descritor:**
- Inserção no fim: **O(1)** com ponteiro `fim` (sem descritor: O(n))
- Tamanho disponível em O(1) com campo `tam`
- Não precisa ponteiro duplo (`**l`) — altera campos da struct via `.`

| Operação | S/ Descritor | C/ Descritor |
|----------|-------------|-------------|
| Inserir início | O(1) | O(1) |
| Inserir fim | O(n) | **O(1)** |
| Remover início | O(1) | O(1) |
| Remover fim | O(n) | O(n)* |
| Busca | O(n) | O(n) |
| Tamanho | O(n) | **O(1)** |

\* Remover fim ainda é O(n) mesmo com descritor na lista simples (precisa do penúltimo nó).

---

## 5. Pilha — revisão

Estrutura **LIFO** (Last In, First Out). Operações fundamentais:

```c
// Pilha com lista encadeada
typedef struct no {
    int         info;
    struct no  *prox;
} No;

No *topo = NULL;  // pilha vazia

// empilhar (push) — insere no topo
void push(No **topo, int x) {
    No *novo = (No*) malloc(sizeof(No));
    novo->info = x;
    novo->prox = *topo;
    *topo = novo;
}

// desempilhar (pop) — remove do topo
int pop(No **topo) {
    if (*topo == NULL) return -1;  // erro
    No *tmp = *topo;
    int val = tmp->info;
    *topo = tmp->prox;
    free(tmp);
    return val;
}
```

| Operação | Big O (encadeada) | Big O (vetor) |
|----------|-------------------|---------------|
| Push | O(1) | O(1)* |
| Pop | O(1) | O(1) |
| Topo (peek) | O(1) | O(1) |

\* O(1) se houver espaço; overflow se cheia.

---

## 6. Fila — revisão

Estrutura **FIFO** (First In, First Out). Operações fundamentais:

```c
// Fila com lista encadeada + descritor (inicio + fim)
typedef struct no {
    int         info;
    struct no  *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
} Fila;

// enfileirar (enqueue) — insere no fim
void enfileirar(Fila *f, int x) {
    No *novo = (No*) malloc(sizeof(No));
    novo->info = x;
    novo->prox = NULL;
    if (f->fim != NULL)
        f->fim->prox = novo;
    else
        f->inicio = novo;
    f->fim = novo;
}

// desenfileirar (dequeue) — remove do início
int desenfileirar(Fila *f) {
    if (f->inicio == NULL) return -1;
    No *tmp = f->inicio;
    int val = tmp->info;
    f->inicio = tmp->prox;
    if (f->inicio == NULL) f->fim = NULL;
    free(tmp);
    return val;
}
```

| Operação | Big O (encadeada) | Big O (vetor circular) |
|----------|-------------------|------------------------|
| Enqueue | O(1) | O(1)* |
| Dequeue | O(1) | O(1) |
| Frente (peek) | O(1) | O(1) |

\* Com vetor circular, usando `ini` e `fim` módulo MAX.

---

## 8. Tabela comparativa — Big O completo

| Estrutura | Inserir | Remover | Buscar | Acesso índice |
|-----------|---------|---------|--------|---------------|
| **BST balanceada** | O(log n) | O(log n) | O(log n) | — |
| **BST degenerada** | O(n) | O(n) | O(n) | — |
| **Lista seq. (vetor)** | O(n) ini / O(1) fim | O(n) ini / O(1) fim | O(n) | O(1) |
| **Lista encad. simples** | O(1) ini / O(n) fim | O(1) ini / O(n) fim | O(n) | O(n) |
| **Lista c/ descritor** | O(1) ini / O(1) fim | O(1) ini / O(n) fim | O(n) | O(n) |
| **Lista dupla encad.** | O(1) ini / O(1) fim | O(1) ini / O(1) fim* | O(n) | O(n) |
| **Lista circular** | O(1) ini / O(1) fim | O(1) ini / O(1) fim | O(n) | O(n) |
| **Pilha** | O(1) push | O(1) pop | — | — |
| **Fila** | O(1) enqueue | O(1) dequeue | — | — |

\* Com ponteiro para o último nó.

**Resumo prático:**
- Dados ordenados, busca frequente → **BST** (balanceada: O(log n)).
- Inserções/remoções no início, tamanho variável → **Lista encadeada simples**.
- Inserções/remoções no fim frequentes → **Lista com descritor** (O(1)).
- Precisa "desfazer" operações, recursão → **Pilha**.
- Processamento em ordem de chegada → **Fila**.
- Precisa percorrer nos dois sentidos → **Lista duplamente encadeada**.
