#include "contatinho.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
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

  char opcao = '1';
  int qntdOperacao = 0;
  criar(&A);
  while (opcao != 0)
  {

    if (scanf(" %c", &opcao) == 1)
    {

      if (opcao == '0')
      //esse if libera os nós da avl e é o parâmetro de parada do scanf
      {
        ApagaArvore(&A);
        break;
      }
    }
    switch (opcao)
    {

    case 'I': //inserir

      if (scanf("%s", e.nome) == 1)//o == 1 garante que a leitura do usuário é sempre verdadeira
      //e evita possíveis erros na leitura
      { 
        if (scanf("%ld", &e.numero) == 1)
          inserir(&A, e);
      }
      break;
    case 'R': //remover
      if (scanf("%s", e.nome) == 1)//não usa & devido ao uso de string
        remover(&A, e.nome);
      break;
    case 'A': //alterar
      if (scanf("%s", e.nome) == 1)
      {
        if (scanf("%ld", &e.numero) == 1)
          alterar(&A, e);
      }
      break;
    case 'P': //pesquisar
      if (scanf("%s", e.nome) == 1)
        pesquisar(&A, e.nome);

      break;
    default:
      printf("Operacao invalida\n");
    }
    qntdOperacao++;
  }
  return 0;
}