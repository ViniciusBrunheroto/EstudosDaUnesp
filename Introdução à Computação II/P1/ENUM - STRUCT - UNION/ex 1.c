//1) Escreva programa para gerenciar os estoques de uma empresa composta de 5 lojas, vendendo 10 produtos 
//   diferentes em cada uma delas. Para cada uma das lojas são armazenadas as seguintes informações
//   (1) nome da loja, (2) informações a respeito dos itens vendidos (nome do produto, 
//   unidades disponíveis e preço unitário) e (3) o total (unidades * preço unitário) em estoque na loja. 
//   Faça um programa que, através de subprogramas adequados, efetuar as seguintes tarefas: 

//   a) preenchimento de todos os dados para a empresa; 
//   b) inclusão de novos produtos em uma das lojas;  
//   c) remoção de unidades de algum produto de alguma loja (devido a venda efetuada);  
//   d) alteração de alguma informação (nome da loja, 
//   nome do produto, unidades disponíveis, preço unitário); 
//   e) fornecimento de informações solicitadas, relativas a alguma loja ou à empresa como um todo.


	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <ctype.h>

// ------------------------------------  ENUM E STRUCTS --------------------------------------------//

enum menu{adicionar_produto=1,remocao_unidades,alterar_dados,info,sair};

struct mercadorias
{
char nome[20];
float preco_unitario;
int unidades;
};

struct empresa
{
char nome_loja[20];
struct mercadorias produtos[15];
}lojas[5];

// --------------------------------------- SUBROTINAS -------------------------------------------------//

void cadastro(struct empresa *lojas);

void incluir_p(struct empresa *lojas);

void remover_unidade(struct empresa *lojas);

void alteracao(struct empresa *lojas);

void informacao(struct empresa *lojas);


// ------------------------------------------------------------------------------------------------//

int main()
{

int op;
cadastro (lojas);



do{
	printf("Digite a opcao : \n[1] incluir produtos em uma loja\n[2]Remover unidades de um produto\n[3]Alterar informacao de alguma loja\n[4]Ver informacoes\n[5]Sair\n");
	scanf("%d",&op);
		switch(op)
		{
			case adicionar_produto:
			{
				incluir_p(lojas);
				break;
			}

			case remocao_unidades:
			{
				remover_unidade(lojas);
			}

			case alterar_dados:
			{
				alteracao(lojas);
			}

			case info:
			{
				informacao(lojas);
			}

			case sair:
			{
				system("pause");
				
			}

		}



}while(op!=sair);



}





//-----------------------------------------------------------------------------------------//






void cadastro(struct empresa *lojas)
{

	int i;

	int cont=0;
	int quantidade=0;



	do{
	system("cls");

	printf("Digite o nome da loja:\n");
	scanf("%s",&lojas[cont].nome_loja);
	fflush(stdin);
	printf("Digite a quantidade de produtos para cadastrar da loja %d\n",cont+1);
	scanf("%d",&quantidade);
	fflush(stdin);

	

	if(quantidade<10)
	{
		for(i=0;i<quantidade;i++)// i serve para percorrer até o quantidade de produtos p/ cadastrar
		{
			printf("Digite o nome do produto %d:\n",i+1);
			scanf("%s",&lojas[cont].produtos[i].nome);
			fflush(stdin);
			printf("Digite a quantidade de unidades do produto:\n");
			scanf("%d",&lojas[cont].produtos[i].unidades);
			fflush(stdin);
			printf("Digite o preco unitario do produto:\n");
			scanf("%f",&lojas[cont].produtos[i].preco_unitario);
			fflush(stdin);
		}
	}
	lojas[cont].produtos[quantidade].unidades = -1;
	cont++;
	
	}while(cont<5);// enquanto cont < 5 para cadastrar todas as 5 lojas




}




//---------------------------------------------------------------------------------------------//




	void incluir_p(struct empresa *lojas)
	{

		system("cls");
		int i,aux;
		int lojasx;
		printf("Digite a loja que deseja incluir produtos:[0][1][2][3][4]\n");
		scanf("%d",&lojasx);
		fflush(stdin);

		for(i=0;i<15;i++)
		{
			if(lojas[lojasx].produtos[i].unidades==-1)
			{
				aux=i;
				lojas[lojasx].produtos[i+1].unidades=-1;
				break;
			}
		}

		printf("Digite o nome do novo produto:\n");
		scanf("%s",&lojas[lojasx].produtos[aux].nome);
		fflush(stdin);
		printf("Digite a quantidade de unidades do produto:\n");
		scanf("%d",&lojas[lojasx].produtos[aux].unidades);
		fflush(stdin);
		printf("Digite o preco do produto:\n");
		scanf("%f",&lojas[lojasx].produtos[aux].preco_unitario);
		fflush(stdin);

	}




