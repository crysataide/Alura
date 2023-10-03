#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int var1,var2,resultado;
	
	printf("Digite o primeiro número: ");
    scanf("%d", &var1);
	printf("\nDigite o segundo número: ");
    scanf("%d", &var2);

    resultado = var1 * var2;

    printf("\nResultado da multiplicação: %d\n",resultado);
}