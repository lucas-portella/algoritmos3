#ifndef __ARVBIN__
#define __ARVBIN__

typedef struct nodo {
	int chave;
	struct nodo *fe;
	struct nodo *fd;
	struct nodo *pai;
} nodo;

nodo* insere (nodo *raiz, int chave);

nodo* busca (nodo* raiz, int chave);

void imprime_em_ordem (nodo *raiz); 

nodo *destroi_arvore (nodo *raiz);

#endif
