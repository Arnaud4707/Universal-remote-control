.section .text.entry
	.align 4
    .global _start
    .global reset_handler
    .type _start @function
    .type reset_handler @function

_start:
    movi	a1, _stack_top
	call0	reset_handler

hang:
	j	hang

.section .text.startup
.align 4

reset_handler:
	movi	a2, _data_load
	movi	a3, _data_start
	movi	a4, _data_end

copy_data:
	beq		a3, a4, clear_bss

	l32i	a5, a2, 0
	s32i	a5, a3, 0

	addi	a2, a2, 4
	addi	a3, a3, 4

	j		copy_data

clear_bss:
	movi	a2, _start_bss
	movi	a3, _end_bss
	movi	a4, 0

	j		bzero

bzero:
	beq		a2, a3, entry_main

	s32i	a4, a2, 0
	addi	a2, a2, 4

	j		bzero

entry_main:
	call0	main

loop:
	j	loop