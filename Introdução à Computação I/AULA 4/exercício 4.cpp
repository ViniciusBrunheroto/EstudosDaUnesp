#include<stdio.h>
#include<locale.h>

int main()
{
	float pes, polegadas, jardas, milhas;
	setlocale(LC_ALL,"");
	
	printf("Insira um número na unidade pés: ");
	scanf("%f" , &pes); 
	
	polegadas= (12 * pes);
	printf("Equivale em polegadas a: %.5f\n",polegadas);
	
	jardas= ( ((float)1 / 3) * pes);
	printf("Equivale em jardas a: %.2f\n",jardas);
	
	milhas= ( ((float)1 / 5280) * pes);
	printf("Equivale em milhas a: %f\n",milhas);
	
}
