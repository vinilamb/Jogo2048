#pragma once

#include <stdbool.h>

#include "board.h"
#include "placar.h"

void Display();

// Remover esses do header depois
void Display_Board(Board b);
void Display_Casa(int x, int y, int score);
void Display_Score(int x, int y, int score);
void Display_Movimentos(int x, int y, int movimentos);
void Display_Placar(Placar p);

void MostrarCursor(bool mostrar);