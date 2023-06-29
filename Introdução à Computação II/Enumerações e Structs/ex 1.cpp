#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


//1ª parte: cadastro
//2ª parte: digitar código e verificar
//3ª parte: imprimir nome da profissão e descrição da profissão


struct tipo_cadastro
{
	int codigo; // números
	char nome[50]; // caracteres
	char profissao[50];	// caracteres
}; 


//Subrotinas
int preencher_cadastro(struct tipo_cadastro *cadastro , int cont, int tam);
int digitar_codigo(struct tipo_cadastro *cadastro, int cont);
void imprimir_dados(struct tipo_cadastro *cadastro, int codigodigitado);


//MAIN
int main()
{
	const int tam = 5;
	int codigodigitado=0,cont=0,contador=0;
	struct tipo_cadastro cadastro[5]; // para 5 profissões
	
    contador=preencher_cadastro(cadastro,cont,tam);
    codigodigitado=digitar_codigo(cadastro,contador);
    imprimir_dados(cadastro,codigodigitado);

}


//CADASTRO
int preencher_cadastro(struct tipo_cadastro *cadastro, int cont, int tam)
{
	cont=0;
    int i;
    printf("==========CADASTRO============\n");
    for (i=0;i<tam;i++)	
    {	
		printf("Digite o codigo: ");
		scanf("%d", &cadastro[i].codigo);
    	
    	if (cadastro[i].codigo == -1 || i > 5)
    	{
    	   break;
        }
		
		fflush(stdin);
	
    	printf("Digite o nome da profissao: ");
    	gets(cadastro[i].nome);
    	
    	printf("Digite a descricao da profissao: ");
    	gets(cadastro[i].profissao);
    	
    	cont++;
    	
    	fflush(stdin);
    }
        
    
	 return cont;   
	}



int digitar_codigo(struct tipo_cadastro *cadastro,int contador)
{
	int codigodigit,pos,achou,i;
	
	
	printf("==========AREA DO USUARIO==========\n");
	printf("Digite um codigo: ");
	scanf("%d",&codigodigit);
	
	achou=0;
	for (i=0;i<contador;i++)
	{
		if (codigodigit == cadastro[i].codigo)
		{
		   achou=1;
		   pos=i;
		   break;
		}
	}
	
	if (achou!=1)
	{
     printf("Codigo inexistente!");
	}
	return pos;
}


void imprimir_dados(struct tipo_cadastro *cadastro, int codigodigitado)
{
	int num;
	num=codigodigitado;
	printf("\n");
	printf("Nome da profissao: %s\n",cadastro[num].nome);
	printf("Descricao da profissao: %s\n",cadastro[num].profissao);
}
