#if ! defined( LISTA_ )
#define LISTA_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: LIS  Lista duplamente encadeada
*
*  Arquivo gerado:              LISTA.h
*  Letras identificadoras:      LIS
*
*  Nome da base de software:     OpenJogos
*
*  Projeto: INF 1301 / 1628 Automatiza��o dos testes de m�dulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: ghba, mcs, avs
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*		7 		gbha		14/nov/2016 Conlusao desenvolvimento T3
*     6       mcs   01/out/2016 implementar mudancas do T2, adaptando o m�dulo 
*     5       mcs   13/set/2016 implementar mudancas do T1 (procurar valor na lista)
*     4       avs   01/fev/2006 criar linguagem script simb�lica
*     3       avs   08/dez/2004 uniformiza��o dos exemplos
*     2       avs   07/jul/2003 unifica��o de todos os m�dulos em um s� projeto
*     1       avs   16/abr/2003 in�cio desenvolvimento
*
*  $ED Descri��o do m�dulo
*     Implementa listas gen�ricas duplamente encadeadas.
*     Podem existir n listas em opera��o simultaneamente.
*     As listas possuem uma cabe�a encapsulando o seu estado.
*
*     Cada lista � homog�nea quanto ao tipo dos dados que armazena.
*     Cada elemento da lista referencia o valor que cont�m.
*
*     Os ponteiros para os dados s�o copiados para elementos da lista.
*        N�o � copiado o valor apontado por estes ponteiros.
*
*     O controle da destrui��o do valor de um elemento a ser exclu�do
*        � realizado por uma fun��o fornecida pelo usu�rio.
*
*     Cada lista referencia uma fun��o que determina como devem ser
*        desalocados os dados nela contidos.
*
*     A fun��o de libera��o dos valores contidos nos elementos deve
*        assegurar a libera��o de todos os espa�os refer�nciados pelo
*        valor contido em um elemento.
*        Esta fun��o � chamada antes de se desalocar um elemento
*        de uma lista.
*        Caso n�o seja necess�rio desalocar o valor referenciado pelo
*        elemento, o ponteiro para a fun��o de libera��o poder� ser NULL .
*        Caso o elemento da lista seja a �nica �ncora do valor referenciado,
*        esta fun��o deve promover a destrui��o (free) desse valor e
*        de todos os dados nele ancorados.
*
***************************************************************************/
 
#if defined( LISTA_OWN )
   #define LISTA_EXT
#else
   #define LISTA_EXT extern
#endif

#define LIS_TAM_ID 4
	/* Tamanho do identificador da lista*/

/***** Declara��es exportadas pelo m�dulo *****/

/* Tipo refer�ncia para uma lista */

typedef struct LIS_tagLista * LIS_tppLista ;


/***********************************************************************
*
*  $TC Tipo de dados: LIS Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es da lista
*
***********************************************************************/

   typedef enum {

         LIS_CondRetOK = 0,
               /* Concluiu corretamente */

         LIS_CondRetListaVazia = 2,
               /* A lista n�o cont�m elementos */

         LIS_CondRetErro = 3,
               /* Condi��o de erro encontrada */

         LIS_CondRetFimLista = 4,
               /* Foi atingido o fim de lista */

         LIS_CondRetInicioLista = 5,
               /* Foi atingido o inicio da lista */

         LIS_CondRetFaltouMemoria = 6,
               /* Faltou mem�ria ao tentar criar um elemento de lista */

   } LIS_tpCondRet ;


/***********************************************************************
*
*  $FC Fun��o: LIS  &Criar lista
*
*  $ED Descri��o da fun��o
*     Cria uma lista gen�rica duplamente encadeada.
*     Os poss�veis tipos s�o desconhecidos a priori.
*     A tipagem � implicita.
*     N�o existe identificador de tipo associado � lista.
*
*  $EP Par�metros
*     idLista - string de at� 4 caracteres que identifica a lista
*     ExcluirValor  - ponteiro para a fun��o que processa a
*                     exclus�o do valor referenciado pelo elemento
*                     a ser exclu�do.
*                     Ver descri��o do m�dulo.
*     pLista - ponteiro para a lista
*
*  $FV Valor retornado
*     LIS_CondRetOk - executou corretamente
*     LIS_CondErro  - se ocorreu algum erro, por exemplo falta de mem�ria ou dados errados.
*                     N�o ser� dada mais informa��o quanto ao problema ocorrido.
*
***********************************************************************/

   LIS_tpCondRet LIS_CriarLista( char * idLista, void ( * ExcluirValor ) ( void * pDado )
   , LIS_tppLista* pLista ) ;


/***********************************************************************
*
*  $FC Fun��o: LIS  &Destruir lista
*
*  $ED Descri��o da fun��o
*     Destr�i a lista fornecida.
*     O par�metro ponteiro para a lista n�o � modificado.
*     Se ocorrer algum erro durante a destrui��o, a lista resultar�
*     estruturalmente incorreta.
*     OBS. n�o existe previs�o para poss�veis falhas de execu��o.
*
*  $EP Par�metros
*     pLista - ponteiro para a lista
*
*  $FV Valor retornado
*     LIS_CondRetOK    - destruiu sem problemas
*
***********************************************************************/

   LIS_tpCondRet LIS_DestruirLista( LIS_tppLista pLista ) ;


