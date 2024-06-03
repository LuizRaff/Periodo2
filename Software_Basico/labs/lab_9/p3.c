#include <stdio.h>

void foo(int a[], int n);

void fooFuncionando(int a[], int n) {
  int i;
  int s = 0;
  for (i=0; i<n; i++) {
    s += a[i];
    if (a[i] == 0) {
      a[i] = s;
      s = 0;
    }
  }
}

int main(void){
	int a1[4] = {2, 0, 3, 4};
	int a2[4] = {2, 0, 3, 4};

	int n = 4;

	foo(a1, n);
	fooFuncionando(a2, n);

	printf("Funcao foo do assembly: \n");
	for (int i = 0; i < n; ++i)
	{
		printf("%d\n", a1[i]);
	}

	printf("Funcao foo do C: \n");
	for (int i = 0; i < n; ++i)
	{
		printf("%d\n", a2[i]);
	}

	return 0;
}