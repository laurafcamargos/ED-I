#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaduplamente.h" 

int main() {
    t_no *conexao = NULL; //inicializa a lista duplamente encadeada
    
    //adiciona os nós iniciais à lista, cada um com seu nome, tarefas específicas e estado
    adicionar(&conexao, 'A', "Autenticar Usuário", 1);
    adicionar(&conexao, 'B', "Replicar Dados", 1);
    adicionar(&conexao, 'C', "Criptografar Dados", 1);
    adicionar(&conexao, 'D', "Replicar Dados", 0);
    adicionar(&conexao, 'E', "Monitorar Rede", 1);
    adicionar(&conexao, 'F', "Replicar Dados", 1);
    adicionar(&conexao, 'G', "Compartilhar Arquivos", 1);
    adicionar(&conexao, 'H', "Replicar Dados", 1);
    
    //variáveis usadas na interação com o usuário
    char noInical;
    char servicoInput[25];
    char servicoInput1[25];    
    char escolha;

    printf("Digite 1 para realizar 1 serviço e 2 para realizar 2 serviços\n");
    scanf(" %c", &escolha); //escolha do usuário (cenário 1 ou 2)

    switch (escolha) {
        case '1':
            //caso 1: encontra o melhor caminho entre um nó e um serviço
            char noInical;
            char servicoInput[25];
            printf("Nó: ");
            scanf(" %c", &noInical);
            printf("Serviço: ");
            scanf(" %[^\n]s", servicoInput);
            melhorCaminho(conexao, noInical, servicoInput); //função que retorna o melhor caminho
            break;
        case '2':
            //caso 2: encontra o melhor caminho para uma combinação de dois serviços a partir de um nó
            printf("Nó: ");
            scanf(" %c", &noInical);
            printf("Serviço 1: ");
            scanf(" %[^\n]s", servicoInput);
            printf("Serviço 2: ");
            scanf(" %[^\n]s", servicoInput1);
            melhoresCaminhos(conexao, noInical, servicoInput, servicoInput1); //função que retorna os melhores caminhos
            break;
        default:
            break;
    }
    return 0;
}
