.data
Sf:	.string "%d\n"

.text
.global main
main:
pushq %rbp

movl	$1,	%r12d

L1:
cmpl	$11, %r12d
je L2

movl    %r12d, %eax
imull	%eax,	%eax
/*************************************************************/
/* este trecho imprime o valor de %eax (estraga %eax)  */
  movq    $Sf, %rdi    /* primeiro parametro (ponteiro)*/
  movl    %eax, %esi   /* segundo parametro  (inteiro) */
  call  printf       /* chama a funcao da biblioteca */
/*************************************************************/

addl	$1, %r12d
jmp L1

L2:
popq  %rbp
ret