/*
int foo (int x) {
  return add(x);
}
*/

.text
.global foo
foo:
	pushq	%rbp

	call add

	popq	%rbp
	ret