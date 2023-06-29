#include<stdio.h>
#include<locale.h>



int main()
{
	
	setlocale(LC_ALL,"Portuguese");
	
	
	const int linhas = 10;
	const int colunas = 20;
	
	int matriz [linhas] [colunas],vet[linhas],soma,i,j,k;
	
	for ( i= 0 ; i < linhas ; i++) // criando a matriz
	{
		for ( j = 0 ; j < colunas ; j++)
		{
		printf("Digite um número:  ");
		scanf("%d",& matriz[i] [j]);		
	    }
	}
	
	printf("A sua matriz é:  \n");
    for ( i = 0 ; i < linhas ; i++) //printando a matriz
	{
		for ( j = 0 ; j < colunas ; j++)
		  {
		   printf("%d ",matriz[i] [j]);		
		  }
		
		printf("\n");	
	}
	
	
	
	for ( i= 0 ; i < linhas ; i++) // somando os elementos de cada linha
	{
		soma=0;
		for ( j = 0 ; j < colunas ; j++)
		{
		soma= soma + matriz [i] [j];	
	    }
	    
	 vet[i] = soma;  // vetor composto pela soma de cada linha
	}


	k=0;	
    for ( i = 0 ; i < linhas ; i++) //multiplicando cada elemento pela soma da linha
    {	
    	for ( j = 0 ; j < colunas ; j++)
    	{
    	matriz[i] [j]= (matriz [i] [j] * vet[k]); 
    	}
	k++;
    }
	
	printf("\nA matriz resultante ficou: \n");
	for ( i = 0 ; i < linhas ; i++) //printando a matriz resultante
	{
		for ( j = 0 ; j < colunas ; j++)
		{
		printf("%d ",matriz[i] [j]);		
		}
		
		printf("\n");	
	}
	
}
