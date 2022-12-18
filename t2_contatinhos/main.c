#include "contatinho.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  t_avl A;
  t_elemento e;
  t_apontador P;

  /*
  Operações
  0 - sair
  I - inserir
  R - remover
  A - alterar
  P - pesquisar
  */

  /*
    Operacao invalida: 0
    Contatinho ja inserido: 1
    Contatinho nao encontrado: 2
    Contatinho encontrado: telefone: 3
    Operacao invalida: contatinho nao encontrado: 4
  */

  int respostas[100000],
      idxResp = 0; // vetor que armazena as respostas e indice da ultima saida
  long int telefones[100000]; // vetor que armazena os telefones da saida
  int idxTel = 0;          // indice do ultimo telefone da saida

  char opcao = '1';
  criar(&A);
  while (opcao != 0) {

    if (scanf(" %c", &opcao) == 1) {

      if (opcao == '0')
      // esse if libera os nós da avl e é o parâmetro de parada do scanf
      {
        ApagaArvore(&A);
        break;
      }
    }
    switch (opcao) {

    case 'I': // inserir

      if (scanf("%s", e.nome) ==
          1) // o == 1 garante que a leitura do usuário é sempre verdadeira
      // e evita possíveis erros na leitura
      {
        if (scanf("%ld", &e.numero) == 1)
          inserir(&A, e, &idxResp, respostas);
      }
      break;
    case 'R':                       // remover
      if (scanf("%s", e.nome) == 1) // não usa & devido ao uso de string
        remover(&A, e.nome, &idxResp, respostas);
      break;
    case 'A': // alterar
      if (scanf("%s", e.nome) == 1) {
        if (scanf("%ld", &e.numero) == 1)
          alterar(&A, e, &idxResp, respostas);
      }
      break;
    case 'P': // pesquisar
      if (scanf("%s", e.nome) == 1)
        pesquisar(&A, e.nome, &idxResp, respostas, &idxTel, telefones);

      break;
    default:
      respostas[idxResp] = 0;
      // printf("Operacao invalida\r");
    }
    // printf("idx: %d\n", idxResp);
    // for (int i = 0; i < idxResp; i++)
    //{
    // printf("%d \n", respostas[i]);
    //}
  }

  int auxIdxTel = 0;

  for (int i = 0; i <= idxResp - 1; i++) {

    switch (respostas[i]) {
    case 0:
      printf("Operacao invalida\n");
      break;
    case 1:
      printf("Contatinho ja inserido\n");
      break;
    case 2:
      printf("Contatinho nao encontrado\n");
       //printf("Operacao invalida: contatinho nao encontrado\n");
      break;
    case 3:
      printf("Contatinho encontrado: telefone %ld\n", telefones[auxIdxTel]);
      auxIdxTel++;
      break;
    case 4:
      printf("Operacao invalida: contatinho nao encontrado\n");
      break;
    }
  }

  return 0;
}