#include<stdio.h>
#include<conio.h>
#include<string.h>



void escrever(char *str);
void inverte(char *str,char *str2,int tamanho);


int main()
{
	char str[50], str2[50];
	int tamanho=0;
	
	escrever(str);
	tamanho= strlen(str);
	
    inverte(str,str2,tamanho);
	printf("%s",str2);
	
}

void escrever(char *str)
{
	
	puts("Digite algo:");
	gets(str);
}


void inverte(char *str,char *str2,int tamanho)
{
	
	int i=0,j=0;
	char *ptr;
	
	ptr= str;
	
	for (i=tamanho;i>0;i--)
	{
		str2[i] = *(ptr+j);
		j++;
	}
	str2[j+1] = '\0';
	
}

