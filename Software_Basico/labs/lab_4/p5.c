#include <stdio.h>

void enter(void){
	printf("\n");
	return;
}

void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
}

int main(void){
	signed char sc = -1;
	unsigned int ui = sc;

	printf("%d\n", ui);
	printf("%u\n", ui);
	dump(&ui, sizeof(ui));

	enter();

	printf("%d\n", sc);
	printf("%u\n", sc);
	dump(&sc, sizeof(sc));

	enter();
	
	return 0;
}