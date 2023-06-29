
/*
*************COMENTÁRIOS INICIAIS*********************
Nome do programa: Trabalho de Microprocessadores II
Autor: Vinícius do Amaral Brunheroto
Objetivo: Implementar todos os comandos que foram solicitados,
estes que envolvem o conteúdo que foi aprendido durante todo
o semestre do curso, desde operações com bits,construção de sub-rotinas
e pilhas, manipulação de dispositivos I/O de comunicação paralela, 
fazer comunicação serial, comunicações com a JTAG UART, 
utilização do temporizador, utilização do VGA pixel buffer 
para plotar gráficos.
E claro, implementar tudo isso dentro do escopo da linguagem do
Nios II e possível por meio do simulador online do Nios II
Estruturação do código
O código pode ser dividido em 3 partes principais
1ª INÍCIO:
RTI e subrotinas que tratam interrupção
2ª MEIO:
PARTE I) Implementação de instruções com LED's VERDES.
PARTE II)Implementação de instruções com VGA pixel buffer
PARTE III)Implementação de instruções com contador
3ª FIM:
Onde o MAIN se localiza junto dos labels que chamam as subrotinas
do MEIO.
É aqui que se localiza o final do programa e a área de declaração 
de dados que foram usados durante o programa
	
O código foi revisto e bugs encontrados foram tratados,
porém ainda podem existir bugs.
	
	
OBSERVAÇÃO: SE VOCÊ EXECUTAR ESSE CÓDIGO NO SIMULADOR NIOS II
DE FORMA CONTÍNUA POR FAVOR, DESATIVE DEVICE-SPECIFIC WARNINGS.
	
	
*/	
	
	

	
	
#Área para definir endereços de dispositivos I/O que serão usados
#no programa
.equ D7SEG, 0x10000020
.equ D7SEG_2,0x10000030
.equ UART, 0x10001000
.equ TIMER, 0x10002000
.equ LEDV, 0x10000010
.equ SW, 0x10000040
.equ MEMVIDEO, 0x08000000
.equ LEDR, 0x10000000
.equ PB, 0x10000050
 

#------------------------RTI: INTERRUPÇÕES---------------------------
#A RTI tratará as interrupções encaminhando para subrotinas
# dependendo do dispositivo que gerou a interrupção
.org 0x20
RTI:
  addi sp, sp, -8
  stw  ra, 4(sp)
  stw  r16, (sp)
  

# quem gerou a exceção: foi SW ou HW?
   rdctl  et, ipending
   beq    et, r0, NOT_HW

   addi   ea, ea, -4


# como que eu sei quem gerou a interrupção?
   andi   r16, et, 0b10         # -> PB
   beq    r16, r0, NOT_PB

    call TRATA_PB

br NOT_TIMER

NOT_PB:
# checar se foi o TIMER
   andi   r16, et, 0b01          # -> TIMER (IRQ0)
   beq    r16, r0, NOT_TIMER

   call   TRATA_TIMER



NOT_TIMER:

NOT_HW:


FIM_RTI:

  ldw r16,(sp)
  ldw ra ,4(sp)
  addi sp, sp, 8

  eret  # volta para o endereço salvo em r29 (ea)

# ----------------PUSH - BUTTON ---------------------------------

#--------------------------------------------------------------------
#Subrotinas que tratam possíveis bugs que possam ser causadas pelo 
#PUSH-BUTTON

BUG:
# precisa resetar os dois botões

   movi r8,0b0110
   stwio r8, 12(r20)
   
br FIM_PB   


BUG2:


   movi r8,0b0001
   stwio r8, 12(r20)
   
br FIM_PB   

BUG3:


   movi r8,0b1000
   stwio r8, 12(r20)
   
br FIM_PB   


BUG4:

   movi r8,0b1001
   stwio r8, 12(r20)
   
br FIM_PB   

#--------------------------------------------------------------------

#Subrotinas que auxilia no tratamento da interrupção por push-button
#CASO: PAUSAR CONTADOR
TEMP0:
#  pausa o contador
   movia r18,CHAVE_t
   movia r17,0b1
   stb r17,(r18)
   
   movi r14, 0b0010
  
   stwio r14, 12(r20)  # resetar reg de captura de borda
 
   
br FIM_PB



#Subrotina para tratar PUSH-BUTTON
TRATA_PB:
#PRÓLOGO
  addi sp, sp, -32
  stw  r8,  28(sp)
  stw  r11, 24(sp)
  stw  r13, 20(sp)
  stw  r14, 16(sp)
  stw  r15, 12(sp)
  stw  r17,  8(sp)
  stw  r18,  4(sp)
  stw  r20 , (sp)
  
  
   #qual botão foi pressionado? 1 ou 2?
  movia r20, PB
  ldwio r15,12(r20)
  
   movi r13,0b1001
  
   # usuário o apertou 1 e 2? = situação de BUG
   andi r11,r15,0b0110
   beq r11,r13,BUG
   
    mov r11,r0
	movi r13,0b0001
  # usuário o apertou 0? = situação de BUG
   andi r11,r15,0b0001
   beq r11,r13,BUG2
   
    mov r11,r0
	movi r13,0b1000
   # usuário o apertou 3? = situação de BUG
   andi r11,r15,0b1000
   beq r11,r13,BUG3
  
   mov r11,r0
   movi r13,0b1001
   # usuário o apertou 0 e 3? = situação de BUG
   andi r11,r15,0b1001
   beq r11,r13,BUG4
  
   mov r11,r0
   movi r13,10
 
  # usuário apertou o botão 1 = 
   andi r11,r15,0b0010
   beq r11,r15,TEMP0
  
  # usuário apertou o botão 2 = 
   movia r17,CHAVE_t
   stb  r0,(r17)
   
   
   movi r14, 0b0100
  
   stwio r14, 12(r20)  # resetar reg de captura de borda
   
   
FIM_PB:
#EPÍLOGO
  ldw  r8,  28(sp)
  ldw  r11, 24(sp)
  ldw  r13, 20(sp)
  ldw  r14, 16(sp)
  ldw  r15, 12(sp)
  ldw  r17,  8(sp)
  ldw  r18,  4(sp)
  ldw  r20 , (sp)
  addi sp, sp, 32
  

 ret

# ----------------FIM DO TRATAMENTO AO PUSH - BUTTON ---------------------------------




# ----------------INÍCIO DO TRATAMENTO AO TEMPORIZADOR ---------------------------------

/* 1- Subrotina usada para alterar os valores que serão
colocados nos displays de 7seg quando 9 segundos se passaram 
  **09   ----> **10
*/
ZERAR_S:

  movia r9,D7SEG 

#1 DIGITO 
    movia r8,V1_S
    mov r14,r0
    stb r14,(r8)
	movia r8,V1_S
	ldb r10,(r8)
	
	movia r12,TABELA
    add r12,r12,r10
    ldb r13,(r12)
    stbio r13,0(r9)
	
#2 DIGITO 
    movia r8,V2_S
	ldb r14,(r8)
	addi r14,r14,1
	stb r14,(r8)
	movia r8,V2_S
	ldb r10,(r8)
	
	movi r12,TABELA
    add r12,r12,r10
    ldb r13,(r12)
    stbio r13,1(r9)
	
#3 DIGITO 	
	movia r8,V3_S
    ldb r10,(r8)


	movi r12,TABELA
    add r12,r12,r10
    ldb r13,(r12)
    stbio r13,2(r9)
	
#4 DIGITO    
    movia r8,V4_S
    ldb r10,(r8)
	
	movi r12,TABELA
    add r12,r12,r10
    ldb r13,(r12)
    stbio r13,3(r9)

	
br FIM_CONT

/* 2- Subrotina usada para alterar os valores que serão
colocados nos displays de 7seg quando já contou 9 minutos
 09:**   ----> 10:**   */
ZERAR_M:

  movia r9,D7SEG 
  
  
#1 DIGITO 
    movia r8,V1_S
	ldb r10,(r8)
	
 	movia r12,TABELA
    add r12,r12,r10
    ldb r13,(r12)
    stbio r13,0(r9)
	
 #2 DIGITO   
    movia r8,V2_S
    ldb r10,(r8)
	
	movia r12,TABELA
    add r12,r12,r10
    ldb r13,(r12)
    stbio r13,1(r9)
	
