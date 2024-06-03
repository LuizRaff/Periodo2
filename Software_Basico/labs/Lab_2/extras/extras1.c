#include <stdio.h>

int islittle(void){
	int num = 1;
	return *((char*)&num) == 1;
}

void dump(void *p, int n){
	unsigned char *p1 = p;
	while(n--){
		printf("%p - %02x\n", p1, *p1);
		p1++;
	}

	return;
}

int main(void){
	if(islittle()){
		printf("Isso e um Little Endian!\n");
	}else{
		printf("Isso e um Big Endian!\n");
	}

	int i = 1;
	dump(&i, sizeof(i));

	return 0;
}