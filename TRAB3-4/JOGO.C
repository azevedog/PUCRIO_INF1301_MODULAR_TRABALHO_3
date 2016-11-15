/***************************************************************************
*  $MCI Módulo de implementação: JOG  Jogo generico 
*
*  Arquivo gerado:              JOGO.c
*  Letras identificadoras:      JOG
*
*  Nome da base de software:    OpenJogos
*
*  Projeto: MODULAR_T2
*  Gestor:  EAMCEMP LTDA
*  Autores: MCS e GBHA
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*      1       gbha   5/NOV/2016 início desenvolvimento
*      2       mcs   11/nov/2016 Continuação do desenvolvimento
*
*
***************************************************************************/

#include   <stdio.h>
#include   <string.h>
#include   <memory.h>
#include   <malloc.h>
#include   <assert.h>
#include	"TABULEIRO.h"
#include	"LISTA.h"

#define LINHAS 8
#define COLUNAS 8

TAB_tppTabuleiro tabuleiro;

/***********************************************************************
*
*  $TC Tipo de dados: JOG Descritor do Jogo
*
*
***********************************************************************/

   typedef struct JOG_tagJogo {
   
				/* Numero  */
			   
   } JOG_tpJogo ;

/***** Protótipos das funções encapuladas no módulo *****/
	
	static int converteColuna(char coluna);
	
	static int converterLinha(int linha);
	
	static void initTabuleiro();

/*****  Código das funções exportadas pelo módulo  *****/

/***********************************************************************
*
*  $FC Função: JOG  -ImprimirTabuleiro
*
***********************************************************************/

   JOG_tpCondRet JOG_ImprimirPosicoes(){
   
	int lin, col;
	initTabuleiro();
	
	
	for(lin = 0; lin< LINHAS; lin++){
		printf("\n%d ", (LINHAS - lin));
	
		for(col = 0; col< COLUNAS; col++){
			if(TAB_ObterPeca(int linhaInicial, int colunaInicial, char** id,
				TAB_tppTabuleiro tabuleiro) == TAB_CondRetOK){
				
				
			}else{
				printf("ERROR!!!\n");
				return JOG_CondRetErro;
			}
			
		}
	}
		
	/* PrintLetters */
   
   return JOG_CondRetOK
   } /* Fim função: JOG  -ImprimirTabuleiro*/	

/*****  Código das funções encapsuladas no módulo  *****/

/***********************************************************************
*
*  $FC Função: JOG  -Inicia o tabuleiro
*
***********************************************************************/

   void initTabuleiro(){
   
		tabuleiro = *((TAB_tppTabuleiro*) malloc(sizeof(TAB_tppTabuleiro)));
		if(tabuleiro == NULL) return JOG_CondRetErro;
		if(TAB_CriarTabuleiro(COLUNAS, LINHAS, &tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		
	
	}/* Fim função: JOG  -Inicia o tabuleiro*/	


/***********************************************************************
*
*  $FC Função: JOG  -Converte coordenada da linha
*
***********************************************************************/

   int converteLinha(int linha){
		/* Ajuste das coordenadas 1 based para a matriz interna 0 based, invertendo o
		 * ponto (0,0)
		 */
		return LINHAS - linha
   
	}/* Fim função: JOG  -Converte coordenada da linha*/		

   
/***********************************************************************
*
*  $FC Função: JOG  -Converte coordenada da coluna
*
***********************************************************************/

   int converteColuna(char coluna){
   
   		/* Ajuste das coordenadas 1 based para a matriz interna 0 based*/
		inicialX = inicialX -1;
		finalX = finalX -1;
	
		int dist;
		if ((coluna >= 'a') && (coluna <= 'z')){
			dist = (coluna - 'a');
		}
		else{
			dist = coluna - 'A';
		}
		return dist;
	}/* Fim função: JOG  -Converte coordenada da coluna*/			

/********** Fim do módulo de implementação: JOG  Jogo generico **********/

