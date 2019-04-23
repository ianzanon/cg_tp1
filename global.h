// Primeiro inimigo após 500 de profundidade
int next_enemy = -500;
// Número de inimigos
int enemies_num = 100;
// Profundidade
int depth = 0;

// Primeira moeda após 500 de profundidade
int next_coin = -500;
// Número de moedas
int moedas_num = 100;
int moedas_coletadas = 0;

// Mundo inicial
int xBegin = -1280;
int xEnd = 1280;
int yBegin = -720;
int yEnd = 720;

// Teclas [W, A, S, D] desligadas
int moveKeys[4] = {0,0,0,0}; 

// Jogo começa pausado
int pause = 1;
// Ultimo char digitado
char last_char;


// Estrutura para criar objetos animados
typedef struct object {
    int x, y, alt, larg, velo;
} Object;

Object personagem;
Object enemies[100];
Object moedas[100];