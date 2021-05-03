#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

#include "board.h"
#include "display.h"
#include "placar.h"



struct game_state {
	Board board;
	int score;
	int movimentos;
};

void Jogada(struct game_state* state, char cmd);

void NewGame(struct game_state* state);