#include<stdio.h>


int main()
{
	
	int i=0,vetor[4], *ptr;
	
	ptr=vetor;

	for (i=0;i<4;i++)
	{
	  
	  printf("\nDigite um n�mero:  ");	
	  scanf("%d",&vetor[i]);
		
	}
	
	
	printf("\nO vetor ficou: \n");
	
	for (i=0;i<4;i++)
	{
		printf("%d ",*(ptr+i));
	}
	
	
	/*Lembrar que arrays j� s�o ponteiros que apontam para sua primeira posi��o(�ndice 0)
	Ent�o, em C *v e v[] s�o sin�nimos: a[0] e *a apontam para a primeira posi��o, logo
	a[i] � igual a *(a+i); */
}
