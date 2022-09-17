#include "listadinam.h"
#include <stdio.h>
#include <stdlib.h>

int criar(t_lista *lista) {
	lista->primeiro = NULL;
	lista->ultimo = NULL;
}

int inserir(t_lista *lista, t_elemento elemento) {

	t_apontador novo;
	novo = (t_apontador) malloc(sizeof(t_no));
	if (novo == NULL)
		return ERRO_CHEIA;

	novo->elemento = elemento;
	novo->proximo = lista->primeiro;
	lista->primeiro = novo;

	return SUCESSO;

}
 t_apontador pesquisar(t_lista *lista, t_chave chave) {

	t_apontador P = lista->primeiro; 
	if(P == NULL)
		return NULL;
	while(P != NULL) {
		if (P->elemento.chave == chave)
			return P;
		P = P->proximo;
	}
	return P;
}
static int remove_posicao(t_lista *lista, t_apontador p) {
	//lista vazia
	if (p == NULL) {
		return POS_INVALIDA;
	}

	// unico elemento
	if (p == lista->primeiro && p == lista->ultimo) {
		criar(lista);
		free(p);
		return SUCESSO;
	}

	// remove do inicio
	if (p == lista->primeiro) {
		lista->primeiro = lista->primeiro->proximo;
		free(p);
		return SUCESSO;
	}

	// remove do meio
	t_apontador aux = lista->primeiro;//necessário criar o aux para nao perder a posição 
	while(aux->proximo != NULL && aux->proximo != p) {
		aux = aux->proximo;//passa a apontar pra prox posição
	}

	aux->proximo = p->proximo;//exemplo do a,b,c,tipo, vc aponta pro b com o aux, o b aponta pro c, o a prox = b prox, pois ele passa a apontar pro c, e dps da free no ponteiro do b 
	// remove do fim
	if (aux->proximo == NULL) {
		lista->ultimo = aux;
	}
	free(p);
	return SUCESSO;
}

int remover(t_lista *lista, t_chave chave) {
	t_apontador P = pesquisar(lista,chave);
	int elemento = remove_posicao(lista,P);
	if (elemento == POS_INVALIDA)
	{
		printf("Não foi possivel remover o %d!\n",chave);
	}else printf("Sucesso, o %d foi removido!\n",chave);
}

int alterar(t_lista *lista, t_elemento novo_elemento);
int vazia(t_lista *lista) {
	if (lista->ultimo == NULL && lista->primeiro == NULL)
	{
		return 1;
	}
	else return 0;
}
//int cheia(t_lista *lista) {
 //t_apontador p= lista->primeiro;
 //while (p != NULL)
void imprimir(t_lista *lista) {
    t_apontador P = lista->primeiro; //p =Piliar
	while(P != NULL) {
		 printf("%d ",P->elemento.chave);
		P = P->proximo;
	}
}
int tamanho (t_lista *lista) {
	t_apontador p= lista->primeiro; 
	int n=0;
	while (p != NULL) {
		n++;
		p = p->proximo;
}
	return n;
}

void reverse(t_lista *lista)
{
	t_apontador P = lista->primeiro; // p =Piliar
	if (lista->primeiro == NULL)
		printf("Lista vazia\n");
	if (lista->primeiro->proximo == NULL)
	{
		printf("Lista unitária\n");
	}
	t_apontador anterior = NULL;
	t_apontador proximo = lista->primeiro;
	do
	{
		proximo = lista->primeiro->proximo;
		lista->primeiro->proximo = anterior; // inverter o prox
		anterior = lista->primeiro;			 // andar com o ant pra frente
		lista->primeiro = proximo;
	} while (proximo != NULL);
	lista->primeiro = anterior;
} 
