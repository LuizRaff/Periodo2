#include <stdio.h>

int odd_ones(unsigned int x) {
  unsigned char* a = (unsigned char*)&x;
  int count = 0;

  for (int i = 0; i < 4; ++i)
  {
    unsigned char tmp = *(a + i);

    for (int j = 0; j< 8; ++j)
    {
      count += tmp & 1;
      tmp >>= 1;
    }
  }

  return count & 1;

}

int main() {
  printf("%x tem numero %s de bits\n",0x01010101,odd_ones(0x01010101) ? "impar":"par");
  printf("%x tem numero %s de bits\n",0x01030101,odd_ones(0x01030101) ? "impar":"par");
  return 0;
}