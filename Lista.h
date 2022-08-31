#define LISTA_H
#ifndef LISTA_H

#define MAX_TAM 100

typedef int t_chave;
typedef int t_apontador;

typedef struct {
    t_chave chave;
    char nome[50];
} t_elemento;

typedef struct {
    t_elemento elementos[MAX_TAM];
    t_apontador ultimo;
} t_lista;

int criar(t_lista *lista);
int inserir(t_lista *lista, t_elemento elemento);
int remover(t_lista *lista,t_elemento elemento);
t_elemento pesquisar(t_lista *lista,t_chave t_chave);
int alterar(t_lista *lista,t_elemento novo_elemento);
int excluir(t_lista *lista);
int vazia(t_lista *lista);
int cheia(t_lista *lista);
 #endif