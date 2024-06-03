#include <stdio.h>

typedef union { 
  float f;
  unsigned int i;
 } U;

#define getsig(x)  ((x)>>31 & 1)
#define getexp(x)  ((x)>>23 & 0xff)
#define getfrac(x) ((x) & 0x7fffff)
#define makefloat(s,e,f) ((s & 1)<<31 | (((e) & 0xff) << 23) | ((f) & 0x7fffff))

float float2(float f){
	unsigned sinal, expoente, fracao;
	U u;
	u.f = f;
	
	sinal = getsig(u.i);
    expoente = getexp(u.i);
    fracao = getfrac(u.i);
	expoente++;

	u.i = makefloat(sinal, expoente, fracao);
	return u.f;
}

int main(void){
	float f;
	f = 2;
	printf("%f\n", float2(f));
	f = 5;
	printf("%f\n", float2(f));
	f = 12;
	printf("%f\n", float2(f));
	f = -5;
	printf("%f\n", float2(f));
	f = 1.576;
	printf("%f\n", float2(f));
	f = 57;
	printf("%f\n", float2(f));
	return 0;
}