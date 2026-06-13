# Algoritmos de Busca

> EDA1 — UnB Gama · Material: `algoritmos_busca.html` · Teoria para provas: `teoria_busca_prova.html`

Buscar um dado em um vetor é uma das operações mais frequentes em computação. A eficiência depende diretamente de **como os dados estão organizados**. Três cenários são estudados: busca em vetor desordenado, em vetor ordenado e busca binária.

---

## Índice

1. [Busca Sequencial — Vetor Desordenado](#1-busca-sequencial--vetor-desordenado)
2. [Busca Sequencial — Vetor Ordenado](#2-busca-sequencial--vetor-ordenado)
3. [Busca Binária](#3-busca-binária)
4. [Como identificar cada tipo](#como-identificar-cada-tipo)
5. [Tabela comparativa](#tabela-comparativa)

---

## 1. Busca Sequencial — Vetor Desordenado

Percorre o vetor do início ao fim sem nenhuma premissa sobre os dados. Para somente ao encontrar o elemento ou chegar ao final.

```c
int buscaSequencialDesordenado(int v[], int n, int valor) {
    for (int i = 0; i < n; i++)
        if (v[i] == valor)
            return i;
    return -1;
}
```

**Complexidade:** melhor O(1) · pior O(n) · médio O(n)

---

## 2. Busca Sequencial — Vetor Ordenado

Aproveita a ordenação para interromper a busca cedo: se o elemento atual já é **maior** que o procurado, o elemento não existe no restante.

```c
int buscaSequencialOrdenado(int v[], int n, int valor) {
    for (int i = 0; i < n; i++) {
        if (v[i] == valor)  return i;
        if (v[i] > valor)   break;   // parada antecipada
    }
    return -1;
}
```

**Complexidade:** melhor O(1) · pior O(n) · médio O(n/2)

---

## 3. Busca Binária

Algoritmo de **divisão e conquista**. A cada passo compara o alvo com o elemento do meio e descarta metade do vetor. Requer vetor ordenado.

```c
// Versão iterativa
int buscaBinariaIterativa(int v[], int n, int valor) {
    int esq = 0, dir = n - 1, meio;
    while (esq <= dir) {
        meio = (esq + dir) / 2;
        if (valor == v[meio])     return meio;
        else if (valor < v[meio]) dir  = meio - 1;
        else                      esq = meio + 1;
    }
    return -1;
}

// Versão recursiva
int buscaBinariaRecursiva(int v[], int esq, int dir, int valor) {
    if (esq > dir) return -1;
    int meio = (esq + dir) / 2;
    if (valor == v[meio])
        return meio;
    else if (valor < v[meio])
        return buscaBinariaRecursiva(v, esq, meio - 1, valor);
    else
        return buscaBinariaRecursiva(v, meio + 1, dir, valor);
}
```

**Complexidade:** melhor O(1) · pior **O(log n)** · in-place: sim

> Para 1 milhão de elementos: busca binária faz ~20 comparações. Busca sequencial faz até 1.000.000.

---

## Como identificar cada tipo

Use esses padrões para reconhecer o tipo de busca em um código:

### Busca Sequencial Desordenada
```
SINAL: loop simples, UMA única condição de parada (v[i] == valor)
```
```c
for (int i = 0; i < n; i++)
    if (v[i] == valor) return i;
//  ^--- só compara igualdade, sem break antecipado
```

### Busca Sequencial Ordenada
```
SINAL: loop com DUAS condições — igualdade E comparação de maior/menor
```
```c
for (int i = 0; i < n; i++) {
    if (v[i] == valor) return i;
    if (v[i] > valor)  break;   // <--- este break é o diferencial
}
```

### Busca Binária Iterativa
```
SINAL: três variáveis (esq, dir, meio), while com esq <= dir,
       meio = (esq + dir) / 2, atualiza esq ou dir
```
```c
int esq = 0, dir = n - 1;     // <--- limites
while (esq <= dir) {
    int meio = (esq + dir) / 2; // <--- divisão ao meio
    if (v[meio] == valor) return meio;
    else if (valor < v[meio]) dir = meio - 1;  // descarta direita
    else                      esq = meio + 1;  // descarta esquerda
}
```

### Busca Binária Recursiva
```
SINAL: função recursiva com parâmetros (esq, dir),
       caso base esq > dir, chama a si mesma com metade dos índices
```
```c
int busca(int v[], int esq, int dir, int valor) {
    if (esq > dir) return -1;       // <--- caso base
    int meio = (esq + dir) / 2;
    if (valor < v[meio])
        return busca(v, esq, meio-1, valor);  // metade esquerda
    else
        return busca(v, meio+1, dir, valor);  // metade direita
}
```

---

## Tabela comparativa

| Algoritmo | Vetor | Melhor caso | Pior caso | Pré-requisito |
|-----------|-------|-------------|-----------|---------------|
| Sequencial (desordenado) | Qualquer | O(1) | O(n) | Nenhum |
| Sequencial (ordenado) | Ordenado | O(1) | O(n) | Ordenação |
| Binária | Ordenado | O(1) | **O(log n)** | Ordenação |

**Resumo prático:**
- Vetores pequenos (n < 30): sequencial é competitivo pela simplicidade.
- Vetores grandes: binária é amplamente superior.
- Sequencial ordenada só vantajosa quando o elemento **não existe** — parada antecipada.
