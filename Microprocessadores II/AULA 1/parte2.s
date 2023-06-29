/*

1)Calcular série de fibonacci
F(O)=0, se N=0
F(1)=1, se N=1
F(N)= F(N - 1) + F(N - 2), se N>1

ENTRADA: N
(no endereço 0xffc)

SAÍDA: vetor com N primeiros números da série de fibonacci
(no endereço 0x1000)

2) Escrever algoritmo

F[0]=0
F[1]=1

for (i=2; i<N; i++)
    F[i] = F[i-1] + F[i-2]
	
	
3) Mapeamento de registrador

	N    => r8
	F   => r9    (ponteiro para F)
	i    => r10
	aux => r11
	fib1 => r12
	fib2 => r13
	
*/

.global _start
_start:

# Seção de código

  movia r11,N     #r11 recebe endereço de N
  ldw r8,(r11)    #r8 = N

  movia r9,F     #r9 = F
  
  #F[0]=0
  stw r0,(r9)
  addi r9,r9,4
 
  
  #F[1]=1
  # será necessário usar um reg auxiliar
  add r11,r0,r0 # zerar r11
  addi r11,r11,1 # r11 = 1
  stw r11,(r9)
  addi r9,r9,4
  
  # for (i=2; i<N; i++)
  movi r10,2 #i=2
  
  LACO:
  	# para sair do laco, i precisa ser maior ou igual que N (i>=N)
	bge r10,r8,SAI_LACO

	# corpo
	# F[i] = F[i-1] + F[i-2]
	# carregar F[i-1] e F[i-2]
	ldw r12,-4(r9) # r12= F[i-1]
	ldw r13,-8(r9) # r13 = F[i-2]
	add r12, r12, r13 # r12 = F[i-1] + F[i-2]
	stw r12,(r9)

	addi r9, r9, 4  # incrementa para próximo elemento (i+1)
	
   	addi r10, r10, 1 # i++
    br LACO


SAI_LACO:

fim:
 br fim




# Seção de dados

.equ  TAM, 8    #define TAM 4

.org 0xffc
N:
.word TAM     #int N= TAM


.org 0x1000
F:
.skip TAM*4     # int F[TAM*4];

.end












	