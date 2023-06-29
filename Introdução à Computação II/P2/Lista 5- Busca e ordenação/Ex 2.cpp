#include<stdio.h>
#include<stdlib.h>





struct lista
{
	int info;
	struct lista *prox;
};
typedef struct lista Lista;



int buscaT(int x, int *a, int inf, int sup)
{
	int meio, meio1,meio2;
	
	if (inf > sup) return -1;  // caso trivial
	else
	{
		meio = (inf+sup)/2
		meio1= (inf+meio)/2
		meio2= ((meio+1)+sup)/2
		
		
		if (x == a[meio1])
		    return meio1;
		else if (x == a[meio2])
		    return meio2;
		else if (x < a[meio1])
		    return buscaT(x,a,inf,meio1-1);
		else if (x > a[meio2])  
		    return buscaT(x,a,meio2+1,sup);
		else
		    return buscaT(x,a,meio1+1,meio2-1);	
    }
	
}
