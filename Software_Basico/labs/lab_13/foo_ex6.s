/*
int foo (int x) {
  return add(x);
}
*/

.text
.global foo
foo:
	pushq	%rbp

	jmp add

	popq	%rbp	
	ret