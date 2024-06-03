#include <stdlib.h>
#include <stdio.h>

int* pares(int* v, int n, int* qt)
{
	int i, j;
	int* w;

	// percorre v para calcular quantidade de pares
	for (i = 0, *qt = 0; i < n; i++)
		if (v[i] % 2 == 0)
			(*qt)++;

	w = (int*)malloc(*qt * sizeof(int));
	if (w == NULL) return NULL;
	// percorre novamente para preencher novo vetor
	if (*qt)
		for (i = 0, j = 0; i < n; i++)
			if (v[i] % 2 == 0)
				w[j++] = v[i];

	return w;
}

void printIntArray(int* v, int n)
{
	int i;
	for (i = 0; i < n; i++)
	printf("%d ", v[i]);
	printf("\n");
}

int main(void)
{
	int v[] = { 3, 4, 5, 6, 8, 9 };
	// int v[] = {3, 5, 7};
	int n = sizeof(v) / sizeof(v[0]);
	int* w;
	int m;

	printf("vetor original: ");
	printIntArray(v, n);
	
	w = pares(v, n, &m);
	if (w == NULL)
	{
		printf("Out of memory, malloc failed\n");
		exit(1);
	}
	
	printf("vetor pares: ");
	printIntArray(w, m);
	
	if (m == 0)
		printf("no even elements found\n");
	
	free(w);
	
	return 0;
}