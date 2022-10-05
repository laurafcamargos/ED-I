#ifndef TRABALHO1_H
#define TRABALHO1_H
#define JA_EXISTE -2
#define POS_INVALIDA -1
#define ERRO_CHEIA 0
#define SUCESSO 1

typedef char t_chave[12];

typedef struct
{
  t_chave nome;
  long int numero;
} t_elemento;

typedef struct t_no *t_apontador;
typedef struct t_no
{ // cada nó contém um objeto de determinado tipos e o
  // endereço da célula seguinte
  t_elemento elemento;
  t_apontador proximo;
} t_no;

typedef struct
{
  t_apontador primeiro, ultimo;
} t_lista;

void criar(t_lista *lista);
int inserir(t_lista *lista, t_elemento elemento);
void remover(t_lista *lista, t_chave nome);
t_apontador pesquisa_pos(t_lista *lista, t_chave nome); // devolve o apontador
void pesquisar(t_lista *lista, t_chave nome);           // devolve o numero
void alterar(t_lista *lista, t_elemento elemento);
#endif
