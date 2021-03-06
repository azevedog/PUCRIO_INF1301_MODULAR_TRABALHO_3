/***************************************************************************
*
*  $MCD M�dulo de defini��o: JOG  Jogo generico 
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
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*      3       gbha   16/nov/2016 Conclusao do desenvolvimento
*      2       mcs   11/nov/2016 Continua��o do desenvolvimento
*      1       gbha   5/nov/2016 In�cio desenvolvimento
*
*
*  $ED Descri��o do m�dulo
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

/***** Declara��es exportadas pelo m�dulo *****/

/* Tipo refer�ncia para um jogo */
typedef struct JOG_tagJogo* JOG_tppJogo;


/***********************************************************************
*
*  $TC Tipo de dados: JOG Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es do jogo
*
***********************************************************************/

typedef enum {

         JOG_CondRetOK ,
               /* Concluiu corretamente */

         JOG_CondRetErro,
               /* Nao concluiu a solicitacao */
			   
		 JOG_CondRetMovimentoIlegal,
               /* Movimento n�o permitido */

         JOG_CondRetEliminouPecaAdversario,
               /* Movimento comeu uma peca do adversario */
		
		JOGCondRetAmecada,
				/* Indica que outros elementos ameacam uma posicao */
				
		JOGCondRetAmeaca,
                /* Indica que o elemento desta posicao ameaca outros
				elementos */
				
		JOGCondRetCheckMate
				/* Indica o fim do jogo */
} JOG_tpCondRet ;

/***********************************************************************
*
*  $FC Fun��o: JOG  &IniciaJogo
*
*  $ED Descri��o da fun��o
*     Monta as estruturas necessarias para o jogo comecar.
*
*  $EP Par�metros
*	
*  $FV Valor retornado
*     JOG_CondRetOK - Se executou corretamente.
*     JOG_CondRetErro - Caso contr�rio.
* 
*
***********************************************************************/  
   JOG_tpCondRet JOG_IniciaJogo();


/***********************************************************************
*
*  $FC Fun��o: JOG  &MoverPeca
*
*  $ED Descri��o da fun��o
*     Exibe todos os elementos no jogo.
*
*  $EP Par�metros
*		colunaInicial - Letra da coluna de onde se quer tirar a peca.
*		linhaInicial - Numero da linha de onde se quer tirar a peca.
*		colunaFinal - Letra da coluna para onde se quer mover a peca.
*		linhaFinal - Letra da linha para onde se quer mover a peca.
*	
*  $FV Valor retornado
*     JOG_CondRetOK - Se executou corretamente.
*     JOG_CondRetMovimentoIlegal - Caso nao tenha sido possivel realizar.
*     JOG_CondRetEliminouPecaAdversario - Caso tenha comido adversario.
*     JOG_CondRetErro - Caso contr�rio.
* 
*
***********************************************************************/  
	JOG_tpCondRet JOG_MoverPeca(char colunaInicial, int linhaInicial,
	char colunaFinal, int linhaFinal);
   
/***********************************************************************
*
*  $FC Fun��o: JOG  &ValidarAmeacantes
*
*  $ED Descri��o da fun��o
*     Determina se uma posicao sofre ameaca.
*
*  $EP Par�metros
*		colunaInicial - Letra da coluna de onde se quer verificar a condicao.
*		linhaInicial - Numero da linha de onde se quer verificar a condicao.
*
*  $FV Valor retornado
*     JOG_CondRetOK - Caso nao seja ameacada.
*	  JOGCondRetAmecada - Caso seja ameacada.
*     JOG_CondRetErro - Caso contr�rio.
* 
*
***********************************************************************/  
	JOG_tpCondRet JOG_ValidarAmeacantes(char colunaInicial, int linhaInicial);
	
/***********************************************************************
*
*  $FC Fun��o: JOG  &ValidarAmeacados
*
*  $ED Descri��o da fun��o
*     Determina se uma posicao esta ameacando.
*
*  $EP Par�metros
*		colunaInicial - Letra da coluna de onde se quer verificar a condicao.
*		linhaInicial - Numero da linha de onde se quer verificar a condicao.
*
*  $FV Valor retornado
*     JOG_CondRetOK - Caso nao esteja ameacando ninguem.
*	  JOGCondRetAmeaca - Caso esteja ameacando alguem.
*     JOG_CondRetErro - Caso contr�rio.
* 
*
***********************************************************************/  
	JOG_tpCondRet JOG_ValidarAmeacados(char colunaInicial, int linhaInicial);
	
/***********************************************************************
*
*  $FC Fun��o: JOG  &ValidarReis
*
*  $ED Descri��o da fun��o
*     Determina se os reis est�o sob ameaca.
*
*  $EP Par�metros
*
*  $FV Valor retornado
*     JOG_CondRetOK - Caso nao esteja ameacando ninguem.
*	  JOGCondRetCheckMate - Caso o jogo tenha chegado ao fim.
*     JOG_CondRetErro - Caso contr�rio.
* 
*
***********************************************************************/  
	JOG_tpCondRet JOG_ValidarReis();	
	
/***********************************************************************
*
*  $FC Fun��o: JOG  &ImprimirPosicoes
*
*  $ED Descri��o da fun��o
*     Exibe todos os elementos no jogo.
*
*  $EP Par�metros
*
*  $FV Valor retornado
*     JOG_CondRetOK - Se executou corretamente.
*     JOG_CondRetErro - Caso contr�rio.
* 
*
***********************************************************************/  
   JOG_tpCondRet JOG_ImprimirPosicoes();


/********** Fim do m�dulo de defini��o: JOG Jogo generico de tabuleiro **********/
		

