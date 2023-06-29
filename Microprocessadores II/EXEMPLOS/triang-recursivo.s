/*



*/

.equ TOPSTACK, 0x3000
.equ N, 7   # T(7) = 28
#.equ N, 1   # T(1) = 1

.global _start
_start:

   movia sp, TOPSTACK		# inicializa pilha

 
   movi  r16, N
   
   
   addi  sp, sp, -4
   stw   r16, (sp)
   call  TRIANG


fim: 
  br fim
  
  
/*
 SUBROTINA
1) Calcular sequencia de numeros triangulares.

   T(0) = 0, se N = 0
   T(N) = N + T(N-1), se N > 0
   
   ENTRADA: N   
    (passado como parâmetro pela sub-rotina no stack-frame)

   SAIDA: inteiro (32 bits) com o valor de T(N)  

2) pseudo-código (recursivo)

  if (N = 0) return 0
  else return N + T(N-1)
  

3) uso de registradores 

  r8   -> N
  r2   -> retorno (pela ABI)
  r9   -> T(N-1)
 
4) Formato do stack-frame
  
        ARGUMENTOS DE ENTRADA (N -> 4 bytes)
        ---------------------	 
 sp ->   RA (endereço de retorno)
         R8 (N atual) 
         N-1 (argumento da chamada)
*/
TRIANG:    # sou recursivo -> tanto CALLER quanto CALLEE 
# PROLOGO
	addi  sp, sp, -12  # 3 entradas no stack-frame
	stw   ra, 8(sp)
	stw   r8, 4(sp)

	ldw	  r8, 12(sp)	# carregar N (passado como parâmetro)

#  if (N = 0) return 0
	mov  r2, r0			# retorno 0
	beq  r8, r0, FIM_TRIANG

#  else return N + T(N-1)

    ## salvar N-1 no stack-frame
	addi  r9, r8, -1     # r9 = N-1
	stw   r9, (sp)
	call  TRIANG
    # r2 = T(N-1)
    add   r2, r8, r2


FIM_TRIANG:
# EPILOGO
	ldw   ra, 8(sp)
	ldw   r8, 4(sp)
	addi  sp, sp, 12  # 3 entradas no stack-frame
  ret
	
	