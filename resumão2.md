# Árvores Binárias

## Intro, Nomenclaturas e Conceitos Gerais

- **Características**:
	- uma estrutura de dados que pode ser representada como uma hierarquia onde cada elemento é chamado de nó.
	- utiliza de relações genealógicas para relacionar seus nós(pai,filho).
    - são representadas com a raiz no topo e as folhas na base (contrário da árvore natural). 
	- uma árvore binária é uma árvore em que cada
	nó possui entre 0 e 2 sub-árvores/filhos.
	- os filhos de um nó são chamados filhos esquerdo e direito.

- **Conceitos gerais**:
	- **Nó Raiz**: não possui ancestrais, só pode ter filhos.
    - **Nó Folha**: não tem filhos (ou melhor, seus filhos são estruturas vazias).
    - **Grau**: é o número de sub-árvores que o nó possui (Ex: um nó folha ou terminal é aquele que possui grau 0).
	- **Nível ou profundidade de um nó r**: é o comprimento do caminho entre a raiz e r (Ex: a raiz está no nível 0). 
	- **Altura de um nó r**: é o comprimento do caminho mais longo de r a algum nó folha (de suas subárvores). Ex: a altura da árvore é a altura do nó raiz, das folhas é 0.

- **Tipos de dados**:
    - **t_nó**: contém o elemento e os apontadores para os filhos esquerda ou direita.
    - **t_apontador**: ponteiro do tipo nó.
	- **t_chave**: inteiro que serve de identificação do elemento.
	- **t_elemento**: struct que contém a chave de identificação e outros campos de informação.
	- **t_ab**: é uma variável do tipo apontador, sempre que manipulado usar (*ab)->elemento = elemento, por exemplo.

- Estrutura de uma AB:
```
typedef int t_chave;
typedef struct {
	t_chave chave;
	//outros campos
} t_elemento;

typedef struct t_no *t_apontador;
typedef struct t_no { 
	t_elemento elemento;
	t_apontador esq;
    t_apontador dir;
} t_no;
typedef t_apontador t_abb;
```

- Para acessar cada elemento dentro da struct:
	- Nome.Elemento1 ou Nome -> Elemento1 (caso for ponteiro)
	- caso ponteiro, utiliza-se a função **malloc**

#### Malloc(sizeof())

- retorna um tipo \*void
- para transformá-lo, utiliza-se o "casting" (ex.: int * x = **(int * )** malloc(sizeof(int));)

## Operações Básicas na ABB

- **Cria árvore**:
```
int criar(t_abb *abb) {
	// ideal seria limpar caso houvesse algo
	*abb = NULL;
}
```

- **Cria raiz**: 
```
int static criar_raiz(t_abb *abb, t_elemento elemento){
	*abb = (t_abb) malloc(sizeof(t_no));
	if (*abb == NULL)
		return ERRO_CHEIA;
	
	(*abb)->esq = NULL;
	(*abb)->dir = NULL;
	(*abb)->elemento = elemento;

	return SUCESSO;
}
```
- **Insere esquerda ou direita**:
```
int inserir(t_abb *abb, t_elemento elemento) {
	
	if ((*abb) == NULL) {
		return criar_raiz(abb, elemento);
	}

	//considerar chaves primárias
	if ((*abb)->elemento.chave == elemento.chave) { 
		printf("elemento ja inserido\n");
		return JA_EXISTE; 
	} else {

		if (elemento.chave < (*abb)->elemento.chave) {
			return inserir(&(*abb)->esq, elemento);
		} else {
			return inserir(&(*abb)->dir, elemento);
		}
	}
}
```

- **Qual é a complexidade das operações de uma AB?**: a busca, inserção e remoção são O(n). 
- Então, qual é a principal vantagem da AB em relação a, por exemplo, uma lista encadeada? Nenhuma.

## Árvores Binárias de Busca(ABB)

- **Características**: é uma estrutura que implementa a TS com as operações:
	- **Busca**: encontrar se uma chave existe e retornar seu valor, caso exista.
	- Encontrar o maior, o menor e/ou o k-ésimo elemento. 
	- Inserção, remoção, alteração, etc.
	- As chaves de uma ABB precisam ser comparáveis.

