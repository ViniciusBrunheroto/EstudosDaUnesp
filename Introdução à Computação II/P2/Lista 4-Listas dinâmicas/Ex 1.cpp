#include<stdio.h>
#include<locale.h>
#include<stdlib.h>



typedef struct Lista
{
	int elemento;
	struct Lista *prox;	
}celula;


//SUBROTINA: INSERIR ELEMENTOS NO INÍCIO DA LISTA
void insereInicio(celula **topo,int num) // **topo pois é necessario alterar elementos
{
	celula *novo; 
	
	novo= (celula *)malloc(sizeof(celula));
	novo->elemento= num;
	
	if (*topo == NULL)// condição em que não existe elementos na lista, apenas o topo
	{
		novo->prox= NULL; 
		*topo=novo;
	}else
	{ //condição em que já existe elementos na lista
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
	
    printf("Quantos números?\n");
	scanf(" %d",&quant);
	    
	celula *topo= NULL;
	   
	while (cont != quant)//INSERIR ELEMENTOS NA LISTA
	{
	printf("Digite o número: ");
	scanf(" %d",&num);
	insereInicio(&topo,num);
	cont++;
    }
        

    destruirLista(&topo);
	   
    aux=topo;
	printf("\nA lista encadeada atual é: \n");
	while (aux != NULL)
	     {
		 printf("%d->",aux->elemento);
		 aux=aux->prox; //INCREMENTANDO(INDO AO PROXIMO ELEMENTO DA LISTA ENCADEADA)
	     }
	     
	if (aux == NULL)
	   printf("Não há elementos na lista!");    
}