#3 DIGITO 
    movia r8,V3_S
    mov r14,r0
	stb r14,(r8)
	movia r8,V3_S
	ldb r10,(r8)
	
	movia r12,TABELA
    add r12,r12,r10
    ldb r13,(r12)
    stbio r13,2(r9)
	
	
#4 DIGITO 	
	movia r8,V4_S
	ldb r14,(r8)
	
	# -- se o 4 digito for 5 vai pra  MIN_60
	movia r15,0b0101
	
	beq r14,r15,MIN_60
	
	addi r14,r14,1
	stb r14,(r8)
	
	movia r8,V4_S
	ldb r10,(r8)
	
	
	movia r12,TABELA
    add r12,r12,r10
    ldb r13,(r12)
    stbio r13,3(r9)
	
	
br FIM_CONT


/* 3- Subrotina usada para alterar os valores que serão
colocados nos displays de 7seg quando 60 segundos se passaram 
  *0:59   ----> *1:00
*/

MIN_1:

  movia r9,D7SEG 

#1 DIGITO 
    movia r8,V1_S
    mov r14,r0
	stb r14,(r8)
	movia r8,V1_S
	ldb r10,(r8)
	
	
    movia r12,TABELA
    add r12,r12,r10
    ldb r13,(r12)
    stbio r13,0(r9)
	
#2 DIGITO 	
	movia r8,V2_S
    mov r14,r0
	stb r14,(r8)
	movia r8,V2_S
	ldb r10,(r8)
	
	movia r12,TABELA
    add r12,r12,r10
    ldb r13,(r12)
    stbio r13,1(r9)
	
	
	
#3 DIGITO 		
    movia r8,V3_S
    ldb r14,(r8)


	# -- se o 3 digito for 9 vai pra zerar_M
	movia r15,0b1001
	
	beq r14,r15,ZERAR_M
	
	
	addi r14,r14,1
	stb r14,(r8)
   
    movia r8,V3_S
	ldb r10,(r8)
	
	
	movia r12,TABELA
    add r12,r12,r10
    ldb r13,(r12)
    stbio r13,2(r9)
   
   
#4 DIGITO 	   
   
    movia r8,V4_S
    ldb r10,(r8)
  
	movia r12,TABELA
    add r12,r12,r10
    ldb r13,(r12)
    stbio r13,3(r9)
  br FIM_CONT
  
  
/* 4- Subrotina usada para alterar os valores que serão
colocados nos displays de 7seg quando 60 minutos se passaram 
  59:59   ----> 00:00
*/  
  
MIN_60:

  movia r9,D7SEG 

#DIGITO 1
    movia r8,V1_S
    mov r14,r0
	stb r14,(r8)
	movia r8,V1_S
	ldb r10,(r8)
	
	movia r12,TABELA
    add r12,r12,r10
    ldb r13,(r12)
    stbio r13,0(r9)
	
#DIGITO 2	
	movia r8,V2_S
    mov r14,r0
	stb r14,(r8)
	
	movia r8,V2_S
	ldb r10,(r8)
	
	movia r12,TABELA
    add r12,r12,r10
    ldb r13,(r12)
    stbio r13,1(r9)
	
	
	
#DIGITO 3	
	movia r8,V3_S
    mov r14,r0
	stb r14,(r8)
	
	
	movia r8,V3_S
	ldb r10,(r8)
	
	movia r12,TABELA
    add r12,r12,r10
    ldb r13,(r12)
    stbio r13,2(r9)
	
	
#DIGITO 4	
	movia r8,V4_S
    mov r14,r0
	stb r14,(r8)
	
	movia r8,V4_S
	ldb r10,(r8)
	
	movia r12,TABELA
    add r12,r12,r10
    ldb r13,(r12)
    stbio r13,3(r9)
	
	
	
br FIM_CONT


#5 - Subrotina que analisa se já deu 60 segundos
#Ela só é executada quando V2 é 5 (está perto de dar 1 min)
#Analisa se V1 é 9
#Obs: Disposição dos displays V8 V7 V6 V5  V4 V3 V2 V1 (esq p/ dir)
MIN_t:
    movia r8,V1_S
    ldb r10,(r8)
	
	movia r11,0b1010

    beq r10,r11,MIN_1

br fim_MIN_T

    
#6 - Subrotina que administra a sequência de contagem do contador
# e é ativada a cada 1s
pm_Cont:
   
  movia r9,D7SEG 
     
   #Deu 1s 
 # 2 ---> 1    
    movia r10, COUNTER
	ldb r11,(r10)
	
    mov r11,r0
    stb r11,(r10)
   
   
   mov r10,r0
   mov r11,r0
   
   
   
  # implementar o evento
  
    
 #------> SEGUNDOS
 
#e deu 60 s
   movia r8,V2_S
   ldb r10,(r8)
 
   movi r14,0b0101 #5
   beq r10,r14,MIN_t
 
fim_MIN_T:
 #1º Dígito
    movia r8,V1_S
    ldb r10,(r8)
   
    movi r14,0b1010
    beq r10,r14,ZERAR_S
 
 
   movia r12,TABELA

   add r12,r12,r10
   
   ldb r13,(r12)
   
   stbio r13,0(r9)
   
   #incrementar 
   addi r10,r10,1
   stb r10,(r8)
      
   mov r8,r0
   mov r10,r0   
 #2º Dígito   
    movia r8,V2_S
    ldb r10,(r8)
	
	movia r12,TABELA

    add r12,r12,r10
   
    ldb r13,(r12)
   
    stbio r13,1(r9)
		
	
 

   movia r8,V4_S
   ldb r10,(r8)
   
   movi r14,0b1010
   
   beq r10,r14,ZERAR_M  
   
   mov r8,r0
   mov r10,r0
   
#3º Dígito   
    movia r8,V3_S
    ldb r10,(r8)
	
	movia r12,TABELA

    add r12,r12,r10
   
    ldb r13,(r12)
   
    stbio r13,2(r9)
   
   
  #4º Dígito   
    movia r8,V4_S
    ldb r10,(r8)
	
	movia r12,TABELA

    add r12,r12,r10
   
    ldb r13,(r12)
   
    stbio r13,3(r9)
   
   
   
br FIM_CONT


/* 7- Subrotina que serve para verificar se os números no contador
batem com os números no alarme  
Só entra nessa subrotina quando a flag S_temp é igual a 1,
ou seja um alarme foi setado 
Se um alarme não foi setado, não há necessidade de passar por aqui */

verif_temp:

#Verificar se o valor do contador atingiu o valor do alarme

#------------------------------------------------------------

  movia r13,V1_S
  movia r14,V5_S

  ldb r15,(r13)
  ldb r17,(r14)
  bne r15,r17,FIM_CONT

  mov r13,r0
  mov r14,r0
  mov r15,r0
  mov r17,r0
#-----------------------------------------------#

  movia r13,V2_S
  movia r14,V6_S

  ldb r15,(r13)
  ldb r17,(r14)
  bne r15,r17,FIM_CONT

  mov r13,r0
  mov r14,r0
  mov r15,r0
  mov r17,r0

#-----------------------------------------------#
  movia r13,V3_S
  movia r14,V7_S

  ldb r15,(r13)
  ldb r17,(r14)
  bne r15,r17,FIM_CONT

  mov r13,r0
  mov r14,r0
  mov r15,r0
  mov r17,r0

#--------------------------------------------------#

  movia r13,V4_S
  movia r14,V8_S

  ldb r15,(r13)
  ldb r17,(r14)
  bne r15,r17,FIM_CONT

  mov r13,r0
  mov r14,r0
  mov r15,r0
  mov r17,r0

#-----------------------------------------------

#Se chegou aqui, os valores batem

# ALARME = 1 

   movia r13,ALARME
   movia r14,0b1
   stb r14,(r13)


br FIM_CONT


# 8- Subrotina para o caso de número do alarme ter sido atingido
# e assim auxiliar a provocar o efeito de pisca-pisca nos Led's vermelhos
ACENDER:

  #preciso acender o LED 
   movia r12, 0b111111111111111111
   stwio r12,(r8)
   
   movia r13,COUNTER2
   ldb r14,(r13)
   addi r14,r14,1
   stb r14,(r13)
	  
  
  br FIM_CONT


