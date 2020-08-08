.global flush_idt

.global isr0
.global isr1
.global isr2
.global isr3
.global isr4
.global isr5
.global isr6
.global isr7
.global isr8
.global isr9
.global isr10
.global isr11
.global isr12
.global isr13
.global isr14
.global isr15

.extern irq0_handler
.extern irq1_handler
.extern irq2_handler
.extern irq3_handler
.extern irq4_handler
.extern irq5_handler
.extern irq6_handler
.extern irq7_handler
.extern irq8_handler
.extern irq9_handler
.extern irq10_handler
.extern irq11_handler
.extern irq12_handler
.extern irq13_handler
.extern irq14_handler
.extern irq15_handler

.extern pit_callback

isr0:
	pusha
	cld
	call irq0_handler
	popa
    sti
	iret
 
isr1:
	pusha
	cld
	call irq1_handler
	popa
	iret
 
isr2:
	pusha
	cld
	call irq2_handler
	popa
	iret
 
isr3:
	pusha
	cld
	call irq3_handler
	popa
	iret
 
isr4:
	pusha
	cld
	call irq4_handler
	popa
	iret
 
isr5:
	pusha
	cld
	call irq5_handler
	popa
	iret
 
isr6:
	pusha
	cld
	call irq6_handler
	popa
	iret
 
isr7:
	pusha
	cld
	call irq7_handler
	popa
	iret
 
isr8:
	pusha
	cld
	call irq8_handler
	popa
	iret
 
isr9:
	pusha
	cld
	call irq9_handler
	popa
	iret
 
isr10:
	pusha
	cld
	call irq10_handler
	popa
	iret
 
isr11:
	pusha
	cld
	call irq11_handler
	popa
	iret
 
isr12:
	pusha
	cld
	call irq12_handler
	popa
	iret
 
isr13:
	pusha
	cld
	call irq13_handler
	popa
	iret
 
isr14:
	pusha
	cld
	call irq14_handler
	popa	
	iret
 
isr15:
	pusha
	cld
	call irq15_handler
	popa	
	iret

flush_idt:
    movl 4(%esp), %eax
	lidt (%eax)
    sti
    ret

