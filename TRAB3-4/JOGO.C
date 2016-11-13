/***************************************************************************
*  $MCI M�dulo de implementa��o: JOG  Jogo generico 
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
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*      1       gbha   5/NOV/2016 in�cio desenvolvimento
*      2       mcs   11/nov/2016 Continua��o do desenvolvimento
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

/***** Prot�tipos das fun��es encapuladas no m�dulo *****/
	
	static int converteColuna(char coluna);	

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/


/*****  C�digo das fun��es encapsuladas no m�dulo  *****/
   
/***********************************************************************
*
*  $FC Fun��o: TAB  -Converte coordenada da coluna
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
	}/* Fim fun��o: TAB  -Converte coordenada da coluna*/			

/********** Fim do m�dulo de implementa��o: JOG  Jogo generico **********/
