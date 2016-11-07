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
#include	"PECA.h"

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

/*****  Código das funções exportadas pelo módulo  *****/


/*****  Código das funções encapsuladas no módulo  *****/
   
/***********************************************************************
*
*  $FC Função: TAB  -Converte coordenada da coluna
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
	}/* Fim função: TAB  -Converte coordenada da coluna*/			

/********** Fim do módulo de implementação: JOG  Jogo generico **********/

