#include<stdio.h>
#include<locale.h>

int main()
{
	float area, base, altura;
	setlocale(LC_ALL,"");
	
	printf("Digite o valor da base: ");
	scanf("%f" ,&base);
	printf("Digite o valor da altura: ");
	scanf("%f" , &altura);
	
	area=((base * altura) / (float) 2);
	printf( "O valor da �rea do tri�ngulo ser�: %.2f",area);
	
}
