#include "trabalho2.h"
#include <stdio.h>

int main() {
  t_lista pilha, fila;
  t_elemento e;
  t_apontador p;
  t_no no;
  int N, K, i, j;
  int resultA, resultB, flagpilha = 0, flagfila = 0;
  char operacao;

  criar_fila(&fila);
  criar_pilha(&pilha);
  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    scanf("%d", &K);
    for (j = 0; j < K; j++) {
      scanf(" %c %d", &operacao, &e.chave);
      switch (operacao) {
      case 'i':
        resultA = empilhar(&pilha, e);
        resultB = enfileirar(&fila, e);
        break;
      case 'r':
        resultA = desempilhar(&pilha, e);
        resultB = desenfileirar(&fila, e);
        break;
      }
      if (resultA == 0) {
        flagpilha++;
      }
      if (resultB == 0) {
        flagfila++;
      }
    }
      
    if (flagfila > 0 && flagpilha > 0) {
      printf("\nimpossivel");
    } else if (flagfila > 0) {
      printf("\npilha");
    } else if (flagpilha > 0) {
      printf("\nfila");
    } else {
      printf("\nindefinido");
    }
    libera_fila(&fila);
    libera_pilha(&pilha);
    criar_fila(&fila);
    criar_pilha(&pilha);
    flagfila = 0;
    flagpilha = 0;
  }
  return 0;
}