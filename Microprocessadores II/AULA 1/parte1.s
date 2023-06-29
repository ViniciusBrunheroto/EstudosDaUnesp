
/* Programa que encontra o maior número em uma lista de inteiros */

.equ LIST, 0x500 /*Inicia o endereço da lista, simbolo -> expressão */

.global _start
_start:

movia r4,LIST /* r4 aponta para o início da lista */
ldw r5,4(r4) /* r5 é um contador, inicializado com n */
addi r6,r4,8 /* r6 aponta pro primeiro valor */
ldw r7,(r6) /*r7 guarda o maior valor encontrado até aqui */

LOOP:
subi r5,r5,1 /* decrementa o contador */
beq r5,r0,DONE /*termina se r5 for igual a 0 */
addi r6,r6,4 /* incrementa o ponteiro da lista */
ldw r8,(r6) /* obtém o próximo número *//
bge r7,r8,LOOP /* Checa se o maior número foi encontrado */
add r7,r8,r0 /* Atualiza o maior número encontrado */
br LOOP

DONE:
stw r7,(r4) /*Armazena o maior valor encontrado no RESULT */

STOP:
br STOP /*Se estiver tudo concluído */

.org 0x500
RESULT:
.skip 4 /*Espaço para o maior número */

N:
.word 7 /*Número de entradas na lista */

NUMBERS:
.word 4,5,3,6,1,8,2 /* Números na lista */
.end