#include <stdio.h>
void printSquareStar(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("*");
		printf("\n");
	}
}
int main(void)
{
	int n;
	printf("Entre numero: ");
	scanf("%d", &n);
	printSquareStar(n);
}
return 0;