.global flush_gdt
flush_gdt:
	movl 4(%esp), %eax
	lgdt (%eax)
    jmp $0x08,$.flush

.flush:
	movw $0x10, %ax
	movw %ax, %ds
	movw %ax, %es
	movw %ax, %fs
	movw %ax, %gs
	movw %ax, %ss
    ret

