// Verificação do gabarito — Prova Esboço: Complexidade Computacional
// Parâmetros: matrícula 232037937 | nome "italo alves sampaio de oliveira"
#include <stdio.h>
#include <string.h>

// Q1 — conta iterações do while que divide por 10
int Q1(int m) {
    int c = 0;
    while (m > 0) { c++; m /= 10; }
    return c;
}

// Q2 — loop duplo completo n x n
int Q2(int n) {
    int c = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            c++;
    return c;
}

// Q3 — loop que dobra
int Q3(int n) {
    int c = 0;
    for (int i = 1; i < n; i *= 2) c++;
    return c;
}

// Q4 — loop triangular
int Q4(int n) {
    int c = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            c++;
    return c;
}

// Q5 — recursão que divide por 2
int Q5(int n) {
    if (n <= 1) return 1;
    return 1 + Q5(n / 2);
}

// Q6 — percorre string somando 2 por vogal e 0 por outros
int Q6(char *s) {
    int c = 0;
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            c += 2;
    return c;
}

// Q7 — loop triplo com inner constante (10)
int Q7(int n) {
    int c = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < 10; k++)
                c++;
    return c;
}

// Q8 — dois loops sequenciais
int Q8(int n) {
    int c = 0;
    for (int i = 0; i < n; i++) c++;
    for (int j = 0; j < 2 * n; j++) c++;
    return c;
}

// Q9 — loop que triplica
int Q9(int n) {
    int c = 0;
    for (int i = 1; i < n; i *= 3) c++;
    return c;
}

int main() {
    char nome[] = "italo alves sampaio de oliveira";
    int mat = 232037937;
    printf("strlen(nome) = %d\n", (int)strlen(nome));
    printf("Q1(matricula)        = %d\n", Q1(mat));
    printf("Q2(9 digitos)        = %d\n", Q2(9));
    printf("Q3(matricula)        = %d\n", Q3(mat));
    printf("Q4(9 digitos)        = %d\n", Q4(9));
    printf("Q5(37 ult2dig)       = %d\n", Q5(37));
    printf("Q6(nome)             = %d\n", Q6(nome));
    printf("Q7(9 digitos)        = %d\n", Q7(9));
    printf("Q8(9 digitos)        = %d\n", Q8(9));
    printf("Q9(37 ult2dig)       = %d\n", Q9(37));
    return 0;
}
