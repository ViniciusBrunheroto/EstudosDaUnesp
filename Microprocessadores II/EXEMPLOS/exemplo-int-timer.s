/*
Aplicação:
  Toda vez que o botão 2 for apertado, um segmento novo do primeiro display de 7seg 
  deve ser aceso (e o anterior apagado)
  + A cada 1 segundo, um segmento novo do display2 é aceso, e o anterior é apagado.


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
# dispositivos novos da aula
.equ D7S2, 0x10000030
.equ TIMER, 0x10002000


.org 0x20   # Endereço da rotina de tratamento de interrupção (RTI)
RTI:
  addi sp, sp, -8
  stw  ra, 4(sp)
  stw  r16, (sp)

# quem gerou a exceção: foi SW ou HW?
   rdctl  et, ipending
   beq    et, r0, NOT_HW

   addi   ea, ea, -4

# como que eu sei quem gerou a interrupção?
   andi   r16, et, 0b10         # -> PB (IRQ1)
   beq    r16, r0, NOT_PB
   
   call   TRATA_PB
   
 
NOT_PB:
# checar se foi o TIMER
   andi   r16, et, 0b01          # -> TIMER (IRQ0)
   beq    r16, r0, NOT_TIMER

   call   TRATA_TIMER


NOT_TIMER:

NOT_HW:

FIM_RTI:

  ldw  r16, (sp)
  ldw  ra, 4(sp)
  addi sp, sp, 8

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
  
  
# Trata dispositivo temporizador
TRATA_TIMER:
# PROLOGO
  addi sp, sp, -16
  stw  r8, 12(sp)
  stw  r9, 8(sp)
  stw  r10, 4(sp)
  stw  r11, (sp)

 # resetar bit de TO do TIMER
  movia r10, TIMER
  stwio r0, 0(r10)
  
  
  # implementar o evento
  movia r9, D7S2
  
  movia r8, D7S2_STATE
  ldw   r8, (r8)       # r8 = estado do display

  stwio  r8, (r9) 
  slli   r8, r8, 1  # desloco 1 bit para esquerda
	
  movi   r11, 0b10000000
  ble    r8, r11, DO_NOT_RESET2:
	 movi r8, 1      # reseto estado do display 

DO_NOT_RESET2:
  
  movia r9, D7S2_STATE
  stw    r8, (r9)   
  
  

# EPILOGO
  ldw  r8, 12(sp)
  ldw  r9, 8(sp)
  ldw  r10, 4(sp)
  ldw  r11, (sp)
  addi sp, sp, 16
  ret




.global _start
_start:

  movia  sp, 0x1000
  
  movia r8, PB
  
  # habilitar interrupção

  # 1) habilitar dispositivo   
  movi  r9, 0b0100
  stwio r9, 8(r8)     # habilita interrupção do botão 2
  
  # habilitar o temporizador
   # - setar período de contagem (1 segundo - 50MHz)
   movia r10, TIMER
   movia r9, 50000000
   # parte baixa
   andi  r11, r9, 0xFFFF  # isolo a parte baixa dos 32 bits
   stwio r11, 8(r10) 
   # parte alta
   srli  r11, r9, 16      # isolo a parte alta dos 32 bits
   stwio r11, 12(r10)
   # preciso fazer o TIMER começar a contar
   # habilito ITO, habilito CONT, habilito START
   movi  r11, 0b111   # máscara para habilitar TIMER
   stwio r11, 4(r10)
  
  # 2) habilitar IRQ (Interrupt ReQuest)
  # tenho que habilitar IRQ 1 (push button) no ienable
  # tenho também de habilitar IRQ 0 (timer) no ienable
  movi  r9, 0b11
  wrctl ienable, r9
  # ienable - b31 b30 b29 ... b5 b4 b3 b2 b1 b0
  
  # 3) habilitar interrupção na CPU (sistema)
  movi  r9, 0b1
  wrctl status, r9 


fim:

  # computação

  br fim


D7S_STATE:
.word 0x1
D7S2_STATE:
.word 0x1


	
