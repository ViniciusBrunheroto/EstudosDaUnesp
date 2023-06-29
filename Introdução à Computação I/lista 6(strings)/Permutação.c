#include<stdio.h>
#include<string.h>


int main()
{
	int i,j,resultado,cont=0;
	char palavra1[50],palavra2[50],word[50],novafrase[50];
	
	//printf("Digite uma palavra:  ");
	scanf(" %s",palavra1);
	
	//printf("Digite outra palavra:  ");
	scanf(" %s",palavra2);
	
	strcpy(word,"");
	for (i=0;i<strlen(palavra1);i++)
	{	
	    for (j=0;j<strlen(palavra2);j++)
		{
		   if (palavra1[i] == palavra2[j]  && palavra2[j] != '*')
		   {
		   	word[cont]=palavra2[j];
		   	cont++;
		   	palavra2[j]= '*';
		   }
		}
    }
    
    resultado = strcmp(palavra1,word);
    if  (cont == strlen(palavra1) && resultado == 0)
        printf("Sim");
    
    else printf("Nao");

}
