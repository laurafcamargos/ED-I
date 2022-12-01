# Árvores Binárias

## Características, Conceitos Gerais e Tipos de Dados

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

- **Estrutura de uma AB**:
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
- **Inserção, remoção e busca, etc**.

- **Qual é a complexidade das operações de uma AB?** a busca, inserção e remoção são O(n). 
- Então, qual é a principal vantagem da AB em relação a, por exemplo, uma lista encadeada? Nenhuma.

# Árvores Binárias de Busca (ABB)

- **Características**: é uma estrutura que implementa a TS com as operações:
	- **Busca**: encontrar se uma chave existe e retornar seu valor, caso exista.
	- Encontrar o maior, o menor e/ou o k-ésimo elemento. 
	- Inserção, remoção, alteração, etc.

- **Busca**: Para todos os nós da árvore, os nós na sub-árvore esquerda possuem chave menor ou igual que o nó raiz. Para a direita, chave maior. O processo é muito parecido com a busca binária em um vetor ordenado (as chaves de uma ABB precisam ser comparáveis).
```
t_elemento pesquisar(t_abb *abb, t_chave chave) {

	if ((*abb) == NULL) {
		t_elemento e;
		printf("elemento nao foi encontrado\n");
		e.chave = -1;
		return e;
	}
	if ((*abb)->elemento.chave == chave) {

		printf("elemento encontrado\n"); 
		return (*abb)->elemento;
	} else {

		if (chave < (*abb)->elemento.chave) {
			return pesquisar(&(*abb)->esq, chave);
		} else {
			return pesquisar(&(*abb)->dir, chave);
		}
	}
}
```
- **Inserção**: o processo é muito mais barato que a inserção em um vetor ordenado, pois não envolve movimentação de dados. 
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
- **Remoção**: o processo é mais complicado, pois existem 3 possíveis casos de remoção. São eles: 
1- remoção do nó folha; 
2- remoção de um nó que possui uma subárvore (ou direita ou esquerda);
3- remoção de um nó que possui as duas subárvores. 
```
int remover(t_abb *abb, t_chave chave) {

	// nao achou
	if ((*abb) == NULL)
		return NAO_ENCONTROU;

	// busca: direita ou esquerda
	if (chave > (*abb)->elemento.chave) {
		return remover(&(*abb)->dir, chave);
	} else if (chave < (*abb)->elemento.chave) {
		return remover(&(*abb)->esq, chave);
	}
	t_apontador p;
	//se passou, é porque achou a chave
	if ((*abb)->esq == NULL && (*abb)->dir == NULL) { //caso 1 (nó folha)
		p = *abb;
		*abb = NULL;
		free(p);
	} else if ((*abb)->esq == NULL) { //caso 2 (remover da dir)
		p = *abb;
		*abb = (*abb)->dir;
		free(p);
	} else if ((*abb)->dir == NULL) { //caso 3 (remover da esq)
		p = *abb;
		*abb = (*abb)->esq;
		free(p);
		//caso 2 e 3 os nós possuem só 1 filho
	} else { //caso 4 (remover nó que tem 2 filhos)
		buscaMaiorEsqETroca(abb, &(*abb)->esq);
	}
	return SUCESSO;
}
```
- **Função auxiliar que procura o maior elemento à esquerda e realiza a troca no caso 4 da remoção**:
```
static void buscaMaiorEsqETroca(t_abb *raiz, t_abb *subarv) {

	if ((*subarv)->dir == NULL) {

		t_apontador p;

		(*raiz)->elemento = (*subarv)->elemento;

		p = *subarv;
		*subarv = (*subarv)->esq;
		free(p);

	} else {
		buscaMaiorEsqETroca(raiz, &(*subarv)->dir);		
	}
}
```

- **Complexidade das operações**: no pior caso, todas as operações de uma ABB consomem tempo proporcional à altura da árvore - O(n). No melhor caso, a complexidade é O(log n).

