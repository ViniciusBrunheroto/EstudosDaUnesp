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
    celula *anterior, *atual,*aux;
	
    if (*topo == NULL) 
	{
		printf("\nN�o h� nenhum elemento na lista! Tente adicion�-los.");
    }else
    
    
    aux=*topo;
    anterior=*topo;
    atual=*topo;
    
    	cont=0;
    	
        while(aux->prox != NULL)
		{
        		atual = aux;
        	    while (aux->elemento % 2 != 0)// pular n�
        		{
        		 anterior=aux;
		         aux = aux->prox;
		         atual=aux;
		        }
            
        		if (aux == *topo) // SE O ELEMENTO ESTIVER NO IN�CIO DA LISTA
    		   	    {
						(*topo)= (*topo)->prox; //pega o ponteiro inicio e joga para o pr�ximo elemento
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
			              //SE O ELEMENTO ESTIVER NO FINAL DA LISTA
			   	           if (aux->prox == NULL && aux->elemento % 2 != 0) //	SE O ULTIMO ELEMENTO FOR IMPAR
			   	           {
							atual->prox=NULL;	
				           }else
				           {
				           
				           if (aux->prox == NULL && aux->elemento % 2 == 0) //	SE O ELEMENTO FOR PAR
			   	              {
							    atual= anterior;
			   	                atual->prox=NULL;
			   	              }
				           }
					}
					}
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
