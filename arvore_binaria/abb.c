#include "abb.h"
#include <stdio.h>
#include <stdlib.h>

int criar(t_abb *abb) {
	*abb = NULL;
}
int static criar_raiz(t_abb *abb, t_elemento elemento){

     *abb = (t_abb) malloc(sizeof(t_no));
    if(*abb == NULL){
        return ERRO_CHEIA;
    }

    (*abb)->dir = NULL;
    (*abb)->esq = NULL;
    (*abb)->elemento = elemento;
    
    return SUCESSO;
}
int inserir(t_abb *abb, t_elemento elemento) {

    //caso a arvore esteja vazia
    if(*abb == NULL){
        return criar_raiz(abb,elemento);
    }

    //caso a chave da raiz seja igual a chave do elemento
    if((*abb)->elemento.chave == elemento.chave){
        return JA_EXISTE;
    }else{
		if (elemento.chave < (*abb)->elemento.chave) {
			return inserir(&(*abb)->esq->elemento,elemento);
		}
		if (elemento.chave > (*abb)->elemento.chave) {
			return inserir(&(*abb)->dir->elemento, elemento);
		}
		return SUCESSO;
	}
}

 t_elemento pesquisar(t_abb *abb, t_chave chave) {
    t_apontador P;

    //caso a arvore esteja vazia
    if(*abb == NULL){
        //return NULL;
    }

    //caso a chave da raiz seja igual a chave do elemento
    if((*abb)->elemento.chave == chave){
        return P->elemento;
    }

}
static void buscaMaiorEsqETroca(t_abb *raiz, t_abb *subarv) {
	if((*subarv)->dir == NULL) {

		t_apontador P;
		(*raiz)->elemento = (*subarv)->elemento;

		P = *subarv;
		*subarv = (*subarv)->esq;
		free(P);

	}else{
		buscaMaiorEsqETroca(raiz, &(*subarv)->dir);
	}
}

int remover(t_abb *abb, t_chave chave) {
	t_apontador p;
	//nao achou
	if((*abb) == NULL) 
	return NAO_ENCONTROU;

	//direita ou esquerda
	if (chave > (*abb)->elemento.chave)	{
		return remover(&(*abb)->dir,chave);
	}
	else if (chave < (*abb)->elemento.chave)	{
		return remover(&(*abb)->esq,chave);
	}
	//se passou, é porque achou a chave
	if((*abb)->esq == NULL && (*abb)->dir == NULL) { //caso 1: remover o nó folha
		p = *abb;
		*abb = NULL;//subiu o abb 
		free(p);
	}else if((*abb)->esq == NULL) { //caso 2: remover o nó da direita
		p = *abb;
		*abb = (*abb)->dir;
		free(p);
	}else if((*abb)->dir == NULL) { //caso 2: remover o nó da esquerda
		p = *abb;
		*abb = (*abb)->esq;
		free(p);
	}else { //caso 3: remover um nó que tem dois filhos
		buscaMaiorEsqETroca(abb,(*abb)->esq);
	}

}