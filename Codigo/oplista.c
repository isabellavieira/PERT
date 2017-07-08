/*----------------------------------------------------------------------*/
/* 			Universidade Federal de São João del - Rei 
							Grafos
				Ciência da Computação - 4º período
					
						Algoritmo PERT		    
						
					Isabella Vieira Ferreira
					 Mônica Neli de Resende
						Abril / 2013                                    */
/*----------------------------------------------------------------------*/

#include "oplista.h"

/*--------------------------------------------------------------------------*/
/* Função responsável por criar a lista simplesmente encadeada.
   Possui célula cabeça.                                                    */
/*--------------------------------------------------------------------------*/
void criarLista(Lista *L1){
	
	// L1->primeiro é a célula cabeça
	L1->primeiro = (Apontador) malloc(sizeof(celula));
	L1->ultimo = L1->primeiro;
	L1->primeiro->prox = NULL;
	L1->tam = 0;
	
}

/*--------------------------------------------------------------------------*/
/* Função responsável por desalocar a lista.                                 */
/*--------------------------------------------------------------------------*/
void desalocarLista (Lista *L1) {

	Apontador aux1 = L1->primeiro;
	Apontador aux2 = NULL;
	
	while (aux1 == L1->ultimo) {

		aux2 = aux1;
		aux1 = aux1->prox;
		free(aux2);
	}
	
	free(aux1);
	
}

/*--------------------------------------------------------------------------*/
/*Função responsável por imprimir a lista na tela.  */
/*--------------------------------------------------------------------------*/
void mostrarLista (Lista *L1) {  
	Apontador aux = NULL;

	// L1->primeiro é a célula cabeça
	aux = L1->primeiro->prox;
	int i = 1;
		
	while (aux != NULL){
		printf("\nPara %d atividade %d e duração %d\n", aux->para, aux->atividade, aux->duracao);
		aux = aux->prox;
		i++;
	}
	
}

/*--------------------------------------------------------------------------*/
/* Insere elemento no começo da lista										  */
/*--------------------------------------------------------------------------*/
void inserirElementoComeco(int para, int atividade,int duracao, Lista *L1){
	
	Apontador aux;
	aux = L1->primeiro->prox;
	L1->primeiro->prox = (Apontador) malloc(sizeof(celula));
	L1->primeiro->prox->para = para;
	L1->primeiro->prox->atividade = atividade;
	L1->primeiro->prox->duracao = duracao;
	L1->primeiro->prox->prox = aux;
	L1->tam++;
	
}


/*--------------------------------------------------------------------------*/
/* Função responsável por inserir um elemento na lista.                       */
/*--------------------------------------------------------------------------*/
void inserirElemento(int para, int atividade, int duracao, Lista *L1){

	L1->ultimo->prox = (Apontador) malloc(sizeof(celula));
	L1->ultimo = L1->ultimo->prox;
	L1->ultimo->para = para;		
	L1->ultimo->atividade = atividade;
	L1->ultimo->duracao = duracao;		
	L1->ultimo->prox = NULL;
	L1->tam++;
}


/*--------------------------------------------------------------------------*/
/* Função que busca um elemento na lista e retorna sua posição na lista.    */
/*--------------------------------------------------------------------------*/
Apontador buscarElemento(int para, Lista *L1){

	Apontador aux = L1->primeiro->prox;
	
	while((aux != NULL) && (aux->para != para)){
		
		aux = aux->prox;		
		
	}	
	// Retorna NULL ou o apontador para a célula com o item buscado
	return aux;
}
/*--------------------------------------------------------------------------*/
/* Função que verifica se a lista está vazia ou não. 					   */
/*--------------------------------------------------------------------------*/
int Vazia(Lista *L1) {
	
	return (L1->primeiro == L1->ultimo);
}

/*--------------------------------------------------------------------------*/
/* Função que verifica se a lista está vazia ou não. 					   */
/*--------------------------------------------------------------------------*/
int Tam(Lista L1) {
	
	return (L1.tam);
}

/*--------------------------------------------------------------------------*/
/* Função que remove um vertice da lista. 								   */
/*--------------------------------------------------------------------------*/
void removerDaLista (Lista *L1, int para){
	
	Apontador aux1 = L1->primeiro;
	Apontador aux2 = aux1->prox;

	//Buscando o vertice na lista
	while (aux2 != NULL && aux2->para != para){
		aux1 = aux2;
		aux2 = aux2->prox;		
	}
	
	//Tratamento de possivel erro
	if (aux2 == NULL){
		printf("ERRO: Vertice não existe na lista!");
		return;
	}
	
	//Removendo o vertice
	aux1->prox = aux2->prox;
	free(aux2);
	L1->tam--;

	
}
