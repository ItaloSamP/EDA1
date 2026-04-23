#include <stdio.h>

typedef struct {
    float base;
    float altura;
}Retangulo;

typedef struct {
    float base;
    float altura;
}Triangulo;

float areaRetangulo(Retangulo r) {
    return r.base * r.altura;
}

float areaTriangulo(Triangulo t) {
    return (t.base * t.altura) / 2;
}




int main(void) {
    Retangulo r1;
    r1.base = 5.0;
    r1.altura = 3.0;

    Triangulo t1;
    t1.base = 4.0;
    t1.altura = 6.0;


    printf("A área do reângulo é: %.2f\n", areaRetangulo(r1));
    printf("A área do triângulo é: %.2f\n", areaTriangulo(t1));
    return 0;

    
} 