# 9- Subrotina para o caso de 10s terem se passado tdesde que o número
# no contador atingiu o número do alarme
FIM_tempo:
     movia r8,LEDR
     mov r12, r0
     stwio r12,(r8)
	 
	 movia r13,ALARME
     movia r14,0x0
     stb r14,(r13)
br FIM_CONT


#10- Subrotina para tratar o efeito pisca-pisca dos LED'S vermelhos
#a cada 0,5s durante 10s
c_LEDS:
# Observar se counter2 > 20
  movia r15,COUNTER2
  ldb r17,(r15)
  movia r18,0b10100 
  beq r17,r18,FIM_tempo
  
  
  
  #observar a situação do LED
    movia r8,LEDR
	ldwio r10,(r8)
	
	beq r10,r0,ACENDER
	
	#preciso apagar o LED
     mov r12, r0
     stwio r12,(r8)
  
     movia r13,COUNTER2
     ldb r14,(r13)
     addi r14,r14,1
     stb r14,(r13)
	 
br FIM_CONT


#11-Subrotina para tratar interrupções do temporizador a cada 0,5s
 TRATA_TIMER:
  addi sp, sp, -40
  stw  r8, 36(sp)
  stw  r9, 32(sp)
  stw  r10, 28(sp)
  stw  r11, 24(sp)
  stw  r12, 20(sp)
  stw  r13, 16(sp)
  stw  r14, 12(sp)
  stw  r15, 8(sp)
  stw  r17, 4(sp)
  stw  r18, (sp)
  
  
 # resetar bit de TO do TIMER
  movia r11,TIMER
  stwio r0, 0(r11)
   
   mov r11,r0
  
 #observar se o contador está parado 
  movia r11,CHAVE_t
  ldb r12,(r11)
  
  movia r13,0b1
  
  beq r12,r13,FIM_CONT
  
 
    movia r10, COUNTER
	ldb r11,(r10)
	
	movia r12,0b10
	
	beq r11,r12,pm_Cont
 
 
 #Deu 0,5s
  
    addi r11,r11,1
    stb r11,(r10)
  
 # Verificar se alarme está ativado
   movia r13,ALARME
   ldb r14,(r13)
   
   movia r15, 0b01
   
   beq r14,r15,c_LEDS
 
 
  # Verificar se um alarme foi criado
  mov r11,r0
  mov r14,r0
  mov r15,r0
 
  movia r12,S_alarme
  ldb r13,(r12)
 
  movi r14,0b1
 
  beq r13,r14,verif_temp 
 
 
 
 
FIM_CONT:
  ldw  r8, 36(sp)
  ldw  r9, 32(sp)
  ldw  r10, 28(sp)
  ldw  r11, 24(sp)
  ldw  r12, 20(sp)
  ldw  r13, 16(sp)
  ldw  r14, 12(sp)
  ldw  r15, 8(sp)
  ldw  r17, 4(sp)
  ldw  r18, (sp)
  addi sp, sp, 40
   
 ret
   
#-------- Fim das subrotinas tratadas pelo RTI --------------------

#-------- Início das subrotinas chamadas pelo MAIN --------------------
   

#1: Subrotina para escrever "Entre com o comando" na UART
SUB_1:
#PRÓLOGO
  addi sp, sp, -20
  stw sp, 16(sp)
  stw  r9, 12(sp)
  stw  r13, 8(sp)
  stw  r14, 4(sp)
  stw  r15, (sp) 

   movia r9, UART
   movia r13, MINHA_STRING
POLLING_ESCRITA:
   # checar se há espaço no buffer de saida (write FIFO)
   
   #ler as informações do registrador de controle
   ldwio r15, 4(r9) 
   srli  r15, r15, 16  # -> apenas ficar com a informação de WSPACE
   beq   r15, r0, POLLING_ESCRITA #não tem espaço disponível
   
   #tem espaço de escrita disponível   
   
LOOP:	
    ldb  r14, (r13)
	
	stbio r14,(r9) # -> escrever no registrador de dados
	
	addi r13, r13, 1
	
	# checar por byte nulo -> terminou string
	beq  r14, r0, SAI_LOOP
	
	br POLLING_ESCRITA
	

   
SAI_LOOP:

#EPÍLOGO
  ldw sp, 16(sp)
  ldw r9, 12(sp)
  ldw r13, 8(sp)
  ldw r14, 4(sp)
  ldw r15, (sp)
  addi sp, sp, 20
  ret
   
   

#2: Subrotina para coletar o 1º dígito digitado pelo usuário
SUB_2:
#PRÓLOGO
  addi sp, sp, -16
  stw  r8, 12(sp)
  stw  r11, 8(sp)
  stw  r12, 4(sp)
  stw  r13, (sp)
  
    
   movia r8, UART

  POLLING_LEITURA:	

  ldwio r11, (r8)
  andi  r12, r11, 0x8000  # separar campo RVALID
  beq   r12, r0, POLLING_LEITURA
  
  # 8 primeiros bits de r11 tem o caracter lido 
  
  andi  r11, r11, 0xFF   # separar campo DATA
  
  movia r13,DIGITO
  stb r11,(r13)
  
#EPÍLOGO
  ldw r8, 12(sp)
  ldw r11, 8(sp)
  ldw r12, 4(sp)
  ldw r13, (sp)
  addi sp, sp, 16
  ret
  

 # -------------- IMPLEMENTAÇÃO PARTE 1: LED'S VERDES ----------------

/*Subrotina para obter o 2º dígito caso a pessoa já tenha digitado
e o mesmo foi 0 */
/*Essa subrotina também é um divisor de águas para saber qual
implementação dos leds verdes deve fazer: acender, apagar,deslocar?
*/

 LED_V:
 
 
   movia r8, UART
  
  POLLING_LEITURAM:	
  ldwio r11, (r8)
  andi  r12, r11, 0x8000  # separar campo RVALID
  beq   r12, r0, POLLING_LEITURAM
  
  # 8 primeiros bits de r11 tem o caracter lido 
  
  andi  r11, r11, 0xFF   # separar campo DATA
  
  movia r13,DIGITO
  stb r11,(r13)
  
  
  movi r10,0b110000 # testa se r11 = 0 -> tem q apagar led
  beq r11,r10,PART_2
    
  movi r10,0b110001   # testa se r11 = 1 -> tem q acender led
  beq r11,r10,PART_3
  
  movi r10,0b110010   # testa se r11 = 2 -> tem q deslocar todos os leds acesos uma posição para esquerda
  beq r11,r10,PART_4
     
  movi r10,0b110011  # testa se r11 = 3 > tem q deslocar todos os leds acesos uma posição para direita
  beq r11,r10,PART_5

  # Se o segundo dígito for diferente de 0,1,2,3
  # voltar no polling até o usuário digitar um desses 4 valores
  
 br POLLING_LEITURAM 


