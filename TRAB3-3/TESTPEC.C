/***************************************************************************
*  $MCI Módulo de implementação: TPEC Peca de um jogo de 
*	tabuleiro
*
*  Arquivo gerado:              TESTPEC.c
*  Letras identificadoras:      TPEC
*
*  Nome da base de software:    OpenJogos
*
*  Projeto: MODULAR_T2
*  Gestor:  EAMCEMP LTDA
*  Autores: MCS e GBHA
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*		3 		gbha		14/nov/2016 Conlusao desenvolvimento T3
*     2       gbha   3/out/2016 Fim desenvolvimento
*	  1       gbha   1/out/2016 Início desenvolvimento
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include    "TST_Espc.h"
#include    "Generico.h"
#include    "LerParm.h"
#include    "PECA.h"


static const char CRIAR_PECA_CMD        [ ] = "=criarpeca"    ;
static const char DEF_COR_PECA_CMD      [ ] = "=corpeca"  ;
static const char LIBERAR_PECA_CMD      [ ] = "=liberarpeca"  ;
static const char MOVER_PECA_CMD      	[ ] = "=moverpeca"    ;
static const char COMPARAR_PECA_CMD		[ ] = "=compararpeca" ;

#define DIM_VT_PECA   10
#define TRUE  1
#define FALSE 0

PEC_tppPeca vtPecas[ DIM_VT_PECA];

/***** Protótipos das funções encapuladas no módulo *****/

   static int ValidarInxPeca( int inxPeca ) ;
	/*Valida a posicao no vetor interno */

/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TPEC &Testar Peca
*
*  $ED Descrição da função
*     Podem ser criadas até 10 pecas, identificadas pelos índices 0 a 10
*
*     Comandos disponíveis:
*
*     =criarpeca                 inxPec string string CondRetEsp
*     =liberarpeca               inxLista CondRetEsp
*     =moverpeca               inxLista int int int int CondRetEsp
*	  =comparapeca				 inxPec inxPec CondRetEsp
*
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste ){

      int inxPeca    = -1 ,
          numLidos   = -1 ,
          CondRetEsp = -1 
		;
		
      TST_tpCondRet CondRet ;
	  
      char   tipoPeca;
	  char   corPeca;
		
      /* Testar criar peca */
		if ( strcmp( ComandoTeste , CRIAR_PECA_CMD ) == 0 )
         {
			char fileName [100];
			char* pFilePath;
			char* pathPrefix = ".\\Movimento\\"; 
			
            numLidos = LER_LerParametros( "isssi" ,
                       &inxPeca, &tipoPeca,&corPeca, &fileName, &CondRetEsp) ;

            if ( ( numLidos != 5 )
              || ( !ValidarInxPeca( inxPeca )))
            {
               return TST_CondRetParm ;
            } /* if */
			
			pFilePath = (char*) malloc(strlen(pathPrefix)+strlen(fileName)+1);
			strcpy(pFilePath, pathPrefix);
			strcat(pFilePath, fileName);
			  
            CondRet =
                 PEC_CriarPeca(&(vtPecas[inxPeca]), tipoPeca, corPeca, pFilePath) ;
				 
            return TST_CompararInt(CondRetEsp, CondRet,
               "Erro ao criar peca.") ;

        } /* fim ativa: Testar CriarPeca */

      /* Testar Esvaziar Liberar Peca */
        else if ( strcmp(ComandoTeste, LIBERAR_PECA_CMD) == 0 ){

            numLidos = LER_LerParametros("ii",
                               &inxPeca, &CondRetEsp) ;

            if ( ( numLidos != 2 )
              || ( !ValidarInxPeca(inxPeca)))
            {
               return TST_CondRetParm ;
            } /* if */

            CondRet = PEC_LiberarPeca( vtPecas[inxPeca] ) ;
			
			return TST_CompararInt( CondRetEsp ,CondRet ,
               "Erro ao liberar peca.") ;

        } /* fim ativa: Testar Liberar Peca */

      /* Testar Mover Peca */
        else if (strcmp( ComandoTeste , MOVER_PECA_CMD ) == 0 ){
			
			int iniX,
				iniY,
				fimX,
				fimY
			;
			
            numLidos = LER_LerParametros( "iiiiii" ,
                               &inxPeca, &iniX, &iniY, &fimX, &fimY, &CondRetEsp) ;

            if ( ( numLidos != 6 )
              || ( ! ValidarInxPeca(inxPeca)))
            {
               return TST_CondRetParm ;
            } /* if */

            CondRet = PEC_Mover(vtPecas[inxPeca], iniX, iniY, fimX, fimY);

            return TST_CompararInt( CondRetEsp ,CondRet ,
               "Erro ao mover a peca.") ;
        } /* fim ativa: Testar Mover Peca */
		else if (strcmp( ComandoTeste, COMPARAR_PECA_CMD) == 0){
			
			int inxPecaCompara;
			numLidos = LER_LerParametros("iii", &inxPeca, &inxPecaCompara, &CondRetEsp);
			
			if ( ( numLidos != 3 )
				|| ( ! ValidarInxPeca(inxPeca) )
				|| ( ! ValidarInxPeca(inxPecaCompara) ) ) {
					return TST_CondRetParm;
				}
			
			CondRet = PEC_ComparaPeca(vtPecas[inxPeca], vtPecas[inxPecaCompara]) ;

            return TST_CompararInt( CondRetEsp ,CondRet ,
               "Erro ao comparar a peca.") ;
			
		} /* fim ativa: Testar Compara Peca */

      return TST_CondRetNaoConhec ;
	}/* Fim função: TPEC &Testar Pecas */
/*****  Código das funções encapsuladas no módulo  *****/


/***********************************************************************
*
*  $FC Função: TPEC -Validar indice de peca
*
***********************************************************************/

   int ValidarInxPeca( int inxPeca)
   {

      if ( ( inxPeca <  0 )
        || ( inxPeca >= DIM_VT_PECA))
      {
         return FALSE ;
      } /* if */
      return TRUE ;

   } /* Fim função: TLIS -Validar indice de peca */

/********** Fim do módulo de implementação: TPEC Teste peca para um jogo e tabuleiro **********/

