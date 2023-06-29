#include<stdio.h>
#include<stdlib.h>
#include<locale.h>


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
void alterar_nota(struct Cadastro *dados,FILE *arq,int tam);



int main(void)
{
	setlocale(LC_ALL,"Portuguese");
	
	const int tam= 2; // número de alunos
	int opcao=0,op2=0;
	struct Cadastro dados[2];
	int num1,num2,num3,num4;
	
	FILE *arq;
	
    num1= sizeof(dados[1].nome);
    num2= sizeof(dados[1].num_matricula);
    num3= sizeof(dados[1].p1);
    num4= sizeof(dados[1].p2);
	
	do
	{
	
	opcao=menu(opcao);
	if (opcao == 1)
	    incluir_dados(dados,arq,tam);
	
    if (opcao == 2)
	    ler_matricula(arq,tam);
		
	if (opcao == 3)
	    alterar_nota(dados,arq,tam);
		
	if (opcao == 4)
	{
		printf("Programa finalizado.");
		exit(1);
	}			
    
    }while (opcao != 4);
    
}



//SUBROTINA 1: MENU DE OPÇÕES
int menu(int opcao)
{
	fflush(stdin);
	printf("\n||||||MENU DE OPÇÕES|||||");
	printf("\n (1) para incluir dados");
	printf("\n (2) para ler a matrícula");
    printf("\n (3) para alterar notas");
	printf("\n (4) para sair do programa");	
	printf("\nDigite a opção:  ");
	scanf(" %d",&opcao);
	
	return opcao;
	
}


//SUBROTINA 2:INCLUIR DADOS
void incluir_dados(struct Cadastro *dados,FILE *arq,int tam)
{
	int i;
	
	if((arq=fopen("cadastro.txt","w"))==NULL)
	{
	   puts("Não é possível abrir o arquivo\n");
	   exit(1);	
	}
	
	printf("\n|||||ÁREA DE CADASTRO DE ALUNOS|||||");
	
	for (i=0;i<2;i++)
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
	    scanf(" %f",&dados[i].p1);
	    
	    printf("\nNota prova 2:  ");
	    fflush(stdin);
	    scanf(" %f",&dados[i].p2);
	
	}
	
	    fwrite(dados,sizeof(struct Cadastro),2,arq);
	    fclose(arq);
	
}


//SUBROTINA 3: PROCURAR DADOS NO ARQUIVO
void ler_matricula(FILE *arq,int tam) //passando apenas o ARQUIVO por parâmetro
{
	int i,num;
	float media=0,n1=0,n2=0;
	struct Cadastro dados;
	
	if((arq=fopen("cadastro.txt","r"))==NULL)
	{
	   puts("Não é possível abrir o arquivo\n");
	   exit(1);	
	}
	
	printf("Digite a matrícula(1-10):  ");
	scanf("%d",&num);

	fseek(arq, (num-1)*sizeof(struct Cadastro),0);	
	fread(&dados,sizeof(struct Cadastro),1,arq);
	
	printf("\nNome: %s",dados.nome);
	printf("\nNOTA P1: %.2f",dados.p1);
	printf("\nNOTA P2: %.2f",dados.p2);
	media = ((dados.p1+ dados.p2) / 2);
	printf("\nA média é: %.2f",media);
    fclose(arq);
}


//SUBROTINA 4: ALTERAR NOTA
void alterar_nota(struct Cadastro *dados, FILE *arq,int tam) // passando apenas o ARQUIVO por parâmetro
{
	int i=0,num=0,op=0,posicao=0;
	float nota1,nota2;
	struct Cadastro reg;

	if((arq=fopen("cadastro.txt","r+"))==NULL)
	{
	   puts("Não é possível abrir o arquivo\n");
	   exit(1);	
	}

	printf("\nDigite o número da matrícula:  ");
	scanf("%d",&num);

	fseek(arq,(num-1)*sizeof(struct Cadastro), 0);
	fread(&reg, sizeof(struct Cadastro), 1, arq);	
	
	printf("Nova nota da p1:");
	scanf("%f",&reg.p1);
	printf("Nova nota da p2:");
	scanf("%f",&reg.p2);
	
	fseek(arq,(num-1)*sizeof(struct Cadastro), 0);
	fwrite(&reg, sizeof(struct Cadastro), 1, arq);	

    fclose(arq);
    
}
