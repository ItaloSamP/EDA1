<!-- generated-by: gsd-doc-writer -->
# Testing — EDA1

## Test Framework and Setup

This is a C study repository with no automated test runner or external test framework. Verification is done by compiling and running C programs directly with `gcc`. No package installation is required — only a C compiler.

Required tool:

- `gcc` (GNU Compiler Collection) — available on Linux/macOS by default; on Windows use MinGW, WSL, or MSYS2

To verify `gcc` is available:

```bash
gcc --version
```

---

## Running Tests

Each topic under `Provas/P2/EsboçosDeProvas/` contains a `gabarito_verificacao.c` file that is the canonical answer key for that topic's simulado. Compile and run it to verify correctness.

**Run a single answer-key verifier:**

```bash
# Example: Algoritmos de Busca
gcc "Provas/P2/EsboçosDeProvas/AlgoritmoDeBusca/gabarito_verificacao.c" -o gabarito && ./gabarito
```

**Run all four topic verifiers:**

```bash
for topic in AlgoritmoDeBusca AlgoritmoDeOrdenação ComplexidadeComputacional EstruturasLineares; do
  echo "=== $topic ==="
  gcc "Provas/P2/EsboçosDeProvas/$topic/gabarito_verificacao.c" -o gabarito_tmp && ./gabarito_tmp
done
```

**Run a real exam example (Provas/P2/ExemplosQuestões):**

```bash
gcc "Provas/P2/ExemplosQuestões/Q1(24.1).c" -o q1 && ./q1
```

**Run any individual exercise in a topic directory:**

```bash
gcc arquivo.c -o saida && ./saida
```

---

## Writing New Tests

There is no fixed test file naming convention enforced by a framework. The established pattern in this repository is:

| File pattern | Purpose |
|---|---|
| `gabarito_verificacao.c` | Answer key for a topic simulado — one per `EsboçosDeProvas/<topic>/` folder |
| `Q<n>(<semester>).c` | Example questions from real exams — stored under `Provas/P2/ExemplosQuestões/` |
| `<concept>.c` in topic dirs | Stand-alone exercise implementations (e.g., `Recursão/fibonacci.c`) |

When adding a new verification program:

1. Place it in the relevant topic directory (e.g., `Provas/P2/EsboçosDeProvas/AlgoritmoDeBusca/`).
2. Name it `gabarito_verificacao.c` if it is a comprehensive answer key, or use a descriptive name for a focused exercise.
3. Include `#include <stdio.h>` and a `main()` function that prints the expected output so results can be compared visually.
4. Compile with `gcc <file>.c -o <out> && ./<out>` to confirm it builds and runs cleanly.

---

## Coverage Requirements

No automated coverage tooling is configured. This is a study repository — completeness is assessed manually by ensuring each topic's core algorithms have a corresponding `.c` implementation and an interactive HTML simulado.

Topics covered by verifier programs:

| Topic | Verifier present |
|---|---|
| AlgoritmoDeBusca | Yes (`gabarito_verificacao.c`) |
| AlgoritmoDeOrdenação | Yes (`gabarito_verificacao.c`) |
| ComplexidadeComputacional | Yes (`gabarito_verificacao.c`) |
| EstruturasLineares | Yes (`gabarito_verificacao.c`) |

---

## CI Integration

No CI/CD pipeline is configured. All compilation and verification is performed locally by the developer. There are no `.github/workflows/` files in this repository.

To verify correctness before an exam, compile and run all `gabarito_verificacao.c` files as shown in the [Running Tests](#running-tests) section above.
