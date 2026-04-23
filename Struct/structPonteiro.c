#include <stdio.h>

typedef struct {
    char nome[50];
    float saldo;

}ContaBancaria;

void depositaConta(ContaBancaria *conta, float valor) {

    printf("Saldo antes do depósito: %.2f\n", conta -> saldo);

    // Atualiza o saldo da conta
    conta -> saldo += valor;

    printf("Valor depositado: %.2f\n", valor);
    printf("Saldo após o depósito: %.2f\n", conta -> saldo);

}


int main (void) {

    ContaBancaria minhaCont = {
        "João Silva",
        1000.00
    };

    //Passando o endereço da estrutura para a função
    depositaConta(&minhaCont, 755.00);

    printf("Saldo final da conta: %.2f\n", minhaCont.saldo);
    return 0;
}
