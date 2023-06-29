	
	
.equ UART, 0x10001000
.equ TIMER, 0x10002000


.org 0x20
RTI:

  addi sp, sp, -8
  stw  ra, 4(sp)
  stw r16, (sp)
  
  # quem gerou a exceção: foi SW ou HW?
   rdctl  et, ipending
   beq    et, r0, NOT_HW

   addi   ea, ea, -4
   
   
  # como que eu sei quem gerou a interrupção?
   andi   r16, et, 0b10         # -> PB
   beq    r16, r0, NOT_PB

  call TRATA_PB



NOT_PB:
# checar se foi o TIMER
   andi   r16, et, 0b01          # -> TIMER (IRQ0)
   beq    r16, r0, NOT_TIMER

   call   TRATA_TIMER


NOT_TIMER:

NOT_HW:

FIM_RTI:

  ldw ra, 4(sp)
  ldw r16, (sp)
  addi sp, sp, 8

  eret  # volta para o endereço salvo em r29 (ea)


TRATA_PB:
  ret

TRATA_TIMER:
  addi sp, sp, -16
  stw  r21, 12(sp)
  stw  r12, 8(sp)
  stw  r11, 4(sp)
  stw  r8 , (sp)




  # resetar bit de TO do TIMER
  movia r21,TIMER
  stwio r0, 0(r21)


  #precisa imprimir o último caractere recebido!
   movia r8, UART
   
   
  #mostrar o caractere no terminal
   movia r11,DIGITO
   ldw r12,(r11)
  
   stwio r12,(r8)
 
 
  ldw  r21, 12(sp)
  ldw  r12, 8(sp)
  ldw  r11, 4(sp)
  ldw  r8, (sp)
  addi sp, sp, 16

 
   ret



.global _start
_start:
	
	movia r8, UART
	movia r21,TIMER
	
	
	# inicializar o stack pointer
    movia  sp, 0x1000
	
	# habilitar interrupção
	 #1) habilitar dispositivo 
	 # habilitar o temporizador
	 
     # - setar período de contagem (1 segundo - 50MHz então 0,5s - 25Mhz)
     movia r21, TIMER
     movia r9, 25000000
     # parte baixa
     andi  r11, r9, 0xFFFF  # isolo a parte baixa dos 32 bits
     stwio r11, 8(r21) 
     # parte alta
     srli  r11, r9, 16      # isolo a parte alta dos 32 bits
     stwio r11, 12(r21)
     # preciso fazer o TIMER começar a contar
     # habilito ITO, habilito CONT, habilito START
     movi  r11, 0b111   # máscara para habilitar TIMER
     stwio r11, 4(r21)
	
	
	#2) habilitar IRQ (Interrupt ReQuest)
	 # tenho que habilitar IRQ 0 (timer) no ienable
     movi  r9, 0b1
     wrctl ienable, r9
	 
	 
	 #3) habilitar interrupção na CPU (sistema)
     movi  r9, 0b1
     wrctl status, r9	


	
/*Nesse caso específico, não há necessidade de um polling para escrita
nem fazer checagem do WSPACE, pois 
o escrever está condicionado à digitação de algum caracter.
*/
POLLING_LEITURA:	

  ldwio r11, (r8)
  andi  r12, r11, 0x8000  # separar campo RVALID
  beq   r12, r0, POLLING_LEITURA
  
  # 8 primeiros bits de r11 tem o caracter lido 
  
  andi  r11, r11, 0xFF   # separar campo DATA
  
  movia r13,DIGITO
  stw r11,(r13)
  
  # mostrar o caractere no terminal
  stwio r11, (r8) 
  
  
  br POLLING_LEITURA
  
  
  
  .org 0x300
  
  DIGITO:
  .word 0x0
  
  
 FIM: 
  br FIM