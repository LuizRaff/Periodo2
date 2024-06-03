/*
int nums[5] = {3,-5,7,8,-2};

int main() {
  int i;
  int *p = nums;
  for (i = 0; i < 5; i++) {
    printf("%d\n", filtro(*p,LIM));
    p++;
  }
  return 0;
}
*/

# 		DICIONARIO		#
# var	->	reg	->	RA  #
# i 	->	ebx -> 	-8  #
# p 	-> 	r12 -> 	-16 #

.data
nums: .int 3, -5, 7, 8, -2
s1:   .string "%d\n"

.text
.globl main
main:
/* prologo */
 pushq %rbp
 movq  %rsp, %rbp
 subq  $16, %rsp
 movq  %rbx, -8(%rbp)
 movq  %r12, -16(%rbp)

/* coloque seu codigo aqui */
movl	$0, %ebx
movq	$nums, %r12
movl	$1, %r13d

L1:
cmpl 	$5, %ebx
je 	FIM

movl	(%r12), %edi
movl 	%r13d, %esi
call filtro

movq	$s1, %rdi
movl 	%eax, %esi
call printf # printf("%d\n", filtro(...))

addl	$1, %ebx
addq	$4, %r12
jmp	L1

FIM:
/* finalizacao */
 movq -8(%rbp), %rbx
 movq -16(%rbp), %r12
 leave
 ret

/* finalizacao */
 movq -8(%rbp), %rbx
 movq -16(%rbp), %r12
 leave
 ret