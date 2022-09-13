#include <stdio.h>
#include <string.h>
#include "Lista.h"

int criar(t_lista *lista) {
    lista->ultimo = -1;

}
int inserir(t_lista *lista, t_elemento elemento) {
    if (cheia(lista))
        return ERRO_CHEIA;
    if (pesquisa(lista,elemento))
        return JA_EXISTE;
    lista->ultimo++;//referência ao ultimo que está em uma struct de ponteiro, usa a setinha
    lista->elementos[lista->ultimo] = elemento;//++ antes: primeiro incrementa e dps atribui o elemento

    return SUCESSO;
}
int remover(t_lista *lista,t_elemento elemento);

static t_aṕontador pesquisa_pos(t_lista *lista,t_chave t_chave) {
    t_apontador P = lista -> primeiro;
    if (P == NULL)
    {
        return NULL; // lista vazia ou ta procurando algum elemento que nao tem
    }
    while (P != NULL)
    {
        if (P->elemento.chave == chave;
            return P;
        P = P->Proximo;
    }
    return NULL;
}
t_elemento pesquisar(t_lista *lista, t_chave chave) {
	return lista->elementos[pesquisa_pos(lista, chave)];
}

int alterar(t_lista *lista,t_elemento novo_elemento);
int excluir(t_lista *lista);
int vazia(t_lista *lista) {
    if(lista->ultimo == -1)
    return 1;
    else
    return 0;
}
int cheia(t_lista *lista) {
    if(lista->ultimo == MAX_TAM-1)
    return 1;
    else
    return 0;
}
]