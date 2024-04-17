**CI057 - Algoritmos e Estruturas de Dados III**
Lista sobre Arvores Binarias

Complete o programa clienteArvBin.c. O cliente utiliza o TAD ArvBin (com itens do tipo int), que por
sua vez utiliza o TAD Fila (com itens do tipo Apontador) para fazer a insercao dos itens por nivel. O cliente
deve conter as funcoes especificadas abaixo, que devem ser chamadas a partir da funcao main.
Para compilar o seu cliente utilize o comando:
gcc clienteArvBin.c tadArvBinInt.o tadFilaApontador.o -lm -o clienteArvBin

_Exercicio 1:_ funcao somaChave
- Calcular a soma de todas as chaves da arvore.

_Exercicio 2:_ funcao valorMinimo
- Calcular o valor m´ınimo das chaves armazenadas na arvore. Caso a arvore esteja vazia o valor retornado deve ser zero.

_Exercicio 3:_ funcao paiMaior
-	Alterar a arvore de forma que na arvore final a chave do nodo pai e igual a chave do seu maior filho.

_Exercicio 4:_ funcao dobraArvore
-	Dobrar a quantidade de nodos da arvore criando para cada um novo pai que tem a chave determinada da
seguinte forma:
	-  se o nodo n tiver chave k que e par, seu pai e um novo nodo que contem chave k + 1 e n e sera seu
filho esquerdo;
	- se o nodo n tiver chave k que e impar, seu pai e um novo nodo que contem chave k − 1 e n e sera seu
filho direito.

_Exercicio 5:_ funcao maiorNaRaiz
-	Alterar os valores das chaves dos nodos de forma que a maior chave da arvore fique na raiz. A arvore deve
manter as chaves originais, fazendo a troca do valor de um nodo com um dos seus filhos caso seu valor nao
seja o maior.

_Exercicio 6:_ funcao ordenaPeloMaior
-	Utilize sua funcao do exercicio 5 para desenvolver uma funcao que altere uma arvore de forma que cada nodo
contenha o maior valor dentre os seus filhos (mantendo todas as chaves originais da arvore).