#EXTRA: Caso especial quando o 4º dígito é igual a 8
 cond2:	
   movia r16,LEDV
   
   movia r18,TABELA_LEDV
 
   add r19,r18,r17
 
   ldh r20,(r19)
 
   ldwio r21,(r16)
 
   xori r20,r20,0x1FF
 
   and r22,r21,r20
 
   sthio r22,(r16)

   br finale2
 
 
 # COMANDO 00 XX: Subrotina para apagar o xx-ésimo led
 # Captura o 3º e o 4º dígito (led a ser apagado)
 LED_V0:
 #PRÓLOGO
  addi sp, sp, -52
  stw  r8, 48(sp)
  stw  r11, 44(sp)
  stw  r12, 40(sp)
  stw  r13, 36(sp)
  stw  r14, 32(sp)
  stw  r15, 28(sp)
  stw  r16 ,24(sp)
  stw  r17 ,20(sp)
  stw  r18 ,16(sp)
  stw  r19, 12(sp)
  stw  r20, 8(sp)
  stw  r21, 4(sp)
  stw  r22, (sp)
  
  
  movia r8,UART
  movia r16,LEDV
  
  # Ler o 1 digito = R11  (tem que ser igual a 0)
  POLLING_LEITURA3:	
  ldwio r11, (r8)
  andi  r12, r11, 0x8000  # separar campo RVALID
  beq   r12, r0, POLLING_LEITURA3

  andi  r11, r11, 0xFF   # separar campo DATA
  
  andi  r11, r11, 0xF   # separar o número desejado


  /* Se o dígito for diferente de 0 voltar para o polling,
  a fim de evitar bugs no contador */
  # Vai ficar no polling até o 3º dígito ser diferente de 0
  bne r11,r0,POLLING_LEITURA3

  movia r13,DIGITO
  stb r11,(r13)
    
  slli r19,r11,1 
 
 # Ler o 2 digito =R14 
  POLLING_LEITURA4:	
  ldwio r14, (r8)
  andi  r15, r14, 0x8000  # separar campo RVALID
  beq   r15, r0, POLLING_LEITURA4
 
  andi  r14, r14, 0xFF   # separar campo DATA
  
  andi r14,r14,0xF  # separar o número desejado

  /* Se o dígito for maior que 9 voltar para o polling,
  a fim de evitar bugs no contador */

   movia r13,0b1001

   bgt r14,r13,POLLING_LEITURA4

# ---------------------------------------------------------------
/* Se o dígito não estiver entre os válidos */
   beq r14,r0,CONTINUAR  # 0
   
   movia r13,0b1
   
   beq r14,r13,CONTINUAR # 1

   movia r13,0b10

   beq r14,r13,CONTINUAR #2
   
   movia r13,0b11
   
   beq r14,r13,CONTINUAR #3
   
   movia r13,0b100
   
   beq r14,r13,CONTINUAR #4
   
   movia r13,0b101
   
   beq r14,r13,CONTINUAR #5
   
    movia r13,0b110
   
    beq r14,r13,CONTINUAR #6
	
	movia r13,0b111
   
    beq r14,r13,CONTINUAR #7
	
	movia r13,0b1000
   
    beq r14,r13,CONTINUAR #7
	
	#Chegou até aqui é algo inválido
	
	br POLLING_LEITURA4
	
# ---------------------------------------------------------------   



CONTINUAR:


  mov r13,r0

  movia r13,DIGITO
  stb r14,(r13)
 
 
 #Sei o 1º e o 2º digito que foi digitado
 
 
 mov r17,r14
 or r17,r17,r11
  
 #r17 tem o dígito certo
 
  mov r21,r0
  movia r21,8
 
  beq r17,r21,cond2
 
 
 movia r18,TABELA_LEDV
 
 add r19,r18,r17
 
 ldb r20,(r19)
 
 ldwio r21,(r16)
 
 xori r20,r20,0xFF
 
 and r22,r21,r20
  
 
 #stwio r22,(r16)
 stbio r22,(r16)
 
  
#EXTRA: Retorno do caso especial (digito 8)
finale2:

#EPILÓGO
  ldw  r8, 48(sp)
  ldw  r11, 44(sp)
  ldw  r12, 40(sp)
  ldw  r13, 36(sp)
  ldw  r14, 32(sp)
  ldw  r15, 28(sp)
  ldw  r16 ,24(sp)
  ldw  r17 ,20(sp)
  ldw  r18 ,16(sp)
  ldw  r19, 12(sp)
  ldw  r20, 8(sp)
  ldw  r21, 4(sp)
  ldw  r22, (sp)
  addi sp, sp, 52

 ret
 
 
 
 #EXTRA: Caso especial quando o 4º dígito é igual a 8
 cond1:	
   movia r16,LEDV
   
   movia r18,TABELA_LEDV
 
   add r19,r18,r17
 
   ldh r20,(r19)
 
   ldwio r21,(r16)
 
   or r22, r21, r20
 
   sthio r22,(r16)

   br finale1
   
  
 # COMANDO 01 XX: Subrotina para acender o xx-ésimo led
 # Captura o 3º e o 4º dígito (led a ser aceso)
 
LED_V1:
#PRÓLOGO
  addi sp, sp, -52
  stw  r8, 48(sp)
  stw  r11, 44(sp)
  stw  r12, 40(sp)
  stw  r13, 36(sp)
  stw  r14, 32(sp)
  stw  r15, 28(sp)
  stw  r16 ,24(sp)
  stw  r17 ,20(sp)
  stw  r18 ,16(sp)
  stw  r19, 12(sp)
  stw  r20, 8(sp)
  stw  r21, 4(sp)
  stw  r22, (sp)

  movia r8,UART
  movia r16,LEDV
  
  # Ler o 1 digito = R11  (tem que ser igual a 0)
  POLLING_LEITURA1:	
  ldwio r11, (r8)
  andi  r12, r11, 0x8000  # separar campo RVALID
  beq   r12, r0, POLLING_LEITURA1

  andi  r11, r11, 0xFF   # separar campo DATA
  
  andi  r11, r11, 0xF   # separar o número desejado


  /* Se o dígito for diferente de 0 voltar para o polling,
  a fim de evitar bugs no contador */
  # Vai ficar no polling até o 3º dígito ser diferente de 0
  bne r11,r0,POLLING_LEITURA1
  
  
  movia r13,DIGITO
  stb r11,(r13) 
  
  slli r19,r11,1 
 
 # Ler o 2 digito =R14 
  POLLING_LEITURA2:	
  ldwio r14, (r8)
  andi  r15, r14, 0x8000  # separar campo RVALID
  beq   r15, r0, POLLING_LEITURA2
 
  andi  r14, r14, 0xFF   # separar campo DATA
  
  andi r14,r14,0xF  # separar o número desejado

    /* Se o dígito for maior que 9 voltar para o polling,
  a fim de evitar bugs no contador */

   movia r13,0b1001

   bgt r14,r13,POLLING_LEITURA2

# ---------------------------------------------------------------
/* Se o dígito não estiver entre os válidos */
   beq r14,r0,CONTINUAR2  # 0
   
   movia r13,0b1
   
   beq r14,r13,CONTINUAR2 # 1

   movia r13,0b10

   beq r14,r13,CONTINUAR2 #2
   
   movia r13,0b11
   
   beq r14,r13,CONTINUAR2 #3
   
   movia r13,0b100
   
   beq r14,r13,CONTINUAR2 #4
   
   movia r13,0b101
   
   beq r14,r13,CONTINUAR2 #5
   
    movia r13,0b110
   
    beq r14,r13,CONTINUAR2 #6
	
	movia r13,0b111
   
    beq r14,r13,CONTINUAR2 #7
	
	movia r13,0b1000
   
    beq r14,r13,CONTINUAR2 #7
	
	#Chegou até aqui é algo inválido
	
	br POLLING_LEITURA2


CONTINUAR2:

  movia r13,DIGITO
  stb r14,(r13)
 
 
 #Sei o 1º e o 2º digito que foi digitado
 
 
 mov r17,r14
 or r17,r17,r11
 
 #r17 tem o dígito certo
 
 
  mov r21,r0
  movia r21,8
 
  beq r17,r21,cond1
 
 
 movia r18,TABELA_LEDV
 
 add r19,r18,r17
 
 ldb r20,(r19)
 
 ldwio r21,(r16)
 
 or r22, r21, r20
  
 
 #stwio r22,(r16)
 stbio r22,(r16)
 
