<!-- generated-by: gsd-doc-writer -->
# Getting Started — EDA1

Study repository for **EDA1 (Estruturas de Dados e Algoritmos 1)** at Universidade de Brasília — Faculdade do Gama. This guide gets you from zero to running C implementations and viewing interactive HTML theory files in under five minutes.

---

## Prerequisites

This project has no package manager, build system, or runtime dependencies beyond a C compiler and a web browser.

| Tool | Version | Purpose |
|------|---------|---------|
| `gcc` | Any modern release (>= 7.0 recommended) | Compile `.c` source files |
| Web browser | Any modern browser (Chrome, Firefox, Edge) | View interactive `.html` theory files |
| `git` | Any recent version | Clone the repository |

**Verifying gcc is available:**

```bash
gcc --version
```

If `gcc` is not installed:

- **Windows**: Install [MinGW-w64](https://www.mingw-w64.org/) or use WSL2 with `sudo apt install gcc`
- **Linux/macOS**: Run `sudo apt install gcc` (Debian/Ubuntu) or `brew install gcc` (macOS)

---

## Installation Steps

1. Clone the repository:

```bash
git clone https://github.com/your-username/EDA1.git
```

2. Enter the project directory:

```bash
cd EDA1
```

No additional install step is required. There are no dependencies to download.

---

## First Run

Compile any `.c` file and run it immediately:

```bash
gcc Ponteiros/MaiorElemVetor.c -o saida && ./saida
```

To view interactive theory, open any `.html` file directly in your browser:

```bash
# Windows
start AlgoritmoDeBusca/algoritmos_busca.html

# Linux
xdg-open AlgoritmoDeBusca/algoritmos_busca.html

# macOS
open AlgoritmoDeBusca/algoritmos_busca.html
```

---

## Exploring the Repository

Each topic directory follows the same layout:

| File type | What it contains |
|-----------|-----------------|
| `*.html` | Full interactive theory — step-by-step tracing, quizzes, syntax-highlighted code |
| `teoria_*_prova.html` | Condensed exam-focused summary |
| `*.c` | Runnable C implementation for each concept |
| `README.md` | Topic overview and key concepts |

Topic directories:

| Directory | Subject |
|-----------|---------|
| `AlgoritmoDeBusca/` | Sequential and binary search |
| `AlgoritmoDeOrdenação/` | Selection, Insertion, Bubble, Quick, Merge Sort |
| `ComplexidadeComputacional/` | Big O / Ω / Θ, P vs NP, NP-Complete |
| `EstruturasLineares/` | Singly/doubly-linked and circular lists |
| `Ponteiros/` | Pointer arithmetic, arrays, strings |
| `Struct/` | Structs, typedef, dynamic allocation |
| `Recursão/` | Recursive algorithms and exercises |
| `AlocaçãoDinâmica/` | malloc/free, heap vs stack |
| `Provas/` | Exam simulados and gabaritos |

---

## Common Setup Issues

**`gcc: command not found` on Windows**

MinGW-w64 must be added to `PATH`. After installing MinGW-w64, add the `bin/` folder (e.g., `C:\mingw64\bin`) to your system `PATH` environment variable, then open a new terminal.

**Compiled output not found after `gcc`**

By default `gcc arquivo.c -o saida` produces `saida` (Linux/macOS) or `saida.exe` (Windows). On Windows, run `saida.exe` instead of `./saida`, or use:

```bash
gcc arquivo.c -o saida && saida
```

**HTML file opens but shows a blank page**

Some browsers block local file access for security reasons. Try a different browser or serve the files with a simple local HTTP server:

```bash
# Python 3 (any platform)
python -m http.server 8080
# Then open http://localhost:8080 in your browser
```

---

## Next Steps

- See [ARCHITECTURE.md](ARCHITECTURE.md) for a full breakdown of the directory structure and content patterns.
- See [CONFIGURATION.md](CONFIGURATION.md) for details on the build environment and `.gitignore` conventions.
