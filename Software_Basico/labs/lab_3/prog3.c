#include <stdio.h>

// a)
unsigned char switch_byte(unsigned char x){
	return (x << 4) | (x >> 4);
}

// b)
unsigned char rotate_left(unsigned char x, int n){
	return (x << n) | (x >> (8 - n));
}

int main(void){
	// a)
	printf("\na)\n");
	printf("0x%02x => %02x\n", 0x9c, switch_byte(0x9c));
	printf("0x%02x => %02x\n", 0xab, switch_byte(0xab));
	printf("0x%02x => %02x\n", 0x01, switch_byte(0x01));
	printf("0x%02x => %02x\n", 0xfe, switch_byte(0xfe));

	// b)
	printf("\nb)\n");
	printf("0x61 com 'left_rotation' de 1 bit: 0x%02x\n", rotate_left(0x61, 1));
	printf("0x61 com 'left_rotation' de 2 bit: 0x%02x\n", rotate_left(0x61, 2));
	printf("0x61 com 'left_rotation' de 7 bit: 0x%02x\n", rotate_left(0x61, 7));

	return 0;
}