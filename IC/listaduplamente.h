#ifndef LISTADINAM_H
#define LISTADINAM_H
//Laura Fernandes Camargos - 13692334

//constantes para retornos de erro ou sucesso
#define ERRO -1
#define SUCESSO 0

//estrutura do tipo de dado t_chave
typedef char t_chave;

//estrutura de um apontador para a estrutura do nó da rede
typedef struct t_no *t_apontador;

//estrutura de cada nó da rede
typedef struct t_no {
    t_chave nome;             //ID dos computadores
    char servicos[25];        //tarefa específica desse computador
    int estado;               //representa o estado do computador na rede (0 = falha, 1 = ativo)
    t_apontador anterior;     //apontador para o nó anterior na lista
    t_apontador proximo;      //apontador para o próximo nó na lista
} t_no;

//declaração das funções utilizadas no .c
t_no* criar(t_chave nome, const char* servicos, int estado);
int adicionar(t_no** network, t_chave nome, const char* servicos, int estado);
int melhorCaminho(t_no* network, char startt_no, const char* servicoInput);
t_no* busca(t_no* conexao, const char *servicoInput);
int melhoresCaminhos(t_apontador conexao, char noInicial, const char *servicoInput1, const char *servicoInput2);
int buscaFalha(t_apontador conexao, char noInicial, const char *servicoInput);

#endif
