#include "jogo.h"
#include "utils.h"
#include <conio.h>
#include <Windows.h>

int main() {
	MainMenu();
}

void MainMenu() {
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

void JogoMain(struct game_state* state) {
	Placar p;

	MostrarCursor(false);
	int n_placar = ObterPlacar(p);

	// Loop do Jogo
	int vitoria = 0;
	do {
		// Atualiza a tela
		Display(state->board, state->score, state->movimentos, p, n_placar);

		char cmd;
		// Lê comando
		cmd = _getch();
		if (cmd == 'e') return;
		// Processa comando
		Jogada(state, cmd);

		if (Jogo_Vitoria(state->board))
			vitoria = 1;

	} while (!Jogo_Derrota(state->board) && !vitoria);
	Display(state->board, state->score, state->movimentos, p, n_placar); // atualiza última vez
	
	// O jogo acabou com vitoria ou derrota
	

	if (vitoria) {
		printf("Voce venceu.\n");
	}
	else {
		printf("Voce nao obteve vitoria\n");
	}

	int insertAt = Placar_NovoRecorde(p, state->score);
	if (insertAt != -1 ) {
		struct registro r;
		r.score = state->score;

		limpar_buffer();

		printf("Novo recorde!!!\n");
		printf("Digite o seu nome: ");
		fgets(r.nome, MAX_NOME, stdin);
		r.nome[strcspn(r.nome, "\n")] = 0;

		Placar_InsereRegistro(p, r, insertAt);
		printf("Recorde salvo.");
		SalvarPlacar(p, min(MAX_PLACAR, n_placar + 1));
	}

	return;
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
	for (int i = 0; i < 3; i++) {
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

void CarregarJogoSalvo(struct game_state* state)
{
	FILE* f = fopen(ARQUIVO_JOGO, "r");
	if (f == NULL) return;
	fread(state, sizeof(struct game_state), 1, f);
	fclose(f);
}

