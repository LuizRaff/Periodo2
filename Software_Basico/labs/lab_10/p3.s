/*
struct X {
  int val1;
  int val2;
};

int f(int i, int v);

void boo (struct X *px, int n, int val) {
  while (n--) {
    px->val2 = f(px->val1, val);
    px++;
  }
}
*/

.text
.global boo
boo:
	pushq 	%rbp
	movq 	%rsp, %rbp
	subq	$32, %rsp

	movq 	%r12, -8(%rbp)
	movq 	%r13, -16(%rbp)
	movq 	%r14, -24(%rbp)

	movq 	%rdi, %r12  	# r12 -> px
	movl 	%esi, %r13d 	# r13d -> n
	movl 	%edx, %r14d 	# r14d -> val

LOOP:
	cmpl 	$0, %r13d
	je FIM

	subl  	$1, %r13d

	movl	(%r12), %edi
	movl 	%r14d, %esi
	call f

	addq 	$4, %r12

	movl 	%eax, (%r12)

	addq 	$4, %r12
	jmp LOOP

FIM:
	movq 	-8(%rbp), %r12
	movq 	-16(%rbp), %r13
	movq 	-24(%rbp), %r14

	movq 	%rbp, %rsp
	popq 	%rbp
	ret