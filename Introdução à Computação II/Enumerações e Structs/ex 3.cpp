#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

//PRESTADORA DE SERVIÇOS//



enum Trabalhos
{pintura,jardinagem,faxina,reforma_geral};

//STRUCTS
struct t // vetor
{
  int codigo;
  char descricao[50];
};


struct servicos_prestados //matriz
{
	int num;
	float valor;
	int codigo_servico;
	int codigo_cliente;	
};



//SUBROTINAS
void limpar_dados(struct t *tipos,struct servicos_prestados serv[][3],int tam,int dias,int dados);
char mostrar_menu(char op);
void cadastrar_servicos(struct t *tipos, int tam);
void prestacao_de_servicos(struct t *tipos,struct servicos_prestados serv[][3],int tam,int dias,int dados);
void dias_trab(struct servicos_prestados serv[][3],struct t *tipos,int dias,int dados);
void comparar_valores(struct t *tipos,struct servicos_prestados serv[][3],int dias,int dados);
void relatorio_geral(struct servicos_prestados serv[][3],struct t *tipos,int dias,int dados);


//MAIN
int main()
{
	setlocale(LC_ALL,"Portuguese");
	
    const int tam=4;
    const int dias=30;
    const int dados=3;
	char op;
	
	struct t tipos[tam];
	struct servicos_prestados serv[30][3];
	
	
	
	limpar_dados(tipos,serv,tam,dias,dados);
	
	do
	{
    op= mostrar_menu(op);	
    
    if (op == '1')
        cadastrar_servicos(tipos,tam);
        
    if (op == '2')
        prestacao_de_servicos(tipos,serv,tam,dias,dados);
        
    if (op == '3')
	    dias_trab(serv,tipos,dias,dados);
	    
	if (op == '4')
	    comparar_valores(tipos,serv,dias,dados);
	
	if (op == '5')
	    relatorio_geral(serv,tipos,dias,dados);
	 
	
	if (op == '6')
	{
		printf("Programa finalizado.");
		exit(0);
	}
	
	fflush(stdin);
	
   }while(op != '6');
}




void limpar_dados(struct t *tipos,struct servicos_prestados serv[][3],int tam,int dias,int dados)
{
	
	int i,j;
	
	for (i=0; i<tam; i++)
	{
		tipos[i].codigo= 0;
		tipos[i].descricao[50]= '0';
	}
	
	for (i=0; i<dias; i++)
	{
		for (j=0; j< dados; j++)
	   {
	   	serv[i][j].codigo_cliente = 0;
	   	serv[i][j].codigo_servico=0;
	   	serv[i][j].num=0;
	   	serv[i][j].valor=0;
	   }
    }
	
}

char mostrar_menu(char op)
{
	printf("\n=======||MENU DE OPÇÕES||=======\n");
	printf("1.Cadastrar os tipos de serviço\n");
	printf("2.Cadastrar os serviços prestados\n");
	printf("3.Mostrar os serviços prestados em um dia\n");
	printf("4.Mostrar os serviços prestados dentro de um intervalo\n");
	printf("5.Mostrar um relatório geral, exibindo a descrição do serviço\n");
	printf("6.Finalizar\n");
	printf("\nDigite a opção: ");
	scanf("%c",&op);
	
	return op;
}



void cadastrar_servicos(struct t *tipos, int tam)
{
	int i=0;

	printf("\n=======||ÁREA DE CADASTRO DE SERVIÇOS||========\n");
	
	for (i=0;i<tam;i++)
	{
	   printf("\n---Serviço nº %d---",i+1);
	   printf("\nDigite o código do serviço:  ");
	   scanf(" %d",&tipos[i].codigo);
	   
	   printf("\nDigite a descrição do serviço: ");
	   fflush(stdin);
	   gets(tipos[i].descricao);
	    	   
    }
		
}


