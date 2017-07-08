/*----------------------------------------------------------------------*/
/* 			Universidade Federal de São João del - Rei 
							Grafos
				Ciência da Computação - 4º período
					
						Algoritmo PERT		    
						
					Isabella Vieira Ferreira
					 Mônica Neli de Resende
						Abril / 2013                                    */
/*----------------------------------------------------------------------*/

#include "opgrafo.h"
#include <limits.h>

#define INFINITO INT_MAX

/*--------------------------------------------------------------------------*/
/* Função responsável por criar o Grafo com o tamanho de vértices definido. */
/*--------------------------------------------------------------------------*/
void criarGrafo(Grafo *G1, int numVertices){
	int i;
	
	G1->hash = (ApontadorVertice) malloc(sizeof(Vertice)*(numVertices+1));
	G1->tam = numVertices;
	
	for (i = 0; i <=numVertices; i++){
		G1->hash[i].de = -1;
		G1->hash[i].dataMaisCedo = 0;
		G1->hash[i].dataMaisTarde = INFINITO;
	}
}

/*--------------------------------------------------------------------------*/
/* Função responsável por desalocar o Grafo.                                 */
/*--------------------------------------------------------------------------*/
void desalocarGrafo(Grafo *G1) {
	int i;
	Vertice adjacentes;
		
	//Desalocando a lista de cada vértice
	for (i=0; i < G1->tam; i++){
		
		adjacentes = G1->hash[i];
		desalocarLista(&adjacentes.L);
	}
	free(G1->hash);
	
}

/*--------------------------------------------------------------------------*/
/*Função responsável por imprimir o grafo na tela.  */
/*--------------------------------------------------------------------------*/
void mostrarGrafo (Grafo G1) {  
	int i;
		
	//Vertice adjacentes;
	for(i = 1; i <= (G1.tam); i++){
			
			if (G1.hash[i].L.primeiro == NULL) {
			
				printf ("Não há lista para esse vértice\n");
			
			} else {

				mostrarLista(&(G1.hash[i].L));
			}
	}
}

/*--------------------------------------------------------------------------*/
/* Função responsável por inserir um vertice no Grafo.                       */
/*--------------------------------------------------------------------------*/
void inserirVertice(int de, Grafo *G1){

	G1->hash[de].de = de;
	criarLista(&G1->hash[de].L);
}

/*--------------------------------------------------------------------------*/
/* Função responsável por inserir uma aresta (v0->v1) no Grafo.      
 * inserirAresta(v0, v1, capacidade, custo).   				                 */
/*--------------------------------------------------------------------------*/
void inserirAresta(int v0, int para, int atividade, int duracao, Grafo *G1){

	if (Tam(G1->hash[v0].L) >= 0){
		
		inserirElemento(para, atividade, duracao, &G1->hash[v0].L);
		
	}else{
		
		printf("Erro: Lista não alocada!");
		
	}	
}

