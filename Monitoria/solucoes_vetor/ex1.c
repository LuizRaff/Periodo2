#include <stdio.h>

void maxmin(int* v, int n, int* max, int* min)
{
	int i;
	*min = *max = v[0];
	for (i = 0; i < n; i++)
	{
		if (v[i] > *max)
			*max = v[i];
		if (v[i] < *min)
			*min = v[i];
	}
}

int main(void)
{
	int v[10];
	int i, n, max, min;

	printf("Entre tamanho do vetor (max 10): ");
	scanf("%d", &n);

	printf("Entre elementos do vetor:\n");
	for (i = 0; i < n; i++){
		scanf("%d", &v[i]);
	}

	maxmin(v, n, &max, &min);
	printf("max= %d min=%d\n", max, min);
	
	return 0;
}