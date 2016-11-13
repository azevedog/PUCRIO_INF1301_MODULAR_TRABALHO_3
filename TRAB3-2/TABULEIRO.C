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
 TAB_tpCondRet TAB_InserirPeca(int linha, int coluna,  char* identificador, char* corTime, 
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
  TAB_tpCondRet TAB_MoverPeca(int inicialX, int inicialY, int finalX, int finalY, TAB_tppTabuleiro tabuleiro){
		
		TAB_tpCondRet ret;
		PEC_tppPeca pPecaOrigem;
		PEC_tppPeca pPecaDestino;
		
		if(posicaoInvalida(finalX, finalY, tabuleiro)){
			return TAB_CondRetForaTabuleiro;
		}
		
		pPecaOrigem = tabuleiro->posicoes[inicialX][inicialY];
		
		if(pPecaOrigem == NULL){
			return TAB_CondRetErro;
		}
		
		if(PEC_Mover(pPecaOrigem, inicialX, inicialY, finalX, finalY)!=PEC_CondRetOK){
			return TAB_CondRetElementoNaoFaz;
		}
		
		pPecaDestino = tabuleiro->posicoes[finalX][finalY];
		
		if(pPecaDestino != NULL){
			if(PEC_ComparaPeca(pPecaOrigem, pPecaDestino) == PEC_CondRetMesmoTime){
				return TAB_CondRetElementoMesmoTime;
			}
			else{
				if(TAB_RetirarPeca(finalX, finalY, tabuleiro)!=PEC_CondRetOK){
					return TAB_CondRetErro;
				}
				ret = TAB_CondRetSubstituiuOutroElemento;
			}
		}
		else{
			ret = TAB_CondRetOK;
		}
				
		tabuleiro->posicoes[finalX][finalY] = pPecaOrigem;
		tabuleiro->posicoes[inicialX][inicialY] = NULL;

		return ret;
	}/* Fim função: TAB  &Mover peca no tabuleiro */

   
/***************************************************************************
*
*  Função: TAB  &Retirar peca do tabuleiro
*  ****/
 TAB_tpCondRet TAB_RetirarPeca(int inicialX, int inicialY, TAB_tppTabuleiro tabuleiro){
 
		if(posicaoInvalida(inicialX, inicialY, tabuleiro)){
			return TAB_CondRetForaTabuleiro;
		}
		
		if(tabuleiro->posicoes[inicialX][inicialY] == NULL){
			return TAB_CondRetErro;
		}
		
		tabuleiro->posicoes[inicialX][inicialY] = NULL;
				
		return TAB_CondRetOK;
	}/* Fim função: TAB  &Retirar peca do tabuleiro */
   

/***************************************************************************
*
*  Função: TAB  &Obter peca do tabuleiro
*  ****/
 TAB_tpCondRet TAB_ObterPeca(int inicialX, int inicialY, char** id,
	TAB_tppTabuleiro tabuleiro){
	
		PEC_tppPeca pPeca;
		
		if(posicaoInvalida(inicialX, inicialY, tabuleiro)){
			return TAB_CondRetForaTabuleiro;
		}
		
		if(tabuleiro->posicoes[inicialX][inicialY] == NULL){
			return TAB_CondRetErro;
		}
		
		pPeca = tabuleiro->posicoes[inicialX][inicialY];
		
		if(!PEC_ObterIdentificarPeca(pPeca, id)){
				return TAB_CondRetErro;
		}
		return TAB_CondRetOK;
	}/* Fim função: TAB  &Obter peca do tabuleiro */
	

/***************************************************************************
*
*  Função: TAB  &Obter ameacantes
*  ****/
 TAB_tpCondRet TAB_ObterListaAmeacantes(int inicialX, int inicialY, LIS_tppLista* lista,
	TAB_tppTabuleiro tabuleiro){
	
		int x, y;
		PEC_tppPeca pPecaOrigem;
		PEC_tppPeca pPecaDestino;
				
		if(posicaoInvalida(inicialX, inicialY, tabuleiro)){
			return TAB_CondRetForaTabuleiro;
		}

		pPecaOrigem = tabuleiro->posicoes[inicialX][inicialY];
		
		if(pPecaOrigem == NULL){
			return TAB_CondRetErro;
		}
		
		for(x=0; x<tabuleiro->colunas; x++){
			for(y=0; y<tabuleiro->linhas; y++){
				if(x!=inicialX && y!=inicialY){
					pPecaDestino = tabuleiro->posicoes[inicialX][inicialY];
					if(PEC_ComparaPeca(pPecaDestino, pPecaOrigem) == PEC_CondRetTimeDiferente){
						if(PEC_Mover(pPecaDestino, x, y, inicialX, inicialY)){
							LIS_InserirElemento((*lista), pPecaDestino);
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
 TAB_tpCondRet TAB_ObterListaAmeacados(int inicialX, int inicialY, LIS_tppLista* lista,
	TAB_tppTabuleiro tabuleiro){
		
		int x, y;
		PEC_tppPeca pPecaOrigem;
		PEC_tppPeca pPecaDestino;
				
		if(posicaoInvalida(inicialX, inicialY, tabuleiro)){
			return TAB_CondRetForaTabuleiro;
		}

		pPecaOrigem = tabuleiro->posicoes[inicialX][inicialY];
		
		if(pPecaOrigem == NULL){
			return TAB_CondRetErro;
		}
		
		for(x=0; x<tabuleiro->colunas; x++){
			for(y=0; y<tabuleiro->linhas; y++){
				if(x!=inicialX && y!=inicialY){
					pPecaDestino = tabuleiro->posicoes[inicialX][inicialY];
					if(PEC_ComparaPeca(pPecaDestino, pPecaOrigem) == PEC_CondRetTimeDiferente){
						if(PEC_Mover(pPecaOrigem, inicialX, inicialY, x, y)){
							LIS_InserirElemento((*lista), pPecaDestino);
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
	
	

/********** Fim do módulo de implementação: TAB  Tabuleiro de jogo generico **********/

