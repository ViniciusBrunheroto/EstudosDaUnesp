#include<stdio.h>
#include<locale.h>
#include<stdlib.h>



typedef struct Lista
{
	int elemento;
	struct Lista *prox;	
}celula;


//SUBROTINA: INSERIR ELEMENTOS NO INÍCIO DA LISTA
void insereFim(celula **topo, int num) // **topo pois é necessario alterar elementos
{
	//2 ponteiros necessários
    celula *novo;
    celula *aux;
    
    novo = (celula *)malloc(sizeof(celula));
    
    if (*topo == NULL)
    {
    	novo->elemento=num;
    	novo->prox=NULL;
    	*topo =novo;
	}else
	{
		aux= *topo;
		while(aux->prox != NULL)
		{
			aux=aux->prox;
		}
		
	novo->elemento=num;
	novo->prox=NULL;
	aux->prox=novo;	
	}
}


void removerItem(celula **topo)
{	
	//considerando uma lista ordenada
	
	
    int cont=0,var,p=0;
    celula *auxiliar;
	
	
	
	if (*topo== NULL || (*topo)->prox == NULL) //caso trivial
	    return;
	    
	else
	{
		if ((*topo)->elemento == ((*topo)->prox)->elemento) //verificando se os elementos consecutivos sao iguais
		{
				
    		auxiliar = (*topo);
			(*topo)= (*topo)->prox; 
    		free(auxiliar);
    		removerItem(topo);
    		
		}else removerItem(&((*topo)->prox));    	
   }
}



int main()
{
	
	int quant,cont=0,num;
	celula *aux;
	
    printf("Quantos números?\n");
	scanf(" %d",&quant);
	    
	celula *topo= NULL;
	
	   
	while (cont != quant)//INSERIR ELEMENTOS NA LISTA
	{
	printf("Digite o número: ");
	scanf(" %d",&num);
	insereFim(&topo,num);
	cont++;
    }
   
   removerItem(&topo);
       
    aux=topo;
	printf("\nA lista encadeada sem os elementos repetidos é: \n");
	while (aux != NULL)
	     {
		 printf("%d->",aux->elemento);
		 aux=aux->prox; //INCREMENTANDO(INDO AO PROXIMO ELEMENTO DA LISTA ENCADEADA)
	     }
	  
}
