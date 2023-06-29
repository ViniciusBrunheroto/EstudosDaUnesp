#include<stdio.h>
#include<locale.h>

int main()

{
	
	setlocale(LC_ALL,"Portuguese");
	
	const int tam = 7;
	const int linhas = 7;
	const int colunas = 7;
	
	int vet1[tam],vet2[tam],matriz[linhas][colunas],i,j,maior,menor;
	
	
	
	for (i = 0 ; i < linhas ; i++) // criação da matriz
	{
		for (j = 0 ; j < colunas ; j++)
		  {
		  printf("Digite um número:  ");
		  scanf("%d",&matriz[i][j]);			
		  }	
	}	
	
	
	for ( i = 0 ; i < linhas ; i++) //maior elemento de cada linha
    {
    	maior= matriz[i][0];
    	for (j = 0 ; j < colunas ; j++)
          {
    	      if ( matriz [i][j] > maior)
		        {
		        maior= matriz[i][j];	
                }
          }
          
    	vet1[i] = maior;	
		}	
	
	
	
	for ( i = 0 ; i < colunas ; i++) //menor elemento de cada coluna
    {
    	menor= matriz[0][i];
    	for (j = 0 ; j < linhas ; j++)
          {
    	      if ( matriz [j][i] < menor)
		        {
		        menor= matriz[j][i];
                }
          }
          
    	vet2[i] = menor;	
	}	


    printf("\nA matriz gerada é:\n\n");
    for (i = 0 ; i < linhas ; i++) // print da matriz
	{
		for (j = 0 ; j < colunas ; j++)
		  {
		  printf("%d ",matriz[i][j]);			
		  }	
		  
	 printf("\n");	  
	}	

    printf("\n\nO primeiro vetor é:  \n");
	for (i = 0 ; i < linhas ; i++) // print do vetor 1
    {
	printf("%d ",vet1[i]);			
	}	
	
	
	printf("\n\nO segundo vetor é:  \n");
	for (i = 0 ; i < linhas ; i++) // print do vetor 2
    {
	printf("%d ",vet2[i]);			
	}	
		  
}
