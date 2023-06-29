#include<stdio.h>
#include<locale.h>


int main()

{
	
	setlocale(LC_ALL,"");
	
	
	float f, c , result;
	
	c = 1.1;
	f = 1.5;
	
	
	do
	{
	c = c + 0.03;
	f = f + 0.02;
	result++;
    }while (c <= f);
-		
    printf("Serão necessários %.2f anos para ciclano ser maior que fulano",result);		
		
		
}
	
