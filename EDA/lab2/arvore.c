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

ArvNo* criano (int v, ArvNo* esq, ArvNo* dir)
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

int num_nos (ArvNo* r)
{
  if (r == NULL) return 0;
  return num_nos(r->esq) + num_nos(r->dir) + 1;
}

ArvNo* busca (ArvNo* r, int v)
{
#if 1 // implementacao recursiva
  if (r == NULL) return NULL;
  else if (v < r->info) return busca(r->esq, v); 
  else if (v > r->info) return busca(r->dir, v); 
  else return r;
#else // implementacao iterativa  
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
    return criano(v, NULL, NULL);
  else if (v < r->info)
    r->esq = insere(r->esq, v);
  else if (v > r->info)
    r->dir = insere(r->dir, v);
  // se for igual, nao sera adicionado
  return r;  
}

ArvNo* retira (ArvNo* r, int v)
{
  if (r == NULL) return NULL;
  else if (v < r->info)
  {
    r->esq = retira(r->esq, v);
  }
  else if (v > r->info)
  {
    r->dir = retira(r->dir, v);
  }
  else 
  { /* achou o nó a remover */
/* nó sem filhos */
    if (r->esq == NULL && r->dir == NULL) {
      free(r);
      r = NULL;
    }
/* nó só tem filho à direita */
    else if (r->esq == NULL) {
      ArvNo* t = r;
      r = r->dir;
      free(t);
    }
/* só tem filho à esquerda */
    else if (r->dir == NULL) {
      ArvNo* t = r;
      r = r->esq;
      free(t);
    }
/* nó tem os dois filhos: busca o sucessor */
    else {
      ArvNo* sucessor = successor(r);
      r->info = sucessor->info;
      sucessor->info = v;
      r->dir = retira(r->dir, v);
    }
  }
  return r;
}

ArvNo* menor_no (ArvNo* r)
{
  while(r->esq != NULL){
    r = r->esq;
  }

  return r;
}

ArvNo* maior_no (ArvNo* r)
{
  while(r->dir != NULL){
    r = r->dir;
  }

  return r;
}

ArvNo* predecessor (ArvNo* r)
{
  return menor_no(r->esq);
}

ArvNo* successor (ArvNo* r)
{
  return maior_no(r->dir);
}

int altura (ArvNo* r)
{
  if(r == NULL){
    return -1;
  }
  int hE = altura(r->esq);
  int hD = altura(r->dir);
  if(hD > hE){
    return hD + 1;
  }
  return hE + 1;
}

int e_balanceada (ArvNo* r)
{
  if(r==NULL){
    return 1;
  }

  if(abs(altura(r->esq) - altura(r->dir)) <= 1){
    if(e_balanceada(r->esq) && e_balanceada(r->dir)){
      return 1;
    }
  }
  
  return 0;
  
}

ArvNo* balancear (ArvNo* r)
{
  if (r == NULL) return NULL;
  int ne = num_nos(r->esq);
  int nd = num_nos(r->dir);
  // se ne+nd for impar, a diferenca sempre vai ser no minimo 1 
  // se ne+nd for, a diferenca entre as duas sempre vai ser par, 
  //     pq vai estar diminuindo de uma e adicionando em outra
  while (!(abs(ne-nd) <= 1)) { // or abs(ne-nd) > 1
    if (nd > ne + 1) {
      r->esq = insere(r->esq, r->info);
      ArvNo* s = menor_no(r->dir);
      r->info = s->info;
      r->dir = retira(r->dir, r->info);
      ne++;
      nd--;
    }
    else {
      r->dir = insere(r->dir, r->info);
      ArvNo* p = maior_no(r->esq);
      r->info = p->info;
      r->esq = retira(r->esq, r->info);
      nd++;
      ne--;
    }
  }
  r->esq = balancear(r->esq);
  r->dir = balancear(r->dir);
  return r;
}