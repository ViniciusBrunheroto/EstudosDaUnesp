



/*

1) Problema:
          Determinar número máximo de 1s consecutivos em uma palavra de 32 bits.
		  
	Entrada -> número de 32 bits (registrador)
	Saída   -> o número de 1s consecutivos
	

2) Pseudo-código

   Ideia: 
     1) olhar cada bit, da direita para esquerda
     2) para cada bit, se estiver setado (1) incrementa o contador
	 3) se o proximo bit não estiver setado compara se o valor do contador
	 é maior que o valor colocado em máximo
	 4)  Se o valor do contador for maior, significa que foi achado
	 uma sequência maior de 1s, então maximo recebe o valor do contador
	 e contador é zerado
	 5) Se o valor do contador for menos, significa que foi achado uma
	 sequência menor de 1s, então ignora-se o valor do contador que é
	 zerado em seguida.

   Pseudo-código:
   
   Entrada - entrada
 
   Máximo=0;	
   cont=0;
   for (i=0; i<=31; i++) {
   
     estado = entrada & (0x1 << i)
	 
	 if (estado != 0)
	   cont++;
	 
	 else
	   {
	     
		 if ( cont > maximo)
		 {
	         maximo = cont;
		 }
		  cont = 0;
	
	   }
   }
   
   
3) Mapeamento para registradores
  
   r4 -> entrada
   r2 -> maximo
   
   r8  -> i
   r9  -> estado
   r10 -> 31	   
   r11, r12 -> temporários
   r13 -> contador

*/


.equ STACK, 0x1000
.equ ENTRADA, 0b11111111111111111111111111111111


.global _start
_start:
	
   movia sp, STACK
   
   movia r4, ENTRADA
   
   call  CONTA_1

FIM:
  br FIM
	


CONTA_1:
 
  movi r10, 31    #  r10 = 31
  
  mov r13,r0
  mov r8,r0

  # for (i=0; i<=31; i++) {
 LACO: 
  bgt r8,r10,FIM_CONTA_1
  
  
  # estado = entrada & (0x1 << i)
  movi r12,1
  sll r11,r12,r8
  and r9,r4,r11  # estado = entrada & (0x1 << i)
  
   # --->R9 != 0?
  
  bne r9, r0, TEM_1  
  	
	# --->R9 = 0
	
	# 1) CONT > MAX?
  bgtu r13,r2,ADICIONA_MAXIMO
  
    # 2) CONT < MAX
  mov r13,r0 # cont =0	, zera a contagem de 1s que vieram anteriormente
  addi r8,r8,1 #i++
  br LACO
  
  
  # R9 != 0
 TEM_1:
   #cont++;
   addi r13,r13,1 #cont++
   
   addi r8,r8,1 #i++
   br LACO
   
   
   
 # R9 = 0 E CONT > MAX
ADICIONA_MAXIMO:
	 mov r2,r13 # Máximo = cont
	 mov r13,r0 # cont =0	
	 addi r8,r8,1 #i++
     br LACO
  
  
 FIM_CONTA_1:
 
   movi r14,32
   beq r13,r14,TODOS_1
   ret
 
 
 # Situação em que todos os bit são iguais a 1
 TODOS_1:
   movi r2,32
   ret
  

	
	