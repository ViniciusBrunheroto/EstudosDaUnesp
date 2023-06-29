#include<stdio.h>


void maior_menor(int *x,int *a,int *b, int tam_v, int *cont_a , int *cont_b);


int main(void)
{
	const int tam=10;
	int vet[tam],a[tam],b[tam],i,quanta=0,quantab=0;
	
	for (i=0;i<tam;i++) //preencher o vetor principal
	   scanf("%d",&vet[i]);
	
	
	maior_menor(vet,a,b,tam,&quanta,&quantab);  //chamando a função
	
	
	for (i=0;i< quanta ;i++) //printando o vetor A
	{
 	   printf("%d ",a[i]);
    }
	
	printf("\n");
	for (i=0;i< quantab ;i++) //printando o vetor B
	{   
	   printf("%d ",b[i]);
    }
	   
	return 0;   
}



 void maior_menor(int *x,int *a,int *b,int tam_v, int *cont_a, int *cont_b)
{
	
	int i,posicaoa=0,posicaob=0,quanta,quantb;
	
	for (i=0;i<tam_v;i++)
	{
		
		if (x[i]> 0)
		{
			a[posicaoa]=x[i];
			posicaoa++;
		}
		
		if (x[i] <= 0)
		{
			b[posicaob]=x[i];
			posicaob++;
	    }
	}
	
	*cont_a= posicaoa;
	*cont_b= posicaob;
}
