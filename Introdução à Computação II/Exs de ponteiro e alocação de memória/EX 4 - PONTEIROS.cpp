#include<stdio.h>


int main()
{
	
	int i=0,vetor[4], *ptr;
	
	ptr=vetor;

	for (i=0;i<4;i++)
	{
	  
	  printf("\nDigite um número:  ");	
	  scanf("%d",&vetor[i]);
		
	}
	
	
	printf("\nO vetor ficou: \n");
	
	for (i=0;i<4;i++)
	{
		printf("%d ",*(ptr+i));
	}
	
	
	/*Lembrar que arrays já são ponteiros que apontam para sua primeira posição(índice 0)
	Então, em C *v e v[] são sinônimos: a[0] e *a apontam para a primeira posição, logo
	a[i] é igual a *(a+i); */
}
