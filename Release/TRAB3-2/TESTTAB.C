/***************************************************************************
*  $MCI Módulo de implementação: TTAB Teste tabuleiro
*
*  Arquivo gerado:              TestTAB.c
*  Letras identificadoras:      TTAB
*
*  Nome da base de software:    OpenJogos
*
*  Projeto: MODULAR_T2
*  Gestor:  EAMCEMP LTDA
*  Autores: MCS e GBHA
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*		4		gbha		14/nov/2016 Conlusao desenvolvimento T3
*	   3       gbha  5/out/2016 Conclusao desenvolvimento T2
*	   2       gbha  4/out/2016 Continuacao desenvolvimento
*     1       mcs   1/out/2016 início desenvolvimento
*
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include    "TST_Espc.h"

#include    "Generico.h"
#include    "LerParm.h"

#include    "TABULEIRO.h"

static const char CRIAR_TAB_CMD         [ ] = "=criartabuleiro"     ;
static const char INSERIR_PECA_CMD         [ ] = "=inserirpeca"     ;
static const char MOVER_PECA_CMD         [ ] = "=moverpeca"     ;
static const char RETIRAR_PECA_CMD         [ ] = "=retirarpeca"     ;
static const char OBTER_PECA_CMD         [ ] = "=obterpeca"     ;
static const char OBTER_CADOS_CMD         [ ] = "=obterameacados"     ;
static const char OBTER_CANTES_CMD         [ ] = "=obterameacantes"     ;
static const char DESTRUIR_TABULEIRO_CMD      [ ] = "=destruirtabuleiro"  ;
  
TAB_tppTabuleiro tab = NULL;
LIS_tppLista pLista = NULL;
		
/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TTAB &Testar tabuleiro
*
*  $ED Descrição da função
*     É criado um tabuleiro LinhaxColuna com duas torres do xadrez que se
*	   ameacam mutuamente
*
*     Comandos disponíveis:
*
*     =criartabuleiro             string int CondRetEsp
*     =inserirpeca                int string string CondRetEsp
*     =moverpeca                  int string int string CondRetEsp
*     =retirarpeca                int string  CondRetEsp
*	  =obterpeca				  int string CondRetEsp
*     =obterameacados             int string  CondRetEsp
*     =obterameacantes            int string  CondretPonteiro
*     =destruirtabuleiro         CondRetEsp
*
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {
   
	  int x;
	  int y;
	  
      int numLidos   = -1 ,
          CondRetEsp = -1,
		  CondRet = -1;

       /* Testar Criar tabuleiro */
         if  ( strcmp( ComandoTeste , CRIAR_TAB_CMD) == 0 )
         {

            numLidos = LER_LerParametros( "iii" , &y, &x,
                       &CondRetEsp ) ;

            if (numLidos != 3){
               return TST_CondRetParm ;
            } /* if */
			
			tab = *((TAB_tppTabuleiro*) malloc(sizeof(TAB_tppTabuleiro)));
			
			CondRet = TAB_CriarTabuleiro(y, x, &tab);
			
            return TST_CompararInt(CondRetEsp, CondRet,
               "Erro ao criar tabuleiro.") ;
         } /* fim ativa: Testar Criar tabuleiro */
		 
		  /* Testar Inserir peca */
        else if  ( strcmp( ComandoTeste , INSERIR_PECA_CMD) == 0 ){

			char corTime;
			char id;
			char fileName [100];
			char* pFilePath;
			char* pathPrefix = ".\\Movimento\\"; 
			
            numLidos = LER_LerParametros( "iisssi", &x, &y, &corTime, &id,
                       &fileName, &CondRetEsp ) ;

            if (numLidos != 6){
               return TST_CondRetParm ;
            } /* if */
		
			pFilePath = (char*) malloc(strlen(pathPrefix)+strlen(fileName)+1);
			strcpy(pFilePath, pathPrefix);
			strcat(pFilePath, fileName);
			
            CondRet = TAB_InserirPeca(x, y, id, corTime, 
			pFilePath, tab);   

            return TST_CompararInt(CondRetEsp, CondRet,
               "Erro ao inserir peca.") ;
        } /* fim ativa: Testar Inserir peca */

