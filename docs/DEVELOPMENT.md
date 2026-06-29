<!-- generated-by: gsd-doc-writer -->
# Development — EDA1

> Contributing to or extending this study repository.

This repository holds static C source files and HTML theory pages for the EDA1 course at Universidade de Brasília — Faculdade do Gama. There is no build system, package manager, or runtime process. Development means editing `.c` files and `.html` files directly.

---

## Local Setup

### Prerequisites

| Tool | Purpose | Notes |
|------|---------|-------|
| `gcc` | Compile and run `.c` files | Any modern GCC version works (GCC 11+ recommended) |
| A browser | View `.html` theory files | Chrome, Firefox, or Edge |
| `git` | Version control | For cloning and committing changes |

On Windows, GCC is available via [MinGW-w64](https://www.mingw-w64.org/) or [MSYS2](https://www.msys2.org/).  
On Linux/macOS, install via the system package manager (`apt install gcc`, `brew install gcc`).

### Clone the repository

```bash
git clone <repository-url>
cd EDA1
```

No install step is required. There are no dependencies to download.

---

## Build Commands

There is no Makefile or build system. Each `.c` file is compiled independently with `gcc`.

| Command | Description |
|---------|-------------|
| `gcc arquivo.c -o saida` | Compile a single C file to a named binary |
| `gcc arquivo.c -o saida && ./saida` | Compile and immediately run (Linux/macOS) |
| `gcc arquivo.c -o saida.exe && saida.exe` | Compile and run on Windows |
| `gcc arquivo.c -Wall -o saida` | Compile with all warnings enabled (recommended) |
| `gcc arquivo.c -g -o saida` | Compile with debug symbols for use with `gdb` |

### Example: compiling an exercise

```bash
# Compile and run a recursion exercise
gcc Recursão/fiboanacci.c -o fiboanacci && ./fiboanacci

# Compile an exam answer key
gcc Provas/P2/EsboçosDeProvas/AlgoritmoDeBusca/gabarito_verificacao.c -o gabarito && ./gabarito
```

Build artifacts (`.exe`, `.o`, `.out`, `.obj`, `build/`, `output/`) are listed in `.gitignore` and should not be committed.

---

## Code Style

No linter or formatter is configured for this repository. Follow standard C conventions:

- Use 4-space indentation (consistent with existing source files)
- Declare variables at the top of each function (C89/C90 style used throughout)
- Add a comment block at the top of new `.c` files describing what the program does
- Match the naming style of the module you are contributing to (snake_case for functions and variables)

No `.editorconfig` is present. Configure your editor manually if needed.

---

## Directory Conventions

Each topic directory follows the same layout:

```
TopicName/
├── README.md                   # Topic overview and key concepts
├── algoritmos_topico.html      # Full interactive theory (quizzes, diagrams, code traces; named per topic, e.g. algoritmos_busca.html)
├── teoria_topico_prova.html    # Condensed exam-focused summary
└── exercicio.c                 # One or more runnable C implementations
```

When adding a new topic or exercise:

1. Place the `.c` file inside the relevant topic directory.
2. Update the topic `README.md` to mention the new file and what it demonstrates.
3. If it is a new top-level topic, add a row to the table in the root `README.md`.

---

## HTML Theory Files

The `.html` files are self-contained — they use inline CSS and JavaScript and open directly in a browser without a local server.

To view a theory file:

```bash
# Windows
start AlgoritmoDeBusca/algoritmos_busca.html

# macOS
open AlgoritmoDeBusca/algoritmos_busca.html

# Linux
xdg-open AlgoritmoDeBusca/algoritmos_busca.html
```

When editing HTML files, preserve the self-contained structure (no external CDN links, no `<script src="...">` pointing to local paths). All styles and scripts must be inline so the file works offline.

---

## Exam Prep Structure (`Provas/`)

```
Provas/
└── P2/
    ├── ExemplosQuestões/              # Real exam questions (24.1 semester)
    │   └── Q1–Q5(24.1).c
    ├── EsboçosDeProvas/               # Topic-specific interactive exams
    │   ├── AlgoritmoDeBusca/
    │   │   ├── prova_busca.html
    │   │   ├── simulado_busca_prova.html
    │   │   └── gabarito_verificacao.c
    │   ├── AlgoritmoDeOrdenação/
    │   ├── ComplexidadeComputacional/
    │   └── EstruturasLineares/
    └── Simulados/                     # General cross-topic simulados
        └── simulado_prova1–4.html
```

`gabarito_verificacao.c` in each topic folder is the canonical answer key. Compile and run it to verify exercise solutions.

---

## Branch Conventions

No formal convention is documented. The repository uses a single `master` branch. For personal study additions, descriptive commit messages summarizing the topic added are sufficient.

---

## PR Process

This is a personal study repository without a formal PR review process. If contributing:

- Open a pull request against `master`
- Include a brief description of what topic or exercise was added
- Ensure no compiled binaries (`.exe`, `.out`, `.o`) are included in the commit

---

## Troubleshooting

**`gcc: command not found` on Windows**  
Install MinGW-w64 and add its `bin/` directory to the system `PATH`. Verify with `gcc --version`.

**Compilation errors in existing files**  
All existing `.c` files target C99 or earlier and the C standard library only. If you see errors with a newer standard, try adding `-std=c99` to the `gcc` command.

**HTML file shows a blank page or broken layout**  
The HTML files are tested in Chrome/Firefox. Some older or non-standard browsers may not render the embedded JavaScript correctly. Use a modern browser.
