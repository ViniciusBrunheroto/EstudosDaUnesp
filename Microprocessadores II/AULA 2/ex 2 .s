/*
 SUBROTINA
1) Calcular sequencia de numeros triangulares.

   F(0) = 0, se N = 0
   F(0) = 1, se N = 1
   F(N) =F(N-1)+F(N-2) , se N > 0
   
   ENTRADA: N   
    (passado como parâmetro pela sub-rotina no stack-frame)

   SAIDA: inteiro (32 bits) com o valor de T(N)  

2) pseudo-código (recursivo)

  if (N = 0) return 0
  else (N = 1) return 1
  else return F(N-1)+F(N-2)
  

3) uso de registradores 

  r8   -> N
  r2   -> retorno (pela ABI)
  r9   -> T(N-1)
 
4) Formato do stack-frame
  
        ARGUMENTOS DE ENTRADA (N -> 4 bytes)
        ---------------------	 
 sp ->   RA (endereço de retorno)
         r8 (N atual)
         r9(salvar conteúdo de r2) 
         N-1 ou N-2 (argumento da chamada)

*/





.equ TOPSTACK, 0x1000
.equ N, 3



.global _start
_start:

	movia sp, TOPSTACK		# inicializa pilha

 
   movi  r16, N
   
   
   addi  sp, sp, -4
   stw   r16, (sp)
   call  FIBONACCI
   
fim:
  br fim
  
FIBONACCI:
#Prólogo
  addi sp,sp,-16
  stw ra,12(sp)
  stw r8,8(sp)
  stw r9,4(sp)
  
  ldw r8,16(sp)
  
  #if (N=0) return O
  mov r2, r0
  beq r8,r0, FIM_FIBONACCI
  
  #if (N=1) return 1
  mov r2,r0
  addi r2,r2,1
  beq r8,r2,FIM_FIBONACCI
  
 #PROCESSO PARA CONSEGUIR OS VALORES DE (n-1)
  addi r8,r8,-1 # (N-1)
  stw r8,(sp)
  call FIBONACCI
   
   mov r9,r2 
   #r9 = Fib(N-1)
   
  
 #PROCESSO PARA CONSEGUIR OS VALORES DE (n-2)
   addi r8,r8,-1
   stw r8,(sp)
   call FIBONACCI 
  #r2= Fib(N-2)
  
  add r2,r9,r2 
  
  
  
FIM_FIBONACCI:
#EPÍLOGO

ldw ra,12(sp)
ldw r8,8(sp)
ldw r9,4(sp)
addi sp,sp,16

ret








