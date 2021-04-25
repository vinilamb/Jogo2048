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

// Valida o valor de uma posicao
// 
int Validar_Posicao(struct posicao pos);

#define LADOS 4
#define CASAS (LADOS*LADOS)

// Definição do tabuleiro
typedef struct square Board[LADOS][LADOS];

// Atribui o valor a todas as casas do tabuleiro
void Fill_Board(Board b, int value);

// Imprime o tabuleiro no console
void imprimir_board(Board b);

// Encontra índices da casa na matriz bidimensional
// Retorno 0 = Peça não está no tabuleiro
int Posicao_Casa(Board b, struct square* casa, struct posicao* pos);

// spawn de números novos
// usar rand() para ver as chances de spawnar 2 ou 4
// usa a função abaixo para encontrar todas as casas vazias
// usar o rand() para escolher o índice no vetor
// atribuir valor a casa vazia pelo pointer
void Spawnar_Numero(Board b);

// funções para as jogadas
// algoritmo para uma jogada:
// 1. começa em um dos cantos
// 2. usa as funções para mover as peças
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