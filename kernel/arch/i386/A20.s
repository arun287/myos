.global enable_A20

enable_A20:
    cli
    pusha
    movb $0x02,%al
    outb %al,$0x92
    popa
    sti
    ret
   
