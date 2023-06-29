/*

1) Calcular sequencia de numeros triangulares.

   T(0) = 0, se N = 0
   T(N) = N + T(N-1), se N > 0
   
   ENTRADA: N   
    (vair estar no endereço 0x400)

   SAIDA: vetor com os N primeiros números triangulares (VT)
    (vair estar no endereço 0x404)


2) Escrever algoritmo

  VT[0] = 0
  
  for (i=1; i<=N; i++)
    VT[i] = i + VT[i-1]


3) Mapeamento de registrador

	N    => r8
	VT   => r9    (ponteiro para VT)
	i    => r10
	temp => r11
	

*/


.global _start
_start:
	
	# carrega valores em registradores
	movia r9, N		# inicializa r9 com o endereço de N
	ldw	  r8, (r9)  # r8 = N
	
	# seta o ponteiro para VT	
	movia  r9, VT	# add	  r9, r9, 4
	
	# VT[0] = 0
	stw    r0, (r9)
	addi   r9, r9, 4	# faz r9 apontar para proximo elemento a ser gerado
	
	
	# for (i=1; i<=N; i++)
	movi   r10, 1		# i=1
LACO:	
	# condicao
	# para sair do laco, i precisa ser maior que N (i>N)
	bgt  r10, r8, SAI_LACO
	
	# corpo
	#VT[i] = i + VT[i-1]
	# carregar VT[i-1]
	ldw  r11, -4(r9)
	add  r11, r10, r11 # r11 = i + VT[i-1]
	stw	 r11, (r9)
	addi r9, r9, 4  # incrementa para próximo elemento (i+1)
	
	addi	r10, r10, 1 # i++
	br  LACO
	
SAI_LACO:	
	
fim:
  br fim
  
  
#
# Secao de dados
#
  
.equ  TAM, 10    # #define TAM 5 

.org 0x400
N:
.word TAM		# int N = TAM;
VT:
.skip TAM*4     # int VT[TAM*4];

.end
	
	