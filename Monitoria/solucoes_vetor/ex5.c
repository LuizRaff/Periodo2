#include <stdio.h>
#include <stdlib.h>

int** cria2d(int nLin, int nCol)
{
	int** v;
	int i, j;
	v = (int**)malloc(nLin * sizeof(int*));
	if (v == NULL) return NULL;
	for (i = 0; i < nLin; i++)
	{
		v[i] = (int*)malloc(nCol * sizeof(int));
		if (v[i] == NULL) return NULL;
			for (j = 0; j < nCol; j++)
				*(v[i] + j) = 0;
	}
	return v;
}

void print2d(int** v, int nLin, int nCol)
{
	int i, j;
	for (i = 0; i < nLin; i++)
	{
		for (j = 0; j < nCol; j++)
			printf("%d ", v[i][j]);
		printf("\n");
	}
}

int** zeroTo1(int** v, int nLin, int nCol)
{
	int i, j;
	for (i = 0; i < nLin; i++)
	{
		for (j = 0; j < nCol; j++)
			if (i == j)
				v[i][j] = 1;
	}
	return v;
}

void libera2d(int** v, int nLin)
{
	int i;
	for (i = 0; i < nLin; i++)
		free(v[i]);
	free(v);
}

int main(void)
{
	int** v;
	int n, m;
	n = m = 3;
	v = cria2d(n, m);
	if (v == NULL)

	{
	printf("Out of memory, malloc failed\n");
	exit(1);
	}
	printf("Matrix %dx%d criada:\n", n, m);
	print2d(v, n, m);
	v = zeroTo1(v, n, m);
	printf("Identity:\n");
	print2d(v, n, m);
	libera2d(v, n);
	printf("Memoria liberada\n");
	return 0;
}