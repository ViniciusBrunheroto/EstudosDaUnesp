#include<stdio.h>
#include<string.h>

int main()
{
	
	
	struct CadastroContas
{
	int num;
	char nome[50];
	float saldo;
};



	
	const int tam= 15;
    int achou=0,ndaconta,i=0,posi=0;
	char saldocliente,nomedocliente[50];
	
	struct CadastroContas cadastro[tam];

	printf("\nDigite o numero da conta:  ");
	scanf(" %d",&ndaconta);
	
	for (i=0;i<15;i++)
	{
		if (ndaconta == cadastro[i].num)
			achou=1;
	}
	
	if (achou==1)
       printf("Conta já cadastrada!\n");
    else
        {
        do
        {
    	    if (cadastro[i].num == 0)
    	    {
    	    posi= i;
    	    i= tam;
    	    }
    	      
          i++;
        }while (i < tam);
        
	     if (posi == 0)
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
	        }   
    }
    
    
}
