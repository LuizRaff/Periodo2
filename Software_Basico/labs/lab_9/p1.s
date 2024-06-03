/*
int add (int a, int b, int c) {
  return a+b+c;
}
*/

.text
.global add
add:
	pushq	%rbp	# salva a base do RA da funcao chamadora

	movl	%edi, %eax
	addl	%esi, %eax
	addl	%edx, %eax

	popq	%rbp
	ret
