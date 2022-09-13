#include <stdio.h>
#include <string.h>
#include "aula1.h"

int main() {
    t_elemento meu_elemento;
    t_conjunto meu_conjunto;
    t_conjunto a,b,c;
    inicializar(meu_conjunto);

    meu_elemento = 5;
    inserir(meu_elemento, meu_conjunto);
    meu_elemento = 10;
    inserir(meu_elemento, meu_conjunto);
    meu_elemento = 5;
    pertence(meu_elemento, meu_conjunto);
    meu_elemento = 15;
    pertence(meu_elemento, meu_conjunto);
    meu_elemento = 15;
    remover(meu_elemento, meu_conjunto);
    meu_elemento = 7;
    remover(meu_elemento, meu_conjunto);
    meu_elemento = 5;
    remover(meu_elemento, meu_conjunto);
    meu_elemento = 5;
    pertence(meu_elemento, meu_conjunto);

    inicializar(a);
    inicializar(b);
    inicializar(c);
    printf("Uniao:\n");
    a[0] = 1; a[1] = 1; a[2] = 1; b[1] = 1; b[3] = 1;//A={a,b,c} B={b,d}
    //a=1 b=2 c=3 d=4
    uniao(a,b,c);
    printf("\n");

    inicializar(a);
    inicializar(b);
    inicializar(c);
    printf("Intersecao:\n");
    a[0] = 1; a[1] = 1; a[2] = 1; b[1] = 1; b[3] = 1;
    inter(a,b,c);
    printf("\n");

    inicializar(a);
    inicializar(b);
    inicializar(c);
    printf("Diferenca:\n");
    a[0] = 1; a[1] = 1; a[2] = 1; b[1] = 1; b[3] = 1;
    diferenca(a,b,c);
    printf("\n");

    return 0;
}

