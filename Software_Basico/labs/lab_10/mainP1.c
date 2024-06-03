#include <stdio.h>
#define MAX 10 /* MAX tem que ser maior que 1!!!! */


struct X {
  int val;
  struct X *next;
};

int add2C (struct X *x) {
  if (x == NULL) return 0;
  else return x->val + add2C(x->next);
}

int addC (struct X *x) {
  int a = 0;
  for (; x != NULL; x = x->next)
    a += x->val;
  return a;
}

int add (struct X *x);
int add2 (struct X *x);

int main (void) {

  struct X x[MAX];
  int i;

  for (i=0;i<MAX;i++)
    x[i].val = i;

  for (i=MAX-1;i>1;i--)
    x[i].next = &(x[i-1]);
  x[0].next = &(x[MAX-1]);
  x[1].next = NULL;


  printf ("resultado de add: %d\n", add(x));
  printf ("resultado de add2: %d\n", add2(x));


  printf ("resultado de addc: %d\n", addC(x));
  printf ("resultado de add2c: %d\n", add2C(x));
  return 0;
}