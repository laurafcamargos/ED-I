#ifndef SUM_H
#define SUM_H

#include <stdio.h>
#include <stdlib.h>

typedef int t_elemento;
typedef struct t_hash *t_apontador;

typedef struct t_hash
{ // cada nó contém um objeto de determinado tipo e o
  // endereço da célula seguinte
  t_elemento elemento;
  t_apontador proximo;
} t_hash;

int consulta(int* vetor, t_hash **tabela, int n, int soma);//função que busca as somas 
void inserir(t_hash **tabela, int elemento, int n);//função que insere o elemento na lista dinâmica
void apaga_tabela(t_hash **tabela, int n);//libera memória da lista dinâmica

//finaliza a header
#endif