- **Conclusão**: a eficiência das operações numa ABB depende da profundidade dos nós folha, e tal profundidade depende do seu **balanceamento**. Os  algoritmos de inserção e remoção não possuem
garantias em relação ao balanceamento.
- Qual o pior caso? Quando nossa árvore binária se torna uma **árvore degenerada**: quando todos os seus nós têm apenas uma única sub-árvore associada(desbalanceada).
- Por que é importante balancear a árvore? Porque se evita o pior caso das operações O(n) e garante o O(logn). A solução é manter a **árvore balanceada por meio de rotações**.

![Arvore Degenerada](https://pythonhelp.files.wordpress.com/2015/01/image09.png)

## Percursos na ABB:
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

# Árvores AVL (ABB Balanceada)

- O balanceamento pode ser entendido como sinônimo de equilibrado.

- O objetivo é manter as subárvores da esquerda e direita com a menor diferença possível.

- Todo nó da árvore possui um **fator de balanceamento (fb)**.

- O fb é a diferença entre a altura da subárvore da esquerda e da direita: **fb = hEsq - hDir**.
	
- O fb de qualquer nó deve ser sempre -1,0,1.

- A altura das subárvores de cada nó pode se diferenciar em, no máximo, 1. Caso contrário, fazemos rotações para a esquerda ou direita, a fim de rebalancear a árvore.


## Rotações:

- Como eu sei quando e qual rotação eu devo fazer?

- **Rotação à direita**: a árvore vai estar "esticada para a esquerda" e se o fator de desbalanceamento for positivo (+2 no pai e +1 ou 0 no filho à esquerda).
```
static void rotacao_dir(t_avl *avl) {

	t_apontador j, B;

	// filho à dir da raiz
	j = (*avl)->dir;
	// filho à dir à esq da raiz
	B = j->esq;

	// a sub-arv muda de pai pela antiga raiz
	(*avl)->dir = B;
	// aux passa a ser a raiz
	j = (*avl);

	(*avl)->altura = max(retornar_altura(&(*avl)->esq),retornar_altura(&(*avl)->dir)) + 1;

	j->altura = max(retornar_altura(&j->esq),retornar_altura(&j->dir)) + 1;

	// mudar o ponteiro "de cima"
	*avl = j;
}
```
- **Rotação à esquerda**: a árvore vai estar "esticada para a direita" e se o fator de desbalanceamento for negativo (-2 no pai e -1 ou 0 no filho à direita).
```
static void rotacao_esq(t_avl *avl) {

	t_apontador j, B;

	// filho à esq da raiz
	j = (*avl)->esq;
	// filho à esq à dir da raiz
	B = j->dir;

	// a sub-arv muda de pai pela antiga raiz
	(*avl)->esq = B;
	// aux passa a ser a raiz
	j = (*avl);

	(*avl)->altura = max(retornar_altura(&(*avl)->esq),retornar_altura(&(*avl)->dir)) + 1;

	j->altura = max(retornar_altura(&j->esq),retornar_altura(&j->dir)) + 1;

	// mudar o ponteiro "de cima"
	*avl = j;
}
```
- **Rotação dupla à direita(ou esquerda-direita)**: se o fator de desbalanceamento misturar positivo e negativo (+2 no pai e -1 no filho à esquerda).
```
static void rotacao_esq_dir(t_avl *avl) {

	rotacao_esq(&(*avl)->esq);
	rotacao_dir(avl);

}
```
- **Rotação dupla à esquerda(ou direita-esquerda)**: se o fator de desbalanceamento misturar positivo e negativo (-2 no pai e +1 no filho à direita).
```
static void rotacao_dir_esq(t_avl *avl) {

	//rotacionar à direita
	rotacao_dir(&(*avl)->dir);
	//rotacionar à esquerda
	rotacao_esq(avl);
}
```
- **Situações podem causar desbalanceamento**: 

	- Nó inserido em descendente esquerdo de nó com Fb = 1.
	- Nó inserido em descendente direito de nó com Fb = -1.

- Lembrando que para manter uma árvore balanceada, é necessário fazer rotações nela, de modo que, o percurso em ordem da árvore antes e depois da transformação seja igual (ou seja, continue sendo uma ABB) e o |fb| <= 1.


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

## Operações Básicas na AVL

- **Inserção nas “partes internas” ou “externas”**:
	- Externa (subárvore direita do filho à direita ou subárvore esquerda do filho à esquerda): **simples**.
	-  Interna (subárvore direita do filho à esquerda ousubárvore esquerda do filho à direita): **dupla**.
- **Remoção**: lembrando que qualquer remoção pode diminuir a altura de uma subárvore (causar desbalanceamento). Portanto, devemos fazer o retrace da folha (que foi removida) até a raiz revendo o rebalanceamento. É possível que seja necessário fazer várias rotações até a raiz.

# Filas de Prioridade

## Conceito, Operações Principais e Implementação

- **Conceito**:

	- São estruturas que armazenam itens contendo:
		-Chave que define a prioridade;
		- Outras informações;

	- Apesar do nome “fila”, não é FIFO: o elemento acessado é sempre o de maior prioridade (que pode ser a maior ou menor chave de todas).
	
- **Operações Principais**:

	- **Insere(F,I)**: insere o elemento I = (chave, info) na fila de prioridade F;
	- **Remove(F)**: remove (e retorna) o elemento com maior prioridade em F;
	- **Próximo(F)**: retorna (sem remover) o elemento com maior prioridade em F;
	- Pode ter outras operações: conta(F), vazia(F), alteraPrioridade(F,chave),etc.

- **Implementação**:
	- Lista estática ordenada;
	- Lista estática não-ordenada;
	- Lista dinâmica ordenada;
	- Lista dinâmica não-ordenada;
	- Árvore balanceada;


# Heaps

## Conceito, Operações Principais e Implementação

- **Conceito**:

	- Comumente traduzido como “pilha”, porém essa é uma péssima tradução para ED.Melhor seria algo como “amontoado”.

	- A tendência é o maior fique no topo, não importa muito como estão os abaixo disso.

	- Uma heap é uma AB que respeita as seguintes propriedades:
		- **Ordem**: para cada nó v, exceto o nó raiz, temos que: chave(v) ≥ chave(pai(v)).
		- **Completude**: uma AB é completa se (considerando altura h): 
			- para i = 0, …, h-1 existem 2^i nós de profundidade i;
			- na altura h, os nós existentes estão à esquerda dos ausentes (o último não precisa estar completo);
	
	- Uma heap armazenando n chaves possui altura h de ordem O(logn na base 2).

	- **Convenções de uma Heap**:
		- Pode/deve haver um item com, ao menos, uma informação adicional à chave dentro de cada nó.
		- O **último nó** é o mais à direita com profundidade h.
	- **2^h = n - 1**: h = altura / n = número de chaves

# Fila de prioridade com heap

## Conceitos, Operações, Complexidade, Implementação e Aplicação

- **Conceitos**:

	- Armazenamos a chave em cada nó e mantemos o controle sobre a localização do último nó (w) e, possivelmente, a onde será a próxima inserção (z);

	-  O próximo item (maior prioridade) estará sempre na raiz:
		- Maxheap vs. minheap: vamos focar no minheap por facilidade.
	
	- A remoção é sempre na raiz.

	- A inserção é logo depois do ultimo nó.

- **Operações**:

- **Remoção**: 
 
	- Primeiro, substituímos o conteúdo da raiz pelo conteúdo do último nó. Então removemos o último.
	- Depois, trocamos a raiz com seu filho de menor valor,recursivamente (Bubble-down).

- **Inserção**:

	- Primeiro, encontra a posição a inserir (z) e atribui o item a ela.
	- Bubble-up: troca-se o item pelo seu pai até a raiz (ou até garantir a propriedade da heap).
	 
- **Complexidade (Heap)**:

	- A complexidade das operações **bubble-up (inserção)** e **bubble-down (remoção)** são diretamente relacionadas à altura da árvore, ou seja, **O(logn)**.

	- O próximo (retornar o elemento com maior prioridade em F) é O(1).

- **Implementação**:

	- Implementação estática (com arranjos): posições dos filhos: Esquerda: pos*2 e
	 Direita: pos*2 + 1. Posição do pai: floor(pos/2).

- **Aplicação**:

	- Muito usada em algoritmos gulosos:
		- Paradigma de resolução de problemas bastante comum;
		- Aplicações em grafos: caminhos mínimos (Djikstra), AGM (Prim / Kruskal);
		- Soluções aproximadas para problemas complexos;
						
	- Ordenação: 
		- Usando uma heap, ordenamos n elementos em O(n logn);
		- Insira os elementos na fila um a um via uma série de operações insere;
		- Retorne os elementos via uma série de operações remove; 


# Hashing

## Motivação

- Precisamos do tempo de acesso do array juntamente com a capacidade de busca um elemento em tempo constante O(1).
- Solução: usar uma tabela hash!

## Conceitos

- **Parâmetros Importantes**:
	- M :  número de posições na tabela de hash;
	- N :  número de chaves da tabela de símbolos;
	- alpha = N/M :  fator de carga (load factor);

- **Função Hashing**: 

	- Transforma cada chave em um índice da tabela de hash.Tenta fazer com que a complexidade de busca seja O(1). 

	- A função de hashing responde a pergunta "Em qual posição da tabela de hash devo colocar esta chave?". A função de hashing espalha as chaves pela tabela de hash.

	- A função de hashing produz uma **colisão** quando duas chaves diferentes têm o mesmo valor hash e portanto são levadas na mesma posição da tabela de hash.

 	- Na inserção e busca é necessário calcular a posição dos dados dentro da tabela. 
	
	- Sua implementação depende do conhecimento prévio da natureza e domínio da chave a ser utilizada.


- **Função de Hashing Modular (comumente usada)**: 
	- Se as chaves são inteiros positivos, podemos usar a função modular (resto da divisão por M).	
	- Em hashing modular, é bom que M seja primo (reduz o número de colisões).
	
```
		private int hash(int key) {
    		return key % M;
		}
```
- **Tabela Hashing**: 
	
	- A criação de uma tabela hash consiste de duas coisas: **uma função hashing e um tratamento de colisões**.

	- Tabela que pega todos os índices (capacidade) e as informações de cada um desses índices. É uma generalização da idéia de array. 

	- Utiliza a função de hashing para espalhar os elementos que queremos armazenar na tabela.

	- Esse espalhamento faz com que os elementos fiquem dispersos de forma não ordenada dentro do array que define a tabela.

	- A tabela permite a associar valores a chaves (chave: parte da informação que compõe o elemento a ser inserido ou buscado na tabela / valor: é a posição (índice) onde o elemento se encontra no array que define a tabela).

	- A partir de uma chave podemos acessar em O(1) uma determinada posição do array.

	- Como escolher a melhor  capacidade da tabela hashing?  
		- A capacidade tem a ver com a quantidade de colisões.O caso de nunca ter colisão é pegar a capacidade = total de informações que você tem (inviável as vezes, pois gasta muito espaço).
		- O ideal é escolher um número primo e evitar valores que sejam uma potência de dois.

## Vantagens

	- Alta eficiência na operação de busca (caso médio é O(1) enquanto o da busca linear é O(N) e a da busca binária é O(log2 N)).
	- Tempo de busca é praticamente independente do número de chaves armazenadas na tabela.
	- Implementação simples.

##	Desvantagens 

	- Alto custo para recuperar os elementos da tabela ordenados pela chave (nesse caso teria que ordenar). 
	- O pior caso é O(N), sendo N o tamanho da tabela (alto número de colisões).

## Hashing Perfeito

	- Nunca ocorre colisão (chaves diferentes irão sempre produzir posições diferentes).
	- No pior caso, as operações de busca e inserção são sempre executadas em tempo constante, O(1). 

## Tratamento de Colisões (endereçamento aberto e fechado)

	- Uma escolha adequada da função de hashing ou do tamanho da tabela hash pode minimizar as colisões.

**Endereçamento Aberto**: 
- No caso de um colisão, percorrer a tabela hash
buscando por uma posição ainda não ocupada, onde es elementos são armazenados na própria
tabela hash.

- Para a realização do cálculo da nova posição
após a colisão, existem três estratégias(sondagens, probes,rehash) muito utilizadas no endereçamento aberto: 

	- Sondagem linear: Tenta espalhar os elementos de forma sequencial a partir da posição calculada utilizando a função de hashing. A medida que a tabela hash fica cheia, o tempo para incluir ou buscar um elemento aumenta, pois surgem longas sequências de posições ocupadas.
	- Tendência de gerar clusters(aglutinações), o que da uma busca O(n) no pior caso.
```
		h(x,i) = (x+i) % m; //x = chave /// i = tentativa
```

	- Sondagem quadrática: Tenta espalhar os elementos utilizando uma
equação do segundo grau. Resolve o problema de aglutinação, porém apresenta outro problema de que todas as chaves que produzam a mesma posição inicial também produzem as mesmas posições na sondagem quadrática (replica as mesmas colisões). 
	- Tendência de criar "buracos" dentro dos blocos.
```
				h(x,i) = (x+i*i) % m; 
						ou 
 		h(x,i) = (x +c1* i+c2 * i*i) % m; 
```

	- Sondagem dupla: Tenta espalhar os elementos utilizando duas funções de hashing. É necessário que as duas funções de hashing sejam diferentes. A segunda função de hashing não pode resultar em um valor igual a 0.

	- A primeira função de hashing (h) é utilizada para calcular a posição inicial do elemento.
	- A segunda função de hashing (h2) é utilizada para calcular os deslocamentos em relação a posição inicial (no caso de uma colisão).
	- O esperado são n/m colisões.

```
		h(x,i) = (x + i*h2(x)) % m; 
		h2(x) = x % P +1 ( P < m); // P e m primos entre si!
```

- **Vantagens do end. aberto**: 
	- Garante um maior número de posições na tabela para a mesma quantidade de memória usada no endereçamento fechado.	
	- A memória utilizada para armazenar os ponteiros da lista encadeada,por exemplo, no endereçamento fechado pode ser aqui usada para aumentar o tamanho da tabela, diminuindo o número de colisões.
	- Busca é realizada dentro da própria tabela (encontra mais rápido).
	- Ao invés de acessarmos ponteiros extras, calculamos a sequência de posições a serem armazenadas.

- **Desvantagens do end. aberto**: 
	- Maior esforço de processamento no cálculo das posições.
	- Esse esforço maior se deve ao fato de que, quando uma colisão ocorre, devemos calcular uma nova posição da tabela (existe o risco de colisões sucessivas).

**Endereçamento Fechado**:
	- Não procura por posições vagas (valor NULL) dentro do array que define a tabela hash.
	- Armazena dentro de cada posição do array o início de uma nova ED (lista encadeada, array, árvore binária,etc).
	- Dentro dessa nova ED serão armazenadas as colisões(elementos com chaves iguais) para aquela posição do array.
	- Funciona bem, mas da problema na remoção (colocar flag -1). 
	- Uma implementação interessante de fazer é dar O(1) para a chave mais popular (informação que procurou por último).

## TAD Tabela Hash

- **Inserção**: calcular a posição da chave no array, recalcular a posição enquanto houver colisão (limitar o número de tentativas), alocar espaço para os dados e armazenar os dados na posição calculada.

- **Busca**: calcular a posição da chave no array, verificar se há dados na posição calculada e se esses dados combinam com a chave, recalcular a posição enquanto os dados forem diferentes da chave e retornar os dados. 
	