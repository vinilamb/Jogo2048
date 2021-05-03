#include "jogo.h"

int main(void) {
	Placar p;
	struct game_state state;
	NewGame(&state);
	MostrarCursor(false);
	int n_placar = ObterPlacar(p);
	Display(state.board, state.score, state.movimentos, p, n_placar);

	printf("\nFaça uma jogada. Use WASD. E para sair.");
	// Loop do Jogo
	do {
		char cmd;
		// Lê comando
		cmd = _getch();
		if (cmd == 'e') return;

		// Processa comando
		Jogada(&state, cmd);

		// Display
		Display(state.board, state.score, state.movimentos, p, n_placar);
	} while (!Jogo_Acabou(state.board));

	return 0;
}

void Jogada(struct game_state* state, char cmd) {

	switch (cmd) {
	case 'w': Jogada_Cima(state->board, &state->score);       break;
	case 'a': Jogada_Esquerda(state->board, &state->score);   break;
	case 's': Jogada_Baixo(state->board, &state->score);      break;
	case 'd': Jogada_Direita(state->board, &state->score);    break;
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

