#ifndef TRABALHO2_H
#define TRABALHO2_H

#define NO_VAZIO -2
#define ERRO_CHEIA -1
#define NAO_ENCONTROU 0
#define SUCESSO 1

typedef int t_chave;

typedef struct
{
	t_chave chave;
} t_elemento;

typedef struct t_no *t_apontador;
typedef struct t_no
{ // cada nó contém um objeto de determinado tipos e o endereço da célula seguinte
	t_elemento elemento;
	t_apontador proximo;
} t_no;

typedef struct
{
	t_apontador primeiro, ultimo;
  t_apontador topo;
} t_lista;

void criar_fila(t_lista *lista);
int enfileirar(t_lista *lista, t_elemento elemento);
int desenfileirar(t_lista *lista,t_elemento elemento);
t_no topo_fila(t_lista *lista);
int vazia_fila(t_lista *lista);
void criar_pilha(t_lista *lista);
int empilhar(t_lista *lista, t_elemento elemento);
int desempilhar(t_lista *lista, t_elemento elemento);
t_no topo_pilha(t_lista *lista);
int vazia_pilha(t_lista *lista);
void libera_pilha(t_lista *lista);
void libera_fila(t_lista *lista);
void imprimir(t_lista *lista);
void imprimir_pilha(t_lista *lista);

#endif

