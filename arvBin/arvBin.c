#include <stdio.h>
#include <stdlib.h>
#include "arvBin.h"

void imprime_em_ordem (nodo *raiz) {
	if (!raiz)	return;

	imprime_em_ordem (raiz->fe);
	printf("%d ", raiz->chave);
	imprime_em_ordem(raiz->fd);
}

nodo *cria_nodo (int chave) {
	nodo* novo = (nodo*) malloc (sizeof(nodo));

	if (novo) {
		novo->chave = chave;
		novo->pai = NULL;
		novo->fd = NULL;
		novo->fd = NULL;
	}
	
	return novo;
}

/*	insere e retorna a raiz da arvore */
nodo* insere (nodo *raiz, int chave) {
	if (!raiz)	return cria_nodo(chave);

	nodo* novo = cria_nodo (chave);
	nodo *atual = raiz;
	nodo *pai = NULL;
	while (atual) {
		if (atual->chave > chave) {
			pai = atual;
			atual = atual->fe;
		}
		else {
			pai = atual;
			atual = atual->fd;
		}
	}
	novo->pai = pai;
	if (pai) {
		if (pai->chave < chave) pai->fd = novo;
		else pai->fe = novo;
		return raiz;
	}
	return novo;
}

nodo* busca (nodo* raiz, int chave) {
	if (!raiz)	return NULL;

	if (raiz->chave == chave)	return raiz;
	if (raiz->chave > chave)	return busca(raiz->fe, chave);
	else	return busca(raiz->fd, chave);
}

nodo *destroi_arvore (nodo *raiz) {
	if (raiz) {
		destroi_arvore(raiz->fe);
		destroi_arvore(raiz->fd);
		free(raiz);
		raiz = NULL;
	}

	return raiz;
}

