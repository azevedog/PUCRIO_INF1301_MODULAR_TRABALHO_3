/***************************************************************************
*  $MCI Módulo de implementação: TJOG Teste Jogo
*
*  Arquivo gerado:              TestJOG.c
*  Letras identificadoras:      TJOG
*
*  Nome da base de software:    OpenJogos
*
*  Projeto: MODULAR_T2
*  Gestor:  EAMCEMP LTDA
*  Autores: MCS e GBHA
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*		2		gbha		16/nov/2016 Conclusao desenvolvimento
*		1		gbha		15/nov/2016 Inicio desenvolvimento
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>
#include    "TST_Espc.h"
#include    "Generico.h"
#include    "LerParm.h"
#include    "JOGO.h"

static const char INIT_JOG_CMD         [ ] = "=initjogo"     ;
static const char PRINT_POS_CMD         [ ] = "=printpos"     ;
static const char MOV_PEC_CMD         [ ] = "=movpec"     ;

/***** Protótipos das funções encapuladas no módulo *****/
		

/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TJOG &Testar tabuleiro
*
*  $ED Descrição da função
*     É criado um jogo de xadrez com algumas pecas para simulacao de situacoes de 
*	   jogo.
*	   
*     Comandos disponíveis:
*
*     =initjogo             CondRetEsp
*     =printpos             CondRetEsp
*     =movpec             string int string int CondRetEsp
*
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {
	  
      int numLidos   = -1 ,
          condRetEsp = -1,
		  condRet = -1;

		  /* Testar Iniciar um jogo */
		  if  ( strcmp( ComandoTeste , INIT_JOG_CMD) == 0 )
         {

            numLidos = LER_LerParametros( "i" , &condRetEsp);

            if (numLidos != 1){
               return TST_CondRetParm ;
            }
			
			condRet = JOG_IniciaJogo();
			return TST_CompararInt(condRetEsp, condRet,
               "Erro ao iniciar o jogo") ;
		} /* fim ativa: Testar Iniciar um jogo */
		  
       /* Testar Imprimir Posicoes */
         else if  ( strcmp( ComandoTeste , PRINT_POS_CMD) == 0 )
         {

            numLidos = LER_LerParametros( "i" , &condRetEsp);

            if (numLidos != 1){
               return TST_CondRetParm ;
            }
			
			condRet = JOG_ImprimirPosicoes();
			
            return TST_CompararInt(condRetEsp, condRet,
               "Erro ao imprimir as posicoes") ;
         } /* fim ativa: Testar Imprimir Posicoes */
		 
		  /* Testar Mover peca */
        else if  ( strcmp( ComandoTeste , MOV_PEC_CMD) == 0 ){
			
			char colInicial2;
			char colFinal;
			int linInicial, linFinal;
			
			numLidos = LER_LerParametros( "sisii" , &colInicial2, &linInicial, &colFinal, &linFinal, &condRetEsp);
				
            if (numLidos != 5){
               return TST_CondRetParm ;
            }
			
			condRet = JOG_MoverPeca(colInicial2, linInicial, colFinal, linFinal);
			
			return TST_CompararInt(condRetEsp, condRet,
               "Erro ao imprimir as posicoes") ;
		
        } /* fim ativa: Testar Mover peca */
		
      return TST_CondRetNaoConhec ;

   } /* Fim função: TJOG &Testar Jogo */
      

/*****  Código das funções encapsuladas no módulo  *****/
   
   
/********** Fim do módulo de implementação: TJOG Teste Jogo **********/

