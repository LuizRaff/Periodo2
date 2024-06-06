#include <stdio.h>

double controle(double a, float b){
	return (a + b) * (a - b);
}
double foo(double a, float b);

int main(void){
	printf("%.2f : %.2f\n", controle(2.2, 3.2), foo(2.2, 3.2));
	printf("%.2f : %.2f\n", controle(4.2, 1.2), foo(4.2, 1.2));
	printf("%.2f : %.2f\n", controle(2.3, 2.2), foo(2.3, 2.2));
	printf("%.2f : %.2f\n", controle(4.21, 6.2), foo(4.21, 6.2));

	return 0;
}