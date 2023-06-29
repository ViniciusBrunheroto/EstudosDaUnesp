#include<stdio.h>

int qtade(int *x,int tam_v);

int main(void)
{
	const int tam = 30;
	int vet[tam];
	
	printf("%d",qtade(vet,tam));
	return 0;
}



int qtade(int *x, int tam_v)
{
	int i,quant=0;
	
	for (i=0;i<tam_v;i++)
	{
	   scanf("%d",&x[i]);
	   
	   if (x[i] % 2 == 0)
	   {
	      quant++;	
	   }
	}
	
	return quant++;
}