#EXTRA: Retorno do caso especial (digito 8) 
finale1:

  ldw  r8, 48(sp)
  ldw  r11, 44(sp)
  ldw  r12, 40(sp)
  ldw  r13, 36(sp)
  ldw  r14, 32(sp)
  ldw  r15, 28(sp)
  ldw  r16 ,24(sp)
  ldw  r17 ,20(sp)
  ldw  r18 ,16(sp)
  ldw  r19, 12(sp)
  ldw  r20, 8(sp)
  ldw  r21, 4(sp)
  ldw  r22, (sp)
  addi sp, sp, 52
 
 ret
 
 
 
 # COMANDO 02 XX: Subrotina para deslocar todos os leds acesos 
 # uma posição para esquerda
 
 LED_V2:
 
  #PRÓLOGO
  addi sp, sp, -16
  stw  r16 ,12(sp)
  stw  r17 ,8(sp)
  stw  r18 ,4(sp)
  stw  r19, (sp)
 
   movia r16,LEDV
   
   
   ldwio r17,(r16)
   
   andi r18,r17,0xFF
   
   slli r19,r18,1
   
   stwio r19,(r16)
   
  #EPÍLOGO 
  stw  r16 ,12(sp)
  stw  r17 ,8(sp)
  stw  r18 ,4(sp)
  stw  r19, (sp)
  addi sp, sp, 16
  ret
 

 # COMANDO 03 XX: Subrotina para deslocar todos os leds acesos 
 # uma posição para direita
 LED_V3:
 
  #PRÓLOGO 
  addi sp, sp, -16
  stw  r16 ,12(sp)
  stw  r17 ,8(sp)
  stw  r18 ,4(sp)
  stw  r19, (sp)
  
   movia r16,LEDV
   
   
   ldwio r17,(r16)
   
   andi r18,r17,0xFF
   
   srli r19,r18,1
   
   stwio r19,(r16)
   
  #EPÍLOGO 
  stw  r16 ,12(sp)
  stw  r17 ,8(sp)
  stw  r18 ,4(sp)
  stw  r19, (sp)
  addi sp, sp, 16
  
  ret

#-------------FIM DA PARTE DE IMPLEMENTAÇÃO DOS LED'S VERDES---------


#----------------IMPLEMENTAÇÃO PARTE 2: TELA VGA --------------------------

#Subrotina para garantir que o 2º dígito é 0 a fim de cumprir o
#comando : 1 0
TELA1:

  #PRÓLOGO
  addi sp, sp, -16
  stw  r8, 12(sp)
  stw  r10, 8(sp)
  stw  r11, 4(sp)
  stw  r12, (sp)
  
  
    movia r8,UART
  
  POLLING_LEITURAc:	
   ldwio r11, (r8)
   andi  r12, r11, 0x8000  # separar campo RVALID
   beq   r12, r0, POLLING_LEITURAc
  
 
   andi  r11, r11, 0xFF   # separar campo DATA


  movi r10,0b110000 # testa se r11 = 0 -> 
  beq r11,r10,TELA
  
  
  #Se for diferente de 0 , o usuário precisa digitar os comandos
  #novamente (desde o início)
  
  
   
  #EPÍLOGO
  ldw  r8, 12(sp)
  ldw  r10, 8(sp)
  ldw  r11, 4(sp)
  ldw  r12, (sp)
  addi sp, sp, 16
  
  ret
 

# COMANDO 10: a tela do dispositivo VGA deve ser limpa 
#com a cor correspondente ao estado das 16 primeiras alavancas

 TELAM:
  #PRÓLOGO
  addi sp, sp, -56
  stw  r8, 52(sp)
  stw  r9, 48(sp)
  stw  r10, 44(sp)
  stw  r11, 40(sp)
  stw  r12, 36(sp)
  stw  r13, 32(sp)
  stw  r14 ,28(sp)
  stw  r15 ,24(sp)
  stw  r17 ,20(sp)
  stw  r18, 16(sp)
  stw  r20, 12(sp)
  stw  r21, 8(sp)
  stw  r22, 4(sp)
  stw  r23, (sp)
 

   # Ler conteúdo dos switches
   movia r9, SW
   movia r10, MEMVIDEO
   
   ldwio r21,(r9) # ---> acessando o reg de dados de chaves(switches)
   
   movia r22, 0xFFFF
   
   and r21,r21,r22 #considerar bits APENAS de 0 a 15
   
   
   movia r8,SIZE
   ldh r12,(r8)
   
   # i -> r11
   # j -> r13
   
# for (i = 0 ; i < 320 ; i++) //linhas
   mov r11, r0 # i = 0 
   mov r13, r0 # j = 0
   
   
  LACO1:

  #condição
  bgeu r11,r12, SAI_LACO1  #(i>= SIZE)
 
  
  #for ( j = 0 ; j < 240 ; j ++)
  movia r14,SIZE2
  ldh r15,(r14)  
  LACO2: 

  #condição 
  bgeu r13,r15,SAI_LACO2 # j >= SIZE

  #posição do pixel
  # posição = (i << 1) + (j << 10)
  slli r17,r11,0b1   #(i << 1)
  slli r18, r13, 0b1010  #(j << 10)

  add r20,r17,r18 # posição = (i << 1) + (j << 10)

  add r23,r10,r20 #  MemVideo =0x08000000 + (i + j)

  sthio r21,(r23) #HALF WORD : pois cada pixel tem 16 bits de armazenamento na memória

  addi r13,r13,1 #j++
 
  mov r23,r0

  br LACO2 


  SAI_LACO2:
  addi r11,r11,1 #i++
  mov r13,r0 #zerar j para iniciar novamente


  br LACO1 


  SAI_LACO1:
  #EPÍLOGO
  ldw  r8, 52(sp)
  ldw  r9, 48(sp)
  ldw  r10, 44(sp)
  ldw  r11, 40(sp)
  ldw  r12, 36(sp)
  ldw  r13, 32(sp)
  ldw  r14 ,28(sp)
  ldw  r15 ,24(sp)
  ldw  r17 ,20(sp)
  ldw  r18, 16(sp)
  ldw  r20, 12(sp)
  ldw  r21, 8(sp)
  ldw  r22, 4(sp)
  ldw  r23, (sp)
  addi sp, sp, 56
 
  ret

#-------------FIM DA PARTE DE IMPLEMENTAÇÃO DA TELA VGA -----------

#----------------IMPLEMENTAÇÃO PARTE 3: CONTADOR --------------------------


/*Subrotina para verificar qual comando de implementação seguir,
capturando assim o 2ºdígito, configurar o contador ou alarme, zerar alarme?*/
  CONTM:
  #PRÓLOGO
  addi sp, sp, -60
  stw  r8, 56(sp)
  stw  r9, 52(sp)
  stw  r10, 48(sp)
  stw  r11, 44(sp)
  stw  r12, 40(sp)
  stw  r13, 36(sp)
  stw  r14 ,32(sp)
  stw  r15 ,28(sp)
  stw  r16 ,24(sp)
  stw  r17, 20(sp)
  stw  r18, 16(sp)
  stw  r19, 12(sp)
  stw  r20, 8(sp)
  stw  r21, 4(sp)
  stw  r22, 0(sp)
   
   
  movia r8,UART
  movia r9,D7SEG
  
  POLLING_LEITURAt:	
   ldwio r11, (r8)
   andi  r12, r11, 0x8000  # separar campo RVALID
   beq   r12, r0, POLLING_LEITURAt
  
 
   andi  r11, r11, 0xFF   # separar campo DATA

   movi r10,0b110000 # testa se r11 = 0 -> configurar o contador
   beq r11,r10,CONT0
   
   
   movi r10,0b110001 # testa se r11 = 1 -> configurar alarme
   beq r11,r10,CONT1
   
   movi r10,0b110010 # testa se r11 = 2 -> zerar alarme
   beq r11,r10,CONT2
   
     #Se for diferente de 0 ,1 ou 2, o usuário precisa digitar 
	 #os comandos novamente (desde o início)
   
  #EPÍLOGO
  ldw  r8, 56(sp)
  ldw  r9, 52(sp)
  ldw  r10, 48(sp)
  ldw  r11, 44(sp)
  ldw  r12, 40(sp)
  ldw  r13, 36(sp)
  ldw  r14 ,32(sp)
  ldw  r15 ,28(sp)
  ldw  r16 ,24(sp)
  ldw  r17, 20(sp)
  ldw  r18, 16(sp)
  ldw  r19, 12(sp)
  ldw  r20, 8(sp)
  ldw  r21, 4(sp)
  ldw  r22, 0(sp)  
  addi sp, sp, 60
   
  ret


/*COMANDO 20 xxyy: configurar o CONTADOR para xx minutos e yy segundos
 OBS: Considero cada display dos displays de 7-seg com um dado:
 V8 V7 V6 V5 V4 V3 V2 V1  ( da esquerda para direita)
 */
