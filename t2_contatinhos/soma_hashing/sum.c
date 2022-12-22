#include <stdio.h>
#include <stdlib.h>
#include "sum.h"

int consulta(int* vetor, t_hash **tabela, int n, int soma){
    int i,dif, res;
    t_apontador aux,P; //auxiliares para percorrer a lista dinâmica durante a busca

    for(i = 0; i < n; i++){
        aux = tabela[i];
        while(aux != NULL){
            dif = (soma - aux->elemento); //ex: dif = 133 - 10 = 123
            res = dif % n; //123 % n já da a posição a se procurar caso exista
            if(res >= 0){
               P = tabela[res]; //recebe o elemento que completa a soma
            while(P != NULL) {
                    if(P->elemento == dif){
                        return 1;
                    }
                   P = P->proximo; 
                }
            }
            aux = aux->proximo; //percorre até achar
        }
    } 
    return 0;
}         

void inserir(t_apontador *tabela, int elemento, int n){

   t_apontador novo; //o apontador novo aponta para o elemento a ser guardado na tabela e faz as atribuições sem perder a lista
	novo = (t_apontador) malloc(sizeof(t_hash));

    int indice = elemento % n; //função hashing modular
    novo->elemento = elemento;
    novo->proximo = tabela[indice]; //aponta pra void
    //o novo elemento sempre é inserido na sua posição modular da lista
    tabela[indice] = novo; 
}

void apaga_tabela(t_hash **tabela,int n) {
    t_apontador aux,aux2;
    for (int i = 0; i < n; i++){
        aux = tabela[i];
        while (aux && aux->proximo != NULL){
            aux2 = aux->proximo;
            aux->proximo = aux2->proximo;
            free(aux2);
        }
        free(aux);
    }
}