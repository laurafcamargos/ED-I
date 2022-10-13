#include <stdio.h>
#include "listadinam.h"
#include <stdlib.h>

int main()
{

	t_lista L;
	int i;
	t_elemento item;
	t_apontador P;
	criar(&L);

	scanf("%d",&item.chave);
	inserir(&L, item);

	item.chave = 1;
	inserir(&L, item);

	item.chave = 3;
	inserir(&L, item);

	item.chave = 0;
	inserir(&L, item);

	item.chave = 25;
	inserir(&L, item);

	item.chave = -3;
	inserir(&L, item);
	i = tamanho(&L);
	printf("A lista possui %d elementos\n",i);
	imprimir(&L);
    printf("\n");
	remover(&L, 5);
	printf("\n");
	imprimir(&L);
	printf("\n");
	remover(&L, -3);
	printf("\n");
	imprimir(&L);
	printf("\n");
	remover(&L, 3);
	printf("\n");
	imprimir(&L);
	printf("\n");
	remover(&L, 450);
	printf("\n");
	imprimir(&L);
	printf("\n");
	printf("Invertendo a lista:\n");
	reverse(&L);
	imprimir(&L);
	printf("\n");
	printf("\n");
	P = L.primeiro;
	while (P != NULL)
	{
		L.primeiro = P->proximo;
		printf("Limpando\n");
		free(P);
		P = L.primeiro;
	}
}