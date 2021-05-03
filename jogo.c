#include "jogo.h"

int main(void) {
	Placar p;
	struct game_state state;
	NewGame(&state);
	MostrarCursor(false);

	int n_placar = ObterPlacar(p);

	Display(state.board, state.score, state.movimentos, p, n_placar);

	// Loop do Jogo
	while (1) {
		char cmd;
		// Lê comando
		printf("\nFaça uma jogada. Use WASD. E para sair.");
		cmd = _getch();
		if (cmd == 'e') return;

		// Processa comando
		Jogada(&state, cmd);

		// checar se o jogo acabou
		if (Jogo_Acabou(state.board)) {
			printf("Você venceu!");
			goto SAIR;
		}

		// Display
		Display(state.board, state.score, state.movimentos, p, n_placar);
	}

SAIR:;
	return 0;
}

void Jogada(struct game_state* state, char cmd) {
	Board* b = state->board;

	switch (cmd) {
	case 'w': Jogada_Cima(b, &state->score);       break;
	case 'a': Jogada_Esquerda(b, &state->score);   break;
	case 's': Jogada_Baixo(b, &state->score);      break;
	case 'd': Jogada_Direita(b, &state->score);    break;
	default: return;
	}
	state->movimentos++;
	Spawnar_Numero(state->board);
}

void NewGame(struct game_state* state) {
	Fill_Board(state->board, 0);
	for (int i = 0; i < 5; i++) {
		Spawnar_Numero(state->board);
	}
	state->movimentos = 0;
	state->score = 0;
}

