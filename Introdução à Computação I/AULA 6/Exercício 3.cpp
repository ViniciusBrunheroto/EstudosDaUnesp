#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<locale.h>

int main()

{
	setlocale(LC_ALL,"");
	
	float n1, n2, n3;
	
	printf("Digite um n�mero: ");
	scanf("%f",&n1);
	
	printf("Digite um n�mero: ");
	scanf("%f",&n2);
	
	printf("Digite um n�mero; ");
	scanf("%f",&n3);
	
	if ((n1 < (n2+n3)) && (n2 < (n1+n3)) && (n3 < (n1+n2)))
	{
		if ((n1 == n2) && (n2 == n3))
		 printf("� um tri�ngulo equil�tero");
		else if ((n1 == n2) || (n2 == n3) || (n1 == n3))
		       printf("� um tri�ngulo is�sceles");
		     else if ((n1 != n2) && (n2 != n3) && (n1 != n3))
		             printf("� um tri�ngulo escaleno");
	}
	
	else printf("N�o forma um tri�ngulo");
}

