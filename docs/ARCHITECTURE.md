# Architecture — EDA1

<!-- GSD-GENERATED -->

## Overview

Study repository for **EDA1 (Estruturas de Dados e Algoritmos 1)** at UnB/FGA (Faculdade do Gama). No runtime, no server, no build system. All content is static: C source files compiled locally with `gcc` and HTML theory files opened in a browser.

---

## Directory Structure

```
EDA1/
├── AlgoritmoDeBusca/          # Sequential and binary search
├── AlgoritmoDeOrdenação/      # Selection, Insertion, Bubble, Quick, Merge Sort
├── ComplexidadeComputacional/ # Big O/Ω/Θ, P vs NP, NP-Complete
├── EstruturasLineares/        # Linked lists, doubly-linked, circular
├── Ponteiros/                 # Pointer arithmetic, arrays, strings
├── Recursão/                  # Recursive algorithms and exercises
├── Struct/                    # Structs, typedefs, dynamic allocation
├── AlocaçãoDinâmica/          # malloc/free, dynamic memory
├── Provas/                    # Exam prep (simulados, gabaritos, examples)
└── docs/                      # Project documentation
```

---

## Content Pattern

Every topic directory follows the same layout:

| File type | Purpose |
|-----------|---------|
| `*.html` (full theory) | Interactive theory with step-by-step tracing, quizzes, syntax-highlighted code |
| `teoria_*_prova.html` | Condensed exam-focused summary |
| `*.c` | Runnable C implementations for each concept |
| `README.md` | Topic overview and key concepts (present in most topic directories; absent in `Recursão/` and `AlocaçãoDinâmica/`) |

---

## Component Layers

```
┌─────────────────────────────────────────────────────┐
│                  Exam Preparation                    │
│  Provas/P2/EsboçosDeProvas/   Provas/P2/Simulados/ │
│  (topic simulados + gabaritos) (general simulados)  │
├─────────────────────────────────────────────────────┤
│               Interactive Theory (HTML)              │
│  algoritmos_busca.html · estruturas_lineares.html   │
│  complexidade_computacional.html · guia_*.html      │
├─────────────────────────────────────────────────────┤
│              C Implementations (.c)                  │
│  topic exercises · data structure implementations   │
│  recursive algorithms · pointer/struct exercises    │
└─────────────────────────────────────────────────────┘
```

---

## Exam Prep Structure (`Provas/`)

```
Provas/
└── P2/
    ├── ExemplosQuestões/          # Real exam questions from 24.1
    │   ├── Q1(24.1).c
    │   ├── Q2(24.1).c
    │   ├── Q3(24.1).c
    │   ├── Q4(24.1).c
    │   └── Q5(24.1).c
    ├── EsboçosDeProvas/           # Topic-specific simulados
    │   ├── AlgoritmoDeBusca/
    │   │   ├── prova_busca.html          # 10-question interactive exam
    │   │   ├── simulado_busca_prova.html
    │   │   └── gabarito_verificacao.c    # Compiled answer key
    │   ├── AlgoritmoDeOrdenação/
    │   ├── ComplexidadeComputacional/
    │   └── EstruturasLineares/
    └── Simulados/                 # General cross-topic simulados
        ├── simulado_prova1.html
        ├── simulado_prova2.html
        ├── simulado_prova3.html
        └── simulado_prova4.html
```

`gabarito_verificacao.c` in each topic folder is the canonical answer key — compiled and run with `gcc` to verify correctness.

---

## Key Abstractions

| Module | Core abstractions |
|--------|------------------|
| ComplexidadeComputacional | Big O/Ω/Θ notation, growth hierarchy, P/NP classes |
| AlgoritmoDeBusca | Sequential O(n), binary O(log n), sorted vs unsorted |
| AlgoritmoDeOrdenação | Comparison sorts, divide-and-conquer, in-place vs stable |
| EstruturasLineares | Node, singly/doubly/circular linked list, dynamic arrays |
| Ponteiros | Address arithmetic, pointer-to-pointer, string as `char*` |
| Struct | Aggregate types, typedef aliases, struct arrays |
| Recursão | Base case, recursive case, stack frame model |
| AlocaçãoDinâmica | `malloc`/`free`, heap vs stack, memory leaks |

---

## Tooling

| Tool | Role |
|------|------|
| `gcc` | Compile and run any `.c` file (`gcc file.c -o out && ./out`) |
| Browser | Open any `.html` file for interactive theory/simulados |
| `git` | Version control |

No build system, no package manager, no runtime dependencies.
