/* Arquivo principal - parte 1 do laboratorio 2 */

.equ	STACK, 0x10000


/*****************************************************************************/
/* Program principal                                                         */
/*   Invoca sub-rotina para ordenar lista de valores em ordem decrescente.   */
/*                                                                           */
/* r8  - Endereco do tamanho da lista de numeros  ====> r4                         */
/* r9  - Endereco do primeiro numero na lista     ====> r5                           */
/*****************************************************************************/
.global _start
_start:
    movia	sp, STACK          /* Configura registradores da pilha e    */
    mov		fp,  sp            /* e frame pointer.                      */

    movia	r8,  SIZE          /* Endereço do tamanho                   */
    movia	r9,  LIST          /* Endereço do primeiro elemento         */

    ldw     	r4, 0(r8)          /* Carrega os parâmetros para sub-rotina */
    mov	    	r5, r9
    
    call	SORT # ir pra subrotina

END:
    br		END              /* Espera aqui quando o programa terminar  */

    
    
/*****************/    
    
.org	0x200

LIST_FILE:
SIZE:
.word 10
LIST:
.word 7,3,1,0,2,4,9,5,6,8

*****************************************************************************/
/* Subrotina SORT                                                        */
/*                                                                           */
/* r9 - i         */
/* r10  - indice_max           */
/* r11  - j           */
/* r12  - elemento que representa vetor[j]           */
/* r13  - elemento que representa vetor[indice_maximo]           */
/* r14 - temp        */
/* r15 - endereço do vetor[indice_maximo]        */
/*****************************************************************************/

.global SORT
SORT:
/* Escreva seu código aqui */
# for (i=0; i < size; i++) 

  mov   r9, r0	# i=0
 
LACO1:
 #condição
 bgeu r9,r4, SAI_LACO1  #(i>= SIZE)
# indice_max = i;
 mov r10,r9
 
 mov r8,r5 # conservar r5
 
 #carregando elemento vector[indice_maximo]
 ldw r13,(r8)
 
  mov r11,r9 # j=i
  addi r11,r11,1 #j = i+1
 #for (j=i+1; j < size; j++)
LACO2:
#condição 
bgeu r11,r4,SAI_LACO2 # j >= SIZE
/* if (vector[j] > vector[indice_max]) {
  indice_max = j; */
  
 #carregando elemento vector[j]
 ldw r12,4(r8)
 
 addi r8,r8,4 # vai para o proximo elemento da lista
 bgtu r12,r13, COND1
 
 
 addi r11,r11,1 #j++
 
 br LACO2

COND1:
  mov r15,r8 #endereço do vector[indice_max]
  mov r10,r11  #indice_max = j
  mov r13,r12 #atualizar valor da comparação
  addi r11,r11,1 #j++

 br LACO2



SAI_LACO2:
  beq r9,r10,COND2
   
  #encontrou valor maior
  #temp = vector[indice_max]
 ldw r14,(r15)
  
 
 mov r8,r0
 ldw r8,(r5)
 
 #vector[indice_max] = vector[i];
 stw r8,(r15)

 #vector[i] = temp
 stw r14,(r5)

  
  addi r9,r9,1 #i++
  addi r5,r5,4 #acompanhando indice i
  br LACO1


COND2:
# não encontrou valor maior
 addi r9,r9,1 #i++
 addi r5,r5,4 #acompanhando indice i
  br LACO1

SAI_LACO1:

ret #retornar pro main

.end

