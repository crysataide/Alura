#include <time.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "forca.h"

#define TAMANHO_PALAVRA 20

int chutesdados = 0;

char chutes[26];
char palavraSecreta[TAMANHO_PALAVRA];

int letraexiste(char letra) {

    for(int j = 0; j < strlen(palavraSecreta); j++) {
        if(letra == palavraSecreta[j]) {
            return 1;
        }
    }

    return 0;
}

int chuteserrados() {
    int erros = 0;

    for(int i = 0; i < chutesdados; i++) {

        int existe = 0;

        if(!letraexiste(chutes[i])) {
            erros++;
        }
    }

    return erros;
}

int enforcou() {
    return chuteserrados() >= 5;
}

int acertou() {
    for (int i = 0; i < strlen(palavraSecreta); i++) {
        if (!jachutou(palavraSecreta[i])) {
            return 0;
        }
    }
    return 1;
}

void abertura() {
    printf("==============\n");
    printf("Jogo da Forca\n");
    printf("==============\n");

    printf("\n");
}

void chuta() {
    char chute;

    printf("Chute uma letra: ");
    scanf(" %c", &chute);

    if(letraexiste(chute)) {
        printf("Você acertou: a palavra tem a letra %c\n\n", 
            chute);
    } else {
        printf("\nVocê errou: a palavra NÃO tem a letra %c\n\n", 
            chute);
    }

    chutes[chutesdados] = toupper(chute);
    chutesdados++;
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

void desenhaForca() {

    int erros =chuteserrados();

    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n",(erros>=1?'(' :' '),(erros>=1?'_':' '),(erros>=1?')':' '));
    printf(" |      %c%c%c  \n",(erros>=3?'\\':' '),(erros>=2?'|':' '),(erros>=3?'/': ' '));
    printf(" |       %c     \n",(erros>=2?'|' :' '));
    printf(" |      %c %c   \n",(erros>=4?'/' :' '),(erros>=4?'\\':' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

    for (int i = 0; i < strlen(palavraSecreta); i++) {
        if (jachutou(palavraSecreta[i])) {
            printf("%c ", palavraSecreta[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n\n");
}

void escolhePalavra() {
    FILE* f;

    f = fopen("palavras.txt","r");

    if (f == 0) {
        printf("Desculpe, banco de dados nao disponivel\n\n");
        exit(1);
    }

    int quantidadePalavras;
    fscanf(f, "%d", &quantidadePalavras);

    srand(time(0));
    int randomico = rand() % quantidadePalavras;

    for (int i = 0; i <= randomico; i++) {
        fscanf(f,"%s", palavraSecreta);
    }

    fclose(f);
}

void adicionarPalavra() {
    char quer;

    printf("Voce deseja adicionar uma nova palavra no jogo (S/N)?  ");
    scanf(" %c", &quer);

    if (toupper(quer) == 'S') {
        char novaPalavra[TAMANHO_PALAVRA];
        printf("Qual a nova palavra? ");
        scanf("%s", &novaPalavra);

        FILE* f;

        f= fopen("palavras.txt","r+");

        if (f == 0) {
            printf("Desculpe, banco de dados nao disponivel\n\n");
            exit(1);
        }

        int quantidade;
        fscanf(f,"%d",&quantidade);
        quantidade++;

        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", quantidade);

        fseek(f, 0, SEEK_END);
        fprintf(f,"\n%s",toupper(novaPalavra));

        fclose(f);
    }
}

int main() {

    abertura();
    escolhePalavra();

    do {
        printf("\n");

        desenhaForca();
        chuta();

    } while(!acertou() && !enforcou());

    if(acertou()) {
        printf("\nParabéns, você ganhou!\n\n");

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");

    } else {
        printf("\nPuxa, você foi enforcado!\n");
        printf("A palavra era **%s**\n\n", palavraSecreta);

        printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
    }

    adicionarPalavra();   
}