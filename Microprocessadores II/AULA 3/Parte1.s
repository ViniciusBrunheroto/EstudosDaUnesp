

.equ TEST_NUM, 0X90abcdef /* O número a ser testado */


.global _start
_start:
     movia r8, TEST_NUM    /* Carregar r8 com o número a ser testado */
	 mov r9,r8      /* Copiar o número para r9 */
	 
	 
STRING_COUNTER:
     mov r10,r0   /* Limpar o contador */
	 
STRING_COUNTER_LOOP:
      beq r9,r0,END_STRING_COUNTER /* Loop até r9 não conter mais 1s */
	  srli r11,r9,0x01 /* Calcula o número de 1s deslocando o número */
	  and r9,r9,r11  /* AND com o resultado deslocado */
	  addi r10,r10,0x01 /* Incrementar o contador */
	  br STRING_COUNTER_LOOP
END_STRING_COUNTER:
      mov r12,r10  /* Armazenar o resultado no r12 */
	  
END:
      br END   /* Espera aqui quando o programa termina */
	  
.end	  
	  
	