#include<stdio.h>
#include<locale.h>
#include<math.h>
#include<conio.h>

int main()
{
	
	setlocale(LC_ALL,"Portuguese");
	
	float ni, nf;
	double n1, na, na2;
	
	printf("Digite um n�mero real:  ");
	scanf("%lf",&n1);
	
	ni = (int)n1;
	printf("A parte inteira desse n�mero �: %0.f\n ",ni);
	
	printf("\n------------------------------------\n\n");
	
	nf= (n1-ni);
	printf("A parte fracionada desse n�mero �: %0.4f\n",nf);
	
	printf("\n------------------------------------\n\n");
	
	na= ceil(n1);
	printf("O arredondamento para cima desse n�mero seria: %0.lf\n",na);
	
	printf("\n------------------------------------\n\n");
	
	na2= floor(n1);
	printf("O arredondamento para baixo desse n�mero seria: %0.lf\n",na2);
	getch( );
	
	
}
