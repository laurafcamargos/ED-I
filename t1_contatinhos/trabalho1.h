#ifndef TRABALHO1_H
#define TRABALHO1_H
#define JA_EXISTE -2
#define POS_INVALIDA -1
#define ERRO_CHEIA 0
#define SUCESSO 1

//estrutura do identificador do elemento
typedef char t_chave[12];

//estrutura do tipo elemento
typedef struct
{
  t_chave nome;
  long int numero;
} t_elemento;

//estrtura do apontado que percorre os nós
typedef struct t_no *t_apontador;

//estrutura do tipo nó
typedef struct t_no
{ // cada nó contém um objeto de determinado tipo e o
  // endereço da célula seguinte
  t_elemento elemento;
  t_apontador proximo;
} t_no;

//estrutura do tipo lista
typedef struct
{
  t_apontador primeiro, ultimo;
} t_lista;

void criar(t_lista *lista);//cria a lista
int inserir(t_lista *lista, t_elemento elemento);//insere novos contatos
void remover(t_lista *lista, t_chave nome);//remove contatos já existentes
t_apontador pesquisa_pos(t_lista *lista, t_chave nome); //devolve a posição buscada
void pesquisar(t_lista *lista, t_chave nome);//printa o telefone quando encontrado
void alterar(t_lista *lista, t_elemento elemento);//altera o contato encontrado

#endif
