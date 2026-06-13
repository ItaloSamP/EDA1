# EDA1 — Estruturas de Dados e Algoritmos

> Universidade de Brasília — Faculdade do Gama  
> Disciplina: Estruturas de Dados e Algoritmos 1

Repositório de estudos e exercícios da disciplina EDA1. Cada pasta contém material teórico (HTML interativo) e implementações em C.

---

## Estrutura do repositório

| Pasta | Conteúdo |
|-------|----------|
| [`AlgoritmoDeBusca/`](AlgoritmoDeBusca/) | Busca sequencial e busca binária — O(n) vs O(log n) |
| [`AlgoritmoDeOrdenação/`](AlgoritmoDeOrdenação/) | Selection, Insertion, Bubble, Quick e Merge Sort |
| [`EstruturasLineares/`](EstruturasLineares/) | Listas sequenciais, encadeadas, duplas e circulares |
| [`ComplexidadeComputacional/`](ComplexidadeComputacional/) | Big O / Ω / Θ, hierarquia, classes P, NP, NP-Completo |
| [`Ponteiros/`](Ponteiros/) | Aritmética de ponteiros, vetores, strings e exercícios |
| [`Struct/`](Struct/) | TADs com struct, typedef, arrays de struct e ponteiros |
| [`Provas/`](Provas/) | Simulados e gabaritos |

---

## Tópicos cobertos

```
Complexidade Computacional
  └── Big O · Big Ω · Big Θ · P vs NP · NP-Completo

Algoritmos de Busca
  └── Sequencial (desordenado) · Sequencial (ordenado) · Binária

Algoritmos de Ordenação
  └── Selection Sort · Insertion Sort · Bubble Sort
  └── QuickSort · Merge Sort

Estruturas Lineares
  └── Lista Sequencial · S. Encadeada · D. Encadeada · Circular

Fundamentos de C
  └── Ponteiros · Struct · Typedef · Alocação dinâmica
```

---

## Material de apoio

Cada pasta contém arquivos `.html` com teoria interativa (quiz, diagramas, código com syntax highlight) e arquivos `.c` com implementações executáveis.

- **`*_busca.html` / `*_ordenacao.html`** — teoria completa com rastreamento passo a passo
- **`teoria_*_prova.html`** — resumo focado em provas
- **`*.c`** — implementações prontas para compilar e testar

```bash
# Compilar qualquer exercício
gcc arquivo.c -o saida && ./saida
```
