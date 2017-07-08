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

#ifndef ENTRADASAIDA_H
#define ENTRADASAIDA_H

/*----------------------------------------------------------------------*/
int converterStringToInt (FILE *entrada, char *caractere);
/*----------------------------------------------------------------------*/
void contarMaiorArquivo (FILE *entrada, int *maiorVertice);
/*----------------------------------------------------------------------*/
void leituraArquivo (FILE *entrada, int numVertices, Grafo *grafo);
/*----------------------------------------------------------------------*/

#endif
