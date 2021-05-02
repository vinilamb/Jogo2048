#pragma once

#include "placar.h"
#include <stdbool.h>

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

		if (r_scan == EOF || r_scan != 1 || r_fgets == NULL)
			break;

		n_lidos++;
	}

	fclose(f);
	return n_lidos;
}

// Tenta inserir o registro no placar. Se o registro for um novo recorde, 
// ele será inserido no placar na posição adequada. Caso contrário nada acontece.
void InsereRecorde(Placar p, int n, struct registro r) {
	//struct registro temp;
	//bool inserido = false;

	//int i;
	//for (i = n - 1; (i >= 0 && p[i].score > r.score); i--)
	//	p[i + 1] = p[i];

	//p[i + 1] = r;

	//return n + 1;
}

// Modelo para a inserção do placar
int insertSorted(int arr[], int n, int key)
{
	// Encontrar posição para inserir.
	int insertAt = 0;
	while (insertAt < n) {
		if (key > arr[insertAt]) break;
		insertAt++;
	}

	if (insertAt == n) return;

	// Efetua a inserção.
	int moving = arr[insertAt];
	arr[insertAt] = key;
	insertAt++;
	while (insertAt < n) {
		int temp = arr[insertAt];
		arr[insertAt] = moving;
		moving = temp;
		insertAt++;
	}
}

void SalvarPlacarComRecorde(Placar placar, int n, struct registro recorde)
{

}
