
.equ UART, 0x10001000

.global _start
_start:
	
	movia r9, UART
	
	
/*Nesse caso específico, não há necessidade de um polling para escrita
nem fazer checagem do WSPACE, pois 
o escrever está condicionado à digitação de algum caracter.
*/
POLLING_LEITURA:	

  ldwio r11, (r9)
  andi  r12, r11, 0x8000  # separar campo RVALID
  beq   r12, r0, POLLING_LEITURA
  
  # 8 primeiros bits de r11 tem o caracter lido 
  
  andi  r11, r11, 0xFF   # separar campo DATA
  
  # mostrar o caractere no terminal
  stwio r11, (r9) 
  
  
  br POLLING_LEITURA
  
  
  
 FIM: 
  br FIM