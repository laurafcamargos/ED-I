#include <stdio.h>
#include <stdlib.h>
#include "sum.h"

int main(){
    int n, m, i, aux;

    scanf("%d", &n); //número de elementos do vetor
    t_hash *tabela[n]; //vetor de ponteiros do tipo hash
    int vetor[n];

     for(i=0;i<n;i++){
        tabela[i] = NULL; //inicializa a lista dinâmica
    }

    for(i=0;i<n;i++){
        scanf("%d", &vetor[i]);
        inserir(tabela, vetor[i], n);
    }

    scanf("%d", &m); //número de consultas a serem feitas

    for(i = 0; i < m; i++){

        scanf("%d", &aux);

        if(consulta(vetor,tabela,n,aux) == 1){
            printf("S\n");
        }else{
            printf("N\n");
        }
    }
    apaga_tabela(tabela,n);

    return 0;
}