#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<locale.h>



typedef struct Lista
{
	int elemento;
	struct Lista *prox;	
}celula;


//SUBROTINA: INSERIR ELEMENTOS NO IN�CIO DA LISTA
void insereFim(celula **topo, int num) // **topo pois � necessario alterar elementos
{
	//2 ponteiros necess�rios
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


void inverterLista(celula **topo)
{
	
    int cont=1;
    celula *atual, *topoauxiliar;
    
    atual = *topo;
    topoauxiliar= atual->prox;
    
    if (topoauxiliar == NULL) return;    //CASO TRIVIAL
     
    inverterLista(&topoauxiliar);
  
  	    
	atual->prox->prox= atual;

    atual->prox=NULL;
    *topo= topoauxiliar;
	
  
}

int main()
{
	setlocale(LC_ALL,"Portuguese");
	int quant,cont=0,num;
	celula *aux;
	
    printf("Quantos n�meros?\n");
	scanf(" %d",&quant);
	    
	celula *topo= NULL;
	   
	while (cont != quant)//INSERIR ELEMENTOS NA LISTA
	{
	printf("Digite o n�mero: ");
	scanf(" %d",&num);
	insereFim(&topo,num);
	cont++;
    }
 
    
   inverterLista(&topo);
       
    aux=topo;
	printf("\nA lista encadeada atual �: \n");
	while (aux != NULL)
	     {
		 printf("%d->",aux->elemento);
		 aux=aux->prox; //INCREMENTANDO(INDO AO PROXIMO ELEMENTO DA LISTA ENCADEADA)
	     }
	  
}
