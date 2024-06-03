#include <stdio.h>

double piSeries(int n)
{
	int i;
	double fraction = 1.0;
	double denominator = 1.0;
	double pi = 0.0;
	for (i = 1; i <= n; i++)
	{
		fraction = 4.0 / denominator;
		if (i % 2){
			pi += fraction; // soma se contador de repeticao eh impar
		}else{
			pi -= fraction; // subtrai se contador de repeticao eh par
		}
		denominator += 2;
	}
	return pi;
}
int main(void)
{
	double pi;
	int n = 5000;
	pi = piSeries(n);
	printf("Gregory-Leibniz Series: PI = %.10lf", pi);

	return 0;
}