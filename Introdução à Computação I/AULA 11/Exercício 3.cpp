#include<stdio.h>
#include<locale.h>



int main()

{
	
	setlocale(LC_ALL,"Portuguese");
	
	
	const int linhas = 4;
	const int colunas = 7;
	
	int matriz[linhas][colunas],i,j,menor,pos,maior,nlinha;
	
	
	for (i=0 ; i < linhas; i++) //criando a matriz
    {
    	
    	for (j=0 ; j < colunas; j++)
    	{
    	printf("Digite um número:  ");
		scanf("%d",&matriz[i] [j]);	
		}
    	
	}
	
	for (i=0 ; i < linhas; i++) //printando a matriz
    {
    	
    	for (j=0 ; j < colunas; j++)
    	{
		printf("%d ",matriz[i] [j]);	
		}
		
    	printf("\n");
	}

	menor = matriz[0][0];
	nlinha=0;
	
	for (i=0 ; i < linhas; i++) //analisando onde fica o menor elemento
    {
    	
    	for (j=0 ; j < colunas; j++)
    	   {
             if (matriz [i] [j] < menor)
		       {
		        menor = matriz[i] [j];
		        nlinha= i;		
		       }		
    	
		   }  	
	}
	
	
	
	maior= matriz[0][0];
    pos=0;
	
	for ( i = nlinha ; i < nlinha+1 ; i++) //verificar o maior número na linha escolhida
    {
    	for ( j = 0 ; j < colunas ; j++)
        {
        	if (matriz [i] [j] > maior)
        	{
        	maior = matriz [i] [j];
			pos = j;		 		
			}
		}
	}
		
	printf("\nO menor elemento dessa matriz é %d que está na linha %d\n",menor,nlinha+1);	
    printf("Então, o MINMAX dessa matriz será: %d que está localizado na coluna %d da linha %d\n",maior,pos+1,nlinha+1);

		
}
	