- **Busca**: Para todos os nós da árvore, os nós na sub-árvore esquerda possuem chave menor ou igual que o nó raiz. Para a direita, chave maior. O processo é muito parecido com a busca binária em um vetor ordenado.

- **Inserção**: o processo é muito mais barato que a inserção em um vetor ordenado, pois não envolve movimentação de dados. 

- **Remoção**: o processo é mais complicado, pois existem 3 possíveis casos de remoção. São eles: 
1- remoção do nó folha; 
2- remoção de um nó que possui uma subárvore (ou direita ou esquerda);
3- remoção de um nó que possui as duas subárvores. 

- **Complexidade das operações**: no pior caso, todas as operações de uma ABB consomem tempo proporcional à altura da árvore - O(n). No melhor caso, a complexidade é O(log n).

- **Conclusão**: a eficiência das operações numa ABB depende da profundidade dos nós folha, e tal profundidade depende do seu **balanceamento**. Os  algoritmos de inserção e remoção não possuem
garantias em relação ao balanceamento.
- Qual o pior caso? Quando nossa árvore binária se torna uma **árvore degenerada**: quando todos os seus nós têm apenas uma única sub-árvore associada(desbalanceada).
- Por que é importante balancear a árvore? Porque se evita o pior caso das operações O(n) e garante o O(logn). A solução é manter a **árvore balanceada por meio de rotações**.

