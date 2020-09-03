.global flush_gdt
flush_gdt:
    cli
	movl 4(%esp), %eax
	lgdt (%eax)
    movl %cr0,%eax 
    orb $0x01,%al
    movl %eax,%cr0 
    jmp $0x08,$.flush

.flush:
    .code32
	movw $0x10, %ax
	movw %ax, %ds
	movw %ax, %es
	movw %ax, %fs
	movw %ax, %gs
	movw %ax, %ss
    sti
    ret

