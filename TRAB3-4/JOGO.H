/***************************************************************************
*
*  $MCD Módulo de definição: JOG  Jogo generico 
*
*  Arquivo gerado:              JOGO.h
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
*      1       gbha   5/nov/2016 Início desenvolvimento
*      2       mcs   11/nov/2016 Continuação do desenvolvimento
*
*
*  $ED Descrição do módulo
*   Implementa um jogo generico de tabuleiro.
*	
*	Um jogo pode N elementos, um tabuleiro e N jogadores. E permite:
*		- Criar e manipular um tabuleiro
*		- Criar e manipular pecas do tabuleiro
*		- Obter lista de ameacantes (outros elementos que podem
*		alcancar aquela posicao eliminando elementos de outros jogadores.
*
***************************************************************************/

#include "LISTA.h"

/***** Declarações exportadas pelo módulo *****/

/* Tipo referência para um jogo */
typedef struct JOG_tagJogo* JOG_tppJogo;


/***********************************************************************
*
*  $TC Tipo de dados: JOG Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções do jogo
*
***********************************************************************/

typedef enum {

         JOG_CondRetOK ,
               /* Concluiu corretamente */

         JOG_CondRetErro
               /* Nao concluiu a solicitacao */
			   
} JOG_tpCondRet ;

/***********************************************************************
*
*  $FC Função: JOG  &IniciaJogo
*
*  $ED Descrição da função
*     Monta as estruturas necessarias para o jogo comecar.
*
*  $EP Parâmetros
*
*  $FV Valor retornado
*     JOG_CondRetOK - Se executou corretamente.
*     JOG_CondRetErro - Caso contrário.
* 
*
***********************************************************************/  
   JOG_tpCondRet JOG_IniciaJogo();


/***********************************************************************
*
*  $FC Função: JOG  &ImprimirPosicoes
*
*  $ED Descrição da função
*     Exibe todos os elementos no jogo.
*
*  $EP Parâmetros
*
*  $FV Valor retornado
*     JOG_CondRetOK - Se executou corretamente.
*     JOG_CondRetErro - Caso contrário.
* 
*
***********************************************************************/  
	JOG_tpCondRet JOG_MoverPeca(char colunaInicial, int linhaInicial, char colunaFinal, int linhaFinal);
   
   
/***********************************************************************
*
*  $FC Função: JOG  &ImprimirPosicoes
*
*  $ED Descrição da função
*     Exibe todos os elementos no jogo.
*
*  $EP Parâmetros
*
*  $FV Valor retornado
*     JOG_CondRetOK - Se executou corretamente.
*     JOG_CondRetErro - Caso contrário.
* 
*
***********************************************************************/  
   JOG_tpCondRet JOG_ImprimirPosicoes();


/********** Fim do módulo de definição: JOG Jogo generico de tabuleiro **********/
		

