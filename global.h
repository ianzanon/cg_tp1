// Primeiro inimigo após 500 de profundidade
int next_enemy = -500;
// Número de inimigos
int enemies_num = 20;

// Primeira moeda após 500 de profundidade
int next_coin = -500;
// Número de moedas
int moedas_num = 20;
int moedas_coletadas = 0;

// Mundo inicial
int xBegin = -1280;
int xEnd = 1280;
int yBegin = -720;
int yEnd = 720;

// Teclas [W, A, S, D] desligadas
int moveKeys[4] = {0,0,0,0}; 

// Estrutura para criar objetos animados
typedef struct object {
    int x, y, alt, larg, velo;
} Object;

Object personagem;
Object enemies[20];
Object moedas[20];