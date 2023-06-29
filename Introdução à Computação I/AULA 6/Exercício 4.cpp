#include<stdio.h>
#include<locale.h>
#include<math.h>
#include<conio.h>

int main()
{
	int n, ano;
	
	
	setlocale(LC_ALL,"Portuguese");
	
	
	printf("Informe o número de um mês: ");
	scanf("%d",&n);
	
	if ((n == 1) || (n == 3) || (n == 5) || (n == 7)|| 
	(n == 8) || (n == 10) || (n == 12))
	printf("O mês escolhido possui 31 dias");
	
	if ((n == 4) || (n == 6) || (n == 9) || (n == 11))
	printf("O mês escolhido possui 30 dias");
	
	if (n == 2)
	{
	printf("Digite o ano: ");
	scanf("%d",&ano);
	
	if ( (n % 400 == 0) && ((n % 4 == 0) && (n % 100 != 0 )) )
	  printf("O mês terá 29 dias");
	else printf("O mês terá 28 dias");
	}
	
}
