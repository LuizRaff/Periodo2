/*
struct X {
  int val;
  struct X *next;
};

int add (struct X *x) {
  int a = 0;
  for (; x != NULL; x = x->next)
    a += x->val;
  return a;
}
*/

.text
.global add
add:
pushq	%rbp
movq	%rsp, %rbp
subq	$16, %rsp

movq	%r12, -8(%rbp)	# r12d -> a
movq	%r13, -16(%rbp)	# r13 -> x

movl 	$0, %r12d
movq 	%rdi, %r13

loop:
cmpq 	$0, %r13
je	FIM

addl 	(%r13), %r12d

addq 	$8, %r13
movq	(%r13), %r13

jmp loop

FIM:
movl 	%r12d, %eax

movq -16(%rbp), %r13
movq -8(%rbp), %r12

movq 	%rbp, %rsp
popq	%rbp
ret
