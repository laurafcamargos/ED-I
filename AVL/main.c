#include <stdio.h>
#include "avl.h"

int main() {
    t_avl raiz;
    t_elemento e;
	t_apontador p;
    
    criar(&raiz);

    e.chave = 5;
    inserir(&raiz, e);

    e.chave = 5;
    inserir(&raiz, e);
    e.chave = 2;
    inserir(&raiz, e);
    e.chave = 10;
    inserir(&raiz, e);
    e.chave = 1;
    inserir(&raiz, e);
    e.chave = 3;
    inserir(&raiz, e);
    e.chave = 8;
    inserir(&raiz, e);
    e.chave = 12;
    inserir(&raiz, e);
    e.chave = 6;
    inserir(&raiz, e);
    e.chave = 9;
    inserir(&raiz, e);
    e.chave = 14;
    inserir(&raiz, e);

    e= pesquisar(&raiz, 10);    
    int i = e.chave;
    printf("%d\n",i);
    e=pesquisar(&raiz, 9);
    printf("%d\n",i);
    remover(&raiz, 10);
    e= pesquisar(&raiz, 10);
    printf("%d\n",i);
    e=pesquisar(&raiz, 9);
    printf("%d\n",i);
 	imprime(&raiz);
	
	return 0;
}