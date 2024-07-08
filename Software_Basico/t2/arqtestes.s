.text
.global main
main:
movl	$10, %edi
movl	$20, %esi
// PROLOGO //
	pushq %RBP
	movq %rsp, %rbp
	subq $32, %rsp
	movq %r12, -8(%rsp)
	movq %r13, -16(%rsp)
	movq %r14, -24(%rsp)
	movq %r15, -32(%rsp)
//*********//

movl $0, %r10d
movl $1, %r11d
addl %r11d, %r10d
movl %r10d, %r12d
cmpl $0,%edi
jne l4
movl %r12d, %eax
movq -8(%rsp), %r12
movq -16(%rsp), %r13
movq -24(%rsp), %r14
movq -32(%rsp), %r15
movq %rbp, %rsp
popq %rbp
ret  
l4:
movl %r12d, %r10d
movl %edi, %r11d
imull %r11d, %r10d
movl %r10d, %r12d
movl %edi, %r10d
movl $1, %r11d
subl %r11d, %r10d
movl %r10d, %edi
cmpl $0, %edi
jne l4

// EPILOGO //
    movl %r12d, %eax
    movq -8(%rsp), %r12
    movq -16(%rsp), %r13
    movq -24(%rsp), %r14
    movq -32(%rsp), %r15
    movq %rbp, %rsp
    popq %rbp
    ret  
//*********//