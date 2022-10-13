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
  int vet[N];
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
      // printf("\nimpossivel");
      vet[i] = 0;
    } else if (flagfila > 0) {
      // printf("\npilha");
      vet[i] = 1;
    } else if (flagpilha > 0) {
      // printf("\nfila");
      vet[i] = 2;
    } else {
      // printf("\nindefinido");
      vet[i] = 3;
    }
    libera_fila(&fila);
    libera_pilha(&pilha);
    criar_fila(&fila);
    criar_pilha(&pilha);
    flagfila = 0;
    flagpilha = 0;
  }

  for (int k = 0; k < N; k++) {
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