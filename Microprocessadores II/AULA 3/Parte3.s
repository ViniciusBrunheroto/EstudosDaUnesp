


/* 

1) Problema:
          Determinar número máximo de 1's e 0's alternantes em uma palavra de 32 bits.
		  
	Entrada -> número de 32 bits (registrador)
	Saída   -> o número que representa a máxima sequência de 1's e 0's consecutivos
	

2) Pseudo-código

   Ideia: 
     1) olhar cada bit, da direita para esquerda
     2) para cada bit, se estiver setado (1) incrementa o contador
	 3) se o proximo bit não estiver setado compara se o valor do contador
	 é maior que o valor colocado em máximo
	 4)  Se o valor do contador for maior, significa que foi achado
	 uma sequência maior de 1s, então maximo recebe o valor do contador
	 e contador é zerado
	 5) Se o valor do contador for menor, significa que foi achado uma
	 sequência menor de 1s, então ignora-se o valor do contador que é
	 zerado em seguida.
	 6)Guardar o valor que representa a maior sequência de 1's em um registrador
	 ***Repetir do (1) ao (6) mas agora para contar a quantidade de 0's****
	 7) para cada bit, se estiver setado (0) incrementa o contador
	 8) se o proximo bit estiver setado(em 1) compara se o valor do contador
	 é maior que o valor colocado em máximo
	 9) Se o valor do contador for menor, significa que foi achado uma
	 sequência menor de 0s, então ignora-se o valor do contador que é
	 zerado em seguida.
	 10)Guardar o valor que representa a maior sequência de 0's em um registrador
	 11)Comparar os valores dos dois registradores
	 12) O maior valor representa a maior sequência de 0's e 1's alternantes, que 
	 deverá ser guardado no r16
	 

   Pseudo-código:
   
   Entrada - entrada
 
   Máximo1=0;	
   cont=0;
   for (i=0; i<=31; i++) {
   
     estado = entrada & (0x1 << i)
	 
	 if (estado != 0)
	   cont++;
	 
	 else
	   {
	     
		 if ( cont > maximo)
		 {
	         maximo1 = cont;
		 }
		  cont = 0;
	
	   }
	
	Maximo2=0;
	cont=0;
	for (i=0; i<=31; i++) {
   
     estado = entrada & (0x1 << i)
	 
	 if (estado == 0)
	   cont++;
	 
	 else
	   {
	     
		 if ( cont > maximo)
		 {
	         maximo2 = cont;
		 }
		  cont = 0;
	
	   } 
	   
   } ---> FIM DO FOR
   
   
    if (maximo1 >= maximo2)
	   reg = maximo1
	   
	   else
	       reg = maximo2
   
*/



.equ STACK, 0x1000
#.equ NUM, 0b011011

.equ NUM,0b101101010001


.global _start
_start:
	
	movia sp, STACK
	movia r10,NUM
	movia r17,0b01010101010101010101010101010101 #---> máscara
	
	 #usando a máscara
	 xor r4, r10, r17
	 
	 
	 
	 
  call SUB1	 

   #R5 contém a maior sequência de 1s

  call SUB2	
  
  #R6 contém a maior sequência de 0s
  
  bgeu r5,r6,MAIOR_1
  mov r16,r6


FIM1:
	br FIM1
	
	
MAIOR_1:
  mov r16,r5
 
FIM2:
	br FIM2



# ----------------------------------------------------------------------
	
SUB1:

# PROLOGO
  addi sp, sp, -4
  stw  r10, (sp)
  
  movi r10, 31 
  mov r8,r0
  
  
  # for (i=0; i<=31; i++) { 
  LACO1: 
  bgt r8,r10,FIM_SUB1
  
  # estado = entrada & (0x1 << i)
  movi r12,1
  sll r11,r12,r8
  and r9,r4,r11  # estado = entrada & (0x1 << i)
 
    # --->R9 != 0?
  
  bne r9, r0, TEM_1  
  	
	# --->R9 = 0
	
	# 1) CONT > MAX?
  bgtu r13,r2,ADICIONA_MAXIMO1
  
    # 2) CONT < MAX
  mov r13,r0 # cont =0	, zera a contagem de 1s que vieram anteriormente
  addi r8,r8,1 #i++
  br LACO1
  
  
  # R9 != 0
 TEM_1:
   #cont++;
   addi r13,r13,1 #cont++
   
   addi r8,r8,1 #i++
   br LACO1
   
   
   
 # R9 = 0 E CONT > MAX
ADICIONA_MAXIMO1:
	 mov r2,r13 # Máximo = cont
	 mov r13,r0 # cont =0	
	 addi r8,r8,1 #i++
     br LACO1
  
  
FIM_SUB1:

   # EPILOGO
   ldw  r10, (sp)
   addi sp, sp, 4
   
   movi r14,32
   beq r13,r14,TODOS_1
   mov r5,r2
   ret
 
 
 # Situação em que todos os bit são iguais a 1
 TODOS_1:
   movi r5,32
   ret
   
   
   
   
   
# ---------------------------------------------------------------------
   
   
SUB2:   
 # PROLOGO
  addi sp, sp, -4
  stw  r10, (sp)
  
  
  #------------------- ***** --------------------------
  #RETIRAR LIXO DE MEMÓRIA QUE SOBROU DAS SUBROTINAS
  
  mov r2,r0
  mov r8,r0
  mov r9,r0
  mov r10,r0
  mov r11,r0
  mov r12,r0
  mov r13,r0
  mov r14,r0
  # ------------------ ***** -----------------------------
  movi r10, 31 

  

 # for (i=0; i<=31; i++) { 
  LACO2: 
  bgt r8,r10,FIM_SUB2 
  # estado = entrada & (0x1 << i)
  movi r12,1
  sll r11,r12,r8
  and r9,r4,r11  # estado = entrada & (0x1 << i)
  
  
    # --->R9 != 0?
  
  beq r9, r0, TEM_0
  	
	# --->R9 = 1

  # 1) CONT > MAX?
  bgtu r13,r2,ADICIONA_MAXIMO2
  
    # 2) CONT < MAX
  mov r13,r0 # cont =0	, zera a contagem de 0s que vieram anteriormente
  addi r8,r8,1 #i++
  br LACO2


  # R9 = 0
 TEM_0:
   #cont++;
   addi r13,r13,1 #cont++
   
   addi r8,r8,1 #i++
   br LACO2
   
   
 # R9 = 1 E CONT > MAX
ADICIONA_MAXIMO2:
	 mov r2,r13 # Máximo = cont
	 mov r13,r0 # cont =0	
	 addi r8,r8,1 #i++
     br LACO2
	 
	 
	 
FIM_SUB2:
   # EPILOGO
   ldw  r10, (sp)
   addi sp, sp, 4
   
   movi r14,32
   beq r13,r14,TODOS_0
   mov r6,r2
   ret
 
 
 # Situação em que todos os bit são iguais a 0
 TODOS_0:
   movi r6,32
   ret
      
   	 