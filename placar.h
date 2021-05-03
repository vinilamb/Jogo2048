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

// Insere o registro em determinada posi��o do placar
// Se o placar est� cheio, o registro na extremidade direita (maior �ndice) cai fora.
void Placar_InsereRegistro(Placar p, struct registro r, int insertAt);

// Determina se a pontua��o informada resultaria em novo recorde no placar.
// Retorno: O �ndice de inser��o do novo recorde no placar, ou -1.
int Placar_NovoRecorde(Placar p, int score);