#include<stdio.h>
#include<string.h>





void TrocarString(char p[][50], int j,int k)
{
	
	char aux[50];
	
	
	strcpy(aux,&(p[j][0]));

	
	strcpy(&p[j][0],&p[k][0]);
	
	
	strcpy(&p[k][0], aux);

}



void Insercao(int i[],int n,char p[][50])
{
	
	int chave,k,j;
	char str;
	
	for (k=0 ; k < n ; k++)
	{
		
		chave = i[k];
		j=k;
		
		while ((j > 0) && (i[j-1] > chave))
		{
			i[j]= i[j-1];
			j=j-1;
		}
		
		i[j] = chave;
		
		TrocarString(p,j,k);
	}	

}




int main()
{
	int i=0;
	int n;
	int v[2];
	char p [2][50]={"Rafaela","Pedro"};
	
	v[0]=5;
	v[1]=2;	
	
	Insercao(v,2,p);
	
	
	for (i = 0 ; i < 2 ; i++)
	{
		printf("%d ",v[i]);
	}
	
	
	for (i = 0 ; i < 2 ; i++)
	{
		printf("%s ",p[i]);
    }
}
