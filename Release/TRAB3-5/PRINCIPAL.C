/***************************************************************************
*  $MCI Módulo de implementação: PRI Implementacao do xadrez para o usuario 
*
*  Arquivo gerado:              PRINCIPAL.c
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
*      2       gbha   16/NOV/2016 Conclusao desenvolvimento
*      1       gbha   14/NOV/2016 Início desenvolvimento
*
*
***************************************************************************/
#include  <stdlib.h>
#include   <stdio.h>
#include   <string.h>
#include   <memory.h>
#include   <malloc.h>
#include	"JOGO.h"

#define PLAYER_NAME_SIZE 10
#define END_GAME "FIM"
#define ZERO 48

static char player0[PLAYER_NAME_SIZE];
static char player1[PLAYER_NAME_SIZE];

/* Funcao interna para imprimir boas vindas.*/
void printWelcome(){
	printf("\n\n\n  ******************************\n");
	printf("  * Bem Vindo ao Xadrez Voador * \n");
	printf("  *          EAMCEMP           * \n");
	printf("  ******************************\n\n\n");
}

/* Funcao interna para ler nome dos jogadores. */
void getPlayerNames(){
	printf("\nDigite o nome do Jogador 1 em %d caracteres: ", PLAYER_NAME_SIZE);
	scanf("%s", player0);
	printf("\nDigite o nome do Jogador 2 em %d caracteres: ", PLAYER_NAME_SIZE);
	scanf("%s", player1);
}

/* Funcao interna de encerramento.*/
void shutDownHook(){
	printf("\n\nObrigado por jogar o Xadrez Voador, volte sempre :-)\n\n");
	exit(42);
}

/* Funcao interna para exibicao do resultado da jogada. */
void showTurnResult(char colunaInicial, int linhaInicial){
	JOG_ImprimirPosicoes();
	JOG_ValidarAmeacantes(colunaInicial, linhaInicial);
	JOG_ValidarAmeacados(colunaInicial,  linhaInicial);
	if(JOG_ValidarReis() == JOGCondRetCheckMate){
		shutDownHook();
	}
	printf("\n");
}

/*Funcao principal*/
int main(void){
	int linhaFinal;
	int linhaInicial;
	int condRet;
	int turn = 0;
	
	char colunaInicial;
	char colunaFinal;
	
	char origem[4];
	char destino[4];
	
	char* endCond = (char*) malloc(sizeof(char)*4);
	if(endCond == NULL) exit(1);
	
	printWelcome();
	getPlayerNames();
	JOG_IniciaJogo();
	JOG_ImprimirPosicoes();
	
	while(strcmp(endCond, END_GAME) != 0){
		if((turn % 2) == 0){
			printf("\n%s ", player0);
		}else{
			printf("\n%s ", player1);
		}
		
		printf("digite o movimento desejado <origem, destino>\n");
		
		printf("Digite a origem (coluna,linha - ex.: B6): ");
		scanf("%s", origem);
		if(strcmp(origem, END_GAME) == 0) break;
		
		printf("Digite o destino (no mesmo formato): ");
		scanf("%s", destino);
		if(strcmp(destino, END_GAME) == 0) break;
		
		colunaInicial = origem[0];
		linhaInicial =  origem[1] - ZERO;
		
		colunaFinal = destino[0];
		linhaFinal = destino[1] - ZERO;
		
		condRet = JOG_MoverPeca(colunaInicial, linhaInicial, colunaFinal, linhaFinal);
		switch(condRet){
			case JOG_CondRetMovimentoIlegal:
				printf("Movimento ilegal");
			break;
             
			case JOG_CondRetEliminouPecaAdversario:
				printf("Eliminou uma peca do adversario :-)");
				showTurnResult(colunaFinal, linhaFinal);
				turn++;
			break;
			
			case JOG_CondRetErro:
				printf("Erro no movimento, repita");
			break;
			
			case JOG_CondRetOK:
				printf("Jogada realizada");
				showTurnResult(colunaFinal, linhaFinal);
				turn++;
			break;
		}
	}
	
	shutDownHook();
	return 42;
}			

/********** Fim do módulo de implementação: PRI Implementacao do xadrez para o usuario **********/

