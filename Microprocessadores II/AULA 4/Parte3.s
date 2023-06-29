
	
.global _start
_start:
	
.equ CHAVES, 0x10000040
.equ LEDV, 0x10000010
.equ PB, 0x10000050
.equ D7SEG, 0x10000020


.global _start
_start:
	
	
  mov r16, r0 		# r16 -> acumulador

  movia r17, CHAVES
  movia r18, LEDV
  movia r20, PB
  movia r10, D7SEG
  
  #zerar auxiliares
  mov r19,r0
  mov r22,r0 
  
  #zerar os dispositivos
  stwio r0,(r17)
  stwio r0,(r18)
  stwio r0,(r20)
  stbio r0,0(r10)
  stbio r0,1(r10)
  stbio r0,2(r10)
  stbio r0,3(r10)

 
  movi r5,0xF
 
  stwio r5,12(r20) # ---> zerar o reg de borda
  
  
 POLLING:
  
  # Ler o conteúdo dos switches
  ldwio r19, (r17) # ---> acessando o reg de dados de chaves(switches) 


  ldwio r22,12(r20)
    
  #observar se o registrador de borda foi acionado
  bne   r22, r0, END_POLLING		
  
  
  br POLLING
  
  
 END_POLLING:
  add r16,r16,r19   #r16 = r16 + r19
  
  
  stwio r16, (r18) # ----> passar a soma acumulada para os LED's
  movi r23, 0b0010
  
  stwio r23, 12(r20)  # resetar reg de captura de borda
  


DISPLAY:
#-----------------------------------------------------------#
#PROCESSO DE PASSAR OS NUMEROS PARA O DISPLAY


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

  br POLLING	
  
  
  
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
  
  
  