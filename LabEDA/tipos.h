#ifndef TIPOS_H
#define TIPOS_H

typedef struct {
    char cidade[50];
    float *temperatura;
}TMedidas;


typedef struct {
    int qtde_medidas;
    int qtde_dias;
    TMedidas medidas;
}TTemperaturas;

#endif