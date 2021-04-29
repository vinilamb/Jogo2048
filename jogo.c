#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

#include "board.h"
#include "display.h"

void imprimir_board(Board b) {
	board_iter(
		printf("%4d", i_casa->valor); if (i_pos.coluna == 3) printf("\n")
	)
}

// Teste do console
//int main(void) {
//	Display_Casa(5, 5);
//	Display_Casa(1, 3);
//	Display_Casa(12, 5);
//	Display_Casa(7, 8);
//}

int main(void) {
	Board b;
	Fill_Board(b, 2);
	Spawnar_Numero(b);
	Spawnar_Numero(b);

	// Imprime tabuleiro
	printf("\n");
	imprimir_board(b);

	// Loop do Jogo
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
		if (Jogo_Acabou(b)) {
			printf("Você venceu!");
			goto SAIR;
		}
		
		// se não acabou, spawna um número
		Spawnar_Numero(b);
		// Imprime tabuleiro
		printf("\n");
		imprimir_board(b);
	}

SAIR:;
}