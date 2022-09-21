	.file	"test.cpp"
	.text
	.section	.text._ZnwmPv,"axG",@progbits,_ZnwmPv,comdat
	.weak	_ZnwmPv
	.type	_ZnwmPv, @function
_ZnwmPv:
.LFB286:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE286:
	.size	_ZnwmPv, .-_ZnwmPv
	.section	.rodata
	.type	_ZStL19piecewise_construct, @object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.zero	1
	.type	_ZStL13allocator_arg, @object
	.size	_ZStL13allocator_arg, 1
_ZStL13allocator_arg:
	.zero	1
	.type	_ZStL6ignore, @object
	.size	_ZStL6ignore, 1
_ZStL6ignore:
	.zero	1
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.text._ZNSt15_Rb_tree_headerC2Ev,"axG",@progbits,_ZNSt15_Rb_tree_headerC5Ev,comdat
	.align 2
	.weak	_ZNSt15_Rb_tree_headerC2Ev
	.type	_ZNSt15_Rb_tree_headerC2Ev, @function
_ZNSt15_Rb_tree_headerC2Ev:
.LFB3805:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$0, (%rax)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt15_Rb_tree_header8_M_resetEv
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3805:
	.size	_ZNSt15_Rb_tree_headerC2Ev, .-_ZNSt15_Rb_tree_headerC2Ev
	.weak	_ZNSt15_Rb_tree_headerC1Ev
	.set	_ZNSt15_Rb_tree_headerC1Ev,_ZNSt15_Rb_tree_headerC2Ev
	.section	.text._ZNSt15_Rb_tree_header8_M_resetEv,"axG",@progbits,_ZNSt15_Rb_tree_header8_M_resetEv,comdat
	.align 2
	.weak	_ZNSt15_Rb_tree_header8_M_resetEv
	.type	_ZNSt15_Rb_tree_header8_M_resetEv, @function
