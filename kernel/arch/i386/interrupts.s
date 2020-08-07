.global flush_idt

.global irq0
.global irq1
.global irq2
.global irq3
.global irq4
.global irq5
.global irq6
.global irq7
.global irq8
.global irq9
.global irq10
.global irq11
.global irq12
.global irq13
.global irq14
.global irq15
.global irq16
.global irq17
.global irq18
.global irq19
.global irq20
.global irq21
.global irq22
.global irq23
.global irq24
.global irq25
.global irq26
.global irq27
.global irq28
.global irq29
.global irq30
.global irq31

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

irq0:
	pusha
	cld
	call irq0_handler
	popa
	iret
 
irq1:
	pusha
	cld
	call irq1_handler
	popa
	iret
 
irq2:
	pusha
	cld
	call irq2_handler
	popa
	iret
 
irq3:
	pusha
	cld
	call irq3_handler
	popa
	iret
 
irq4:
	pusha
	cld
	call irq4_handler
	popa
	iret
 
irq5:
	pusha
	cld
	call irq5_handler
	popa
	iret
 
irq6:
	pusha
	cld
	call irq6_handler
	popa
	iret
 
irq7:
	pusha
	cld
	call irq7_handler
	popa
	iret
 
irq8:
	pusha
	cld
	call irq8_handler
	popa
	iret
 
irq9:
	pusha
	cld
	call irq9_handler
	popa
	iret
 
irq10:
	pusha
	cld
	call irq10_handler
	popa
	iret
 
irq11:
	pusha
	cld
	call irq11_handler
	popa
	iret
 
irq12:
	pusha
	cld
	call irq12_handler
	popa
	iret
 
irq13:
	pusha
	cld
	call irq13_handler
	popa
	iret
 
irq14:
	pusha
	cld
	call irq14_handler
	popa	
	iret
 
irq15:
	pusha
	cld
	call irq15_handler
	popa	
	iret

irq16:
	pusha
	cld
	call irq16_handler
	popa
	iret
 
irq17:
	pusha
	cld
	call irq17_handler
	popa
	iret
 
irq18:
	pusha
	cld
	call irq18_handler
	popa
	iret
 
irq19:
	pusha
	cld
	call irq19_handler
	popa
	iret
 
irq20:
	pusha
	cld
	call irq20_handler
	popa
	iret
 
irq21:
	pusha
	cld
	call irq21_handler
	popa
	iret
 
irq22:
	pusha
	cld
	call irq22_handler
	popa
	iret
 
irq23:
	pusha
	cld
	call irq23_handler
	popa
	iret
 
irq24:
	pusha
	cld
	call irq24_handler
	popa
	iret
 
irq25:
	pusha
	cld
	call irq25_handler
	popa
	iret
 
irq26:
	pusha
	cld
	call irq26_handler
	popa
	iret
 
irq27:
	pusha
	cld
	call irq27_handler
	popa
	iret
 
irq28:
	pusha
	cld
	call irq28_handler
	popa
	iret
 
irq29:
	pusha
	cld
	call irq29_handler
	popa
	iret
 
irq30:
	pusha
	cld
	call irq30_handler
	popa	
	iret
 
irq31:
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

