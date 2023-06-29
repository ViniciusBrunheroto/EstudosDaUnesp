#include <stdio.h>
#include <stdlib.h>




struct lista
{
	int info;
	struct lista *prox;
};
typedef struct lista Lista;




bool BuscaRec(int x, Lista *L)
{
	
     if (L == NULL) 
	     return false; 
     else
     if (L->elemento == x) 
         return true;
    else  
	return BuscaRec(x, &(L->prox));
    
}

