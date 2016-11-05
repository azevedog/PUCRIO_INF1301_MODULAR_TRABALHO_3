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
*
*  $ED Descrição do módulo
*   Implementa um jogo generico de tabuleiro.
*	
*	Um jogo pode N elementos, um tabuleiro e N jogadores. E permite:
*		- 
*		- Obter lista de ameacantes (outros elementos que podem
*		alcancar aquela posicao eliminando elementos de outros jogadores.
*
***************************************************************************/



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


