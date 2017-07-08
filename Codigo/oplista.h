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

#ifndef OPLISTA_H
#define OPLISTA_H


/*--------------------------------------------------------------------------*/
//					TAD - Lista
/*--------------------------------------------------------------------------*/
		typedef struct celula *Apontador;
		
		typedef struct celula {
			int para;
			int atividade;
			int duracao;
			Apontador prox;
		} celula;

		//Tipo abstrato Lista simplesmente encadeada
		typedef struct {
			Apontador primeiro, ultimo;
			int tam;
		} Lista;
  

/*--------------------------------------------------------------------------*/
void criarLista(Lista *L1);
/*--------------------------------------------------------------------------*/
void desalocarLista (Lista *L1);
/*--------------------------------------------------------------------------*/
void mostrarLista (Lista *L1) ;
/*--------------------------------------------------------------------------*/
void inserirElementoComeco(int para, int atividade,int duracao, Lista *L1);
/*--------------------------------------------------------------------------*/
void inserirElemento(int para, int atividade, int duracao, Lista *L1);
/*--------------------------------------------------------------------------*/
Apontador buscarElemento(int para, Lista *L1);
/*--------------------------------------------------------------------------*/
int Vazia(Lista *L1);
/*--------------------------------------------------------------------------*/
int Tam(Lista L1);
/*--------------------------------------------------------------------------*/
void removerDaLista (Lista *L1, int para);
/*--------------------------------------------------------------------------*/

#endif
