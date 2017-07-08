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
#include "oplista.h"

#ifndef PERT_H
#define PERT_H

/*----------------------------------------------------------------------*/
void calculoDataMaisCedo (Grafo *grafo);
/*----------------------------------------------------------------------*/
void calculoDataMaisTarde (Grafo *grafo, int caminhoCritico[], int *j);
/*----------------------------------------------------------------------*/
void calculoFolga (Grafo grafo, int folgas[]);
/*----------------------------------------------------------------------*/

#endif
