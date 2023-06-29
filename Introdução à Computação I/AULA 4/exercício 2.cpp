#include<stdio.h>
#include<locale.h>

int main ()
{
	float s1, s2;
	
	setlocale(LC_ALL,"");
	
	printf("Insira o salário inicial: ");
	scanf("%f", &s1);
	
	s2=(( (float)25/100 * s1)+ s1);
	printf("O salário final com aumento será de: %f",s2);
}
