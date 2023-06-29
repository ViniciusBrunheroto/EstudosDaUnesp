#include<stdio.h>
#include<locale.h>
#include<stdlib.h>



typedef struct Lista
{
	int elemento;
	struct Lista *prox;	
}celula;


//SUBROTINA: INSERIR ELEMENTOS NO IN�CIO DA LISTA
void insereInicio(celula **topo,int num) // **topo pois � necessario alterar elementos
{
	celula *novo; 
	
	novo= (celula *)malloc(sizeof(celula));
	novo->elemento= num;
	
	if (*topo == NULL)// condi��o em que n�o existe elementos na lista, apenas o topo
	{
		novo->prox= NULL; 
		*topo=novo;
	}else
	{ //condi��o em que j� existe elementos na lista
		novo->prox= *topo; 
		*topo=novo;
	}		
}



void destruirLista(celula **topo)
{
		
	if ((*topo)->prox != NULL)
	{
	destruirLista(  &((*topo)->prox )  );
	free(*topo);
	*topo = NULL;
    }
	else
	{ 
		free(*topo);
		*topo = NULL;
	}
}


int main()
{
	
	int quant,cont=0,num;
	celula *aux;
	
    printf("Quantos n�meros?\n");
	scanf(" %d",&quant);
	    
	celula *topo= NULL;
	   
	while (cont != quant)//INSERIR ELEMENTOS NA LISTA
	{
	printf("Digite o n�mero: ");
	scanf(" %d",&num);
	insereInicio(&topo,num);
	cont++;
    }
        

    destruirLista(&topo);
	   
    aux=topo;
	printf("\nA lista encadeada atual �: \n");
	while (aux != NULL)
	     {
		 printf("%d->",aux->elemento);
		 aux=aux->prox; //INCREMENTANDO(INDO AO PROXIMO ELEMENTO DA LISTA ENCADEADA)
	     }
	     
	if (aux == NULL)
	   printf("N�o h� elementos na lista!");    
}
