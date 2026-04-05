#include <stdio.h>

int conta(char *str, char c) {
    int cont = 0;
    char *ptr = str;

    while (*ptr != '\0'){
        if(*ptr == 'a'){
            cont++;
        }
        ptr++;
    }
    return cont;
}
int main(void){
    char str[] = "programacao";
    char c = 'a';
    int resultado = conta(str, c);
    printf("O contador de '%c' na string %s é: %d\n", c, str, resultado);
    return 0;
}