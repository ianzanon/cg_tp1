// Tela inicial
int inicio = 0;
int telas = 0;

// Reduz efeito da velocidade durante a rolagem
int control_speed = -8;

// Primeiro inimigo após 500 de profundidade
int next_enemy = -500;
// Número de inimigos
int enemies_num = 100;

// Primeira moeda após 500 de profundidade
int next_coin = -500;
// Número de moedas
int moedas_num = 100;
int moedas_coletadas = 0;
char score[20];

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

// Começa descendo
int descendo = 1;


// Estrutura para criar objetos animados
typedef struct object {
    int x, y, alt, larg, velo, direcao;
} Object;

Object personagem;
Object enemies[100];
Object moedas[100];