/* Testar Mover peca */
        else if  ( strcmp( ComandoTeste , MOVER_PECA_CMD) == 0 ){

			
			int finalY;
			int finalX;
			
            numLidos = LER_LerParametros( "iiiii" , &x, &y, &finalX, &finalY,
                       &CondRetEsp) ;

            if (numLidos != 5){
               return TST_CondRetParm ;
            } /* if */

			CondRet = TAB_MoverPeca(x, y, finalX, finalY, tab);

            return TST_CompararInt(CondRetEsp, CondRet,
               "Erro ao mover peca.") ;
        } /* fim ativa: Testar Mover Peca */
		
		/* Testar Retirar peca */
        else if  ( strcmp( ComandoTeste , RETIRAR_PECA_CMD) == 0 ){

            numLidos = LER_LerParametros( "iii" , &x, &y,
                       &CondRetEsp ) ;

            if (numLidos != 3){
               return TST_CondRetParm ;
            } /* if */

			CondRet = TAB_RetirarPeca(x , y, tab);

            return TST_CompararInt(CondRetEsp, CondRet,
               "Erro ao retirar peca.") ;
        } /* fim ativa: Testar Retirar peca */
		
		/* Testar Obter peca */
        else if  ( strcmp(ComandoTeste , OBTER_PECA_CMD) == 0 ){
			
			char* id;

            numLidos = LER_LerParametros( "iii" , &x, &y,
                       &CondRetEsp ) ;

            if (numLidos != 3){
               return TST_CondRetParm ;
            } /* if */
			
			id = (char*) malloc(sizeof(char)*4);
			CondRet = TAB_ObterPeca(x, y, &id, tab); 
			
            if(CondRet == TAB_CondRetOK){
				if(strlen(id) == 0){
					CondRet = TAB_CondRetErro;
				}
				else{
					CondRet = TAB_CondRetOK;
				}
			}
			
			free(id);
            return TST_CompararInt(CondRetEsp, CondRet,
               "Erro ao obter peca.") ;
        } /* fim ativa: Testar Obeter peca */
		
		/* Testar Obter ameacados */
        else if  ( strcmp( ComandoTeste , OBTER_CADOS_CMD) == 0 ){

            numLidos = LER_LerParametros( "iii" , &x, &y,
                       &CondRetEsp ) ;

            if (numLidos != 3){
               return TST_CondRetParm ;
            } /* if */

			pLista = *((LIS_tppLista*) malloc(sizeof(LIS_tppLista)));
			CondRet = TAB_ObterListaAmeacados(x, y, &pLista, tab);
			
			if( CondRet == TAB_CondRetOK){
				if(pLista == NULL){
					CondRet = TAB_CondRetErro;
				}
				else{
					CondRet = TAB_CondRetOK;
				}
			}

            return TST_CompararInt(CondRetEsp, CondRet,
               "Erro ao obter ameacados peca.") ;
        } /* fim ativa: Testar Obeter ameacados. */
		
		/* Testar Obter ameacantes */
        else if  ( strcmp( ComandoTeste , OBTER_CANTES_CMD) == 0 ){

            numLidos = LER_LerParametros( "iii" , &x, &y,
                       &CondRetEsp ) ;

            if (numLidos != 3){
               return TST_CondRetParm ;
            } /* if */

            pLista = *((LIS_tppLista*) malloc(sizeof(LIS_tppLista)));
			CondRet = TAB_ObterListaAmeacantes(x, y, &pLista, tab);
			
			if( CondRet == TAB_CondRetOK){
				if(pLista == NULL){
					CondRet = TAB_CondRetErro;
				}
				else{
					CondRet = TAB_CondRetOK;
				}
			}

            return TST_CompararInt(CondRetEsp, CondRet,
               "Erro ao obter ameacantes.") ;
        } /* fim ativa: Testar Obter ameacados */
		
		
		/* Testar Destruir tabuleiro */
        else if  (strcmp( ComandoTeste , DESTRUIR_TABULEIRO_CMD) == 0 ){

            numLidos = LER_LerParametros( "i" , &CondRetEsp ) ;

            if (numLidos != 1){
               return TST_CondRetParm ;
            } /* if */

			CondRet = TAB_DestruirTabuleiro(tab);
			
            return TST_CompararInt(CondRetEsp, CondRet,
			"Erro ao destruir tabuleiro.") ;
        } /* fim ativa: Testar Destruir tabuleiro. */
		
      return TST_CondRetNaoConhec ;

   } /* Fim função: TTAB &Testar Tabuleiro */
   
   
/********** Fim do módulo de implementação: TTAB Teste Tabuleiro **********/

