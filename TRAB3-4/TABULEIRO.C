/***************************************************************************
*  $MCI Módulo de implementação: TAB  Tabuleiro para jogo generico 
*
*  Arquivo gerado:              TABULEIRO.c
*  Letras identificadoras:      TAB
*
*  Nome da base de software:    OpenJogos
*
*  Projeto: MODULAR_T2
*  Gestor:  EAMCEMP LTDA
*  Autores: MCS e GBHA
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
* 		5		gbha		14/nov/2016 Conlusao desenvolvimento T3
*	   4       gbha  13/Nov/2016 Ajustes para o T3
*	   3       gbha  4/out/2016 Conclusao desenvolvimento
*	   2       gbha  3/out/2016 Continuacao desenvolvimento
*      1       mcs   1/out/2016 início desenvolvimento
*
***************************************************************************/

#include   <stdio.h>
#include   <string.h>
#include   <memory.h>
#include   <malloc.h>
#include   <assert.h>
#include	"TABULEIRO.h"
#include	"LISTA.h"
#include	"PECA.h"

/***********************************************************************
*
*  $TC Tipo de dados: TAB Descritor do tabuleiro
*
*
***********************************************************************/

   typedef struct TAB_tagTabuleiro {
   
		/*PEC_tppPeca criadas[26];
				/*Vetor de pecas "definidas" prontas para serem inseridas no tabuleiro",
				 * bastando definir o seu time ao inserir. A limitacao de 26 pecas se deve
				 * ao uso de letras como identificadores de cada tipo de peca. Só pode haver
				 * um tipo por letra a distancia do valor ASCII de 'A' serve como index do vetor.
				 */

        PEC_tppPeca** posicoes;
               /* Matriz de posicoes do tabuleiro*/
			   
		int linhas;
				/* Numero de linhas no tabuleiro. */
				
		int colunas;
				/* Numero de colunas no tabuleiro. */
			   
   } TAB_tpTabuleiro ;

/***** Protótipos das funções encapuladas no módulo *****/
	
	static TAB_tpCondRet posicaoInvalida(int x, int y, TAB_tppTabuleiro tabuleiro);
		/* Verifica se uma posicao esta dentro dos limites do tabuleiro.*/
		
	static void ExcluirValor ( void * pDado ) ;
		/*Funcao para remocao de elemento das listas de ameacados e ameacantes. */

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: TAB  &Criar Tabuleiro
*  ****/
TAB_tpCondRet TAB_CriarTabuleiro(int numColunas, int numLinhas,
		TAB_tppTabuleiro* novoTabuleiro){
		
	int lin, col;
	
	(*novoTabuleiro) =  (TAB_tppTabuleiro) malloc(sizeof(TAB_tpTabuleiro));
	if ((*novoTabuleiro) == NULL ){
      return TAB_CondRetErro ;
    } /* if */
	
	(*novoTabuleiro)->posicoes = (PEC_tppPeca**)
	malloc(sizeof(PEC_tppPeca*)*numLinhas);
	
	for(lin =0; lin < numLinhas; lin++){
		(*novoTabuleiro)->posicoes[lin] = 
			 (PEC_tppPeca*) malloc(sizeof(PEC_tppPeca)*numColunas); 
		for(col = 0; col < numColunas; col++){
			(*novoTabuleiro)->posicoes[lin][col] = NULL;
		}
	}	
	
	(*novoTabuleiro)->linhas = numLinhas;
	(*novoTabuleiro)->colunas = numColunas;
	
	return TAB_CondRetOK;
	}/* Fim função: TAB  &Criar Tabuleiro */


/***************************************************************************
*
*  Função: TAB  &Inserir peca no tabuleiro
*  ****/
 TAB_tpCondRet TAB_InserirPeca(int linha, int coluna,  char identificador, char corTime, 
		char* pathMovimento, TAB_tppTabuleiro tabuleiro){
		
		PEC_tppPeca pPeca;
		
		if(posicaoInvalida(linha, coluna, tabuleiro) ){
			return TAB_CondRetForaTabuleiro;
		}

		pPeca = tabuleiro->posicoes[linha][coluna];		
		
		if(pPeca != NULL){
			return TAB_CondRetErro;
		}
		
		if(PEC_CriarPeca(&pPeca, identificador, corTime,
		 pathMovimento)!= PEC_CondRetOK) {
			return TAB_CondRetErro;
		}
		
		tabuleiro->posicoes[linha][coluna] = pPeca;

		return TAB_CondRetOK;
	}/* Fim função: TAB  &Inserir peca no tabuleiro */

  

