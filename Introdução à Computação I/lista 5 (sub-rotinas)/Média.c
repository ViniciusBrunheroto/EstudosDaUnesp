#include<stdio.h>

float media(void);

int main(void)
{
	printf("%.2f",media());
	return 0;	
}

float media(void)
{
	float num,soma=0,q;
	int quant=0;
	
	do
	{
  	  //printf("Digite um número:  ");
	  scanf("%f",&num);
	
	  if (num > 0)
	  {	
	  soma = soma + num;
	  quant++;
      }
      
	}while (num > 0);
	
	
	q= soma / quant;
	
	return q;	
}
