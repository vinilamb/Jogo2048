#include "utils.h"

#include <stdio.h>

void limpar_buffer()
{
	char c; while ((c = getchar()) != '\n' && c != EOF);
}