CONT_0:

 #PRÓLOGO
  addi sp, sp, -60
  stw  r8, 56(sp)
  stw  r9, 52(sp)
  stw  r10, 48(sp)
  stw  r11, 44(sp)
  stw  r12, 40(sp)
  stw  r13, 36(sp)
  stw  r14 ,32(sp)
  stw  r15 ,28(sp)
  stw  r16 ,24(sp)
  stw  r17, 20(sp)
  stw  r18, 16(sp)
  stw  r19, 12(sp)
  stw  r20, 8(sp)
  stw  r21, 4(sp)
  stw  r22, 0(sp)
   
	
	 movia r8,UART
	 movia r9,D7SEG

# SEQUÊNCIA DE POLLING'S PARA COLETAR OS DÍGITOS QUE DEVERÃO
# SER COLOCADOS NO DISPLAY DE 7 SEGMENTOS (CONTADOR)
# ------------------------------------------------------------------
    # r11 - V4
    POLLING_CONT1: 
	ldwio r11, (r8)
    andi  r12, r11, 0x8000  # separar campo RVALID
	beq   r12, r0, POLLING_CONT1

    andi  r11, r11, 0xFF   # separar campo DATA
    andi  r11, r11, 0xF   # separar o número desejado
	


  /* Se o dígito for maior que 5 voltar para o polling,
  a fim de evitar bugs no contador */

   movia r13,0b0110

   bgeu r11,r13,POLLING_CONT1

# ---------------------------------------------------------------
/* Se o dígito não estiver entre os válidos */
   beq r11,r0,CONTINUAR3  # 0
   
   movia r13,0b1
   
   beq r11,r13,CONTINUAR3 # 1

   movia r13,0b10

   beq r11,r13,CONTINUAR3 #2
   
   movia r13,0b11
   
   beq r11,r13,CONTINUAR3 #3
   
   movia r13,0b100
   
   beq r11,r13,CONTINUAR3 #4
   
   movia r13,0b101
   
   beq r11,r13,CONTINUAR3 #5
      	
  #Chegou até aqui é ALGO INVÁLIDO
	
	br POLLING_CONT1
		
		
CONTINUAR3:
	
	mov r13,r0	
	
	#r13 -V3
	POLLING_CONT2:
	ldwio r13, (r8)
    andi  r14, r13, 0x8000  # separar campo RVALID
	beq   r14, r0, POLLING_CONT2

    andi  r13, r13, 0xFF   # separar campo DATA
    andi  r13, r13, 0xF   # separar o número desejado
	
    mov r14,r0	
# ---------------------------------------------------------------
/* Se o dígito não estiver entre os válidos */
   beq r13,r0,CONTINUAR4  # 0
   
   movia r14,0b1
   
   beq r13,r14,CONTINUAR4 # 1

   movia r14,0b10

   beq r13,r14,CONTINUAR4 #2
   
   movia r14,0b11
   
   beq r13,r14,CONTINUAR4 #3
   
   movia r14,0b100
   
   beq r13,r14,CONTINUAR4 #4
   
   movia r14,0b101
   
   beq r13,r14,CONTINUAR4 #5
   
   movia r14,0b110
	
   beq r13,r14,CONTINUAR4 #6
   
   movia r14,0b111
	
   beq r13,r14,CONTINUAR4 #7
	
   movia r14,0b1000
	
   beq r13,r14,CONTINUAR4 #8
	
   movia r14,0b1001
	
   beq r13,r14,CONTINUAR4 #9
	
	
	#Chegou até aqui é ALGO INVÁLIDO
	
	br POLLING_CONT2



CONTINUAR4:

	
	#r15 -V2
	POLLING_CONT3:
	ldwio r15, (r8)
    andi  r16, r15, 0x8000  # separar campo RVALID
	beq   r16, r0, POLLING_CONT3

    andi  r15, r15, 0xFF   # separar campo DATA
    andi  r15, r15, 0xF   # separar o número desejado
	
	
	mov r16,r0
	/* Se o dígito for maior que 5 voltar para o polling,
  a fim de evitar bugs no contador */

   movia r16,0b0110

   bgeu r15,r16,POLLING_CONT3

# ---------------------------------------------------------------
/* Se o dígito não estiver entre os válidos */
   beq r15,r0,CONTINUAR5  # 0
   
   movia r16,0b1
   
   beq r15,r16,CONTINUAR5 # 1

   movia r16,0b10

   beq r15,r16,CONTINUAR5 #2
   
   movia r16,0b11
   
   beq r15,r16,CONTINUAR5 #3
   
   movia r16,0b100
   
   beq r15,r16,CONTINUAR5 #4
   
   movia r16,0b101
   
   beq r15,r16,CONTINUAR5 #5
      	
  #Chegou até aqui é ALGO INVÁLIDO
	
	br POLLING_CONT3
	
	
CONTINUAR5:

	#r17 - V1
	POLLING_CONT4:
	ldwio r17, (r8)
    andi  r18, r17, 0x8000  # separar campo RVALID
	beq   r18, r0, POLLING_CONT4

    andi  r17, r17, 0xFF   # separar campo DATA
    andi  r17, r17, 0xF   # separar o número desejado
  
    mov r18,r0
  # ---------------------------------------------------------------
/* Se o dígito não estiver entre os válidos */
   beq r17,r0,CONTINUAR6  # 0
   
   movia r18,0b1
   
   beq r17,r18,CONTINUAR6 # 1

   movia r18,0b10

   beq r17,r18,CONTINUAR6 #2
   
   movia r18,0b11
   
   beq r17,r18,CONTINUAR6 #3
   
   movia r18,0b100
   
   beq r17,r18,CONTINUAR6 #4
   
   movia r18,0b101
   
   beq r17,r18,CONTINUAR6 #5
   
   movia r18,0b110
	
   beq r17,r18,CONTINUAR6 #6
   
   movia r18,0b111
	
   beq r17,r18,CONTINUAR6 #7
	
   movia r18,0b1000
	
   beq r17,r18,CONTINUAR6 #8
	
   movia r18,0b1001
	
   beq r17,r18,CONTINUAR6 #9
	
	
	#Chegou até aqui é ALGO INVÁLIDO
	
	br POLLING_CONT4
 
 
CONTINUAR6:
  #---------------------------------------------#

  #Obtido os dígitos, colocá-los no display 7seg
	movia r19,V4_S
	
	stb r11,(r19)

	ldb r20,(r19)
	
	movia r10,TABELA

    add r21,r10,r11
	
	ldb r22,(r21)
	
	stbio r22,3(r9)


    mov r19,r0
    mov r20,r0
    mov r21,r0
    mov r22,r0
   
  
    movia r19,V3_S
	
	stb r13,(r19)
	
	ldb r20,(r19)
	
	movia r10,TABELA

    add r21,r10,r13
	
	ldb r22,(r21)
	
	stbio r22,2(r9)

    mov r19,r0
    mov r20,r0
    mov r21,r0
    mov r22,r0

    movia r19,V2_S
	
	stb r15,(r19)
	
	ldb r20,(r19)
	
	movia r10,TABELA

    add r21,r10,r15
	
	ldb r22,(r21)
	
	stbio r22,1(r9)
	
    mov r19,r0
    mov r20,r0
    mov r21,r0
    mov r22,r0

    movia r19,V1_S
	
	stb r17,(r19)
	
	ldb r20,(r19)
	
	movia r10,TABELA

    add r21,r10,r17
	
	ldb r22,(r21)
	
	stbio r22,(r9)

#EPÍLOGO
  ldw  r8, 56(sp)
  ldw  r9, 52(sp)
  ldw  r10, 48(sp)
  ldw  r11, 44(sp)
  ldw  r12, 40(sp)
  ldw  r13, 36(sp)
  ldw  r14 ,32(sp)
  ldw  r15 ,28(sp)
  ldw  r16 ,24(sp)
  ldw  r17, 20(sp)
  ldw  r18, 16(sp)
  ldw  r19, 12(sp)
  ldw  r20, 8(sp)
  ldw  r21, 4(sp)
  ldw  r22, 0(sp)
  addi sp, sp, 60
  
 ret
 
 
# COMANDO 21 xxyy: configurar ALARME para xx minutos e yy segundos
 
