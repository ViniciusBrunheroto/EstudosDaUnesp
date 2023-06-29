
/*
  
   Sequência de passos:
   
   1) Ler conteúdo das switches(alavancas)
   2) Adicionar o número à soma acumulada
   3) Mostrar SOMA nos LED's.
   


LOOP:    // POLLING
   Le o estado dos switches -> paralelo (número em binário)
   
    cont= (switch)
   
    soma = soma + cont
	
	acender os led's correspondentes ao numero da soma

 volto para o começo do LOOP

*/



.equ CHAVES, 0x10000040
.equ LEDV, 0x10000010


.global _start
_start:
	
	
  mov r16, r0 		# r16 -> acumulador

  movia r17, CHAVES
  movia r18, LEDV
  
  mov r19,r0
  
  #zerar os dispositivos
  stwio r0,(r17)
  stwio r0,(r18)
  
  
 LACO:
  
  # Ler o conteúdo dos switches
  ldwio r19, (r17) # ---> acessando o reg de dados de chaves(switches) 
  add r16,r16,r19   #r16 = r16 + r19
  stwio r16, (r18) # ----> passar a soma acumulada para os LED's	
  
  br LACO
  
 