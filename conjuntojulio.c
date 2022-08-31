#include <stdio.h>
#include "cod1.h"

void inicializar(t_conjunto c){
    for(int i=0; i<max; i++){
        c[i] = 0;
    }
}
void inserir(t_elemento e, t_conjunto c){
    if(c[e] == 0){
        c[e] = 1;
        printf("Elemento %d inserido.\n", e);
    }
    else printf("O elemento %d ja existe.\n", e);
}

void pertence(t_elemento e, t_conjunto c){
    if(c[e] == 1) printf("O elemento %d pertence ao conjunto.\n", e);
    else printf("O elemento %d nao pertence ao conjunto.\n", e);
}

void remover(t_elemento e, t_conjunto c){
    if(c[e] == 1){
        c[e] = 0;
        printf("Elemento %d removido.\n", e);
    }
    else printf("O elemento %d nao pode ser removido.\n", e);
}

void uniao(t_conjunto a, t_conjunto b, t_conjunto c){
    for(int i=0; i<max; i++){
        c[i] = a[i];
        if(c[i]==0) c[i] = b[i];
    }
    for(int i=0; i<max; i++){
        if(c[i]==1) printf("%d ", i+1);
    }
}

void inter(t_conjunto a, t_conjunto b, t_conjunto c){
    for(int i=0; i<max; i++){
        if(a[i]==1 && b[i]==1){
            c[i] = 1;
        }
    }
    for(int i=0; i<max; i++){
        if(c[i]==1) printf("%d ", i+1);
    }
}

void diferenca(t_conjunto a, t_conjunto b, t_conjunto c){
    for(int i=0; i<max; i++){
        c[i] = a[i];
        if(a[i]==1 && b[i]==1){
            c[i] = 0;
        }
    }
    for(int i=0; i<max; i++){
        if(c[i]==1) printf("%d ", i+1);
    }
}

void print(t_conjunto c){
    for(int i=0; i<max; i++){
        printf("%d", c[i]);
    }
    printf("\n");
}