![Arvore Degenerada](https://pythonhelp.files.wordpress.com/2015/01/image09.png)

## Percusos na ABB:
- **Operações para percorrer uma AB visitando cada nó uma única vez**: visitar pode significar qualquer tipo de operação feita no nó (imprimir, modificar seu valor, etc). 
```
					void visita (t_abb *abb){ 
						printf("%d ",(*abb)->elemento.chave);
}
```

- Um percurso gera uma sequência linear de nós visitados (agora existe o conceito de sucessor e predecessor de um nó). Logo, diferentes percursos podem ser realizados, dependendo da aplicação.
- **3 percursos comuns para ABs podem ser feitos com o mesmo algoritmo base**: diferença básica está na ordem em que os nós são visitados. Percorre-se a AB recursivamente:

- Pré-ordem (pre-order): visita o nó **antes** de acessar qualquer um dos seus filhos:
```
			void visita (t_abb *abb){ 
				if((*abb) != NULL) {
					printf("%d ",(*abb)->elemento.chave);
					visita(&(*abb)->esq);
					visita(&(*abb)->dir);
				}
			}	
```
- Em-ordem (in-order): visita o nó **entre** o acesso a cada um de seus dois filhos:
```
			void visita (t_abb *abb){ 
				if((*abb) != NULL) {
					visita(&(*abb)->esq);
					printf("%d ",(*abb)->elemento.chave);
					visita(&(*abb)->dir);
				}
			}	
```
	- Pós-ordem (post-order): visita o nó somente **depois** de acessar seus filhos:
```
			void visita (t_abb *abb){ 
				if((*abb) != NULL) {
					visita(&(*abb)->esq);
					visita(&(*abb)->dir);
					printf("%d ",(*abb)->elemento.chave);
				}
			}	
```

- **Aplicações**: representar uma expressão em uma árvore binária. Ex: (A + B) * (C - D) -> A B + C D - * > notação pós-fixa mais fácil.
-colocar imagem

## Árvores AVL (ABB Balanceada)

- O balanceamento pode ser entendido como sinônimo de equilibrado.

- O objetivo é manter as subárvores da esquerda e direita com a menor diferença possível.

- Todo nó da árvore possui um **fator de balanceamento(fb)**.

- O fb é a diferença entre a altura da subárvore da esquerda e da direita: **fb = hEsq - hDir**.
	
- O fb de qualquer nó é sempre -1,0,1.

- A altura das subárvores de cada nó pode se diferenciar em, no máximo, 1. Caso contrário, fazemos rotações para a esquerda ou direita, a fim de rebalancear a árvore.


## Rotações:

- **Rotação à direita**: a árvore vai estar "esticada para a esquerda" 

- **Rotação à esquerda**: a árvore vai estar "esticada para a direita" 

- **Rotação dupla à direita(ou esquerda-direita)**:

- **Rotação dupla à esquerda(ou direita-esquerda)**:

-**Situações podem causar desbalanceamento**: lembrando que para manter uma árvore balanceada, é necessário fazer rotações nela, de modo que, o percurso em ordem da árvore antes e depois da
transformação seja igual (ou seja, continue sendo uma ABB) e o |fb| <= 1.

	- Nó inserido em descendente esquerdo de nó com Fb = 1.
	- Nó inserido em descendente direito de nó com Fb = -1.

- Como eu sei quando e qual rotação eu devo fazer? 
	- Para saber quando a árvore está balanceada, é só descobrir o **fator de balanceamento**.
	- Se fator de desbalanceamento for positivo (+2 no pai e +1 ou 0 no filho à esquerda), **rotacionar à direita**.
	- Se fator de desbalanceamento for negativo (-2 no pai e -1 ou 0 no filho à direita), **rotacionar à esquerda**.
	- Se misturar positivo e negativo (+2 no pai e -1 no filho à esquerda ou -2 no pai e +1 no filho à direita), **rotacionar duplamente**.

### Rotação simples ou dupla?

- Balanceamento positivo/negativo: rotação simples.
- Balanceamento “misto”: rotação dupla.
- Visualmente falando, se olharmos para os nós envolvidos no desbalanceamento, veremos uma reta (rotação simples) ou um “joelho” (rotação dupla).

- Estrutura de uma AVL:
```
typedef int t_chave;

typedef struct {
	t_chave chave;
	char nome[50];
} t_elemento;

typedef struct t_no *t_apontador;
typedef struct t_no {
	t_elemento elemento;
	t_apontador esq, dir;
	int altura; //novo
} t_no;

typedef t_apontador t_avl;
```


## Operações Básicas na ABB

- **Inserção nas “partes internas” ou “externas”**:
	- Externa (subárvore direita do filho à direita ou subárvore esquerda do filho à esquerda): **simples**.
	-  Interna (subárvore direita do filho à esquerda ousubárvore esquerda do filho à direita): **dupla**.
- **Remoção**: lembrando que qualquer remoção pode diminuir a altura de uma subárvore (causar desbalanceamento). Portanto, devemos fazer o retrace da folha (que foi removida) até a raiz revendo o rebalanceamento. É possível que seja necessário fazer várias rotações até a raiz.




```
void CriaLista(t_lista *lista) {
	lista->ultimo = -1;
}
```





















### Lista Ligada (linked list) (implementação dinâmica)

#### Ideia geral

- é uma "array" dinâmica
- as operações de inserção e remoção são menos custosas
- Um ponteiro para o primeiro elemento
- cada elemento tem um ponteiro para indicar seu sucessor

- **Complexidade**
	- Busca: O(n)
	- Inserção: O(1) na não ordenada
	- Remoção: O(1) na não ordenada
	- Espaço: O(n)

- **desvantagens:**
	- não suporta busca binária
	- espaço extra na memória para o ponteiro

#### Tipos

- lista ligada simples (simple linked list)
- lista duplamente ligada (double linked list)
- lista ligada circular (circular linked list)
- A complexidade dos 3 tipos de listas dinâmicas é igual!

#### Modelagem

- **representação:**
	- um ponteiro para o primeiro nó da lista
	- o primeiro nó é chamado de cabeça (head)
	- se a lista está vazia, então o valor do ponteiro da cabeça é nulo (null)
	- cada nó da lista consiste em ao menos duas partes: data (int, string, etc...) e ponteiro (para o próximo nó ou um endereço para outro ponteiro)
	- em C, um nó pode ser representado com structs
```
// a linked list node
typedef struct t_no { 
	t_elemento elemento; // informação
	t_apontador proximo; // ponteiro para o proximo elemento da lista
}t_no;
```

```
#include<stdio.h>
#include<stdlib.h> 

typedef int t_chave;

typedef struct {
	t_chave chave;
	//char nome[50];
} t_elemento;

typedef struct t_no *t_apontador;
typedef struct t_no { //cada nó contém um objeto de determinado tipos e o endereço da célula seguinte
	t_elemento elemento;
	t_apontador proximo;
} t_no;

typedef struct {
	t_apontador primeiro,ultimo;
} t_lista;
```

**Criar/Inicializar Lista Dinâmica**
```
void criar(t_lista *lista) {
	lista->primeiro = NULL;
	lista->ultimo = NULL;
}
```

**Imprimir Elementos**
```
void imprimir(t_lista *lista) {
    t_apontador P = lista->primeiro; //p =Piliar
	while(P != NULL) {
		 printf("%d ",P->elemento.chave);
		P = P->proximo;
	}
}
```
**Retornar o número de elemento**

- percorrer o número de elementos

```
int tamanho(LISTA * l) {
	PONT posicao = l->inicio;
	int tam = 0;
	while(posicao != NULL) {
		tam++;
		posicao = posicao->prox;
	}
	return tam;
}
```

**Buscar elemento**

- não suporta busca binária - busca sequencial - complexidade O(n)
- recebe uma chave
- retorna o endereço do elemento (se existir)
- retorna null caso não encontre

a) busca sequencial 