/***************************************************************************
*
*  Função: TAB  &Mover peca no tabuleiro
*  ****/
  TAB_tpCondRet TAB_MoverPeca(int linhaInicial, int colunaInicial, int linhaFinal, int colunaFinal,
  TAB_tppTabuleiro tabuleiro){
		
		TAB_tpCondRet ret;
		PEC_tppPeca pPecaOrigem;
		PEC_tppPeca pPecaDestino;
		
		if(posicaoInvalida(linhaFinal, colunaFinal, tabuleiro)){
			return TAB_CondRetForaTabuleiro;
		}
		
		pPecaOrigem = tabuleiro->posicoes[linhaInicial][colunaInicial];
		
		if(pPecaOrigem == NULL){
			return TAB_CondRetPosicaoVazia;
		}

		if(PEC_Mover(pPecaOrigem, colunaInicial, linhaInicial, colunaFinal, linhaFinal)!=PEC_CondRetOK){
			return TAB_CondRetElementoNaoFaz;
		}
		
		pPecaDestino = tabuleiro->posicoes[linhaFinal][colunaFinal];
		
		if(pPecaDestino != NULL){
			if(PEC_ComparaPeca(pPecaOrigem, pPecaDestino) == PEC_CondRetMesmoTime){
				return TAB_CondRetElementoMesmoTime;
			}
			else{
				if(TAB_RetirarPeca(linhaFinal, colunaFinal, tabuleiro)!=PEC_CondRetOK){
					return TAB_CondRetErro;
				}
				ret = TAB_CondRetSubstituiuOutroElemento;
			}
		}
		else{
			ret = TAB_CondRetOK;
		}
				
		tabuleiro->posicoes[linhaFinal][colunaFinal] = pPecaOrigem;
		tabuleiro->posicoes[linhaInicial][colunaInicial] = NULL;

		return ret;
	}/* Fim função: TAB  &Mover peca no tabuleiro */

   
/***************************************************************************
*
*  Função: TAB  &Retirar peca do tabuleiro
*  ****/
 TAB_tpCondRet TAB_RetirarPeca(int linhaInicial, int colunaInicial, TAB_tppTabuleiro tabuleiro){
		PEC_tppPeca pPecaOrigem;
		
		if(posicaoInvalida(linhaInicial, colunaInicial, tabuleiro)){
			return TAB_CondRetForaTabuleiro;
		}
		
		if(tabuleiro->posicoes[linhaInicial][colunaInicial] == NULL){
			return TAB_CondRetPosicaoVazia;
		}
		
		pPecaOrigem = tabuleiro->posicoes[linhaInicial][colunaInicial];
		
		PEC_LiberarPeca(pPecaOrigem);
		tabuleiro->posicoes[linhaInicial][colunaInicial] = NULL;
				
		return TAB_CondRetOK;
	}/* Fim função: TAB  &Retirar peca do tabuleiro */
   

/***************************************************************************
*
*  Função: TAB  &Obter peca do tabuleiro
*  ****/
 TAB_tpCondRet TAB_ObterPeca(int linhaInicial, int colunaInicial, char** id,
	TAB_tppTabuleiro tabuleiro){
	
		PEC_tppPeca pPeca;
		
		if(posicaoInvalida(linhaInicial, colunaInicial, tabuleiro)){
			return TAB_CondRetForaTabuleiro;
		}
		
		if(tabuleiro->posicoes[linhaInicial][colunaInicial] == NULL){
			return TAB_CondRetPosicaoVazia;
		}
		
		pPeca = tabuleiro->posicoes[linhaInicial][colunaInicial];
		
		if(PEC_ObterIdentificadorPeca(pPeca, id) != PEC_CondRetOK){
				return TAB_CondRetErro;
		}
		return TAB_CondRetOK;
	}/* Fim função: TAB  &Obter peca do tabuleiro */
	

