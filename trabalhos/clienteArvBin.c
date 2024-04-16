/*---------------------------------------------------------
PROGRAMA: cliente TAD ArvBin
-----------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

typedef int ItemArv;
#include "arvBin.h"

int somaChave (ArvBin arv);
/* ----------------------------------------------------- */
/* Programa: cria uma árvore binária e imprime a árvore
*/
int main(int argc, char *argv[]){
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

	/*
  printf("%d\n" valorMinimo(...) );
	*/

	/*
  ... paiMaior(...)
  escreveArv( arv );
	*/

	/*
  ... maiorNaRaiz(...)
  escreveArv( raiz );
	*/

	/*
  ... ordenaPeloMaior(...)
  escreveArv( raiz );
	*/

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
