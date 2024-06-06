/*
float foo (double a, float b) {
  return (a+b)*(a-b);
}
*/

/*
float foo(double a, float b){
	double c = a + b;
	double d = a - b;
	double e = c * d;
	return e;
}
*/

.text
.global foo
foo:
	pushq	%rbp
	movq	%rsp, %rbp
	
	CVTSS2SD	%xmm1, %xmm1	# (double) b

	MOVSD	%xmm0, %xmm8			#	xmm8 = a
	ADDSD	%xmm1, %xmm8			# xmm8 + b

	MOVSD	%xmm0, %xmm9			# xmm9 = b
	SUBSD	%xmm1, %xmm9			# xmm9 - b

	MULSD	%xmm9, %xmm8			# xmm8 * xmm9

	MOVSD	%xmm8, %xmm0			# return xmm8

	popq	%rbp
	ret