#include "board.h"

#include <stdio.h>
#include <stdlib.h>

// preenche o buffer com casas vazias e retorna o total de vazias
void encontra_casas_vazias(Board b, struct square* buffer_vazias[CASAS], int* qtd_vazias);

int Validar_Posicao(struct posicao pos) {
	return pos.linha < LADOS&& pos.coluna < LADOS;
}

// Encontra índices da casa na matriz bidimensional
// Retorno 0 = Peça não está no tabuleiro
int Posicao_Casa(Board b, struct square* casa, struct posicao* pos) {
	for (int i = 0; i < LADOS; i++) {
		for (int j = 0; j < LADOS; j++) {
			if (&b[i][j] == casa) {
				pos->linha = i;
				pos->coluna = j;
				return 1;
			}
		}
	}
	return 0;
}

void Spawnar_Numero(Board b) {
	int qtd_vazias, valor_spawn;
	struct square* buffer_vazias[CASAS];
	encontra_casas_vazias(b, buffer_vazias, &qtd_vazias);

	// calcula o valor para spawnar
	if (rand() % 9) {
		valor_spawn = 2;
	}
	else {
		valor_spawn = 4;
	}

	if (qtd_vazias > 0) {
		buffer_vazias[rand() % qtd_vazias]->valor = valor_spawn;
	}
}

// Atribui o valor especificado à todas as casas do tabuleiro;
void Fill_Board(Board b, int value) {
	int i, j;
	for (i = 0; i < LADOS; i++) {
		for (j = 0; j < LADOS; j++) {
			b[i][j].valor = value;
		}
	}
}

// ----------------------------------
// Funções para Processar as Jogadas
// ----------------------------------

void Jogada_Esquerda(Board b) {
	for (int col = 1; col < LADOS; col++) {
		for (int linha = 0; linha < LADOS; linha++) {
			Mover_Esquerda(b, &b[linha][col]);
		}
	}
}

void Jogada_Direita(Board b) {
	for (int col = 3; col >= 0; col--) {
		for (int linha = 0; linha < LADOS; linha++) {
			Mover_Direita(b, &b[linha][col]);
		}
	}
}

void Jogada_Cima(Board b) {
	for (int linha = 1; linha < LADOS; linha++) {
		for (int col = 0; col < LADOS; col++) {
			Mover_Cima(b, &b[linha][col]);
		}
	}
}

void Jogada_Baixo(Board b) {
	for (int linha = 2; linha >= 0; linha--) {
		for (int col = 0; col < LADOS; col++) {
			Mover_Baixo(b, &b[linha][col]);
		}
	}
}

// ------------------------------------------
// Funções do Movimento de Peças Individuais
// ------------------------------------------

void Mover_Esquerda(Board b, struct square* casa_ptr) {
	struct square* casa_esq = Casa_Esquerda(b, casa_ptr);

	if (casa_esq == NULL) {
		return;
	}
	else if (casa_esq->valor == 0) {
		casa_esq->valor = casa_ptr->valor;
		casa_ptr->valor = 0;
		Mover_Esquerda(b, casa_esq);
	}
	else if (casa_esq->valor == casa_ptr->valor) {
		casa_esq->valor += casa_ptr->valor;
		casa_ptr->valor = 0;
	}
	else {
		return;
	}
}

void Mover_Direita(Board b, struct square* casa_ptr) {
	struct square* vizinho = Casa_Direita(b, casa_ptr);

	if (vizinho == NULL) {
		return;
	}
	else if (vizinho->valor == 0) {
		vizinho->valor = casa_ptr->valor;
		casa_ptr->valor = 0;
		Mover_Direita(b, vizinho);
	}
	else if (vizinho->valor == casa_ptr->valor) {
		vizinho->valor += casa_ptr->valor;
		casa_ptr->valor = 0;
	}
	else {
		return;
	}
}

void Mover_Cima(Board b, struct square* casa_ptr) {
	struct square* vizinho = Casa_Cima(b, casa_ptr);

	if (vizinho == NULL) {
		return;
	}
	else if (vizinho->valor == 0) {
		vizinho->valor = casa_ptr->valor;
		casa_ptr->valor = 0;
		Mover_Cima(b, vizinho);
	}
	else if (vizinho->valor == casa_ptr->valor) {
		vizinho->valor += casa_ptr->valor;
		casa_ptr->valor = 0;
	}
	else {
		return;
	}
}

void Mover_Baixo(Board b, struct square* casa_ptr) {
	struct square* vizinho = Casa_Baixo(b, casa_ptr);

	if (vizinho == NULL) {
		return;
	}
	else if (vizinho->valor == 0) {
		vizinho->valor = casa_ptr->valor;
		casa_ptr->valor = 0;
		Mover_Baixo(b, vizinho);
	}
	else if (vizinho->valor == casa_ptr->valor) {
		vizinho->valor += casa_ptr->valor;
		casa_ptr->valor = 0;
	}
	else {
		return;
	}
}

// -----------------------------------------------------------------
//	Funções para encontrar casas em posição relativa a outras casas
// -----------------------------------------------------------------

struct square* Casa_Esquerda(Board b, struct square* casa_ptr) {
	struct posicao pos;
	Posicao_Casa(b, casa_ptr, &pos);
	pos.coluna = pos.coluna - 1;
	if (pos.coluna < 0) return NULL;
	return &b[pos.linha][pos.coluna];
}

struct square* Casa_Direita(Board b, struct square* casa_ptr) {
	struct posicao pos;
	Posicao_Casa(b, casa_ptr, &pos);
	pos.coluna = pos.coluna + 1;
	if (!(pos.coluna < LADOS)) return NULL;
	return &b[pos.linha][pos.coluna];
}

struct square* Casa_Cima(Board b, struct square* casa_ptr) {
	struct posicao pos;
	Posicao_Casa(b, casa_ptr, &pos);
	pos.linha = pos.linha - 1;
	if (pos.linha < 0) return NULL;
	return &b[pos.linha][pos.coluna];
}

struct square* Casa_Baixo(Board b, struct square* casa_ptr) {
	struct posicao pos;
	Posicao_Casa(b, casa_ptr, &pos);
	pos.linha = pos.linha + 1;
	if (!(pos.linha < LADOS)) return NULL;
	return &b[pos.linha][pos.coluna];
}

void encontra_casas_vazias(Board b, struct square* buffer_vazias[CASAS], int* qtd_vazias) {
	*qtd_vazias = 0;
	struct square* p;
	for (p = b[0]; p < b[0] + CASAS; p++) {
		if (p->valor == 0) {
			buffer_vazias[*qtd_vazias] = p;
			*qtd_vazias += 1;
		}
	}
}