```
t_apontador pesquisar(t_lista *lista, t_chave chave) {

	t_apontador P = lista->primeiro; 
	if(P == NULL)
		return NULL;
	while(P != NULL) {
		if (P->elemento.chave == chave)
			return P;
		P = P->proximo;
	}
	return P;
}
```

b) busca em lista ordenada pelos valores das chaves dos registros

```
PONT buscaSeqOrd(LISTA * l, TIPOCHAVE ch) {
	PONT posicao = l->inicio;
	while(posicao != NULL && posicao->r.chave < ch) posicao = posicao->prox;
	if(posicao != NULL && posicao->r.chave == ch) return posicao;
	return NULL;
}

```

**Inserção de um nó**

- 3 maneiras:
	- na frente da lista
	- depois de um nó específico
	- no final da lista

- **Na frente**
```
// é preciso dar um ponteiro para um ponteiro (head_ref) para a cabeça da lista e um inteiro
int inserir(t_lista *lista, t_elemento elemento) {
	// alocação dinâmica do novo nó
	t_apontador novo;
	novo = (t_apontador) malloc(sizeof(t_no));
	if (novo == NULL)
		return ERRO_CHEIA;

	// inserir dado
	novo->elemento = elemento;

	// fazer o ponteiro de proximo do novo nó ser a cabeça
	novo->proximo = lista->primeiro;
	lista->primeiro = novo;
}
```

- **Depois de um dado nó**
```
void insertAfter(struct Node* prev_node, int new_data) {
	// 1 - verificar se o nó dado aponta para NULL
	if(prev_node == NULL)
		printf("o nó anterior não pode ser nulo\n");
		return;

	// 2 - alocar o novo nó
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	// 3 - inserir dado
	new_node->data = new_data;

	// fazer o "proximo" do novo nó ser o proximo do nó dado
	new_node->next = prev_node->next;

	// apontar o "proximo" do nó dado para o novo nó
	prev_node->next = new_node;
}
```

- **No final da lista**
```
void append(struct Node** head_ref, int new_data) {

	// 1 alocar o novo nó
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	// 2 criar um apontador para o último
	struct Node * last = * head_ref;

	// 3 atribuir valor do dado
	new_node->data = new_data;

	// 4 proximo do novo nó apontar para nulo
	new_node->next = NULL;

	// 5 se a lista estiver vazia, o novo_nó é também a cabeça (head)
	if(*head_ref == NULL) {
		*head_ref = new_node;
		return;
	}

	// 6 se não estiver vazia, percorrer até o último nó
	while(last->next != NULL)
		last = last->next;

	// 7 apontar o proximo do ultimo nó para o novo nó
	last->next = new_node;
	return;
}
```

