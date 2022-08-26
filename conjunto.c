#include "aula1.h"
#include <stdio.h>
#include <string.h>

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