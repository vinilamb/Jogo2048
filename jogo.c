#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

#include "board.h"
#include "display.h"
#include "placar.h"

#include "utils.h"

int main() {
	int arr[10] = { 32, 24, 15, 7, 3, 0, 0 };
	int n = 5;
	insertSorted(arr, n, 25);

	for (int* p = arr; p < arr + n; p++)
		printf("%d ", *p);
}


int main2(void) {
	int score = 0, movimentos = 0;
	Board b;

	MostrarCursor(false);

	Fill_Board(b, 0);
	Spawnar_Numero(b);
	Spawnar_Numero(b);

	Display(b, score, movimentos);

	// Loop do Jogo
	while (1) {
		char cmd;
		// L� comando
		printf("\nFa�a uma jogada. Use WASD. E para sair.");
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
			printf("Voc� venceu!");
			goto SAIR;
		}

		// se n�o acabou, spawna um n�mero
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


