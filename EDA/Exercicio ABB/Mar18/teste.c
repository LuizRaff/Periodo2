#include <stdio.h>
#include "arvore.h"

int main() {
  ArvNo *a1 = cria_no(6, cria_no(2, cria_no(1, NULL, NULL),
                                    cria_no(4, NULL, NULL)),
                         cria_no(10, NULL,
                                     cria_no(15, NULL, NULL))
					           );
  ArvNo *a2 = cria_no(7, cria_no(3, cria_no(2, NULL, NULL), 
                                    NULL),
                         cria_no(15, cria_no(12, NULL, NULL),
                                     cria_no(19, cria_no(18, NULL, NULL), 
									                               NULL)
			                          )
					           );

  /* Mostra a arvore 1 */
  //      6
  //   2     10 
  // 1   4  -  15
  printf("----> Arvore 1:\n");
  imprime(a1);
  printf("\n");
  printf("Inserir 7 e 5\n");
  a1 = insere(a1, 7);
  a1 = insere(a1, 5);
  //       6
  //   2       10 
  // 1   4    7  15
  //       5
  imprime(a1);
  printf("\n");
  printf("Menor valor: %d\n", menor_valor(a1));
  printf("Maior valor: %d\n", maior_valor(a1));
  printf("Predecessor: %d\n", info(predecessor(a1)));
  printf("Sucessor: %d\n",    info(sucessor(a1)));

  printf("Remove 6\n");
  a1 = retira(a1, 6);
  //       7
  //   2       10 
  // 1   4    -  15
  //       5
  imprime(a1);
  printf("\n");
  printf("Remove 4\n");
  a1 = retira(a1, 4);
  //       7
  //   2       10 
  // 1   5    -  15
  //       -
  imprime(a1);
  printf("\n");
  printf("Remove 5\n");
  a1 = retira(a1, 5);
  //       7
  //   2       10 
  // 1   -    -  15
  //       -
  imprime(a1);
  printf("\n");

  /* Mostra a arvore 2 */
  //      7
  //   3       15 
  // 2   -  12    19
  //            18
  printf("----> Arvore 2:\n");
  imprime(a2);
  printf("\n");
  printf("Inserir 4, 5, 6, 13, 22 e 30\n");
  a2 = insere(a2, 4);
  a2 = insere(a2, 5);
  a2 = insere(a2, 6);
  a2 = insere(a2, 13);
  a2 = insere(a2, 22);
  a2 = insere(a2, 30);
  //      7
  //   3          15 
  // 2   4     12     19
  //      5     13  18  22
  //       6              30
  imprime(a2);
  printf("\n");
  printf("Menor valor: %d\n", menor_valor(a2));
  printf("Maior valor: %d\n", maior_valor(a2));
  printf("Predecessor: %d\n", info(predecessor(a2)));
  printf("Sucessor: %d\n",    info(sucessor(a2)));
 
  return 0;
}
  