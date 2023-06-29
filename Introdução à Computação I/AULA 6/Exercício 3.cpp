#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<locale.h>

int main()

{
	setlocale(LC_ALL,"");
	
	float n1, n2, n3;
	
	printf("Digite um número: ");
	scanf("%f",&n1);
	
	printf("Digite um número: ");
	scanf("%f",&n2);
	
	printf("Digite um número; ");
	scanf("%f",&n3);
	
	if ((n1 < (n2+n3)) && (n2 < (n1+n3)) && (n3 < (n1+n2)))
	{
		if ((n1 == n2) && (n2 == n3))
		 printf("É um triângulo equilátero");
		else if ((n1 == n2) || (n2 == n3) || (n1 == n3))
		       printf("É um triângulo isósceles");
		     else if ((n1 != n2) && (n2 != n3) && (n1 != n3))
		             printf("É um triângulo escaleno");
	}
	
	else printf("Não forma um triângulo");
}

