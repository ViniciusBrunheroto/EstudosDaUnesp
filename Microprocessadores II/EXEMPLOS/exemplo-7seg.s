
.equ D7SEG, 0x10000020

.global _start
_start:

  movia r8, D7SEG
  
 # movi  r9, 0b100000001
  
  
  # quero imprimir #1
  movi  r9, 0
  movi  r10, TABELA
  add   r10, r10, r9
  ldb   r11, (r10)   # TABELA[1]
  
  slli  r12, r11, 16
  or    r12, r12, r11 
  
  stwio  r12, (r8)
  

  
  
  
.org 0x300

TABELA:
  .byte  0b0111111     #0x3F    # 0
  .byte  0b0000110     # 1
  .byte                # 2
  .byte                # ...
  .byte                # F

  
	
	