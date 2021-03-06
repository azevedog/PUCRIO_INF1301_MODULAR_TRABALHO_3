/***************************************************************************
*  $MCI M�dulo de implementa��o: LIS  Lista duplamente encadeada
*
*  Arquivo gerado:              LISTA.c
*  Letras identificadoras:      LIS
*
*  Nome da base de software:  OpenJogos
*
*  Projeto: INF 1301 / 1628 Automatiza��o dos testes de m�dulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: mcs, gbha, avs
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*		7		gbha		14/nov/2016 Conlusao desenvolvimento T3
*     6       mcs   01/out/2016 implementar mudancas do T2, adaptando o m�dulo 
*     5       mcs   13/set/2016 implementar mudancas do T1 (procurar valor na lista)
*     4       avs   01/fev/2006 criar linguagem script simb�lica
*     3       avs   08/dez/2004 uniformiza��o dos exemplos
*     2       avs   07/jul/2003 unifica��o de todos os m�dulos em um s� projeto
*     1       avs   16/abr/2003 in�cio desenvolvimento
*
***************************************************************************/

#include   <stdio.h>
#include   <string.h>
#include   <memory.h>
#include   <malloc.h>
#include   <assert.h>

#define LISTA_OWN
#include "LISTA.h"
#undef LISTA_OWN

/***********************************************************************
*
*  $TC Tipo de dados: LIS Elemento da lista
*
*
***********************************************************************/

   typedef struct tagElemLista {

         void * pValor ;
               /* Ponteiro para o valor contido no elemento */

         struct tagElemLista * pAnt ;
               /* Ponteiro para o elemento predecessor */

         struct tagElemLista * pProx ;
               /* Ponteiro para o elemento sucessor */

   } tpElemLista ;

/***********************************************************************
*
*  $TC Tipo de dados: LIS Descritor da cabe�a de lista
*
*
***********************************************************************/

   typedef struct LIS_tagLista {

         char * idLista;
               /* String identificadora de lista */

         tpElemLista * pOrigemLista ;
               /* Ponteiro para a origem da lista */

         tpElemLista * pFimLista ;
               /* Ponteiro para o final da lista */

         tpElemLista * pElemCorr ;
               /* Ponteiro para o elemento corrente da lista */

         int numElem ;
               /* N�mero de elementos da lista */

         void ( * ExcluirValor ) ( void * pValor ) ;
               /* Ponteiro para a fun��o de destrui��o do valor contido em um elemento */

   } LIS_tpLista ;

/***** Prot�tipos das fun��es encapuladas no m�dulo *****/

   static void LiberarElemento( LIS_tppLista   pLista ,
                                tpElemLista  * pElem   ) ;

   static tpElemLista * CriarElemento( LIS_tppLista pLista ,
                                       void *       pValor  ) ;

   static void LimparCabeca( LIS_tppLista pLista ) ;

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

/***************************************************************************
*
*  Fun��o: LIS  &Criar lista
*  ****/

   LIS_tpCondRet LIS_CriarLista( char * idLista, void ( * ExcluirValor ) ( void * pDado ),
   LIS_tppLista* pLista ){

      char * identificaLista;
      int contarChar = strlen(idLista);

      if ( contarChar > 4 || contarChar < 0)
      {
         return LIS_CondRetErro;
      } /* if */

      (*pLista) = ( LIS_tpLista * ) malloc( sizeof( LIS_tpLista )) ;
      if ( (*pLista) == NULL )
      {
         return LIS_CondRetErro ;
      } /* if */

      LimparCabeca( (*pLista) );
      (*pLista)->ExcluirValor = ExcluirValor;

      identificaLista = ( char * ) malloc( contarChar + 1) ;

      if( identificaLista == NULL){
         return LIS_CondRetErro;
      }

      strcpy( identificaLista , idLista ) ;

      (*pLista)->idLista = identificaLista ;

      return LIS_CondRetOK;

   } /* Fim fun��o: LIS  &Criar lista */