CONT_1:
#PRÓLOGO
  addi sp, sp, -60
  stw  r8, 56(sp)
  stw  r9, 52(sp)
  stw  r10, 48(sp)
  stw  r11, 44(sp)
  stw  r12, 40(sp)
  stw  r13, 36(sp)
  stw  r14 ,32(sp)
  stw  r15 ,28(sp)
  stw  r16 ,24(sp)
  stw  r17, 20(sp)
  stw  r18, 16(sp)
  stw  r19, 12(sp)
  stw  r20, 8(sp)
  stw  r21, 4(sp)
  stw  r22, 0(sp)



  movia r8,UART
  movia r9,D7SEG_2


# SEQUÊNCIA DE POLLING'S PARA COLETAR OS DÍGITOS QUE DEVERÃO
# SER COLOCADOS NO DISPLAY DE 7 SEGMENTOS (ALARME)
# ------------------------------------------------------------------

    # r11 - V8
    POLLING_CONTa1: 
	ldwio r11, (r8)
    andi  r12, r11, 0x8000  # separar campo RVALID
	beq   r12, r0, POLLING_CONTa1

    andi  r11, r11, 0xFF   # separar campo DATA
    andi  r11, r11, 0xF   # separar o número desejado
	
	/* Se o dígito for maior que 5 voltar para o polling,
  a fim de evitar bugs no contador */

   movia r13,0b0110

   bgeu r11,r13,POLLING_CONTa1

# ---------------------------------------------------------------
/* Se o dígito não estiver entre os válidos */
   beq r11,r0,CONTINUAR7  # 0
   
   movia r13,0b1
   
   beq r11,r13,CONTINUAR7 # 1

   movia r13,0b10

   beq r11,r13,CONTINUAR7 #2
   
   movia r13,0b11
   
   beq r11,r13,CONTINUAR7 #3
   
   movia r13,0b100
   
   beq r11,r13,CONTINUAR7 #4
   
   movia r13,0b101
   
   beq r11,r13,CONTINUAR7 #5
      	
  #Chegou até aqui é ALGO INVÁLIDO
	
	br POLLING_CONTa1
	
	
CONTINUAR7:

     mov r13,r0
	
	#r13 -V7
	POLLING_CONTa2:
	ldwio r13, (r8)
    andi  r14, r13, 0x8000  # separar campo RVALID
	beq   r14, r0, POLLING_CONTa2

    andi  r13, r13, 0xFF   # separar campo DATA
    andi  r13, r13, 0xF   # separar o número desejado
	
	mov r14,r0
	
  # ---------------------------------------------------------------
/* Se o dígito não estiver entre os válidos */
   beq r13,r0,CONTINUAR8  # 0
   
   movia r14,0b1
   
   beq r13,r14,CONTINUAR8 # 1

   movia r14,0b10

   beq r13,r14,CONTINUAR8 #2
   
   movia r14,0b11
   
   beq r13,r14,CONTINUAR8 #3
   
   movia r14,0b100
   
   beq r13,r14,CONTINUAR8 #4
   
   movia r14,0b101
   
   beq r13,r14,CONTINUAR8 #5
   
   movia r14,0b110
	
   beq r13,r14,CONTINUAR8 #6
   
   movia r14,0b111
	
   beq r13,r14,CONTINUAR8 #7
	
   movia r14,0b1000
	
   beq r13,r14,CONTINUAR8 #8
	
   movia r14,0b1001
	
   beq r13,r14,CONTINUAR8 #9
	
	
	#Chegou até aqui é ALGO INVÁLIDO
	
	br POLLING_CONTa2	
	
CONTINUAR8:
	#r15 -V6
	POLLING_CONTa3:
	ldwio r15, (r8)
    andi  r16, r15, 0x8000  # separar campo RVALID
	beq   r16, r0, POLLING_CONTa3

    andi  r15, r15, 0xFF   # separar campo DATA
    andi  r15, r15, 0xF   # separar o número desejado
	
	
	mov r16,r0
	
 /* Se o dígito for maior que 5 voltar para o polling,
  a fim de evitar bugs no contador */

   movia r16,0b0110

   bgeu r15,r16,POLLING_CONTa3
	
	
	# ---------------------------------------------------------------
/* Se o dígito não estiver entre os válidos */
   beq r15,r0,CONTINUAR9 # 0
   
   movia r16,0b1
   
   beq r15,r16,CONTINUAR9 # 1

   movia r16,0b10

   beq r15,r16,CONTINUAR9 #2
   
   movia r16,0b11
   
   beq r15,r16,CONTINUAR9 #3
   
   movia r16,0b100
   
   beq r15,r16,CONTINUAR9 #4
   
   movia r16,0b101
   
   beq r15,r16,CONTINUAR9 #5
      	
  #Chegou até aqui é ALGO INVÁLIDO
	
	br POLLING_CONTa3
	
		
CONTINUAR9:

	#r17 - V5
	POLLING_CONTa4:
	ldwio r17, (r8)
    andi  r18, r17, 0x8000  # separar campo RVALID
	beq   r18, r0, POLLING_CONTa4

    andi  r17, r17, 0xFF   # separar campo DATA
    andi  r17, r17, 0xF   # separar o número desejado
  
  
  mov r18,r0
    # ---------------------------------------------------------------
/* Se o dígito não estiver entre os válidos */
   beq r17,r0,CONTINUAR10  # 0
   
   movia r18,0b1
   
   beq r17,r18,CONTINUAR10 # 1

   movia r18,0b10

   beq r17,r18,CONTINUAR10 #2
   
   movia r18,0b11
   
   beq r17,r18,CONTINUAR10 #3
   
   movia r18,0b100
   
   beq r17,r18,CONTINUAR10 #4
   
   movia r18,0b101
   
   beq r17,r18,CONTINUAR10 #5
   
   movia r18,0b110
	
   beq r17,r18,CONTINUAR10 #6
   
   movia r18,0b111
	
   beq r17,r18,CONTINUAR10 #7
	
   movia r18,0b1000
	
   beq r17,r18,CONTINUAR10 #8
	
   movia r18,0b1001
	
   beq r17,r18,CONTINUAR10 #9
	
	
	#Chegou até aqui é ALGO INVÁLIDO
	
	br POLLING_CONTa4	
  
  
  
  
CONTINUAR10:   
  #---------------------------------------------#

   #Obtido os dígitos, colocá-los no display 7seg 
	movia r19,V8_S
	
	stb r11,(r19)

	ldb r20,(r19)
	
	movia r10,TABELA

    add r21,r10,r11
	
	ldb r22,(r21)
	
	stbio r22,3(r9)


    mov r19,r0
    mov r20,r0
    mov r21,r0
    mov r22,r0
   
  
    movia r19,V7_S
	
	stb r13,(r19)
	
	ldb r20,(r19)
	
	movia r10,TABELA

    add r21,r10,r13
	
	ldb r22,(r21)
	
	stbio r22,2(r9)

    mov r19,r0
    mov r20,r0
    mov r21,r0
    mov r22,r0

    movia r19,V6_S
	
	stb r15,(r19)
	
	ldb r20,(r19)
	
	movia r10,TABELA

    add r21,r10,r15
	
	ldb r22,(r21)
	
	stbio r22,1(r9)
	
    mov r19,r0
    mov r20,r0
    mov r21,r0
    mov r22,r0

    movia r19,V5_S
	
	stb r17,(r19)
	
	ldb r20,(r19)
	
	movia r10,TABELA

    add r21,r10,r17
	
	ldb r22,(r21)
	
	stbio r22,(r9)
	
	
	mov r19,r0
    mov r20,r0
    mov r21,r0
    mov r22,r0

 /* Alarme foi criado, então deve-se preocupar se o número do contador
 chegou no número do alarme. Dessa forma habilita-se S_alarme
 que funciona como uma flag para avisar que a cada interrupção
 deve-se observar se o número do alarme foi atingido */
    movia r19,S_alarme
    
	movi r20,0b1
	
	stb r20,(r19)


