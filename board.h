#ifndef H_BOARD
#define H_BOARD

struct square {
	int cor;
	int valor;
};

struct posicao {
	int linha;
	int coluna;
};

#define LADOS 4
#define CASAS (LADOS*LADOS)

// Definição do tabuleiro
typedef struct square Board[LADOS][LADOS];

// Atribui o valor a todas as casas do tabuleiro
void Fill_Board(Board b, int value);

// Encontra índices da casa na matriz bidimensional
struct posicao Posicao_Da_Casa(Board b, struct square* casa);

// Encotra a casa referenca a posição no tabuleiro
struct square* Casa_Na_Posicao(Board b, struct posicao pos);

// Spawna um novo 2 (com 90% de chance) ou 4 (10% das vezes) no tabuleiro, apenas se houver espaço.
void Spawnar_Numero(Board b);

// Processa uma jogada sobre o tabuleiro, na direção especificada.
void Jogada_Cima(Board b);
void Jogada_Baixo(Board b);
void Jogada_Esquerda(Board b);
void Jogada_Direita(Board b);

// funções para mover peças
void Mover_Esquerda(Board b, struct square* casa);
void Mover_Baixo(Board b, struct square* casa);
void Mover_Cima(Board b, struct square* casa);
void Mover_Direita(Board b, struct square* casa);

// funções Casa_%DIREÇÃO% retornam null se casa não for válida ou não estiver na Board
// Em vez de Casa, quem sabe Vizinho no nome?
struct square* Casa_Cima(Board b, struct square* casa_ptr);
struct square* Casa_Baixo(Board b, struct square* casa_ptr);
struct square* Casa_Esquerda(Board b, struct square* casa_ptr);
struct square* Casa_Direita(Board b, struct square* casa_ptr);

#endif // H_BOARD