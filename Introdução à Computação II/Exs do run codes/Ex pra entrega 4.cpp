#include<stdio.h>
#include<stdlib.h>



void escolher_coordenadas(int *x1, int *y1,int *x2,int *y2);
void preencher(int matriz[][10],int matrizaux[][10],int linhas,int colunas);
void percorrer_labirinto(int xfim,int yfim,int matriz[][10],int matrizaux[][10],
int linhas,int colunas,int *min, int dist,int i, int j);
int verificar_posicao(int i,int j,int linhas, int colunas);
int verificar_valor(int matriz[][10],int matrizaux[][10],int i, int j, int linhas, int colunas);


int main()
{
	int xini=0,yini=0,xfim=0,yfim=0,linhas=0,colunas=0,i=0,j=0,dist=0;
	
	//printf("Linhas e colunas:\n");
	scanf("%d %d",&linhas,&colunas);
	
	int matriz[10][10];
	int matrizaux[10][10];
	
	
	escolher_coordenadas(&xini,&yini,&xfim,&yfim);
    preencher(matriz,matrizaux,linhas,colunas);
       
	i=0,j=0;
	
	int dist_minima = 600000;
	percorrer_labirinto(xfim,yfim,matriz,matrizaux,
	linhas,colunas,&dist_minima,dist,i,j);
	
	if (dist_minima != 600000)
	    printf("%d",dist_minima);
	
}


void escolher_coordenadas(int *x1, int *y1,int *x2,int *y2)
{
	//printf("Escolha as coordenadas de entrada: ");
	scanf("%d %d %d %d",&*x1,&*y1,&*x2,&*y2); //coordenadas de entrada	
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
	
	if (i == xfim && j == yfim)
	{
		if (dist < *min)
		   *min= dist;
		
		return;
	}
	
	
	matrizaux[i][j] = 1;
	
	//PARA BAIXO
	if((verificar_posicao(i+1,j,linhas,colunas)==1) && (verificar_valor(matriz,matrizaux,i+1,j,linhas,colunas)==1))
	{
		percorrer_labirinto(xfim,yfim,matriz,matrizaux,linhas,colunas,min,
		dist+1,i+1,j);	
			
	} 
	
	
	//PARA DIREITA
	if((verificar_posicao (i,j+1,linhas,colunas)==1) && (verificar_valor(matriz,matrizaux,i,j+1,linhas,colunas)==1))
	{
		percorrer_labirinto(xfim,yfim,matriz,matrizaux,linhas,colunas,min,
		dist+1,i,j+1);		
	} 
	
	
	//PARA ESQUERDA
	if((verificar_posicao (i,j-1,linhas,colunas)==1) && (verificar_valor(matriz,matrizaux,i,j-1,linhas,colunas)==1))
	{
		percorrer_labirinto(xfim,yfim,matriz,matrizaux,linhas,colunas,min,
		dist+1,i,j-1);	
	} 
	
	
	//PARA CIMA
	if((verificar_posicao(i-1,j,linhas,colunas)==1) && (verificar_valor(matriz,matrizaux,i-1,j,linhas,colunas)==1))
	{
		percorrer_labirinto(xfim,yfim,matriz,matrizaux,linhas,colunas,min,
		dist+1,i-1,j);			
	} 
	
	matrizaux[i][j] = 0;		
}



int verificar_posicao(int i,int j,int linhas,int colunas)
{
	int q;
	
	if (i < linhas && j < colunas && i >= 0 && j >=0)
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



int verificar_valor(int matriz[][10],int matrizaux[][10],int i, int j, int linhas, int colunas)
{
	int q;
	
	if (matriz[i][j] == 0 || matrizaux[i][j])
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
