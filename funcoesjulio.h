#ifndef COD1_H
#define COD1_H
#define max 20
typedef int t_elemento;
typedef t_elemento t_conjunto[max];

void inicializar(t_conjunto c);
void inserir(t_elemento e, t_conjunto c);
void remover(t_elemento e, t_conjunto c);
void pertence(t_elemento e, t_conjunto c);
void uniao(t_conjunto a, t_conjunto b, t_conjunto c);
void inter(t_conjunto a, t_conjunto b, t_conjunto c);
void diferenca(t_conjunto a, t_conjunto b, t_conjunto c);
void print(t_conjunto c);

#endif