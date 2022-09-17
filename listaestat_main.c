#include<stdio.h>
#include "listaestat.h"

int main() {
	t_lista L;
	t_elemento e;
	t_apontador P;

	CriaLista(&L);
	

	e.chave = 5;
	InsereLista(&L, e);

	e.chave = 1;
	InsereLista(&L, e);

	e.chave = 3;
	InsereLista(&L, e);

	e.chave = 0;
	InsereLista(&L, e);

	e.chave = 25;
	InsereLista(&L, e);

	e.chave = -3;
	InsereLista(&L, e);

	ImprimeLista(&L);
	
	printf("Achou? Onde? %d\n", PesquisaLista(&L,3));
	printf("Achou? Onde? %d\n", PesquisaLista(&L,450));
	
	RemoveLista(&L, 5);
	ImprimeLista(&L);
	RemoveLista(&L, -3);	
	ImprimeLista(&L);
	RemoveLista(&L, 3);
	ImprimeLista(&L);
	RemoveLista(&L, 450);
	ImprimeLista(&L);
	
	printf("Achou? Onde? %d\n", PesquisaLista(&L,3));
	printf("Achou? Onde? %d\n", PesquisaLista(&L,450));

}