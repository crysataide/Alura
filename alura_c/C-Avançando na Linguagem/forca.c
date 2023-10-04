#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "forca.h"

int chutesdados = 0;

char chutes[26];
char palavraSecreta[20];

void abertura() {
    printf("==============\n");
    printf("Jogo da Forca\n");
    printf("==============\n");

    printf("\n");
}

int jachutou(char letra) {
    int achou = 0;

    for (int j = 0; j < chutesdados; j++) {
        if (chutes[j] == letra) {
            achou = 1;
            break;
        }
    }
    return achou;
}

int enforcou() {
    int erros = 0;

    for (int i = 0; i < chutesdados; i++) {
        int existe = 0;

        for (int j = 0; j < strlen(palavraSecreta); j++) {
            if (chutes[i] == palavraSecreta[j]) {
                existe = 1;
                break;
            }
        }
        if (!existe) erros++;
    }
    return erros >= 5;
}

int acertou() {
    for (int i = 0; i < strlen(palavraSecreta); i++) {
        if (!jachutou(palavraSecreta[i])) {
            return 0;
        }
    }
    return 1;
}

void desenhaForca() {

    printf("Voce ja deu %d chutes\n", chutesdados);

    for (int i = 0; i < strlen(palavraSecreta); i++) {
        if (jachutou(palavraSecreta[i])) {
            printf("%c ", palavraSecreta[i]);
        }
        else {
            printf("_ ");
        }
    }
    printf("\n\n");
}

void chuta() {
    char chute;

    printf("Chute uma letra: ");
    scanf(" %c", &chute);

    chutes[chutesdados] = toupper(chute);
    chutesdados++;
}

void escolhePalavra() {
    sprintf(palavraSecreta, "MELANCIA");
}

int main() {

    abertura();
    escolhePalavra(palavraSecreta);

    do {
        printf("\n");

        desenhaForca(palavraSecreta);
        chuta();

    } while(!acertou() && !enforcou());
}