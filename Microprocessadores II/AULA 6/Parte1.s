


.equ UART, 0x10001000



.global _start
_start:
	

	
	movia r9, UART
	
	

POLLING_ESCRITA:
   # checar se há espaço no buffer de saida (write FIFO)
   
   #ler as informações do registrador de controle
   ldwio r15, 4(r9) 
   srli  r15, r15, 16  # -> apenas ficar com a informação de WSPACE
   beq   r15, r0, POLLING_ESCRITA #não tem espaço disponível
   
   #tem espaço de escrita disponível
   
  #laço de atraso (escrever os caracteres a cada 0.5s)
   mov r17,r0
   
   
   movia r18,0xf4240 #r18 = 1.000.000 ( faz em 0,5 s)
   
   #movia r18,0x1e8480  #r18 = 2.000.000 ( faz em 1 s)
   
   LACO:
   
   addi r17,r17,1
   
   beq r17,r18,SAI_LACO
   
   br LACO
   
   SAI_LACO:
   
   
   movi r16,'Z'
   stwio r16,(r9) # -> escrever no registrador de dados
   
   
   br POLLING_ESCRITA
   
   
   
   FIM:
     br FIM
   