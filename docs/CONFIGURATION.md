<!-- generated-by: gsd-doc-writer -->
# Configuration

This repository is a collection of study materials for the EDA1 course at Universidade de Brasília — Faculdade do Gama. It contains C source files and interactive HTML documents. There is no application runtime, server, or deployment pipeline — consequently there are no environment variables, config files, or per-environment overrides to configure.

---

## Environment Variables

No environment variables are used. The project has no runtime process, server, or build system that reads from the environment.

| Variable | Required | Default | Description |
|----------|----------|---------|-------------|
| —        | —        | —       | None defined |

---

## Build Configuration

The only build step is compiling individual C source files with GCC. No build system, Makefile, or configuration file governs this step.

```bash
# General pattern — compile any .c file
gcc arquivo.c -o saida && ./saida
```

No flags, preprocessor definitions, or include paths beyond the C standard library are required by any source file in this repository.

---

## Config File Format

No configuration files are used. The project has no server, database, or framework that would require one.

---

## Required vs Optional Settings

Not applicable. There is no application entrypoint that validates or loads settings at startup.

---

## Defaults

Not applicable.

---

## Per-Environment Overrides

Not applicable. There are no development, staging, or production environments.

---

## Editor and Tooling

The `.gitignore` reflects the build artifacts produced during local development:

| Pattern | Meaning |
|---------|---------|
| `build/` | GCC output directory (if used) |
| `output/` | Alternative output directory |
| `*.exe` | Windows executables |
| `*.o` | Object files |
| `*.obj` | Object files (MSVC) |
| `*.out` | Default GCC output (`a.out`) |
| `.vscode/` | VS Code workspace settings |

No editor configuration file (`.editorconfig`) is present. No linter or formatter is configured.
