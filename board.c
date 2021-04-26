#include "board.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// preenche o buffer com casas vazias e retorna o total de vazias
void encontra_casas_vazias(Board b, struct square* buffer_vazias[CASAS], int* qtd_vazias);

// Encontra índices da casa na matriz bidimensional
// Peça deve estar no tabuleiro.
struct posicao Posicao_Da_Casa(Board b, struct square* casa) {
	struct posicao pos;
	int casa_esta_no_tabuleiro = 0;
	for (int i = 0; i < LADOS; i++) {
		for (int j = 0; j < LADOS; j++) {
			if (&b[i][j] == casa) {
				pos.linha = i;
				pos.coluna = j;
				casa_esta_no_tabuleiro = 1;
				break;
			}
		}
	}
	assert(casa_esta_no_tabuleiro);
	return pos;
}

int validar_posicao(struct posicao pos) {
	return (0 <= pos.linha && pos.linha < LADOS)
		&& (0 <= pos.coluna && pos.coluna < LADOS);
}

struct square* Casa_Na_Posicao(Board b, struct posicao pos) {
	assert(validar_posicao(pos));
	return &b[pos.linha][pos.coluna];
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
			Deslizar_Casa(b, &b[linha][col], Casa_Esquerda);
		}
	}
}

void Jogada_Direita(Board b) {
	for (int col = 3; col >= 0; col--) {
		for (int linha = 0; linha < LADOS; linha++) {
			Deslizar_Casa(b, &b[linha][col], Casa_Direita);
		}
	}
}

void Jogada_Cima(Board b) {
	for (int linha = 1; linha < LADOS; linha++) {
		for (int col = 0; col < LADOS; col++) {
			Deslizar_Casa(b, &b[linha][col], Casa_Cima);
		}
	}
}

void Jogada_Baixo(Board b) {
	for (int linha = 2; linha >= 0; linha--) {
		for (int col = 0; col < LADOS; col++) {
			Deslizar_Casa(b, &b[linha][col], Casa_Baixo);
		}
	}
}

// ------------------------------------------
// Funções do Movimento de Peças Individuais
// ------------------------------------------

void Deslizar_Casa(Board b, struct square* casa, struct square* (*proximaCasa)(Board, struct square*)) {
	struct square* next = (*proximaCasa)(b, casa);

	if (next == NULL)
		return;
	
	if (next->valor == 0) {
		next->valor = casa->valor;
		casa->valor = 0;
		Deslizar_Casa(b, next, proximaCasa);
	}
	else if (next->valor == casa->valor) {
		next->valor += casa->valor;
		casa->valor = 0;
	}
}

// -----------------------------------------------------------------
//	Funções para encontrar casas em posição relativa a outras casas
// -----------------------------------------------------------------

struct square* Casa_Esquerda(Board b, struct square* casa_ptr) {
	struct posicao pos = Posicao_Da_Casa(b, casa_ptr);
	pos.coluna = pos.coluna - 1;
	if (!validar_posicao(pos)) return NULL;
	return &b[pos.linha][pos.coluna];
}

struct square* Casa_Direita(Board b, struct square* casa_ptr) {
	struct posicao pos = Posicao_Da_Casa(b, casa_ptr);
	pos.coluna = pos.coluna + 1;
	if (!validar_posicao(pos)) return NULL;
	return &b[pos.linha][pos.coluna];
}

struct square* Casa_Cima(Board b, struct square* casa_ptr) {
	struct posicao pos = Posicao_Da_Casa(b, casa_ptr);
	pos.linha = pos.linha - 1;
	if (!validar_posicao(pos)) return NULL;
	return &b[pos.linha][pos.coluna];
}

struct square* Casa_Baixo(Board b, struct square* casa_ptr) {
	struct posicao pos = Posicao_Da_Casa(b, casa_ptr);
	pos.linha = pos.linha + 1;
	if (!validar_posicao(pos)) return NULL;
	return &b[pos.linha][pos.coluna];
}

// Outras funções
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