/***************************************************************************
*  $MCI Módulo de implementação: PRI Implementacao do xadrez para o usuario 
*
*  Arquivo gerado:              MainJOGO.c
*  Letras identificadoras:      PRI
*
*  Nome da base de software:    OpenJogos
*
*  Projeto: MODULAR_T2
*  Gestor:  EAMCEMP LTDA
*  Autores: MCS e GBHA
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*      1       gbha   14/NOV/2016 início desenvolvimento
*
*
***************************************************************************/

#include   <stdio.h>
#include   <string.h>
#include   <memory.h>
#include   <malloc.h>
#include	"JOGO.h"

#define PLAYER_NAME_SIZE 10

char player1[PLAYER_NAME_SIZE];
char player2[PLAYER_NAME_SIZE];

void printWelcome(){
	printf("\n******************************\n");
	printf("* Bem Vindo ao Xadrez Voador * \n");
	printf("*          EAMCEMP           * \n");
	printf("******************************\n");
}

void getPlayerNames(){
	printf("\nDigite o nome do Jogador 1 em %d caracteres: ", PLAYER_NAME_SIZE);
	scanf("%s", player1);
	printf("\nDigite o nome do Jogador 2 em %d caracteres: ", PLAYER_NAME_SIZE);
	scanf("%s", player2);
}


int main(void){
	printWelcome();
	getPlayerNames();
	JOG_IniciaJogo();
	JOG_ImprimirPosicoes();
}			

/********** Fim do módulo de implementação: PRI Implementacao do xadrez para o usuario **********/

