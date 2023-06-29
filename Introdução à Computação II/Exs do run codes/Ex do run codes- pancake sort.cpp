#include<stdio.h>
#include<stdlib.h>



typedef struct Lista
{
	int elemento;
	struct Lista *prox;	
}celula;



//SUBROTINA: INSERIR ELEMENTOS NO FIM DA LISTA
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


 int percorrerLista(celula *topo)
 {
 
    celula *aux;
    int cont=0;
     
    aux= topo;
    while (aux != NULL)
	{
	  cont++;	
	  aux=aux->prox;
	} 
 
    return cont;
 	
}	


int saberoElemento(celula *topo)
{
	celula *aux;
    int var,vez=0;
     
    aux= topo;
    while (aux != NULL)
	{
	   if (vez==0)
	    {
	   	var= aux->elemento;	
	   	vez++;	
	    }
		else
		{
		if (var < aux->elemento)
		{
			var= aux->elemento;
		}	
	  aux=aux->prox;
	} 
    }
    
    return var;
}




int acharMaximo(celula *topo)
{
	celula *aux;
    int var,vez=0,indice=0,cont=0;
     
    aux= topo;
    while (aux != NULL)
	{
	   if (vez==0)
	    {
	   	var= aux->elemento;	
	   	vez++;	
	    }
		else
		{
		if (aux->elemento > var)
		{
			var= aux->elemento;
			indice=cont;
		}
	    }
	  cont++;
	  aux=aux->prox;
   }
    
    return indice;
}


//SUBROTINA:REMOVER O ELEMENTO POR POSI��O
void removerElemento(celula **topo, int maximo)
{
    int cont=0;
    celula *anterior, *atual, *aux;
    
    anterior = *topo;
	atual= *topo;
	aux= *topo;
    

        while(aux->prox != NULL)
		{
		  atual = aux;
		   if(cont != maximo) //percorrendo a lista (pular n�)
		   {
		   	     anterior=aux;
		         aux = aux->prox;
		         atual=aux; 
		   }else
		   {
		   
		   if (aux == *topo) // SE O ELEMENTO ESTIVER NO IN�CIO DA LISTA
    		   	    {
					(*topo)= (*topo)->prox; //pega o ponteiro inicio e joga para o pr�ximo elemento
					aux=atual->prox;
    		   	    free(atual);
    		   	    }else
    		   	    {
    		   	      if (aux->prox != NULL) // ENCONTROU UM ELEMENTO NO MEIO DA LISTA
			          {	
			           anterior->prox = atual->prox; 
			           aux= atual->prox;
			           free(atual);
					  }else
					  {
	                   if (aux->prox == NULL) //	ENCONTROU O ULTIMO ELEMENTO
			          {
			   	      atual= anterior;
			   	      atual->prox=NULL;	 	
		              }
	                  } 
                   }
                   
            }
                   aux=aux->prox;
                   cont++;
        }    

}


//SUBROTINA: INSERIR NO INICIO
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



//SUBROTINA: INVERTER LISTA
void inverterLista(celula **topo)
{
	
	celula *q,*r,*s;
	
	q= NULL;
	r= *topo;
	
	while(r != NULL)
	{
		s = r->prox;
		r->prox= q; 
		q=r;
		r=s;
	}
	*topo =q;
}



//SUBROTINA: REMOVER PARA O FINAL
void moverFinal(celula **topo,int maximo)
{
	int max=0;
	celula *aux;
  	
	max= saberoElemento(*topo);


    // remover o elemento m�ximo
	removerElemento(topo,maximo);	
	
	aux=*topo;
	printf("\n");
	 do
	     {
		 printf("%d->",aux->elemento);
		 aux=aux->prox; //INCREMENTANDO(INDO AO PROXIMO ELEMENTO DA LISTA ENCADEADA)
	    }while (aux != NULL);
	
	
	
	// removido o elemento, inserir no in�cio
	insereInicio(topo,max);
	
	
	aux=*topo;
	printf("\n");
	 do
	     {
		 printf("%d->",aux->elemento);
		 aux=aux->prox; //INCREMENTANDO(INDO AO PROXIMO ELEMENTO DA LISTA ENCADEADA)
	    }while (aux != NULL);
	    
	    
	//inverter a lista, passando o 1 elemento para o final
	inverterLista(topo);
	
	printf("\n");
	aux=*topo;
	 do
	     {
		 printf("%d->",aux->elemento);
		 aux=aux->prox; //INCREMENTANDO(INDO AO PROXIMO ELEMENTO DA LISTA ENCADEADA)
	    }while (aux != NULL);
	
}	
	
	
void pancakeSort(celula **topo,int num)
{
	int curr_size=0,ind=0;
	
	for (curr_size=num; curr_size>1 ; --curr_size) //achar o �ndice do m�ximo elemento na lista
	{
     ind= acharMaximo(*topo);
      
      if (ind != (curr_size))
      {
      	//mover o maior elemento para o final
      	moverFinal(topo,ind);	
	  }
	  	
	}
}


//SUBROTINA: PRINTAR A LISTA
void printarLista(celula *topo)
{
	celula *aux; //PONTEIRO 3: PRINTAR OS ELEMENTOS DA LISTA

		
	aux=topo;
			
	if (aux == NULL)
	{
		printf("\nA lista selecionada n�o existe!");
	}else 
	{
		printf("\nA lista encadeada atual �: \n");
	   do
	     {
		 printf("%d->",aux->elemento);
		 aux=aux->prox; //INCREMENTANDO(INDO AO PROXIMO ELEMENTO DA LISTA ENCADEADA)
	    }while (aux != NULL);
    }
}


int main()
{
	
	int num,cont=0,quant=0;
	celula *topo= NULL;
	
	
	printf("Quantos n�meros?\n");
	scanf(" %d",&quant);
	
	
	while (cont != quant)//INSERIR ELEMENTOS NA LISTA
	{
	printf("Digite o n�mero: ");
	scanf(" %d",&num);
	insereFim(&topo,num);
	cont++;
    }
    	
	
	num= percorrerLista(topo);
		
	pancakeSort(&topo,num);
	
	printarLista(topo);
}
