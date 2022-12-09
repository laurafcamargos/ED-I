#include "contatinho.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int max(int a, int b) {
	return a > b ? a : b; //função retorna o maior valor entre o inteiro a e b	
}						 //auxilia a calcular o fator de balanceamento da árvore

static void rotacao_esq(t_avl *avl) {

	t_apontador j, B;

	//filho à esq da raiz
	j = (*avl)->esq;
	//filho à esq à dir da raiz
	B = j->dir;

	//a sub-arv muda de pai pela antiga raiz
	(*avl)->esq = B;
	//aux passa a ser a raiz
	j = (*avl);

	(*avl)->altura = max(retornar_altura(&(*avl)->esq),retornar_altura(&(*avl)->dir)) + 1;

	j->altura = max(retornar_altura(&j->esq),retornar_altura(&j->dir)) + 1;

	//mudar o ponteiro "de cima"
	*avl = j;
}

static void rotacao_dir(t_avl *avl) {

	t_apontador j, B;

	//filho à dir da raiz
	j = (*avl)->dir;
	//filho à dir à esq da raiz
	B = j->esq;

	//a sub-arv muda de pai pela antiga raiz
	(*avl)->dir = B;
	//aux passa a ser a raiz
	j = (*avl);

	(*avl)->altura = max(retornar_altura(&(*avl)->esq),retornar_altura(&(*avl)->dir)) + 1;

	j->altura = max(retornar_altura(&j->esq),retornar_altura(&j->dir)) + 1;

	//mudar o ponteiro "de cima"
	*avl = j;

}

static void rotacao_dir_esq(t_avl *avl) {

	//rotacionar à direita
	rotacao_dir(&(*avl)->dir);
	//rotacionar à esquerda
	rotacao_esq(avl);
}

static void rotacao_esq_dir(t_avl *avl) {

	rotacao_esq(&(*avl)->esq);
	rotacao_dir(avl);

}

void criar(t_avl *avl) {
	//inicializa a árvore
	*avl = NULL;
}

int static criar_raiz(t_avl *avl, t_elemento elemento){
	//cria a raiz da árvore
	*avl = (t_avl) malloc(sizeof(t_no));
	if (*avl == NULL)
		return ERRO_CHEIA;
	
	(*avl)->esq = NULL;
	(*avl)->dir = NULL;
	(*avl)->elemento = elemento;
	(*avl)->altura = 0;

	return SUCESSO;

}

int retornar_altura(t_avl *avl) {
	//função que auxilia no cálculo do balanceamento da árvore
    if ((*avl) == NULL)
        return -1;
    else
        return (*avl)->altura;
}

int checar_fb(t_avl *avl) {
	//verifica se a árvore está balanceada
    if ((*avl) == NULL)
        return 0;
    else 
        return retornar_altura(&(*avl)->esq) - retornar_altura(&(*avl)->dir);
}

int inserir(t_avl *avl, t_elemento elemento) {
	
	if ((*avl) == NULL) {
		return criar_raiz(avl, elemento);
	}

	//não permite que contatos com o mesmo nome sejam inseridos
	if (ComparaStrings((*avl)->elemento.nome, elemento.nome) == 0) { 
		printf("Contatinho ja inserido\n");
	} else {
		//a função ComparaStrings retorna o escopo que permite a comparação
		//entre o nome do contato a ser inserido e o nome da raiz
		if (ComparaStrings((*avl)->elemento.nome, elemento.nome) < 0) {
			inserir(&(*avl)->esq, elemento); //insere contato à esquerda, recursivamente
			(*avl)->altura = max((*avl)->altura,retornar_altura(&(*avl)->esq) + 1);
		} else {
			inserir(&(*avl)->dir, elemento);//insere contato à direita, recursivamente
			(*avl)->altura = max((*avl)->altura,retornar_altura(&(*avl)->dir) + 1);
		}

	}  
	int fb = checar_fb(avl);
	//após a inserção, é preciso verificar o fator de balanceamento
	if (fb > 1) { //ocorre do lado esquerdo da avl
		//2 casos
		int fb_filho = checar_fb(&(*avl)->esq);
		if (fb_filho >= 0) {
			rotacao_dir(avl); //rotação simples à direita
		} else {
			rotacao_esq_dir(avl);//rotação dupla à direita
		}

	} else if (fb < -1) { //ocorre do lado esquerdo da avl

		int fb_filho = checar_fb(&(*avl)->dir);
		if (fb_filho <= 0) {
			rotacao_esq(avl);//rotação simples à esquerda
		} else {
			rotacao_dir_esq(avl);//rotação dupla à esquerda
		}
	}
}

