#include <stdio.h>
void dobrar(int *multiplica){
    *multiplica = *multiplica * 3;
}


int main(void){
    int n = 21;
    int *p = &n;

    printf("Valor de n antes da operação %d\n", n);
    dobrar(&n);
    printf("Valor de n depois da operação %d\n", n);

    return 0;   
}