/*
 Aplicação: 
   Toda vez que a tecla 'h' é pressionada (com foco na JTAG UART),
   o primeiro LED vermelho é aceso (se estiver apagado) ou apagado
   (se estiver aceso)

*/

.equ LEDV, 0x10000000
.equ UART, 0x10001000


.global _start
_start:
	
	movia r8, LEDV
	movia r9, UART
	movi  r10, 0x0   # estado do LED
	
POLLING_LEITURA:	
	
	ldwio r11, (r9)
	andi  r12, r11, 0x8000   # separar campo RVALID
	beq   r12, r0, POLLING_LEITURA
	
	
	# se cheguei, então os 8 primeiros bits de r11 tem o caracter
	movi  r12, 'h'
	andi  r11, r11, 0xFF   # separar campo DATA
	
	# falta checar o WSPACE (nesse caso em particular, não é necessário)
	stwio r11, (r9) 
	
	bne   r11, r12, NAO_EH_H
	 # caracter h foi digitado no terminal JTAG UART
	 # codigo para acender/apagar LED
	 
	 xori r10, r10, 1      # inverto primeiro bit
	 stwio r10, (r8)
	
NAO_EH_H:

    br  POLLING_LEITURA 
	
	#ldwio r11, (r9)
	# r11 = 0x0008 8 0  61
	#    DATA = 0x61  - código ASCII da letra digitada
	#    RVALID = 1
	#    RAVAIL = 8   - caracteres restantes no buffer
	
	#ldwio r12, 4(r9)
	# r12 = 0x0040 0000
	# WSPACE = 0x40 (64) - no buffer de saida, ainda há 64 posições
	#   vagas
/*	
	movia r13, MINHA_STRING
LOOP:	
    ldb  r14, (r13)
	
	# checar por byte nulo -> terminou string
	beq  r14, r0, SAI_LOOP
	
	
POLLING_ESCRITA:	
	# checar se há espaço no buffer de saida (write FIFO)
	ldwio r15, 4(r9)
	srli  r15, r15, 16  # -> isolando WSPACE
	beq   r15, r0, POLLING_ESCRITA
	
	stwio r14, (r9)  # envio o caracter 0x61 para saida da UART
	
	addi r13, r13, 1  # aponta para próximo caracter
	
	br LOOP
	
SAI_LOOP:
  br SAI_LOOP
	
	
MINHA_STRING:
 .asciz "123456789-987654321-123456789-987654321-123456789-987654321-987654321" 
*/	
	
	
	
	
	
	
	