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
#include "oplista.h"

#ifndef OPGRAFO_H
#define OPGRAFO_H

/*--------------------------------------------------------------------------*/
//					TAD - Grafo
/*--------------------------------------------------------------------------*/
		typedef struct Vertice *ApontadorVertice;
		
		typedef struct Vertice{
			int de;
			int dataMaisCedo;					
			int dataMaisTarde;
			Lista L;
			
		}Vertice;
		
		//Tipo abstrato Grafo a partir de lista de adjacência
		typedef struct {
			ApontadorVertice hash;
			int tam;
		} Grafo;
  
/*--------------------------------------------------------------------------*/ 
void criarGrafo(Grafo *G1, int numVertices);
/*--------------------------------------------------------------------------*/ 
void desalocarGrafo(Grafo *G1);
/*--------------------------------------------------------------------------*/ 
void mostrarGrafo (Grafo G1);
/*--------------------------------------------------------------------------*/ 
void inserirVertice(int de, Grafo *G1);
/*--------------------------------------------------------------------------*/ 
void inserirAresta(int v0, int para, int atividade, int duracao, Grafo *G1);
/*--------------------------------------------------------------------------*/ 

#endif
