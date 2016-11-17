/***************************************************************************
*  $MCI Módulo de implementação: JOG  Jogo generico 
*
*  Arquivo gerado:              JOGO.c
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
*      1       gbha   5/NOV/2016 início desenvolvimento
*
*
***************************************************************************/

#include   <stdio.h>
#include   <string.h>
#include   <memory.h>
#include   <malloc.h>
#include   <assert.h>
#include	"TABULEIRO.h"
#include	"JOGO.h"

#define LINHAS 8
#define COLUNAS 8

static TAB_tppTabuleiro tabuleiro;
static int colunaRB = 3;
static int linhaRB = 7;
static int colunaRP = 3;
static int linhaRP = 0;

/***********************************************************************
*
*  $TC Tipo de dados: JOG Descritor do Jogo
*
*
***********************************************************************/
/*
   typedef struct JOG_tagJogo {
   
				/* Numero  */
	/*		   
   } JOG_tpJogo ;

/***** Protótipos das funções encapuladas no módulo *****/
	
	static int converterColuna(char coluna);
		/* Converte de letra para numero.*/
	
	static int converterLinha(int linha);
		/* Converte para zero based.*/	
		
	static void atualizaPosicaoReis(int colunaInicial, int linhaInicial,
	int colunaFinal, int linhaFinal);
		/* Atualiza linha e coluna de cada rei.*/
	
	static JOG_tpCondRet JOG_ValidarReiInternal(int linhaIni, int colunaIni, char* label);
		/* Avalia situacao de ameaca do rei.*/

/*****  Código das funções exportadas pelo módulo  *****/

