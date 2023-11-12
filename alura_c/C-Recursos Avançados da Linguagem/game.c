#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "mapa.h"

MAPA m;
POSICAO person;

int ghostDirecao(int xatual, int yatual, int* xdestino, int* ydestino) {
    int opcoes[4][2] = {
        {xatual, yatual + 1},
        {xatual + 1, yatual},
        {xatual, yatual - 1},
        {xatual - 1, yatual}
    };

    srand(time(0));
    for(int i = 0; i < 10; i++) {
        int posicao = rand() % 4;

        if (ehValida(&m, opcoes[posicao][0], opcoes[posicao][1]) &&
            ehVazia(&m, opcoes[posicao][0], opcoes[posicao][1])) {

            *xdestino = opcoes[posicao][0];
            *ydestino = opcoes[posicao][1];

            return 1;
        }
    }
    return 0;
}

void ghost() {
    MAPA copia;

    copiaMapa(&copia, &m);
    for(int i = 0; i < m.linhas; i++) {
        for(int j = 0; j < m.linhas; j++) {

            int xdestino;
            int ydestino;

            int found = ghostDirecao(i, j, &xdestino, &ydestino);

            if (found) {
                moveMapa(&m, i, j, xdestino, ydestino);
            }
        }
    }
    liberaMapa(&copia);
}

int acabou() {
	return 0;
}

int ehDirecao(char direcao) {
	return
		direcao == UP ||
		direcao == LOW ||
		direcao == LEFT || 
		direcao == RIGHT;
}

void move(char direcao) {

	if(!ehDirecao(direcao))	
		return;

	int proximox = person.x;
	int proximoy = person.y;

	switch(direcao) {
		case LEFT:
			proximoy--;
			break;
		case UP:
			proximox--;
			break;
		case LOW:
			proximox++;
			break;
		case RIGHT:
			proximoy++;
			break;
	}

	if(!ehValida(&m, proximox, proximoy))
		return;

	if(!ehVazia(&m, proximox, proximoy))
		return;

	moveMapa(&m, person.x, person.y, proximox, proximoy);
    person.x = proximox;
    person.y = proximoy;
}

int main() {
	
	lerMapa(&m);
	encontraMapa(&m, &person, PERSON);

	do {
		imprimeMapa(&m);

		char comando;
		scanf(" %c", &comando);

		move(comando);
        ghost();

	} while (!acabou());

	liberaMapa(&m);
}