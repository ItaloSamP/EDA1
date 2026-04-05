#include <stdio.h>

int compararStrings(const char *str, const char *str2) {
    while (*str == *str2 && *str != '\0') {
        str++;
        str2++;
    }

    return *str - *str2;
}

int main(void) {
    char s1[] = "casar";
    char s2[] = "casa";
    int resultado = compararStrings(s1, s2);

    printf("Resultado da comparacao: %d\n", resultado);

    return 0;
}
