#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

#include "board.h"
#include "display.h"
#include "placar.h"

#define ARQUIVO_JOGO "jogo_salvo.dat"

struct game_state {
	Board board;
	int score;
	int movimentos;
};

int MainMenu();

void JogoMain(struct game_state* state);

void Jogada(struct game_state* state, char cmd);

void NewGame(struct game_state* state);

void SalvarJogo(struct game_state* state);
void CarregarJogoSalvo(struct game_state* state);