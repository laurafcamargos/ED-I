#include "trabalho2.h"
#include <stdio.h>
#include <stdlib.h>

void criar_fila(t_lista *lista) {
  lista->primeiro = NULL;
  lista->ultimo = NULL;
}

int enfileirar(t_lista *lista, t_elemento elemento) {

  t_apontador novo;
  novo = (t_apontador)malloc(sizeof(t_no));
  if (novo == NULL)
    return ERRO_CHEIA;

  novo->elemento = elemento;
  novo->proximo = NULL;
  if (vazia_fila(lista)) {
    lista->primeiro = novo;
  } else {
    lista->ultimo->proximo = novo;
  }
  lista->ultimo = novo;
  return 1;
}

int desenfileirar(t_lista *lista, t_elemento elemento) {
  if (vazia_fila(lista)){
    return 0;
  }

  if (lista->primeiro->elemento.chave != elemento.chave) {
    return 0;
  }
  if (lista->primeiro == lista->ultimo) {
    lista->ultimo = NULL;
  }
  t_apontador aux = lista->primeiro;
  lista->primeiro = lista->primeiro->proximo;
  free(aux);
  return 1; // geralmente retorna um nó que acabou de remover
}
t_no frente_fila(t_lista *lista) {
  if (vazia_fila(lista)) {
    printf("Nó vazio!\n");
  }

  return *(lista->primeiro);
}

int vazia_fila(t_lista *lista) {
  if (lista->ultimo == NULL && lista->primeiro == NULL) {
    return 1; // tá vazia
  } else
    return 0; // não está vazia
}

void imprimir(t_lista *lista)
{
        t_apontador P = lista->primeiro; // p =Piliar
        while (P != NULL)
        {
                printf("%d ", P->elemento.chave);
                P = P->proximo;
        }
} 

void criar_pilha(t_lista *lista) { lista->topo = NULL; }

int empilhar(t_lista *lista, t_elemento elemento) {

  t_apontador novo;
  novo = (t_apontador)malloc(sizeof(t_no));
  if (novo == NULL)
    return ERRO_CHEIA;

  novo->elemento = elemento;
  novo->proximo = lista->topo;
  lista->topo = novo;
  return 1;
}

int desempilhar(t_lista *lista, t_elemento elemento) {
  if (vazia_pilha(lista))
    return 0;
  if (lista->topo->elemento.chave != elemento.chave) {
    return 0;
  }
  t_apontador aux = lista->topo; // topo=topo
  lista->topo = lista->topo->proximo;
  free(aux);

  return 1; // geralmente retorna um nó que acabou de remover
}
t_no topo_pilha(t_lista *lista) {
  if (vazia_pilha(lista)) {
    printf("Nó vazio!\n");
  }

  return *(lista->topo);
}

int vazia_pilha(t_lista *lista) {
  if (lista->topo == NULL) {
    return 1; // tá vazia
  } else
    return 0; // não está vazia
}

void imprimir_pilha(t_lista *lista) {
  t_apontador P = lista->topo; // p =Piliar
  while (P != NULL) {
    printf("%d ", P->elemento.chave);
    P = P->proximo;
  }
}
void libera_fila(t_lista *lista) {
  t_apontador P = lista->primeiro;
  while (P != NULL) {
    lista->primeiro = P->proximo;
    free(P);
    P = lista->primeiro;
  }
}
void libera_pilha(t_lista *lista) {
  t_apontador P = lista->topo;
  while (P != NULL) {
    lista->topo = P->proximo;
    free(P);
    P = lista->topo;
  }
}