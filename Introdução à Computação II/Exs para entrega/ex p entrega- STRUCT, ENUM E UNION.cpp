#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>
#include<windows.h>


//CADASTRO DE LIVROS NO ACERVO



//ser� usada para os cases
enum Generos {livros= 'L',teses= 'T',periodicos= 'P'};




//STRUCTS DOS GENEROS LITERARIOS
struct Livros
{
	char autor[50];
	char titulo[50];
	int data;
	char editora[50];
	char cidade[50];
};


struct Teses
{
	char titulo[50];
	char autor[50];
	int data;
	char universidade[50];
	char programa[50];
	char modalidade[50];
	char orientador[50];
};


struct Periodicos
{
	char titulo[50];
	int volume[50];
	char mes[5];
	char ano[5];
	char editora[50];
	char cidade[50];
	int numero_pag;
};


union Tipos
{
	struct Livros L;
	struct Teses T;
	struct Periodicos P;
};

struct Cadastro
{
	union Tipos Tipo;
	enum  Generos Genero;
};


//PROT�TIPOS
char menu_de_opcoes(char op);
void escolher_opcao(char op,struct Cadastro *c,int *i);
void verificar_relatorio(struct Cadastro *c);

//MAIN
int main()
{
	setlocale(LC_ALL,"Portuguese");
	char op,resp;
    int i=0,k=0,tam,valor=0;
    
	printf("=========||Bem vindo ao sistema de cadastro da biblioteca!||============\n\n");
	printf("Quantas obras ser�o catalogadas?\n");
	scanf("%d",&tam);
	
	struct Cadastro c[tam];

	do
	{
	   op=menu_de_opcoes(op);
	   
	   escolher_opcao(op,c,&i);
	   k++;
   }while (k < tam);
   
        
		
		printf("Deseja verificar os registros?");
    	scanf("%c",&resp);
    	
    while (resp == 'S')
    {
    	if (resp == 'S')
    	    verificar_relatorio(c);
    	    
    	printf("Deseja continuar verificando os registros?");
    	scanf(" %c",&resp);
	} 
   
    printf("Programa finalizado.");
        exit(0);
}



//SUBROTINA 1: MENU DE OP��ES
char menu_de_opcoes(char op)
{
	int achou=0;
	
	do
	{
	fflush(stdin);
	printf("\n\n-------||MENU DE OP��ES||-------- \n");
	printf("L para cadastrar livros\n");
	printf("T para cadastrar teses\n");
	printf("P para cadastrar peri�dicos\n");
	printf("Digite a op��o:  ");
	scanf(" %c",&op);
	
	if (op == 'L' || op == 'T' || op == 'P')
	{
	    achou= 1;
    }else printf("C�digo inv�lido. Tente novamente: \n");
    }while (achou != 1);
    
	if (achou == 1)
	    return op;
	    
}


