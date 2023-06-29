#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<windows.h>


struct Cadastro
{
	
	int num_matricula;
	char nome[50];
	float p1;
	float p2;	
};


//protótipos
int menu(int opcao);
void incluir_dados(struct Cadastro *dados, FILE *arq,int tam);
void ler_matricula(FILE *arq,int tam);
void alterar_nota(FILE *arq,struct Cadastro *dados,int tam);
void excluir_matricula(FILE *arq,struct Cadastro *dados,int tam);


int main()
{
	
	
	setlocale(LC_ALL,"Portuguese");
	
	const int tam= 10; // número de alunos
	int opcao=0,op2=0;
	struct Cadastro dados[10];
	int num1,num2,num3,num4;
	
	FILE *arq;
	
	do
	{
		
	opcao=menu(opcao);	
		
	if (opcao == 1)
	    incluir_dados(dados,arq,tam);
	
    if (opcao == 2)
	    ler_matricula(arq,tam);
		
	if (opcao == 3)
	    alterar_nota(arq,dados,tam);
	    
	if (opcao == 4)
	    excluir_matricula(arq,dados,tam);    
					
	if (opcao == 5)
	
	{ 
	   printf("Programa finalizado.");
	   exit(1);
	}				
    
    }while (opcao != 5);

	
}


//SUBROTINA: MENU DE OPÇÕES
int menu(int opcao)
{
	fflush(stdin);
	printf("\n||||||MENU DE OPÇÕES|||||");
	printf("\n (1) para incluir dados");
	printf("\n (2) para ler a matrícula");
    printf("\n (3) para alterar notas");
    printf("\n (4) para excluir alguma matrícula");
	printf("\n (5) para sair do programa");	
	printf("\nDigite a opção:  ");
	scanf(" %d",&opcao);
	
	return opcao;
		
}


//SUBROTINA 1:INCLUIR DADOS
void incluir_dados(struct Cadastro *dados,FILE *arq,int tam)
{
   int i;
	
	if((arq=fopen("cadastro.txt","w"))==NULL)
	{
	   printf("Não é possível abrir o arquivo\n");
	   exit(1);	
	}
	
	printf("\n|||||ÁREA DE CADASTRO DE ALUNOS|||||");
	
	    for (i=0;i<tam;i++)
	    {
		
		printf("\n------ALUNO Nº %d------",i+1);
		
		printf("\nDigite o número da matrícula:  ");
		scanf(" %d", &dados[i].num_matricula);
		fflush(stdin);
		
		printf("\nDigite o nome do aluno:   ");
		fflush(stdin);
		gets(dados[i].nome);
		
	    printf("\nNota prova 1:  ");
	    fflush(stdin);
	    scanf("%f",&dados[i].p1);
	    
	    printf("\nNota prova 2:  ");
	    fflush(stdin);
	    scanf("%f",&dados[i].p2);
	    
	    fprintf(arq,"%d %s %f %f\n",dados[i].num_matricula,dados[i].nome,dados[i].p1,dados[i].p2);
	    }
	    
	    fclose(arq);
	
}


//SUBROTINA 2: PROCURAR DADOS NO ARQUIVO
void ler_matricula(FILE *arq,int tam) //passando apenas o ARQUIVO por parâmetro
{
	int i=0,numero=0,achou=0,k=0,vez=0;
	struct Cadastro dados[tam];
	
	if((arq=fopen("cadastro.txt","r"))==NULL)
	{
	   puts("Não é possível abrir o arquivo\n");
	   exit(1);	
	}

	printf("Digite a matrícula(1-10):  ");
	scanf("%d",&numero);
	
	if (numero > tam)
	    printf("\nNúmero fora dos limites de cadastro.\n");
		
    while((fscanf(arq,"%d %s %f %f\n",&dados[i].num_matricula,&dados[i].nome,
	&dados[i].p1,&dados[i].p2)!= EOF) && (achou != 1))
	{	
	  if (numero == dados[i].num_matricula) //PROCURAR O INDIVÍDUO CADASTRADO
	  {
	  	printf("\nAluno: %s",dados[i].nome);
	  	printf("\nNOTA P1: %.2f",dados[i].p1);
	  	printf("\nNOTA P2: %.2f",dados[i].p2);
	  	printf("\nA média desse aluno é: %.2f",(dados[i].p1+dados[i].p2)/2);
	  	printf("\n");
	  	achou=1;
	  }
	     
	   if (((dados[i].p1 <= 0) || (dados[i].p1 > tam) || (dados[i].p2 <= 0) || (dados[i].p2 > tam)) && (vez == 0) && (numero <= tam)) 
	   {
	   	printf("\nAluno não cadastrado\n");
	   	vez=1;
	   }   
	   
	i++;  
	   
    } 
	    
    fclose(arq);
}


//SUBROTINA 3: ALTERAR NOTA
void alterar_nota(FILE *arq,struct Cadastro *dados,int tam) // reescrevendo o arquivo
{
	int i=0,num=0,op=0,pos=0,achou=0;
	
	if((arq=fopen("cadastro.txt","w"))==NULL)
	{
	   puts("Não é possível abrir o arquivo\n");
	   exit(1);	
	}
	
	printf("Deseja mudar as notas de que matrícula?");
	scanf("%d",&num);
	
	if (num != 1)
	{
	    for (i=0;i<num-1;i++) //preencher os espaços antes do slot escolhido
	      {
		    fprintf(arq,"%d %s %f %f\n",dados[i].num_matricula,dados[i].nome,dados[i].p1,dados[i].p2);
	      }
    }
	
	printf("Digite a nota da P1: ");
	scanf("%f",&dados[i].p1);
	printf("Digite a nota da P2: ");
	scanf("%f",&dados[i].p2); 
	
	fprintf(arq,"%d %s %f %f\n",dados[i].num_matricula,dados[i].nome,dados[i].p1,dados[i].p2); 
	 
	if (num != 1 && num < tam)
	{
	 for (i=num;i<tam;i++) //preencher os espaços depois do slot escolhido
	      {
	      	fprintf(arq,"%d %s %f %f\n",dados[i].num_matricula,dados[i].nome,dados[i].p1,dados[i].p2);
	      }
	
    }
	fclose(arq);	
}


//SUBROTINA 4: EXCLUIR MATRICULA
void excluir_matricula(FILE *arq,struct Cadastro *dados,int tam) //reescrevendo o arquivo
{
	int i=0,j=0,k=0,num=0,aux;
	char valor[50];
	float aux3;
	
	if((arq=fopen("cadastro.txt","w"))==NULL)
	{
	   puts("Não é possível abrir o arquivo\n");
	   exit(1);	
	}
	
	
	printf("Deseja excluir que matrícula?");
	scanf("%d",&num);
	
	if (num != 1)
	{
	    for (i=0;i<num-1;i++) //preencher os espaços antes do slot escolhido
	      {
		    fprintf(arq,"%d %s %f %f\n",dados[i].num_matricula,dados[i].nome,dados[i].p1,dados[i].p2);
	      }
    }
	
      if (num != tam)
      {
	    for (k=num-1;k<tam-1;k++)
	    { 
	  	dados[k].num_matricula= dados[k+1].num_matricula;
	
	   	strcpy(dados[k].nome,dados[k+1].nome);
	   	
	  	dados[k].p1= dados[k+1].p1;
	
	  	dados[k].p2= dados[k+1].p2;
	  	
	  	fprintf(arq,"%d %s %f %f\n",dados[k].num_matricula,dados[k].nome,dados[k].p1,dados[k].p2);
	  	
	   }
      }
    
    fclose(arq);
	
}
