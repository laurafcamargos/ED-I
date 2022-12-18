#ifndef CONTATINHO_H
#define CONTATINHO_H

#define JA_EXISTE -2
#define ERRO_CHEIA 0
#define SUCESSO 1

//estrutura do identificador do elemento
typedef char t_chave[50];

//estrutura do tipo elemento
typedef struct {
	t_chave nome;
	long int numero;
} t_elemento;

//estrtura do apontado que percorre os nós
typedef struct t_no *t_apontador;

//estrutura do tipo nó
// cada nó contém um objeto de determinado tipo e o
// endereço da célula seguinte
typedef struct t_no {
	t_elemento elemento;
	t_apontador esq, dir;
	int altura; 
} t_no;

//estrutura do tipo AVL
typedef t_apontador t_avl;


void criar(t_avl *avl);//cria a árvore
int retornar_altura(t_avl *avl);
int checar_fb(t_avl *avl);
int inserir(t_avl *avl, t_elemento elemento, int *idxResp, int respostas[100000]);//insere novos contatos
int pesquisar(t_avl *avl, t_chave nome, int *idxResp, int respostas[100000], int *idxTel, long int telefones[100000]);//devolve a posição buscada
int remover(t_avl *avl, t_chave nome, int *idxResp, int respostas[100000]);//remove contatos já existentes
int alterar(t_avl *avl, t_elemento novo, int *idxResp, int respostas[100000]);//altera o contato encontrado
void ApagaArvore(t_avl *avl);//libera a memória, apagando os nós da árvore
int ComparaStrings(char *str, char *ing);//compara as strings char a char, auxiliando a pesquisa dos contatos
#endif