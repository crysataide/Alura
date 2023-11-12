#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mapa.h"

void copiaMapa(MAPA* destino, MAPA * origem) {
    destino->linhas = origem->linhas;
    destino->colunas = origem->colunas;

    alocaMapa(destino);
    for(int i = 0; i < origem->linhas; i++) {
        strcpy(destino->matriz[i], origem->matriz[i]);
    }
}

void encontraMapa(MAPA* m, POSICAO* person, char c) {
    for (int i = 0; i < m->linhas; i++) {
        for (int j = 0; j < m->colunas; j++) {
            if (m->matriz[i][j] == c) {
                person->x = i; 
                person->y = j; 
                break;
            }
        }
    }
}

void lerMapa(MAPA* m) {

    FILE* f = fopen("../mapa.txt", "r");

    if (f == NULL) {
        printf("Erro na leitura do arquivo\n");
        exit(1);
    }

    fscanf(f, "%d %d", &(m->linhas), &(m->colunas));

    //: Aloca memória
    alocaMapa(m);

    for (int i = 0; i < 5; i++) {
        fscanf(f, "%s", m->matriz[i]);
    }

    fclose(f);
}

void alocaMapa(MAPA* m) {
    m->matriz = malloc(sizeof(char*) * m->linhas);

    for (int i = 0; i < m->linhas; i++) {
        m->matriz[i] = malloc(sizeof(char) * (m->colunas+1));
    }
}

void imprimeMapa(MAPA* m) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c", m->matriz[i][j]);
        }
        printf("\n");
    }
}

void liberaMapa(MAPA* m) {
    for (int i = 0; i < m->linhas; i++) {
        free(m->matriz[i]);
    }
    free(m->matriz);
}

int ehValida(MAPA* m, int x, int y) {
	if(x >= m->linhas) 
		return 0;
	if(y >= m->colunas) 
		return 0;

	return 1;	
}

int ehVazia(MAPA* m, int x, int y) {
	return m->matriz[x][y] == EMPTY;
}

void moveMapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino) {

	char personagem = m->matriz[xorigem][yorigem];
	m->matriz[xdestino][ydestino] = personagem;
	m->matriz[xorigem][yorigem] = EMPTY;

}