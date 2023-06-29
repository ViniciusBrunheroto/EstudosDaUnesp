#include<stdio.h>


float media(void);

int main(void)
{
	printf("%.2f",media());
	return 0;	
}

float media(void)
{
	int num,soma=0,quant=0,q;
	
	do
	{
  	  printf("Digite um número:  ");
	  scanf("%d",&num);
	
	  if (num > 0)
	  {	
	  soma = soma + num;
	  quant++;
      }
      
	}while (num > 0);
	
	
	q= soma / quant;
	
	return q;	
}
