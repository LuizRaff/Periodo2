#include <stdio.h>
#include <math.h>

float controle(float a, float b){
	return sin(a) + b;
}

float foo1(float a, float b);

int main(void){
	printf("%.2f : %.2f\n", controle(2.2, 3.2), foo1(2.2, 3.2));
	printf("%.2f : %.2f\n", controle(4.2, 1.2), foo1(4.2, 1.2));
	printf("%.2f : %.2f\n", controle(2.3, 2.2), foo1(2.3, 2.2));
	printf("%.2f : %.2f\n", controle(4.21, 6.2), foo1(4.21, 6.2));

	return 0;
}