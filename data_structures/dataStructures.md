# Data Structures
## Matrizes e Vetores
- Advantages
  - Random access & replacement
  - Easy sorting and iteration
- Disadvantages
  - Size is fixed
  - Difficult to insert and delete
  - If capacity is more and occupancy less, most of the array gets wasted 
  - Needs contiguous memory to get allocated
> Strings são vetores constantes
## Registros (Nó Heterogêneo)
Um Registro é uma estrutura que fornece um formato especializado para armazenar informações em memória.
> Em linguagem C, por exemplo, os registros podem ser representados por estruturas (structures), ao passo que em C++ e Java, por objetos de uma classe.
## [Listas](https://www.cprogressivo.net/2013/10/Listas-em-C-O-que-e-como-funciona-uma-LIST.html) (Nó Homogêneo)
- Advantages of Data Structure
  - Dynamic in size & efficient memory allocation
  - No wastage as capacity and size is always equal
  - Easy insertion and deletion as 1 link manipulation is required
- Disadvantages of Data Structure
  - If the head node is lost, the linked list is lost
  - No random access possible
- Lista encadeada simples: contém apenas um link por nodo. Este link aponta para o próximo nodo da lista, ou para um valor nulo (vazio) quando se trata do nodo final.
- Lista duplamente encadeadas: são um modelo mais sofisticado das listas simples. Cada nodo possui dois ponteiros - um que aponta para o nodo anterior (ou null se é o primeiro valor ou a lista está vazia) e outro que aponta para o próximo nodo (ou null se é o último nodo ou a lista está vazia).
- [Pilhas x Filas](https://www.learn-c.org/en/Linked_lists)
## [Hashing](https://www.ime.usp.br/~pf/algoritmos/aulas/hash.html)
### Tabela de Símbolos
Uma tabela de símbolos é um conjunto de objetos, cada um dotado de uma chave (= key).  As chaves podem ser números inteiros, ou cadeias de caracteres, ou qualquer outro tipo-de-dados básico que permita comparação: dadas duas chaves ch1 e ch2, deve ser possível dizer se ch1 < ch2 ou ch1 == ch2 ou ch1 > ch2.
>
A tabela de símbolos está sujeita a dois tipos de operação:
- inserção (= insert = enter),  que consiste em introduzir um objeto na tabela
- busca (= search = lookup),  que consiste em encontrar um objeto que tenha uma dada chave
>
A dificuldade está em organizar a tabela de símbolos de maneira que ambas as operações sejam razoavelmente eficientes. Em geral, uma organização que permite inserções rápidas impede buscas rápidas e vice-versa.
### Tabela Hash
- Hash Function
- Hash Code (h)
>A função de espalhamento recebe uma chave v e devolve um número inteiro h no intervalo 0..M-1
>É recomendado que M seja um número primo
>
É fundamental que a função de espalhamento seja uma função no sentido matemático do termo, isto é, que para cada chave v a função devolva sempre o mesmo código de espalhamento.  Além disso, uma boa função de espalhamento espalha as chaves uniformemente pelo conjunto de índices.
>
Dizemos que há uma colisão quando duas chaves diferentes são levadas no mesmo índice.
### Resolvendo colisões por meio de listas encadeadas
Uma solução popular para resolver colisões é conhecida como separate chaining: para cada índice h da tabela há uma lista encadeada que armazena todos os objetos que a função de espalhamento leva em h. Se o número total de objetos for N, o comprimento de cada lista deveria, idealmente, estar próximo de N/M, de modo que fique entre 5 e 10.
### Funções de espalhamento modulares para cadeias de caracteres
```C
//Número primo como base, em vez de 256, e módulo para evitar overflow
int hash(string v, int M) {
   int i, h = v[0];
   for (i = 1; v[i] != '\0'; i++) 
      h = h * 251 + v[i] % M;
   return h;
}
```
## Árvores
- Root, Ancestry, Leafs & Subtrees
- Edges (Unidirectional), Depth & Height
### Binary Trees
- Full / Strict: is a Binary Tree in which every node has 0 or 2 children.
- Complete: has all levels completely filled with nodes except the last level and in the last level, all the nodes are as left side as possible.
> Maximum number of nodes by level (complete): 2^level
>
> Binary Heap
- Perfect: is a Binary Tree in which all internal nodes have 2 children and all the leaf nodes are at the same depth or same level.
> Number of nodes (perfect): 2^levels - 1
- Balanced: is a Binary tree in which height of the left and the right sub-trees of every node may differ by at most 1.
> AVL Tree and Red-Black Tree
- Degenerate(or Pathological): is a Binary Tree where every parent node has only one child node.
> Height of a Degenerate Binary Tree is equal to Total number of nodes in that tree
## Grafos

# [Algorithms](https://introprogramming.info/english-intro-csharp-book/read-online/chapter-19-data-structures-and-algorithm-complexity/)
## [Typical Complexities](https://www.bigocheatsheet.com/)
![compexities](../pictures/Screenshot_20201121_182010.png)
## Execution Time
![execution_time](../pictures/Screenshot_20201121_182253.png)
>
We can draw many conclusions from the above table:
- Algorithms with a constant, logarithmic or linear complexity are so fast that we cannot feel any delay, even with a relatively big size of the input data.
- Complexity O(n*log(n)) is similar to the linear and works nearly as fast as linear, so it will be very difficult to feel any delay.
- Quadratic algorithms work very well up to several thousand elements.
- Cubic algorithms work well if the elements are not more than 1,000.
- Generally these so called polynomial algorithms (any, which are not exponential) are considered to be fast and working well for thousands of elements.
- Generally the exponential algorithms do not work well and we should avoid them (when possible). If we have an exponential solution to a task, maybe we actually do not have a solution, because it will work only if the number of the elements is below 10-20. Modern cryptography is based exactly on this – there are not any fast (non-exponential) algorithms for finding the secret keys used for data encryption.
## Complexity by Several Variables
Complexity can depend on several input variables at once. For example, if we look for an element in a rectangular matrix with sizes M and N, the searching speed depends on M and N. Since in the worst case we have to traverse the entire matrix, we will do M*N number of steps at most. Therefore the complexity is O(M*N).
## Best, Worst and Average Case
Complexity of algorithms is usually evaluated in the worst case (most unfavorable scenario). This means in the average case they can work faster, but in the worst case they work with the evaluated complexity and not slower.
Let’s take an example: searching in array. To find the searched key in the worst case, we have to check all the elements in the array. In the best case we will have luck and we will find the element at first position. In the average case we can expect to check half the elements in the array until we find the one we are looking for. Hence in the worst case the complexity is O(N) – linear. In the average case the complexity is O(N/2) = O(N) – linear, because when evaluating complexity one does not take into account the constants. In the best case we have a constant complexity O(1), because we make only one step and directly find the element.
## Complexity by Memory
Besides the number of steps using a function of the input data, one can measure other resources, which an algorithm uses, for example memory, count of disk operations, etc. For some algorithms the execution speed is not as important as the memory they use. For example if a given algorithm is linear but it uses RAM in the order of N2, it will be probably shortage of memory if N = 100,000 (then it will need memory in order of 9 GB RAM), despite the fact that it should work very fast.
## Comparison between Basic Data Structures
![data_structure_comparison](../pictures/Screenshot_20201121_183705.png)

# Related
## Ponteiros
Um ponteiro é uma variável especial que contém um endereço de memória armazenado, em vez de dados comuns. Esse endereço é, no geral, a posição na memória de uma outra variável
- Declaração e Aritmética (* - &)
- Pointer to an array (Indexação por ptr+index) x Array of Pointers (Indexação por [ ])
- Pointer to Pointer
- Pointer to a constant x Constant pointer
## [Alocação Dinâmica x Estática](https://www.ime.usp.br/~pf/algoritmos/aulas/aloca.html)
- [Vazamento de Memória e Segurança](https://www.cprogressivo.net/2013/10/Funcao-free-Como-liberar-memoria-e-evitar-vazamento.html)
