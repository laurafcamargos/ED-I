#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
static int num_nos;

int criar(t_pilha *pilha)
{
	pilha->topo = NULL;
	num_nos = 0;
} // count = 0

int empilhar(t_pilha *pilha, t_elemento elemento)
{

	t_apontador novo;
	novo = (t_apontador)malloc(sizeof(t_no));
	if (novo == NULL)
		return ERRO_CHEIA;

	novo->elemento = elemento;
	novo->proximo = pilha->topo;
	pilha->topo = novo;
	num_nos++;
	return SUCESSO;
}

int desempilhar(t_pilha *pilha)
{
	if (vazia(pilha))
		return NAO_ENCONTROU;

	t_apontador aux = pilha->topo; // topo=topo
	pilha->topo = pilha->topo->proximo;
	free(aux);
	num_nos--;

	return SUCESSO; // geralmente retorna um nó que acabou de remover
}
t_no topo(t_pilha *pilha)
{
	if (vazia(pilha))
	{
		printf("Nó vazio!\n");
	}

	return *(pilha->topo);
}

int alterar(t_pilha *pilha, t_elemento novo_elemento);
int vazia(t_pilha *pilha)
{
	if (pilha->topo == NULL)
	{
		return 1; // tá vazia
	}
	else
		return 0; // não está vazia
}

int cheia(t_pilha *pilha)
{
	// tenta dar uma malloc e vê se tá nulo
	// isso já é verificar se a pilha ta cheia
}
int contar(t_pilha *pilha)
{
	return num_nos;
}

void imprimir(t_pilha *pilha)
{
	t_apontador P = pilha->topo; // p =Piliar
	while (P != NULL)
	{
		printf("%d ", P->elemento.chave);
		P = P->proximo;
	}
}

void reverse(t_pilha *pilha)
{
	t_apontador P = pilha->topo; // p =Piliar
	if (pilha->topo == NULL)
		printf("pilha vazia\n");
	if (pilha->topo->proximo == NULL)
	{
		printf("pilha unitária\n");
	}
	t_apontador anterior = NULL;
	t_apontador proximo = pilha->topo;
	do
	{
		proximo = pilha->topo->proximo;
		pilha->topo->proximo = anterior; // inverter o prox
		anterior = pilha->topo;			 // andar com o ant pra frente
		pilha->topo = proximo;
	} while (proximo != NULL);
	pilha->topo = anterior;
}