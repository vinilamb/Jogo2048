#pragma once

#define MAX_NOME
#define MAX_PLACAR 10

struct registro {
	int score;
	char nome[MAX_NOME];
};

typedef registro Placar[MAX_PLACAR];

void obter_placar(Placar buffer);

void salvar_placar(Placar buffer, registro novo);