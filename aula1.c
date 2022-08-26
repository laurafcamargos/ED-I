#include <stdio.h>
#include <string.h>
#include "aula1.h"

int main() {
    t_conjunto meu_conjunto;
    t_elemento meu_elemento;
    inicializar(meu_conjunto);
    
    meu_elemento = 45;
    printf("pertence %d\n",pertence(meu_elemento,meu_conjunto));
    printf("insere %d %d\n",meu_elemento,inserir(meu_elemento,meu_conjunto));
    printf("insere %d %d\n",meu_elemento,inserir(meu_elemento,meu_conjunto));

    meu_elemento = 5;
    printf("pertence %d\n",pertence(meu_elemento,meu_conjunto));
    printf("insere %d %d\n",meu_elemento,inserir(meu_elemento,meu_conjunto));

    meu_elemento = 45;
    printf("pertence %d\n",pertence(meu_elemento,meu_conjunto));

    meu_elemento = 4;
    printf("pertence %d\n",pertence(meu_elemento,meu_conjunto));

    meu_elemento = 5;
    printf("pertence %d\n",pertence(meu_elemento,meu_conjunto));
    

    return 0;
}
