#include <stdio.h>
#include "fila.h"

int main(void){
    Fila* oi = fila_cria();
    fila_insere(oi, 10);

    printf("%d", oi->ini);
    return 0;
}