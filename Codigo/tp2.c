/*----------------------------------------------------------------------*/
/* 			Universidade Federal de São João del - Rei 
							Grafos
				Ciência da Computação - 4º período
					
						Algoritmo PERT		    
						
					Isabella Vieira Ferreira
					 Mônica Neli de Resende
						Abril / 2013                                    */
/*----------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#include "opgrafo.h"
#include "entradaSaida.h"
#include "pert.h"

int main(int argc, char *argv[]){

	FILE *entrada;
	char *arquivo_entrada;
	arquivo_entrada = argv[1];
	entrada = fopen(arquivo_entrada, "r");

	Grafo grafo;
	int maiorVertice =0;
	int i;
	int j = 2;
	
	if (entrada == NULL){
	
		printf("\nParametro incorreto!\n\n");		
		return 1;
	
	} else {
	
		contarMaiorArquivo (entrada, &maiorVertice);
		rewind(entrada);
		
		int caminhoCritico[maiorVertice];		// considerando que a atividade é int e o caminho critico vai ser do tamanho do grafo
		int folgas[maiorVertice];
		
		for (i = 1; i<=maiorVertice; i++) {
			caminhoCritico[i] = -1;				// mandar imprimir quando for diferente de -1
			folgas[i] = 0;
		}
		
		leituraArquivo (entrada, maiorVertice, &grafo);
		caminhoCritico[1] = grafo.tam;
		
		for (i = 0; i < grafo.tam; i++) {
			calculoDataMaisCedo(&grafo);		
		}
		
		for (i = 0; i < grafo.tam; i++) {
			calculoDataMaisTarde(&grafo, caminhoCritico, &j);		
		}
		
		calculoFolga (grafo, folgas);
			
		printf("\n\n\n-------------------- Vetor de Folgas --------------------\n");
		for (i = 1; i<=grafo.tam; i++) {
			printf ("%d ", folgas[i]);
		}
		printf("\n\n\n");
		
		printf("-------------------- Caminho Crítico --------------------\n");
		for (i = grafo.tam; i>=1; i--) {
			if (caminhoCritico[i] != -1) {
				printf ("%d ", caminhoCritico[i]);
			}
		}
		printf("\n\n\n");		
	
	}
	
	return 0;
}
