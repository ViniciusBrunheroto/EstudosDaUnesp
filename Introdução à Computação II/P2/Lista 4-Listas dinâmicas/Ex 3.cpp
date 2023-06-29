#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<locale.h>



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


void removerporPosicao(celula **topo)
{
	
    int cont=1;
    celula *anterior, *atual, *aux;
	
    if (*topo == NULL) 
	{
		printf("\nNão há nenhum elemento na lista! Tente adicioná-los.");
    }else
    
    {
    anterior = *topo;
	atual= *topo;
	aux= *topo;
    

        while(atual->prox != NULL)
		{
		  cont=1;
		   while (cont % 2 != 0) //percorrendo a lista (pular nó)
		   {
		   	     anterior=aux;
		         aux = aux->prox;
		         cont++;
		         atual=aux;
		   }
				        
			if (aux != NULL) // ENCONTROU UM ELEMENTO NO MEIO DA LISTA
			{	
			    anterior->prox = atual->prox; 
			    aux= atual->prox;
			    free(atual);
	        }else
	        {
	        
	        
	        if (aux == NULL) //	ENCONTROU O ULTIMO ELEMENTO
			{
			   	atual= anterior;
			   	atual->prox=NULL;	 	
		    }
	       }
    }
    
}
}

int main()
{
	setlocale(LC_ALL,"Portuguese");
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
 
    
   removerporPosicao(&topo);
       
    aux=topo;
	printf("\nA lista encadeada sem as posições pares é: \n");
	while (aux != NULL)
	     {
		 printf("%d->",aux->elemento);
		 aux=aux->prox; //INCREMENTANDO(INDO AO PROXIMO ELEMENTO DA LISTA ENCADEADA)
	     }
	  
}
