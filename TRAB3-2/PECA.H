/***************************************************************************
*
*  $MCD Módulo de definição: PEC Peca de um jogo de tabuleiro
*
*  Arquivo gerado:              PECA.h
*  Letras identificadoras:      PEC
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
*      3     gbha  13/Nov/2016 Ajustes para o T3
*	  2       gbha   3/out/2016	conclusão desenvolvimento
*     1       gbha   1/out/2016 início desenvolvimento
*
*  $ED Descrição do módulo
*     Implementa uma estrutura genérica de peca para jogos de tabuleiro.
*	  Esta peca é definida por um identificacao (char) e uma cor(char).
*
*     A função de movimento das pecas deve ser fornecida pelo usuario do
*	  modulo respeitando a assinatura detalhada na mesma.
*
***************************************************************************/

/***** Declarações exportadas pelo módulo *****/

/* Tipo referência para uma peca */
typedef struct PEC_tagPeca* PEC_tppPeca ;

/***********************************************************************
*
*  $TC Tipo de dados: PEC Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções da peca
*
***********************************************************************/
   typedef enum {
         PEC_CondRetOK,
               /* Concluiu corretamente */
			   
		 PEC_CondRetERRO,
               /* Concluiu com erro */
			   
		 PEC_CondRetTimeDiferente,
               /* Duas pecas NAO tem a mesma cor*/
			   
		 PEC_CondRetMesmoTime
               /* Duas pecas tem a mesma cor*/

   } PEC_tpCondRet;
 
/***********************************************************************
*
*  $FC Função: PEC  &Criar Peca
*
*  $ED Descrição da função
*     Cria uma peca generica para um jogo de tabuleiro.
*
*  $EP Parâmetros
*     ppPeca  - Ponteiro de ponteiro para passagem da peca criada
*     por referência.
*
*     identificador  - Caracter que identifica o tipo de peca. Como
*     este atributo é armazenado em um byte, permite 128 tipos
*	  diferentes.
*
*	   corTime  - Caracter que identifica o time que esta peca
*     pertence. Como este atributo é armazenado em um byte,
*	   permite 128 tipos diferentes.
*
*     pathMovimento  - Caminho para executável que processa a validade
*     do movimento da peca. Se respeita as regras da peca. NÃO
*	  VALIDA SE O MOVIMENTO É OUT OF BOUNDS NO TABU
*	  LEIRO.
*
*  $FV Valor retornado
*     Se executou corretamente retorna PEC_CondRetOK.
*
*     Se ocorreu algum erro, retorna PEC_CondRetERRO.
*     Não será dada mais informação quanto ao problema ocorrido.
*
***********************************************************************/
PEC_tpCondRet PEC_CriarPeca(PEC_tppPeca* ppPeca, char identificador, char corTime, 
char* pathMovimento) ;


/***********************************************************************
*
*  $FC Função: PEC  &ObterIdentificarPeca
*
*  $ED Descrição da função
*     Recupera o nome do tipo da peca e o seu time.
*
*  $EP Parâmetros
*     pPeca  - Ponteiro da peca por valor.
*     por referência.
*
*     id  - String de 3 caracteres <CaracterTipoPeca,CorTime> ex.: Peão do time preto
*	   <P,P>
*
*  $FV Valor retornado
*     Se executou corretamente retorna PEC_CondRetOK.
*
*     Se ocorreu algum erro, retorna PEC_CondRetERRO.
*     Não será dada mais informação quanto ao problema ocorrido.
*
***********************************************************************/
PEC_tpCondRet PEC_ObterIdentificadorPeca(PEC_tppPeca pPeca, char** id);

/***********************************************************************
*
*  $FC Função: PEC  &Mover
*
*  $ED Descrição da função
*     Valida o movimento da peca. Verifica se respeita as regras
*	  da peca. NÃO VALIDA SE O MOVIMENTO É OUT OF
*	  BOUNDS NO TABULEIRO.
*
*  $EP Parâmetros
*     pPeca  - Ponteiro para peca que sera movida.
*
*     inicialX  - Coordenada horizontal da posicao inicial da peca
*
*     inicialY  - Coordenada vertical da posicao inicial da peca
*
*     finalX  - Coordenada horizontal da posicao final da peca
*
*     finalY  - Coordenada vertical da posicao final da peca
*
*  $FV Valor retornado
*     Se executou corretamente retorna PEC_CondRetOK.
*
*     Se ocorreu algum erro, retorna PEC_CondRetERRO.
*     Não será dada mais informação quanto ao problema ocorrido.
*
***********************************************************************/

PEC_tpCondRet PEC_Mover(PEC_tppPeca pPeca, int inicialX, int inicialY, int finalX, int finalY) ;

/***********************************************************************
*
*  $FC Função: PEC  &LiberarPeca
*
*  $ED Descrição da função
*     Libera o espaço de memória utilizado para armazaner a peca.
*
*  $EP Parâmetros
*     pPeca  - Ponteiro para peca que sera liberada.
*
*  $FV Valor retornado
*     Se executou corretamente retorna PEC_CondRetOK.
*
*     Se ocorreu algum erro, retorna PEC_CondRetERRO.
*     Não será dada mais informação quanto ao problema ocorrido.
*
***********************************************************************/

PEC_tpCondRet PEC_LiberarPeca(PEC_tppPeca pPeca) ;

/***********************************************************************
*
*  $FC Função: PEC  &ComparaPeca
*
*  $ED Descrição da função
*     Determina se duas pecas sao do mesmo time pela sua cor.
*
*  $EP Parâmetros
*     elem1  - Ponteiro para peca 1.
*
*     elem2  - Ponteiro para peca 2.
*
*  $FV Valor retornado
*     PEC_CondRetTimeDiferente, se as duas pecas NAO tem a mesma cor
			   
	   PEC_CondRetMesmoTime, se as duas pecas TEM a mesma cor.
*
*     Se ocorreu algum erro, retorna PEC_CondRetERRO.
*     Não será dada mais informação quanto ao problema ocorrido.
*
***********************************************************************/
PEC_tpCondRet PEC_ComparaPeca(void* elem1, void* elem2);

/********** Fim do módulo de definição: PEC Peca de um jogo de tabuleiro**********/
