/*
int novonum(void) {
  int minhalocal;
  printf("numero: ");
  scanf("%d",&minhalocal);
  return minhalocal;
}
*/

.data
ps1:	.string	"numero: "
ps2:	.string "%d"

.text 
.global novonum
novonum:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp

	movq 	$ps1, %rdi
	call printf

	movq 	$ps2, %rdi
	leaq	-4(%rbp), %rsi
	call scanf

	movl 	-4(%rbp), %eax

	movq	%rbp, %rsp
	popq	%rbp
	ret