/***************************************************************************
*
*  $MCI M�dulo de implementa��o: PEC Peca de um jogo de tabuleiro
*
*  Arquivo gerado:              PECA.c
*  Letras identificadoras:      PEC
*
*  Nome da base de software:    OpenJogos
*
*  Projeto: MODULAR_T2
*  Gestor:  EAMCEMP LTDA
*  Autores: MCS e GBHA
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*		4		gbha		14/nov/2016 Conlusao desenvolvimento T3
*     3      gbha  13/Nov/2016 Ajustes para o T3
*	  2       mcs	 2/out/2016 conclus�o do desenvolvimento
*     1       gbha   1/out/2016 in�cio desenvolvimento
***************************************************************************/

#include   <stdio.h>
#include   <string.h>
#include   <memory.h>
#include   <malloc.h>
#include   <assert.h>
#include <process.h> 
#include "PECA.h"

/***********************************************************************
*
*  $TC Tipo de dados: PEC Peca
*
*
***********************************************************************/
typedef struct PEC_tagPeca {

        char identificadorTipo;
               /* Identificador do tipo de peca */

        char corTime;
               /* Cor do time ao qual a peca pertence*/

		char* pathMovimento;
               /* Caminho para o executavel do movimento. */

   } PEC_tpPeca ;


/***** Prot�tipos das fun��es encapuladas no m�dulo *****/
   static void LimparPeca( PEC_tppPeca pPeca) ;

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/


/***************************************************************************
*
*  Fun��o: PEC  &Criar peca
*  ****/
PEC_tpCondRet PEC_CriarPeca(PEC_tppPeca* ppPeca, char identificador,  char corTime,
char* pathMovimento) {

	(*ppPeca) = (PEC_tpPeca*) malloc( sizeof( PEC_tpPeca)) ;
	if((*ppPeca) == NULL){
		return PEC_CondRetERRO;
	}
	
	LimparPeca((*ppPeca));
	
	(*ppPeca)->identificadorTipo = identificador;
	(*ppPeca)->corTime = corTime;
	(*ppPeca)->pathMovimento = pathMovimento;
	
	return PEC_CondRetOK;

}/* Fim fun��o: PEC  &Criar peca */


/***************************************************************************
*
*  Fun��o: PEC  &ObterIdentificarPeca
*  ****/
PEC_tpCondRet PEC_ObterIdentificadorPeca(PEC_tppPeca pPeca, char** id) {
	char localString[4];
	
	if(pPeca == NULL){
		return PEC_CondRetERRO;
	}
	
	localString[0] = (pPeca->identificadorTipo);
	localString[1] = ',';
	localString[2] = (pPeca->corTime);
	localString[3] = '\0';
	
	strcpy(*id, localString);
	
	return PEC_CondRetOK;
}/* Fim fun��o: PEC  &ObterIdentificarPeca */


/***************************************************************************
*
*  Fun��o: PEC  &Mover
*  ****/
PEC_tpCondRet PEC_Mover(PEC_tppPeca pPeca, int inicialX, int inicialY, int finalX, int finalY) {
	int ret = -10;
	char iX, iY, fX, fY;
	
	if ( ( pPeca->pathMovimento == NULL ) ){
		return PEC_CondRetERRO;
	}
	
	iX = '0' + ((unsigned char) inicialX);
	iY = '0' + ((unsigned char) inicialY);
	fX = '0' + ((unsigned char) finalX);
	fY = '0' + ((unsigned char) finalY);
	
	ret = _spawnl(P_WAIT, pPeca->pathMovimento,  pPeca->pathMovimento, &iX, &iY, &fX, &fY, NULL);
	
	if(ret == 0)
	{
		return PEC_CondRetOK;
	} else
	{ 
		return PEC_CondRetERRO;
	}
}

/* Fim fun��o: PEC  &LiberarPeca */

/***************************************************************************
*
*  Fun��o: PEC  &LiberarPeca
*  ****/
PEC_tpCondRet PEC_LiberarPeca(PEC_tppPeca pPeca){
	if(pPeca == NULL){
		return PEC_CondRetERRO;
	}
	free(pPeca->pathMovimento);
	free(pPeca) ;
	return PEC_CondRetOK;
} /* Fim fun��o: PEC  &LiberarPeca */

/***************************************************************************
*
*  Fun��o: PEC  &ComparaPeca
*  ****/
PEC_tpCondRet PEC_ComparaPeca(void* elem1, void* elem2){
	PEC_tppPeca pPeca1 = (PEC_tppPeca) elem1;
	PEC_tppPeca pPeca2 = (PEC_tppPeca) elem2;
	
	
	if(pPeca1->corTime == pPeca2->corTime){
		return PEC_CondRetMesmoTime;
	}
	return PEC_CondRetTimeDiferente;
}


/*****  C�digo das fun��es encapsuladas no m�dulo  *****/

/***********************************************************************
*
*  $FC Fun��o: PEC  -Limpa a peca
*
***********************************************************************/

void LimparPeca( PEC_tppPeca pPeca)
   {
	
		pPeca->identificadorTipo = 0;
		pPeca->corTime = 0;
} /* Fim fun��o: PEC  -Limpa a peca */

/********** Fim do m�dulo de implementa��o: LIS  Lista duplamente encadeada **********/

