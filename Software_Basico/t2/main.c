#include <stdlib.h>
#include "compilalinb.h"

#define TAM_CODIGO 2000

int main(void) {
  unsigned char codigo[TAM_CODIGO];
  FILE* myfp;
  funcp f;
  int retorno;
  
  if ((myfp = fopen ("programa.txt", "r")) == NULL) {
    perror ("nao conseguiu abrir arquivo!");
    exit(1);
  }


  f = compilaLinB(myfp, codigo);

  retorno = (f)(10, 5); /* se a função não recebe parametros, são descartados */

  printf("resultado =  %d\n",retorno);
  }