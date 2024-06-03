#include <stdlib.h>
#include <stdio.h>

float* reverse(float* v, int n)
{
	int i = 0, j = n - 1; //inicio e fim do vetor

	float* w = (float*)malloc(n * sizeof(float));
	if (w == NULL) return NULL;

	while (i < n)
		w[i++] = v[j--];
	
	return w;
}
/*
// alternativa
float * reverse(float * v, int n)
{
	int i, j;
	float * w = (float *)malloc(n * sizeof(float));
	if (w == NULL) return NULL;
	for (i = 0, j = n - 1; i < n; i++, j--)
	w[i] = v[j];
	return w;
}
*/

void printFloatArray(float* v, int n)
{
	int i;
	for (i = 0; i < n; i++)
	printf("\t%.2f", v[i]);
	printf("\n");
}

int main(void)
{
	float v[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(v)/sizeof(v[0]);
	float* w;

	printf("Vetor Original:\n");
	printFloatArray(v, n);

	w = reverse(v, n);
	if (w == NULL)
	{
		printf("Out of memory, malloc failed\n");
		exit(1);
	}

	printf("Vetor invertido:\n");
	printFloatArray(w, n);

	free(w);
	
	return 0;
}