//SUBROTINA 2: CADASTRO
void escolher_opcao(char op, struct Cadastro *c, int *i)
{
	char opcao;
	
	switch(op)
	{
		case livros:
			{
				printf("\nVoc� entrou na categoria LIVROS\n");
				printf("Digite os seguintes dados:\n");
				
				printf("Autor: ");
				fflush(stdin);
				gets(c[*i].Tipo.L.autor);
				
				printf("\nT�tulo: ");
				fflush(stdin);
				gets(c[*i].Tipo.L.titulo);
				
				printf("\nData: ");
				scanf("%d",&c[*i].Tipo.L.data);
				
			    printf("\nEditora: ");
			    fflush(stdin);
			    gets(c[*i].Tipo.L.editora);
			    
			    printf("\nRegistro conclu�do com sucesso!\n");
				
			    *i= *i+1;
			    
			    break;
			}
				
			
			case teses:
			{
				printf("Voc� entrou na categoria TESES\n");
				printf("\nDigite os seguintes dados:");
				
				printf("\nAutor: ");
				fflush(stdin);
				gets(c[*i].Tipo.T.autor);
				
				printf("\nT�tulo: ");
				fflush(stdin);
				gets(c[*i].Tipo.T.titulo);
				
				printf("\nData: ");
				scanf("%d",&c[*i].Tipo.T.data);
				
			    printf("\nUniversidade: ");
			    fflush(stdin);
			    gets(c[*i].Tipo.T.universidade);
				
				printf("\nPrograma de P�s-Gradua��o: ");
				fflush(stdin);
				gets(c[*i].Tipo.T.programa);
				
				printf("\nModalidade: ");	
				fflush(stdin);   
				gets(c[*i].Tipo.T.modalidade);
			      
				printf("\nOrientador: ");
				fflush(stdin);
				gets(c[*i].Tipo.T.orientador);
				
				printf("\nRegistro conclu�do com sucesso!\n");
			
				*i=*i+1;
				break;
			}
		
		
		case periodicos:
			{
				printf("Voc� entrou na categoria PERI�DICOS\n");
				printf("Digite os seguintes dados:\n");
				
				printf("T�tulo: ");
				fflush(stdin);
				gets(c[*i].Tipo.P.titulo);
				
				printf("\nVolume: ");
				scanf("%d",c[*i].Tipo.P.volume);
				
				printf("\nM�s: ");
				scanf("%d",&c[*i].Tipo.P.mes);
				
			    printf("\nAno: ");
			    scanf("%d",&c[*i].Tipo.P.ano);
			    
			    printf("\nEditora: ");
			    fflush(stdin);
			    gets(c[*i].Tipo.P.editora);
			    
			    printf("\nCidade: ");
			    fflush(stdin);
			    gets(c[*i].Tipo.P.cidade);
			    
			    printf("\nN�mero de p�ginas: ");
			    scanf("%d",&c[*i].Tipo.P.numero_pag);
				
				printf("\nRegistro conclu�do com sucesso!\n");
				
				*i=*i+1;
				break;
			}
		
	}	
}


//SUBROTINA 3: VERIFICAR O CADASTRO
void verificar_relatorio(struct Cadastro *c)
{
	int j=0,num=0;
	char tipo;
	
	printf("\n==========||VERIFICA��O DE REGISTRO||==========\n");
	printf("Voc� deseja ver qual ficha?\n");
	scanf("%d",&num);
	
	printf("� referente � qual g�nero?(L-T-P)?\n");
	scanf(" %c",&tipo);
	
	switch(tipo)
	{
		case livros:
			{   
			    printf("Verificando...\n");
			    Sleep(5000); //em ms
				printf("\n-->FICHA N� %d\n",num);
			    printf("Autor: %s",c[num].Tipo.L.autor);
				printf("\nT�tulo: %s",c[num].Tipo.L.titulo);
				printf("\nData: %d",c[num].Tipo.L.data);
		        printf("\nEditora: %s",c[num].Tipo.L.editora);
		        printf("\nVerifica��o conclu�da!\n");
		        break;
			}
			
		case teses:
			{
				printf("Verificando...\n");
			    Sleep(5000); //em ms
				printf("\n-->FICHA N� %d\n",num);
				printf("Autor: %s",c[num].Tipo.T.autor);
				printf("\nT�tulo: %s",c[num].Tipo.T.titulo);
				printf("\nData: %d",c[num].Tipo.T.data);
			    printf("\nUniversidade: %s",c[num].Tipo.T.universidade);
				printf("\nPrograma de P�s-Gradua��o: %s",c[num].Tipo.T.programa);
				printf("\nModalidade: %s",c[num].Tipo.T.modalidade);
				printf("\nOrientador: %s",c[num].Tipo.T.orientador);
				printf("\nVerifica��o conclu�da!\n");
				break;
			}
		
		
		case periodicos:
			{				
			    printf("Verificando...\n");
			    Sleep(5000); //em ms
			    printf("\n-->FICHA N� %d",num);
				printf("T�tulo: %s",c[num].Tipo.P.titulo);
				printf("\nVolume: %d",c[num].Tipo.P.volume);
				printf("\nM�s: %d",c[num].Tipo.P.mes);
			    printf("\nAno: %d",c[num].Tipo.P.ano);
			    printf("\nEditora: %s",c[num].Tipo.P.editora);
			    printf("\nCidade: %s",c[num].Tipo.P.cidade);
			    printf("\nN�mero de p�ginas: %d",c[num].Tipo.P.numero_pag);
			    printf("\nVerifica��o conclu�da!\n");
			    break;
			}
		
	}
}


