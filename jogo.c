#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

#include "board.h"
#include "display.h"
#include "placar.h"

void imprimir_board(Board b) {
	board_iter(
		printf("%4d", i_casa->valor); if (i_pos.coluna == 3) printf("\n")
	)
}

// Teste do console
int main2(void) {
	//Board b;
	//int i = 2;
	//board_iter(
	//	i_casa->valor = i;
	//	i *= 2;
	//);
	//Display_Board(b);
	Display_Casa(2, 2, 0);
	printf("Lol");
}

// Para testar a criação do placar
/*int main(void) {
	Placar p;
	fill_placar(p);
	salvar_placar(p);
}*/


int main(void) {
	int score = 0, movimentos = 0;
	Board b;
	Placar p;

	MostrarCursor(false);

	Fill_Board(b, 0);
	Spawnar_Numero(b);
	Spawnar_Numero(b);

	Display(b, score, movimentos);

	// Loop do Jogo
	while (1) {
		char cmd;
		// Lê comando
		printf("\nFaça uma jogada. Use WASD. E para sair.");
		cmd = _getch();

		// Processa comando
		switch (cmd) {
		case 'w': Jogada_Cima(b, &score);       break;
		case 'a': Jogada_Esquerda(b, &score);   break;
		case 's': Jogada_Baixo(b, &score);      break;
		case 'd': Jogada_Direita(b, &score);    break;
		case 'e': goto SAIR;
		default: break;
		}
		movimentos++;
		// checar se o jogo acabou
		if (Jogo_Acabou(b)) {
			printf("Você venceu!");
			goto SAIR;
		}
		
		// se não acabou, spawna um número
		Spawnar_Numero(b);

		// Display
		Display(b, score, movimentos);
	}

SAIR:;

	//struct registro r;
	//r.nome = "nome";
	//r.score = score;
	//AtualizarPlacar(p, r);
	//fill_placar();
	//ler_placar(p);
	//obter_score(p, score);
	//salvar_placar(p);
	return 0;
}


