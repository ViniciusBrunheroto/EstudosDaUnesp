#include <stdio.h>
#include<locale.h>

int main()
{
	float a1, a2, idade1, idade2, resp, a3;
	setlocale(LC_ALL,"");
	printf("Qual � o ano do seu nascimento?");
	scanf("%f", & a1);
	
	printf("Qual � o ano atual?");
	scanf("%f", & a2);
	
	idade1= (a2-a1);
	
	printf("Sua idade �: %.2f\n",idade1);
	
	printf("Para saber sua idade em 2050, digite 2050\n");
	scanf("%f", &a3);
	
	idade2= (a3-a1);
	printf("Em 2050, voc� ter� %.2f\n",idade2);	
}
