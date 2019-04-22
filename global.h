typedef struct object {
    int x, y, alt, larg;
} Object;

Object personagem;

// Mundo inicial
int xBegin = -1280;
int xEnd = 1280;
int yBegin = -720;
int yEnd = 720;

// Teclas [W, A, S, D] desligadas
int moveKeys[4] = {0,0,0,0}; 
