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
.global isr16
.global isr17
.global isr18
.global isr19
.global isr20
.global isr21
.global isr22
.global isr23
.global isr24
.global isr25
.global isr26
.global isr27
.global isr28
.global isr29
.global isr30
.global isr31

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
.extern irq16_handler
.extern irq17_handler
.extern irq18_handler
.extern irq19_handler
.extern irq20_handler
.extern irq21_handler
.extern irq22_handler
.extern irq23_handler
.extern irq24_handler
.extern irq25_handler
.extern irq26_handler
.extern irq27_handler
.extern irq28_handler
.extern irq29_handler
.extern irq30_handler
.extern irq31_handler

isr0:
	pusha
	cld
	call irq0_handler
	popa
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

isr16:
	pusha
	cld
	call irq16_handler
	popa
	iret
 
isr17:
	pusha
	cld
	call irq17_handler
	popa
	iret
 
isr18:
	pusha
	cld
	call irq18_handler
	popa
	iret
 
isr19:
	pusha
	cld
	call irq19_handler
	popa
	iret
 
isr20:
	pusha
	cld
	call irq20_handler
	popa
	iret
 
isr21:
	pusha
	cld
	call irq21_handler
	popa
	iret
 
isr22:
	pusha
	cld
	call irq22_handler
	popa
	iret
 
isr23:
	pusha
	cld
	call irq23_handler
	popa
	iret
 
isr24:
	pusha
	cld
	call irq24_handler
	popa
	iret
 
isr25:
	pusha
	cld
	call irq25_handler
	popa
	iret
 
isr26:
	pusha
	cld
	call irq26_handler
	popa
	iret
 
isr27:
	pusha
	cld
	call irq27_handler
	popa
	iret
 
isr28:
	pusha
	cld
	call irq28_handler
	popa
	iret
 
isr29:
	pusha
	cld
	call irq29_handler
	popa
	iret
 
isr30:
	pusha
	cld
	call irq30_handler
	popa	
	iret
 
isr31:
	pusha
	cld
	call irq31_handler
	popa	
	iret

flush_idt:
    movl 4(%esp), %eax
	lidt (%eax)
    sti
    ret

