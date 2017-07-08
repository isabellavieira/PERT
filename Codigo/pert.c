/*----------------------------------------------------------------------*/
/* 			Universidade Federal de São João del - Rei 
							Grafos
				Ciência da Computação - 4º período
					
						Algoritmo PERT		    
						
					Isabella Vieira Ferreira
					 Mônica Neli de Resende
						Abril / 2013                                    */
/*----------------------------------------------------------------------*/

#include "pert.h"

/*---------------------------------------------------------------------*/
/* Função que calcula a data mais cedo no grafo						   */
/*---------------------------------------------------------------------*/
void calculoDataMaisCedo (Grafo *grafo) {
	
	int i;
	Apontador lista = NULL;

	for (i = 1; i<grafo->tam; i++){
		
		lista = grafo->hash[i].L.primeiro->prox;

		while (lista != NULL) {
			
		// Se a soma for maior que o que já está no dataMaisCedo -> substitui
		if ((lista->duracao + grafo->hash[i].dataMaisCedo) > grafo->hash[lista->para].dataMaisCedo) {
			grafo->hash[lista->para].dataMaisCedo = lista->duracao + grafo->hash[i].dataMaisCedo;
		}

		lista = lista->prox;

		}
	}
}


/*---------------------------------------------------------------------*/
/* Função que calcula a data mais tarde no grafo					   */
/*---------------------------------------------------------------------*/
void calculoDataMaisTarde (Grafo *grafo, int caminhoCritico[], int *j) {
	
	int i;
	Apontador lista = NULL;
	
	// O campo dataMaisTarde da última posição do grafo = dataMaisCedo
	grafo->hash[grafo->tam].dataMaisTarde = grafo->hash[grafo->tam].dataMaisCedo;
	
	
	
	for (i = grafo->tam-1; i>=1;i--) {
		
		lista = grafo->hash[i].L.primeiro->prox;
		
		while (lista != NULL) {
			
			if ((grafo->hash[lista->para].dataMaisTarde - lista->duracao) < grafo->hash[i].dataMaisTarde) {
				grafo->hash[i].dataMaisTarde = grafo->hash[lista->para].dataMaisTarde - lista->duracao;

				// verificando o caminho critico
				if (grafo->hash[i].dataMaisCedo == grafo->hash[i].dataMaisTarde) {
					caminhoCritico[*j] = i;
					*j = *j+1;
				}
			}

			lista = lista->prox;
		}
	} 
}

/*---------------------------------------------------------------------*/
/* Vetor de folgas													   */
/*---------------------------------------------------------------------*/
void calculoFolga (Grafo grafo, int folgas[]) {
	
	int i;
	
	for (i=1; i<=grafo.tam; i++) {	
		folgas[i] = grafo.hash[i].dataMaisTarde - grafo.hash[i].dataMaisCedo; 
	}
}
