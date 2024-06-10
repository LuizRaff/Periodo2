#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct lst{
	int inf;
	struct lst* prox;
};

typedef struct lst Lst;

Lst* lst_insere(Lst* lista, int info);
void lst_imprime(Lst* lista);

int main(void){
	Lst* a = (Lst*)malloc(sizeof(Lst));
	assert(a);
	Lst* b = (Lst*)malloc(sizeof(Lst));
	assert(b);
	a->inf = 45;
	b->inf = 23;

	a->prox = b;
	b->prox = NULL;

	Lst* lista;
	lista = a;

	lista = lst_insere(lista, 40);

	lst_imprime(lista);

	return 0;
}

Lst* lst_insere(Lst* lista, int info){
	Lst* a = (Lst*)malloc(sizeof(Lst));
	a->inf = info;
	a->prox = lista;

	return a;
}

void lst_imprime(Lst* lista){
	while(lista != NULL){
		printf("%d\n", lista->inf);
		lista = lista->prox;
	}

}