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
*      3       gbha   16/nov/2016 Conclusao do desenvolvimento
*      2       mcs   11/nov/2016 Continuação do desenvolvimento
*      1       gbha   5/nov/2016 Início desenvolvimento
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

         JOG_CondRetErro,
               /* Nao concluiu a solicitacao */
			   
		 JOG_CondRetMovimentoIlegal,
               /* Movimento não permitido */

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
*  $FC Função: JOG  &MoverPeca
*
*  $ED Descrição da função
*     Exibe todos os elementos no jogo.
*
*  $EP Parâmetros
*		colunaInicial - Letra da coluna de onde se quer tirar a peca.
*		linhaInicial - Numero da linha de onde se quer tirar a peca.
*		colunaFinal - Letra da coluna para onde se quer mover a peca.
*		linhaFinal - Letra da linha para onde se quer mover a peca.
*	
*  $FV Valor retornado
*     JOG_CondRetOK - Se executou corretamente.
*     JOG_CondRetMovimentoIlegal - Caso nao tenha sido possivel realizar.
*     JOG_CondRetEliminouPecaAdversario - Caso tenha comido adversario.
*     JOG_CondRetErro - Caso contrário.
* 
*
***********************************************************************/  
	JOG_tpCondRet JOG_MoverPeca(char colunaInicial, int linhaInicial,
	char colunaFinal, int linhaFinal);
   
/***********************************************************************
*
*  $FC Função: JOG  &ValidarAmeacantes
*
*  $ED Descrição da função
*     Determina se uma posicao sofre ameaca.
*
*  $EP Parâmetros
*		colunaInicial - Letra da coluna de onde se quer verificar a condicao.
*		linhaInicial - Numero da linha de onde se quer verificar a condicao.
*
*  $FV Valor retornado
*     JOG_CondRetOK - Caso nao seja ameacada.
*	  JOGCondRetAmecada - Caso seja ameacada.
*     JOG_CondRetErro - Caso contrário.
* 
*
***********************************************************************/  
	JOG_tpCondRet JOG_ValidarAmeacantes(char colunaInicial, int linhaInicial);
	
/***********************************************************************
*
*  $FC Função: JOG  &ValidarAmeacados
*
*  $ED Descrição da função
*     Determina se uma posicao esta ameacando.
*
*  $EP Parâmetros
*		colunaInicial - Letra da coluna de onde se quer verificar a condicao.
*		linhaInicial - Numero da linha de onde se quer verificar a condicao.
*
*  $FV Valor retornado
*     JOG_CondRetOK - Caso nao esteja ameacando ninguem.
*	  JOGCondRetAmeaca - Caso esteja ameacando alguem.
*     JOG_CondRetErro - Caso contrário.
* 
*
***********************************************************************/  
	JOG_tpCondRet JOG_ValidarAmeacados(char colunaInicial, int linhaInicial);
	
/***********************************************************************
*
*  $FC Função: JOG  &ValidarReis
*
*  $ED Descrição da função
*     Determina se os reis estão sob ameaca.
*
*  $EP Parâmetros
*
*  $FV Valor retornado
*     JOG_CondRetOK - Caso nao esteja ameacando ninguem.
*	  JOGCondRetCheckMate - Caso o jogo tenha chegado ao fim.
*     JOG_CondRetErro - Caso contrário.
* 
*
***********************************************************************/  
	JOG_tpCondRet JOG_ValidarReis();	
	
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
		

