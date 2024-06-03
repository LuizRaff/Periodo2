#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "arvtrie.h"

struct arvtrie {
  int n;           // informa a quantidade de ponteiros != NULL em 'nos'
  ArvTrie* nos[M]; // vetor contendo os ponteiros correspondentes a cada digito
  bool palavra;    // informa se o no corresponde ao final de uma palavra
};

static int transformaparaindice (char c) {
  if (c < 'a' || c > 'z') {
    printf(">>> digito desconhecido\n");
    exit(1);
  }
  int d = c - 'a';
  return d;
}

static char transformaparadigito (int d) {
  char c = d + 'a';
  if (c < 'a' || c > 'z') {
    printf(">>> digito desconhecido\n");
    exit(1);
  }
  return c;
}

static ArvTrie* criano (void) {
  ArvTrie* t = (ArvTrie*)malloc(sizeof(ArvTrie));
  t->n = 0;
  t->palavra = false;
  for (int i = 0; i < M; i++)
    t->nos[i] = NULL;
  return t;  
}

ArvTrie* cria (void) {
  return criano();
}

void destroi (ArvTrie* t) {
  for (int i = 0; i < M; i++) {
    if (t->nos[i]) {
      destroi(t->nos[i]);
    }
  }
  free(t);
}

bool insere (ArvTrie* t, const char* chave) {
  // COMPLETAR
  int i, j = 0;
  while(chave[j] != '\0'){
    i = chave[j] - 'a';
    if(t->nos[i] == NULL){
      t->n++;
      t->nos[i] = criano();
    }
    t = t->nos[i];
    j++;
  }

  if (t == NULL || t->palavra) {
    printf("I: Chave \"%s\" nao inserida\n", chave);
    return false;
  }
  t->palavra = true;
  printf("I: Chave \"%s\" inserida\n", chave);
  return true;
}

bool retira (ArvTrie* t, const char* chave) {
  // COMPLETAR
  int i, j = 0, iaux;
  ArvTrie* taux;
  while(chave[j] != '\0'){
    i = chave[j] - 'a';
    if(t->palavra||t->n>1){
      taux = t;
      iaux = j;
    }
    if(t->nos[i] == NULL){
      printf("R[");
      printf("]: Chave \"%s\" nao encontrada\n", chave);
      return false;
    }
    t = t->nos[i];
    j++;
  }

  if(t->n > 0){
    t->palavra = false;
    printf("R[");
    printf("]: Chave \"%s\" nao removida\n", chave);
    return false;
  }else{
    j = iaux;
    printf("R[");
    while(chave[j] != '\0'){
      printf("%c", chave[j]);
      j++;
    }
    printf("]: Chave \"%s\" removida\n", chave);
    i = chave[iaux] - 'a';
    destroi(taux->nos[i]);
    taux->n--;
    taux->nos[i] = NULL;
  }
  return true;
}

static void imprimechaves (ArvTrie* t, char* chave) {
  if (t == NULL) return;

  // se for uma palavra, imprime o que foi acumulado
  if (t->palavra)
    printf("%s\n", chave);
  
  // se nao tiver nenhum proximo no, deve ser uma palavra, ou temos um erro 
  if (t->n == 0) {
    if (!t->palavra) {
      printf(">>> No folha e nao e' palavra, arvore contem algum erro\n");
      exit(1);
    }
  }
  else {
    // adiciona novo \0, em s+1, deixando a posicao s livre para o novo digito
    int s = strlen(chave);
    chave[s+1] = FIMDECHAVE;
    for (int d = 0; d < M; d++) {
      if (t->nos[d]) {
        // define digito na posicao s
        chave[s] = transformaparadigito(d);
        imprimechaves(t->nos[d], chave);
      }
    }
    // "reseta" o final da palavra
    chave[s] = FIMDECHAVE;
  }
}

void imprime (ArvTrie* t) {
  printf("Imprime chaves da arvore:\n");
  char chave[KMAX];
  chave[1] = FIMDECHAVE; 
  for (int d = 0; d < M; d++) {
    if (t->nos[d]) {
      chave[0] = transformaparadigito(d);
      imprimechaves(t->nos[d], chave);
    }
  }
}

static void sugerirchaves (ArvTrie* t, const char* prefixo) {
  int j = 0, i;
  while(prefixo[j] != '\0'){
    i = prefixo[j] - 'a';
    if(t->nos[i] == NULL){
      printf("preixo: %s inesitente:(\n",prefixo);
      return;
    }
    t = t->nos[i];
    j++;
  }

  char* pchave[strlen(prefixo)];
  strcpy(pchave,prefixo);
  printf("\n");
  imprimechaves(t, pchave);
}

void sugerir (ArvTrie* t, const char* prefixo) {
  printf("Sugerir completacoes para \"%s\": ", prefixo);
  sugerirchaves(t, prefixo);
  printf("\n");
}