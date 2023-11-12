#define UP 'w'
#define LOW 's'
#define LEFT 'a'
#define RIGHT 'd'

int acabou();
int ehDirecao(char direcao);
void move(char direcao);
void ghost();

int ghostDirecao(int xatual, int yatual, int* xdestino, int* ydestino);