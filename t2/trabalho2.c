#include "trabalho2.h"
#include <stdio.h>
#include <stdlib.h>

void criar_fila(t_lista *lista) {
  //ao criar a fila, é necessário fazer o primeiro e o último apontarem para NULL
  lista->primeiro = NULL;
  lista->ultimo = NULL;
}

int enfileirar(t_lista *lista, t_elemento elemento) {

  //essa função insere sempre novos elementos no final da fila
  t_apontador novo;
  novo = (t_apontador)malloc(sizeof(t_no));
  //o ponteiro novo aponta para o novo elemento e faz as atribuições sem perder a fila
  if (novo == NULL)
    return ERRO_CHEIA;

  novo->elemento = elemento;
  novo->proximo = NULL;

  //caso da lista estar vazia
  if (vazia_fila(lista)) {
    lista->primeiro = novo;
  } else {
    lista->ultimo->proximo = novo;
  }
  lista->ultimo = novo;
  return 0;
}

int desenfileirar(t_lista *lista, t_elemento elemento) {
  /*essa função remove elementos sempre do início da fila e trata todos 
  os casos especiais de remoção*/ 

  //caso da fila estar vazia
  if (vazia_fila(lista)){
    return 1;
  }
  //caso da remoção de um elemento que não existe
  if (lista->primeiro->elemento.chave != elemento.chave) {
    return 1;
  }
  //caso da remoção em uma fila unitária
  if (lista->primeiro == lista->ultimo) {
    lista->ultimo = NULL;
  }
  //caso geral: o apontador auxiliar recebe o primeiro elemento da fila e o lista primeiro
  //passa a apontar para o próximo.Sendo assim, é possível liberar o aux que aponta para
  //o primeiro(que será removido)
  t_apontador aux = lista->primeiro;
  lista->primeiro = lista->primeiro->proximo;
  free(aux);
  return 0;
}

int vazia_fila(t_lista *lista) {
  //função que verifica se a fila está vazia ou não
  if (lista->ultimo == NULL && lista->primeiro == NULL) {
    return 1; //está vazia
  } else
    return 0; //não está vazia
} 

void criar_pilha(t_lista *lista) { 
  //ao criar a pilha, é necessário fazer o topo apontar para NULL
  lista->topo = NULL; 
}

int empilhar(t_lista *lista, t_elemento elemento) {
  //essa função insere elementos sempre no topo da pilha
  t_apontador novo;
  novo = (t_apontador)malloc(sizeof(t_no));
  //o ponteiro novo aponta para o novo elemento e faz as atribuições sem perder a pilha
  if (novo == NULL)
    return ERRO_CHEIA;
  //o novo elemento sempre é inserido no topo da pilha
  novo->elemento = elemento;
  novo->proximo = lista->topo;
  lista->topo = novo;
  return 0;
}

int desempilhar(t_lista *lista, t_elemento elemento) {
  /*essa função realiza a remoção de um elemento sempre do topo da pilha 
  e lida com todos os casos especiais*/

  //caso da pilha estiver vazia
  if (vazia_pilha(lista))
    return 1;
  //caso da pilha ser unitária
  if (lista->topo->elemento.chave != elemento.chave) {
    return 1;
  }
  //caso geral: o apontador auxiliar recebe o topo da pilha e o lista topo
  //passa a apontar para o próximo.Sendo assim, é possível liberar o aux que aponta para
  //o topo(que será removido)
  t_apontador aux = lista->topo; 
  lista->topo = lista->topo->proximo;
  free(aux);

  return 0; 
}

int vazia_pilha(t_lista *lista) {
  //função que verifica se a pilha está vazia ou não 
  if (lista->topo == NULL) {
    return 1;//está vazia
  } else
    return 0;//não está vazia
}


void libera_fila(t_lista *lista) {
  //função que libera os nós da fila 
  t_apontador P = lista->primeiro;//P aponta para o primeiro antes de percorrer
  while (P != NULL) {
    lista->primeiro = P->proximo;//lista percorre todos os elementos da fila
    free(P);
    P = lista->primeiro;//P volta a apontar para o primeiro da fila até acabar
  }
}
void libera_pilha(t_lista *lista) {
  //função que libera os nós da pilha
  t_apontador P = lista->topo;//P aponta para o topo antes de percorrer
  while (P != NULL) {
    lista->topo = P->proximo;//lista percorre todos os elementos da pilha
    free(P);
    P = lista->topo;//P volta a apontar para o primeiro da pilha até acabar
  }
}