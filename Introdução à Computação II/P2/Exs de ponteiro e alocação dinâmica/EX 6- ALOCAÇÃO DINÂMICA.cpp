#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

void escrever(char *string);


int main()
{
	
	char *str;
	int num;
	
	printf("Escreva um valor N para ser o tamanho da sua string: ");
	scanf("%d",&num);
	
	if ((str = (char *) malloc(num *sizeof(char))))
        printf("Sucesso na alocacao de uma string de %d bytes\n",num);
    else
    printf("Erro de alocação alocação da string\n");
    
    
	escrever(str);
	
	strrev(str);
	
	printf("%s",str);
	
	free(str);	
}


void escrever(char *string)
{
	fflush(stdin);
	printf("\nDigite algo:  ");
	gets(string);
	
}