/***************************************************************************
*
*  Fun��o: LIS  &Destruir lista
*  ****/

   LIS_tpCondRet LIS_DestruirLista( LIS_tppLista pLista )
   {

      #ifdef _DEBUG
         assert( pLista != NULL ) ;
      #endif

      tpElemLista * pElem ;
      tpElemLista * pProx ;

      pElem = pLista->pOrigemLista ;

      while ( pElem != NULL )
      {
         pProx = pElem->pProx ;
         LiberarElemento( pLista , pElem ) ;
         pElem = pProx ;
      } /* while */

      LimparCabeca( pLista ) ;
      free( pLista ) ;

      return LIS_CondRetOK;

   } /* Fim fun��o: LIS  &Destruir lista */



/***************************************************************************
*
*  Fun��o: LIS  &Inserir elemento 
*  ****/

   LIS_tpCondRet LIS_InserirElemento( LIS_tppLista pLista ,
                                          void * pValor        )
      
   {

      tpElemLista * pElem ;

      #ifdef _DEBUG
         assert( pLista != NULL ) ;
      #endif

      /* Criar elemento a inserir */

         pElem = CriarElemento( pLista , pValor ) ;
         if ( pElem == NULL )
         {
            return LIS_CondRetFaltouMemoria ;
         } /* if */

      /* Encadear o elemento ap�s o elemento */

         if ( pLista->pElemCorr == NULL )
         {
            pLista->pOrigemLista = pElem ;
            pLista->pFimLista = pElem ;
         } else
         {
            if ( pLista->pElemCorr->pProx != NULL )
            {
               pElem->pProx  = pLista->pElemCorr->pProx ;
               pLista->pElemCorr->pProx->pAnt = pElem ;
            } else
            {
               pLista->pFimLista = pElem ;
            } /* if */

            pElem->pAnt = pLista->pElemCorr ;
            pLista->pElemCorr->pProx = pElem ;

         } /* if */
                  
         pLista->pElemCorr = pElem ;
                  
         return LIS_CondRetOK ;

   } /* Fim fun��o: LIS  &Inserir elemento */

/***************************************************************************
*
*  Fun��o: LIS  &Excluir elemento
*  ****/

   LIS_tpCondRet LIS_ExcluirElemento( LIS_tppLista pLista )
   {

      tpElemLista * pElem ;

      #ifdef _DEBUG
         assert( pLista  != NULL ) ;
      #endif

      if ( pLista->pElemCorr == NULL )
      {
         return LIS_CondRetListaVazia ;
      } /* if */

      pElem = pLista->pElemCorr ;

      /* Desencadeia � esquerda */

         if ( pElem->pAnt != NULL )
         {
            pElem->pAnt->pProx   = pElem->pProx ;
            pLista->pElemCorr    = pElem->pAnt ;
         } else {
            pLista->pElemCorr    = pElem->pProx ;
            pLista->pOrigemLista = pLista->pElemCorr ;
         } /* if */

      /* Desencadeia � direita */

         if ( pElem->pProx != NULL )
         {
            pElem->pProx->pAnt = pElem->pAnt ;
         } else
         {
            pLista->pFimLista = pElem->pAnt ;
         } /* if */

      LiberarElemento( pLista , pElem ) ;

      return LIS_CondRetOK ;

   } /* Fim fun��o: LIS  &Excluir elemento */

/***************************************************************************
*
*  Fun��o: LIS  &Obter refer�ncia para o valor contido no elemento
*  ****/

   LIS_tpCondRet LIS_ObterValor( LIS_tppLista pLista, void ** pValor)
   {

      #ifdef _DEBUG
         assert( pLista != NULL ) ;
      #endif

      if ( pLista->pElemCorr == NULL )
      {
        return LIS_CondRetListaVazia ;
      } /* if */

	  
	  (*pValor) = pLista->pElemCorr->pValor;

         if ((*pValor) == NULL)
         {
            return LIS_CondRetErro;
         }

      return LIS_CondRetOK;

   } /* Fim fun��o: LIS  &Obter refer�ncia para o valor contido no elemento */

/***************************************************************************
*
*  Fun��o: LIS  &Ir para o pr�ximo elemento 
*  ****/

   LIS_tpCondRet LIS_IrProximoLista ( LIS_tppLista pLista )
   {

      #ifdef _DEBUG
         assert( pLista != NULL ) ;
      #endif

      if ( pLista->pElemCorr == NULL){
         return LIS_CondRetListaVazia ;
       }
	  
	  if( pLista->pElemCorr == pLista->pFimLista ){
         return LIS_CondRetFimLista ;
      } /* if */

      pLista->pElemCorr = pLista->pElemCorr->pProx ;

      return LIS_CondRetOK ;

   } /* Fim fun��o: LIS  &Ir para o pr�ximo elemento */

