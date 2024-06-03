#include <stdio.h>
float f(float x)
{
	if (x <= 1)
		return x*x;
	else
		return 6 - x;
}
int main(void)
{
	float x0, delta, x;
	int maxn, i;
	printf("Entre x inicial, incremento e numero maximo de pontos\n");
	scanf("%f %f %d", &x0, &delta, &maxn);
	printf("x
		\tf(x)\n");
	for (x=x0, i = 0; i < maxn; i++, x+=delta)
		printf("%7.2f\t%7.2f\n", x, f(x));
	return 0;
}