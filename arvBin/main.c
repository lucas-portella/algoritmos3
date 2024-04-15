#include <stdio.h>
#include <stdlib.h>
#include "arvBin.h"

int menu () {
	int op;
	printf("Escolha uma opcao:\n");
	printf("\t[0] Inserir na Arvore;\n");
	printf("\t[1] Buscar na Arvore;\n");
	printf("\t[2] Imprimir Arvore;\n");
	printf("\t[3] Encerrar programa;\n");
	printf("Digite a opcao: ");
	scanf("%d", &op);
	return op;
}

nodo *inserir_arvore (nodo *raiz) {
	int chave;
	printf("Digite o valor a inserir: ");
	scanf("%d", &chave);
	raiz = insere(raiz, chave);
	if (raiz) printf("Chave inserida com sucesso.\n");
	return raiz;
}

nodo *busca_arvore (nodo *raiz) {
	int chave;
	printf("Digite o valor a buscar: ");
	scanf("%d", &chave);
	nodo *nodo = busca(raiz, chave);
	if (nodo) printf("Chave presente na arvore.\n");
	else	printf("Chave nao presente na arvore.\n");
	return raiz;

}

nodo *imprime_arvore (nodo *raiz) {
	printf("Imprimindo arvore:\n");
	imprime_em_ordem(raiz);
	printf("\n");
	return raiz;
}

nodo *encerra_programa (nodo *raiz) {
	printf("Encerrando...\n");
	return destroi_arvore (raiz);
}

int main () {
	int op;
	nodo* raiz = NULL;

	nodo*(*funcao_arvore[])(nodo*) = {
		inserir_arvore,
		busca_arvore,
		imprime_arvore,
		encerra_programa
	};
	
	do{
		op = menu();
		raiz = funcao_arvore[op](raiz);
	} while (op != 3);

}
