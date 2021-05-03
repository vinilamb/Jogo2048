#pragma once

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_NOME 15
#define MAX_PLACAR 10

struct registro {
	char nome[MAX_NOME];
	int score;
};

typedef struct registro Placar[MAX_PLACAR];

// Salva os resultados do placar.
void SalvarPlacar(Placar placar, int n_registros);

// Retorna o placar salvo.
int ObterPlacar(Placar buffer);

// Insere o registro em determinada posição do placar
// Se o placar está cheio, o registro na extremidade direita (maior índice) cai fora.
void Placar_InsereRegistro(Placar p, struct registro r, int insertAt);

// Determina se a pontuação informada resultaria em novo recorde no placar.
// Retorno: O índice de inserção do novo recorde no placar, ou -1.
int Placar_NovoRecorde(Placar p, int score);