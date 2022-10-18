#include "trabalho2.h"
#include <stdio.h>

int main() {
  t_lista pilha, fila;
  t_elemento e;
  t_apontador p;
  t_no no;
  int N, K, i, j;
  int resultA, resultB, flagpilha = 0, flagfila = 0;
  /*as flags servirão para fazer as comparações e as atribuições do vetor 
  para printar os possíveis casos.
  os inteiros resultA e resultB receberão o escopo das funções de empilhar e enfileirar
  ou desempilhar e desenfileirar, a fim de incrementar as flags após as comparações*/

  char operacao;
  criar_fila(&fila);
  criar_pilha(&pilha);
  scanf("%d", &N);
  int vet[N];
  for (i = 0; i < N; i++) {
    scanf("%d", &K);
    for (j = 0; j < K; j++) {
      scanf(" %c %d", &operacao, &e.chave);
      switch (operacao) {
      case 'i': //inserir
        resultA = empilhar(&pilha, e);
        resultB = enfileirar(&fila, e);
        break;
      case 'r': //remover
        resultA = desempilhar(&pilha, e);
        resultB = desenfileirar(&fila, e);
        break;
      }
      if (resultA == 1) {
        //no caso do retorno da função ser 1, significa que a operação não funcionou para
        //aquele tipo de TAD
        flagpilha++;
      }
      if (resultB == 1) {
        //no caso do retorno da função ser 1, significa que a operação não funcionou para
        //aquele tipo de TAD, então incrementa-se a flag para realizar as comparações e 
        //atribuições das posições do vetor
        flagfila++;
      }
    }

    if (flagfila > 0 && flagpilha > 0) {
      //caso impossível
      vet[i] = 0;
    } else if (flagfila > 0) {
      //caso de ser possível realizar com pilha
      vet[i] = 1;
    } else if (flagpilha > 0) {
      //caso de ser possível realizar com fila
      vet[i] = 2;
    } else { 
      //caso de ser indefinido a solução 
      vet[i] = 3;
    }
    libera_fila(&fila);//é necessário liberar a fila após cada incrementação do for para que 
    //pŕoximas inserções e remoções possam ser realizadas sem erro
    libera_pilha(&pilha);//é necessário liberar a pilha após cada incrementação do for para que 
    //pŕoximas inserções e remoções possam ser realizadas sem erro
    criar_fila(&fila);//cria-se uma nova fila após liberar todos os nós 
    criar_pilha(&pilha);//cria-se uma nova pilha após liberar todos os nós 
    flagfila = 0;
    flagpilha = 0;
    //as flags voltama a ser 0 para não ocorrer erros nas próximas comparações
    //é como se o código voltasse a ser o mesmo do início a cada iteração do for
  }

  for (int k = 0; k < N; k++) {
    //for responsável por printar os N resultados
    switch (vet[k]) {
    case 0:
      printf("impossivel\n");
      break;
    case 1:
      printf("pilha\n");
      break;
    case 2:
      printf("fila\n");
      break;
    case 3:
      printf("indefinido\n");
      break;
    }
  }

  return 0;
}