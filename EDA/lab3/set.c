#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "set.h"

struct set {
  int n;
  unsigned int members;
};

static int set_member_valid(int i) {
  if ((i<0) || (i>=MAX_MEMBERS)) return 0;
  return 1;
}

/* cria um conjunto com n elementos */
Set *set_create(void){
  Set *set;
  set = (Set *)malloc(sizeof(Set));
  if (set != NULL) {
    set->n = MAX_MEMBERS;
    set->members = 0;
  }
  return set;
}

/* destroi (desaloca) o conjunto */
void set_destroy(Set *set) {
  if (set) free(set);
}

/* mostra os elementos do conjunto */
void set_show(char* title, Set *set){
  int i, first=1;
  printf("%s = {", title);
  for (i = 0; i < MAX_MEMBERS; i++) {
    if (set_is_member(set, i)) {
      if (first) { 
      	printf("%d", i); 
      	first = 0; 
      }
      else 
      	printf(",%d", i);
    }
  }
  printf("}\n\n");
}

/* insere o elemento i no conjunto */
void set_insert(Set *set, int i) {
  if (set == NULL) return;
  else if(set_member_valid(i)){
    unsigned int imagem = 1;
    set->members = ((imagem << i) | set->members);
  }

  return;
}

/* remove o elemento i do conjunto */
void set_remove(Set *set, int i){
  if (set == NULL) return;
  else if(set_member_valid(i)){
    unsigned int imagem = 1;
    set->members = ((~(imagem << i)) & set->members);
  }
  return;
}

/* cria uma copia do conjunto */
Set* set_copy(Set *set){
  if (set==NULL) return NULL;
  Set* newSet = set_create();
  newSet->members = set->members;
  return newSet;
}

/* cria conjunto com a uniao de dois conjuntos */
Set *set_union(Set *set1,  Set *set2){
  if (set1==NULL || set2 == NULL) return NULL;
  Set* newSet = set_create();
  newSet->members = set1->members | set2->members;
  return newSet;
}

/* cria conjunto com a intersecao de dois conjuntos */
Set *set_intersection(Set *set1,  Set *set2){
  if (set1==NULL || set2 == NULL) return NULL;
  Set* newSet = set_create();
  newSet->members = set1->members & set2->members;
  return newSet;
}

/* cria conjunto com a diferenca de set1-set2 */
Set *set_difference(Set *set1, Set *set2){
  if (set1==NULL || set2 == NULL) return NULL;
  Set* newSet = set_create();
  newSet->members = set1->members & set2->members;
  newSet->members = newSet->members ^ set1->members;
  return newSet;
}

/* verifica se o elemento i pertence ao conjunto */
int set_is_member(Set *set, int i){
  if (set==NULL) return 0;
  if (!set_member_valid(i)) return 0;
  return ((1<<i) & (set->members));
}

/* verifica se set2 e' um subconjunto de set1 */
int set_is_subset(Set *set1,  Set *set2) {
  if (set1==NULL || set2 == NULL) return 0;
  return (set1->members & set2->members) == set2->members;
}

/* verifica se dois conjuntos sao iguais */
int set_is_equal(Set *set1,  Set *set2) {
  if (set1==NULL || set2 == NULL) return 0;
  return !(set1->members ^ set2->members);
}

/* informa a cardinalidade do conjunto */
int set_number_of_elements(Set *set){
  if (set==NULL) return 0;
  int count = 0;
  unsigned int setMembro;
  setMembro = set->members;
  for (int i = 0; i < 32; ++i)
  {
    if(setMembro & 1){
      count++;
    }
    setMembro = setMembro >> 1;
  }
  return count;
}

/* cria um novo conjunto que e' complementar ao primeiro */
Set *set_complement(Set *set){
  if (set == NULL) return NULL;
  Set* newSet = set_create();
  newSet->members = ~set->members;
  return newSet;
}
