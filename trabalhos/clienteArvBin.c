/*---------------------------------------------------------
PROGRAMA: cliente TAD ArvBin
-----------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

typedef int ItemArv;
#include "arvBin.h"

/* -----------------------------------------------------*/
/*	Definicoes das funcoes
*/

int somaChave (ArvBin arv);
int valorMinimo (ArvBin arv);
int valorMaximo (ArvBin arv);
void paiMaior (ArvBin arv);
void troca (ArvBin, ArvBin);
void maiorNaRaiz (ArvBin);
void ordenaPeloMaior (ArvBin);

/* ----------------------------------------------------- */
/* Programa: cria uma árvore binária e imprime a árvore
*/
int main () {
  ArvBin arv;
  ItemArv v;

  criaArv( &arv );
  printf("Insira uma sequencia de chaves. Finalize a sequencia com 0: \n");
  scanf( "%d", &v );
  while( v != 0 ){
    insereArvNivel( v, &arv );
    scanf( "%d", &v );
  }
  printf( "\nArvore\n" );
  escreveArv( arv );

/*----   chamada das funcoes da lista ---- */
  printf("%d\n", somaChave(arv));

	
  printf("%d\n", valorMinimo(arv) );
	
  paiMaior(arv);
  escreveArv(arv);

  maiorNaRaiz(arv);
  escreveArv(arv);
	

	
  ordenaPeloMaior(arv);
  escreveArv(arv);

	/*
  ... dobraArvore(...)
  escreveArv( raiz );
	*/

  free( arv );
  return 0;
}

int somaChave (ArvBin arv) {
	if (!arv)	return 0;

	int soma = somaChave(arv->esq);
	soma += somaChave(arv->dir);
	return soma + arv->item;
}

int valorMinimo (ArvBin arv) {
	if (arvVazia(arv))	return 0;

	int menor = arv->item;
	if (arv->esq) {
		int menor_esq = valorMinimo(arv->esq);
		if (menor_esq < menor)
			menor = menor_esq;
	}
	if (arv->dir) {
		int menor_dir = valorMinimo(arv->dir);
		if (menor_dir < menor)
			menor = menor_dir;
	}
	
	return menor;
}

int valorMaximo (ArvBin arv) {
	if (arvVazia(arv))	return 0;

	int maior = arv->item;
	if (arv->esq) {
		int maior_esq = valorMaximo(arv->esq);
		if (maior_esq > maior)
			maior = maior_esq;
	}

	if (arv->dir) {
		int maior_dir = valorMaximo(arv->dir);
		if (maior_dir > maior)
			maior = maior_dir;
	}
	
	return maior;
}

void paiMaior (ArvBin arv) {
	if (arvVazia(arv))	return;

	int maior = valorMaximo(arv);
	arv->item = maior;
}

void troca (ArvBin a1, ArvBin a2) {
	int aux = a1->item;
	a1->item = a2->item;
	a2->item = aux;
}

void maiorNaRaiz (ArvBin arv) {
	if (arvVazia(arv))	return;

	ArvBin maior = arv;
	ArvBin menor = arv;
	if (arv->esq) {
		maiorNaRaiz (arv->esq);
		if (arv->esq->item > arv->item) maior = arv->esq;
	}
	troca (maior, menor);

	maior = arv;
	menor = arv;
	if (arv->dir) {
		maiorNaRaiz (arv->dir);
		if (arv->dir->item > maior->item) maior = arv->dir;
	}
	troca(maior, menor);
}

void ordenaPeloMaior (ArvBin arv) {
	if (arvVazia(arv))	return;

	if (arv->esq)	ordenaPeloMaior (arv->esq);
	if (arv->dir)	ordenaPeloMaior (arv->dir);
	maiorNaRaiz(arv);
}
