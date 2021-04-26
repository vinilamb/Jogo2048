#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "board.h"

void imprimir_board(Board b) {
	board_iter(
		printf("%4d", i_casa->valor); if (i_pos.coluna == 3) printf("\n")
	)
}

int main(void) {
	Board b;
	Fill_Board(b, 0);
	Spawnar_Numero(b);
	Spawnar_Numero(b);

	// Imprime tabuleiro
	printf("\n");
	imprimir_board(b);

	// Loop
	while (1) {
		char cmd;
		// Lê comando
		printf("\nFaça uma jogada. Use WASD. E para sair: ");
		cmd = _getche();

		// Processa comando
		switch (cmd) {
		case 'w': Jogada_Cima(b);       break;
		case 'a': Jogada_Esquerda(b);   break;
		case 's': Jogada_Baixo(b);      break;
		case 'd': Jogada_Direita(b);    break;
		case 'e': goto SAIR;
		default: break;
		}

		// checar se o jogo acabou
		// se não acabou, spawna um número
		Spawnar_Numero(b);
		// se acabou, sair do loop

		// Imprime tabuleiro
		printf("\n");
		imprimir_board(b);
	}

SAIR:;
}