/***********************************************************************
*
*  $FC Função: JOG  -IniciaJogo
*
***********************************************************************/
JOG_tpCondRet JOG_IniciaJogo(){
	
		//int condRet;
   
		tabuleiro = *((TAB_tppTabuleiro*) malloc(sizeof(TAB_tppTabuleiro)));
		if(tabuleiro == NULL) return JOG_CondRetErro;
		if(TAB_CriarTabuleiro(COLUNAS, LINHAS, &tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		
		
		if(TAB_InserirPeca(0, 0,  'T', 'P', ".\\Movimento\\Torre.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		if(TAB_InserirPeca(0, 2,  'B', 'P', ".\\Movimento\\Bispo.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		if(TAB_InserirPeca(linhaRP, colunaRP,  'R', 'P', ".\\Movimento\\Rei.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		if(TAB_InserirPeca(0, 5,  'B', 'P', ".\\Movimento\\Bispo.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		if(TAB_InserirPeca(0, 7,  'T', 'P', ".\\Movimento\\Torre.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		
		if(TAB_InserirPeca(1, 0,  'P', 'P', ".\\Movimento\\Peao.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		if(TAB_InserirPeca(1, 1,  'P', 'P', ".\\Movimento\\Peao.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		if(TAB_InserirPeca(1, 2,  'P', 'P', ".\\Movimento\\Peao.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		if(TAB_InserirPeca(1, 3,  'P', 'P', ".\\Movimento\\Peao.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		if(TAB_InserirPeca(1, 4,  'P', 'P', ".\\Movimento\\Peao.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		if(TAB_InserirPeca(1, 5,  'P', 'P', ".\\Movimento\\Peao.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		if(TAB_InserirPeca(1, 6,  'P', 'P', ".\\Movimento\\Peao.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		if(TAB_InserirPeca(1, 7,  'P', 'P', ".\\Movimento\\Peao.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		
		
		if(TAB_InserirPeca(6, 0,  'P', 'B', ".\\Movimento\\Peao.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		if(TAB_InserirPeca(6, 1,  'P', 'B', ".\\Movimento\\Peao.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		if(TAB_InserirPeca(6, 2,  'P', 'B', ".\\Movimento\\Peao.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		if(TAB_InserirPeca(6, 3,  'P', 'B', ".\\Movimento\\Peao.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		if(TAB_InserirPeca(6, 4,  'P', 'B', ".\\Movimento\\Peao.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		if(TAB_InserirPeca(6, 5,  'P', 'B', ".\\Movimento\\Peao.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		if(TAB_InserirPeca(6, 6,  'P', 'B', ".\\Movimento\\Peao.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		if(TAB_InserirPeca(6, 7,  'P', 'B', ".\\Movimento\\Peao.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		
		if(TAB_InserirPeca(7, 0,  'T', 'B', ".\\Movimento\\Torre.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		if(TAB_InserirPeca(7, 2,  'B', 'B', ".\\Movimento\\Bispo.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		if(TAB_InserirPeca(linhaRB, colunaRB,  'R', 'B', ".\\Movimento\\Rei.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		if(TAB_InserirPeca(7, 5,  'B', 'B', ".\\Movimento\\Bispo.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		if(TAB_InserirPeca(7, 7,  'T', 'B', ".\\Movimento\\Torre.exe", tabuleiro) != TAB_CondRetOK) return JOG_CondRetErro;
		
		return JOG_CondRetOK;

}/*Fim função: JOG  - IniciaJogo*/

/***********************************************************************
*
*  $FC Função: JOG  -MoverPeca
*
***********************************************************************/
	JOG_tpCondRet JOG_MoverPeca(char colunaInicial, int linhaInicial,
	char colunaFinal, int linhaFinal){
		   int linInicial, colInicial, linFinal, colFinal, condRet;
		   
			linInicial = converterLinha(linhaInicial);
			colInicial = converterColuna(colunaInicial);
			
			linFinal = converterLinha(linhaFinal);
			colFinal = converterColuna(colunaFinal);
			
			
		   
		   condRet = TAB_MoverPeca(linInicial, colInicial, linFinal, colFinal, tabuleiro);
			
			switch(condRet){
				case TAB_CondRetForaTabuleiro:
					return JOG_CondRetMovimentoIlegal;
				break;
              
				case TAB_CondRetElementoNaoFaz:
					return JOG_CondRetMovimentoIlegal;
				break;
				
				case TAB_CondRetSubstituiuOutroElemento:
					return JOG_CondRetEliminouPecaAdversario;
				break;
				
				case TAB_CondRetElementoMesmoTime:
					return JOG_CondRetMovimentoIlegal;
				break;
				
				case TAB_CondRetPosicaoVazia:
					return JOG_CondRetErro;
				break;
			  }
			  
			
		atualizaPosicaoReis(linInicial, colInicial, colFinal, linFinal);			
		return JOG_CondRetOK;
	}/* Fim função: JOG  -MoverPeca*/
	
/***********************************************************************
*
*  $FC Função: JOG  -ValidarAmeacantes
*
***********************************************************************/	
	JOG_tpCondRet JOG_ValidarAmeacantes(char colunaInicial, int linhaInicial){
		int linInicial, colInicial, condRet;
		LIS_tppLista pLista;
		char* tempString = (char*) malloc(sizeof(char)*4);
		
		linInicial = converterLinha(linhaInicial);
		colInicial = converterColuna(colunaInicial);
		
		pLista = *((LIS_tppLista*) malloc(sizeof(LIS_tppLista)));
	
		condRet = TAB_ObterListaAmeacantes(linInicial, colInicial, &pLista, tabuleiro);
		switch(condRet){
			case TAB_CondRetForaTabuleiro:
				return JOG_CondRetMovimentoIlegal;
			break;
             
			case TAB_CondRetPosicaoVazia:
				return JOG_CondRetMovimentoIlegal;
			break;
				
			case TAB_CondRetErro:
				return JOG_CondRetErro;
			break;
		}
		
		printf("\nAmeacantes de %c%d:", colunaInicial, linhaInicial);
		condRet = -1;
		do{
			condRet = LIS_IrAnteriorLista(pLista);
			if(condRet == LIS_CondRetListaVazia){
				printf("\n(VAZIO)");
				return JOG_CondRetErro;
			}
		}while(condRet!=LIS_CondRetInicioLista);
		
		do{
			if(LIS_ObterValor(pLista, &tempString)) return JOG_CondRetErro;
			printf("\n%s", tempString);
			condRet = LIS_IrProximoLista(pLista);
			if(condRet == LIS_CondRetErro) return JOG_CondRetErro;
		}while(condRet!=LIS_CondRetFimLista);

		free(tempString);
		LIS_DestruirLista(pLista);		
		return JOG_CondRetOK;
	
	}/* Fim função: JOG  -ValidarAmeacantes*/

	
/***********************************************************************
*
*  $FC Função: JOG  -ValidarAmeacados
*
***********************************************************************/	
	JOG_tpCondRet JOG_ValidarAmeacados(char colunaInicial, int linhaInicial){
		int linInicial, colInicial, condRet;
		LIS_tppLista pLista;
		char* tempString = (char*) malloc(sizeof(char)*4);
		
		linInicial = converterLinha(linhaInicial);
		colInicial = converterColuna(colunaInicial);
		
		pLista = *((LIS_tppLista*) malloc(sizeof(LIS_tppLista)));
	
		condRet = TAB_ObterListaAmeacados(linInicial, colInicial, &pLista, tabuleiro);
		switch(condRet){
			case TAB_CondRetForaTabuleiro:
				return JOG_CondRetMovimentoIlegal;
			break;
             
			case TAB_CondRetPosicaoVazia:
				return JOG_CondRetMovimentoIlegal;
			break;
				
			case TAB_CondRetErro:
				return JOG_CondRetErro;
			break;
		}
		
		printf("\nAmeacados de %c%d:", colunaInicial, linhaInicial);
		condRet = -1;
		do{
			condRet = LIS_IrAnteriorLista(pLista);
			if(condRet == LIS_CondRetListaVazia){
				printf("\n(VAZIO)");
				return JOG_CondRetErro;
			}
		}while(condRet!=LIS_CondRetInicioLista);
		
		do{
			if(LIS_ObterValor(pLista, &tempString)) return JOG_CondRetErro;
			printf("\n%s", tempString);
			condRet = LIS_IrProximoLista(pLista);
			if(condRet == LIS_CondRetErro) return JOG_CondRetErro;
		}while(condRet!=LIS_CondRetFimLista);
		
		free(tempString);
		LIS_DestruirLista(pLista);		
		return JOG_CondRetOK;
	
	}/* Fim função: JOG  -ValidarAmeacados*/
	
/***********************************************************************
*
*  $FC Função: JOG  &ValidarReis
*
***********************************************************************/  
	JOG_tpCondRet JOG_ValidarReis(){

		if(JOG_ValidarReiInternal(linhaRP, colunaRP, "Preto")
		== JOGCondRetCheckMate) return JOGCondRetCheckMate;
		return JOG_ValidarReiInternal(linhaRB, colunaRB, "Branco");
		
	}/* Fim função: JOG  -ValidarReis*/	
	
/***********************************************************************
*
*  $FC Função: JOG  -ImprimirPosicoes
*
***********************************************************************/
   JOG_tpCondRet JOG_ImprimirPosicoes(){
   
	int lin, col, condRet;
	char* id =  (char*) malloc(sizeof(char)*4);
	
	/*Print header */
	printf("\n\n- - POSICOES - -\n\n");
	
	/*Print miolo do tabuleiro */
	for(lin = 0; lin< LINHAS; lin++){
		printf(" %d | ", (LINHAS - lin));
		
		for(col = 0; col< COLUNAS; col++){
			*id = '\0';
			condRet = TAB_ObterPeca(lin, col, &id, tabuleiro);
			if(condRet == TAB_CondRetOK){
				printf("|%s| ", id);
			}else if(condRet == TAB_CondRetPosicaoVazia){
				printf("|_,_| ");
			}else{
				printf("ERROR!!!\n");
				return JOG_CondRetErro;
			}
		}
		
		printf("|\n");
	}
	
	/* PrintLetters */
	printf("\n   | |_A_| |_B_| |_C_| |_D_| |_E_| |_F_| |_G_| |_H_| |\n");  
   
   free(id);
   return JOG_CondRetOK;
   } /* Fim função: JOG  -ImprimirPosicoes*/	

/*****  Código das funções encapsuladas no módulo  *****/
	
/***********************************************************************
*
*  $FC Função: JOG  -ValidarReiInternal
*
***********************************************************************/
JOG_tpCondRet JOG_ValidarReiInternal(int linhaIni, int colunaIni, char* label){
		LIS_tppLista pLista;
		int lin, col, condRet;
		int numChecks = 0;
		char* tempString = (char*) malloc(sizeof(char)*4);
		
		pLista = *((LIS_tppLista*) malloc(sizeof(LIS_tppLista)));
		condRet = TAB_ObterListaAmeacantes(linhaIni, colunaIni, &pLista, tabuleiro);
		if(condRet == TAB_CondRetErro) return JOG_CondRetErro;
		
		if(condRet == TAB_CondRetOK){
			if(LIS_IrAnteriorLista(pLista) != LIS_CondRetListaVazia){
				printf("\nRei %s: Check", label);
				LIS_DestruirLista(pLista);
				for(lin = (linhaIni - 1); lin <= (linhaIni + 1); lin++){
					for(col = (colunaIni - 1); col <= (colunaIni + 1); col++){
						if(!(lin == linhaIni && col == colunaIni)){
							condRet = TAB_ObterPeca(lin, col, &tempString, tabuleiro);
							if(condRet == TAB_CondRetOK || condRet == TAB_CondRetForaTabuleiro){
								numChecks++;
							}else if(condRet == TAB_CondRetPosicaoVazia){
								if(TAB_MoverPeca(linhaIni, colunaIni, lin, col, tabuleiro) == TAB_CondRetOK){
									pLista = *((LIS_tppLista*) malloc(sizeof(LIS_tppLista)));
									condRet = TAB_ObterListaAmeacantes(lin, col, &pLista, tabuleiro);
									if(condRet == TAB_CondRetErro) return JOG_CondRetErro;
									if(condRet == TAB_CondRetOK){
										if(LIS_IrAnteriorLista(pLista) != LIS_CondRetListaVazia){
											numChecks++;
										}
										LIS_DestruirLista(pLista);
									}
									if(TAB_MoverPeca(lin, col, linhaIni, colunaIni, tabuleiro) == TAB_CondRetErro) return JOG_CondRetErro;
								}
							}else{
								pLista = *((LIS_tppLista*) malloc(sizeof(LIS_tppLista)));
								condRet = TAB_ObterListaAmeacantes(lin, col, &pLista, tabuleiro);
								if(condRet == TAB_CondRetErro) return JOG_CondRetErro;
								if(condRet == TAB_CondRetOK){
									if(LIS_IrAnteriorLista(pLista) != LIS_CondRetListaVazia){
										numChecks++;
									}
									LIS_DestruirLista(pLista);
								}
							}
						}
			
					}
				}
				if(numChecks == 8){
					printf("Mate\n");
					return JOGCondRetCheckMate;
				}
			}
		}
		
		free(tempString);
		return JOG_CondRetOK;
		
	}/* Fim função: JOG  -ValidarReiInternal*/	


/***********************************************************************
*
*  $FC Função: JOG  -Converte coordenada da linha
*
***********************************************************************/

   int converterLinha(int linha){
		/* Ajuste das coordenadas 1 based para a matriz interna 0 based, invertendo o
		 * ponto (0,0)
		 */
		return LINHAS - linha;
   
	}/* Fim função: JOG  -Converte coordenada da linha*/		

   
/***********************************************************************
*
*  $FC Função: JOG  -Converte coordenada da coluna
*
***********************************************************************/

   int converterColuna(char coluna){

		int dist;
		if ((coluna >= 'a') && (coluna <= 'z')){
			dist = (coluna - 'a');
		}
		else{
			dist = coluna - 'A';
		}
		return dist;
	}/* Fim função: JOG  -Converte coordenada da coluna*/	

	   
/***********************************************************************
*
*  $FC Função: JOG  -Atualiza posicao dos reis
*
***********************************************************************/
static void atualizaPosicaoReis(int colunaInicial, int linhaInicial,
	int colunaFinal, int linhaFinal){
	
	if(linhaInicial == colunaRB && colunaInicial == linhaRB){
		colunaRB = colunaFinal;
		linhaRB = linhaFinal;
	}else if(linhaInicial == colunaRP && colunaInicial == linhaRP){
		colunaRB = colunaFinal;
		linhaRB = linhaFinal;
	}
	
}/* Fim função: JOG  -Atualiza posicao dos reis*/

/********** Fim do módulo de implementação: JOG  Jogo generico **********/

