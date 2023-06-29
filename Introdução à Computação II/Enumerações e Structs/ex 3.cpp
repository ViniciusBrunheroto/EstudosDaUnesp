#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

//PRESTADORA DE SERVI�OS//



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
	printf("\n=======||MENU DE OP��ES||=======\n");
	printf("1.Cadastrar os tipos de servi�o\n");
	printf("2.Cadastrar os servi�os prestados\n");
	printf("3.Mostrar os servi�os prestados em um dia\n");
	printf("4.Mostrar os servi�os prestados dentro de um intervalo\n");
	printf("5.Mostrar um relat�rio geral, exibindo a descri��o do servi�o\n");
	printf("6.Finalizar\n");
	printf("\nDigite a op��o: ");
	scanf("%c",&op);
	
	return op;
}



void cadastrar_servicos(struct t *tipos, int tam)
{
	int i=0;

	printf("\n=======||�REA DE CADASTRO DE SERVI�OS||========\n");
	
	for (i=0;i<tam;i++)
	{
	   printf("\n---Servi�o n� %d---",i+1);
	   printf("\nDigite o c�digo do servi�o:  ");
	   scanf(" %d",&tipos[i].codigo);
	   
	   printf("\nDigite a descri��o do servi�o: ");
	   fflush(stdin);
	   gets(tipos[i].descricao);
	    	   
    }
		
}


void prestacao_de_servicos(struct t *tipos,struct servicos_prestados serv[][3],int tam, int dias, int dados)
{
	int i,j,k=0,achou=0,ordem,dia;
	
    printf("\n=======||CADASTRO DE SERVI�OS PRESTADOS||========\n");
    
    	
    	printf("\nInforme o dia em que o servi�o foi prestado:  ");
    	scanf("%d",&dia);
    	
    	printf("\nInforme a ordem do servi�o(1-2-3): ");
    	scanf("%d",&ordem);
    	
    	printf("\nN�mero do servi�o:  ");
    	scanf(" %d",&serv[dia-1][ordem-1].num);
    	
    	printf("\nValor do servi�o:  ");
    	scanf(" %f",&serv[dia-1][ordem-1].valor);
    	
		do
    	{
    	   printf("\nC�digo do servi�o: ");
    	   scanf(" %d",&serv[dia-1][ordem-1].codigo_servico);
    	   
    	   for (k=0;k<tam;k++)
    	   {
    	      if (serv[dia-1][ordem-1].codigo_servico == tipos[k].codigo)
		          achou=1;
	       }
            
            if (achou != 1)
                printf("\nErro.");
            
        }while(achou != 1);
    	
    	printf("\nC�digo do cliente: ");
    	scanf(" %d",&serv[dia-1][ordem-1].codigo_cliente);
   
}


void dias_trab(struct servicos_prestados serv[][3],struct t *tipos,int dias,int dados)
{
	int dia,i,j=0,achou=-1,cont=0;
	
	printf("\nInforme o dia em que se deseja saber os servi�os prestados: ");
	scanf("%d",&dia);
	
	
	printf("\nServi�os do dia %d:\n",dia);
	
	do
	{
	achou=-1;	
		
	for (i=0; i<4 ;i++) //PROCURAR O TIPO DE SERVI�O
	{
	if (serv[dia-1][j].codigo_servico == tipos[i].codigo && serv[dia-1][j].codigo_servico != '0')
	    {
	     achou= i; // 1 , 2 , 3 ou 4
	    }

    }
     
     if (achou != -1)
        printf("%d:%s\n",j+1,tipos[achou].descricao);
        
     if (achou == -1)
	    cont++; // SEM SERVI�O CADASTRADO 
    
     if (cont == 3)
       printf("\nN�o h� servi�os cadastrados nesse dia!\n");
       
    j++;   
       
    } while ( j < 3); 
    
    
}

void comparar_valores(struct t *tipos,struct servicos_prestados serv[][3],int dias,int dados)
{
	float valorminimo,valormaximo;
	int i,j,k=0,q[4],l=0;
	
	printf("\nDigite o valor m�nimo: R$:  ");
	scanf("%f",&valorminimo);
	
	printf("\nDigite o valor m�ximo: R$:  ");
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
	
        printf("Os servi�os que est�o no intervalo entre R$ %.2f e R$ %.2f s�o: \n",valorminimo,valormaximo);
        
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
			printf("\nServi�o n�: %d",serv[i][j].num);
			printf("\nValor: R$ %.2f",serv[i][j].valor);
			printf("\nC�digo do servi�o: %d",serv[i][j].codigo_servico);
			
			q= serv[i][j].codigo_servico;
			for (k=0;k<4;k++)
		    {
			     if (q == tipos[k].codigo)
				    achou=k;   
			}
		
			printf("\nDescri��o: %s",tipos[achou].descricao);
			printf("\nC�digo do cliente: %d",serv[i][j].codigo_cliente);
			
			printf("\n=====================================================\n");
		    }
		}
    }
	
}
