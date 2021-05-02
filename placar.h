#pragma once

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_NOME 40
#define MAX_PLACAR 10

struct registro {
	char nome[MAX_NOME];
	int score;
};

typedef struct registro Placar[MAX_PLACAR];

int ObterPlacar(Placar buffer);

void SalvarPlacarComRecorde(Placar placar, int n, struct registro recorde);