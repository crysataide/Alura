#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "portuguese");

    printf("******************************************\n");
    printf("* Bem-vindo ao nosso jogo de adivinhação *\n");
    printf("******************************************\n");

    int numSecreto = 42;

    int chute;

    printf("Qual o seu chute? ");
    scanf("%d", &chute);
    
    printf("Seu chute foi %d\n",chute);
}