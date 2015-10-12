	.file	"switch.c"
	.section	.rodata
	.align 4
.LC0:
	.string	"Enter an integer for i[0, -1, 1]: "
.LC1:
	.string	"%d"
.LC2:
	.string	"you printed 0"
.LC3:
	.string	"-1, that's not real!"
.LC4:
	.string	"the only one"
.LC5:
	.string	"no idea what that is.."
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	movl	$.LC0, (%esp)
	call	printf
	leal	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	__isoc99_scanf
	movl	28(%esp), %eax
	testl	%eax, %eax
	je	.L3
	cmpl	$1, %eax
	je	.L4
	cmpl	$-1, %eax
	je	.L5
	jmp	.L8
.L3:
	movl	$.LC2, (%esp)
	call	puts
	jmp	.L6
.L5:
	movl	$.LC3, (%esp)
	call	puts
	jmp	.L6
.L4:
	movl	$.LC4, (%esp)
	call	puts
	jmp	.L6
.L8:
	movl	$.LC5, (%esp)
	call	puts
	nop
.L6:
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
