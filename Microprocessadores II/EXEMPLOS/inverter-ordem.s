/*

1) instruções lógicas
 and/or/xor/nor
 
   - NOR -        - XOR -
    A B  X        A  B  X
    0 0  1        0  0  0 
    0 1  0        0  1  1
	1 0  0        1  0  1
	1 1  0        1  1  0
 
 not r1 -> não existe
 
 nor r1, r1, r1  -> inverte conteúdo de r1
 
 portas lógicas universais - nor/nand


2) instruções de deslocamento/rotação

 shifts  -> esquerda/direita            b3b2b1b0      >>    1 (srli)   -->     0b3b2b1 
 rotação -> esquerda/direita            b3b2b1b0   rot-dir  1 (ror)    -->     b0b3b2b1
 
 deslocamentos
   lógicos        - "default"
   aritméticos    -
 
  Exemplo 
   (lógicas)
         0b0100 (4)  ->  slli 1   =>  0b1000  (8) 
         0b0100 (4)  ->  srli 1   =>  0b0010  (2)
 
   (aritmética)
         0b1110 (-2) -> srli  1   =>  0b0111  (7)
		 0b1110 (-2) -> srai  1   =>  0b1111  (-1)
		 
		 0b0100 (+4) -> srai  1   =>  0b0010  (+2)		 
		 0b1110 (-2) -> slli  1   =>  0b1100  (-4)
		 

1) Problema:
          inverter a ordem dos bits da entrada
		  
	Entrada -> número de 32 bits (registrador)
	Saída   -> a ordem dos bits invertidas
	
	Ex:
	Entrada -> b3b2b1b0   -  1101   (13)  (0xD)
	Saida   -> b0b1b2b3   -  1011   (11)  (0xB)
		 

2) Pseudo-código

   Ideia: 
     1) olhar cada bit, da direita para esquerda
     2) para cada bit, se estiver setado (1) -> seto o respectivo bit espelhado

   Pseudo-código:
   
   Entrada - entrada
   Saida   - saida =
		 
   saida = 0
   for (i=0; i<=31; i++) {
   
     estado = entrada & (0x1 << i)
	 
	 if (estado != 0)
	   saida  = saida | [0x1 << (31-i)]
   }
   
   entrada = 0b1101
   
   saida = 0
   iteração i=0
       estado = 0b1101 & 1 => 1
	   saida  =  0 | 1000  => 0b1000

   iteração i=1
       estado = 0b1101 & 0b10  => 0
	   
   iteração i=2
       estado = 0b1101 & 0b100  => 1
	   saida  = 0b1000 | 0x1 << (3-2) -> 0x1 << 1 -> 0x0010  =>
	            0b1000 |
				0b0010 
	   saida  = 0b1010
	 
   iteração i=3
	   estado = 0b1101 & 0b1000 => 1
	   saida  = 0b1010 | 0b1    => 0b1011
	   
	   
3) Mapeamento para registradores
  
   r4 -> entrada
   r2 -> saida
   
   r8  -> i
   r9  -> estado
   r10 -> 31	   
   r11, r12 -> temporários
		 
*/

.equ STACK, 0x1000
#.equ ENTRADA, 0x0000FFFF  # invertido -> 0xFFFF0000
.equ ENTRADA, 0x12345678   # invertido ->
 # 0001 0010 0011 0100 0101 0110 0111 1000
 # 0001 1110 0110 1010 0010 1100 0100 1000  -> 0x1E6A2C48

.global _start
_start:

   movia sp, STACK
   
   movia r4, ENTRADA
   
   call  INVERT_ORDEM

FIM:
  br FIM
 
 
 
INVERT_ORDEM:
# PROLOGO
  addi sp, sp, -4
  stw  fp, (sp)
  mov  fp, sp

 

  mov  r2, r0     #  saida = 0
  movi r10, 31    #  r10 = 31
  
  mov  r8, r0	  #  i = 0
LACO:
 #  for (i=0; i<=31; i++) {
  bgt  r8, r10, FIM_INVERT_ORDEM 
  
 #    estado = entrada & (0x1 << i)
  movi r12, 1
  sll  r11, r12, r8  	# (0x1 << i)
  and  r9, r4, r11      # estado = entrada & (0x1 << i)
	 
 #	 if (estado != 0) 
  beq r9, r0, NAO_FAZ_ATRIBUICAO
  
 #	   saida  = saida | [0x1 << (31-i)]  
  sub  r11, r10, r8		# r11 = (31-i)
  movi r12, 1
  sll  r11, r12, r11    # r11 = [0x1 << (31-i)]
  or   r2, r2, r11      # saida | [0x1 << (31-i)]
   
 
NAO_FAZ_ATRIBUICAO: 
 
   addi r8, r8, 1	# i++
  br LACO
 
 
 #  }



FIM_INVERT_ORDEM:
# EPILOGO
  ldw  fp, (sp)
  addi sp, sp, 4
  ret
  
  
	
	