// Primeiro inimigo após 500 de profundidade
int next_enemy = -500;
int enemies_num = 20;

// Mundo inicial
int xBegin = -1280;
int xEnd = 1280;
int yBegin = -720;
int yEnd = 720;

// Teclas [W, A, S, D] desligadas
int moveKeys[4] = {0,0,0,0}; 

typedef struct object {
    int x, y, alt, larg, velo;
} Object; 

Object personagem;
Object enemies[20];

