#include "listaestat.h"
#include <stdio.h>

static int RemovePosicao(t_lista *lista, t_apontador P);

void CriaLista(t_lista *lista) {
	lista->ultimo = -1;
}

int InsereLista(t_lista *lista, t_elemento elemento) {

	if (ListaCheia(lista)) {
		printf("Deu ruim... tá lotado!\n");
		return LISTA_CHEIA;
	}

	lista->ultimo++;
	lista->elemento[lista->ultimo] = elemento;

}

int RemoveLista(t_lista *lista, t_chave chave) {
	RemovePosicao(lista, PesquisaLista(lista, chave));
}

static int RemovePosicao(t_lista *lista, t_apontador P) {
	t_apontador i;
	if (P < 0 || P > lista->ultimo) {
		printf("Posicao invalida\n");
		return POS_INVALIDA;
	}
	for (i = P; i < lista->ultimo; i++)
		lista->elemento[i] = lista->elemento[i+1];
	lista->ultimo--;
}

t_apontador PesquisaLista(t_lista *lista, t_chave chave) {
	t_apontador i;
	for (i=0; i <= lista->ultimo; i++) {
		if (lista->elemento[i].chave == chave)
			return i;
	}
	return NAO_ENCONTROU;
}

int ListaVazia(t_lista *lista) {
	if(lista->ultimo == -1) {
        return 1;
    }
    else return 0;
}
int ListaCheia(t_lista *lista) {
	if(lista->ultimo == MAXTAM - 1) {
        return 1;
    }
    else return 0;
}

void ImprimeLista(t_lista *lista)  {
        t_apontador i;
	printf("Lista:");
        for (i=0; i <= lista->ultimo; i++) {
                printf(" %d", lista->elemento[i].chave);
        }
	printf("\n\n");
}
