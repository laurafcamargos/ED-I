#ifndef LISTAESTATICA_H
#define LISTAESTATICA_H

#define MAXTAM 1000

#define SEM_ERRO 0
#define POS_INVALIDA -1
#define NAO_ENCONTROU -2
#define LISTA_CHEIA -3

typedef int t_chave;
typedef int t_apontador;

typedef struct {
	t_chave chave;
	//char nome[50];
} t_elemento;

typedef struct {
	t_elemento elemento[MAXTAM];
	t_apontador ultimo;
} t_lista;

void CriaLista(t_lista *L);
int InsereLista(t_lista *L, t_elemento elemento);
int RemoveLista(t_lista *L, t_chave C);
t_apontador PesquisaLista(t_lista *L, t_chave C);

int ListaVazia(t_lista *L);
int ListaCheia(t_lista *L);

void ImprimeLista(t_lista *L);

#endif