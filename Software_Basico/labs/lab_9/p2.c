#include <stdio.h>

int fat(int);

int main(int argc, char* argv[]){
	int valor;
	int resultado;

	valor = atoi(argv[1]);
	resultado = fat(valor);
	printf("O fatorial de %d e %d\n", valor, resultado);
	
	return 0;
}