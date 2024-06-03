#include <stdio.h>
unsigned long long fat(int n)
{
	unsigned long long f = 1ull;
	while (n > 1)
		f *= n--;
	return f;
}
int main(void)
{
	int n;
	do
	{
		printf("Entre numero (-1 para sair): ");
		scanf("%d", &n);
		if (n >= 0)
			printf("%d! = %llu\n", n, fat(n));
	} while (n >= 0);
	return 0;
}