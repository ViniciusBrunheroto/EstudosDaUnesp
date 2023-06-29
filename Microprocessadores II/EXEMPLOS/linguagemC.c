/*

 Toda vez que o botão 2 for pressionado, quero acender um
 led verde
 - a cada pressionamento, o led atual é apagado e do esquerda
 é aceso


*/

volatile int *PB  = (int *)0x10000050;   // botao
volatile int *LED = (int *)0x10000010;   // leds verdes

int main() {
	
	int estado = 1;
	
	while(1) {
	/*
POLLING:	
	ldwio  rX, 12(...)
	and    ...
	beq        , POLLING -> se não tiver sido apertado  
	*/
		while ( (*(PB+3) & 4) == 0); // polling
	/*
	 condicao = *(PB+3) & 4;
	 if (condicao == 0) while(1);	
	*/
		*(PB+3) = 4;
	
		*LED = estado;
		estado <<= 1;
	}
	
	return 0;
}