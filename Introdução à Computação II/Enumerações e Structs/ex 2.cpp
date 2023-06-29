#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>


struct CadastroContas
{
	int num;
	char nome[50];
	float saldo;
};

void limpar_dados(struct CadastroContas *cadastro, int tam);
char ler_dados(struct CadastroContas *cadastro,char op);
void cadastrar_contas(struct CadastroContas *cadastro,int tam);
void visualizar_contas(struct CadastroContas *cadastro, int tam);
void excluir_contas(struct CadastroContas *cadastro,int tam);


//MAIN
int main()
{
	setlocale(LC_ALL,"Portuguese");
	
	const int tam = 15;
	struct CadastroContas cadastro[tam];
	char op;
	
	limpar_dados(cadastro,tam);
	do
	{
	   op=ler_dados(cadastro,op);
	   
	    if (op != '1' && op != '2' && op != '3' && op != '4')
	    {
	       printf("Opcao invalida.\n");
	       printf("\n===================|===========|====================\n");
	    }
	    fflush(stdin);
	
	    if (op == '1')
	       cadastrar_contas(cadastro,tam);
	   
	    if (op == '2')
	       visualizar_contas(cadastro,tam);
	    
	    if (op == '3')
	        excluir_contas(cadastro,tam);
	
	    if (op == '4')
	    {
		printf("Programa finalizado.\n");
		exit(0);
	    }
	       
    } while (op != '4');
}


void limpar_dados(struct CadastroContas *cadastro, int tam)
{
	int i;
	
	for (i=0;i<tam-1;i++)
	{
	  cadastro[i].num=0;
	  cadastro[i].saldo=0;		
	}
}


char ler_dados(struct CadastroContas *cadastro, char op)
{
	printf("\n\n\n=======||Menu de opcoes: ||===========\n");
	printf("1-Cadastrar contas\n");
	printf("2-Visualizar contas do cliente\n");
	printf("3-Excluir conta com menor saldo\n");
    printf("4-Sair\n");
    printf("Digite a opcao: ");
    scanf(" %c",&op);

    
    return op;
}


//OPÇÃO 1
void cadastrar_contas(struct CadastroContas *cadastro,int tam)
{
	int achou=0,ndaconta,i=0,posi=0,vez=0;
	float saldocliente;
	char nomedocliente[50];

	printf("\nDigite o numero da conta:  ");
	scanf(" %d",&ndaconta);
	
	for (i=0;i<tam;i++)
	{
		if (ndaconta == cadastro[i].num)
			achou=1;
	}
	
	if (achou==1)
       printf("Conta já cadastrada!\n");
    else
        {
        posi=0;
        i=0;
        
        while ( i < tam)
        {
    	    if (cadastro[i].num == 0)
    	    {
    	    posi= i;
    	    break;
    	    }
    	      
          i++;
        }
        
	     if (posi == 0 && vez > 0)
	     {
         printf("\nImpossivel cadastrar novas contas\n");
         }
         else
	        {
			 fflush(stdin);	
	         printf("Digite nome:  ");
	         gets(nomedocliente);
	
	         
	         printf("Digite o saldo: ");
	         scanf("%f",&saldocliente);
	         
	         strcpy(cadastro[posi].nome,nomedocliente);
	         cadastro[posi].saldo=saldocliente;
	         cadastro[posi].num= ndaconta;
	   
	   
	         printf("Conta cadastrada com sucesso!");
			 

            vez++;
	        }   
    }
   
}



//OPÇÃO 2
void visualizar_contas(struct CadastroContas *cadastro, int tam)
{
	char nomCliente[50];
	int achou=0,i,var=0;
	
	printf("Digite o nome do cliente: ");
	gets(nomCliente);

	
	for (i=0;i<15;i++)
	{
		var= strcmp(cadastro[i].nome,nomCliente);
		if (var == 0)
		{
			break;
		}
	}
	
	if (var == 0)
	{
        printf("Numero da conta:%d \nSaldo: R$%.2f\n",cadastro[i].num,cadastro[i].saldo);
		achou= 1;
	}
	
	if (achou==0)
	{
		printf("Nao existe conta para esse cliente!\n");
    }
}


//OPÇÃO 3
void excluir_contas(struct CadastroContas *cadastro,int tam)
{
	int i=0,achou=0,posi=0;
	float saldomenor=999999.9;
	
	while (i < tam)
	{
	   if (cadastro[i].num == 0)
	   {
	 	i=tam;
	   }else
	        {
	 	    achou=1;
	 	    if (cadastro[i].saldo < saldomenor)
	 	     {
	 		 saldomenor= cadastro[i].saldo;
	 		 posi=i;
	  	     }
	   	     i= i+1;    
	        }
    }
    
	     if (achou==0)
	     {
	     	printf("Sem conta.\n");
		 }else
		      {
		 	   i = posi;
		 	   while (i < tam-1)
		 	   {
		 	     if (cadastro[i+1].num != 0)
			     {  
			      cadastro[i].num = cadastro[i+1].num;
			      strcpy(cadastro[i].nome,cadastro[i+1].nome);
			      cadastro[i].saldo = cadastro[i+1].saldo;
			      i=i+1;
			      } else
			         {
			         	cadastro[i].num = 0;
			         	cadastro[i].nome[0] ='\0';
			         	cadastro[i].saldo=0;
			         	i=14;
					 }
			}
		printf("Conta excluída com sucesso!");	
		 }	
}
