#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "grafo.h"
#include "heap.h"
#include "ub.h"

typedef struct _viz Viz;
struct _viz {
  int noj;
  int peso;
  Viz*  prox;
};

struct _grafo {
  int nv;    /* numero de nos ou vertices */
  int na;    /* numero de arestas */
  Viz** viz; /* viz[i] aponta para a lista de arestas vizinhas do no i */
};

static Viz* criaViz (Viz* head, int noj, int peso) {
/* insere vizinho no inicio da lista */
  Viz* no = (Viz*) malloc(sizeof(Viz));
  assert(no);
  no->noj = noj;
  no->peso = peso;
  no->prox = head;
  return no;
}

static Grafo* grafoCria (int nv) {
  int i;
  Grafo* g = (Grafo *) malloc(sizeof(Grafo));
  assert(g);
  g->nv = nv;
  g->na = 0;
  g->viz = (Viz **) malloc(sizeof(Viz *) * nv);
  assert(g->viz);
  for (i = 0; i < nv; i++)
    g->viz[i] = NULL;
  return g;
}


Grafo* grafoLe (const char* filename) {
/* cria grafo nao orientado - supoe que arquivo esta correto! */

  FILE *arq = fopen(filename,"rt");
  int nv, na, no1, no2 = 0;
  int peso;
  Grafo* novo;
	
  fscanf(arq, "%d %d", &nv, &na);
  novo = grafoCria(nv);
  assert(novo);
  while (fscanf(arq, "%d %d %d", &no1, &no2, &peso) == 3) {
    novo->viz[no1] = criaViz(novo->viz[no1], no2, peso);
    novo->viz[no2] = criaViz(novo->viz[no2], no1, peso);
    novo->na++;
  }
  return novo;
}

Grafo* grafoLibera (Grafo* grafo) {
  if (grafo) {
    int i = 0;
    Viz* no,*aux;
    for (i = 0; i < grafo->nv; i++){
      no = grafo->viz[i];
      while (no){
        aux = no->prox;
        free(no);
        no = aux;
      }
    }
    free(grafo->viz);
    free(grafo);
  }
  return NULL;
}

void grafoMostra (Grafo* grafo) {
  int i;
  if (grafo) {
    printf("NV: %d, NA: %d\n", grafo->nv, grafo->na);
    for (i = 0; i < grafo->nv; i++){
      Viz* viz = grafo->viz[i];
      printf("[%d]->", i);
      while (viz) {
        printf(" {%d, %d}", viz->noj, viz->peso);
        viz = viz->prox;
      }
      printf("\n");
    }
  }
}

Grafo* primArvoreCustoMinimo (Grafo* g, int inicial) {
  /* Cria array auxiliar com nos ja inseridos no heap, valor passa a ser 1 no
     momento em que for adicionado no heap. Previne um vertice de ser adicionado
     novamente no heap apos ser removido. */
  int* inserido = (int*)malloc(g->nv*sizeof(int));
  for(int i = 0; i < g->nv; i++)
    inserido[i] = 0;

  Heap* heap = heap_cria(g->nv, g->nv);
  /* Cria o heap com os vertices a partir do vertice inicial. */
  // COMPLETAR

  Grafo *acm = grafoCria(g->nv);
  /* Cria a arvore de custo minimo */
  while (!heap_vazio(heap)) {
    /* Busca proximo vertice (ainda nao adicionado na acm) com aresta de menor peso no heap. */
    // COMPLETAR

    /* Adiciona aresta na vizinhanca do grafo acm (adicionando o novo vertice). */
    // COMPLETAR

    /* Verifica vizinhos do vertice adicionado e atualiza o heap. */
    // COMPLETAR
  }
    
  heap_libera(heap);
  return acm;
}

Grafo* kruskalArvoreCustoMinimo (Grafo* g) {
  /* Cria a estrutura de uniao e busca com a particao. */
  UniaoBusca *ub = ub_cria(g->nv);

  Heap *heap = heap_cria(g->na, 0);
  /* Cria o heap com as arestas. */
  // COMPLETAR

  Grafo *acm = grafoCria(g->nv);
  /* Cria a arvore de custo minimo */
  while (!heap_vazio(heap) && acm->na < (g->nv - 1)) {
    /* Retira proxima aresta. */
    // COMPLETAR

    /* Verifica se aresta deve ser adicionada no grafo acm. Se for,
       realiza a insercao, utilizando a estrutura de Uniao e Busca. */
    // COMPLETAR
  }
  
  heap_libera(heap);
  ub_libera(ub);
  return acm;
}
