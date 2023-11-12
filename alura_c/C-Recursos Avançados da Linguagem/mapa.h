#define EMPTY '.'
#define GHOST 'F'
#define PERSON '@'

struct mapa {
    char** matriz;
    int linhas;
    int colunas;
};

typedef struct mapa MAPA;

struct posicao {
    int x;
    int y;
};

typedef struct posicao POSICAO;

void lerMapa(MAPA* m);
void encontraMapa(MAPA* m, POSICAO* person, char c);
void alocaMapa(MAPA* m);
void imprimeMapa(MAPA* m);
void liberaMapa(MAPA* m);
int ehValida(MAPA* m, int x, int y);
int ehVazia(MAPA* m, int x, int y);
void moveMapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino);
void copiaMapa(MAPA* destino, MAPA * origem);
