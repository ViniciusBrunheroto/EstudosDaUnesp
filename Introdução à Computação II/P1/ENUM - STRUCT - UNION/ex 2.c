#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>


struct cadastro{

char nome[20];
int codigo;
float salario_bruto;

};

void cadastrar(struct cadastro *empresa,int n_funcionarios);

void mostrar(struct cadastro *empresa,int n_funcionarios);

int main()
{

	int n_funcionarios;
	char escolha;
	setlocale(LC_ALL,"");

	printf("Digite o numero de funcionarios para cadastrar:\n");
	scanf("%d",&n_funcionarios);
	fflush(stdin);

	struct cadastro empresa[n_funcionarios];
	cadastrar(empresa,n_funcionarios);

	printf("Deseja visualizar todos os empregados cadastrados? [S] / [N]\n");
	scanf("%c",&escolha);

	if(toupper(escolha)=='S')
	{
		mostrar(empresa,n_funcionarios);
	}
	if(toupper(escolha)=='N')
	{
		system("pause");
		exit(1);
	}
}


void cadastrar(struct cadastro *empresa,int n_funcionarios)
{

	int aux=0;

	do{
		system("cls");
		printf("-----------  Cadastro do funcionario %d  -----------\n",aux+1);

		printf("Digite o nome do funcionario:\n");
		fgets(empresa[aux].nome,20,stdin);
		fflush(stdin);
		printf("Digite o codigo do funcionario:\n");
		scanf("%d",&empresa[aux].codigo);
		fflush(stdin);
		printf("Digite o salario do funcionario:\n");
		scanf("%f",&empresa[aux].salario_bruto);
		fflush(stdin);

		aux++;

	}while(aux<n_funcionarios);


}


void mostrar(struct cadastro *empresa,int n_funcionarios)
{
	int aux=0;
	float aux1=0;
	system("cls");
	setlocale(LC_ALL,"");

	do{
		aux1 = ((empresa[aux].salario_bruto*12)/100);

		printf("-----------  Funcionario %d  -----------\n",aux+1);
		printf("Nome: %s\n",empresa[aux].nome);
		printf("Codigo: %d\n",empresa[aux].codigo);
		printf("Salario bruto: R$ %.2f\n",empresa[aux].salario_bruto);
		printf("Deducao INSS: 12%%\n");
		printf("Salario liquido: R$ %.2f\n\n",empresa[aux].salario_bruto-aux1);
		
		aux++;

	}while(aux<n_funcionarios);




}