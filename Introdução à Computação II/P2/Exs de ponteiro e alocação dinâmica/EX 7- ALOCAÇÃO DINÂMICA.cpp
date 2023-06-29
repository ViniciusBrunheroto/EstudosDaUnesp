#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<stdlib.h>


void escrever(char *str);
void contar(char *str);



int main()
{
	
   setlocale(LC_ALL,"Portuguese");
   char *str;
   int num;
   
    printf("Escreva um valor N para ser o tamanho da sua string: ");
	scanf("%d",&num);
	
	if ((str = (char *) malloc(num *sizeof(char))))
        printf("Sucesso na alocação de uma string de %d bytes\n",num);
    else
    printf("Erro de alocação alocação da string\n");
   
   	
	escrever(str);
	contar(str);
	
	free(str);
}

void escrever(char *str)
{
	fflush(stdin);
	printf("\nDigite algo: ");
	gets(str);
}


void contar(char *str)
{
	int i=0,tamanho=0,cont1=0,cont2=0;

	tamanho= strlen(str);
	strlwr(str);
		
	for (i=0;i<tamanho;i++)
	{
		if ( str[i] == 'a' || str[i] == 'e'|| str[i] == 'i'|| str[i] == 'o'|| str[i] == 'u')
		   cont1++;
		else if (str[i] != ' ')
		   cont2++;
	}
	
	printf("\nHá %d vogais e %d consoantes",cont1,cont2);
	
	
}
