#include <stdio.h>
#include <string.h>

int strings_iguais(char *s1, char *s2) {
    // Caso base: ambas chegaram ao fim ao mesmo tempo
    if (*s1 == '\0' && *s2 == '\0') {
        return 1;
    }
    // Se os caracteres atuais forem diferentes, as strings não são iguais
    if (*s1 != *s2) {
        return 0;
    }
    // Passo recursivo: avança para o próximo caractere de cada string
    return strings_iguais(s1 + 1, s2 + 1);
}

int main(void) {
    char str1[100], str2[100];

    printf("Digite a primeira string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Digite a segunda string: ");
    fgets(str2, sizeof(str2), stdin);

    // Remove o caractere de nova linha adicionado pelo fgets
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    if (strings_iguais(str1, str2)) {
        printf("As strings são iguais.\n");
    } else {
        printf("As strings são diferentes.\n");
    }

    return 0;
}