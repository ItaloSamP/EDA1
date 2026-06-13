# Struct

> EDA1 — UnB Gama · Guia interativo: `guia_struct.html`

`struct` permite agrupar variáveis de tipos diferentes sob um único nome — a base para criar **Tipos Abstratos de Dados (TAD)** em C.

---

## Exercícios nesta pasta

| Arquivo | Conceito |
|---------|----------|
| `struct.c` | Declaração e uso básico de struct |
| `struct1.c` | Múltiplos campos e acesso com `.` |
| `typedef.c` | Alias com typedef para simplificar declarações |
| `funcaoStruct.c` | Passar struct por valor para funções |
| `areaRetangulo.c` | Struct Retangulo com campos largura/altura |
| `structPonteiro.c` | Ponteiro para struct e operador `->` |
| `valorvsreferencia.c` | Diferença entre passar por valor e por referência |
| `arraysStruct.c` | Vetor de structs |
| `mediaNotas.c` | Struct Aluno com array de notas |
| `cadastroPessoas.c` | Cadastro com array de structs |
| `structaninhada.c` | Struct dentro de struct (nested) |
| `cadastro.c` | Sistema de cadastro completo |

---

## Conceitos-chave

**Declaração e acesso:**

```c
typedef struct {
    char nome[50];
    int  idade;
    float nota;
} Aluno;

Aluno a;
a.idade = 20;            // acesso com ponto (.)
strcpy(a.nome, "João");
```

**Ponteiro para struct:**

```c
Aluno *p = &a;
p->idade = 21;           // acesso via ponteiro com ->
(*p).nota = 9.5;         // equivalente, menos usual
```

**Struct em funções:**

```c
// por valor: cópia — não modifica o original
float media(Aluno a) { return a.nota; }

// por referência: modifica o original
void setNota(Aluno *a, float n) { a->nota = n; }
```

**Vetor de structs:**

```c
Aluno turma[40];
for (int i = 0; i < 40; i++)
    printf("%s\n", turma[i].nome);
```

---

## Compilar e executar

```bash
gcc mediaNotas.c -o saida && ./saida
```
