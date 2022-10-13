#include "trabalho1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void criar(t_lista *lista)
{
  lista->primeiro = NULL;
  lista->ultimo = NULL;
}

int inserir(t_lista *lista, t_elemento elemento)
{
  t_apontador novo = (t_apontador)malloc(sizeof(t_no));
  t_apontador aux = (t_apontador)malloc(sizeof(t_no));

  if (novo == NULL)
    return ERRO_CHEIA;
  if (aux == NULL)
    return ERRO_CHEIA;

  aux = lista->primeiro;
  while (aux != NULL)
  { // verificar se tem nome repetido
    if (strcmp(aux->elemento.nome, elemento.nome) == 0) // ==0 → valores da string são iguais
    {
      printf("Contatinho ja inserido\n");
      return JA_EXISTE;
    }
    aux = aux->proximo;
  }
  novo->elemento = elemento;
  novo->proximo = lista->primeiro;
  lista->primeiro = novo;

  free(aux);

  return SUCESSO;
}
t_apontador pesquisa_pos(t_lista *lista, t_chave nome)
{

  t_apontador P = lista->primeiro;
  if (P == NULL)
    return NULL;
  while (P != NULL)
  {
    if (strcmp(P->elemento.nome, nome) == 0)
      return P;
    P = P->proximo;
  }
  return P;
}
void pesquisar(t_lista *lista, t_chave nome)
{
  t_apontador P = pesquisa_pos(lista, nome);

  if (P->elemento.nome == NULL)
    printf("Operacao Invalida: contatinho nao encontrado\n");
  else
  {
    printf("Contatinho encontrado: telefone %ld \n", P->elemento.numero);
  }
}
static int remove_posicao(t_lista *lista, t_apontador p)
{
  // lista vazia
  if (p == NULL)
  {
    return POS_INVALIDA;
  }

  // unico elemento
  if (p == lista->primeiro && p == lista->ultimo)
  {
    criar(lista);
    free(p);
    return SUCESSO;
  }

  // remove do inicio
  if (p == lista->primeiro)
  {
    lista->primeiro = lista->primeiro->proximo;
    free(p);
    return SUCESSO;
  }

  // remove do meio
  t_apontador aux =
      lista->primeiro; // necessário criar o aux para nao perder a posição
  while (aux->proximo != NULL && aux->proximo != p)
  {
    aux = aux->proximo; // passa a apontar pra prox posição
  }

  aux->proximo = p->proximo; // exemplo do a,b,c,tipo, vc aponta pro b com o aux, o b
                  // aponta pro c, o a prox = b prox, pois ele passa a apontar
                  // pro c, e dps da free no ponteiro do b
                  // remove do fim
  if (aux->proximo == NULL)
  {
    lista->ultimo = aux;
  }
  free(p);
  return SUCESSO;
}

void remover(t_lista *lista, t_chave nome)
{
  t_apontador P = pesquisa_pos(lista, nome);
  int elemento = remove_posicao(lista, P);
  if (elemento == POS_INVALIDA)
  {
    printf("Operacao invalida: contatinho nao encontrado\n");
  }
}

void alterar(t_lista *lista, t_elemento e)
{
  t_apontador P = pesquisa_pos(lista, e.nome);
  if (P->elemento.nome == NULL)
    printf("Operacao Invalida: contatinho nao encontrado\n");
  else
    P->elemento.numero = e.numero;
}