/***************************************************************************
*
*  Fun��o: LIS  &Ir para o elemento anterior
*  ****/

   LIS_tpCondRet LIS_IrAnteriorLista( LIS_tppLista pLista )
   {

      #ifdef _DEBUG
         assert(pLista != NULL ) ;
      #endif

      if (pLista->pElemCorr == NULL){
         return LIS_CondRetListaVazia ;
      }

	  if( pLista->pOrigemLista == pLista->pElemCorr ){
         return LIS_CondRetInicioLista ;
      } /* if */
	  
      pLista->pElemCorr = pLista->pElemCorr->pAnt ;

      return LIS_CondRetOK ;
   } /* Fim fun��o: LIS  &Ir para o elemento anterior */

/***************************************************************************
*
*  Fun��o: LIS  &Alterar valor do elemento corrente
*  ****/

  LIS_tpCondRet LIS_AlterarElementoCorrente( LIS_tppLista pLista ,
                                              void * novoElemento )
   {

      #ifdef _DEBUG
         assert( pLista != NULL ) ;
      #endif

      /* Tratar lista vazia */

         if ( pLista->pElemCorr == NULL )
         {
            return LIS_CondRetListaVazia ;
         } /* fim ativa: Tratar lista vazia */

         pLista->pElemCorr->pValor = novoElemento;

         return LIS_CondRetOK ;

   } /* Fim fun��o: LIS  &Alterar valor do elemento corrente */

/***************************************************************************
*
*  Fun��o: LIS  &Obter identifica��o da lista
*  ****/

   LIS_tpCondRet LIS_ObterId ( LIS_tppLista pLista , char** pDado)
   {

      #ifdef _DEBUG
         assert( pLista != NULL ) ;
      #endif

      /* Tratar lista vazia */

         if ( pLista->idLista == NULL )
         {
            return LIS_CondRetErro ;
         } /* fim ativa: Tratar lista vazia */

         (*pDado) = pLista->idLista;

         if ((*pDado) == NULL)
         {
            return LIS_CondRetErro;
         }

         return LIS_CondRetOK ;

   } /* Fim fun��o: LIS &Obter identifica��o da lista*/




/*****  C�digo das fun��es encapsuladas no m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: LIS  -Liberar elemento da lista
*
*  $ED Descri��o da fun��o
*     Elimina os espa�os apontados pelo valor do elemento e o
*     pr�prio elemento.
*
***********************************************************************/

   void LiberarElemento( LIS_tppLista   pLista ,
                         tpElemLista  * pElem   )
   {

      if ( ( pLista->ExcluirValor != NULL )
        && ( pElem->pValor != NULL        ))
      {
         pLista->ExcluirValor( pElem->pValor ) ;
      } /* if */

      free( pElem ) ;

      pLista->numElem-- ;

   } /* Fim fun��o: LIS  -Liberar elemento da lista */


/***********************************************************************
*
*  $FC Fun��o: LIS  -Criar o elemento
*
***********************************************************************/

   tpElemLista * CriarElemento( LIS_tppLista pLista ,
                                void *       pValor  )
   {

      tpElemLista * pElem ;

      pElem = ( tpElemLista * ) malloc( sizeof( tpElemLista )) ;
      if ( pElem == NULL )
      {
         return NULL ;
      } /* if */

      pElem->pValor = pValor ;
      pElem->pAnt   = NULL  ;
      pElem->pProx  = NULL  ;

      pLista->numElem ++ ;

      return pElem ;

   } /* Fim fun��o: LIS  -Criar o elemento */


/***********************************************************************
*
*  $FC Fun��o: LIS  -Limpar a cabe�a da lista
*
***********************************************************************/

   void LimparCabeca( LIS_tppLista pLista )
   {

      pLista->pOrigemLista = NULL ;
      pLista->pFimLista = NULL ;
      pLista->pElemCorr = NULL ;
      pLista->numElem   = 0 ;

   } /* Fim fun��o: LIS  -Limpar a cabe�a da lista */

/********** Fim do m�dulo de implementa��o: LIS  Lista duplamente encadeada **********/