- inserção de ordenada pelo valor da chave
- não se permitirá a inserção de elementos repetidos
- é preciso identificar entre quais elementos o novo será inserido
- é preciso alocar memória para o novo elemento
- é preciso saber quem será o predecessor do elemento
- função auxiliar

```
PONT buscaSequencialExc(LISTA * l, TIPOCHAVE ch, PONT * ant) {
	*ant = null;
	PONT atual = l->inicio;
	while((atual != NULL) && (atual->r.chave < ch)) {
		*ant = atual;
		atual = atual->prox;
	}
	if((atual != NULL) && (atual->r.chave == ch))
		return atual;
	return NULL;
}

int inserirElementoListOrdenada(LISTA * l, REGISTRO r) {
	TIPOCHAVE ch = r.chave;
	PONT ant, i;
	i = buscaSequencialExc(l, ch, &ant);
	if(i != NULL) return false // significa que o elemento já existe na lista
	i = (PONTO) malloc(sizeof(ELEMENTO));
	i->r = r;
	if(ant == NULL) {
		i->prox = l->inicio;
		i->inicio = i;
	} else {
		i->prox = ant->prox;
		ant->prox = i;
	}
	return 1; // "true"
}
```

**Remover elemento por posição**

- passar a chave do elemento que se quer excluir

```
int remover(t_lista *lista, t_chave chave) {
	t_apontador P = pesquisar(lista,chave);
	int elemento = remove_posicao(lista,P);
	if (elemento == POS_INVALIDA)
	{
		printf("Não foi possivel remover o %d!\n",chave);
	}else printf("Sucesso, o %d foi removido!\n",chave);
}

-Função auxiliar: 
static int remove_posicao(t_lista *lista, t_apontador p) {
	//lista vazia
	if (p == NULL) {
		return POS_INVALIDA;
	}

	// unico elemento
	if (p == lista->primeiro && p == lista->ultimo) {
		criar(lista);
		free(p);
		return SUCESSO;
	}

	// remove do inicio
	if (p == lista->primeiro) {
		lista->primeiro = lista->primeiro->proximo;
		free(p);
		return SUCESSO;
	}

	// remove do meio
	t_apontador aux = lista->primeiro;//necessário criar o aux para nao perder a posição 
	while(aux->proximo != NULL && aux->proximo != p) {
		aux = aux->proximo;//passa a apontar pra prox posição
	}

	aux->proximo = p->proximo;//exemplo do a,b,c,tipo, vc aponta pro b com o aux, o b aponta pro c, o a prox = b prox, pois ele passa a apontar pro c, e dps da free no ponteiro do b 
	// remove do fim
	if (aux->proximo == NULL) {
		lista->ultimo = aux;
	}
	free(p);
	return SUCESSO;
}

```

**Zerar a lista**

- criar uma variável auxiliar antes de dar "free" no endereço
- se fizer sem auxiliar, perde o conteúdo do endereço, incluíndo quais os proximos elementos da lista

```
void libera_fila(t_lista *lista) {
  t_apontador P = lista->primeiro;
  while (P != NULL) {
    lista->primeiro = P->proximo;
    free(P);
    P = lista->primeiro;
  }
```
**Alterar o conteúdo de uma posição**

```
void alterar(t_lista *lista, t_elemento e)
{
  t_apontador P = pesquisa_pos(lista, e.nome);
  if (P->elemento.nome == NULL)
    printf("Operacao Invalida: contatinho nao encontrado\n");
  else
    P->elemento.numero = e.numero;
}
```
**Inverter a lista - O(n) em tempo e O(1) em espaço.**

```
void reverse(t_lista *lista)
{
	t_apontador P = lista->primeiro; 
	if (lista->primeiro == NULL)
		printf("Lista vazia\n");
	if (lista->primeiro->proximo == NULL)
	{
		printf("Lista unitária\n");
	}
	
	t_apontador anterior = NULL;
	t_apontador proximo = lista->primeiro;
	while (proximo != NULL)
	{
		proximo = lista->primeiro->proximo;
		lista->primeiro->proximo = anterior; // inverter o prox
		anterior = lista->primeiro;			 // andar com o ant pra frente
		lista->primeiro = proximo;
	} 
	lista->primeiro = anterior;
} 
```
**Tamanho ou quantidade de nós da lista**

