#include<stdio.h>
#include<conio.h>
#include<locale.h>


enum Pagamento{dinheiro= 'd', cheque= 'c', vale_refeicao= 'v',cartao= 'k'};


int main()
{
	setlocale(LC_ALL,"Portuguese");
	
	enum Pagamento pag;
	
	printf("Qual a forma de pagamento?\n");	
	scanf(" %c",&pag);
		
	switch(pag)
	{
		case dinheiro:
			{
			printf("O seu pagamento ser� em DINHEIRO");
			break;
		    }
		    
		case cheque:
			{
		    printf("O seu pagamento ser� em CHEQUE");
		    break;
		    }
		    
		case vale_refeicao:
		    {
		    printf("O seu pagamento ser� em VALE REFEI��O");
			break;
		    }
		case cartao:
			{
		    printf("O seu pagamento ser� em CARTAO");
			break;
		    }
		    
		default:
		    {
	        printf("Opcao invalida");
			break;
		    }
	}
	
	return 0;
}
