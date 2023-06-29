#include<stdio.h>
#include<locale.h>
#include<time.h>
#include<stdlib.h>


int main()
{
	
	setlocale(LC_ALL,"Portuguese");
	
	const int tam = 10;
	const int tam2 = 5;

    int n1[tam], n2[tam2], pos, i, j, k, div;
	
	srand(time(NULL));
	
	for( i = 0 ; i < tam ; i++) //para 10 unidades
	{
	   n1[i]= rand() % 10;
	   printf("%d, ",n1[i]);
	}
	

	printf("\n");
	for (j = 0 ; j < tam2 ; j++) //para 5 unidades
	{
	   n2[j]= rand() % 10;
	   printf("%d, ",n2[j]);
	}
	
    fflush(stdin);
    
    
	for( i = 0 ; i < tam ; i++)	
	{
	printf("\nNúmero %d\n", n1[i]);
	div=0;
	fflush(stdin);
	     for (j = 0;  j < tam2 ; j++)	
	     {	
	     if ((n1[i] % n2[j] == 0) && ( n1[i] != 0))
	     {
	     pos=j+1;
	     printf("Divisível por %d na posição %d \n",n2[j],pos);
	     div++;
	     fflush(stdin);
	     }
         }
    if (div == 0)
	printf("Não há divisores para esse número");     
    fflush(stdin);     
    }
    
    
}


    
    