/***************************************************************************
*
*  Função: TAB  &Obter ameacantes
*  ****/
 TAB_tpCondRet TAB_ObterListaAmeacantes(int linhaInicial, int colunaInicial, LIS_tppLista* lista,
	TAB_tppTabuleiro tabuleiro){
		
		char* ameacanteId;
		int x, y;
		char* idLista= "T";
		PEC_tppPeca pPecaOrigem;
		PEC_tppPeca pPecaDestino;
				
		if(posicaoInvalida(linhaInicial, colunaInicial, tabuleiro)){
			return TAB_CondRetForaTabuleiro;
		}

		pPecaDestino = tabuleiro->posicoes[linhaInicial][colunaInicial];
		
		if(pPecaDestino == NULL){
			return TAB_CondRetPosicaoVazia;
		}
		
		if(LIS_CriarLista(idLista, ExcluirValor, lista) != LIS_CondRetOK) return TAB_CondRetErro;
		
		for(y=0; y<tabuleiro->linhas; y++){
			for(x=0; x<tabuleiro->colunas; x++){
				if(!(x==colunaInicial && y== linhaInicial)){
					pPecaOrigem = tabuleiro->posicoes[y][x];
					if(pPecaOrigem != NULL){
						if(PEC_Mover(pPecaOrigem, x, y, colunaInicial, linhaInicial) == PEC_CondRetOK){
							if(PEC_ComparaPeca(pPecaDestino, pPecaOrigem) == PEC_CondRetTimeDiferente){
								ameacanteId = (char*) malloc(sizeof(char)*4);
								if(PEC_ObterIdentificadorPeca(pPecaOrigem, &ameacanteId) != PEC_CondRetOK){
									return TAB_CondRetErro;
								}
								LIS_InserirElemento((*lista), ameacanteId);
							}
						}
					}
				}
			}
		}
		
		return TAB_CondRetOK;
	}/* Fim função: TAB  &Obter ameacantes */

	
/***************************************************************************
*
*  Função: TAB  &Obter ameacados
*  ****/
 TAB_tpCondRet TAB_ObterListaAmeacados(int linhaInicial, int colunaInicial, LIS_tppLista* lista,
	TAB_tppTabuleiro tabuleiro){
		
		char* ameacadoId;
		int x, y;
		char* idLista= "D";
		PEC_tppPeca pPecaOrigem;
		PEC_tppPeca pPecaDestino;
				
		if(posicaoInvalida(linhaInicial, colunaInicial, tabuleiro)){
			return TAB_CondRetForaTabuleiro;
		}

		pPecaOrigem = tabuleiro->posicoes[linhaInicial][colunaInicial];
		
		if(pPecaOrigem == NULL){
			return TAB_CondRetPosicaoVazia;
		}
		
		if(LIS_CriarLista(idLista, ExcluirValor, lista) != LIS_CondRetOK) return TAB_CondRetErro;
		
		for(y=0; y<tabuleiro->linhas; y++){
			for(x=0; x<tabuleiro->colunas; x++){
				if(!(x==colunaInicial && y== linhaInicial)){
					if(PEC_Mover(pPecaOrigem, colunaInicial, linhaInicial, x, y) == PEC_CondRetOK){
						pPecaDestino = tabuleiro->posicoes[y][x];
						if(pPecaDestino != NULL){
							if(PEC_ComparaPeca(pPecaDestino, pPecaOrigem) == PEC_CondRetTimeDiferente){
								ameacadoId = (char*) malloc(sizeof(char)*4);
								if(PEC_ObterIdentificadorPeca(pPecaDestino, &ameacadoId) != PEC_CondRetOK){
									return TAB_CondRetErro;
								}
								LIS_InserirElemento((*lista), ameacadoId);
							}
						}
					}
				}
			}
		}
		
		return TAB_CondRetOK;
	}/* Fim função: TAB  &Obter ameacados */


	/***************************************************************************
*
*  Função: TAB  &Destriuir tabuleiro
*  ****/
 TAB_tpCondRet TAB_DestruirTabuleiro(TAB_tppTabuleiro tabuleiro){
	
		int lin, col;
		int numLinhas = tabuleiro->linhas;
		int numColunas = tabuleiro->colunas;
		
		for(lin = 0; lin < numLinhas; lin++){
			
			for(col = 0; col < numColunas; col++){
 
				if( tabuleiro->posicoes[lin][col] != NULL){	
					PEC_LiberarPeca(tabuleiro->posicoes[lin][col]);
				}
			}	
			free(tabuleiro->posicoes[lin]);
		}	
		return TAB_CondRetOK;
	}/* Fim função: TAB &Destriuir tabuleiro */
	



/*****  Código das funções encapsuladas no módulo  *****/
   
/***********************************************************************
*
*  $FC Função: TAB  -Validar posicao
*
***********************************************************************/

   int posicaoInvalida(int x, int y, TAB_tppTabuleiro tabuleiro){
		if((x < 0) || (x >= tabuleiro->linhas) ||
			(y < 0) ||(y >= tabuleiro->colunas)){
			return TAB_CondRetErro;
		}
		
		return TAB_CondRetOK;
	}/* Fim função: TAB  -Validar posicao */
	
	
/***********************************************************************
*
*  $FC Função: TAB  -Excluir valor da lista
*
***********************************************************************/
   void ExcluirValor ( void * pDado ) {
		free(pDado);
		//PEC_LiberarPeca(pDado);
   } /* Fim função: TAB -Excluir */  
	
	

/********** Fim do módulo de implementação: TAB  Tabuleiro de jogo generico **********/

