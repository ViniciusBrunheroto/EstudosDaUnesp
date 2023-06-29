#include<stdio.h>
#include<locale.h>
#include<math.h>
#include<conio.h>


int main ()

{
	setlocale(LC_ALL,"Portuguese");
	
	int num;
	
	printf("Insira um número inteiro: ");
	scanf("%d",&num);
	
	if (num % 2 == 0)
	  printf("\nO número é par");
    else if (num % 2 != 0)
           printf ("\nO número é ímpar");
    
    getch();
}  
