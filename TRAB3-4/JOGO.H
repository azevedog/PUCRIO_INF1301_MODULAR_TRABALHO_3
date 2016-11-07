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
#include "TABULEIRO.h"
#include "PECA.h"

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
*  $FC Função: JOG  &Criar Tabuleiro
*
*  $ED Descrição da função
*     Cria um tabuleiro genérico para jogos.
*
*  $EP Parâmetros
*     numColunas  - Número de colunas do tabuleiro.
*
*     numLinhas  - Número de linhas do tabuleiro.
*
*     novoTabuleiro  - Ponteiro para o endereço de tabuleiro, para passagem do retorno
*		por referencia.
*
*  $FV Valor retornado
*     JOG_CondRetOK - Se executou corretamente.
*     JOG_CondRetErro - Caso contrário.
* 
*
***********************************************************************/

   JOG_tpCondRet  JOG_CriarTabuleiro(int numColunas, int numLinhas,
		TAB_tppTabuleiro* novoTabuleiro);
		
/***********************************************************************
*
*  $FC Função: JOG  &Inserir Peca
*
*  $ED Descrição da função
*     Criar e inserir uma peca no tabuleiro.
*
*  $EP Parâmetros
*     idPeca  - identificador da peca.
*
*     colunaPeca  - coluna onde se encontra a peca.
*
*     linhaPeca  - linha onde se encontra a peca.
*
*     TAB_MoverPeca  - ponteiro pra funcao mover peca do modulo Tabuleiro.
*
*  $FV Valor retornado
*     JOG_CondRetOK - Se executou corretamente.
*     JOG_CondRetErro - Caso contrário.
* 
*
***********************************************************************/

   JOG_tpCondRet  JOG_InserirPeca(char idPeca, int colunaPeca, int linhaPeca,
		int* TAB_MoverPeca (int iniX, int iniY, int fimX, int fimY);

/***********************************************************************
*
*  $FC Função: JOG  &Procurar Peca
*
*  $ED Descrição da função
*     Procurar uma peca no tabuleiro.
*
*  $EP Parâmetros
*     idPeca  - identificador da peca.
*
*     timePeca  - time da peca.
*
*  $FV Valor retornado
*     JOG_CondRetOK - Se executou corretamente.
*     JOG_CondRetErro - Caso contrário.
* 
*
***********************************************************************/

   JOG_tpCondRet  JOG_InserirPeca(char idPeca, char timePeca);
		

		
		
		
		

