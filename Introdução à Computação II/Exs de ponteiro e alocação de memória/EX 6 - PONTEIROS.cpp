#include<stdio.h>
#include<conio.h>
#include<string.h>



void escrever(char *str);
void inverte(char *str,char *str2,char *ptr,int tamanho);


int main()
{
	char str[50], str2[50],*ptr;
	int tamanho=0,i=0,j=0;
	
	escrever(str);
	tamanho= strlen(str);
	ptr=str;
	
	for (i=tamanho;i<=0;i--)
	{
		
		str2[i] = *(ptr+j);
		j++;
	}
    
	printf("\n%s",str2);	
	
}


void escrever(char *str)
{
	
	printf("Digite algo:  ");
	gets(str);
}
