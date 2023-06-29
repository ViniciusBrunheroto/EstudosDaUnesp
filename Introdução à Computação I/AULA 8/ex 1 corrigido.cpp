#include<stdio.h>
#include<locale.h>


int main ()


{
	
	
	setlocale(LC_ALL,"Portuguese");
	
	
	int i, x, n,result;
	
	
	printf("\nInforme a base: ");
	scanf("%d",&x);
	
	printf("\nInforme o expoente: ");
	scanf("%d",&n);

	
	
	if (n >= 1)
	{
	{
		for ( i = 1; i <= n; i++ )
		result = result * x;
			
	}
	printf("\n%d elevado a %d é igual a : %d",x,n,result);
    }
	
	if (n == 0)
	printf("\nO resultado será 1");
	
	
	
	if (n < 0)
	{
	{
		for ( i = -1; i >= n ; i= i - 1 )
		result= result * x;
	
	}
	
	printf("\n%d elevado a %d é igual a: 1 / %d",x,n,result);
	
	
    }
	
	
	
}
