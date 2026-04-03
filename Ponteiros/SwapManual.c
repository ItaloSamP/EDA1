#include <stdio.h>

int main(void){
    int x = 10, y = 20;
    int *p1, *p2;
    
    p1 = &x;
    p2 = &y;

    // Exibindo os valores antes da troca
    printf("Antes de trocar: x = %d, y = %d\n", x, y);

    // Trocando os valores usando ponteiros
    *p1 = *p1 + *p2; // p1 agora tem o valor de x + y
    *p2 = *p1 - *p2; // p2 agora tem o valor de (x + y) - y = x
    *p1 = *p1 - *p2; // p1 agora tem o valor de (x + y) - x = y

    printf("Após trocar: x = %d, y = %d\n", x, y);

    return 0;
}