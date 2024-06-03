/*
int bemboba (int num) {
  int local[4];
  int *a;
  int i;

  for (i=0,a=local;i<4;i++) {
    *a = num;
    a++;
  }
  return addl (local, 4);
}
*/

.data
local:	.int	0, 0, 0, 0

.text
.global bemboba
bemboba:
	pushq 	%rbp

	movl 	$0, %r12d
	movq	$local, %r13

LOOP:
	cmpl	$4, %r12d 	# if(r12d == 4)
	jae	FIM

	movl	%edi, (%r13)

	addq	$4, %r13
	addl 	$1, %r12d
	jmp LOOP

FIM:
	movq	$local, %rdi
	movl 	$4, %esi
	call addl

	popq	%rbp
	ret