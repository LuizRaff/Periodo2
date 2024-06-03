#include <stdio.h>
#include <math.h>

#define getsig(x)        ((x)>>31 & 1)
#define getexp(x)        ((x)>>23 & 0xff)
#define getfrac(x)       ((x) & 0x7fffff)
#define makefloat(s,e,f) ((s & 1)<<31 | (((e) & 0xff) << 23) | ((f) & 0x7fffff))

typedef union {
  float f;
  unsigned int i;
} U;

void exibe_bin(unsigned int j){
  for (int i = 0; i < 31; ++i)
  {
    printf("%d", j & 1);
    j = j >> 1;
  }
  printf("\n");
}

float int2float(int i){
  if(i == 0){
    return 0.0f;
  };

  unsigned int signal = getsig(i);
  if(signal){
    i = abs(i);
  }
  printf("\n");
  unsigned int exp = i;
  int pos = 0;
  while(exp != 1){
    pos++;
    exp = exp >> 1;
  }
  exp = pos + 127;

  unsigned int msk = 0;

  for (int j = 0; j < pos; ++j)
  {
    msk = msk << 1;
    msk = msk | 1;
  }

  unsigned int mantissa = i & msk;
  U u;
  u.i = makefloat(signal, exp, mantissa);
  return u.f;
}

int main() {
   int i;

   printf("\n******** int2float ****************\n");
   i = 0;
   printf(" %d ->\t\t%+10.4f\n", i, int2float(i));
   i = 1; 
   printf(" %d ->\t\t%+10.4f\n", i, int2float(i));
   i = -1;  
   printf(" %d ->\t\t%+10.4f\n", i, int2float(i));
   i = 0x7fffffff;  
   printf(" %d ->\t%+10.4f\n", i, int2float(i));
   i = -i;
   printf(" %d ->\t%+10.4f\n", i, int2float(i));
   i = 12345;
   printf(" %d ->\t%+10.4f\n", i, int2float(i));
   i = -12345;
   printf(" %d ->\t%+10.4f\n", i, int2float(i));
   return 0;
}
