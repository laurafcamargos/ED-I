#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaduplamente.h"

//declaração de funções auxiliares utilizadas para printar o caminho
static void printarCaminho(t_apontador inicio, const char *servicoInput);
static void printarCaminhoFalha(t_apontador inicio, const char *servicoInput);
static int encontraCaminho(t_apontador conexao, char noInicial, const char *servicoInput);


//função que cria um novo nó na rede
t_apontador criar(t_chave nome, const char* servicos, int estado) {
    t_apontador novo = (t_apontador)malloc(sizeof(t_no)); //aloca memória para um novo nó
    if (novo != NULL) {
        novo->nome = nome; //define o nome do novo nó
        strcpy(novo->servicos, servicos); //copia o nome do serviço para o novo nó
        novo->anterior = NULL; //define o apontador para o nó anterior como NULL
        novo->proximo = NULL; //define o apontador para o próximo nó como NULL
        novo->estado = estado; //define o estado do nó na rede
    }
    return novo; //retorna o novo nó criado
}


//função que adiciona um novo nó à rede, mantendo a topologia em anel
int adicionar(t_apontador *conexao, t_chave nome, const char* servicos, int estado) {
    //cria um novo nó com os dados fornecidos
    t_apontador novo = criar(nome, servicos, estado);

    //verifica se teve algum erro na criação do novo nó 
    if (novo == NULL) {
        return ERRO; //retorna -1 em caso de falha na criação do nó
    }

    //verifica se a rede está vazia, ou seja, se é o primeiro nó a ser inserido
    if (*conexao == NULL) {
        *conexao = novo; //o primeiro nó é o novo nó criado
        novo->anterior = novo; //o primeiro nó aponta para ele mesmo como anterior
        novo->proximo = novo;  //também aponta para ele mesmo como próximo
    } else {
        //encontra o último nó no anel
        t_apontador ultimo = (*conexao)->anterior;

        //atualiza os ponteiros para incluir o novo nó no anel
        ultimo->proximo = novo; //o próximo do último nó é o novo nó
        novo->anterior = ultimo; //o anterior do novo nó é o último nó
        novo->proximo = *conexao; //o próximo do novo nó é o primeiro nó
        (*conexao)->anterior = novo; //o anterior do primeiro nó é o novo nó
    }

    return SUCESSO; //retorna 0 após adicionar o novo nó à rede
}

//função auxiliar recursiva para printar o caminho até um serviço no cenário 1
static int encontraCaminho(t_apontador conexao, char noInicial, const char *servicoInput) {

    //verifica se a conexão = NULL, indicando fim do anel
    if (conexao == NULL) 
        return ERRO;

    //verifica se o serviço atual é o serviço desejado
    if (strcmp(conexao->servicos, servicoInput) == 0) {
        printf("%c → Wifi → %c\n", noInicial, conexao->nome); //imprime o caminho encontrado
        return SUCESSO; //retorna 0
    }
    //chama recursivamente a função para o próximo nó na conexão
    return encontraCaminho(conexao->proximo, noInicial, servicoInput);
}



//função encontra o melhor caminho entre um nó e um serviço no cenário 1
int melhorCaminho(t_apontador conexao, char noInicial, const char *servicoInput) {
    //chama a função que identifica se tem algum computador com falha na rede
    int resultado = buscaFalha(conexao, noInicial, servicoInput);
    
    //se o pc com falha for o mesmo do nó inicial, imprime uma mensagem de erro
    if (resultado == 1) {
        printf("Não é possível realizar o serviço %s a partir do nó %c\n", servicoInput, noInicial);
    } else {
        //busca e imprime o caminho até o serviço
        encontraCaminho(conexao, noInicial, servicoInput);
    }

    return SUCESSO;//retorna 0
}


//função que encontra os melhores caminhos para a combinação de dois serviços a partir de um nó, cenário 2
int melhoresCaminhos(t_apontador conexao, char noInicial, const char *servicoInput1, const char *servicoInput2) {
    //verifica se existe nó com defeito para o serviço 1
    int noComFalha1 = buscaFalha(conexao, noInicial, servicoInput1);

    //chama a função de printar o caminho para o serviço 1, considerando possíveis falhas
    //dependendo do retorno de buscaFalha, é feito um caminho contrário na tentativa de chegar ao serviço desejado  
    if (noComFalha1 == ERRO) {
        printarCaminhoFalha(conexao, servicoInput1);
    } else {
        printarCaminho(conexao, servicoInput1);
    }
    
    //verifica se existe nó com defeito para o serviço 2
    int noComFalha2 = buscaFalha(conexao, noInicial, servicoInput2);
    
    //chama a função de printar o caminho para o serviço 2, considerando possíveis falhas
    //dependendo do retorno de buscaFalha, é feito um caminho contrário na tentativa de chegar ao serviço desejado 
    if (noComFalha2 == ERRO) {
        printarCaminhoFalha(conexao, servicoInput2); 
    } else {
        printarCaminho(conexao, servicoInput2);
    }

    return SUCESSO; //retorna 0 
}

//função que busca falha na rede ao longo do caminho até o serviço
int buscaFalha(t_apontador conexao, char noInicial, const char *servicoInput) {
    t_apontador aux = conexao;
    while (strcmp(aux->servicos,servicoInput) != 0) {
        if (aux->estado == 0) {
            printf("Nó %c está com defeito\n", aux->nome); //printa qual nó está com defeito, independente se ele está envolvido
            if (aux->nome == noInicial) {
                return 1; //se o nó inicial estiver com defeito, retorna 1
            }
            return ERRO;
        }
        aux = aux->proximo;
    }
    return SUCESSO; //retorna sucesso se não houver falhas
}



//função que imprime o caminho até o serviço, considerando possíveis falhas
static void printarCaminhoFalha(t_apontador inicio, const char *servicoInput) {
    t_apontador atual = inicio;
    int encontrouFalha = 0; //indicador de falha encontrada no caminho

    while (atual != NULL && strcmp(atual->servicos, servicoInput) != 0) {
        if (atual->estado == 0) {
            encontrouFalha = 1;
            break; //sai do loop ao encontrar um nó com estado 0
        }
        
        atual = atual->anterior;
    }
    
    if (encontrouFalha) {
        printf("Não é possível realizar o serviço %s a partir do nó %c\n", servicoInput, inicio->nome);
    } else {
        while (inicio != NULL && strcmp(inicio->servicos, servicoInput) != 0) {
            printf("%c → ", inicio->nome); //printa o caminho
            inicio = inicio->anterior;
        }
        printf("%c\n", inicio->nome); //printa o destino final
    }
}

//função que imprime o caminho até o serviço, sem considerar falhas
static void printarCaminho(t_apontador inicio, const char *servicoInput) {
    t_apontador atual = inicio;
    while (strcmp(atual->servicos, servicoInput) != 0) {
        printf("%c → ", atual->nome); //printa o caminho 
        atual = atual->proximo;
    }
    printf("%c\n", atual->nome); //printa o destino final
}

