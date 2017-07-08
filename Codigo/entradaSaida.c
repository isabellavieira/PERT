/*----------------------------------------------------------------------*/
/* 			Universidade Federal de São João del - Rei 
							Grafos
				Ciência da Computação - 4º período
					
						Algoritmo PERT		    
						
					Isabella Vieira Ferreira
					 Mônica Neli de Resende
						Abril / 2013                                    */
/*----------------------------------------------------------------------*/

#include "entradaSaida.h"

/*----------------------------------------------------------------------*/
/* Converte string para inteiro											*/
/*----------------------------------------------------------------------*/
int converterStringToInt (FILE *entrada, char *caractere){  

	char palavra[5]; 
	int result;
	int i = 0;
	
	while ((*caractere) != ' ' && (*caractere) != '\n'){
		palavra[i] = (*caractere);
		i++;
		fscanf(entrada, "%c" , &(*caractere));			
	}
	
	palavra[i] = '\0';

	result = (atoi(palavra));
	return result;
}

/*----------------------------------------------------------------------*/
/* Função que verifica qual o maior vértice do grafo para alocar a hash */
/*----------------------------------------------------------------------*/
void contarMaiorArquivo (FILE *entrada, int *maiorVertice) {
	
	int de;
	int para;
	int caractere;
	
	while (!feof(entrada)) {
		
		// lendo o caractere DE como inteiro
		fscanf(entrada, "%d" , &de);
			
		// lendo o caractere PARA como inteiro
		fscanf(entrada, "%d" , &para);
		
		// Pegando o maior vértice
		if (de > *maiorVertice) {
			*maiorVertice = de;
		}
		
		if (para > *maiorVertice) {
			*maiorVertice = para;
		}
	
		// lendo a atividade como um caractere
		fscanf(entrada, "%d" , &caractere);
		
		// lendo a duracao como um inteiro
		fscanf(entrada, "%d" , &caractere);

	}	
}

/*----------------------------------------------------------------------*/
/* Leitura do arquivo e alocacao do grafo								*/
/*----------------------------------------------------------------------*/
void leituraArquivo (FILE *entrada, int numVertices, Grafo *grafo) {
	
	int de;
	int para;
	int atividade;
	int duracao;
	int c;
	// Criando grafo (hash)
	criarGrafo (&(*grafo), numVertices);
			
	while (!feof(entrada)) {
		
		//Controlando o preenchimento de linhas e colunas		
		c = getc(entrada);
		if (c != '\n') {
			ungetc(c,entrada);
		
			// lendo o caractere DE
			fscanf(entrada, "%d" , &de);
		
			// lendo o caractere PARA
			fscanf(entrada, "%d" , &para);
			
			// lendo o caractere ATIVIDADE - TODO: CONFERIR SE E CARACTERE MESMO
			fscanf(entrada, "%d" , &atividade);
			
			// lendo o caractere DURACAO
			fscanf(entrada, "%d" , &duracao);	
			
			// inserindo vertices
			if (grafo->hash[de].de != de) {		// se não existe na hash o vertice de, eu o insiro
				inserirVertice(de, &(*grafo));
			} 
		
			// inserindo arestas ("listas") na hash
			inserirAresta(de, para, atividade, duracao, &(*grafo));
		}
	}
	
	// colocando o valor no último vértice
	grafo->hash[grafo->tam].de = grafo->tam;
}
