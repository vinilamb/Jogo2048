#pragma once

#include "placar.h"
#include <stdbool.h>
#include <assert.h>

#define ARQUIVO "placar.txt"

int ObterPlacar(Placar buffer)
{
	FILE* f = fopen(ARQUIVO, "r");
	if (f == NULL) {
		// Arquivo não existe (e possívelmente outros casos onde o arquivo não pode ser acessado)
		return 0;
	}

	int n_lidos = 0;
	while (n_lidos < MAX_NOME) {
		struct registro* current = &buffer[n_lidos];
		int r_scan;
		char* r_fgets;

		r_scan = fscanf(f, " %d", &current->score);
		r_fgets = fgets(current->nome, MAX_NOME, f);
		// Remove a newline no final do nome
		current->nome[strcspn(current->nome, "\n")] = 0;

		if (r_scan == EOF || r_scan != 1 || r_fgets == NULL)
			break;

		n_lidos++;
	}

	fclose(f);
	return n_lidos;
}

void SalvarPlacar(Placar p, int n_registros)
{
	assert(n_registros <= MAX_PLACAR);

	FILE* f = fopen(ARQUIVO, "w");
	if (f == NULL) {
		// Arquivo não existe (e possívelmente outros casos onde o arquivo não pode ser acessado)
		return;
	}

	for (int i = 0; i < n_registros; i++) {
		fprintf(f, "%d %s\n", p[i].score, p[i].nome);
	}
}

void Placar_InsereRegistro(Placar p, struct registro r, int insertAt) {
	for (int i = MAX_PLACAR - 1; i > insertAt; i--) {
		p[i] = p[i - 1];
	}
	p[insertAt] = r;
}


int Placar_NovoRecorde(Placar p, int score) {
	int insertAt = 0;
	while (insertAt < MAX_PLACAR) {
		if (score > p[insertAt].score) break;
		insertAt++;
	}
	return insertAt != MAX_PLACAR ? insertAt : -1;
}