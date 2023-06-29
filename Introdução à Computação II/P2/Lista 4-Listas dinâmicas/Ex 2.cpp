#include<stdio.h>
#include<locale.h>
#include<stdlib.h>



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


void removerporValor(celula **topo)
{
	
    int cont=0;
    celula *anterior, *atual;
	
    if (*topo == NULL) 
	{
		printf("\nN�o h� nenhum elemento na lista! Tente adicion�-los.");
    }else
    
    do
    {
    	cont=0;
    	anterior=*topo;
    	atual=*topo;
    	
        while(atual != NULL)
		{
				
        	if (atual->elemento % 2 == 0) //achei o elemento
        	{
        		cont++;
        		if (atual == *topo) // SE O ELEMENTO ESTIVER NO IN�CIO
    		   	    {
						(*topo)= (*topo)->prox; //pega o ponteiro inicio e joga para o pr�ximo elemento
    		   	        free(atual);
    		   	       break;
					}
			         else
			             {
			   	           if (atual == NULL) //	SE O ELEMENTO ESTIVER NO FINAL
			   	           {
			   	            atual= anterior;	
				           }
				           
				            anterior->prox = atual->prox; 
				            free(atual);
				            break; 	
			             }
		        }
		        
		  else //percorrendo a lista(caso nao encontrar elemento)
		  {  
		    anterior=atual;
			atual=atual->prox;
		  }  
	   }
	   
	}while(cont != 0);


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
	insereFim(&topo,num);
	cont++;
    }
 
    
   removerporValor(&topo);
       
    aux=topo;
	printf("\nA lista encadeada sem os elementos pares �: \n");
	while (aux != NULL)
	     {
		 printf("%d->",aux->elemento);
		 aux=aux->prox; //INCREMENTANDO(INDO AO PROXIMO ELEMENTO DA LISTA ENCADEADA)
	     }
	  
}
