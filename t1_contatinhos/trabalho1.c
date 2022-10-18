#include "trabalho1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void criar(t_lista *lista)
{
  //ao criar a lista, é necessário fazer o primeiro e o último apontarem para NULL
  lista->primeiro = NULL;
  lista->ultimo = NULL;
}

int inserir(t_lista *lista, t_elemento elemento)
{
  t_apontador novo = (t_apontador)malloc(sizeof(t_no));
  t_apontador aux = (t_apontador)malloc(sizeof(t_no));
  //o ponteiro aux percorre a lista 
  //o ponteiro novo aponta para o novo elemento e faz as atribuições sem perder a lista
  if (novo == NULL)
    return ERRO_CHEIA;
  if (aux == NULL)
    return ERRO_CHEIA;

  aux = lista->primeiro;
  while (aux != NULL)
  { 
    if (strcmp(aux->elemento.nome, elemento.nome) == 0)
    //verifica se tem nome repetido na agenda, comparando cada chave da lista com 
    //a chave do elemento do parâmetro da função
    {
      printf("Contatinho ja inserido\n");
      return JA_EXISTE;
    }
    aux = aux->proximo;//o aux percorre a lista inteira
  }
  //o novo elemento sempre é inserido na primeira posição
  novo->elemento = elemento;
  novo->proximo = lista->primeiro;
  lista->primeiro = novo;

  free(aux);

  return SUCESSO;
}
t_apontador pesquisa_pos(t_lista *lista, t_chave nome)
{
  /*essa função retorna sempre a posição de um elemento
  quando o elemento não é encontrado a função retorna NULL*/
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
  /*essa função é chamada na main e realiza apenas comparações com a posição retornada
  pela função pesquisa_pos, a fim de retornar quando um contato é encontrado ou não*/
  t_apontador P = pesquisa_pos(lista, nome);

  if (P->elemento.nome == NULL)
    //quando o nome da posição retornada for NULL, significa
    //que o contato não existe na agenda
    printf("Operacao Invalida: contatinho nao encontrado\n");
  else
  {
    //quando o nome da posição retornada for diferente de NULL, significa
    //que o contato existe na agenda, e seu número pode ser acessado pelo ponteiro P
    printf("Contatinho encontrado: telefone %ld \n", P->elemento.numero);
  }
}
static int remove_posicao(t_lista *lista, t_apontador p)
{
  /*essa função só pode ser acessada dentro do arquivo trabalho1.c e ela realiza a remoção
  de um elemento em qualquer posição da lista, lidando com todos os casos especiais*/

  //caso da lista estiver vazia
  if (p == NULL)
  {
    return POS_INVALIDA;
  }

  //caso de lista unitária
  if (p == lista->primeiro && p == lista->ultimo)
  {
    criar(lista);
    free(p);
    return SUCESSO;
  }

  //caso de remover o primeiro elemento 
  if (p == lista->primeiro)
  {
    lista->primeiro = lista->primeiro->proximo;
    free(p);
    return SUCESSO;
  }

  //caso geral: percorre a lista até achar a posição da remoção e remove tomando cuidado 
  //para não perder a lista
  t_apontador aux = lista->primeiro; //necessário criar o aux para não perder a posição
  while (aux->proximo != NULL && aux->proximo != p)
  {
    aux = aux->proximo;/*percorre a lista até chegar na posição anterior 
    do elemento a ser removido*/
  }

  aux->proximo = p->proximo;//o aux passa a apontar para o próximo do elemento a ser removido
  
  //caso de remover o último elemento
  if (aux->proximo == NULL)
  {
    lista->ultimo = aux;
  }
  free(p);
  return SUCESSO;
}

void remover(t_lista *lista, t_chave nome)
{
  /*essa função é chamada na main e realiza apenas comparações com a posição retornada
  pela função pesquisa_pos e com o inteiro retornado pela função remove_posicao, a fim
  de retornar algum erro caso o contato a ser removido não seja encontrado*/
  t_apontador P = pesquisa_pos(lista, nome);
  int elemento = remove_posicao(lista, P);
  if (elemento == POS_INVALIDA)
  {
    printf("Operacao invalida: contatinho nao encontrado\n");
  }
}

void alterar(t_lista *lista, t_elemento e)
{
  /*essa função é responsaǘel por alterar o número de um contato e utiliza a função
  pesquisa_pos para buscar se o contato existe através da chave e aí então alterar
  o número pelo número inputado pelo usuário*/
  t_apontador P = pesquisa_pos(lista, e.nome);
  if (P->elemento.nome == NULL)
    printf("Operacao Invalida: contatinho nao encontrado\n");
  else
    P->elemento.numero = e.numero;
}
