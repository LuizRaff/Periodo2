/*
#include <stdio.h>

int nums[4] = {65, -105, 111, 34};

int main (void) {
  int i;
  int s = 0;

  for (i=0;i<4;i++)
    s = s+nums[i];

  printf ("soma = %d\n", s);

  return 0;
}
*/

.data
nums:	.int	65, -105, 111, 34
sf:		.string	"soma = %d\n"

.text
.global main
main:
  pushq   %rbp

  movl  $0, %ebx  /* ebx = 0 */
  /*movq  $nums, %r12  /* r12 = &nums */
  movl  $0, %r13d # r13d = 0

L1:
  cmpl  $4, %ebx  # ebx == 4
  jae  FIM

  movq  $nums, %r10
  movl  %ebx, %r11d

  imull $4, %r11d
  addq  %r11, %r10

  addl  (%r10), %r13d

  addl  $1, %ebx
  jmp L1

FIM:
  /*************************************************************/
  /* este trecho imprime o valor de %eax (estraga %eax)  */
    movq    $sf, %rdi    /* primeiro parametro (ponteiro)*/
    movq    %r13, %rsi   /* segundo parametro  (inteiro) */
    call  printf       /* chama a funcao da biblioteca */
  /*************************************************************/

  popq %rbp
  ret
	