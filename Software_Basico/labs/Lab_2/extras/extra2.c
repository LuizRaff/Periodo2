#include <stdio.h>
#include <math.h>

void num2string(char* s, int num, int base){
	if(base < 10){
		if (num < base){
			return (char*)num;
		}
	}else{

	}
	return;
}

int main(void){
	num2string("oi", 198, 2);

	return 0;
}