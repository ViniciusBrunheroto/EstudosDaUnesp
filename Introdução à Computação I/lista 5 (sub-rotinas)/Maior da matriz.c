#include <stdio.h>


int elemento(int mat[][10], int linhas, int colunas);


int main(void)
{
	const int linhas = 10;
	const int colunas = 10;
	
	
    int i,j,matriz[linhas][colunas],maior;
    
    
    for (i=0;i<linhas;i++)//preenchendo a matriz
    {
    	for (j=0;j<colunas;j++)
    	{
    	 scanf("%d",&matriz[i][j]);
		}
	}
    
    maior = elemento(matriz,linhas,colunas);
    
    printf("%d",maior);
    return 0;
}


int elemento(int mat[][10], int linhas, int colunas)
{
	
	int i,j,maior;
	
	maior= mat[0][1];
	j=1;
	for (i=0;i<linhas;i++)
	{
		for (j=i+1;j<colunas;j++)
		{
		    if (mat[i][j] > maior)
		    {
		    maior = mat[i][j];
	        }

	    }
    }
	return maior;
	
}
