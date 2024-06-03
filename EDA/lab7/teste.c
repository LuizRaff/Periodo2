#include <stdio.h>
#include <stdlib.h>
#include "arvb23.h"

int main (void) {
  ArvB23 *b = cria();
  int chave;
  
  // while (1) {
  //   printf ("chave a inserir (-111 para terminar): ");
  //   scanf ("%d", &chave);
  //   if (chave==-111) break;

  //   b = insere(b, chave);
  //   printf("arvore: \n");
  //   mostra(b);
  // }

  for (int i = 0; i < 8; ++i)
  {
    chave = rand() % 15;
    printf("Chave %d inserida.\n", chave);

    b = insere(b, chave);
    printf("arvore: \n");
    mostra(b);
  }

  
  for (int i = 0; i < 8; ++i)
  {
    int c = (rand() + i) % 15;
    int a = existe(b,c);
    if(a != -1){
      printf("%d Existe no nivel %d\n", c,a);
    }else{
      printf("%d Não existe na arvore\n", c);
    }

  }

  destroi(b); 
  return 0;
}    
