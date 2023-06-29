
.equ CHAVES, 0x10000040
.equ LEDV, 0x10000010
.equ PB, 0x10000050
.equ D7SEG, 0x10000020

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

  call TRATA_PB
 
 
DISPLAY:
#-----------------------------------------------------------#
#PROCESSO DE PASSAR OS NUMEROS PARA O DISPLAY

  addi sp, sp, -28
  stw  r11, 24(sp)
  stw  r12, 20(sp)
  stw  r13, 16(sp)
  stw  r14, 12(sp)
  stw  r15, 8(sp)
  stw  r16, 4(sp)
  stw  r7,  (sp)

  movia r7,SOMA
  ldw r16,(r7)

# 1º DÍGITO
   andi r11,r16,0b0000000000001111

   movi r12,TABELA

   add r12,r12,r11
   
   ldb r13,(r12)
   
   stbio r13,0(r10)
   
   mov r13,r0 # zerando reg do dígito
   mov r15,r0
   mov r12,r0
   
# 2º DÍGITO
   andi r11,r16,0b0000000011110000
   srli r14,r11,4 # desloca 4 bits à direita
   
   movi r12,TABELA
   add r12,r12,r14
   
   ldb r13,(r12)
   
   stbio r13,1(r10)

  mov r13,r0 # zerando reg do dígito
  mov r14,r0
  mov r12,r0

# 3º DÍGITO
   andi r11,r16,0b0000111100000000
   srli r14,r11,8 # desloca 8 bits à direita
   
   movi r12,TABELA
   
   add r12,r12,r14
   
   ldb r13,(r12)
   
   stbio r13,2(r10)
   
   
   mov r13,r0 # zerando reg do dígito
   mov r14,r0 
   mov r12,r0
   
 # 4º DÍGITO
   andi r11,r16,0b1111000000000000
   srli r14,r11,16 # desloca 12 bits à direita
   
   movi r12,TABELA
   
   add r12,r12,r14
   
   ldb r13,(r12)
   
   stbio r13,3(r10)

 
  ldw r11, 24(sp)
  ldw r12, 20(sp)
  ldw r13, 16(sp)
  ldw r14, 12(sp)
  ldw r15, 8(sp)
  ldw r16, 4(sp)
  ldw r7, (sp)
  addi sp, sp, 28
 
 # ---------------------------------------------------------------------
 
 
NOT_PB:

NOT_HW:

FIM_RTI:

  ldw ra, (sp)
  addi sp, sp, 4

  eret  # volta para o endereço salvo em r29 (ea)
  
  

 TRATA_PB:
 
  addi sp, sp, -28
  stw  r5,  24(sp)
  stw  r11, 20(sp)
  stw  r13, 16(sp)
  stw  r14, 12(sp)
  stw  r15, 8(sp)
  stw  r16, 4(sp)
  stw  r19,  (sp)


  movi r13,10
  #qual botão foi pressionado? 1 ou 3?
  ldwio r15,12(r20)
  
  
  # usuário o apertou 1 e 3? = situação de BUG
   andi r11,r15,0b1010
   beq r11,r13,BUG
  
   mov r11,r0
  # usuário apertou o botão 1 = somar
  andi r11,r15,0b0010
  beq r11,r15,NAO_RESETAR


# usuário apertou o botão 3 = resetar

   movia r5,SOMA
   ldw r16,(r5)

   mov r16, r0 		# r16 -> acumulador

   
   movi r14, 0b1010
  
   stwio r14, 12(r20)  # resetar reg de captura de borda
   
   stwio r16, (r18) # ----> passar a soma acumulada para os LED's

   stw r16,(r5)
  
  ldw  r5,  24(sp)
  ldw  r11, 20(sp)
  ldw  r13, 16(sp)
  ldw  r14, 12(sp)
  ldw  r15, 8(sp)
  ldw  r16,  4(sp)
  ldw  r19,  (sp)
  addi sp, sp, 28
 
  ret

#usuário apertou o botão 1 = precisa acumular a soma
NAO_RESETAR:
  mov r11,r0
  
  ldwio r19,(r17)
  
  movia r11,SOMA
  ldw r16,(r11)
 
  add r16,r16,r19   #r16 = r16 + r19
  
  stw r16,(r11)
 
  stwio r16, (r18) # ----> passar a soma acumulada para os LED's
 
  movi r14, 0b0010
  
  stwio r14, 12(r20)  # resetar reg de captura de borda
 
 
  ldw  r5,  24(sp)
  ldw  r11, 20(sp)
  ldw  r13, 16(sp)
  ldw  r14, 12(sp)
  ldw  r15, 8(sp)
  ldw  r16, 4(sp)
  ldw  r19,  (sp)
  addi sp, sp, 28 
 
  ret
  
  
  BUG:
# precisa resetar os dois botões

   movi r5,0b1010
   stwio r5, 12(r20)
   
   
   
  ldw  r5,  24(sp)
  ldw  r11, 20(sp)
  ldw  r13, 16(sp)
  ldw  r14, 12(sp)
  ldw  r15, 8(sp)
  ldw  r16, 4(sp)
  ldw  r19,  (sp)
  addi sp, sp, 28 
 
  ret
  
  

.global _start
_start:
	
    movia  sp, 0x1000

	  movia r17, CHAVES
      movia r18, LEDV
      movia r20, PB
      movia r10, D7SEG
	  
	  mov r16,r0  #zerar o contador
	  
	  
 #zerar os dispositivos
    stwio r0,(r17)
    stwio r0,(r18)
    stwio r0,(r20)
    stbio r0,0(r10)
    stbio r0,1(r10)
    stbio r0,2(r10)
    stbio r0,3(r10)
	
	
	# habilitar interrupção
	
     #1) habilitar dispositivo  
	 movi  r9, 0b1010
     stwio r9, 8(r20)     # habilita interrupção do botão 1 e 3
	
	 #2) habilitar IRQ (Interrupt ReQuest)
     # tenho que habilitar IRQ 1 (push button) no ienable
     movi  r9, 0b10
     wrctl ienable, r9
	
	 #3) habilitar interrupção na CPU (sistema)
     movi  r9, 0b1
     wrctl status, r9	
	
	
FIM:
   br FIM
		

SOMA:
.word 0x0	
		
	
 .org 0x300 
  TABELA:
  .byte  0b0111111  # 0
  .byte  0b0000110  # 1
  .byte  0b1011011  # 2
  .byte  0b1001111  # 3
  .byte  0b1100110  # 4
  .byte  0b1101101  # 5
  .byte  0b1111101  # 6
  .byte  0b0000111  # 7
  .byte  0b1111111  # 8
  .byte  0b1100111  # 9
  .byte  0b1110111  # A
  .byte  0b1111111  # B
  .byte  0b0111001  # C
  .byte  0b0111111  # D
  .byte  0b0111001  # E
  .byte  0b0000111  # F	
	
	


  
  