// ------------------------------------------------------------------------------------------------//




void remover_unidade(struct empresa *lojas)
{
	int vendidos;
	int op,i,iescolhido;
	system("cls");
	printf("Digite a loja para ver seus produtos:[0][1][2][3][4]\n");
	scanf("%d",&op);

	for(i=0;i<15;i++)
	{
		if(lojas[op].produtos[i].unidades!=-1)
		{
			break;
		}

		else
		{
			printf("Nome do produto:%s ///i correspondente: %d\n",lojas[op].produtos[i].nome,i);
			printf("Unidades do produto:%d\n",lojas[op].produtos[i].unidades);
		}

	}

	printf("Digite o i correspondente do produto para remover unidade desse produto:\n");
	scanf("%d",&iescolhido);
	printf("Digite quantas unidades foram vendidas:\n");
	scanf("%d",&vendidos);

	lojas[op].produtos[iescolhido].unidades = lojas[op].produtos[iescolhido].unidades-vendidos;



}

// ------------------------------------------------------------------------------------------------//






void alteracao(struct empresa *lojas)
{

		int op,escolha,i,novoi,novounidade;
		char novo_nomeloja[20];
		char novo_nomeproduto[20];
		float novopunitario;
		system("cls");

		printf("Digite a loja para ver alterar dados:[0][1][2][3][4]\n");
		scanf("%d",&op);
		fflush(stdin);
		printf("%s",lojas[op].nome_loja);

		for(i=0;i<15;i++)
			{
				if(lojas[op].produtos[i].unidades!=-1)
				{
					break;
				}

				else
				{

					printf("Nome do produto:%s ///i correspondente: %d\n",lojas[op].produtos[i].nome,i);
					printf("Unidades do produto:%d\n",lojas[op].produtos[i].unidades);
					printf("Preco unitario do produto:%f\n",lojas[op].produtos[i].preco_unitario);
				}

			}

		printf("Deseja alterar nome da loja[1],nome do produto[2],unidades disponiveis[3],preco unitario[4]:\n");
		scanf("%d",&escolha);
		if(escolha==2||escolha==3||escolha==4)
		{
			printf("Digite o valor de i para alterar o produto especifico:\n");
			scanf("%d",&novoi);
			fflush(stdin);
		}
		

		if(escolha==1)
		{
			printf("Digite o novo nome da loja:\n");
			scanf("%s",&novo_nomeloja);
			fflush(stdin);
			strcpy(lojas[op].nome_loja,novo_nomeloja);
			
		}

		if(escolha==2)
		{
			printf("Digite o novo nome do produto:\n");
			scanf("%s",&novo_nomeproduto);
			fflush(stdin);
			strcpy(lojas[op].produtos[novoi].nome,novo_nomeproduto);
			
		}

		if(escolha==3)
		{
			printf("Digite o numero de unidades disponiveis:\n");
			scanf("%d",&novounidade);
			fflush(stdin);
			lojas[op].produtos[novoi].unidades = novounidade;

		}

		if(escolha==4)
		{
			printf("Digite o novo preco unitario:\n");
			scanf("%f",&novopunitario);
			fflush(stdin);
			lojas[op].produtos[novoi].preco_unitario=novopunitario;
		}


}





// ------------------------------------------------------------------------------------------------//


void informacao(struct empresa *lojas)
{
	int op;
	int i;
	printf("Digite a loja para ver informacoes:[0][1][2][3][4]\n");
	scanf("%d",&op);

	for(i=0;i<15;i++)
			{
				if(lojas[op].produtos[i].unidades!=-1)
				{
					break;
				}

				else
				{

					printf("Nome do produto:%s ///i correspondente: %d\n",lojas[op].produtos[i].nome,i);
					printf("Unidades do produto:%d\n",lojas[op].produtos[i].unidades);
					printf("Preco unitario do produto:%f\n",lojas[op].produtos[i].preco_unitario);
				}

			}

}


// ------------------------------------------------------------------------------------------------//