```
int tamanho (t_lista *lista) {
	t_apontador p= lista->primeiro; 
	int n=0;
	while (p != NULL) {
		n++;
		p = p->proximo;
}
	return n;
}
```
### Lista Duplamente Ligada (implementação dinâmica)

#### Ideia geral

- Similar à lista padrão
- Ponteiro para o anterior é adicionado na struct
- Operações de busca, remoção e inserção análogas à lista padrão, atentando-se ao ponteiro para o anterior
- Ponteiro para o fim pode ser conveniente

- **desvantagens:**
	- não suporta busca binária
    - implementação mais difícil, pq gasta mais um ponteiro.Dica: ponteiro pro final.Dificuldade de remover o último e  primeiro, pq ambos apontam pra NULL
	- Vantagem: busca pelo elemento que quer remover
### Lista Circular (implementação estática)

#### Ideia geral

- Vetor normal
- Ponteiros para início e fim são importantes
- Como qualquer Lista Estática é importante manter a informação da quantidade de espaços alocados (MAX_TAM)
- Como iterar 5 e 0(fazer a volta)? usando MOD(%). 
- Busca sequencial basta iterar de inicio para fim.
- Busca binária é preciso considerar que o início não é 0 e que é possivel estourar o vetor. PIVO = ((inicio+fim)/2)%(max_tam)
- Na inserção, verificações de limites são importantes para evitar que dados sejam sobrescritos.
- O dado é inserido no fim. → fim=(fim+1)%TAM
- Ao remover um número fica inicio =(inicio+1)%TAM. 
- Se o inicio e fim se encontrarem ela tá cheia, ai não tem como inserir.

### Lista Circular (implementação dinâmica)

#### Ideia geral

- Similar à lista padrão
- A diferença é que o próximo do último é o primeiro(ao invés de NULL)
- ultimo->prox = primeiro.(simplesmente ligada) 
- ultimo->prox = primeiro;
  primeiro->ant = ultimo; (na duplamente ligada)

## Aplicações de listas ligadas

- Visualizador de imagens: As imagens Próximo e Anterior são ligadas, portanto, podem ser acessadas pelos botões “próximo” e “anterior”.
- Página seguinte e anterior em um navegador da web: Podemos acessar o “url” anterior e seguinte pesquisado em um navegador da web pressionando os botões “voltar” e “próximo”, pois eles estão conectados como uma lista ligadas.(usa pilhas)
- Music Player: As músicas no music player são conectadas à música anterior e seguinte. Você pode ouvir as músicas do início ou do final da lista.

# Estrutura de dados

## Estrutura de dados elementares

### Pilhas e filas

- conjuntos dinâmicos

#### Pilhas

- São especializações de listas em que as inserções e remoções são feitas na mesma extremidade, chamada TOPO
- LIFO (Last In, First Out == o último elemento a entrar é o primeiro a sair)
- A ordem da retirada dos elementos é inversa ao da entrada
- O *TOPO* indica o último elemento inserido
- Se *TOPO* == 0, a pilha está vazia
- Se a pilha está vazia e mesmo assim é realizada a operação de retirada de elementos, ocorreu um *estouro negativo*


**Operações e nomenclaturas comuns em pilhas**

- INSERIR/EMPILHAR -> PUSH
- REMOVER/DESEMPILHAR -> POP
- STACK-EMPTY: verifica se a pilha está vazia (topo == -1)
- Operações Complementares: cria uma pilha vazia,topo(retorna o item no topo da pilha),vazia(verifica se ta vazia),inverte,conta,imprime,etc. 

EMPILHAR

```
S.topo = S.topo + 1;
S[S.topo] = x;
```
```
int empilhar(t_pilha *pilha, t_elemento elemento)
{

	t_apontador novo;
	novo = (t_apontador)malloc(sizeof(t_no));
	if (novo == NULL)
		return ERRO_CHEIA;

	novo->elemento = elemento;
	novo->proximo = pilha->topo;
	pilha->topo = novo;
	num_nos++;
	return SUCESSO;
}
```