_ZNSt15_Rb_tree_header8_M_resetEv:
.LFB3811:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	$0, 8(%rax)
	movq	-8(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 16(%rax)
	movq	-8(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 24(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 32(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3811:
	.size	_ZNSt15_Rb_tree_header8_M_resetEv, .-_ZNSt15_Rb_tree_header8_M_resetEv
	.section	.rodata
	.align 4
	.type	_ZN9__gnu_cxxL21__default_lock_policyE, @object
	.size	_ZN9__gnu_cxxL21__default_lock_policyE, 4
_ZN9__gnu_cxxL21__default_lock_policyE:
	.long	2
	.type	_ZStL10defer_lock, @object
	.size	_ZStL10defer_lock, 1
_ZStL10defer_lock:
	.zero	1
	.type	_ZStL11try_to_lock, @object
	.size	_ZStL11try_to_lock, 1
_ZStL11try_to_lock:
	.zero	1
	.type	_ZStL10adopt_lock, @object
	.size	_ZStL10adopt_lock, 1
_ZStL10adopt_lock:
	.zero	1
	.align 4
	.type	_ZNSt15regex_constantsL5icaseE, @object
	.size	_ZNSt15regex_constantsL5icaseE, 4
_ZNSt15regex_constantsL5icaseE:
	.long	1
	.align 4
	.type	_ZNSt15regex_constantsL6nosubsE, @object
	.size	_ZNSt15regex_constantsL6nosubsE, 4
_ZNSt15regex_constantsL6nosubsE:
	.long	2
	.align 4
	.type	_ZNSt15regex_constantsL8optimizeE, @object
	.size	_ZNSt15regex_constantsL8optimizeE, 4
_ZNSt15regex_constantsL8optimizeE:
	.long	4
	.align 4
	.type	_ZNSt15regex_constantsL7collateE, @object
	.size	_ZNSt15regex_constantsL7collateE, 4
_ZNSt15regex_constantsL7collateE:
	.long	8
	.align 4
	.type	_ZNSt15regex_constantsL10ECMAScriptE, @object
	.size	_ZNSt15regex_constantsL10ECMAScriptE, 4
_ZNSt15regex_constantsL10ECMAScriptE:
	.long	16
	.align 4
	.type	_ZNSt15regex_constantsL5basicE, @object
	.size	_ZNSt15regex_constantsL5basicE, 4
_ZNSt15regex_constantsL5basicE:
	.long	32
	.align 4
	.type	_ZNSt15regex_constantsL8extendedE, @object
	.size	_ZNSt15regex_constantsL8extendedE, 4
_ZNSt15regex_constantsL8extendedE:
	.long	64
	.align 4
	.type	_ZNSt15regex_constantsL3awkE, @object
	.size	_ZNSt15regex_constantsL3awkE, 4
_ZNSt15regex_constantsL3awkE:
	.long	128
	.align 4
	.type	_ZNSt15regex_constantsL4grepE, @object
	.size	_ZNSt15regex_constantsL4grepE, 4
_ZNSt15regex_constantsL4grepE:
	.long	256
	.align 4
	.type	_ZNSt15regex_constantsL5egrepE, @object
	.size	_ZNSt15regex_constantsL5egrepE, 4
_ZNSt15regex_constantsL5egrepE:
	.long	512
	.align 4
	.type	_ZNSt15regex_constantsL12__polynomialE, @object
	.size	_ZNSt15regex_constantsL12__polynomialE, 4
_ZNSt15regex_constantsL12__polynomialE:
	.long	1024
	.align 4
	.type	_ZNSt15regex_constantsL13match_defaultE, @object
	.size	_ZNSt15regex_constantsL13match_defaultE, 4
_ZNSt15regex_constantsL13match_defaultE:
	.zero	4
	.align 4
	.type	_ZNSt15regex_constantsL13match_not_bolE, @object
	.size	_ZNSt15regex_constantsL13match_not_bolE, 4
_ZNSt15regex_constantsL13match_not_bolE:
	.long	1
	.align 4
	.type	_ZNSt15regex_constantsL13match_not_eolE, @object
	.size	_ZNSt15regex_constantsL13match_not_eolE, 4
_ZNSt15regex_constantsL13match_not_eolE:
	.long	2
	.align 4
	.type	_ZNSt15regex_constantsL13match_not_bowE, @object
	.size	_ZNSt15regex_constantsL13match_not_bowE, 4
_ZNSt15regex_constantsL13match_not_bowE:
	.long	4
	.align 4
	.type	_ZNSt15regex_constantsL13match_not_eowE, @object
	.size	_ZNSt15regex_constantsL13match_not_eowE, 4
_ZNSt15regex_constantsL13match_not_eowE:
	.long	8
	.align 4
	.type	_ZNSt15regex_constantsL9match_anyE, @object
	.size	_ZNSt15regex_constantsL9match_anyE, 4
_ZNSt15regex_constantsL9match_anyE:
	.long	16
	.align 4
	.type	_ZNSt15regex_constantsL14match_not_nullE, @object
	.size	_ZNSt15regex_constantsL14match_not_nullE, 4
_ZNSt15regex_constantsL14match_not_nullE:
	.long	32
	.align 4
	.type	_ZNSt15regex_constantsL16match_continuousE, @object
	.size	_ZNSt15regex_constantsL16match_continuousE, 4
_ZNSt15regex_constantsL16match_continuousE:
	.long	64
	.align 4
	.type	_ZNSt15regex_constantsL16match_prev_availE, @object
	.size	_ZNSt15regex_constantsL16match_prev_availE, 4
_ZNSt15regex_constantsL16match_prev_availE:
	.long	128
	.align 4
	.type	_ZNSt15regex_constantsL14format_defaultE, @object
	.size	_ZNSt15regex_constantsL14format_defaultE, 4
_ZNSt15regex_constantsL14format_defaultE:
	.zero	4
	.align 4
	.type	_ZNSt15regex_constantsL10format_sedE, @object
	.size	_ZNSt15regex_constantsL10format_sedE, 4
_ZNSt15regex_constantsL10format_sedE:
	.long	256
	.align 4
	.type	_ZNSt15regex_constantsL14format_no_copyE, @object
	.size	_ZNSt15regex_constantsL14format_no_copyE, 4
_ZNSt15regex_constantsL14format_no_copyE:
	.long	512
	.align 4
	.type	_ZNSt15regex_constantsL17format_first_onlyE, @object
	.size	_ZNSt15regex_constantsL17format_first_onlyE, 4
_ZNSt15regex_constantsL17format_first_onlyE:
	.long	1024
	.align 4
	.type	_ZNSt15regex_constantsL13error_collateE, @object
	.size	_ZNSt15regex_constantsL13error_collateE, 4
_ZNSt15regex_constantsL13error_collateE:
	.zero	4
	.align 4
	.type	_ZNSt15regex_constantsL11error_ctypeE, @object
	.size	_ZNSt15regex_constantsL11error_ctypeE, 4
_ZNSt15regex_constantsL11error_ctypeE:
	.long	1
	.align 4
	.type	_ZNSt15regex_constantsL12error_escapeE, @object
	.size	_ZNSt15regex_constantsL12error_escapeE, 4
_ZNSt15regex_constantsL12error_escapeE:
	.long	2
	.align 4
	.type	_ZNSt15regex_constantsL13error_backrefE, @object
	.size	_ZNSt15regex_constantsL13error_backrefE, 4
_ZNSt15regex_constantsL13error_backrefE:
	.long	3
	.align 4
	.type	_ZNSt15regex_constantsL11error_brackE, @object
	.size	_ZNSt15regex_constantsL11error_brackE, 4
_ZNSt15regex_constantsL11error_brackE:
	.long	4
	.align 4
	.type	_ZNSt15regex_constantsL11error_parenE, @object
	.size	_ZNSt15regex_constantsL11error_parenE, 4
_ZNSt15regex_constantsL11error_parenE:
	.long	5
	.align 4
	.type	_ZNSt15regex_constantsL11error_braceE, @object
	.size	_ZNSt15regex_constantsL11error_braceE, 4
_ZNSt15regex_constantsL11error_braceE:
	.long	6
	.align 4
	.type	_ZNSt15regex_constantsL14error_badbraceE, @object
	.size	_ZNSt15regex_constantsL14error_badbraceE, 4
_ZNSt15regex_constantsL14error_badbraceE:
	.long	7
	.align 4
	.type	_ZNSt15regex_constantsL11error_rangeE, @object
	.size	_ZNSt15regex_constantsL11error_rangeE, 4
_ZNSt15regex_constantsL11error_rangeE:
	.long	8
	.align 4
	.type	_ZNSt15regex_constantsL11error_spaceE, @object
	.size	_ZNSt15regex_constantsL11error_spaceE, 4
_ZNSt15regex_constantsL11error_spaceE:
	.long	9
	.align 4
	.type	_ZNSt15regex_constantsL15error_badrepeatE, @object
	.size	_ZNSt15regex_constantsL15error_badrepeatE, 4
_ZNSt15regex_constantsL15error_badrepeatE:
	.long	10
	.align 4
	.type	_ZNSt15regex_constantsL16error_complexityE, @object
	.size	_ZNSt15regex_constantsL16error_complexityE, 4
_ZNSt15regex_constantsL16error_complexityE:
	.long	11
	.align 4
	.type	_ZNSt15regex_constantsL11error_stackE, @object
	.size	_ZNSt15regex_constantsL11error_stackE, 4
_ZNSt15regex_constantsL11error_stackE:
	.long	12
	.align 8
	.type	_ZNSt8__detailL19_S_invalid_state_idE, @object
	.size	_ZNSt8__detailL19_S_invalid_state_idE, 8
_ZNSt8__detailL19_S_invalid_state_idE:
	.quad	-1
	.section	.text._ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE13_Rb_tree_implIS3_Lb1EED2Ev,"axG",@progbits,_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE13_Rb_tree_implIS3_Lb1EED5Ev,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE13_Rb_tree_implIS3_Lb1EED2Ev
	.type	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE13_Rb_tree_implIS3_Lb1EED2Ev, @function
_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE13_Rb_tree_implIS3_Lb1EED2Ev:
.LFB8294:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaISt13_Rb_tree_nodeIiEED2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8294:
	.size	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE13_Rb_tree_implIS3_Lb1EED2Ev, .-_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE13_Rb_tree_implIS3_Lb1EED2Ev
	.weak	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE13_Rb_tree_implIS3_Lb1EED1Ev
	.set	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE13_Rb_tree_implIS3_Lb1EED1Ev,_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE13_Rb_tree_implIS3_Lb1EED2Ev
	.section	.text._ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEEC2Ev,"axG",@progbits,_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEEC5Ev,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEEC2Ev
	.type	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEEC2Ev, @function
_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEEC2Ev:
.LFB8296:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE13_Rb_tree_implIS3_Lb1EEC1Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8296:
	.size	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEEC2Ev, .-_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEEC2Ev
	.weak	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEEC1Ev
	.set	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEEC1Ev,_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEEC2Ev
	.section	.text._ZNSt3setIiSt4lessIiESaIiEEC2Ev,"axG",@progbits,_ZNSt3setIiSt4lessIiESaIiEEC5Ev,comdat
	.align 2
	.weak	_ZNSt3setIiSt4lessIiESaIiEEC2Ev
	.type	_ZNSt3setIiSt4lessIiESaIiEEC2Ev, @function
_ZNSt3setIiSt4lessIiESaIiEEC2Ev:
.LFB8298:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEEC1Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8298:
	.size	_ZNSt3setIiSt4lessIiESaIiEEC2Ev, .-_ZNSt3setIiSt4lessIiESaIiEEC2Ev
	.weak	_ZNSt3setIiSt4lessIiESaIiEEC1Ev
	.set	_ZNSt3setIiSt4lessIiESaIiEEC1Ev,_ZNSt3setIiSt4lessIiESaIiEEC2Ev
	.section	.text._ZNSt3setIiSt4lessIiESaIiEED2Ev,"axG",@progbits,_ZNSt3setIiSt4lessIiESaIiEED5Ev,comdat
	.align 2
	.weak	_ZNSt3setIiSt4lessIiESaIiEED2Ev
	.type	_ZNSt3setIiSt4lessIiESaIiEED2Ev, @function
_ZNSt3setIiSt4lessIiESaIiEED2Ev:
.LFB8301:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEED1Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8301:
	.size	_ZNSt3setIiSt4lessIiESaIiEED2Ev, .-_ZNSt3setIiSt4lessIiESaIiEED2Ev
	.weak	_ZNSt3setIiSt4lessIiESaIiEED1Ev
	.set	_ZNSt3setIiSt4lessIiESaIiEED1Ev,_ZNSt3setIiSt4lessIiESaIiEED2Ev
	.text
	.globl	main
	.type	main, @function
main:
.LFB8290:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA8290
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$88, %rsp
	.cfi_offset 3, -24
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movl	$0, %edi
	call	time@PLT
	movl	%eax, %edi
	call	srand@PLT
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt3setIiSt4lessIiESaIiEEC1Ev
	movl	$0, -84(%rbp)
.L11:
	cmpl	$9, -84(%rbp)
	jg	.L10
	call	rand@PLT
	movl	%eax, -88(%rbp)
	leaq	-88(%rbp), %rdx
	leaq	-80(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB0:
	call	_ZNSt3setIiSt4lessIiESaIiEE6insertEOi
.LEHE0:
	addl	$1, -84(%rbp)
	jmp	.L11
.L10:
	movl	$0, %ebx
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt3setIiSt4lessIiESaIiEED1Ev
	movl	%ebx, %eax
	movq	-24(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L14
	jmp	.L16
.L15:
	endbr64
	movq	%rax, %rbx
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt3setIiSt4lessIiESaIiEED1Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB1:
	call	_Unwind_Resume@PLT
.LEHE1:
.L16:
	call	__stack_chk_fail@PLT
.L14:
	addq	$88, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8290:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA8290:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE8290-.LLSDACSB8290
.LLSDACSB8290:
	.uleb128 .LEHB0-.LFB8290
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L15-.LFB8290
	.uleb128 0
	.uleb128 .LEHB1-.LFB8290
	.uleb128 .LEHE1-.LEHB1
	.uleb128 0
	.uleb128 0
.LLSDACSE8290:
	.text
	.size	main, .-main
	.section	.text._ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE,"axG",@progbits,_ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE,comdat
	.weak	_ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE
	.type	_ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE, @function
_ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE:
.LFB8867:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8867:
	.size	_ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE, .-_ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE
	.section	.text._ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE13_Rb_tree_implIS3_Lb1EEC2Ev,"axG",@progbits,_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE13_Rb_tree_implIS3_Lb1EEC5Ev,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE13_Rb_tree_implIS3_Lb1EEC2Ev
	.type	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE13_Rb_tree_implIS3_Lb1EEC2Ev, @function
_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE13_Rb_tree_implIS3_Lb1EEC2Ev:
.LFB8871:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaISt13_Rb_tree_nodeIiEEC2Ev
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt20_Rb_tree_key_compareISt4lessIiEEC2Ev
	movq	-8(%rbp), %rax
	addq	$8, %rax
	movq	%rax, %rdi
	call	_ZNSt15_Rb_tree_headerC2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8871:
	.size	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE13_Rb_tree_implIS3_Lb1EEC2Ev, .-_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE13_Rb_tree_implIS3_Lb1EEC2Ev
	.weak	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE13_Rb_tree_implIS3_Lb1EEC1Ev
	.set	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE13_Rb_tree_implIS3_Lb1EEC1Ev,_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE13_Rb_tree_implIS3_Lb1EEC2Ev
	.section	.text._ZNSaISt13_Rb_tree_nodeIiEED2Ev,"axG",@progbits,_ZNSaISt13_Rb_tree_nodeIiEED5Ev,comdat
	.align 2
	.weak	_ZNSaISt13_Rb_tree_nodeIiEED2Ev
	.type	_ZNSaISt13_Rb_tree_nodeIiEED2Ev, @function
_ZNSaISt13_Rb_tree_nodeIiEED2Ev:
.LFB8874:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEED2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8874:
	.size	_ZNSaISt13_Rb_tree_nodeIiEED2Ev, .-_ZNSaISt13_Rb_tree_nodeIiEED2Ev
	.weak	_ZNSaISt13_Rb_tree_nodeIiEED1Ev
	.set	_ZNSaISt13_Rb_tree_nodeIiEED1Ev,_ZNSaISt13_Rb_tree_nodeIiEED2Ev
	.section	.text._ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEED2Ev,"axG",@progbits,_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEED5Ev,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEED2Ev
	.type	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEED2Ev, @function
_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEED2Ev:
.LFB8877:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA8877
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_M_beginEv
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_M_eraseEPSt13_Rb_tree_nodeIiE
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE13_Rb_tree_implIS3_Lb1EED1Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8877:
	.section	.gcc_except_table
.LLSDA8877:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE8877-.LLSDACSB8877
.LLSDACSB8877:
.LLSDACSE8877:
	.section	.text._ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEED2Ev,"axG",@progbits,_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEED5Ev,comdat
	.size	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEED2Ev, .-_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEED2Ev
	.weak	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEED1Ev
	.set	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEED1Ev,_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEED2Ev
	.section	.text._ZNSt3setIiSt4lessIiESaIiEE6insertEOi,"axG",@progbits,_ZNSt3setIiSt4lessIiESaIiEE6insertEOi,comdat
	.align 2
	.weak	_ZNSt3setIiSt4lessIiESaIiEE6insertEOi
	.type	_ZNSt3setIiSt4lessIiESaIiEE6insertEOi, @function
_ZNSt3setIiSt4lessIiESaIiEE6insertEOi:
.LFB8879:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$72, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -72(%rbp)
	movq	%rsi, -80(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	-72(%rbp), %rbx
	movq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE16_M_insert_uniqueIiEESt4pairISt17_Rb_tree_iteratorIiEbEOT_
	movq	%rax, -64(%rbp)
	movq	%rdx, -56(%rbp)
	leaq	-64(%rbp), %rax
	leaq	8(%rax), %rdx
	leaq	-64(%rbp), %rcx
	leaq	-48(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt4pairISt23_Rb_tree_const_iteratorIiEbEC1IRSt17_Rb_tree_iteratorIiERbLb1EEEOT_OT0_
	movq	-48(%rbp), %rax
	movq	-40(%rbp), %rdx
	movq	-24(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L24
	call	__stack_chk_fail@PLT
.L24:
	addq	$72, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8879:
	.size	_ZNSt3setIiSt4lessIiESaIiEE6insertEOi, .-_ZNSt3setIiSt4lessIiESaIiEE6insertEOi
	.section	.text._ZSt7forwardIbEOT_RNSt16remove_referenceIS0_E4typeE,"axG",@progbits,_ZSt7forwardIbEOT_RNSt16remove_referenceIS0_E4typeE,comdat
	.weak	_ZSt7forwardIbEOT_RNSt16remove_referenceIS0_E4typeE
	.type	_ZSt7forwardIbEOT_RNSt16remove_referenceIS0_E4typeE, @function
_ZSt7forwardIbEOT_RNSt16remove_referenceIS0_E4typeE:
.LFB9154:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9154:
	.size	_ZSt7forwardIbEOT_RNSt16remove_referenceIS0_E4typeE, .-_ZSt7forwardIbEOT_RNSt16remove_referenceIS0_E4typeE
	.section	.text._ZNSaISt13_Rb_tree_nodeIiEEC2Ev,"axG",@progbits,_ZNSaISt13_Rb_tree_nodeIiEEC5Ev,comdat
	.align 2
	.weak	_ZNSaISt13_Rb_tree_nodeIiEEC2Ev
	.type	_ZNSaISt13_Rb_tree_nodeIiEEC2Ev, @function
_ZNSaISt13_Rb_tree_nodeIiEEC2Ev:
.LFB9163:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEEC2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9163:
	.size	_ZNSaISt13_Rb_tree_nodeIiEEC2Ev, .-_ZNSaISt13_Rb_tree_nodeIiEEC2Ev
	.weak	_ZNSaISt13_Rb_tree_nodeIiEEC1Ev
	.set	_ZNSaISt13_Rb_tree_nodeIiEEC1Ev,_ZNSaISt13_Rb_tree_nodeIiEEC2Ev
	.section	.text._ZNSt20_Rb_tree_key_compareISt4lessIiEEC2Ev,"axG",@progbits,_ZNSt20_Rb_tree_key_compareISt4lessIiEEC5Ev,comdat
	.align 2
	.weak	_ZNSt20_Rb_tree_key_compareISt4lessIiEEC2Ev
	.type	_ZNSt20_Rb_tree_key_compareISt4lessIiEEC2Ev, @function
_ZNSt20_Rb_tree_key_compareISt4lessIiEEC2Ev:
.LFB9166:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9166:
	.size	_ZNSt20_Rb_tree_key_compareISt4lessIiEEC2Ev, .-_ZNSt20_Rb_tree_key_compareISt4lessIiEEC2Ev
	.weak	_ZNSt20_Rb_tree_key_compareISt4lessIiEEC1Ev
	.set	_ZNSt20_Rb_tree_key_compareISt4lessIiEEC1Ev,_ZNSt20_Rb_tree_key_compareISt4lessIiEEC2Ev
	.section	.text._ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEED2Ev,"axG",@progbits,_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEED5Ev,comdat
	.align 2
	.weak	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEED2Ev
	.type	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEED2Ev, @function
_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEED2Ev:
.LFB9169:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9169:
	.size	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEED2Ev, .-_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEED2Ev
	.weak	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEED1Ev
	.set	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEED1Ev,_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEED2Ev
	.section	.text._ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_M_eraseEPSt13_Rb_tree_nodeIiE,"axG",@progbits,_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_M_eraseEPSt13_Rb_tree_nodeIiE,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_M_eraseEPSt13_Rb_tree_nodeIiE
	.type	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_M_eraseEPSt13_Rb_tree_nodeIiE, @function
_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_M_eraseEPSt13_Rb_tree_nodeIiE:
.LFB9171:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
.L32:
	cmpq	$0, -32(%rbp)
	je	.L33
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_S_rightEPSt18_Rb_tree_node_base
	movq	%rax, %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_M_eraseEPSt13_Rb_tree_nodeIiE
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE7_S_leftEPSt18_Rb_tree_node_base
	movq	%rax, -8(%rbp)
	movq	-32(%rbp), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE12_M_drop_nodeEPSt13_Rb_tree_nodeIiE
	movq	-8(%rbp), %rax
	movq	%rax, -32(%rbp)
	jmp	.L32
.L33:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9171:
	.size	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_M_eraseEPSt13_Rb_tree_nodeIiE, .-_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_M_eraseEPSt13_Rb_tree_nodeIiE
	.section	.text._ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_M_beginEv,"axG",@progbits,_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_M_beginEv,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_M_beginEv
	.type	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_M_beginEv, @function
_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_M_beginEv:
.LFB9172:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9172:
	.size	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_M_beginEv, .-_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_M_beginEv
	.section	.text._ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_,"axG",@progbits,_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_,comdat
	.weak	_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_
	.type	_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_, @function
_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_:
.LFB9173:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9173:
	.size	_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_, .-_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_
	.section	.text._ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE16_M_insert_uniqueIiEESt4pairISt17_Rb_tree_iteratorIiEbEOT_,"axG",@progbits,_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE16_M_insert_uniqueIiEESt4pairISt17_Rb_tree_iteratorIiEbEOT_,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE16_M_insert_uniqueIiEESt4pairISt17_Rb_tree_iteratorIiEbEOT_
	.type	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE16_M_insert_uniqueIiEESt4pairISt17_Rb_tree_iteratorIiEbEOT_, @function
_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE16_M_insert_uniqueIiEESt4pairISt17_Rb_tree_iteratorIiEbEOT_:
.LFB9174:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$96, %rsp
	movq	%rdi, -88(%rbp)
	movq	%rsi, -96(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-96(%rbp), %rdx
	leaq	-32(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNKSt9_IdentityIiEclERi
	movq	%rax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE24_M_get_insert_unique_posERKi
	movq	%rax, -48(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-40(%rbp), %rax
	testq	%rax, %rax
	je	.L39
	movq	-88(%rbp), %rdx
	leaq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE11_Alloc_nodeC1ERS5_
	movb	$1, -65(%rbp)
	movq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE
	movq	%rax, %rcx
	movq	-40(%rbp), %rdx
	movq	-48(%rbp), %rsi
	leaq	-64(%rbp), %rdi
	movq	-88(%rbp), %rax
	movq	%rdi, %r8
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE10_M_insert_IiNS5_11_Alloc_nodeEEESt17_Rb_tree_iteratorIiEPSt18_Rb_tree_node_baseSB_OT_RT0_
	movq	%rax, -56(%rbp)
	leaq	-65(%rbp), %rdx
	leaq	-56(%rbp), %rcx
	leaq	-32(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt4pairISt17_Rb_tree_iteratorIiEbEC1IS1_bLb1EEEOT_OT0_
	movq	-32(%rbp), %rax
	movq	-24(%rbp), %rdx
	jmp	.L41
.L39:
	movb	$0, -64(%rbp)
	movq	-48(%rbp), %rdx
	leaq	-56(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt17_Rb_tree_iteratorIiEC1EPSt18_Rb_tree_node_base
	leaq	-64(%rbp), %rdx
	leaq	-56(%rbp), %rcx
	leaq	-32(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt4pairISt17_Rb_tree_iteratorIiEbEC1IS1_bLb1EEEOT_OT0_
	movq	-32(%rbp), %rax
	movq	-24(%rbp), %rdx
.L41:
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L42
	call	__stack_chk_fail@PLT
.L42:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9174:
	.size	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE16_M_insert_uniqueIiEESt4pairISt17_Rb_tree_iteratorIiEbEOT_, .-_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE16_M_insert_uniqueIiEESt4pairISt17_Rb_tree_iteratorIiEbEOT_
	.section	.text._ZNSt4pairISt23_Rb_tree_const_iteratorIiEbEC2IRSt17_Rb_tree_iteratorIiERbLb1EEEOT_OT0_,"axG",@progbits,_ZNSt4pairISt23_Rb_tree_const_iteratorIiEbEC5IRSt17_Rb_tree_iteratorIiERbLb1EEEOT_OT0_,comdat
	.align 2
	.weak	_ZNSt4pairISt23_Rb_tree_const_iteratorIiEbEC2IRSt17_Rb_tree_iteratorIiERbLb1EEEOT_OT0_
	.type	_ZNSt4pairISt23_Rb_tree_const_iteratorIiEbEC2IRSt17_Rb_tree_iteratorIiERbLb1EEEOT_OT0_, @function
_ZNSt4pairISt23_Rb_tree_const_iteratorIiEbEC2IRSt17_Rb_tree_iteratorIiERbLb1EEEOT_OT0_:
.LFB9188:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-24(%rbp), %rbx
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIRSt17_Rb_tree_iteratorIiEEOT_RNSt16remove_referenceIS3_E4typeE
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZNSt23_Rb_tree_const_iteratorIiEC1ERKSt17_Rb_tree_iteratorIiE
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIRbEOT_RNSt16remove_referenceIS1_E4typeE
	movzbl	(%rax), %edx
	movq	-24(%rbp), %rax
	movb	%dl, 8(%rax)
	nop
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9188:
	.size	_ZNSt4pairISt23_Rb_tree_const_iteratorIiEbEC2IRSt17_Rb_tree_iteratorIiERbLb1EEEOT_OT0_, .-_ZNSt4pairISt23_Rb_tree_const_iteratorIiEbEC2IRSt17_Rb_tree_iteratorIiERbLb1EEEOT_OT0_
	.weak	_ZNSt4pairISt23_Rb_tree_const_iteratorIiEbEC1IRSt17_Rb_tree_iteratorIiERbLb1EEEOT_OT0_
	.set	_ZNSt4pairISt23_Rb_tree_const_iteratorIiEbEC1IRSt17_Rb_tree_iteratorIiERbLb1EEEOT_OT0_,_ZNSt4pairISt23_Rb_tree_const_iteratorIiEbEC2IRSt17_Rb_tree_iteratorIiERbLb1EEEOT_OT0_
	.section	.text._ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEEC2Ev,"axG",@progbits,_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEEC5Ev,comdat
	.align 2
	.weak	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEEC2Ev
	.type	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEEC2Ev, @function
_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEEC2Ev:
.LFB9323:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9323:
	.size	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEEC2Ev, .-_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEEC2Ev
	.weak	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEEC1Ev
	.set	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEEC1Ev,_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEEC2Ev
	.section	.text._ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_S_rightEPSt18_Rb_tree_node_base,"axG",@progbits,_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_S_rightEPSt18_Rb_tree_node_base,comdat
	.weak	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_S_rightEPSt18_Rb_tree_node_base
	.type	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_S_rightEPSt18_Rb_tree_node_base, @function
_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_S_rightEPSt18_Rb_tree_node_base:
.LFB9325:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	24(%rax), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9325:
	.size	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_S_rightEPSt18_Rb_tree_node_base, .-_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_S_rightEPSt18_Rb_tree_node_base
	.section	.text._ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE7_S_leftEPSt18_Rb_tree_node_base,"axG",@progbits,_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE7_S_leftEPSt18_Rb_tree_node_base,comdat
	.weak	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE7_S_leftEPSt18_Rb_tree_node_base
	.type	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE7_S_leftEPSt18_Rb_tree_node_base, @function
_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE7_S_leftEPSt18_Rb_tree_node_base:
.LFB9326:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9326:
	.size	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE7_S_leftEPSt18_Rb_tree_node_base, .-_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE7_S_leftEPSt18_Rb_tree_node_base
	.section	.text._ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE12_M_drop_nodeEPSt13_Rb_tree_nodeIiE,"axG",@progbits,_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE12_M_drop_nodeEPSt13_Rb_tree_nodeIiE,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE12_M_drop_nodeEPSt13_Rb_tree_nodeIiE
	.type	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE12_M_drop_nodeEPSt13_Rb_tree_nodeIiE, @function
_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE12_M_drop_nodeEPSt13_Rb_tree_nodeIiE:
.LFB9327:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE15_M_destroy_nodeEPSt13_Rb_tree_nodeIiE
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE11_M_put_nodeEPSt13_Rb_tree_nodeIiE
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9327:
	.size	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE12_M_drop_nodeEPSt13_Rb_tree_nodeIiE, .-_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE12_M_drop_nodeEPSt13_Rb_tree_nodeIiE
	.section	.text._ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE24_M_get_insert_unique_posERKi,"axG",@progbits,_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE24_M_get_insert_unique_posERKi,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE24_M_get_insert_unique_posERKi
	.type	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE24_M_get_insert_unique_posERKi, @function
_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE24_M_get_insert_unique_posERKi:
.LFB9328:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$104, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -104(%rbp)
	movq	%rsi, -112(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	-104(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_M_beginEv
	movq	%rax, -80(%rbp)
	movq	-104(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE6_M_endEv
	movq	%rax, -72(%rbp)
	movb	$1, -81(%rbp)
.L54:
	movq	-80(%rbp), %rax
	testq	%rax, %rax
	je	.L51
	movq	-80(%rbp), %rax
	movq	%rax, -72(%rbp)
	movq	-104(%rbp), %rbx
	movq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE6_S_keyEPKSt13_Rb_tree_nodeIiE
	movq	%rax, %rdx
	movq	-112(%rbp), %rax
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZNKSt4lessIiEclERKiS2_
	movb	%al, -81(%rbp)
	cmpb	$0, -81(%rbp)
	je	.L52
	movq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE7_S_leftEPSt18_Rb_tree_node_base
	jmp	.L53
.L52:
	movq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_S_rightEPSt18_Rb_tree_node_base
.L53:
	movq	%rax, -80(%rbp)
	jmp	.L54
.L51:
	movq	-72(%rbp), %rdx
	leaq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt17_Rb_tree_iteratorIiEC1EPSt18_Rb_tree_node_base
	cmpb	$0, -81(%rbp)
	je	.L55
	movq	-104(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE5beginEv
	movq	%rax, -48(%rbp)
	leaq	-48(%rbp), %rdx
	leaq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZSteqRKSt17_Rb_tree_iteratorIiES2_
	testb	%al, %al
	je	.L56
	leaq	-72(%rbp), %rdx
	leaq	-80(%rbp), %rcx
	leaq	-48(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRPSt13_Rb_tree_nodeIiERS1_Lb1EEEOT_OT0_
	movq	-48(%rbp), %rax
	movq	-40(%rbp), %rdx
	jmp	.L59
.L56:
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt17_Rb_tree_iteratorIiEmmEv
.L55:
	movq	-104(%rbp), %rbx
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE6_S_keyEPKSt18_Rb_tree_node_base
	movq	%rax, %rcx
	movq	-112(%rbp), %rax
	movq	%rax, %rdx
	movq	%rcx, %rsi
	movq	%rbx, %rdi
	call	_ZNKSt4lessIiEclERKiS2_
	testb	%al, %al
	je	.L58
	leaq	-72(%rbp), %rdx
	leaq	-80(%rbp), %rcx
	leaq	-48(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRPSt13_Rb_tree_nodeIiERS1_Lb1EEEOT_OT0_
	movq	-48(%rbp), %rax
	movq	-40(%rbp), %rdx
	jmp	.L59
.L58:
	movq	$0, -56(%rbp)
	leaq	-56(%rbp), %rdx
	leaq	-64(%rbp), %rcx
	leaq	-48(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_Lb1EEEOT_RKS1_
	movq	-48(%rbp), %rax
	movq	-40(%rbp), %rdx
.L59:
	movq	-24(%rbp), %rbx
	xorq	%fs:40, %rbx
	je	.L60
	call	__stack_chk_fail@PLT
.L60:
	addq	$104, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9328:
	.size	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE24_M_get_insert_unique_posERKi, .-_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE24_M_get_insert_unique_posERKi
	.section	.text._ZNKSt9_IdentityIiEclERi,"axG",@progbits,_ZNKSt9_IdentityIiEclERi,comdat
	.align 2
	.weak	_ZNKSt9_IdentityIiEclERi
	.type	_ZNKSt9_IdentityIiEclERi, @function
_ZNKSt9_IdentityIiEclERi:
.LFB9343:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9343:
	.size	_ZNKSt9_IdentityIiEclERi, .-_ZNKSt9_IdentityIiEclERi
	.section	.text._ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE11_Alloc_nodeC2ERS5_,"axG",@progbits,_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE11_Alloc_nodeC5ERS5_,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE11_Alloc_nodeC2ERS5_
	.type	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE11_Alloc_nodeC2ERS5_, @function
_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE11_Alloc_nodeC2ERS5_:
.LFB9345:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9345:
	.size	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE11_Alloc_nodeC2ERS5_, .-_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE11_Alloc_nodeC2ERS5_
	.weak	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE11_Alloc_nodeC1ERS5_
	.set	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE11_Alloc_nodeC1ERS5_,_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE11_Alloc_nodeC2ERS5_
	.section	.text._ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE10_M_insert_IiNS5_11_Alloc_nodeEEESt17_Rb_tree_iteratorIiEPSt18_Rb_tree_node_baseSB_OT_RT0_,"axG",@progbits,_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE10_M_insert_IiNS5_11_Alloc_nodeEEESt17_Rb_tree_iteratorIiEPSt18_Rb_tree_node_baseSB_OT_RT0_,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE10_M_insert_IiNS5_11_Alloc_nodeEEESt17_Rb_tree_iteratorIiEPSt18_Rb_tree_node_baseSB_OT_RT0_
	.type	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE10_M_insert_IiNS5_11_Alloc_nodeEEESt17_Rb_tree_iteratorIiEPSt18_Rb_tree_node_baseSB_OT_RT0_, @function
_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE10_M_insert_IiNS5_11_Alloc_nodeEEESt17_Rb_tree_iteratorIiEPSt18_Rb_tree_node_baseSB_OT_RT0_:
.LFB9347:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$80, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%rdi, -56(%rbp)
	movq	%rsi, -64(%rbp)
	movq	%rdx, -72(%rbp)
	movq	%rcx, -80(%rbp)
	movq	%r8, -88(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	cmpq	$0, -64(%rbp)
	jne	.L65
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE6_M_endEv
	cmpq	%rax, -72(%rbp)
	je	.L65
	movq	-56(%rbp), %rbx
	movq	-72(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE6_S_keyEPKSt18_Rb_tree_node_base
	movq	%rax, %r12
	movq	-80(%rbp), %rdx
	leaq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNKSt9_IdentityIiEclERi
	movq	%r12, %rdx
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZNKSt4lessIiEclERKiS2_
	testb	%al, %al
	je	.L66
.L65:
	movl	$1, %eax
	jmp	.L67
.L66:
	movl	$0, %eax
.L67:
	movb	%al, -41(%rbp)
	movq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE
	movq	%rax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNKSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE11_Alloc_nodeclIiEEPSt13_Rb_tree_nodeIiEOT_
	movq	%rax, -32(%rbp)
	movq	-56(%rbp), %rax
	leaq	8(%rax), %rcx
	movzbl	-41(%rbp), %eax
	movq	-72(%rbp), %rdx
	movq	-32(%rbp), %rsi
	movl	%eax, %edi
	call	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_@PLT
	movq	-56(%rbp), %rax
	movq	40(%rax), %rax
	leaq	1(%rax), %rdx
	movq	-56(%rbp), %rax
	movq	%rdx, 40(%rax)
	movq	-32(%rbp), %rdx
	leaq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt17_Rb_tree_iteratorIiEC1EPSt18_Rb_tree_node_base
	movq	-40(%rbp), %rax
	movq	-24(%rbp), %rbx
	xorq	%fs:40, %rbx
	je	.L69
	call	__stack_chk_fail@PLT
.L69:
	addq	$80, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9347:
	.size	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE10_M_insert_IiNS5_11_Alloc_nodeEEESt17_Rb_tree_iteratorIiEPSt18_Rb_tree_node_baseSB_OT_RT0_, .-_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE10_M_insert_IiNS5_11_Alloc_nodeEEESt17_Rb_tree_iteratorIiEPSt18_Rb_tree_node_baseSB_OT_RT0_
	.section	.text._ZNSt4pairISt17_Rb_tree_iteratorIiEbEC2IS1_bLb1EEEOT_OT0_,"axG",@progbits,_ZNSt4pairISt17_Rb_tree_iteratorIiEbEC5IS1_bLb1EEEOT_OT0_,comdat
	.align 2
	.weak	_ZNSt4pairISt17_Rb_tree_iteratorIiEbEC2IS1_bLb1EEEOT_OT0_
	.type	_ZNSt4pairISt17_Rb_tree_iteratorIiEbEC2IS1_bLb1EEEOT_OT0_, @function
_ZNSt4pairISt17_Rb_tree_iteratorIiEbEC2IS1_bLb1EEEOT_OT0_:
.LFB9349:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardISt17_Rb_tree_iteratorIiEEOT_RNSt16remove_referenceIS2_E4typeE
	movq	-8(%rbp), %rdx
	movq	(%rax), %rax
	movq	%rax, (%rdx)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIbEOT_RNSt16remove_referenceIS0_E4typeE
	movzbl	(%rax), %edx
	movq	-8(%rbp), %rax
	movb	%dl, 8(%rax)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9349:
	.size	_ZNSt4pairISt17_Rb_tree_iteratorIiEbEC2IS1_bLb1EEEOT_OT0_, .-_ZNSt4pairISt17_Rb_tree_iteratorIiEbEC2IS1_bLb1EEEOT_OT0_
	.weak	_ZNSt4pairISt17_Rb_tree_iteratorIiEbEC1IS1_bLb1EEEOT_OT0_
	.set	_ZNSt4pairISt17_Rb_tree_iteratorIiEbEC1IS1_bLb1EEEOT_OT0_,_ZNSt4pairISt17_Rb_tree_iteratorIiEbEC2IS1_bLb1EEEOT_OT0_
	.section	.text._ZNSt17_Rb_tree_iteratorIiEC2EPSt18_Rb_tree_node_base,"axG",@progbits,_ZNSt17_Rb_tree_iteratorIiEC5EPSt18_Rb_tree_node_base,comdat
	.align 2
	.weak	_ZNSt17_Rb_tree_iteratorIiEC2EPSt18_Rb_tree_node_base
	.type	_ZNSt17_Rb_tree_iteratorIiEC2EPSt18_Rb_tree_node_base, @function
_ZNSt17_Rb_tree_iteratorIiEC2EPSt18_Rb_tree_node_base:
.LFB9352:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9352:
	.size	_ZNSt17_Rb_tree_iteratorIiEC2EPSt18_Rb_tree_node_base, .-_ZNSt17_Rb_tree_iteratorIiEC2EPSt18_Rb_tree_node_base
	.weak	_ZNSt17_Rb_tree_iteratorIiEC1EPSt18_Rb_tree_node_base
	.set	_ZNSt17_Rb_tree_iteratorIiEC1EPSt18_Rb_tree_node_base,_ZNSt17_Rb_tree_iteratorIiEC2EPSt18_Rb_tree_node_base
	.section	.text._ZSt7forwardIRSt17_Rb_tree_iteratorIiEEOT_RNSt16remove_referenceIS3_E4typeE,"axG",@progbits,_ZSt7forwardIRSt17_Rb_tree_iteratorIiEEOT_RNSt16remove_referenceIS3_E4typeE,comdat
	.weak	_ZSt7forwardIRSt17_Rb_tree_iteratorIiEEOT_RNSt16remove_referenceIS3_E4typeE
	.type	_ZSt7forwardIRSt17_Rb_tree_iteratorIiEEOT_RNSt16remove_referenceIS3_E4typeE, @function
_ZSt7forwardIRSt17_Rb_tree_iteratorIiEEOT_RNSt16remove_referenceIS3_E4typeE:
.LFB9354:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9354:
	.size	_ZSt7forwardIRSt17_Rb_tree_iteratorIiEEOT_RNSt16remove_referenceIS3_E4typeE, .-_ZSt7forwardIRSt17_Rb_tree_iteratorIiEEOT_RNSt16remove_referenceIS3_E4typeE
	.section	.text._ZSt7forwardIRbEOT_RNSt16remove_referenceIS1_E4typeE,"axG",@progbits,_ZSt7forwardIRbEOT_RNSt16remove_referenceIS1_E4typeE,comdat
	.weak	_ZSt7forwardIRbEOT_RNSt16remove_referenceIS1_E4typeE
	.type	_ZSt7forwardIRbEOT_RNSt16remove_referenceIS1_E4typeE, @function
_ZSt7forwardIRbEOT_RNSt16remove_referenceIS1_E4typeE:
.LFB9355:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9355:
	.size	_ZSt7forwardIRbEOT_RNSt16remove_referenceIS1_E4typeE, .-_ZSt7forwardIRbEOT_RNSt16remove_referenceIS1_E4typeE
	.section	.text._ZNSt23_Rb_tree_const_iteratorIiEC2ERKSt17_Rb_tree_iteratorIiE,"axG",@progbits,_ZNSt23_Rb_tree_const_iteratorIiEC5ERKSt17_Rb_tree_iteratorIiE,comdat
	.align 2
	.weak	_ZNSt23_Rb_tree_const_iteratorIiEC2ERKSt17_Rb_tree_iteratorIiE
	.type	_ZNSt23_Rb_tree_const_iteratorIiEC2ERKSt17_Rb_tree_iteratorIiE, @function
_ZNSt23_Rb_tree_const_iteratorIiEC2ERKSt17_Rb_tree_iteratorIiE:
.LFB9357:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9357:
	.size	_ZNSt23_Rb_tree_const_iteratorIiEC2ERKSt17_Rb_tree_iteratorIiE, .-_ZNSt23_Rb_tree_const_iteratorIiEC2ERKSt17_Rb_tree_iteratorIiE
	.weak	_ZNSt23_Rb_tree_const_iteratorIiEC1ERKSt17_Rb_tree_iteratorIiE
	.set	_ZNSt23_Rb_tree_const_iteratorIiEC1ERKSt17_Rb_tree_iteratorIiE,_ZNSt23_Rb_tree_const_iteratorIiEC2ERKSt17_Rb_tree_iteratorIiE
	.section	.text._ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE15_M_destroy_nodeEPSt13_Rb_tree_nodeIiE,"axG",@progbits,_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE15_M_destroy_nodeEPSt13_Rb_tree_nodeIiE,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE15_M_destroy_nodeEPSt13_Rb_tree_nodeIiE
	.type	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE15_M_destroy_nodeEPSt13_Rb_tree_nodeIiE, @function
_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE15_M_destroy_nodeEPSt13_Rb_tree_nodeIiE:
.LFB9444:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt13_Rb_tree_nodeIiE9_M_valptrEv
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE21_M_get_Node_allocatorEv
	movq	%rbx, %rsi
	movq	%rax, %rdi
	call	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeIiEEE7destroyIiEEvRS2_PT_
	nop
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9444:
	.size	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE15_M_destroy_nodeEPSt13_Rb_tree_nodeIiE, .-_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE15_M_destroy_nodeEPSt13_Rb_tree_nodeIiE
	.section	.text._ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE11_M_put_nodeEPSt13_Rb_tree_nodeIiE,"axG",@progbits,_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE11_M_put_nodeEPSt13_Rb_tree_nodeIiE,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE11_M_put_nodeEPSt13_Rb_tree_nodeIiE
	.type	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE11_M_put_nodeEPSt13_Rb_tree_nodeIiE, @function
_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE11_M_put_nodeEPSt13_Rb_tree_nodeIiE:
.LFB9445:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA9445
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE21_M_get_Node_allocatorEv
	movq	%rax, %rcx
	movq	-16(%rbp), %rax
	movl	$1, %edx
	movq	%rax, %rsi
	movq	%rcx, %rdi
	call	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeIiEEE10deallocateERS2_PS1_m
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9445:
	.section	.gcc_except_table
.LLSDA9445:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE9445-.LLSDACSB9445
.LLSDACSB9445:
.LLSDACSE9445:
	.section	.text._ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE11_M_put_nodeEPSt13_Rb_tree_nodeIiE,"axG",@progbits,_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE11_M_put_nodeEPSt13_Rb_tree_nodeIiE,comdat
	.size	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE11_M_put_nodeEPSt13_Rb_tree_nodeIiE, .-_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE11_M_put_nodeEPSt13_Rb_tree_nodeIiE
	.section	.text._ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE6_M_endEv,"axG",@progbits,_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE6_M_endEv,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE6_M_endEv
	.type	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE6_M_endEv, @function
_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE6_M_endEv:
.LFB9446:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$8, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9446:
	.size	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE6_M_endEv, .-_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE6_M_endEv
	.section	.text._ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE6_S_keyEPKSt13_Rb_tree_nodeIiE,"axG",@progbits,_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE6_S_keyEPKSt13_Rb_tree_nodeIiE,comdat
	.weak	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE6_S_keyEPKSt13_Rb_tree_nodeIiE
	.type	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE6_S_keyEPKSt13_Rb_tree_nodeIiE, @function
_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE6_S_keyEPKSt13_Rb_tree_nodeIiE:
.LFB9447:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt13_Rb_tree_nodeIiE9_M_valptrEv
	movq	%rax, %rdx
	leaq	-9(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNKSt9_IdentityIiEclERKi
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L83
	call	__stack_chk_fail@PLT
.L83:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9447:
	.size	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE6_S_keyEPKSt13_Rb_tree_nodeIiE, .-_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE6_S_keyEPKSt13_Rb_tree_nodeIiE
	.section	.text._ZNKSt4lessIiEclERKiS2_,"axG",@progbits,_ZNKSt4lessIiEclERKiS2_,comdat
	.align 2
	.weak	_ZNKSt4lessIiEclERKiS2_
	.type	_ZNKSt4lessIiEclERKiS2_, @function
_ZNKSt4lessIiEclERKiS2_:
.LFB9449:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-16(%rbp), %rax
	movl	(%rax), %edx
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	setl	%al
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9449:
	.size	_ZNKSt4lessIiEclERKiS2_, .-_ZNKSt4lessIiEclERKiS2_
	.section	.text._ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE5beginEv,"axG",@progbits,_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE5beginEv,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE5beginEv
	.type	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE5beginEv, @function
_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE5beginEv:
.LFB9450:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-24(%rbp), %rax
	movq	24(%rax), %rdx
	leaq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt17_Rb_tree_iteratorIiEC1EPSt18_Rb_tree_node_base
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L88
	call	__stack_chk_fail@PLT
.L88:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9450:
	.size	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE5beginEv, .-_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE5beginEv
	.section	.text._ZSteqRKSt17_Rb_tree_iteratorIiES2_,"axG",@progbits,_ZSteqRKSt17_Rb_tree_iteratorIiES2_,comdat
	.weak	_ZSteqRKSt17_Rb_tree_iteratorIiES2_
	.type	_ZSteqRKSt17_Rb_tree_iteratorIiES2_, @function
_ZSteqRKSt17_Rb_tree_iteratorIiES2_:
.LFB9451:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rdx
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	cmpq	%rax, %rdx
	sete	%al
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9451:
	.size	_ZSteqRKSt17_Rb_tree_iteratorIiES2_, .-_ZSteqRKSt17_Rb_tree_iteratorIiES2_
	.section	.text._ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRPSt13_Rb_tree_nodeIiERS1_Lb1EEEOT_OT0_,"axG",@progbits,_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC5IRPSt13_Rb_tree_nodeIiERS1_Lb1EEEOT_OT0_,comdat
	.align 2
	.weak	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRPSt13_Rb_tree_nodeIiERS1_Lb1EEEOT_OT0_
	.type	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRPSt13_Rb_tree_nodeIiERS1_Lb1EEEOT_OT0_, @function
_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRPSt13_Rb_tree_nodeIiERS1_Lb1EEEOT_OT0_:
.LFB9453:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIRPSt13_Rb_tree_nodeIiEEOT_RNSt16remove_referenceIS4_E4typeE
	movq	(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIRPSt18_Rb_tree_node_baseEOT_RNSt16remove_referenceIS3_E4typeE
	movq	(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 8(%rax)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9453:
	.size	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRPSt13_Rb_tree_nodeIiERS1_Lb1EEEOT_OT0_, .-_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRPSt13_Rb_tree_nodeIiERS1_Lb1EEEOT_OT0_
	.weak	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRPSt13_Rb_tree_nodeIiERS1_Lb1EEEOT_OT0_
	.set	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRPSt13_Rb_tree_nodeIiERS1_Lb1EEEOT_OT0_,_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRPSt13_Rb_tree_nodeIiERS1_Lb1EEEOT_OT0_
	.section	.text._ZNSt17_Rb_tree_iteratorIiEmmEv,"axG",@progbits,_ZNSt17_Rb_tree_iteratorIiEmmEv,comdat
	.align 2
	.weak	_ZNSt17_Rb_tree_iteratorIiEmmEv
	.type	_ZNSt17_Rb_tree_iteratorIiEmmEv, @function
_ZNSt17_Rb_tree_iteratorIiEmmEv:
.LFB9455:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base@PLT
	movq	-8(%rbp), %rdx
	movq	%rax, (%rdx)
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9455:
	.size	_ZNSt17_Rb_tree_iteratorIiEmmEv, .-_ZNSt17_Rb_tree_iteratorIiEmmEv
	.section	.text._ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE6_S_keyEPKSt18_Rb_tree_node_base,"axG",@progbits,_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE6_S_keyEPKSt18_Rb_tree_node_base,comdat
	.weak	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE6_S_keyEPKSt18_Rb_tree_node_base
	.type	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE6_S_keyEPKSt18_Rb_tree_node_base, @function
_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE6_S_keyEPKSt18_Rb_tree_node_base:
.LFB9456:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE6_S_keyEPKSt13_Rb_tree_nodeIiE
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9456:
	.size	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE6_S_keyEPKSt18_Rb_tree_node_base, .-_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE6_S_keyEPKSt18_Rb_tree_node_base
	.section	.text._ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRS1_Lb1EEEOT_RKS1_,"axG",@progbits,_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC5IRS1_Lb1EEEOT_RKS1_,comdat
	.align 2
	.weak	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRS1_Lb1EEEOT_RKS1_
	.type	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRS1_Lb1EEEOT_RKS1_, @function
_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRS1_Lb1EEEOT_RKS1_:
.LFB9458:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIRPSt18_Rb_tree_node_baseEOT_RNSt16remove_referenceIS3_E4typeE
	movq	(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-24(%rbp), %rax
	movq	(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 8(%rax)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9458:
	.size	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRS1_Lb1EEEOT_RKS1_, .-_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRS1_Lb1EEEOT_RKS1_
	.weak	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_Lb1EEEOT_RKS1_
	.set	_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC1IRS1_Lb1EEEOT_RKS1_,_ZNSt4pairIPSt18_Rb_tree_node_baseS1_EC2IRS1_Lb1EEEOT_RKS1_
	.section	.text._ZNKSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE11_Alloc_nodeclIiEEPSt13_Rb_tree_nodeIiEOT_,"axG",@progbits,_ZNKSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE11_Alloc_nodeclIiEEPSt13_Rb_tree_nodeIiEOT_,comdat
	.align 2
	.weak	_ZNKSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE11_Alloc_nodeclIiEEPSt13_Rb_tree_nodeIiEOT_
	.type	_ZNKSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE11_Alloc_nodeclIiEEPSt13_Rb_tree_nodeIiEOT_, @function
_ZNKSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE11_Alloc_nodeclIiEEPSt13_Rb_tree_nodeIiEOT_:
.LFB9460:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rbx
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE14_M_create_nodeIJiEEEPSt13_Rb_tree_nodeIiEDpOT_
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9460:
	.size	_ZNKSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE11_Alloc_nodeclIiEEPSt13_Rb_tree_nodeIiEOT_, .-_ZNKSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE11_Alloc_nodeclIiEEPSt13_Rb_tree_nodeIiEOT_
	.section	.text._ZSt7forwardISt17_Rb_tree_iteratorIiEEOT_RNSt16remove_referenceIS2_E4typeE,"axG",@progbits,_ZSt7forwardISt17_Rb_tree_iteratorIiEEOT_RNSt16remove_referenceIS2_E4typeE,comdat
	.weak	_ZSt7forwardISt17_Rb_tree_iteratorIiEEOT_RNSt16remove_referenceIS2_E4typeE
	.type	_ZSt7forwardISt17_Rb_tree_iteratorIiEEOT_RNSt16remove_referenceIS2_E4typeE, @function
_ZSt7forwardISt17_Rb_tree_iteratorIiEEOT_RNSt16remove_referenceIS2_E4typeE:
.LFB9461:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9461:
	.size	_ZSt7forwardISt17_Rb_tree_iteratorIiEEOT_RNSt16remove_referenceIS2_E4typeE, .-_ZSt7forwardISt17_Rb_tree_iteratorIiEEOT_RNSt16remove_referenceIS2_E4typeE
	.section	.text._ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE21_M_get_Node_allocatorEv,"axG",@progbits,_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE21_M_get_Node_allocatorEv,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE21_M_get_Node_allocatorEv
	.type	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE21_M_get_Node_allocatorEv, @function
_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE21_M_get_Node_allocatorEv:
.LFB9525:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9525:
	.size	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE21_M_get_Node_allocatorEv, .-_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE21_M_get_Node_allocatorEv
	.section	.text._ZNSt13_Rb_tree_nodeIiE9_M_valptrEv,"axG",@progbits,_ZNSt13_Rb_tree_nodeIiE9_M_valptrEv,comdat
	.align 2
	.weak	_ZNSt13_Rb_tree_nodeIiE9_M_valptrEv
	.type	_ZNSt13_Rb_tree_nodeIiE9_M_valptrEv, @function
_ZNSt13_Rb_tree_nodeIiE9_M_valptrEv:
.LFB9526:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$32, %rax
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx16__aligned_membufIiE6_M_ptrEv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9526:
	.size	_ZNSt13_Rb_tree_nodeIiE9_M_valptrEv, .-_ZNSt13_Rb_tree_nodeIiE9_M_valptrEv
	.section	.text._ZNSt16allocator_traitsISaISt13_Rb_tree_nodeIiEEE7destroyIiEEvRS2_PT_,"axG",@progbits,_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeIiEEE7destroyIiEEvRS2_PT_,comdat
	.weak	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeIiEEE7destroyIiEEvRS2_PT_
	.type	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeIiEEE7destroyIiEEvRS2_PT_, @function
_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeIiEEE7destroyIiEEvRS2_PT_:
.LFB9527:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE7destroyIiEEvPT_
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9527:
	.size	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeIiEEE7destroyIiEEvRS2_PT_, .-_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeIiEEE7destroyIiEEvRS2_PT_
	.section	.text._ZNSt16allocator_traitsISaISt13_Rb_tree_nodeIiEEE10deallocateERS2_PS1_m,"axG",@progbits,_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeIiEEE10deallocateERS2_PS1_m,comdat
	.weak	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeIiEEE10deallocateERS2_PS1_m
	.type	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeIiEEE10deallocateERS2_PS1_m, @function
_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeIiEEE10deallocateERS2_PS1_m:
.LFB9528:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rcx
	movq	-8(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE10deallocateEPS2_m
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9528:
	.size	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeIiEEE10deallocateERS2_PS1_m, .-_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeIiEEE10deallocateERS2_PS1_m
	.section	.text._ZNKSt13_Rb_tree_nodeIiE9_M_valptrEv,"axG",@progbits,_ZNKSt13_Rb_tree_nodeIiE9_M_valptrEv,comdat
	.align 2
	.weak	_ZNKSt13_Rb_tree_nodeIiE9_M_valptrEv
	.type	_ZNKSt13_Rb_tree_nodeIiE9_M_valptrEv, @function
_ZNKSt13_Rb_tree_nodeIiE9_M_valptrEv:
.LFB9529:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$32, %rax
	movq	%rax, %rdi
	call	_ZNK9__gnu_cxx16__aligned_membufIiE6_M_ptrEv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9529:
	.size	_ZNKSt13_Rb_tree_nodeIiE9_M_valptrEv, .-_ZNKSt13_Rb_tree_nodeIiE9_M_valptrEv
	.section	.text._ZNKSt9_IdentityIiEclERKi,"axG",@progbits,_ZNKSt9_IdentityIiEclERKi,comdat
	.align 2
	.weak	_ZNKSt9_IdentityIiEclERKi
	.type	_ZNKSt9_IdentityIiEclERKi, @function
_ZNKSt9_IdentityIiEclERKi:
.LFB9530:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9530:
	.size	_ZNKSt9_IdentityIiEclERKi, .-_ZNKSt9_IdentityIiEclERKi
	.section	.text._ZSt7forwardIRPSt13_Rb_tree_nodeIiEEOT_RNSt16remove_referenceIS4_E4typeE,"axG",@progbits,_ZSt7forwardIRPSt13_Rb_tree_nodeIiEEOT_RNSt16remove_referenceIS4_E4typeE,comdat
	.weak	_ZSt7forwardIRPSt13_Rb_tree_nodeIiEEOT_RNSt16remove_referenceIS4_E4typeE
	.type	_ZSt7forwardIRPSt13_Rb_tree_nodeIiEEOT_RNSt16remove_referenceIS4_E4typeE, @function
_ZSt7forwardIRPSt13_Rb_tree_nodeIiEEOT_RNSt16remove_referenceIS4_E4typeE:
.LFB9531:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9531:
	.size	_ZSt7forwardIRPSt13_Rb_tree_nodeIiEEOT_RNSt16remove_referenceIS4_E4typeE, .-_ZSt7forwardIRPSt13_Rb_tree_nodeIiEEOT_RNSt16remove_referenceIS4_E4typeE
	.section	.text._ZSt7forwardIRPSt18_Rb_tree_node_baseEOT_RNSt16remove_referenceIS3_E4typeE,"axG",@progbits,_ZSt7forwardIRPSt18_Rb_tree_node_baseEOT_RNSt16remove_referenceIS3_E4typeE,comdat
	.weak	_ZSt7forwardIRPSt18_Rb_tree_node_baseEOT_RNSt16remove_referenceIS3_E4typeE
	.type	_ZSt7forwardIRPSt18_Rb_tree_node_baseEOT_RNSt16remove_referenceIS3_E4typeE, @function
_ZSt7forwardIRPSt18_Rb_tree_node_baseEOT_RNSt16remove_referenceIS3_E4typeE:
.LFB9532:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9532:
	.size	_ZSt7forwardIRPSt18_Rb_tree_node_baseEOT_RNSt16remove_referenceIS3_E4typeE, .-_ZSt7forwardIRPSt18_Rb_tree_node_baseEOT_RNSt16remove_referenceIS3_E4typeE
	.section	.text._ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE14_M_create_nodeIJiEEEPSt13_Rb_tree_nodeIiEDpOT_,"axG",@progbits,_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE14_M_create_nodeIJiEEEPSt13_Rb_tree_nodeIiEDpOT_,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE14_M_create_nodeIJiEEEPSt13_Rb_tree_nodeIiEDpOT_
	.type	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE14_M_create_nodeIJiEEEPSt13_Rb_tree_nodeIiEDpOT_, @function
_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE14_M_create_nodeIJiEEEPSt13_Rb_tree_nodeIiEDpOT_:
.LFB9533:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE11_M_get_nodeEv
	movq	%rax, -8(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE
	movq	%rax, %rdx
	movq	-8(%rbp), %rcx
	movq	-24(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE17_M_construct_nodeIJiEEEvPSt13_Rb_tree_nodeIiEDpOT_
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9533:
	.size	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE14_M_create_nodeIJiEEEPSt13_Rb_tree_nodeIiEDpOT_, .-_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE14_M_create_nodeIJiEEEPSt13_Rb_tree_nodeIiEDpOT_
	.section	.text._ZN9__gnu_cxx16__aligned_membufIiE6_M_ptrEv,"axG",@progbits,_ZN9__gnu_cxx16__aligned_membufIiE6_M_ptrEv,comdat
	.align 2
	.weak	_ZN9__gnu_cxx16__aligned_membufIiE6_M_ptrEv
	.type	_ZN9__gnu_cxx16__aligned_membufIiE6_M_ptrEv, @function
_ZN9__gnu_cxx16__aligned_membufIiE6_M_ptrEv:
.LFB9631:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx16__aligned_membufIiE7_M_addrEv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9631:
	.size	_ZN9__gnu_cxx16__aligned_membufIiE6_M_ptrEv, .-_ZN9__gnu_cxx16__aligned_membufIiE6_M_ptrEv
	.section	.text._ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE7destroyIiEEvPT_,"axG",@progbits,_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE7destroyIiEEvPT_,comdat
	.align 2
	.weak	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE7destroyIiEEvPT_
	.type	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE7destroyIiEEvPT_, @function
_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE7destroyIiEEvPT_:
.LFB9632:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9632:
	.size	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE7destroyIiEEvPT_, .-_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE7destroyIiEEvPT_
	.section	.text._ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE10deallocateEPS2_m,"axG",@progbits,_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE10deallocateEPS2_m,comdat
	.align 2
	.weak	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE10deallocateEPS2_m
	.type	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE10deallocateEPS2_m, @function
_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE10deallocateEPS2_m:
.LFB9633:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZdlPv@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9633:
	.size	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE10deallocateEPS2_m, .-_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE10deallocateEPS2_m
	.section	.text._ZNK9__gnu_cxx16__aligned_membufIiE6_M_ptrEv,"axG",@progbits,_ZNK9__gnu_cxx16__aligned_membufIiE6_M_ptrEv,comdat
	.align 2
	.weak	_ZNK9__gnu_cxx16__aligned_membufIiE6_M_ptrEv
	.type	_ZNK9__gnu_cxx16__aligned_membufIiE6_M_ptrEv, @function
_ZNK9__gnu_cxx16__aligned_membufIiE6_M_ptrEv:
.LFB9634:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK9__gnu_cxx16__aligned_membufIiE7_M_addrEv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9634:
	.size	_ZNK9__gnu_cxx16__aligned_membufIiE6_M_ptrEv, .-_ZNK9__gnu_cxx16__aligned_membufIiE6_M_ptrEv
	.section	.text._ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE11_M_get_nodeEv,"axG",@progbits,_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE11_M_get_nodeEv,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE11_M_get_nodeEv
	.type	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE11_M_get_nodeEv, @function
_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE11_M_get_nodeEv:
.LFB9635:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE21_M_get_Node_allocatorEv
	movl	$1, %esi
	movq	%rax, %rdi
	call	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeIiEEE8allocateERS2_m
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9635:
	.size	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE11_M_get_nodeEv, .-_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE11_M_get_nodeEv
	.section	.text._ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE17_M_construct_nodeIJiEEEvPSt13_Rb_tree_nodeIiEDpOT_,"axG",@progbits,_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE17_M_construct_nodeIJiEEEvPSt13_Rb_tree_nodeIiEDpOT_,comdat
	.align 2
	.weak	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE17_M_construct_nodeIJiEEEvPSt13_Rb_tree_nodeIiEDpOT_
	.type	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE17_M_construct_nodeIJiEEEvPSt13_Rb_tree_nodeIiEDpOT_, @function
_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE17_M_construct_nodeIJiEEEvPSt13_Rb_tree_nodeIiEDpOT_:
.LFB9636:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$32, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, %rsi
	movl	$40, %edi
	call	_ZnwmPv
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE
	movq	%rax, %r12
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt13_Rb_tree_nodeIiE9_M_valptrEv
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE21_M_get_Node_allocatorEv
	movq	%r12, %rdx
	movq	%rbx, %rsi
	movq	%rax, %rdi
	call	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeIiEEE9constructIiJiEEEvRS2_PT_DpOT0_
	nop
	addq	$32, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9636:
	.size	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE17_M_construct_nodeIJiEEEvPSt13_Rb_tree_nodeIiEDpOT_, .-_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE17_M_construct_nodeIJiEEEvPSt13_Rb_tree_nodeIiEDpOT_
	.section	.text._ZN9__gnu_cxx16__aligned_membufIiE7_M_addrEv,"axG",@progbits,_ZN9__gnu_cxx16__aligned_membufIiE7_M_addrEv,comdat
	.align 2
	.weak	_ZN9__gnu_cxx16__aligned_membufIiE7_M_addrEv
	.type	_ZN9__gnu_cxx16__aligned_membufIiE7_M_addrEv, @function
_ZN9__gnu_cxx16__aligned_membufIiE7_M_addrEv:
.LFB9695:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9695:
	.size	_ZN9__gnu_cxx16__aligned_membufIiE7_M_addrEv, .-_ZN9__gnu_cxx16__aligned_membufIiE7_M_addrEv
	.section	.text._ZNK9__gnu_cxx16__aligned_membufIiE7_M_addrEv,"axG",@progbits,_ZNK9__gnu_cxx16__aligned_membufIiE7_M_addrEv,comdat
	.align 2
	.weak	_ZNK9__gnu_cxx16__aligned_membufIiE7_M_addrEv
	.type	_ZNK9__gnu_cxx16__aligned_membufIiE7_M_addrEv, @function
_ZNK9__gnu_cxx16__aligned_membufIiE7_M_addrEv:
.LFB9696:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9696:
	.size	_ZNK9__gnu_cxx16__aligned_membufIiE7_M_addrEv, .-_ZNK9__gnu_cxx16__aligned_membufIiE7_M_addrEv
	.section	.text._ZNSt16allocator_traitsISaISt13_Rb_tree_nodeIiEEE8allocateERS2_m,"axG",@progbits,_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeIiEEE8allocateERS2_m,comdat
	.weak	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeIiEEE8allocateERS2_m
	.type	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeIiEEE8allocateERS2_m, @function
_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeIiEEE8allocateERS2_m:
.LFB9697:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rcx
	movq	-8(%rbp), %rax
	movl	$0, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE8allocateEmPKv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9697:
	.size	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeIiEEE8allocateERS2_m, .-_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeIiEEE8allocateERS2_m
	.section	.text._ZNSt16allocator_traitsISaISt13_Rb_tree_nodeIiEEE9constructIiJiEEEvRS2_PT_DpOT0_,"axG",@progbits,_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeIiEEE9constructIiJiEEEvRS2_PT_DpOT0_,comdat
	.weak	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeIiEEE9constructIiJiEEEvRS2_PT_DpOT0_
	.type	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeIiEEE9constructIiJiEEEvRS2_PT_DpOT0_, @function
_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeIiEEE9constructIiJiEEEvRS2_PT_DpOT0_:
.LFB9698:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE
	movq	%rax, %rdx
	movq	-16(%rbp), %rcx
	movq	-8(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE9constructIiJiEEEvPT_DpOT0_
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9698:
	.size	_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeIiEEE9constructIiJiEEEvRS2_PT_DpOT0_, .-_ZNSt16allocator_traitsISaISt13_Rb_tree_nodeIiEEE9constructIiJiEEEvRS2_PT_DpOT0_
	.section	.text._ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE8allocateEmPKv,"axG",@progbits,_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE8allocateEmPKv,comdat
	.align 2
	.weak	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE8allocateEmPKv
	.type	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE8allocateEmPKv, @function
_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE8allocateEmPKv:
.LFB9724:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE8max_sizeEv
	cmpq	%rax, -16(%rbp)
	seta	%al
	testb	%al, %al
	je	.L134
	call	_ZSt17__throw_bad_allocv@PLT
.L134:
	movq	-16(%rbp), %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	movq	%rax, %rdi
	call	_Znwm@PLT
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9724:
	.size	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE8allocateEmPKv, .-_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE8allocateEmPKv
	.section	.text._ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE9constructIiJiEEEvPT_DpOT0_,"axG",@progbits,_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE9constructIiJiEEEvPT_DpOT0_,comdat
	.align 2
	.weak	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE9constructIiJiEEEvPT_DpOT0_
	.type	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE9constructIiJiEEEvPT_DpOT0_, @function
_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE9constructIiJiEEEvPT_DpOT0_:
.LFB9725:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE
	movl	(%rax), %ebx
	movq	-32(%rbp), %rax
	movq	%rax, %rsi
	movl	$4, %edi
	call	_ZnwmPv
	movl	%ebx, (%rax)
	nop
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9725:
	.size	_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE9constructIiJiEEEvPT_DpOT0_, .-_ZN9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE9constructIiJiEEEvPT_DpOT0_
	.section	.text._ZNK9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE8max_sizeEv,"axG",@progbits,_ZNK9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE8max_sizeEv,comdat
	.align 2
	.weak	_ZNK9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE8max_sizeEv
	.type	_ZNK9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE8max_sizeEv, @function
_ZNK9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE8max_sizeEv:
.LFB9728:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movabsq	$230584300921369395, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9728:
	.size	_ZNK9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE8max_sizeEv, .-_ZNK9__gnu_cxx13new_allocatorISt13_Rb_tree_nodeIiEE8max_sizeEv
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB9753:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L141
	cmpl	$65535, -8(%rbp)
	jne	.L141
	leaq	_ZStL8__ioinit(%rip), %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	leaq	__dso_handle(%rip), %rdx
	leaq	_ZStL8__ioinit(%rip), %rsi
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__cxa_atexit@PLT
.L141:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9753:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB9776:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9776:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.rel.local.DW.ref.__gxx_personality_v0,"awG",@progbits,DW.ref.__gxx_personality_v0,comdat
	.align 8
	.type	DW.ref.__gxx_personality_v0, @object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.quad	__gxx_personality_v0
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