/***********************************************************************
*
*  $FC Fun��o: LIS  &Inserir elemento
*
*  $ED Descri��o da fun��o
*     Insere novo elemento ap�s o elemento corrente.
*     Caso a lista esteja vazia, insere o primeiro elemento da lista.
*
*  $EP Par�metros
*     Par�metros
*        pLista - ponteiro para a lista onde deve ser inserido o elemento
*        pValor - ponteiro para o valor do novo elemento
*                 Pode ser NULL
*           
*
*  $FV Valor retornado
*     Valor retornado
*        LIS_CondRetOK
*        LIS_CondRetFaltouMemoria
*
***********************************************************************/

   LIS_tpCondRet LIS_InserirElemento( LIS_tppLista pLista ,
                                          void * pValor        );


/***********************************************************************
*
*  $FC Fun��o: LIS  &Excluir elemento
*
*  $ED Descri��o da fun��o
*     Exclui o elemento corrente da lista dada.
*     Se existir o elemento aa esquerda do corrente ser� o novo corrente.
*     Se n�o existir e existir o elemento � direita, este se tornar� corrente.
*     Se este tamb�m n�o existir a lista tornou-se vazia.
*
*  $EP Par�metros
*     pLista    - ponteiro para a lista na qual deve excluir.
*
*  $FV Valor retornado
*     LIS_CondRetOK
*     LIS_CondRetListaVazia
*
***********************************************************************/

   LIS_tpCondRet LIS_ExcluirElemento( LIS_tppLista pLista ) ;


/***********************************************************************
*
*  $FC Fun��o: LIS  &Obter refer�ncia para o valor contido no elemento
*
*  $ED Descri��o da fun��o
*     Obtem a refer�ncia para o valor contido no elemento corrente da lista
*
*  $EP Par�metros
*     pLista - ponteiro para a lista de onde se quer o valor
*	  pValor - ponteiro para armazenar o valor contido no elemento 
*			   corrente da lista
*
*  $FV Valor retornado
*     LIS_CondRetOk 
*     LIS_CondRetListaVazia
*
***********************************************************************/

   LIS_tpCondRet LIS_ObterValor( LIS_tppLista pLista, void ** pValor ) ;


/***********************************************************************
*
*  $FC Fun��o: LIS  &Ir para o pr�ximo elemento da lista
*
*  $ED Descri��o da fun��o
*     Torna corrente o pr�ximo elemento da lista.
*     Faz nada se a lista est� vazia.
*     Faz nada se o elemento corrente � o ultimo da lista.
*
*  $EP Par�metros
*     pLista - ponteiro para a lista a manipular
*
*  $FV Valor retornado
*     LIS_CondRetOk 
*     LIS_CondRetListaVazia
*	  LIS_CondRetFimLista
*
***********************************************************************/

   LIS_tpCondRet LIS_IrProximoLista( LIS_tppLista pLista ) ;


/***********************************************************************
*
*  $FC Fun��o: LIS  &Ir para o elemento anterior da lista
*
*  $ED Descri��o da fun��o
*     Torna corrente o elemento anterior da lista.
*     Faz nada se a lista est� vazia.
*     Faz nada se o elemento corrente � o primeiro da lista.
*
*  $EP Par�metros
*     pLista - ponteiro para a lista a manipular
*
*  $FV Valor retornado
*     LIS_CondRetOk 
*     LIS_CondRetListaVazia
*	  LIS_CondRetInicioLista
*
***********************************************************************/

   LIS_tpCondRet LIS_IrAnteriorLista( LIS_tppLista pLista ) ;


/***********************************************************************
*
*  $FC Fun��o: LIS  &Alterar valor armazenado no elemento corrente
*
*  $ED Descri��o da fun��o
*    Altera o valor armazenado no elemento corrente pelo novo elemento
*    recebido
*
*  $EP Par�metros
*     pLista  - ponteiro para a lista a ser manipulada
*     novoElemento - o novo elemento a ser armazenado
*
*  $FV Valor retornado
*     CondRetOK         - se alterar o valor armazenado
*     CondRetListaVazia - se a lista est� vazia
*
***********************************************************************/

   LIS_tpCondRet LIS_AlterarElementoCorrente( LIS_tppLista pLista ,
                                              void * novoElemento ) ;

/***********************************************************************
*
*  $FC Fun��o: LIS  &Obter identifica��o da lista
*
*  $ED Descri��o da fun��o
*    Obt�m a string identificadora da lista
*
*  $EP Par�metros
*     pLista  - ponteiro para a lista a ser manipulada
*     pDado   - ponteiro para a string a armazenar o id da lista
*
*  $FV Valor retornado
*     CondRetOK         - se encontrar o id da lista
*     CondRetErro 		- se encontrar erro
*
***********************************************************************/

   LIS_tpCondRet LIS_ObterId ( LIS_tppLista pLista ,
                                              char** pDado ) ;


#undef LISTA_EXT

/********** Fim do m�dulo de defini��o: LIS  Lista duplamente encadeada **********/

#else
#endif
