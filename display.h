#pragma once

#include <stdbool.h>

#include "board.h"
#include "placar.h"

void Display(Board b, int score, int movimentos, Placar p, int n_placar);

// Remover esses do header depois
void Display_Board(Board b);
void Display_Casa(int x, int y, int score);
void Display_Score(int x, int y, int score);
void Display_Movimentos(int x, int y, int movimentos);
void Display_Placar(int x, int y, Placar p, int n);

void MostrarCursor(bool mostrar);