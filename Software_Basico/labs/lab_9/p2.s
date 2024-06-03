/*
int fat (int n){
	if (n==0) return 1;
	else return n*fat(n-1);
}
*/

/*
				DIC
Variaveis	Regostradores	RA
n 			edi				-16
parametro	r10d			-8
*/

.text
.global fat
fat:
	pushq	%rbp	# salva a base do RA da funcao chamadora
	movq	%rsp, %rbp	# cria a base do RA da funcao chamada
	subq	$16, %rsp # aloca espaco para o RA da funcao chamada

	# salvar o registradores callee-saved
	movq	%r15, -8(%rbp)

	cmpl	$0, %edi	# if (n == 0)
	jne	ELSE

	movl	$1, %eax	# valor de retorno
	jmp		FIM

ELSE:
	movl 	%edi, %r15d
	decl	%r15d		# n - 1

	movq	%rdi, -16(%rbp) # temporariamente salvei o valor de edi no RA
	movl	%r15d, %edi	# movendo o valor de r15d para edi porque ele e o primeiro paramtro a ser enviado para fat

	call 	fat

	movq	-16(%rbp), %rdi # edi agora contem n novamente
	imull	%edi, %eax	# n * fat(parametro)

FIM:	#	aqui e esperado que o valor de retorno ja esteja no EAX
	movq	-8(%rbp), %r15

	movq	%rbp, %rsp	# libera a RA
	popq	%rbp	# restaura a base do RA da funcao chamadora
	ret
