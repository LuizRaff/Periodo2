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

float int2float(int i){
  if(i == 0) return 0.0;

  unsigned int signal = getsig(i);
  if(signal) i = -i;

  unsigned int pos = 0, msk = i;
  while(msk != 1 ){
    pos++;
    msk = msk >> 1;
  }

  unsigned int exp = pos + 127;

  msk = 1;
  for (int i = 0; i < pos; ++i)
  {
    msk = msk << 1;
    msk = msk | 1;
  }
  //msk = ~(msk << (31 - pos));

  U u;
  unsigned int mantissa;
  if(pos < 24){
    printf("%d\n", pos);
    mantissa = (msk & i);
    u.i = makefloat(signal, exp, mantissa << (23 - pos));
  }else{
    printf("%d\n", pos);
    mantissa = (msk & i) >> (31 - 24);
    u.i = makefloat(signal, exp + 1, mantissa >> (23 - pos));
  }
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
