#include "board.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// preenche o buffer com casas vazias e retorna o total de vazias
void encontra_casas_vazias(Board b, struct square* buffer_vazias[CASAS], int* qtd_vazias);

// Encontra índices da casa na matriz bidimensional
// Peça deve estar no tabuleiro.
struct posicao Posicao_Da_Casa(Board b, struct square* casa) {
	board_iter(
		if (i_casa == casa) return i_pos);
	printf("ERRO: Casa sem posição pois não está no tabuleiro");
	exit(EXIT_FAILURE);
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
	board_iter(i_casa->valor = value)
}

// ----------------------------------
// Funções para Processar as Jogadas
// ----------------------------------

void Jogada_Esquerda(Board b) {
	for (int col = 1; col < LADOS; col++) {
		for (int linha = 0; linha < LADOS; linha++) {
			Deslizar_Casa(b, &b[linha][col], Esquerda);
		}
	}
}

void Jogada_Direita(Board b) {
	for (int col = 3; col >= 0; col--) {
		for (int linha = 0; linha < LADOS; linha++) {
			Deslizar_Casa(b, &b[linha][col], Direita);
		}
	}
}

void Jogada_Cima(Board b) {
	for (int linha = 1; linha < LADOS; linha++) {
		for (int col = 0; col < LADOS; col++) {
			Deslizar_Casa(b, &b[linha][col], Cima);
		}
	}
}

void Jogada_Baixo(Board b) {
	for (int linha = 2; linha >= 0; linha--) {
		for (int col = 0; col < LADOS; col++) {
			Deslizar_Casa(b, &b[linha][col], Baixo);
		}
	}
}

// ------------------------------------------
// Funções do Movimento de Peças Individuais
// ------------------------------------------

void Deslizar_Casa(Board b, struct square* casa, enum Sentido s) {
	struct square* next = Vizinho(b, casa, s);

	if (next == NULL)
		return;

	if (next->valor == 0) {
		next->valor = casa->valor;
		casa->valor = 0;
		Deslizar_Casa(b, next, s);
	}
	else if (next->valor == casa->valor) {
		next->valor += casa->valor;
		casa->valor = 0;
	}
}

// -----------------------------------------------------------------
//	Função para encontrar casas em posição relativa a outras casas
// -----------------------------------------------------------------

struct square* Vizinho(Board b, struct square* casa_ptr, enum Sentido s) {
	struct posicao pos = Posicao_Da_Casa(b, casa_ptr);
	switch (s)
	{
	case Cima:		pos.linha = pos.linha - 1; break;
	case Direita:	pos.coluna = pos.coluna + 1; break;
	case Esquerda:	pos.coluna = pos.coluna - 1; break;
	case Baixo:		pos.linha = pos.linha + 1; break;
	}
	if (!validar_posicao(pos)) return NULL;
	return Casa_Na_Posicao(b, pos);
}

// --------------
//	Fim de jogo
// --------------

int Movimento_Possivel(struct square casa, struct square* vizinho) {
	if (vizinho == NULL) return 0;
	return casa.valor == 0 || vizinho->valor == 0 || casa.valor == vizinho->valor;
}

int Casa_Movivel(Board b, struct square* casa) {
	for (enum Sentido s = Cima; s <= Baixo; s++) {
		if (Movimento_Possivel(*casa, Vizinho(b, casa, s))) return 1;
	}
	return 0;
}

int Jogo_Acabou(Board b) {
	board_iter(if (Casa_Movivel(b, i_casa)) return 0);
	return 1;
}

// Outras funções
void encontra_casas_vazias(Board b, struct square* buffer_vazias[CASAS], int* qtd_vazias) {
	*qtd_vazias = 0;
	board_iter(
		if (i_casa->valor == 0) {
			buffer_vazias[*qtd_vazias] = i_casa;
			*qtd_vazias += 1;
		}
	)
}