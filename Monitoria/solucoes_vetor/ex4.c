#include <stdio.h>

void reverse(float* v, int n)
{
	int i, j;
	float temp;
	for (i = 0, j = n - 1; i < j; i++, j--)
	{
		temp = v[i];
		v[i] = v[j];
		v[j] = temp;
	}
}

void printFloatArray(float* v, int n)
{
	int i;
	for (i = 0; i < n; i++)
	printf("%f ", v[i]);
	printf("\n");
}

int main(void)
{
	float v[] = { 1, 2, 3, 4, 5 };
	int n = 5;

	printf("Vetor Original:\n");
	printFloatArray(v, n);

	reverse(v, n);
	printf("Vetor invertido:\n");
	printFloatArray(v, n);
	
	return 0;
}