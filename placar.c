#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define PLACAR_ARQ "C:\\Users\\navar\\Desktop\\AlgProg\\Trab Final\\placar.txt"  //MUDAR PARA APENAS PLACAR.TXT
#define MAX_NOME 11
#define MAX_PLACAR 10
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int score = 0;

struct registro {
	char nome[MAX_NOME];
	int score;
};

typedef struct registro Placar[MAX_PLACAR];



void fill_placar(Placar buffer) {
	for (int i = 0; i < MAX_PLACAR; i++) {
		fgets(buffer[i].nome, MAX_NOME, stdin);
		if (strlen(buffer[i].nome) != MAX_NOME - 1 || buffer[i].nome[MAX_NOME - 2] == '\n')
			buffer[i].nome[strlen(buffer[i].nome) - 1] = '\0';
		fflush(stdin);
		buffer[i].score = 0;
	}
	return;
}

//Nao quer criar o txt na pasta do meu repo (Vini N.)!!

void salvar_placar(Placar buffer) {
	FILE *arq = fopen(PLACAR_ARQ, "r+");
	if (arq == NULL) {
		printf("Não foi possível acessar o arquivo.");
		return;
	}

	for (int i = 0; i < MAX_PLACAR; i++) {
		fprintf(arq, "%s %d\n", buffer[i].nome, buffer[i].score);
	}
	fclose(arq);
	return;
}
/*    //Tá dando excecao no segundo strtok sla pq...
struct registro ler_linha(FILE *arq) {
	char string_lida[30], *pch = NULL;
	struct registro jogador;
	fgets(string_lida, 30, arq);
	pch = strtok(string_lida, " ");
	strcpy(jogador.nome, pch);
	pch = strtok(pch, "\n");
	jogador.score = atoi(pch);
	return jogador;
}*/

void ler_placar(Placar buffer) {
	FILE* arq = fopen(PLACAR_ARQ, "r");

	if (arq == NULL) {
		printf("Erro na leitura do placar!!");
		exit(EXIT_FAILURE);
	}else{
		for (int i = 0; i < MAX_NOME; i++) {
			buffer[i] = ler_linha(arq);
		}
	}
	
	fclose(arq);

}


//Queria verificar!!!!
void obter_score(Placar buffer, int score) {
	for (int i = 0; i <= MAX_PLACAR; i++) {
		if (score > buffer[i].score) {
			struct registro pontuacao;

			printf("Insira o seu nome: ");
			fgets(pontuacao.nome, MAX_NOME, stdin);
			if (strlen(pontuacao.nome) != MAX_NOME - 1 || pontuacao.nome[MAX_NOME - 2] == '\n')
				pontuacao.nome[strlen(pontuacao.nome) - 1] = '\0';

			pontuacao.score = score;
			for (int j = 0; j < MAX_PLACAR - i; j++) {
				buffer[MAX_PLACAR - j] = buffer[MAX_PLACAR - j - 1];
			}

			buffer[i] = pontuacao;
			return;
		}
	}
}


void imprimir_score(int score) {
	printf("Pontuacao: %d \n", score);

}