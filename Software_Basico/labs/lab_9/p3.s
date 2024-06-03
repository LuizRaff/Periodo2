.text
.globl foo
foo:
	pushq 	%rbp # salva base do RA

  movl  $0, %r12d # i (r12d) = 0
  movl  $0, %r14d # s (r13d) = 0

LOOP:
  cmpl %esi, %r12d # if(n < i)
  jae  FIM

  movq  %rdi, %r10  # r10 = a

  movl  %r12d, %r13d  # tmp = i
  imull $4, %r13d
  addq  %r13, %r10 # r10[tmp]

  addl  (%r10), %r14d # s += r10[tmp]

  cmpl  $0, (%r10)
  je L1

  addl  $1, %r12d
  jmp LOOP

L1:
  movl  %r14d, (%r10)
  movl  $0, %r14d
  jmp LOOP

FIM:
  popq %rbp
  ret


