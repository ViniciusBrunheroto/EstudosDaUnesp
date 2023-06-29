/*
   Quero manter 1o LED verde setado, se botao1 for mantido pressionado
   Quero manter 1o LED vermelho setado, se botao2 for mantido pressionado
  
   Caso contrário, o respectivo botão é resetado.


DO:    // POLLING

   Se botao1 !pressionado: reseta LEDV 1
   Se botao2 !pressionado: reseta LEDR 1

   Le o estado dos botões -> paralelo 
WHILE(botao1 !pressionado AND botao2 !pressionado)
	
 se botao1 == pressionado: 
 	seto LEDV
 se botao2 == pressionado: 
 	seto LEDR

 volto para o começo

*/

.equ CHAVES, 0x10000040
.equ LEDV, 0x10000010
.equ LEDR, 0x10000000
.equ PB, 0x10000050

.global _start
_start:


  mov r10, r0 		# r10 -> acumulador

  movia r8, PB
  movia r9, LEDV
  movia r12, LEDR
  
  stwio r0, (r9)
  stwio r0, (r12)

DO:

  ldwio r10, 0(r8)	    # r10 -> estado dos botões (PB3, PB2, PB1, PB0)


# VERIFICA SE PRECISA APAGAR OS LEDS
  andi  r11, r10, 0b0010  # 2
  bne   r11, r0, NAO_APAGO_LEDV 
  
  stwio r0, (r9)
  
NAO_APAGO_LEDV:
  andi  r11, r10, 0b0100  # 4
  bne   r11, r0, NAO_APAGO_LEDR 
  
  stwio r0, (r12)
  
NAO_APAGO_LEDR:


# CONDICOES PARA SAIR DO POLLING

  # testar se o botão 1 está pressionado
  andi  r11, r10, 0b0010  # 2
  bne   r11, r0, END_DO			# se botao1 pressionado, saio do WHILE
 ## bne   r11, r0, TESTA_LEDR			# se botao1 pressionado, saio do WHILE

TESTA_LEDR:
  # testar se o botão 1 está pressionado
  andi  r11, r10, 0b0100  # 4
  bne   r11, r0, END_DO         # se botao2 pressionado, saio do WHILE

  #
  br DO

END_DO:

  movi  r13, 1

  # r10 -> estado dos botões
  andi  r11, r10, 0b0010  # 2
  beq   r11, r0, NAO_ACENDE_VERDE

  stwio r13, (r9)

NAO_ACENDE_VERDE:
  andi  r11, r10, 0b0100  # 2
  beq   r11, r0, NAO_ACENDE_VERMELHO

  stwio r11, (r12)

NAO_ACENDE_VERMELHO:
  
  br DO


.end



	
	
	
	