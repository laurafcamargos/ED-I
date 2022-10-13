#include <stdio.h>
#include <string.h>
#ifndef CONJUNTO_H
#define CONJUNTO_H

#define max 200
#define SEM_ERRO 0
#define JA_EXISTE 1
#define OUTRO_ERRO 2

typedef int t_elemento;//deixar explícito q vai trabalhar com int no conjunto
typedef t_elemento t_conjunto[max];

void inicializar(t_conjunto c); //função que zera todos os valores do vetor
char inserir(t_elemento e, t_conjunto c);
void pertence(t_elemento e, t_conjunto c);
void remover(t_elemento e, t_conjunto c);
void uniao(t_conjunto a, t_conjunto b, t_conjunto c);
void inter(t_conjunto a, t_conjunto b, t_conjunto c);
void diferenca(t_conjunto a, t_conjunto b, t_conjunto c);
void print(t_conjunto c);

#endif