#include "trabalho1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
  t_lista l;
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
  criar(&l);
  while (opcao != 0)
  {

    if (scanf(" %c", &opcao) == 1)
    {

      if (opcao == '0')
      {
        P = l.primeiro;
        while (P != NULL)
        {
          l.primeiro = P->proximo;
          free(P);
          P = l.primeiro;
        }
        break;
      }
    }
    switch (opcao)
    {

    case 'I': // inserir

      if (scanf("%s", e.nome) == 1)
      { // nao usa & por causa que é string
        if (scanf("%ld", &e.numero) == 1)
          inserir(&l, e);
      }
      break;
    case 'R': // remover
      if (scanf("%s", e.nome) == 1)
        remover(&l, e.nome);
      break;
    case 'A': // alterar
      if (scanf("%s", e.nome) == 1)
      {
        if (scanf("%ld", &e.numero) == 1)
          alterar(&l, e);
      }
      break;
    case 'P': // pesquisar
      if (scanf("%s", e.nome) == 1)
        pesquisar(&l, e.nome);

      break;
    default:
      printf("Operacao invalida\n");
    }
    qntdOperacao++;
  }
  return 0;
}