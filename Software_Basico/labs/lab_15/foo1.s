/*
float foo1 (float a, float b) {
  return sin(a) + b;
}
*/

.text
.global foo1
foo1:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp

	movss	%xmm0, -4(%rbp)
	movss	%xmm1, -8(%rbp)

	call sin

	movss	-8(%rbp), %xmm9
	addss	%xmm9, %xmm0

	movq 	%rbp, %rsp
	popq	%rbp
	ret