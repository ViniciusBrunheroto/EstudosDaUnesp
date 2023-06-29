#include<stdio.h>
#include<locale.h>


int main()
{
	setlocale(LC_ALL,"Portuguese");
	
	
	const int tam = 8;
	const int tam2 = 10;
	
	int num[tam2],somanota[tam2],ndeaprovados,i,j;
	char gab[tam],resp[tam];
	
	printf("--------GABARITO------------\n");
	for ( i = 0; i < tam ; i++)
	{	
	printf("Informe o gabarito da questão %d\n",i+1);
	scanf("%c",&gab[i]);
	fflush(stdin);		
	}
	
	printf("-------RESPOSTAS DOS ALUNOS-------\n");

	for (j = 0 ; j < tam2 ; j++)
	{	
	printf("\nInforme o número do aluno: \n");
	scanf(" %d",&num[j]);
    fflush(stdin);
    somanota[j]=0;
	     for (i = 0; i < tam ; i++)
         {	
	     printf("Informe a resposta da questão %d\n",i+1);
	     scanf(" %c",&resp[i]);	
	     
	     if (resp[i] == gab[i])
	     {
	     somanota[j]= somanota[j]+ 1;
         }
         }
	}	
	
	for (j = 0; j < tam2 ; j++)
	{
		
	printf("\nAluno número %d\n",num[j]);
	printf("Nota %d\n",somanota[j]);
		
	if (somanota[j] >= 6.0)
	ndeaprovados++;
	
	}
	

	printf("\nA porcentagem de aprovação é de %.2f%%",((float)ndeaprovados * 100) / tam2);
	
	
	
	
	
	
}
