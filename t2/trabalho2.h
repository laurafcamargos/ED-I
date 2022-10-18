#ifndef TRABALHO2_H
#define TRABALHO2_H
#define ERRO_CHEIA -1

//estrutura do identificador do elemento
typedef int t_chave;

//estrutura do tipo elemento
typedef struct
{
	t_chave chave;
} t_elemento;

//estrutura do tipo apontador que percorre os nós
typedef struct t_no *t_apontador;
//estrutura do tipo nó
typedef struct t_no
{ //cada nó contém um objeto de determinado tipos e o endereço da célula seguinte
	t_elemento elemento;
	t_apontador proximo;
} t_no;

//estrutura do tipo lista
typedef struct
{
	t_apontador primeiro, ultimo;
  t_apontador topo;
} t_lista;

void criar_fila(t_lista *lista);//cria a fila 
int enfileirar(t_lista *lista, t_elemento elemento);//insere novos elementos na fila
int desenfileirar(t_lista *lista,t_elemento elemento);//remove elementos existentes da fila
int vazia_fila(t_lista *lista);//verifica se a fila está vazia ou não
void libera_fila(t_lista *lista);//libera os nós da fila

void criar_pilha(t_lista *lista);//cria a pilha
int empilhar(t_lista *lista, t_elemento elemento);//insere novos elementos na pilha
int desempilhar(t_lista *lista, t_elemento elemento);//remover elementos existentes da pilha
int vazia_pilha(t_lista *lista);//verifica se a pilha está vazia ou não
void libera_pilha(t_lista *lista);//libera os nós da pilha

#endif

