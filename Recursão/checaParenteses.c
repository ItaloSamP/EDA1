#include <stdio.h>

// Função auxiliar recursiva
int ChecaParentesesAux(const char *expr, int count){
    // Correção de Bug: Se count > 0 no meio do caminho, fechou um parêntese sem ter aberto!
    if(count > 0)
        return 1;

    if(*expr == '\0'){
        if(count == 0)
            return 0;
            
        if (count < 0)
            return -1;
    }

    if(*expr == '(')
        count--;
    
    if(*expr == ')')
        count++;
    
    return ChecaParentesesAux(expr+1, count);
}

// Função principal (Wrapper) para o usuário usar facilmente
int ChecaParenteses(const char *expr){
    return ChecaParentesesAux(expr, 0);
}

int main() {
    const char *expression1 = "((1 + 2) * (3 + 4))";  
    const char *expression2 = "((1 + 2) * (3 + 4)";   
    const char *expression3 = "((1 + 2)) * (3 + 4))"; 
    printf("Resultado para expressão 1: %d\n", ChecaParenteses(expression1)); // Deve retornar 0
    printf("Resultado para expressão 2: %d\n", ChecaParenteses(expression2)); // Deve retornar -1
    printf("Resultado para expressão 3: %d\n", ChecaParenteses(expression3)); // Deve retornar 1
    return 0;
}