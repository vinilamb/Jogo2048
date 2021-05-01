#pragma once
#define _CRT_SECURE_NO_WARNINGS  //necessário para o fopen
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


//Cria um template para o arquivo placar
void fill_placar(void) {
	FILE* arq = fopen(PLACAR_ARQ, "w");
	if (arq == NULL) {
		printf("Não foi possível acessar o arquivo.");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < MAX_PLACAR; i++) {
		fprintf(arq, "---\n-1\n");
	}
	fclose(arq);


	return;
}


//Nao quer criar o txt na pasta do meu repo (Vini N.)!!
//Salva o placar no txt
void salvar_placar(Placar buffer) {
	FILE *arq = fopen(PLACAR_ARQ, "r+");
	if (arq == NULL) {
		printf("Não foi possível acessar o arquivo.");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < MAX_PLACAR; i++) {
		fprintf(arq, "%s\n%d\n", buffer[i].nome, buffer[i].score);
	}
	fclose(arq);
	return;
}


//Lê a e retorna a informação relativa a um jogador no arquivo placar
struct registro ler_informacao(FILE *arq) {
	struct registro jogador;
	char caux;
	fgets(jogador.nome, MAX_NOME, arq);
	if (strlen(jogador.nome) != MAX_NOME - 1 || jogador.nome[MAX_NOME - 2] == '\n')
		jogador.nome[strlen(jogador.nome) - 1] = '\0';

	fscanf(arq, " %d", &jogador.score);
	fscanf(arq, "%c", &caux);

	printf("\n ler linha %s %d \n", jogador.nome, jogador.score);
	return jogador;
}

//Lê o arquivo placar e preenche o buffer
void ler_placar(Placar buffer) {
	FILE* arq = fopen(PLACAR_ARQ, "r");

	if (arq == NULL) {
		printf("Erro na leitura do placar!!");
		exit(EXIT_FAILURE);
	}else{
		for (int i = 0; i < MAX_PLACAR; i++) {
			buffer[i] = ler_informacao(arq);
			printf("\n buffer %s %d\n", buffer[i].nome, buffer[i].score);
		}
	}
	
	fclose(arq);
	return;
}


//Compara o escore obtido com o top 10 e substitui na posicao adequada
void obter_score(Placar buffer, int score) {
	for (int i = 0; i < MAX_PLACAR; i++) {
		if (score > buffer[i].score) {
			struct registro pontuacao;
			printf("Insira o seu nome: ");
			fgets(pontuacao.nome, MAX_NOME, stdin);
			if (strlen(pontuacao.nome) != MAX_NOME - 1 || pontuacao.nome[MAX_NOME - 2] == '\n')
				pontuacao.nome[strlen(pontuacao.nome) - 1] = '\0';
			printf("oi1\n");
			pontuacao.score = score;
			for (int j = 0; j <= MAX_PLACAR - i - 1; j++) {
				printf("%d\nbuffer[%d] =buffer[%d] \n", MAX_PLACAR - i - 1, MAX_PLACAR - j, MAX_PLACAR - j - 1);
				buffer[MAX_PLACAR - j-1] = buffer[MAX_PLACAR - j  - 2];
			}
			printf("oi %d", i);
			buffer[i] = pontuacao;
			printf("\ntestefinal %d\n", i);
			return;
		}
	}
}


void imprimir_score(int score) {
	printf("Pontuacao: %d \n", score);

}