/*
int f(int x);

void map2 (int* um, int * outro, int n) {
  int i;
  for (i=0; i<n; i++)
    *(outro+i) = f(*(um+i));
}
*/

.text
.global map2
map2:
  pushq  %rbp
  
  movl   $0, %r12d   # r12d -> i
  movq   %rdi, %r13  # r13 -> um
  movq   %rsi, %r14  # r14 -> outro
  movl   %edx, %r15d # r15d -> n

LOOP:
  cmpl   %r15d, %r12d
  jae   FIM

  /* INDEXAÇÃO */
  movl   %r12d, %r10d
  imull  $4, %r10d

  movq   %r13, %r11
  addq   %r10, %r11

  movl   (%r11), %edi
  call f

  movq   %r14, %r11
  addq   %r10, %r11
  movl   %eax, (%r11)

  addl   $1, %r12d
  jmp LOOP

FIM:
  popq   %rbp
  ret