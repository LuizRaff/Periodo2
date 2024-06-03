#include <stdio.h>
void dump (void *p, int n) {
unsigned char *p1 = (unsigned char *) p;
int a;
while (n--) {
printf("%p - %02x\n", p1, *p1);
a++;
p1++;
}
printf("%d\n",a);
}
struct Ficha {
char i;
struct Ficha *v;
int p;
};
int main (void) {
struct Ficha f[1] = {{'e', f, -3}};
dump (&f, sizeof(struct Ficha));
return 0;
}