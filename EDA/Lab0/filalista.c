#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct no No;
struct no {
  int info;
  No* prox;
};

struct fila {
  No* ini;
  No* fim;
};

Fila* fila_cria (void) {
  printf("Fila implementada com lista\n");
  Fila* f = (Fila*)malloc(sizeof(Fila));
  f->ini = f->fim = NULL;
  return f;
}

void fila_insere (Fila* f, int v) {
    No* novoNo = (No*) malloc (sizeof(No));
    if(novoNo == NULL){
      perror("Erro ao alocar 'novoNo'");
      exit(1);
    }
    novoNo->info = v;
  if(fila_vazia(f)){
    novoNo->prox = NULL;

    f->ini = novoNo;
    f->fim = novoNo;
  }else{ 
    f->fim->prox = novoNo;
    f->fim = novoNo;
  }
}

int fila_retira (Fila* f) {
  float va;
  va = f->ini->info;
  No* tempNo;
  tempNo = f->ini;

  f->ini = f->ini->prox;

  free(tempNo);
  return va;
}

int fila_vazia (Fila *f) {
  return (f->ini == NULL);
}

void fila_libera (Fila* f) {
  No* n = f->ini;
  while (n != NULL) {
    No* t = n->prox;
    free(n);
    n = t;
  }
  free(f);
}


