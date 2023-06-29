#include<stdio.h>
#include<locale.h>


int main()

{
	
	
	setlocale(LC_ALL,"");
	
	
	int i, q, result, x;
	
	result= 0;
	
	for (q = 1; q <= 5 ; q++)
	{
	printf("\nDigite a sua idade:  ");
	scanf("%d",&i);
	
	if (i >= 18)
	result= result + 1;
    }
    
    printf("\nExistem %d pessoas maiores de idade",result);


   
   
}
