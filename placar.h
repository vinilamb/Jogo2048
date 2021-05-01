#pragma once

#define MAX_NOME 11
#define MAX_PLACAR 10
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct registro {
	char nome[MAX_NOME];
	int score;
};

typedef struct registro Placar[MAX_PLACAR];

void obter_score(Placar buffer, int score);

void salvar_placar(Placar buffer);

void fill_placar(void);

void imprimir_score(int score);

void ler_placar(Placar buffer);

struct registro ler_linha(FILE* arq);