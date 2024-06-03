#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "arvore.h"

struct arvno {
  int info;
  ArvNo* esq;
  ArvNo* dir;
};

int info (ArvNo* p)
{
  if (p == NULL) return -1;
  return p->info;
}

ArvNo* cria_no (int v, ArvNo* esq, ArvNo* dir)
{
  ArvNo* p = (ArvNo*)malloc(sizeof(ArvNo));
  if (p != NULL) {
    p->info = v;
    p->esq = esq;
    p->dir = dir;
  }
  return p;
}

void imprime (ArvNo* r)
{
  printf("(");
  if (r != NULL) {
    printf("%d ", r->info);
    imprime(r->esq);
    printf(", ");
    imprime(r->dir);
  }
  printf(")");
}

void libera (ArvNo* r)
{
  if (r != NULL) {
    libera(r->esq);
    libera(r->dir);
    free(r);
  }
}

ArvNo* busca (ArvNo* r, int v)
{
#if 1 // implementação recursiva
  if (r == NULL) return NULL;
  else if (v < r->info) return busca(r->esq, v); 
  else if (v > r->info) return busca(r->dir, v); 
  else return r;
#else // implementação iterativa  
  while (r != NULL) {
    if (v < r->info)
      r = r->esq;
    else if (v > r->info)
      r = r->dir;
    else
      return r;
  }
  return NULL;
#endif
}

ArvNo* insere (ArvNo* r, int v)
{
  if (r == NULL)
    return cria_no(v, NULL, NULL);
  else if (v < r->info)
    r->esq = insere(r->esq, v);
  else // v > r->info
    r->dir = insere(r->dir, v);
  return r;  
}

ArvNo* retira (ArvNo* r, int v)
{
  if (r == NULL) return NULL;
  else if (r->info < v) return retira(r->esq, v);
  else if (r->info > v) return retira(r->dir, v);
  return r;
}

int menor_valor (ArvNo* r)
{
  if (r == NULL) return INT_MAX;
  
  return r->info;
}

int maior_valor (ArvNo* r)
{
  if (r == NULL) return INT_MIN;
  // COMPLETAR
  return r->info;
}

ArvNo* predecessor (ArvNo* r)
{
  // COMPLETAR
  return NULL;
}

ArvNo* sucessor (ArvNo* r)
{
  // COMPLETAR
  return NULL;
}