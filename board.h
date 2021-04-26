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

// Defini��o do tabuleiro
typedef struct square Board[LADOS][LADOS];

#define board_iter(fn) struct posicao i_pos; \
struct square *i_casa; \
for (i_pos.linha = 0; i_pos.linha < LADOS; i_pos.linha++) \
for (i_pos.coluna = 0; i_pos.coluna < LADOS; i_pos.coluna++) { i_casa = Casa_Na_Posicao(b, i_pos); fn; } 

// Atribui o valor a todas as casas do tabuleiro
void Fill_Board(Board b, int value);

// Encontra �ndices da casa na matriz bidimensional
struct posicao Posicao_Da_Casa(Board b, struct square* casa);

// Encotra a casa referenca a posi��o no tabuleiro
struct square* Casa_Na_Posicao(Board b, struct posicao pos);

// Spawna um novo 2 (com 90% de chance) ou 4 (10% das vezes) no tabuleiro, apenas se houver espa�o.
void Spawnar_Numero(Board b);

// Processa uma jogada sobre o tabuleiro, na dire��o especificada.
void Jogada_Cima(Board b);
void Jogada_Baixo(Board b);
void Jogada_Esquerda(Board b);
void Jogada_Direita(Board b);

// fun��es para mover pe�as individuais
void Deslizar_Casa(Board b, struct square* casa, struct square* (*proximaCasa)(Board, struct square*));

// fun��es Casa_%DIRE��O% retornam null se casa n�o for v�lida ou n�o estiver na Board
// Em vez de Casa, quem sabe Vizinho no nome?
struct square* Casa_Cima(Board b, struct square* casa_ptr);
struct square* Casa_Baixo(Board b, struct square* casa_ptr);
struct square* Casa_Esquerda(Board b, struct square* casa_ptr);
struct square* Casa_Direita(Board b, struct square* casa_ptr);

#endif // H_BOARD