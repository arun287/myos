.section .text

.global flush_gdt
.type flush_gdt, @function

flush_gdt:
	# Disable Interrupts
	#cli

	# Load the GDT
	movl 4(%esp), %eax
	lgdt (%eax)

	# Load Data Segment Registers
	movw $0x10, %ax
	movw %ax, %ds
	movw %ax, %es
	movw %ax, %fs
	movw %ax, %gs
	movw %ax, %ss

	#Longjump to load code register
	jmp $0x08,$.flush
.flush:
	ret
