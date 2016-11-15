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
#include	"JOGO.h"

#define LINHAS 8
#define COLUNAS 8

TAB_tppTabuleiro tabuleiro;

/***********************************************************************
*
*  $TC Tipo de dados: JOG Descritor do Jogo
*
*
***********************************************************************/
/*
   typedef struct JOG_tagJogo {
   
				/* Numero  */
	/*		   
   } JOG_tpJogo ;

/***** Protótipos das funções encapuladas no módulo *****/
	
	static int converterColuna(char coluna);
	
	static int converterLinha(int linha);
	
	static int initTabuleiro();

/*****  Código das funções exportadas pelo módulo  *****/

/***********************************************************************
*
*  $FC Função: JOG  -ImprimirTabuleiro
*
***********************************************************************/
	JOG_tpCondRet JOG_MoverPeca(char colunaInicial, int linhaInicial, char colunaFinal, int linhaFinal){
	
		   int condRet;
		   int linInicial, colInicial, linFinal, colFinal;
		   
			linInicial = converterLinha(linhaInicial);
			colInicial = converterColuna(colunaInicial);
			
			linFinal = converterLinha(linhaFinal);
			colFinal = converterColuna(colunaFinal);
		   
		   condRet = TAB_MoverPeca(linInicial, colInicial, linFinal, colFinal, tabuleiro);
			
		return JOG_CondRetOK;
	}/* Fim função: JOG  -ImprimirTabuleiro*/

/***********************************************************************
*
*  $FC Função: JOG  -ImprimirTabuleiro
*
***********************************************************************/
   JOG_tpCondRet JOG_ImprimirPosicoes(){
   
	int lin, col, condRet;
	char* id =  (char*) malloc(sizeof(char)*4);
	initTabuleiro();
	
	/*Print header */
	printf("\n\n\n- - POSICOES - -\n\n");
	
	/*Print miolo do tabuleiro */
	for(lin = 0; lin< LINHAS; lin++){
		printf(" %d | ", (LINHAS - lin));
		
		for(col = 0; col< COLUNAS; col++){
			*id = '\0';
			condRet = TAB_ObterPeca(lin, col, &id, tabuleiro);
			if(condRet == TAB_CondRetOK){
				printf("|%s| ", id);
			}else if(condRet == TAB_CondRetPosicaoVazia){
				printf("|_,_| ");
			}else{
				printf("ERROR!!!\n");
				return JOG_CondRetErro;
			}
		}
		
		printf("|\n");
	}
	
	/* PrintLetters */
	printf("\n   | |_A_| |_B_| |_C_| |_D_| |_E_| |_F_| |_G_| |_H_| |\n");  
   
   free(id);
   return JOG_CondRetOK;
   } /* Fim função: JOG  -ImprimirTabuleiro*/	

/*****  Código das funções encapsuladas no módulo  *****/

/***********************************************************************
*
*  $FC Função: JOG  -Inicia o tabuleiro
*
***********************************************************************/

   int initTabuleiro(){
   
		//int condRet;
   
		tabuleiro = *((TAB_tppTabuleiro*) malloc(sizeof(TAB_tppTabuleiro)));
		if(tabuleiro == NULL) return JOG_CondRetErro;
		if(TAB_CriarTabuleiro(COLUNAS, LINHAS, &tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		
		
		if(TAB_InserirPeca(0, 0,  'T', 'P', "Torre.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		if(TAB_InserirPeca(0, 2,  'B', 'P', "Bispo.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		if(TAB_InserirPeca(0, 3,  'R', 'P', "Rei.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		if(TAB_InserirPeca(0, 5,  'B', 'P', "Bispo.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		if(TAB_InserirPeca(0, 7,  'T', 'P', "Torre.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		
		if(TAB_InserirPeca(1, 2,  'P', 'P', "Peao.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		if(TAB_InserirPeca(1, 3,  'P', 'P', "Peao.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		if(TAB_InserirPeca(1, 4,  'P', 'P', "Peao.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		if(TAB_InserirPeca(1, 5,  'P', 'P', "Peao.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		
		
		if(TAB_InserirPeca(6, 2,  'P', 'B', "Peao.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		if(TAB_InserirPeca(6, 3,  'P', 'B', "Peao.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		if(TAB_InserirPeca(6, 4,  'P', 'B', "Peao.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		if(TAB_InserirPeca(6, 5,  'P', 'B', "Peao.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		
		if(TAB_InserirPeca(7, 0,  'T', 'B', "Torre.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		if(TAB_InserirPeca(7, 2,  'B', 'B', "Bispo.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		if(TAB_InserirPeca(7, 3,  'R', 'B', "Rei.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		if(TAB_InserirPeca(7, 5,  'B', 'B', "Bispo.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		if(TAB_InserirPeca(7, 7,  'T', 'B', "Torre.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		
		return JOG_CondRetOK;
	}/* Fim função: JOG  -Inicia o tabuleiro*/	


/***********************************************************************
*
*  $FC Função: JOG  -Converte coordenada da linha
*
***********************************************************************/

   int converterLinha(int linha){
		/* Ajuste das coordenadas 1 based para a matriz interna 0 based, invertendo o
		 * ponto (0,0)
		 */
		return LINHAS - linha;
   
	}/* Fim função: JOG  -Converte coordenada da linha*/		

   
/***********************************************************************
*
*  $FC Função: JOG  -Converte coordenada da coluna
*
***********************************************************************/

   int converterColuna(char coluna){

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

