#include "utils.h"

#include <stdlib.h>
#include <ctype.h>

// Função auxiliar para ler os nomes dos jogadores.
// Pula whitespace no inicio da stream e não deixa a newline no final.
int ler_nome(char* buffer, int n, FILE* f) {
	char c;
	int i = 0, skip_ws = 1;

	while ((c = fgetc(f)) != EOF && i < n-1) {
		if (skip_ws && isspace(c)) 
			continue;
		else 
			skip_ws = 0;

		if (c == '\n') break;

		buffer[i] = c;
		i++;
	}

	if (!ferror(f)) {
		fprintf(stderr, "FATAL: Erro ao ler o nome!");
		exit(EXIT_FAILURE);
	}

	buffer[i] = '\0';
	return i;
}