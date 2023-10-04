#include <stdio.h>

void abertura() {
    // aqui nao enxergamos a variável multiplicador
    printf("Tabuada do ");
    printf("Quero imprimir o multiplicador aqui, mas nao consigo...");
}

int main() {
    int multiplicador = 2;

    abertura();

    for(int i = 0; i < 10; i++) {
        int resultado = multiplicador * i;
        printf("%d x %d = %d", i, multiplicador, 
            resultado);
    }
}