#include "fila1.h"
#include <stdio.h>
#include <stdlib.h>
static int contador;

int criar(t_fila *fila)
{
	fila->primeiro = NULL;
	fila->ultimo = NULL;
	contador = 0;
} // count = 0

int enfileirar(t_fila *fila, t_elemento elemento)
{

	t_apontador novo;
	novo = (t_apontador)malloc(sizeof(t_no));
	if (novo == NULL)
		return ERRO_CHEIA;

	novo->elemento = elemento;
	novo->proximo = NULL;
	if (vazia(fila))
	{
		fila->primeiro = novo;
	}
	else
	{
		fila->ultimo->proximo = novo;
	}
	fila->ultimo = novo;
	contador++;
	return SUCESSO;
}

int desenfileirar(t_fila *fila)
{
	if (vazia(fila))
		return NAO_ENCONTROU;
	if (fila->primeiro == fila->ultimo)
	{ // fila unitária
		fila->ultimo = NULL;
	}

	t_apontador aux = fila->primeiro;
	fila->primeiro = fila->primeiro->proximo;
	free(aux);
	contador--;
	return SUCESSO; // geralmente retorna um nó que acabou de remover
}
t_no frente(t_fila *fila)
{
	if (vazia(fila))
	{
		printf("Nó vazio!\n");
	}

	return *(fila->primeiro);
}

int alterar(t_fila *fila, t_elemento novo_elemento);
int vazia(t_fila *fila)
{
	if (fila->ultimo == NULL && fila->primeiro == NULL)
	{
		return 1; // tá vazia
	}
	else
		return 0; // não está vazia
}

int cheia(t_fila *fila)
{
	// tenta dar uma malloc e vê se tá nulo
	// isso já é verificar se a fila ta cheia
}
int contar(t_fila *fila)
{
	return contador;
}

void imprimir(t_fila *fila)
{
	t_apontador P = fila->primeiro; // p =Piliar
	while (P != NULL)
	{
		printf("%d ", P->elemento.chave);
		P = P->proximo;
	}
}

void reverse(t_fila *fila)
{
	t_apontador P = fila->primeiro; // p =Piliar
	if (fila->primeiro == NULL)
		printf("fila vazia\n");
	if (fila->primeiro->proximo == NULL)
	{
		printf("fila unitária\n");
	}
	t_apontador anterior = NULL;
	t_apontador proximo = fila->primeiro;
	do
	{
		proximo = fila->primeiro->proximo;
		fila->primeiro->proximo = anterior; // inverter o prox
		anterior = fila->primeiro;			// andar com o ant pra frente
		fila->primeiro = proximo;
	} while (proximo != NULL);
	fila->primeiro = anterior;
}