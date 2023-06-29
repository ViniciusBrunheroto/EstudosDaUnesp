.global _start
_start:
	
.equ CHAVES, 0x10000040
.equ LEDV, 0x10000010
.equ PB, 0x10000050


.global _start
_start:
	
	
  mov r16, r0 		# r16 -> acumulador

  movia r17, CHAVES
  movia r18, LEDV
  movia r20, PB
  
  #zerar auxiliares
  mov r19,r0
  mov r22,r0 
  
  #zerar os dispositivos
  stwio r0,(r17)
  stwio r0,(r18)
  stwio r0,(r20)
 
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
  
  br POLLING