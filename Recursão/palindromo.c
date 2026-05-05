#include <stdio.h>

int palindromo(char *s, int i, int f) {
    if (i >= f) {
        return 1; // Se a string tem 0 ou 1 caractere, é um palíndromo
    }

    if (s[i] != s[f]){
        return 0;

    }

    return palindromo(s, i + 1, f - 1); // Verifica os próximos caracteres
    
}



int main(void){


char palavra[] = "arara";
int tam = strlen(palavra);

if (palindromo(palavra, 0, tam - 1)) {
    printf("E um palindromo!\n");
} else {
    printf("Nao e um palindromo.\n");
}

}