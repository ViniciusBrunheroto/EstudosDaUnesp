#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <conio.h>

int main ()
{
	int a1, r;
	
	setlocale(LC_ALL,"");
	
	printf("Digite um numero que ira representar o ano: ");
	scanf("%d",&a1);
	
	if ((a1 % 400 == 0)||((a1 % 4 == 0) && (a1 % 100 != 0)))
    printf("O ano e bissexto");
	else printf("O ano nao e bissexto");
	
	getch();
	
}
