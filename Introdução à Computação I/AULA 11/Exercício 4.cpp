#include<stdio.h>
#include<locale.h>



int main()

{
	
	setlocale(LC_ALL,"Portuguese");
	
	const int tam1 = 8;
	const int tam2 = 8;
	
	
	int matriz[tam1][tam2] ,i,j,cont,transposta[tam2][tam1];
	
	
	for (i = 0 ; i < tam1 ; i++) //criando a matriz
	{
		for ( j = 0 ; j < tam2 ; j++)
		{
			printf("Digite um número:  ");
			scanf("%d",&matriz[i][j]);
			transposta[j][i] = matriz [i][j];	
		}	
	}
	
	
	printf("A matriz ficará: \n\n");
	for (i = 0 ; i < tam1 ; i++) //printando a matriz
	{
		for ( j = 0 ; j < tam2 ; j++)
		{
			printf("%d ",matriz[i][j]);	
		}	
		printf("\n");
	}
	
	
	printf("\nA transposta dessa matriz será: \n\n");
	for (i = 0 ; i < tam1 ; i++) //printando a transposta
	{
		for ( j = 0 ; j < tam2 ; j++)
		{
			printf("%d ",transposta[i][j]);	
		}	
		printf("\n");
	}
	
	
	cont=0;
	for (i = 0 ; i < tam1 ; i++) 
	{
		for ( j = 0 ; j < tam2 ; j++)
		{
		   if (transposta[i][j] != matriz [i][j])
		     {
		     cont=1;
			 break;	
		    }	
	    }
	}
	
	
	if (!cont)
	printf("\nÉ uma matriz simétrica!");
	else printf("\nNão é uma matriz simétrica!");
	
}
