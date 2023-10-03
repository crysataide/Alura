#include <stdio.h>

int main() {
    int nX,num;

    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    printf("\n");

    printf("\nTabuada do numero: %d\n",num);

    printf("\n");

    for (nX = 1 ;nX < 11 ; nX++) {
        printf("%d x %d = %d\n",num,nX,num*nX);
    }
}