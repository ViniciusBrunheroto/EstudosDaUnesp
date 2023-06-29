/*
Aplicação:
  Toda vez que o botão 2 for apertado, um segmento novo do primeiro display de 7seg 
  deve ser aceso (e o anterior apagado)


POLLING versus INTERRUPÇÃO:

POLLING -> CPU espera o dispositivo
INT     -> dispositivo que avisa que está pronto
        -> é assíncrono (pode acontecer a qualquer momento)
		-> parar o que estava fazendo e salta para a RTI (0x20)
		   -> salvar o PC no registrador (r29 ou ea)
		   
	ienable -> identifica as IRQs dos dispositivos habilitados
    ipending -> identifica qual dispositivo (através da IRQ) que gerou a INT
*/

.equ PB, 0x10000050
.equ D7S, 0x10000020


.org 0x20   # Endereço da rotina de tratamento de interrupção (RTI)
RTI:
  addi sp, sp, -4
  stw  ra, (sp)

# quem gerou a exceção: foi SW ou HW?
   rdctl  et, ipending
   beq    et, r0, NOT_HW

   addi   ea, ea, -4

# como que eu sei quem gerou a interrupção?
   andi   et, et, 0b10         # -> PB
   beq    et, r0, NOT_PB
   
   call   TRATA_PB
   
 
NOT_PB:

NOT_HW:

FIM_RTI:

  ldw ra, (sp)
  addi sp, sp, 4

  eret  # volta para o endereço salvo em r29 (ea)



TRATA_PB:
  addi sp, sp, -12
  stw  r8, 8(sp)
  stw  r9, 4(sp)
  stw  r11, (sp)

  movia r8, PB
  movi  r11, 0b0100
  stwio r11, 12(r8)    # reseta edge-capture (botao 2)
 
  movia r9, D7S
  
  movia r8, D7S_STATE
  ldw   r8, (r8)       # r8 = estado do display

# MESMA CODIGO DO POLLING  
  stwio  r8, (r9) 
  slli   r8, r8, 1  # desloco 1 bit para esquerda
	
  movi   r11, 0b10000000
  ble    r8, r11, DO_NOT_RESET:
	 movi r8, 1      # reseto estado do display 

DO_NOT_RESET:
  
  movia r9, D7S_STATE
  stw    r8, (r9) 
  
  ldw  r8, 8(sp)
  ldw  r9, 4(sp)
  ldw  r11, (sp)
  addi sp, sp, 12
  ret
  
  




.global _start
_start:

  movia  sp, 0x1000
  
  movia r8, PB
  
  # habilitar interrupção

  # 1) habilitar dispositivo   
  movi  r9, 0b0100
  stwio r9, 8(r8)     # habilita interrupção do botão 2
  
  # 2) habilitar IRQ (Interrupt ReQuest)
  # tenho que habilitar IRQ 1 (push button) no ienable
  movi  r9, 0b10
  wrctl ienable, r9
  
  # 3) habilitar interrupção na CPU (sistema)
  movi  r9, 0b1
  wrctl status, r9 


fim:


  br fim


D7S_STATE:
.word 0x1


/*
# VERSAO COM POLLING

	movia r8, PB
	movia r9, D7S
	
	movi r10, 1    # estado do display
	
POLLING:  # aguardar botão ser pressionado
   # C - 1100
    ldwio r11, 12(r8)   # PB 
    andi  r12, r11, 0b0100   # 4 -> botao2
	
    beq   r12, r0, POLLING

    movi  r11, 0b0100
	stwio r11, 12(r8)    # reseta edge-capture (botao 2)

    # botao 2 foi pressionado
    stwio  r10, (r9)
	
	slli   r10, r10, 1  # desloco 1 bit para esquerda
	
	movi   r11, 0b10000000
	ble    r10, r11, DO_NOT_RESET:
	   movi r10, 1      # reseto estado do display
DO_NOT_RESET:	
	
	br POLLING
*/	
	
