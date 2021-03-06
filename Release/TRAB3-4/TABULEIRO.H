/***************************************************************************
*
*  $MCD M�dulo de defini��o: TAB  Tabuleiro para jogo generico 
*
*  Arquivo gerado:              TABULEIRO.h
*  Letras identificadoras:      TAB
*
*  Nome da base de software:    OpenJogos
*
*  Projeto: MODULAR_T2
*  Gestor:  EAMCEMP LTDA
*  Autores: MCS e GBHA
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*		5		gbha		14/nov/2016 Conlusao desenvolvimento T3
*     4       gbha  13/Nov/2016 Ajustes para o T3
*	   3       gbha  4/out/2016 Conclusao desenvolvimento
*	   2       gbha  3/out/2016 Continuacao desenvolvimento
*      1       mcs   1/out/2016 In�cio desenvolvimento
*
*  $ED Descri��o do m�dulo
*   Implementa um tabuleiro generico para jogos organizado
*	por linhas e colunas, ocupados por elementos genericos.
*	
*	Um jogo pode ser desenvolvido com este tabuleiro que
*	permite:
*		- Inserir peca
*		- Mover peca
*		- Remover peca
*		- Obter peca
*		- Obter lista de ameacantes (outras pecas que podem
*		alcancar aquela posicao. ELIMINACOES NAO SAO IMPLEMEN
*		TADAS NESSE MODULO. DEPENDE DAS REGRAS DE JOGOS QUE
*		SAO IMPLEMENTADAS FORA DESTE MODULO.
*
***************************************************************************/

#include "LISTA.h"

/***** Declara��es exportadas pelo m�dulo *****/

/* Tipo refer�ncia para um tabuleiro */
typedef struct TAB_tagTabuleiro* TAB_tppTabuleiro;


/***********************************************************************
*
*  $TC Tipo de dados: TAB Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es do tabuleiro
*
***********************************************************************/

typedef enum {

         TAB_CondRetOK ,
               /* Concluiu corretamente */

         TAB_CondRetErro,
               /* Nao concluiu a solicitacao */
			   
		 TAB_CondRetForaTabuleiro,
               /* Movimento para fora do tabuleiro */
		  
		 TAB_CondRetElementoNaoFaz,
               /* Movimento invalido para o elemento selecionado */

         TAB_CondRetSubstituiuOutroElemento,
               /* Movimento tirou um elemento original da posicao */
			   
		 TAB_CondRetElementoMesmoTime,
		  /* Movimento n�o realizando, posicao bloqueada por elemento do seu time. */
		  
		 TAB_CondRetPosicaoVazia
		  /*Indica que nao ha elemento na posicao solicitada*/
			   
} TAB_tpCondRet ;


/***********************************************************************
*
*  $FC Fun��o: TAB  &Criar Tabuleiro
*
*  $ED Descri��o da fun��o
*     Cria um tabuleiro gen�rico para jogos.
*
*  $EP Par�metros
*     numColunas  - N�mero de colunas do tabuleiro.
*
*     numLinhas  - N�mero de linhas do tabuleiro.
*
*     novoTabuleiro  - Ponteiro para o endere�o de tabuleiro, para passagem do retorno
*		por referencia.
*
*  $FV Valor retornado
*     TAB_CondRetOK - Se executou corretamente.
*     TAB_CondRetErro - Caso contr�rio.
* 
*
***********************************************************************/

   TAB_tpCondRet TAB_CriarTabuleiro(int numColunas, int numLinhas,
		TAB_tppTabuleiro* novoTabuleiro);

/***********************************************************************
*
*  $FC Fun��o: TAB  &Inserir peca
*
*  $ED Descri��o da fun��o
*     Insere uma peca no tabuleiro gen�rico para jogos.
*
*  $EP Par�metros
*     linha  - Posicao X no tabuleiro.
*
*     coluna  - Posicao Y no tabuleiro.
*
*     identificador  - Caracter que identifica o tipo de peca. Como
*     este atributo � armazenado em um byte, permite 128 tipos
*	  diferentes.
*
*	   corTime  - Caracter que identifica o time que esta peca
*     pertence. Como este atributo � armazenado em um byte,
*	   permite 128 tipos diferentes.
*
*     pathMovimento  - Caminho para execut�vel que processa a validade
*     do movimento da peca. Se respeita as regras da peca. N�O
*	  VALIDA SE O MOVIMENTO � OUT OF BOUNDS NO TABU
*	  LEIRO.
*
*     tabuleiro  - Ponteiro o tabuleiro que ter� a peca inserida
*
*     ExcluirValor  - Ponteiro para funcao que exclui valores das listas do elemento do
*	   tabuleiro.
*
*		OBS: ESSA FUNCAO NAO VALIDA SE ESTA INSERINDO POR CIMA DE OUTRA PECA
*		CABE AO JOGO VALIDAR ISSO OBTENDO A PECA NA POSICAO ANTES!
*  $FV Valor retornado
*     TAB_CondRetOK - Se executou corretamente.
*     TAB_CondRetForaTabuleiro - Caso x e y estajam fora dos limites.
*     TAB_CondRetErro - Caso contr�rio.
* 
*
***********************************************************************/

	TAB_tpCondRet TAB_InserirPeca(int linha, int coluna,  char identificador, char corTime, 
			char* pathMovimento, TAB_tppTabuleiro tabuleiro);

