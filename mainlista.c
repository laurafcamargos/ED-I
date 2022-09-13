#include <stdio.h>
#include "Lista.h"
void reverse(t_lista *lista) {
    t_apontador P = lista->primeiro; //p =auxiliar
	if(lista->primeiro == NULL)
		printf("Lista vazia\n");
        if (lista->primeiro->proximo == NULL)
        {
            printf("Lista unitária\n");
        }
        t_apontador anterior = NULL;
        t_apontador proximo = lista->primeiro;
        do  
        {
            proximo = lista->primeiro->proximo;
            lista->primeiro->proximo = anterior;//inverter o prox
            anterior = lista ->primeiro;//andar com o ant pra frente
            lista->primeiro = proximo;
            }
        }while(proximo != NULL);
        lista->primeiro = anterior;
}

int main() {
    t_lista l;
    t_elemento e;
	t_apontador p;

    criar(&l);

    e.chave = 5;
    inserir(&l, e);

    e.chave = 3;
    inserir(&l, e);

    e.chave = 7;
    inserir(&l, e);

    imprimir(&l);
	
	return 0;
}