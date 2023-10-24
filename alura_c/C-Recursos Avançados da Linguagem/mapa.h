#define EMPTY '.'
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