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
t_elemento pesquisar(t_lista *lista,t_chave t_chave);
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