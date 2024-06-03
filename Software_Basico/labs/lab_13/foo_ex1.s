/*
int foo (int x) {
  return x+1;
}
*/

.global foo
foo:
	pushq	%rbp
	
	addl 	$1, %edi
	movl 	%edi, %eax

	popq 	%rbp
	ret