#include<stdio.h>


void maior_menor(int *x,int *a,int *b, int tam_v);


int tamanhoa=0,tamanhob=0; //variáveis globais


int main(void)
{
	const int tam=30;
	int vet[tam],a[tam],b[tam],i;
	
	for (i=0;i<tam;i++) //preencher o vetor principal
	   scanf("%d",&vet[i]);
	
	
	maior_menor(vet,a,b,tam);  //chamando a função
	
	for (i=0;i<tamanhoa;i++) //printando o vetor A
	{
 	   printf("%d ",a[i]);
    }
	
	printf("\n");
	for (i=0;i<tamanhob;i++) //printando o vetor B
	{   
	   printf("%d ",b[i]);
    }
	   
	return 0;   
}



 void maior_menor(int *x,int *a,int *b,int tam_v)
{
	
	int i,posicaoa=0,posicaob=0;
	
	for (i=0;i<tam_v;i++)
	{
		
		if (x[i]> 0) //criando o vetor A
		{
			a[posicaoa]=x[i];
			posicaoa++;
		}
		
		if (x[i] <= 0) //criando o vetor B
		{
			b[posicaob]=x[i];
			posicaob++;
	    }
	}
	
	tamanhoa= posicaoa;
	tamanhob= posicaob;
}
