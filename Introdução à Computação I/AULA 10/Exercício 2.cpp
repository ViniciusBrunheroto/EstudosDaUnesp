#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>

int main()

{
	
	setlocale(LC_ALL,"Portuguese");
	
	
	const int tam = 10;
	const int tam2 = 20;
	
	int n1[tam],n2[tam],n3[tam2],i,j;
	
	srand(time(NULL));
	
	for (i = 0 ; i < tam ;i++)
	{
	   n1[i] = rand() % 10;
	   printf("%d, ",n1[i]);
    }
    
    printf("\n");
    for(i = 0 ; i < tam ; i++)
    {	
       n2[i] = rand() % 10;
	   printf("%d, ",n2[i]);		
	}
	
	j=0;
	for( i = 0 ; i < tam; i++)
	{
			
	   n3[j]= n1 [i];
	   j++;
	
	   n3[j]= n2 [i]; 				
	   j++;	
	}
	
	printf("\n");
	for( j = 0; j < tam2 ; j++)
	{
	 printf("%d, ",n3[j]);	
	}

	
	
}
	

