#include<stdio.h>
#include<locale.h>
#include<math.h>
#include<conio.h>


int main ()

{
	setlocale(LC_ALL,"Portuguese");
	
	int num;
	
	printf("Insira um n�mero inteiro: ");
	scanf("%d",&num);
	
	if (num % 2 == 0)
	  printf("\nO n�mero � par");
    else if (num % 2 != 0)
           printf ("\nO n�mero � �mpar");
    
    getch();
}  
