#include<stdio.h>
#include<locale.h>

int main ()
{
	float s1, s2;
	
	setlocale(LC_ALL,"");
	
	printf("Insira o sal�rio inicial: ");
	scanf("%f", &s1);
	
	s2=(( (float)25/100 * s1)+ s1);
	printf("O sal�rio final com aumento ser� de: %f",s2);
}
