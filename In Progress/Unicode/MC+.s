	.file	"MC+.c"
	.text
	.def	printf;	.scl	3;	.type	32;	.endef
	.seh_proc	printf
printf:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	48(%rsp), %rbp
	.seh_setframe	%rbp, 48
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	%rdx, 40(%rbp)
	movq	%r8, 48(%rbp)
	movq	%r9, 56(%rbp)
	leaq	40(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rbx
	movl	$1, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rax, %rcx
	movq	32(%rbp), %rax
	movq	%rbx, %r8
	movq	%rax, %rdx
	call	__mingw_vfprintf
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "Hello World\12\0"
.LC1:
	.ascii "Enter the Code: \0"
.LC2:
	.ascii "\12The Given Code Is: \0"
.LC3:
	.ascii "\12The Unicode: \0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	subq	$368, %rsp
	.seh_stackalloc	368
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	call	__main
	movq	$8998, 80(%rbp)
	movq	$0, 88(%rbp)
	movq	$0, 96(%rbp)
	movq	$0, 104(%rbp)
	movq	$0, 112(%rbp)
	movq	$0, 120(%rbp)
	movq	$0, 128(%rbp)
	movq	$0, 136(%rbp)
	movq	$0, 144(%rbp)
	movq	$0, 152(%rbp)
	movq	$0, 160(%rbp)
	movq	$0, 168(%rbp)
	movq	$0, 176(%rbp)
	movq	$0, 184(%rbp)
	movq	$0, 192(%rbp)
	movq	$0, 200(%rbp)
	movq	$0, 208(%rbp)
	movq	$0, 216(%rbp)
	movq	$0, 222(%rbp)
	movq	$0, -80(%rbp)
	movq	$0, -72(%rbp)
	movq	$0, -64(%rbp)
	movq	$0, -56(%rbp)
	movq	$0, -48(%rbp)
	movq	$0, -40(%rbp)
	movq	$0, -32(%rbp)
	movq	$0, -24(%rbp)
	movq	$0, -16(%rbp)
	movq	$0, -8(%rbp)
	movq	$0, 0(%rbp)
	movq	$0, 8(%rbp)
	movq	$0, 16(%rbp)
	movq	$0, 24(%rbp)
	movq	$0, 32(%rbp)
	movq	$0, 40(%rbp)
	movq	$0, 48(%rbp)
	movq	$0, 56(%rbp)
	movq	$0, 62(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	printf
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	printf
	leaq	-80(%rbp), %rax
	movq	%rax, %rcx
	call	gets
	leaq	-80(%rbp), %rdx
	leaq	80(%rbp), %rax
	movq	%rax, %rcx
	call	strcat
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	printf
	leaq	80(%rbp), %rax
	movq	%rax, %rcx
	call	puts
	leaq	80(%rbp), %rax
	movq	%rax, %rcx
	call	strlen
	subl	$1, %eax
	movl	%eax, -84(%rbp)
	movl	$1, -88(%rbp)
	jmp	.L4
.L6:
	movl	-88(%rbp), %eax
	cltq
	movzbl	80(%rbp,%rax), %edx
	movzbl	-78(%rbp), %eax
	cmpb	%al, %dl
	jne	.L5
	leaq	-84(%rbp), %rcx
	leaq	-88(%rbp), %rdx
	leaq	80(%rbp), %rax
	movq	%rcx, %r8
	movq	%rax, %rcx
	call	shitf
.L5:
	movl	-88(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -88(%rbp)
.L4:
	movl	-88(%rbp), %edx
	movl	-84(%rbp), %eax
	cmpl	%eax, %edx
	jl	.L6
	leaq	.LC3(%rip), %rax
	movq	%rax, %rcx
	call	printf
	leaq	80(%rbp), %rax
	movq	%rax, %rcx
	call	puts
	movl	$0, %eax
	addq	$368, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	shitf
	.def	shitf;	.scl	2;	.type	32;	.endef
	.seh_proc	shitf
shitf:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	%r8, 32(%rbp)
	movq	32(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -4(%rbp)
	jmp	.L9
.L10:
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	leaq	3(%rdx), %rcx
	movq	16(%rbp), %rdx
	addq	%rcx, %rdx
	movzbl	(%rax), %eax
	movb	%al, (%rdx)
	subl	$1, -4(%rbp)
.L9:
	movq	24(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, -4(%rbp)
	jg	.L10
	movq	24(%rbp), %rax
	movl	(%rax), %eax
	movslq	%eax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movb	$59, (%rax)
	movq	24(%rbp), %rax
	movl	(%rax), %eax
	cltq
	leaq	1(%rax), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movb	$32, (%rax)
	movq	24(%rbp), %rax
	movl	(%rax), %eax
	cltq
	leaq	2(%rax), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movb	$35, (%rax)
	movq	24(%rbp), %rax
	movl	(%rax), %eax
	cltq
	leaq	3(%rax), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movb	$38, (%rax)
	movq	24(%rbp), %rax
	movl	(%rax), %eax
	leal	3(%rax), %edx
	movq	24(%rbp), %rax
	movl	%edx, (%rax)
	movq	32(%rbp), %rax
	movl	(%rax), %eax
	leal	3(%rax), %edx
	movq	32(%rbp), %rax
	movl	%edx, (%rax)
	nop
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (Rev4, Built by MSYS2 project) 12.2.0"
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
	.def	gets;	.scl	2;	.type	32;	.endef
	.def	strcat;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	strlen;	.scl	2;	.type	32;	.endef
