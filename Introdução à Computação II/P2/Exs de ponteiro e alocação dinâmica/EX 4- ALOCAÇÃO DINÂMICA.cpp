#include<stdio.h>
#include<stdlib.h>
#include<locale.h>



int main()
{
	
	setlocale(LC_ALL,"Portuguese");
	int *vetor,n,i;
	
	printf("\nDigite um valor N: ");
	scanf("%d",&n);
	
	if(( vetor=((int *)malloc( n * sizeof(int)))))
	   printf("\nSucesso na alocação de um vetor com %d elementos",n);
	else
	printf("\nErro na alocação do vetor.");
	
	
	printf("\nDigite %d número(s):  \n",n);	
	for (i=0;i<n;i++)
	{
	  scanf("%d",&vetor[i]);
		
	}
	
	printf("O vetor final ficou: ");
	for (i=0;i<n;i++)
	{
		printf("%d ",vetor[i]);
	}
	
	free(vetor);
	
}
