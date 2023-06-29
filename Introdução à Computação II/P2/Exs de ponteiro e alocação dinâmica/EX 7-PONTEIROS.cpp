#include<stdio.h>
#include<string.h>
#include<locale.h>


void escrever(char *str);
void contar(char *str);



int main()
{
	
	setlocale(LC_ALL,"Portuguese");
   char str[50];
   
   
   	escrever(str);
	contar(str);

	
	
}

void escrever(char *str)
{
	printf("\nDigite algo: ");
	gets(str);
}


void contar(char *str)
{
	int i=0,tamanho=0,cont1=0,cont2=0;
	char *ptr;
	
	tamanho= strlen(str);
	strlwr(str);
	
	ptr=str;
	
	for (i=0;i<tamanho;i++)
	{
		if ( *(ptr+i) == 'a' || *(ptr+i)== 'e'|| *(ptr+i) == 'i'|| *(ptr+i)== 'o'|| *(ptr+i) == 'u')
		   cont1++;
		else if (*(ptr+i)!= ' ')
		   cont2++;
	}
	
	printf("\nHá %d vogais e %d consoantes",cont1,cont2);
	
	
}
