#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "arvore.h"

struct arvno {
  int info;
  ArvNo* esq;
  ArvNo* dir;
};

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

int num_nos (ArvNo* r)
{
  // COMPLETAR
    int i = 0;
    if (r != NULL) { //caso de parada: quando r é igual a nulo.
        i += num_nos(r->esq); //chamada para o próximo elemento na esquerda somando o resultado ao contador (i).
        i += num_nos(r->dir); //chamada para o próximo elemento na direita somando o resultado ao contador (i).
        i++; //somando +1 para adicionar cada elemento em cada chamada da função recursiva.
    }

    return i; //retornando o contador (i) ao final.
}

static int e_abb_preordem (ArvNo* r, int min, int max)
{
  // COMPLETAR: Escolha entre completar 'e_abb_preordem' OU 'e_abb_simetrica'
    if (r == NULL) { //caso de parada: quando r é igual a nulo. caso verdadeiro.
        return 1;
    }

    if (r->info < min || r->info > max) { //caso onde o valor do elemento está fora do intervalo entre max e min, ou seja, não é uma abb. caso falso.
        return 0;
    }

    return e_abb_preordem(r->esq, min, r->info) && e_abb_preordem(r->dir, r->info, max); //chamada para o próximo elemento na esquerda e direita, com a redefinição do max como o valor do elemento atual.
}

static int e_abb_simetrica (ArvNo *r, int *corrente)
 {
  // COMPLETAR: Escolha entre completar 'e_abb_preordem' OU 'e_abb_simetrica'
}

int e_abb (ArvNo* r)
{
# if 0 // Troque para 0 se optar por implementar a função e_abb_preordem
  int corrente = INT_MIN;
  return e_abb_simetrica(r, &corrente);
#else
  return e_abb_preordem(r, INT_MIN, INT_MAX);
#endif
}

int arvores_iguais (ArvNo* r1, ArvNo* r2)
{
  // COMPLETAR
    if (r1 == NULL && r2 == NULL) { //caso de parada: quando r é igual a nulo nas duas árvores. caso onde é verdade que elas são iguais.
        return 1;
    }
    if (r1 == NULL || r2 == NULL) { //caso de parada: quando r é igual a nulo em apenas uma das árvores. caso onde é falso que elas são iguais.
        return 0;
    }
    if (r1->info != r2->info) { //caso de parada: quando o valor de um elemento em uma árvore é diferente do valor na outra árvore. caso onde é falso que elas são iguais.
        return 0;
    }
  return arvores_iguais(r1->esq, r2->esq) && arvores_iguais(r1->dir, r2->dir); //chamada para o próximo elemento nas duas árvores.
}

int num_maiores_que (ArvNo* r, int v)
{
  int nos = 0;
  // COMPLETAR
  if (r == NULL) { //caso de parada: quando r é igual a nulo.
      return nos;
  }

  if (r->info <= v) { //caso onde o valor do elemento é menor ou igual ao valor recebido, logo a chamada será com o próximo nó da direita. pois, valores a direita são maiores.
      nos += num_maiores_que(r->dir, v); //valor do resultado sendo somado a variável nos.
  }

  else {
      nos++; //somando +1 para adicionar cada elemento maior que v em cada chamada da função recursiva.
      nos += num_maiores_que(r->esq, v); //chamada para o próximo elemento na esquerda somando o resultado a variável nos.
      nos += num_maiores_que(r->dir, v); //chamada para o próximo elemento na direita somando o resultado a variável nos.
  }

  return nos; //retornando o valor final de nos.
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