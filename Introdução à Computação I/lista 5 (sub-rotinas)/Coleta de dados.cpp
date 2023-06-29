#include<stdio.h>



void le_dados(int *idade, char *sexo, float *salario, int *filhos, int tam_v);
float media(float *salario, int tam_v);
void idades(int *idade, int *maior, int *menor, int tam_v);
int qtdade(char *sexo, int *filhos, float *salario, int tam_v);


int main(void) //função principal
{
	const int tam = 15;
	int maior_idade=0,menor_idade=0,idade[tam],filhos[tam];
	float salario[tam];
	char sexo[tam];
	
	le_dados(idade,sexo,salario,filhos,tam); //chamar a 1ª subrotina 
	printf("%.2f ", media(salario,tam)); // salário
	idades(idade,&maior_idade,&menor_idade,tam); //idades
    printf("%d ", menor_idade); // maior idade
    printf("%d ", maior_idade); // menor idade
    printf("%d", qtdade(sexo,filhos,salario,tam));
    return 0;
}
	
void le_dados(int *idade, char *sexo, float *salario, int *filhos, int tam_v)
{
	int i;
	
	for (i=0;i<tam_v;i++)
	{
		
		scanf(" %d",&idade[i]);
		scanf(" %c",&sexo[i]);
		scanf(" %f",&salario[i]);
		scanf(" %d",&filhos[i]);	
    }		
}

    
float media(float *salario, int tam_v)
{
    int i;
	float media,soma=0;
    	
    for (i=0;i<tam_v;i++)
    	soma = soma+salario[i];

	media= soma / tam_v;
	
	return media;
	
}


void idades(int *idade, int *maior, int *menor, int tam_v)
{
	int i,idadeMaior,idadeMenor;
	
	idadeMaior=idade[0];
	idadeMenor=idade[0];
	
	for (i=1;i<tam_v;i++)
	{
		if (idade[i] > idadeMaior)
		{
		    idadeMaior=idade[i];	
		}
		
		if (idade[i] < idadeMenor)
		{
			idadeMenor=idade[i];
		}
	}
	
	*maior=idadeMaior;
	*menor=idadeMenor;
	
	
}
	
	
int qtdade(char *sexo, int *filhos, float *salario, int tam_v)
{
    
    int i,quant=0;
    
	for (i=0;i<tam_v;i++)
	{
	  if (sexo[i] == 'M' && filhos[i] == 3 && salario[i] <= 500.00)
	  {
	  	quant++;
	  }
	}
	
	return quant;		
}	
	
	
	
	

