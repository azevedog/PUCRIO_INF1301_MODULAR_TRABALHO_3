/***************************************************************************
*  $MCI M�dulo de implementa��o: TLIS Teste lista de s�mbolos
*
*  Arquivo gerado:              TestLIS.c
*  Letras identificadoras:      TLIS
*
*  Nome da base de software:    Arcabou�o para a automa��o de testes de programas redigidos em C
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\LISTA.BSW
*
*  Projeto: INF 1301 / 1628 Automatiza��o dos testes de m�dulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: avs, mcs, gbha
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
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include    "TST_Espc.h"

#include    "Generico.h"
#include    "LerParm.h"

#include    "Lista.h"


static const char CRIAR_LISTA_CMD         [ ] = "=criarLista"        ;
static const char DESTRUIR_LISTA_CMD      [ ] = "=destroiLista"      ;
static const char OBTER_LISTA_CMD         [ ] = "=obterIdLista"      ;
static const char INS_ELEM_CMD            [ ] = "=inserirNo"         ;
static const char OBTER_VALOR_CMD         [ ] = "=obterNo"           ;
static const char EXC_ELEM_CMD            [ ] = "=excluirNoCorrente" ;
static const char IR_PROX_CMD             [ ] = "=irProx"            ;
static const char IR_ANT_CMD              [ ] = "=irAnt"             ;
static const char ALTERAR_CORR_CMD        [ ] = "=alterarNoCorrente" ;

#define TRUE  1
#define FALSE 0

#define VAZIO     0
#define NAO_VAZIO 1

#define DIM_VT_LISTA   10
#define DIM_VALOR     100

LIS_tppLista   vtListas[ DIM_VT_LISTA ] ;

/***** Prot�tipos das fun��es encapuladas no m�dulo *****/

   static void DestruirValor( void * pValor ) ;

   static int ValidarInxLista( int inxLista , int Modo ) ;

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TLIS &Testar lista
*
*  $ED Descri��o da fun��o
*     Podem ser criadas at� 10 listas, identificadas pelos �ndices 0 a 10
*
*     Comandos dispon�veis:
*
*     =criarlista                   inxLista  idLista  CondRetEsp
*     =obterIdLista                 inxLista  idLista
*     =inserirNo                    inxLista  char     CondRetEsp
*     =obterNo                      inxLista  char     CondRetEsp
*     =excluirNoCorrente            inxLista  CondRetEsp
*     =irProx                       inxLista  CondRetEsp
*     =irAnt                        inxLista  CondRetEsp
*     =alterarNoCorrente            inxLista  char  CondRetEsp
*     =destroiLista                 inxLista  CondRetEsp
*    
*
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

      int inxLista  = -1 ,
          numLidos   = -1 ,
          CondRetEsp = -1  ;

      TST_tpCondRet CondRet ;

      char   StringDado[  DIM_VALOR ] ;
      char * pDado ;

      StringDado[ 0 ] = 0 ;


      /* Testar CriarLista */

         if ( strcmp( ComandoTeste , CRIAR_LISTA_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "isi" ,
                       &inxLista, StringDado, &CondRetEsp ) ;

            if ( ( numLidos != 3 )
              || ( ! ValidarInxLista( inxLista , VAZIO )))
            {
               return TST_CondRetParm ;
            } /* if */
			
			pDado = ( char * ) malloc( strlen( StringDado ) + 1 ) ;
            if ( pDado == NULL )
            {
               return TST_CondRetMemoria ;
            } /* if */
			
			strcpy(pDado , StringDado ) ;

            CondRet = LIS_CriarLista(pDado, DestruirValor, &(vtListas[inxLista]) ) ;

            return TST_CompararInt( CondRetEsp , CondRet ,
               "Erro em ponteiro de nova lista"  ) ;

         } /* fim ativa: Testar CriarLista */

      /* Testar Destruir lista */

         else if ( strcmp( ComandoTeste , DESTRUIR_LISTA_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "ii" ,
                               &inxLista, &CondRetEsp ) ;
            
			if ( numLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */
			
			if ( ! ValidarInxLista( inxLista , NAO_VAZIO ))
			{
				return TST_CompararInt( CondRetEsp , 3 ,
				"Condi��o de retorno errada para lista n�o existente");
			}

            CondRet = LIS_DestruirLista( vtListas[ inxLista ] ) ;
            vtListas[ inxLista ] = NULL ;

            return TST_CompararInt( CondRetEsp , CondRet ,
               "Erro em destruir lista." ) ;

         } /* fim ativa: Testar Destruir lista */

      /* Testar inserir elemento */

         else if ( strcmp( ComandoTeste , INS_ELEM_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "isi" ,
                       &inxLista , StringDado , &CondRetEsp ) ;

            if ( ( numLidos != 3 )
              || ( ! ValidarInxLista( inxLista , NAO_VAZIO )) )
            {
               return TST_CondRetParm ;
            } /* if */

            pDado = ( char * ) malloc( strlen( StringDado ) + 1 ) ;
            if ( pDado == NULL )
            {
               return TST_CondRetMemoria ;
            } /* if */

            strcpy(pDado , StringDado ) ;

            CondRet = LIS_InserirElemento( vtListas[ inxLista ] , pDado ) ;

            if ( CondRet != LIS_CondRetOK )
            {
               free( pDado ) ;
            } /* if */

            return TST_CompararInt( CondRetEsp , CondRet ,
                     "Condicao de retorno errada ao inserir elemento.") ;

         } /* fim ativa: Testar inserir elemento */

      /* Testar excluir elemento */

         else if ( strcmp( ComandoTeste , EXC_ELEM_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "ii" ,
                  &inxLista , &CondRetEsp ) ;

            if ( ( numLidos != 2 )
              || ( ! ValidarInxLista( inxLista , NAO_VAZIO )) )
            {
               return TST_CondRetParm ;
            } /* if */

            return TST_CompararInt( CondRetEsp ,
                      LIS_ExcluirElemento( vtListas[ inxLista ] ) ,
                     "Condi��o de retorno errada ao excluir."   ) ;

         } /* fim ativa: Testar excluir elemento */

      /* Testar obter valor do elemento corrente */

         else if ( strcmp( ComandoTeste , OBTER_VALOR_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "isi" ,
                       &inxLista , StringDado , &CondRetEsp ) ;

            if ( ( numLidos != 3 )
              || ( ! ValidarInxLista( inxLista , NAO_VAZIO )) )
            {
               return TST_CondRetParm ;
            } /* if */
			
			pDado = ( char * ) malloc( strlen( StringDado ) + 1 ) ;
            if ( pDado == NULL )
            {
               return TST_CondRetMemoria ;
            } /* if */

            CondRet = LIS_ObterValor( vtListas[ inxLista ], &pDado );
			
			if ( CondRet == 0 ){
				if ( strcmp(StringDado, pDado) == 0) 
				{
					return TST_CompararInt( CondRetEsp, CondRet,
					"Condi��o de retorno errada ao comparar strings");
				}
			}
			return TST_CompararInt( CondRetEsp , CondRet, 
					"Condi��o de retorno errada ao obter valor");

         } /* fim ativa: Testar obter valor do elemento corrente */

      /* Testar ir para o pr�ximo elemento */

         else if ( strcmp( ComandoTeste , IR_PROX_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "ii" , &inxLista, &CondRetEsp ) ;

            if ( ( numLidos != 2 )
              || ( ! ValidarInxLista( inxLista , NAO_VAZIO )) )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRet = LIS_IrProximoLista( vtListas[ inxLista ] ) ;

            return TST_CompararInt( CondRetEsp , CondRet,
              "Condi��o de retorno errada ao ir para o pr�ximo elemento") ;

         } /* fim ativa: Testar ir para o pr�ximo elemento */

      /* LIS  &Ir para o elemento anterior */

         else if ( strcmp( ComandoTeste , IR_ANT_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "ii" , &inxLista, &CondRetEsp ) ;

            if ( ( numLidos != 2 )
              || ( ! ValidarInxLista( inxLista , NAO_VAZIO )) )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRet = LIS_IrAnteriorLista(vtListas[ inxLista ] ) ;

            return TST_CompararInt( CondRetEsp , CondRet,
              "Condi��o de retorno errada ao ir para o elemento anterior") ;

         } /* fim ativa: LIS  &Ir para o elemento anterior */

      /* LIS  &Alterar valor do elemento corrente*/

         else if ( strcmp( ComandoTeste , ALTERAR_CORR_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "isi" , &inxLista , StringDado ,
                                &CondRetEsp ) ;

            if ( numLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */
			
			if ( ! ValidarInxLista( inxLista , NAO_VAZIO ))
			{
				return TST_CompararInt( CondRetEsp , 3 ,
				"Condi��o de retorno errada para lista n�o existente");
			}

            CondRet = LIS_AlterarElementoCorrente( vtListas[ inxLista ], StringDado);

            return TST_CompararInt( CondRetEsp , CondRet ,
                      "Condicao de retorno errada ao alterar o valor do elemento corrente" ) ;

         } /* fim ativa: LIS  &Alterar valor do elemento corrente */

      /* LIS &Obter Id da Lista */
         else if ( strcmp (ComandoTeste , OBTER_LISTA_CMD) == 0)
         {
            numLidos = LER_LerParametros( "is" , &inxLista, StringDado );

            if ( numLidos != 2
              || ( !ValidarInxLista( inxLista , NAO_VAZIO )))
            {
               return TST_CondRetParm;
            } 

            pDado = ( char * ) malloc( strlen( StringDado ) + 1 ) ;
            if ( pDado == NULL )
            {
               return TST_CondRetMemoria ;
            } /* if */

            CondRet = LIS_ObterId( vtListas[ inxLista ], &pDado );

            if ( pDado == NULL )
            {
               return TST_CompararPonteiroNulo( 1 , pDado ,
                         "Dado tipo um deveria existir." ) ;
            } /* if */

            return TST_CompararString( StringDado , pDado ,
                         "Valor do elemento errado." ) ;
         }
      /* fim ativa: LIS &Obter Id da Lista */

      return TST_CondRetNaoConhec ;

   } /* Fim fun��o: TLIS &Testar lista */


/*****  C�digo das fun��es encapsuladas no m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TLIS -Destruir valor
*
***********************************************************************/

   void DestruirValor( void * pValor )
   {

      free( pValor ) ;

   } /* Fim fun��o: TLIS -Destruir valor */


/***********************************************************************
*
*  $FC Fun��o: TLIS -Validar indice de lista
*
***********************************************************************/

   int ValidarInxLista( int inxLista , int Modo )
   {

      if ( ( inxLista <  0 )
        || ( inxLista >= DIM_VT_LISTA ))
      {
         return FALSE ;
      } /* if */
         
      if ( Modo == VAZIO )
      {
         if ( vtListas[ inxLista ] != 0 )
         {
            return FALSE ;
         } /* if */
      } else
      {
         if ( vtListas[ inxLista ] == 0 )
         {
            return FALSE ;
         } /* if */
      } /* if */
         
      return TRUE ;

   } /* Fim fun��o: TLIS -Validar indice de lista */

/********** Fim do m�dulo de implementa��o: TLIS Teste lista de s�mbolos **********/

