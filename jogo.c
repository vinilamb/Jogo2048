#include "jogo.h"
#include <conio.h>
#include <Windows.h>

int main() {
	MainMenu();
}

int MainMenu() {
	struct game_state state = { 0 };

	printf("Bem vindo ao 2048. Suas opcoes sao: \n");
	printf("  1. (N)ovo jogo\n");
	printf("  2. (C)arregar um jogo salvo\n");
	printf("  3. (S)air\n");

	printf("Digite sua escolha: ");
	char cmd = getchar();
	switch (cmd) {
	case '1': case 'N': case 'n':

		NewGame(&state);
		JogoMain(&state);
		break;
	case '2': case 'C': case 'c':
		CarregarJogoSalvo(&state);
		JogoMain(&state);
		break;
	case '3': case 'S': case 's':
		break;
	}
}

char JogoMain(struct game_state* state) {
	Placar p;

	MostrarCursor(false);
	int n_placar = ObterPlacar(p);

	// Loop do Jogo
	do {
		// Atualiza a tela
		Display(state->board, state->score, state->movimentos, p, n_placar);

		char cmd;
		// Lê comando
		cmd = _getch();
		if (cmd == 'e') return;

		// Processa comando
		Jogada(state, cmd);
	} while (!Jogo_Acabou(state->board));

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

void SalvarJogo(struct game_state* state)
{
	FILE* f = fopen(ARQUIVO_JOGO, "w");
	if (f == NULL) return;
	fwrite(state, sizeof(struct game_state), 1, f);
}

bool CarregarJogoSalvo(struct game_state* state)
{
	FILE* f = fopen(ARQUIVO_JOGO, "r");
	if (f == NULL) return;
	fread(state, sizeof(struct game_state), 1, f);
	fclose(f);
}

