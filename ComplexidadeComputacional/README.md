# Complexidade Computacional

> EDA1 — UnB Gama · Material: `complexidade_computacional.html` · Teoria para provas: `teoria_complexidade_prova.html`

Complexidade computacional mede **quantas operações elementares** um algoritmo realiza em função do tamanho da entrada `n`. Não é o tempo em segundos (que depende de hardware), mas a **taxa de crescimento** do custo com o crescimento de `n`.

---

## Índice

1. [Análise Assintótica](#1-análise-assintótica)
2. [Notação Big O — limite superior](#2-notação-big-o--limite-superior)
3. [Notação Big Ω — limite inferior](#3-notação-big-ω--limite-inferior)
4. [Notação Big Θ — limite justo](#4-notação-big-θ--limite-justo)
5. [Hierarquia das complexidades](#5-hierarquia-das-complexidades)
6. [Como identificar a complexidade de um código](#como-identificar-a-complexidade-de-um-código)
7. [Classes P, NP, NP-Completo](#classes-p-np-np-completo)
8. [Tabela resumo](#tabela-resumo)

---

## 1. Análise Assintótica

Foca no comportamento para entradas **grandes**. Ignora constantes e termos de menor ordem:

```
3n² + 5n + 100  →  O(n²)   (n² domina para n grande)
7 log n + 42    →  O(log n)
```

| n | log n | n | n log n | n² | 2ⁿ |
|---|-------|---|---------|----|----|
| 10 | 3 | 10 | 33 | 100 | 1.024 |
| 100 | 7 | 100 | 664 | 10.000 | inviável |
| 1.000 | 10 | 1.000 | 9.966 | 10⁶ | inviável |

---

## 2. Notação Big O — limite superior

**Pior caso.** Responde: "no máximo, quantos passos?"

> `f(n) = O(g(n))` se existem c > 0 e n₀ tal que `f(n) ≤ c·g(n)` para todo `n ≥ n₀`.

```c
// Exemplo: f(n) = 3n + 2
// 3n + 2 ≤ 4n para n ≥ 2  →  O(n), com c=4, n₀=2

// Exemplo: f(n) = n² + 10n
// n² + 10n ≤ 2n² para n ≥ 10  →  O(n²), com c=2, n₀=10
```

---

## 3. Notação Big Ω — limite inferior

**Melhor caso.** Responde: "no mínimo, quantos passos?"

> `f(n) = Ω(g(n))` se existem c > 0 e n₀ tal que `c·g(n) ≤ f(n)` para todo `n ≥ n₀`.

```c
// Busca linear:
// Melhor caso: elemento na 1ª posição  →  Ω(1)
// Pior caso:   elemento na última      →  O(n)
```

---

## 4. Notação Big Θ — limite justo

**Limite superior e inferior coincidem.** O algoritmo sempre executa o mesmo número de operações.

> `f(n) = Θ(g(n))` se `f(n) = O(g(n))` E `f(n) = Ω(g(n))`.

```c
// Θ(n): percorrer vetor SEMPRE faz exatamente n iterações
for (int i = 0; i < n; i++)
    printf("%d\n", vet[i]);

// NÃO é Θ: busca com break — melhor caso varia
for (int i = 0; i < n; i++)
    if (vet[i] == alvo) break;  // O(n) pior, Ω(1) melhor → sem Θ definido
```

---

## 5. Hierarquia das complexidades

```
O(1)         constante    → acesso a vetor: vet[i]
O(log n)     logarítmica  → busca binária
O(n)         linear       → busca sequencial, soma de vetor
O(n log n)   linearítmica → mergesort, quicksort (médio)
O(n²)        quadrática   → bubble sort, insertion sort (pior)
O(n³)        cúbica       → multiplicação ingênua de matrizes
O(2ⁿ)        exponencial  → Fibonacci ingênuo, subconjuntos
O(n!)        fatorial     → caixeiro viajante (força bruta)
```

> **Polinomiais** (O(1) a O(n^k)) são **tratáveis**.  
> **Exponenciais** (O(2ⁿ), O(n!)) são **intratáveis** para n grande.

---

## Como identificar a complexidade de um código

### O(1) — Constante
```
SINAL: sem loops, acesso direto por índice ou ponteiro
```
```c
int x = vet[5];           // O(1): acesso direto
int y = lista->info;      // O(1): acesso por ponteiro
```

### O(log n) — Logarítmica
```
SINAL: variável que DIVIDE o espaço pela metade a cada iteração
       (esq/dir em busca binária, nível de árvore balanceada)
```
```c
while (esq <= dir) {
    meio = (esq + dir) / 2;   // divide ao meio
    if (v[meio] < alvo) esq = meio + 1;   // descarta metade
    else                dir = meio - 1;   // descarta metade
}
// a cada iteração: n → n/2 → n/4 → ... → 1  =  log₂(n) passos
```

### O(n) — Linear
```
SINAL: um loop simples de 0 a n (ou equivalente)
```
```c
for (int i = 0; i < n; i++)      // O(n): percorre uma vez
    total += vet[i];

No *atu = inicio;
while (atu != NULL) atu = atu->prox;  // O(n): percorre lista
```

### O(n log n) — Linearítmica
```
SINAL: recursão que divide em 2 metades + O(n) de trabalho por nível
       (intercalação no merge sort, particionamento no quick sort)
```
```c
void mergesort(int p, int r, int v[]) {
    int q = (p + r) / 2;        // divide: log n níveis
    mergesort(p, q, v);
    mergesort(q, r, v);
    intercala(p, q, r, v);      // intercala: O(n) por nível
}
// log n níveis × O(n) por nível = O(n log n)
```

### O(n²) — Quadrática
```
SINAL: dois loops aninhados, ambos de 0 a n
       OU loop externo + loop interno que varia com o externo
```
```c
// laços independentes:
for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)   // n × n = n²
        soma++;

// laços dependentes (soma triangular):
for (int i = 0; i < n-1; i++)
    for (int j = i+1; j < n; j++) // (n-1)+(n-2)+...+1 = n(n-1)/2 = O(n²)
        compara(i, j);
```

### O(2ⁿ) — Exponencial
```
SINAL: função recursiva que faz DUAS ou mais chamadas recursivas
       sem memoização
```
```c
int fib(int n) {
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);  // 2 chamadas: árvore de recursão dobra a cada nível
}
// T(n) = T(n-1) + T(n-2) + O(1)  →  T(n) = O(2ⁿ)
```

### Regras rápidas

| Padrão no código | Complexidade |
|-----------------|--------------|
| Sem loop, acesso direto | O(1) |
| Loop divide por 2 (esq, dir, meio) | O(log n) |
| Um loop de 0 a n | O(n) |
| Dois loops aninhados de 0 a n | O(n²) |
| Divide ao meio + O(n) por nível | O(n log n) |
| Recursão com 2+ chamadas, sem memo | O(2ⁿ) |

---

## Classes P, NP, NP-Completo

### Classe P — Polinomial
Problemas **resolvíveis** em tempo polinomial O(n^k).  
Exemplos: ordenação, busca, caminho mínimo (Dijkstra), árvore geradora mínima.

### Classe NP — Nondeterministic Polynomial
Problemas cuja solução pode ser **verificada** em tempo polinomial.  
Exemplos: problema da mochila, SAT, caixeiro viajante (versão decisão).

```
P ⊆ NP  (todo problema fácil de resolver é fácil de verificar)
P = NP? → questão em aberto da Ciência da Computação
```

### NP-Completo
Problema X é NP-Completo se:
1. X está em NP (verificável em tempo polinomial)
2. Todo problema em NP se reduz a X em tempo polinomial

Exemplos clássicos:

| Problema | Descrição |
|----------|-----------|
| SAT | Existe atribuição que satisfaz fórmula booleana? |
| Problema da Mochila | Subconjunto com peso ≤ capacidade e valor ≥ alvo? |
| Caixeiro Viajante | Rota com distância total ≤ K? |
| Clique | Subgrafo completo de tamanho K? |
| Coloração de Grafos | Colorir vértices com K cores sem conflito? |

> Para NP-Completos: usa-se **heurísticas**, **algoritmos aproximados** ou **programação dinâmica** para casos especiais — não se busca ótimo exato para entradas grandes.

---

## Tabela resumo

### Notações

| Notação | Nome | O que expressa | Analogia |
|---------|------|----------------|----------|
| O (Big O) | Limite superior | Pior caso | "Não vai demorar mais que..." |
| Ω (Big Ω) | Limite inferior | Melhor caso | "Vai demorar pelo menos..." |
| Θ (Big Θ) | Limite justo | Sempre igual | "Sempre demora exatamente..." |

### Complexidades

| Notação | Nome | Algoritmo de exemplo |
|---------|------|----------------------|
| O(1) | Constante | Acesso a vetor `vet[i]` |
| O(log n) | Logarítmica | Busca binária |
| O(n) | Linear | Busca sequencial, soma de vetor |
| O(n log n) | Linearítmica | Merge Sort, QuickSort (médio) |
| O(n²) | Quadrática | Bubble Sort, Insertion Sort (pior) |
| O(n³) | Cúbica | Multiplicação ingênua de matrizes |
| O(2ⁿ) | Exponencial | Fibonacci ingênuo, subconjuntos |
| O(n!) | Fatorial | Caixeiro viajante (força bruta) |

### Classes

| Classe | Descrição | Exemplos |
|--------|-----------|----------|
| P | Resolvível em tempo polinomial | Ordenação, busca, Dijkstra |
| NP | Verificável em tempo polinomial | SAT, mochila, caixeiro (decisão) |
| NP-Completo | NP + todo NP se reduz a ele | SAT, 3-SAT, clique, coloração |
| NP-Difícil | Pelo menos tão difícil quanto NP | Caixeiro (otimização) |