void prestacao_de_servicos(struct t *tipos,struct servicos_prestados serv[][3],int tam, int dias, int dados)
{
	int i,j,k=0,achou=0,ordem,dia;
	
    printf("\n=======||CADASTRO DE SERVIÇOS PRESTADOS||========\n");
    
    	
    	printf("\nInforme o dia em que o serviço foi prestado:  ");
    	scanf("%d",&dia);
    	
    	printf("\nInforme a ordem do serviço(1-2-3): ");
    	scanf("%d",&ordem);
    	
    	printf("\nNúmero do serviço:  ");
    	scanf(" %d",&serv[dia-1][ordem-1].num);
    	
    	printf("\nValor do serviço:  ");
    	scanf(" %f",&serv[dia-1][ordem-1].valor);
    	
		do
    	{
    	   printf("\nCódigo do serviço: ");
    	   scanf(" %d",&serv[dia-1][ordem-1].codigo_servico);
    	   
    	   for (k=0;k<tam;k++)
    	   {
    	      if (serv[dia-1][ordem-1].codigo_servico == tipos[k].codigo)
		          achou=1;
	       }
            
            if (achou != 1)
                printf("\nErro.");
            
        }while(achou != 1);
    	
    	printf("\nCódigo do cliente: ");
    	scanf(" %d",&serv[dia-1][ordem-1].codigo_cliente);
   
}


void dias_trab(struct servicos_prestados serv[][3],struct t *tipos,int dias,int dados)
{
	int dia,i,j=0,achou=-1,cont=0;
	
	printf("\nInforme o dia em que se deseja saber os serviços prestados: ");
	scanf("%d",&dia);
	
	
	printf("\nServiços do dia %d:\n",dia);
	
	do
	{
	achou=-1;	
		
	for (i=0; i<4 ;i++) //PROCURAR O TIPO DE SERVIÇO
	{
	if (serv[dia-1][j].codigo_servico == tipos[i].codigo && serv[dia-1][j].codigo_servico != '0')
	    {
	     achou= i; // 1 , 2 , 3 ou 4
	    }

    }
     
     if (achou != -1)
        printf("%d:%s\n",j+1,tipos[achou].descricao);
        
     if (achou == -1)
	    cont++; // SEM SERVIÇO CADASTRADO 
    
     if (cont == 3)
       printf("\nNão há serviços cadastrados nesse dia!\n");
       
    j++;   
       
    } while ( j < 3); 
    
    
}

void comparar_valores(struct t *tipos,struct servicos_prestados serv[][3],int dias,int dados)
{
	float valorminimo,valormaximo;
	int i,j,k=0,q[4],l=0;
	
	printf("\nDigite o valor mínimo: R$:  ");
	scanf("%f",&valorminimo);
	
	printf("\nDigite o valor máximo: R$:  ");
	scanf("%f",&valormaximo);
	
	for (i=0;i<dias;i++)
	{
		for (j=0;j<dados;j++)
		{
			if (serv[i][j].valor >= valorminimo && serv[i][j].valor <= valormaximo)
			{
                q[k]= serv[i][j].codigo_servico;
                k++;
			}
		
		}	   	
	}
	
        printf("Os serviços que estão no intervalo entre R$ %.2f e R$ %.2f são: \n",valorminimo,valormaximo);
        
        for (k=0;k<4;k++)
		    {
			     if (q[l] == tipos[k].codigo)
			     {
				    printf("%s\n",tipos[k].descricao);
				    l++;
				 }
			}


}

void relatorio_geral(struct servicos_prestados serv[][3],struct t *tipos,int dias,int dados)
{
   	
   	int i,j,q,k=0,achou=0;
   	
	for (i=0;i<dias;i++)
	{
		printf("\n=-----Dia: %d--------",i+1);
		for (j=0;j<dados;j++)
		{
			if (serv[i][j].num != 0 && serv[i][j].valor != 0 && serv[i][j].codigo_servico != 0)
			{
				
			printf("\n=====================================================");	
			printf("\nServiço nº: %d",serv[i][j].num);
			printf("\nValor: R$ %.2f",serv[i][j].valor);
			printf("\nCódigo do serviço: %d",serv[i][j].codigo_servico);
			
			q= serv[i][j].codigo_servico;
			for (k=0;k<4;k++)
		    {
			     if (q == tipos[k].codigo)
				    achou=k;   
			}
		
			printf("\nDescrição: %s",tipos[achou].descricao);
			printf("\nCódigo do cliente: %d",serv[i][j].codigo_cliente);
			
			printf("\n=====================================================\n");
		    }
		}
    }
	
}
