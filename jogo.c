#include <stdio.h>
#include <stdlib.h>

#include "board.h"

int main(void) {
	Board b;
	fill_board(b, 0);
	Spawnar_Numero(b);
	Spawnar_Numero(b);

	// Imprime tabuleiro
	printf("\n");
	imprimir_board(b);

	// Loop
	while (1) {
		char cmd;
		// L� comando
		printf("\nFa�a uma jogada. Use WASD. E para sair: ");
		cmd = getche();

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
		// se n�o acabou, spawna um n�mero
		Spawnar_Numero(b);
		// se acabou, sair do loop

		// Imprime tabuleiro
		printf("\n");
		imprimir_board(b);
	}

SAIR:;
}