int pesquisar(t_avl *avl, t_chave chave) {
	 /*essa função realiza a busca dos contatos em O(logn),realiza a comparação das strings
	 e retorna que o contato não foi encontrado ou caso encontrado, o numero do contato buscado*/
	if ((*avl)->elemento.nome == NULL) {
		//quando o nome da posição retornada for NULL, significa
    	//que o contato não existe na agenda
		printf("Operacao Invalida: contatinho nao encontrado\n");
		return -1;
	}

	if (ComparaStrings((*avl)->elemento.nome, chave) == 0) {
		//quando o nome da posição retornada for diferente de NULL, significa
    	//que o contato existe na agenda
		printf("Contatinho encontrado: telefone %ld \n", (*avl)->elemento.numero);  
	} else {
		//as comparações permitem que a busca aconteça recursivamente 
		//até encontrar o contato buscado
		if (ComparaStrings(chave, (*avl)->elemento.nome) < 0) {
			return pesquisar(&(*avl)->esq, chave);
		} else {
			return pesquisar(&(*avl)->dir, chave);
		}
	}
}

static void buscaMaiorEsqETroca(t_avl *raiz, t_avl *subarv) {

	if ((*subarv)->dir == NULL) {

		t_apontador p;

		(*raiz)->elemento = (*subarv)->elemento;

		p = *subarv;
		*subarv = (*subarv)->esq;
		free(p);

	} else {
		buscaMaiorEsqETroca(raiz, &(*subarv)->dir);		
	}
}

int remover(t_avl *avl, t_chave chave) {
	/*essa função realiza a busca do do contato a ser removido em O(logn), a fim
  	de retornar algum erro caso o contato a ser removido não seja encontrado*/

	//nao achou a chave 
	if ((*avl)->elemento.nome == NULL) {
		printf("Operacao invalida: contatinho nao encontrado\n");
		return -1;
	}
	//busca recursivamente: direita ou esquerda
	if (ComparaStrings(chave, (*avl)->elemento.nome) > 0) {
		return remover(&(*avl)->dir, chave);
	} else if (ComparaStrings(chave, (*avl)->elemento.nome) < 0) {
		return remover(&(*avl)->esq, chave);
	}
	t_apontador p;

	//trata os casos de remoção, que são 4:
	if ((*avl)->esq==NULL && (*avl)->dir==NULL) { //caso 1 (folha)
		p = *avl;
		*avl = NULL;
		free(p);
	} else if ((*avl)->esq==NULL) { //caso 2 (remoção de nó com um filho na dir)
		p = *avl;
		*avl = (*avl)->dir;
		free(p);
	} else if ((*avl)->dir==NULL) { //caso 3 (remoção de nó com um filho na esq)
		p = *avl;
		*avl = (*avl)->esq;
		free(p);
	} else { //caso 4: remoção de um nó com dois filhos, utiliza função auxiliar
		buscaMaiorEsqETroca(avl, &(*avl)->esq);
	}
	return SUCESSO;
}

int alterar(t_avl *avl, t_elemento novo) {
	/*essa função é responsável por alterar o número de um contato a partir da
	comparação entre as chaves e então a chamada da função de busca*/
	if ((*avl)->elemento.nome == NULL) {
		printf("Operacao Invalida: contatinho nao encontrado\n");
	}
	if (ComparaStrings((*avl)->elemento.nome, novo.nome) == 0) {
		(*avl)->elemento.numero = novo.numero;
	} else {
		if (ComparaStrings(novo.nome, (*avl)->elemento.nome) < 0) {
			return pesquisar(&(*avl)->esq, novo.nome);
		} else {
			return pesquisar(&(*avl)->dir, novo.nome);
		}
	}
}

void ApagaArvore(t_avl *avl) {
	//essa função libera os nós da avl seguindo o percurso pós-ordem, ou seja, visita 
	//o nó somente depois de acessar seus filhos, com o intuito de não "perder" o acesso
	if((*avl) != NULL) {
		ApagaArvore(&(*avl)->esq);
		ApagaArvore(&(*avl)->dir);
		free(*avl);
	}
}

int ComparaStrings(char *a, char *b) {
	//essa função compara as strings, char por char, com o intuito de tentar ordenar os nomes   
	//e serve de auxílio em quase todas as funções do programa
  	int i,str1,str2,menor;
	str1 = strlen(a); //pega o tamanho da string a
  	str2 = strlen(b); //pega o tamanho da string b

  	if (str1 < str2) 
    	menor = str1;
  	else
    	menor = str2;
	//essas condições auxiliam a determinar o critério de parada do for
  	for (i = 0; i < menor; i++) {

    	if (a[i] < b[i]) 
      		return 1; //a string 'a' vem antes da 'b' na ordem alfabética
    
    	if (a[i] > b[i]) 
      		return -1; //a string 'b' vem antes da 'a' na ordem alfabética
    }
 
 	if (str1 == str2) 
    	return 0; //as strings são iguais
}