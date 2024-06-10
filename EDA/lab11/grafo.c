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

Grafo* primArvoreCustoMinimo(Grafo* g, int inicial) {
  int* inserido = (int*)malloc(g->nv * sizeof(int));
  for (int i = 0; i < g->nv; i++) {
    inserido[i] = 0;
  }

  Heap* heap = heap_cria(g->nv, g->nv);
  heap_insere(heap, 0, inicial, inicial);

  Grafo *acm = grafoCria(g->nv);

  while (heap_vazio(heap) == NULL) {
    int v1, v2;
    int peso = heap_remove(heap, &v1, &v2);
    if (!inserido[v1]) {
      inserido[v1] = 1;
      if (v1 != v2) {
        acm->viz[v1] = criaViz(acm->viz[v1], v2, peso);
        acm->viz[v2] = criaViz(acm->viz[v2], v1, peso);
        acm->na++;
      }
      Viz* vizinho = g->viz[v1];
      while (vizinho != NULL) {
        if (inserido[vizinho->noj] == NULL) {
          heap_insere(heap, vizinho->peso, vizinho->noj, v1);
        }
        vizinho = vizinho->prox;
      }
    }
  }

  heap_libera(heap);
  free(inserido);
  return acm;
}

Grafo* kruskalArvoreCustoMinimo(Grafo* g) {
  UniaoBusca *ub = ub_cria(g->nv);

  Heap *heap = heap_cria(g->na, 0);
  for (int i = 0; i < g->nv; i++) {
    Viz* vizinho = g->viz[i];
    while (vizinho != NULL) {
      int v1 = i;
      int v2 = vizinho->noj;
      int peso = vizinho->peso;
      if( v1 > v2){
        heap_insere(heap, peso, v2, v1);
      }
      vizinho = vizinho->prox;
    }
  }

  Grafo *acm = grafoCria(g->nv);
  while (!heap_vazio(heap) && acm->na < (g->nv - 1)) {
    int v1, v2;
    int peso = heap_remove(heap, &v1, &v2);
    if (ub_busca(ub, v1) != ub_busca(ub, v2)) {
      acm->viz[v1] = criaViz(acm->viz[v1], v2, peso);
      acm->viz[v2] = criaViz(acm->viz[v2], v1, peso);
      acm->na++;
      ub_uniao(ub, v1, v2);
    }
  }

  heap_libera(heap);
  ub_libera(ub);
  return acm;
}