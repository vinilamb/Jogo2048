#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

#include "board.h"
#include "display.h"
#include "placar.h"

int main(void) {
	int score = 0, movimentos = 0;
	Board b;
	Placar p;
	int n_placar = ObterPlacar(p);

	MostrarCursor(false);

	Fill_Board(b, 0);
	Spawnar_Numero(b);
	Spawnar_Numero(b);

	Display(b, score, movimentos, p, n_placar);

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
		Display(b, score, movimentos, p, n_placar);
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


