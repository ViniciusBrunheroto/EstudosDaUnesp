#include<stdio.h>
#include<stdlib.h>



void escolher_coordenadas(int *x1, int *y1,int *x2,int *y2);
void preencher(int matriz[][10],int matrizaux[][10],int linhas,int colunas);
void percorrer_labirinto(int xfim,int yfim,int matriz[][10],int matrizaux[][10],
int linhas,int colunas,int *min, int dist,int i, int j);
int verificar_posicao(int n1,int n2,int linhas, int colunas);
int verificar_valor(int matriz[][10],int matrizaux[][10],int n1, int n2);



int main()
{
	int xini=0,yini=0,xfim=0,yfim=0,linhas=0,colunas=0,dist=0,i=0,j=0;
	
	//printf("Linhas e colunas:\n");
	scanf("%d%d",&linhas,&colunas);
	
	int matriz[linhas][colunas];
	int matrizaux[linhas][colunas];
	
	
	escolher_coordenadas(&xini,&yini,&xfim,&yfim);
	
	i= xini;
	j= yini;
	
    preencher(matriz,matrizaux,linhas,colunas);
       
	   	
	int dist_minima = 100000;
	
	percorrer_labirinto(xfim,yfim,matriz,matrizaux,
	linhas,colunas,&dist_minima,dist,i,j);
	
	if (dist_minima != 100000)
	    printf("%d",dist_minima);

}



void escolher_coordenadas(int *x1, int *y1,int *x2,int *y2)
{
	//printf("Escolha as coordenadas de entrada: ");
	scanf("%d%d%d%d",&*x1,&*y1,&*x2,&*y2); //coordenadas de entrada	
}



void preencher(int matriz[][10],int matrizaux[][10],int linhas,int colunas)
{
	
	int i=0,j=0;
	//printf("Digite a matriz: \n");
	for (i=0;i<linhas;i++)
	{
		for (j=0;j<colunas;j++)
		{
			scanf("%d",&matriz[i][j]);
			matrizaux[i][j] = 0;
		}
	}	
}

		
	
void percorrer_labirinto(int xfim,int yfim,int matriz[][10],int matrizaux[][10],int linhas,int colunas,int *min,int dist,int i,int j)
{
		
	//Caso o destino foi encontrado, atualizar o valor de distância mínima
	if (i == xfim && j == yfim)
	{
		if (dist < *min)
		   *min= dist; // *min está apontando para dist_minima(que está no main e começa no valor de 100000)
		      		
		return;
	}
	
	// Use uma matriz auxiliar da mesma dimensão da matriz do labirinto para marcar se a célula já foi visitada (1) 
	matrizaux[i][j] = 1;
	
	
	//Orientação na matriz ( por meio de recursão):
	
	
	//PARA DIREITA
	if((verificar_posicao (i,j+1,linhas,colunas)==1) && (verificar_valor(matriz,matrizaux,i,j+1)==1))
		percorrer_labirinto(xfim,yfim,matriz,matrizaux,linhas,colunas,min,dist+1,i,j+1);	
	
	//PARA BAIXO
	if((verificar_posicao(i+1,j,linhas,colunas)==1) && (verificar_valor(matriz,matrizaux,i+1,j)==1))
		percorrer_labirinto(xfim,yfim,matriz,matrizaux,linhas,colunas,min,dist+1,i+1,j);
		
	//PARA ESQUERDA
	if((verificar_posicao (i,j-1,linhas,colunas)==1) && (verificar_valor(matriz,matrizaux,i,j-1)==1))
		percorrer_labirinto(xfim,yfim,matriz,matrizaux,linhas,colunas,min,dist+1,i,j-1);	
		
    //PARA CIMA
	if((verificar_posicao(i-1,j,linhas,colunas)==1) && (verificar_valor(matriz,matrizaux,i-1,j)==1))
		percorrer_labirinto(xfim,yfim,matriz,matrizaux,linhas,colunas,min,dist+1,i-1,j);			

	
	//Caso um caminho não leve à solução, desmarca-se a célula da matriz auxiliar como visitada.
	matrizaux[i][j] = 0;
			
}



int verificar_posicao(int n1,int n2,int linhas,int colunas)
{
	
	int q=0;
	
	if (n1 < linhas && n2 < colunas && n1 >= 0 && n2 >=0)
    {
	  q=1;
	  return q;
    }
	else
	    {
	     q=0;   
	     return q;
        }
}



int verificar_valor(int matriz[][10],int matrizaux[][10],int n1, int n2)
{
	int q=0;
	
	if (matriz[n1][n2] == 0 || matrizaux[n1][n2])
	{
	   q=0;
	   return q;
	}
	else
	    {  
	     q=1;
	     return q;   
        }

}
