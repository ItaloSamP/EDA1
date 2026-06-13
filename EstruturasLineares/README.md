# Estruturas Lineares

> EDA1 — UnB Gama · Material: `estruturas_lineares.html` · Teoria para provas: `teoria_estruturas_prova.html`

Uma **lista linear** é uma sequência finita de elementos onde a ordem é determinada pela posição. A diferença entre os tipos está em **como** a relação entre elementos é mantida na memória — contiguamente (vetor) ou através de ponteiros (nós encadeados).

**Operações fundamentais de qualquer lista:**
- `inserir(x, p)` — insere elemento x na posição p
- `remover(p)` — remove o elemento na posição p
- `buscar(valor)` — localiza um elemento
- `percorrer()` — visita todos os elementos

---

## Índice

1. [Lista Sequencial (Estática)](#1-lista-sequencial-estática)
2. [Lista Simplesmente Encadeada](#2-lista-simplesmente-encadeada)
3. [Lista Duplamente Encadeada](#3-lista-duplamente-encadeada)
4. [Lista Circular](#4-lista-circular)
5. [Como identificar cada tipo](#como-identificar-cada-tipo)
6. [Tabela comparativa](#tabela-comparativa)

---

## 1. Lista Sequencial (Estática)

Elementos em **posições consecutivas de memória** (vetor). Acesso direto O(1), mas tamanho fixo. Inserção/remoção exige deslocamento de elementos.

```c
#define MAX 100

typedef struct {
    int v[MAX];  // vetor de elementos
    int n;       // quantidade armazenada
} Lista;

int inserir(Lista *l, int x, int p) {
    if (l->n == MAX || p < 0 || p > l->n) return 0;
    for (int i = l->n; i > p; i--)
        l->v[i] = l->v[i - 1];    // desloca para a direita
    l->v[p] = x;
    l->n++;
    return 1;
}
```

**Complexidade:**
- Acesso: O(1)
- Inserção/remoção no início: O(n)
- Inserção/remoção no fim: O(1)*
- Busca: O(n)

---

## 2. Lista Simplesmente Encadeada

Nós **alocados dinamicamente**, ligados por ponteiros `prox`. Tamanho dinâmico, sem deslocamento. Acesso é sequencial (sem índice).

```c
typedef struct no {
    int         info;
    struct no  *prox;   // ponteiro para o próximo
} No;

void inserirInicio(No **l, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->info = valor;
    novo->prox = *l;    // aponta para o antigo primeiro
    *l = novo;
}

int remover(No **l, int valor) {
    No *ant = NULL, *atu = *l;
    while (atu != NULL && atu->info != valor) {
        ant = atu;
        atu = atu->prox;
    }
    if (atu == NULL) return 0;
    if (ant == NULL)  *l = atu->prox;       // remove o primeiro
    else              ant->prox = atu->prox; // remove meio/fim
    free(atu);
    return 1;
}
```

**Complexidade:**
- Acesso: O(n)
- Inserção/remoção no início: O(1)
- Inserção/remoção no fim: O(n)
- Busca: O(n)

---

## 3. Lista Duplamente Encadeada

Cada nó tem **dois ponteiros**: `ant` (anterior) e `prox` (próximo). Permite percorrer nos dois sentidos e remover um nó conhecido sem precisar do antecessor.

```c
typedef struct no {
    int         info;
    struct no  *ant;    // ponteiro para o anterior
    struct no  *prox;   // ponteiro para o próximo
} No;

void inserirInicio(No **l, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->info = valor;
    novo->ant  = NULL;
    novo->prox = *l;
    if (*l != NULL) (*l)->ant = novo;
    *l = novo;
}

int remover(No **l, int valor) {
    No *atu = *l;
    while (atu != NULL && atu->info != valor)
        atu = atu->prox;
    if (atu == NULL) return 0;
    if (atu->ant != NULL)  atu->ant->prox = atu->prox;
    else                   *l = atu->prox;
    if (atu->prox != NULL) atu->prox->ant = atu->ant;
    free(atu);
    return 1;
}
```

**Complexidade:**
- Acesso: O(n)
- Inserção/remoção no início: O(1)
- Inserção/remoção no fim: O(1) com ponteiro para o último
- Busca: O(n)

---

## 4. Lista Circular

O **último nó aponta de volta para o primeiro** — não há `NULL`. Pode ser simples ou duplamente encadeada. Percorrimento usa `do-while` com critério de parada no nó inicial.

```
Circular simples:
[info|prox] → [info|prox] → [info|prox] ←┐
└──────────────────────────────────────────┘
```

```c
void percorrer(No *inicio) {
    if (inicio == NULL) return;
    No *atu = inicio;
    do {
        printf("%d ", atu->info);
        atu = atu->prox;
    } while (atu != inicio);    // para quando volta ao início
}
```

**Usos típicos:** escalonamento round-robin, buffers circulares, jogos de turnos.

---

## Como identificar cada tipo

### Lista Sequencial
```
SINAL: struct com vetor fixo int v[MAX] e contador int n,
       inserção com loop deslocando elementos (v[i] = v[i-1])
```
```c
struct {
    int v[MAX];   // <--- vetor estático de tamanho fixo
    int n;        // <--- contador de elementos
} Lista;

// inserção: loop que desloca
for (int i = l->n; i > p; i--)
    l->v[i] = l->v[i - 1];   // <--- deslocamento característico
```

### Lista Simplesmente Encadeada
```
SINAL: struct com campo info e UM ponteiro prox,
       inserção usa malloc, acesso via ->prox
       remoção mantém ponteiro ant para o anterior
```
```c
struct no {
    int        info;
    struct no *prox;   // <--- UM ponteiro (só para frente)
};

// percorrimento clássico
No *atu = inicio;
while (atu != NULL) {
    // processa atu->info
    atu = atu->prox;   // <--- avança só para frente
}
```

### Lista Duplamente Encadeada
```
SINAL: struct com DOIS ponteiros: ant E prox,
       inserção atualiza (*l)->ant = novo,
       remoção acessa atu->ant->prox e atu->prox->ant
```
```c
struct no {
    int        info;
    struct no *ant;    // <--- ponteiro para o anterior
    struct no *prox;   // <--- ponteiro para o próximo
};

// remoção sem precisar do anterior (diferencial):
if (atu->ant != NULL)  atu->ant->prox = atu->prox;
if (atu->prox != NULL) atu->prox->ant = atu->ant;
```

### Lista Circular
```
SINAL: último->prox aponta para o primeiro (não é NULL),
       percorrimento usa do-while comparando com o nó inicial,
       inserção NÃO atribui NULL ao campo prox do novo nó
```
```c
// percorrimento: do-while é o sinal mais claro
No *atu = inicio;
do {
    // processa atu->info
    atu = atu->prox;
} while (atu != inicio);   // <--- termina ao voltar ao início

// na inserção, o último aponta para o primeiro:
ultimo->prox = inicio;     // <--- circular: sem NULL
```

---

## Tabela comparativa

| Critério | Sequencial | S. Encadeada | D. Encadeada | Circular |
|----------|-----------|-------------|-------------|---------|
| Acesso | **O(1)** | O(n) | O(n) | O(n) |
| Inserção início | O(n) | **O(1)** | **O(1)** | O(1) |
| Inserção fim | O(1)* | O(n) | O(1)** | O(1) |
| Remoção início | O(n) | **O(1)** | **O(1)** | O(1) |
| Remoção fim | O(1) | O(n) | **O(1)** | O(1) |
| Busca | O(n) | O(n) | O(n) | O(n) |
| Tamanho | Fixo | Dinâmico | Dinâmico | Dinâmico |
| Memória extra | Nenhuma | 1 ptr/nó | 2 ptr/nó | 1 ou 2 ptr/nó |

\* O(1) só se houver espaço no vetor.  
\** O(1) com ponteiro para o último nó.

**Resumo prático:**
- Muitas buscas, tamanho fixo → **Lista Sequencial** (acesso O(1)).
- Muitas inserções/remoções no início, tamanho imprevisível → **Lista Simplesmente Encadeada**.
- Precisa percorrer nos dois sentidos → **Lista Duplamente Encadeada**.
- Iteração contínua / round-robin → **Lista Circular**.
