#ifndef LISTADINAM_H
#define LISTADINAM_H

#define JA_EXISTE -2
#define POS_INVALIDA -1
#define ERRO_CHEIA 0
#define SUCESSO 1

typedef int t_chave;

typedef struct {
	t_chave chave;
	//char nome[50];
} t_elemento;

typedef struct t_no *t_apontador;
typedef struct t_no { //cada nó contém um objeto de determinado tipos e o endereço da célula seguinte
	t_elemento elemento;
	t_apontador proximo;
} t_no;

typedef struct {
	t_apontador primeiro,ultimo;
} t_lista;

int criar(t_lista *lista);
int inserir(t_lista *lista, t_elemento elemento);
int remover(t_lista *lista, t_chave chave);
t_apontador pesquisar(t_lista *lista, t_chave chave);
int alterar(t_lista *lista, t_elemento novo_elemento);
int vazia(t_lista *lista);
int cheia(t_lista *lista);
void imprimir(t_lista *lista);
void reverse(t_lista *lista);
int tamanho(t_lista *lista);

#endif