DESEMPILHAR

```
if SACK-EMPTY(S)
	error "underflow"
else S.topo = S.topo - 1;
	return S[S.topo + 1];
```
```
int desempilhar(t_pilha *pilha)
{
	if (vazia(pilha))
		return NAO_ENCONTROU;

	t_apontador aux = pilha->topo; // topo=topo
	pilha->topo = pilha->topo->proximo;
	free(aux);
	num_nos--;

	return SUCESSO; // geralmente retorna um nó que acabou de remover
}
```
TOPO

```
t_no topo(t_pilha *pilha)
{
	if (vazia(pilha))
	{
		printf("Nó vazio!\n");
	}

	return *(pilha->topo);
}
```

VER SE ESTÁ VAZIA

```
if S.topo == 0
	return true;
else return false;
```
```
int vazia(t_pilha *pilha)
{
	if (pilha->topo == NULL)
	{
		return 1; // tá vazia
	}
	else
		return 0; // não está vazia
}
```
**Aplicações:**

- Undo e redo de editores de texto (similar à pags de navegação):  
- Avaliar expressões matemáticas, verificar parênteses e chaves
- Simular recursão

**Notação Pós-fixa:**

```
para cada elemento E da expressão faça
   Se E é operando / número
		empilha(P,E)
   Senão //operador
		V1 = desempilha(P)
		V2 = desempilha(P)
		empilha(V2 operador V1)
Se conta(P) > 1
   INVALIDO
Senão
   Resultado = topo(P)
```
**Como tornar a infixa em pós-fixa?**

```
para cada elemento E da expressão faça
	Se E é operando / número
		Imprime E
	Senão se E é ‘(‘
		empilha(P, E)
	Senão se E ')’
		imprime(desempilha(P)) até que topo(P) seja ‘(‘
	Senão // operador
		enquanto precedência(E) <= precedência(topo(P))
			imprime(desempilha(P))
		empilha(P, E)
enquanto não(vazia(P))
	imprime(desempilha(P))
```

#### Filas

- Filas são especializações de listas em que as inserções e remoções são feitas em extremidades diferentes, chamadas frente e trás ou cabeça e cauda.
- FIFO (First In, First Out == Primeiro a entrar, primeiro a sair)
- Tem um **início (ou cabeça)** e um **fim (ou cauda)**
- O elemento retirado da fila é sempre o que está **início**
- (final-início) + 1 = indica quantos elementos há na fila


**Operações e nomenclaturas comuns em filas**

- INSERT/ENFILEIRAR -> ENQUEUE
- DELETE/DESENFILEIRAR -> DEQUEUE 
- Operações Complementares similar à pilha

ENFILEIRAR(sempre no final)
```
Q[Q.fim] = x;
if(Q.fim == Q.comprimento)
	Q.fim = q;
else Q.fim = Q.fim + 1;
```
```
int enfileirar(t_fila *fila, t_elemento elemento)
{

	t_apontador novo;
	novo = (t_apontador)malloc(sizeof(t_no));
	if (novo == NULL)
		return ERRO_CHEIA;

	novo->elemento = elemento;
	novo->proximo = NULL;
	if (vazia(fila))
	{
		fila->primeiro = novo;
	}
	else
	{
		fila->ultimo->proximo = novo;
	}
	fila->ultimo = novo;
	contador++;
	return SUCESSO;
}
```

DESENFILEIRAR(sempre no início)
```
x = Q[Q.inicio];
if Q.inicio == Q.comprimento
	Q.inicio = 1;
else Q.inicio = Q.inicio + 1;
return x;
```
```
int desenfileirar(t_fila *fila)
{
	if (vazia(fila))
		return NAO_ENCONTROU;
	if (fila->primeiro == fila->ultimo)
	{ // fila unitária
		fila->ultimo = NULL;
	}

	t_apontador aux = fila->primeiro;
	fila->primeiro = fila->primeiro->proximo;
	free(aux);
	contador--;
	return SUCESSO; // geralmente retorna um nó que acabou de remover
}






