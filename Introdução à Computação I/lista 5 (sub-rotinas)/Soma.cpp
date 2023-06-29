#include<stdio.h>

int soma(int n);

int main(void)
{
	int x;
	
	scanf("%d",&x);
	printf("%d",soma(x));
	
	return 0;	
}


int soma(int n)
{
	int i,soma=0;
	
	for (i=1;i<=n;i++)
	   soma = soma + i;
	
	
	return soma;
	
}
