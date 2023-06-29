#include<stdio.h>
#include<locale.h>
#include<math.h>

int main ()
{
	
	double num, num2, num3, raiz2num , raiz3num;
	
	setlocale(LC_ALL, "");
	 
	
	printf("Informe um número positivo e maior que zero: ");
	scanf("%lf",&num);
	
	num2= pow(num, 2.0);
	printf("O número digitado ao quadrado equivale a: %.2lf\n",num2);
	
	printf("\n----------------------------------------------\n\n");
	
	num3= pow(num, 3.0);
	printf("O número digitado ao cubo equivale a: %.2lf\n",num3);
	
	printf("\n----------------------------------------------\n\n");
	
	raiz2num= sqrt(num);
	printf("A raiz quadrada do número digitado é: %.6lf\n",raiz2num);
	
	printf("\n----------------------------------------------\n\n");
	
	raiz3num = cbrt(num);
	printf("A raiz cúbica do número digitado é %.6lf\n",raiz3num);
		
}
