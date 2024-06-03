/*
int add2 (struct X *x) {
  if (x == NULL) return 0;
  else return x->val + add2(x->next);
}
*/

.text
.global add2
add2:
    pushq   %rbp            # Salva o ponteiro de base da pilha
    movq    %rsp, %rbp      # Estabelece a base da pilha
    subq    $16, %rsp       # Aloca espaço na pilha para variáveis locais

    movq 	%r12, -8(%rbp)
    movq 	%r13, -16(%rbp)


	movq 	%rdi, %r12

    cmpq    $0, %r12        # Verifica se o ponteiro é nulo
    jne ELSE            # Se for nulo, vá para ELSE

    movl 	$0, %eax
    jmp FIM

ELSE:
	movl 	(%r12), %r13d

	addq 	$8, %r12
	movq 	(%r12), %r10
	movq 	%r10, %rdi
	call add2

	addl 	%eax, %r13d
	movl 	%r13d, %eax

FIM:
  movq  -8(%rbp),%r12
  movq  -16(%rbp), %r13

movq 	%rbp, %rsp
popq 	%rbp
ret