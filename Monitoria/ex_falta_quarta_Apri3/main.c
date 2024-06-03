#include <stdio.h>
#include <stdlib.h>

void circle1(float r, float* per, float* area);
void circle2(float r, float* v);
float * circle3(float r, float* v);

int main(void){
	float per, area;
	float r = 1.0;
	circle1(r, &per, &area);
	printf("circle1: per= %.2f area= %.2f\n", per, area);
	
	float v[2];
	circle2(r, v);
	printf("circle2 vetor v: per= %.2f area= %.2f\n", v[0], v[1]);
	
	r = 2;
	float * w;
	w = circle3(r, v);
	printf("circle3 vetor v: per= %.2f area= %.2f\n", v[0], v[1]);
	printf("circle3 via pointer w: per= %.2f area= %.2f\n", *w, *(w+1));
	printf("circle3 via pointer w com notacao indice: per= %.2f area= %.2f\n", w[0], w[1]);
	return 0;
}

void circle1(float r, float* per, float* area){
	float PI = 3.14159;
	*per = PI * 2 * r;
	*area = PI * r * r;

	return;
}

void circle2(float r, float* v)
{
	float PI = 3.14159;
	v[0] = 2 * PI * r;
	v[1] = PI * r * r;

	return;
}

float * circle3(float r, float* v)
{
	float PI = 3.14159;
	v[0] = 2 * PI * r;
	v[1] = PI * r * r;

	return v;
}