/***********************************************************************
*
*  $FC Fun��o: TAB  &Mover peca
*
*  $ED Descri��o da fun��o
*     Move uma peca no tabuleiro gen�rico para jogos.
*
*  $EP Par�metros
*     linhaInicial  - Coordenada horizontal da posicao inicial da peca
*
*     colunaInicial  - Coordenada vertical da posicao inicial da peca
*
*     linhaFinal  - Coordenada horizontal da posicao final da peca
*
*     colunaFinal  - Coordenada vertical da posicao final da peca
*
*     tabuleiro  - Ponteiro o tabuleiro que ter� a peca inserida
*
*  $FV Valor retornado
*     TAB_CondRetOK - Se executou corretamente.
*     TAB_CondRetForaTabuleiro - Caso x e y estajam fora dos limites.
*     TAB_CondRetElementoNaoFaz - Caso o elemento nao possa realizar o movimento.
*     TAB_CondRetSubstituiuOutroElemento - Caso existisse uma peca na posicao alvo.
*     TAB_CondRetErro - Caso contr�rio.
* 
*
***********************************************************************/

   TAB_tpCondRet TAB_MoverPeca(int linhaInicial, int colunaInicial, int linhaFinal,
   int colunaFinal, TAB_tppTabuleiro tabuleiro);
   
/***********************************************************************
*
*  $FC Fun��o: TAB  &Retirar peca
*
*  $ED Descri��o da fun��o
*     Retira uma peca no tabuleiro gen�rico para jogos.
*
*  $EP Par�metros
*     linhaInicial  - Coordenada horizontal da posicao da peca
*
*     colunaInicial  - Coordenada vertical da posicao  da peca
*
*     tabuleiro  - Ponteiro o tabuleiro que ter� a peca inserida
*
*  $FV Valor retornado
*     TAB_CondRetOK - Se executou corretamente.
*     TAB_CondRetForaTabuleiro - Caso x e y estajam fora dos limites.
*     TAB_CondRetErro - Caso contr�rio.
* 
*
***********************************************************************/

   TAB_tpCondRet TAB_RetirarPeca(int linhaInicial, int colunaInicial, TAB_tppTabuleiro tabuleiro);

/***********************************************************************
*
*  $FC Fun��o: TAB  &Obter peca
*
*  $ED Descri��o da fun��o
*     Obtem uma peca no tabuleiro gen�rico para jogos.
*
*  $EP Par�metros
*     linhaInicial  - Coordenada horizontal da posicao da peca
*
*     colunaInicial  - Coordenada vertical da posicao da peca
*
*     id  - Identificador e time da peca, passado por referencia.
*
*     tabuleiro  - Ponteiro o tabuleiro que ter� a peca inserida
*
*  $FV Valor retornado
*     TAB_CondRetOK - Se executou corretamente.
*     TAB_CondRetForaTabuleiro - Caso x e y estajam fora dos limites.
*     TAB_CondRetErro - Caso contr�rio.
* 
*
***********************************************************************/

 TAB_tpCondRet TAB_ObterPeca(int linhaInicial, int colunaInicial, char** id,
	TAB_tppTabuleiro tabuleiro);
	
/***********************************************************************
*
*  $FC Fun��o: TAB  &Obter ameacantes
*
*  $ED Descri��o da fun��o
*     Obtem a cabeca da lista de ameacantes.
*
*  $EP Par�metros
*     linhaInicial  - Coordenada horizontal da posicao da peca
*
*     colunaInicial  - Coordenada vertical da posicao  da peca
*
*     lista  - Ponteirto para o cabecalho da lista (retornado por referencia).
*
*     tabuleiro  - Ponteiro o tabuleiro que ter� a peca inserida
*
*  $FV Valor retornado
*     TAB_CondRetOK - Se executou corretamente.
*     TAB_CondRetForaTabuleiro - Caso x e y estajam fora dos limites.
*     TAB_CondRetErro - Caso contr�rio.
* 
*
***********************************************************************/

	TAB_tpCondRet TAB_ObterListaAmeacantes(int linhaInicial, int colunaInicial, LIS_tppLista* lista,
	TAB_tppTabuleiro tabuleiro);
	
/***********************************************************************
*
*  $FC Fun��o: TAB  &Obter ameacados
*
*  $ED Descri��o da fun��o
*     Obtem a cabeca da lista de ameacados.
*
*  $EP Par�metros
*     linhaInicial  - Coordenada horizontal da posicao da peca
*
*     colunaInicial  - Coordenada vertical da posicao  da peca
*
*     lista  - Ponteirto para o cabecalho da lista (retornado por referencia).
*
*     tabuleiro  - Ponteiro o tabuleiro que ter� a peca inserida
*
*
*  $FV Valor retornado
*     TAB_CondRetOK - Se executou corretamente.
*     TAB_CondRetForaTabuleiro - Caso x e y estajam fora dos limites.
*     TAB_CondRetErro - Caso contr�rio.
* 
*
***********************************************************************/

	TAB_tpCondRet TAB_ObterListaAmeacados(int linhaInicial, int colunaInicial, LIS_tppLista* lista,
	TAB_tppTabuleiro tabuleiro);

/***********************************************************************
*
*  $FC Fun��o: TAB  &Destriuir tabuleiro
*
*  $ED Descri��o da fun��o
*     Libera a memoria do tabuleiro e todas as suas pecas.
*
*  $EP Par�metros
*     tabuleiro  - Ponteiro o tabuleiro que ter� a peca inserida
*
*  $FV Valor retornado
*     TAB_CondRetOK - Se executou corretamente.
*     TAB_CondRetErro - Caso contr�rio.
* 
*
***********************************************************************/

	TAB_tpCondRet TAB_DestruirTabuleiro();
	
/********** Fim do m�dulo de defini��o: TAB Tabuleiro de jogo gen�rico. **********/

