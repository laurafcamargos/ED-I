#include <stdio.h>
#include <string.h>

#define max 200
#define SEM_ERRO 0
#define JA_EXISTE 1
#define OUTRO_ERRO 2

typedef int t_elemento;//deixar explícito q vai trabalhar com int no conjunto
typedef t_elemento t_conjunto[max];

void inicializar(t_conjunto c);
char inserir(t_elemento e, t_conjunto c);
char pertence(t_elemento e, t_conjunto c);

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
void inicializar(t_conjunto c) {
    memset(c, 0, sizeof(t_conjunto));//zera o vetor direto da memória e insere nos bits e não nos bytes
}

char inserir(t_elemento e, t_conjunto c) {
    if (!pertence(e,c)) {
        c[e] = 1;
        return SEM_ERRO;
    } else {
        return JA_EXISTE;
    }
}

char pertence(t_elemento e,t_conjunto c) {
    return c[e]; //pode fazer isso, mas nesse código ele vai retornar 0 ou 1
}