#include <stdio.h>
#include <stdlib.h>

typedef struct t_hash *t_apontador;
typedef struct t_hash
{ // cada nó contém um objeto de determinado tipo e o
  // endereço da célula seguinte
  int elemento;
  t_apontador proximo;
} t_hash;



int consulta(int* vetor, t_hash **tabela, int n, int soma);
void inserir(t_hash **tabela, int elemento, int n);
void apagar(t_hash **tabela, int n);


int consulta(int* vetor, t_hash **tabela, int n, int soma){
    int i,dif, res;
    t_apontador aux,P;

    for(i = 0; i < n; i++){
        aux = tabela[i];
        while(aux != NULL){
            dif = (soma - aux->elemento);
            res = dif % n;
            if(res >= 0){
               P = tabela[res];
            while(P != NULL) {
                    if(P->elemento == dif){
                        return 1;
                    }
                   P =P->proximo;
                }
            }
            aux = aux->proximo;
        }
    } 
    return 0;
}         

void inserir(t_apontador *tabela, int elemento, int n){

   t_apontador novo; //o apontador novo aponta para o elemento a ser guardado na tabela e faz as atribuições sem perder a lista
	novo = (t_apontador) malloc(sizeof(t_hash));

    int indice = elemento % n; //função hashing modular
    novo->elemento = elemento;
    novo->proximo = tabela[indice];
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

int main()
{
    int n, m, i, aux;

    scanf("%d", &n);
    t_hash *tabela[n];
    int vetor[n];

     for(i=0;i<n;i++){
        tabela[i] = NULL; //inicializa a lista dinâmica
    }

    for(i=0;i<n;i++){
        scanf("%d", &vetor[i]);
        inserir(tabela, vetor[i], n);
    }

    scanf("%d", &m);

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