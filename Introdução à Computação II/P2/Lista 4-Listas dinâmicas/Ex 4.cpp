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
	
    int cont=0,item;
    celula *anterior, *atual,*aux;
	
    if (*topo == NULL) 
	{
		printf("\nNão há nenhum elemento na lista! Tente adicioná-los.");
    }else
    
    
    aux=*topo;
    anterior=*topo;
    atual=*topo;
    
    
    printf("Informe o item que deseja remover da lista encadeada:  ");
    scanf("%d",&item);
    
    	cont=0;
    	
        while(atual->prox != NULL)
		{
				
			atual = aux;		
           while (aux->elemento != item && aux->prox != NULL) //percorrendo a lista (pular nó)
		   {
		   	     anterior=aux;
		         aux = aux->prox;
		         atual=aux;
		   }
		   
        		if (aux == *topo) // SE O ELEMENTO ESTIVER NO INÍCIO DA LISTA
    		   	    {
						(*topo)= (*topo)->prox; //pega o ponteiro inicio e joga para o próximo elemento
						aux=atual->prox;
    		   	        free(atual);
    		   	       
					}else
					{
					  if (aux->prox != NULL) //SE O ELEMENTO ESTIVER NO MEIO DA LISTA
				           {
				            anterior->prox = atual->prox; 
			                aux= atual->prox;
			                free(atual);
			               }
					
			         else
			         {
		              //SE O ELEMENTO ESTIVER NO FINAL DA LISTA E FOR O ITEM
			   	           if (aux->prox == NULL && aux->elemento == item) 
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
	printf("\nA lista encadeada sem os elementos pares é: \n");
	while (aux != NULL)
	     {
		 printf("%d->",aux->elemento);
		 aux=aux->prox; //INCREMENTANDO(INDO AO PROXIMO ELEMENTO DA LISTA ENCADEADA)
	     }
	  
}