#EPÍLOGO
  ldw  r8, 56(sp)
  ldw  r9, 52(sp)
  ldw  r10, 48(sp)
  ldw  r11, 44(sp)
  ldw  r12, 40(sp)
  ldw  r13, 36(sp)
  ldw  r14 ,32(sp)
  ldw  r15 ,28(sp)
  ldw  r16 ,24(sp)
  ldw  r17, 20(sp)
  ldw  r18, 16(sp)
  ldw  r19, 12(sp)
  ldw  r20, 8(sp)
  ldw  r21, 4(sp)
  ldw  r22, 0(sp)
  addi sp, sp, 60
  
  ret
 
 
 # COMANDO 22 xxyy: zerar o alarme- os 4 displays superiores devem ser apagados.
 
CONT_2:
#PRÓLOGO
  addi sp, sp, -12
  stw  r9, 8(sp)
  stw  r10, 4(sp)
  stw  r11, (sp)


#zerar botão S_alarme

    movia r9,S_alarme
	movia r11,D7SEG_2
	
	
#zerando displays correspondentes
    movia r10,V8_S
	
    stb r0,(r10)
	
	stbio r0,3(r11)
	
	
	
	movia r10,V7_S
	
	stb r0,(r10)
	
	stbio r0,2(r11)
	
	
	
	movia r10,V6_S
	
	stb r0,(r10)
	
	stbio r0,1(r11)
	
	
	
	movia r10,V5_S
	
	stb r0,(r10)
	
	stbio r0,(r11)

#EPÍLOGO
  ldw  r9, 8(sp)
  ldw  r10, 4(sp)
  ldw  r11, (sp)
  addi sp, sp, 12
	
 ret
 


#-------------FIM DA PARTE DE IMPLEMENTAÇÃO DO CONTADOR -----------


#------------------------ MAIN -----------------------------------

.global _start
_start:

# ->1ª PARTE: INICIALIZAR PILHA E DISPOSTIVOS QUE FARÃO INTERRUPÇÃO
	
	# inicializar o stack pointer 
	# PILHA COLOCADA NO ENDEREÇO 10.000 (em decimal) para não
	#colidir com o código escrito
	movia  sp, 0x2710
	 
	movia r8,LEDV
	movia r9, UART
	movia r10,D7SEG
	movia r11,D7SEG_2
	movia r20, PB
	  
	  
   #zerando diplay de 7 segmentos
   stbio r0,0(r10)
   stbio r0,1(r10)
   stbio r0,2(r10)
   stbio r0,3(r10) 
   
   
   stbio r0,0(r11)
   stbio r0,1(r11)
   stbio r0,2(r11)
   stbio r0,3(r11) 
   
   
   #zerando Leds verdes
    stwio r0,(r8)
	  
	  
    #1)a) habilitar dispositivo push-button 
	 movi  r22, 0b0110
     stwio r22, 8(r20)     # habilita interrupção do botão 1 e 2
		
     #1)b) habilitar o temporizador
     # - setar período de contagem (1 segundo - 50MHz então 0,5s - 25Mhz)
     movia r21, TIMER
     movia r9,25000000
     # parte baixa
     andi  r11, r9, 0xFFFF  # isolo a parte baixa dos 32 bits
     stwio r11, 8(r21) 
     # parte alta
     srli  r11, r9, 16      # isolo a parte alta dos 32 bits
     stwio r11, 12(r21)
     # preciso fazer o TIMER começar a contar
     # habilito ITO, habilito CONT, habilito START
     movi  r11, 0b111   # máscara para habilitar TIMER
     stwio r11, 4(r21)
	  
	 
	 #habilitar IRQ (Interrupt ReQuest)
	 # tenho de habilitar IRQ 0 (timer) no ienable
	 # tenho que habilitar IRQ 1 (push button) no ienable
     movi  r9, 0b11
     wrctl ienable, r9
	 
	 
	 # habilitar interrupção na CPU (sistema)
     movi  r9, 0b1
     wrctl status, r9	
	 
	 	
# ->2ª PARTE: ESCREVER "Entre com um novo comando: " na tela	
	#SUBROTINA 1: Inicializar JTAG UART
     call SUB_1
	 
User_info: 		 
# ->3ª PARTE: Seguir os comandos que o usuário digita na tela

	#SUBROTINA 2: Receber informação do usuário
	 call SUB_2
	
    #VERIFICAR QUAL É O PRIMEIRO DIGITO
	
	#se for 0 => Comando para leds verdes
	
	 movia r12,DIGITO
	 ldb r13,(r12)
	 
	 movia r15,0b110000 # caractere ASCII do 0
	 
	 
	 beq r13,r15,LED_V
	 
	 #se for 1 => Limpar a tela com cor específica
	 
	 movia r15,0b110001 # caractere ASCII do 1
	 
	 beq r13,r15,TELA0
	 
	 #se for 2  => Comandos para contador
	 
	 movia r15,0b110010 #caractere ASCII do 2
	 
	 beq r13,r15,CONT
	 
	 #se for 3  => Termina a execução do programa
	 movia r15,0b110011 #caractere ASCII do 3
	 
	 beq r13,r15,TERMINAR
	 
	 
	 
	 #Se for qualquer caractere diferente voltar a
	 #esperar o usuário digitar outro caractere 	 
     br User_info	 

# ---------------------------------------------------------------
/* Essa parte foi feita para faciliar o retorno das subrotinas
ao programa principal, então se o programa executou uma 
função específica solicitada anteriormente, é aberto ao
usuário a oportunidade de digitar novos comandos */

   PART_2:
   call LED_V0
   br User_info

   PART_3:	 
   call LED_V1
   br User_info

   PART_4:
   call LED_V2
   br User_info

   PART_5:
   call LED_V3
   br User_info

   TELA: 
   call TELAM
   br User_info

   TELA0: 
   call TELA1
   br User_info
   
   CONT:
   call CONTM
   br User_info
 
   CONT0:
   call CONT_0
   br User_info

   CONT1:
   call CONT_1
   br User_info
 
   CONT2:
   call CONT_2
   br User_info
 # ---------------------------------------------------------------
	 
	 	 
	 
TERMINAR:
	movia r8,LEDV
	movia r10,D7SEG
	movia r11,D7SEG_2
	movia r21, TIMER
	
 #zerando diplay de 7 segmentos
   stbio r0,0(r10)
   stbio r0,1(r10)
   stbio r0,2(r10)
   stbio r0,3(r10) 
   
   
   stbio r0,0(r11)
   stbio r0,1(r11)
   stbio r0,2(r11)
   stbio r0,3(r11) 
   
   
   #zerando Leds verdes
    stwio r0,(r8)
	
	#parar o temporizador
	movi  r11, 0b000   
    stwio r11, 4(r21)

FIM:
 br FIM



/* Área de definição dos dados que serão usados 
durante o programa */
	 
MINHA_STRING:
 .asciz "Entre com o comando: " 
 
 
  
 
  V1_S:
  .byte 0x0
  
  V2_S:
  .byte 0x0
  
  V3_S:
  .byte 0x0
  
  V4_S:
  .byte 0x0
  
  V5_S:
  .byte 0x0
  
  V6_S:
  .byte 0x0
  
  V7_S:
  .byte 0x0
  
  V8_S:
  .byte 0x0
    
  COUNTER:
  .byte 0x0
    
  COUNTER2:
  .byte 0x0
  
  ALARME:
  .byte 0x0
  
  S_alarme:
  .byte 0x0
  
   DIGITO:
  .byte 0x0
  
   CHAVE_t:
  .byte 0x0



TABELA:
  .byte  0b0111111  # 0
  .byte  0b0000110  # 1
  .byte  0b1011011  # 2
  .byte  0b1001111  # 3
  .byte  0b1100110  # 4
  .byte  0b1101101  # 5
  .byte  0b1111101  # 6
  .byte  0b0000111  # 7
  .byte  0b1111111  # 8
  .byte  0b1100111  # 9
  
  

  SIZE:
  .hword 0x140

  SIZE2:
  .hword 0xF0
  
  
  
  TABELA_LEDV:
  .byte 0b000000001 # 0
  .byte 0b000000010 # 1
  .byte 0b000000100 # 2
  .byte 0b000001000 # 3
  .byte 0b000010000 # 4
  .byte 0b000100000 # 5
  .byte 0b001000000 # 6
  .byte 0b010000000 # 7
  .hword 0b100000000 # 8
  
  

