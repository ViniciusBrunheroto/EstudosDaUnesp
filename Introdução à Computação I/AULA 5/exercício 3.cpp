#include<stdio.h>
#include<locale.h>
#include<math.h>

int main()

{
	double n1, n2 , n3;
	
	setlocale(LC_ALL,"");
	

	printf("Informe um número positivo: ");
	scanf("%lf",&n1);
	
	printf("Informe outro valor positivo: ");
	scanf("%lf",&n2);
	
	n3= pow(n1 , n2);
	printf("O primeiro número elevado ao segundo daria: %.2lf\n",n3);
	
	
	
}
