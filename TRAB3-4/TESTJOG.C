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

static const char PRINT_POS_CMD         [ ] = "=printpos"     ;

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
*     =printpos             CondRetEsp
*
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {
	  
      int numLidos   = -1 ,
          CondRetEsp = -1,
		  CondRet = -1;

       /* Testar Imprimir Posicoes */
         if  ( strcmp( ComandoTeste , PRINT_POS_CMD) == 0 )
         {

            numLidos = LER_LerParametros( "i" , &CondRetEsp);

            if (numLidos != 1){
               return TST_CondRetParm ;
            }
			
			CondRet = JOG_ImprimirPosicoes();
			
			
            return TST_CompararInt(CondRetEsp, CondRet,
               "Erro ao imprimir as posicoes") ;
         } /* fim ativa: Testar Imprimir Posicoes */
		 
		  /* Testar Inserir peca 
        else if  ( strcmp( ComandoTeste , INSERIR_PECA_CMD) == 0 ){

		
        } /* fim ativa: Testar Inserir peca */
		
      return TST_CondRetNaoConhec ;

   } /* Fim função: TJOG &Testar Jogo */
      

/*****  Código das funções encapsuladas no módulo  *****/
   
   
/********** Fim do módulo de implementação: TJOG Teste Jogo **********/

