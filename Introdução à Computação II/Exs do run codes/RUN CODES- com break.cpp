#include<stdio.h>
#include<stdlib.h>


typedef struct Lista
{
	int elemento;
	struct Lista *prox;	
}celula;


//SUBROTINA: INSERIR ELEMENTOS NO FINAL DA LISTA A
void insereFimA(celula **topoA, int num) // **topo pois é necessario alterar elementos
{
	int n,cont=0;
	//2 ponteiros necessários
    celula *novo;
    celula *aux;
    
    novo = (celula *)malloc(sizeof(celula));
    
    if (*topoA == NULL)
    {
    	novo->elemento=num;
    	novo->prox=NULL;
    	*topoA =novo;
	}else
	{
		aux= *topoA;
		while(aux->prox != NULL)
		{
			aux=aux->prox;
		}
		
	novo->elemento=num;
	novo->prox=NULL;
	aux->prox=novo;	
	}
}

//SUBROTINA: INSERIR ELEMENTOS NO FINAL DA LISTA B
void insereFimB(celula **topoB, int num) // **topo pois é necessario alterar elementos
{
	int n,cont=0;
	//2 ponteiros necessários
    celula *novo;
    celula *aux;
	
	novo= (celula *)malloc(sizeof(celula));	
	
	if (*topoB == NULL) // caso a lista esteja no início, fazer uma subrotina para incluir elementos no início
	{
		novo->elemento=num;
		novo->prox= NULL; 
	    *topoB=novo;
	}else
	{
		aux= *topoB;
		while (aux->prox != NULL) //percorrendo a lista
		   {
		   	aux=aux->prox;
		   }
	
	 novo->elemento= num;
	 novo->prox= NULL;
	 aux->prox=novo;
    }
}


//A-B
void subtrair1(celula **topoA, celula **topoB,celula **lista1)
{
	celula *aux,*aux2;
	int var,cont=0,p=0,i;
	celula *novo;
    celula *auxiliar;
	
	
	aux= *topoA;
	aux2 = *topoB;
	while (aux != NULL)
	{ 
	    cont=0;
		var = aux->elemento;
	
		while (aux2 != NULL)
		{
			if (aux2->elemento == var)
			    cont++;
			    
			aux2= aux2->prox;
		}
		
		if (cont == 0)
		{
		   p=0;
		   
		   
		  novo= (celula *)malloc(sizeof(celula));
		  //ADICIONANDO O ELEMENTO A LISTA 1  
		   if (*lista1 == NULL) // 1 inserção
		   {
		   novo->elemento=var;
    	   novo->prox=NULL;
    	   *lista1 =novo;
           }
		   else
           {
           	auxiliar= *lista1;
		    
			while(auxiliar->prox != NULL)//2 inserção
		        {
			     auxiliar=auxiliar->prox;
		        }
		
	        novo->elemento=var;
	        novo->prox=NULL;
	        auxiliar->prox=novo;	
		   }
          
	
	
		   auxiliar=*lista1;
		   //VERIFICAR SE O ELEMENTO É REPETIDO OU NÃO
		   
		   while (auxiliar != NULL) //percorrendo a lista
		   {
		   	if (var == auxiliar->elemento)
		   	    p++;
		   	    
            auxiliar=auxiliar->prox;
		   }
		
		   if (p == 1)
		     printf("%d ",var);
	    }

	aux=aux->prox;
	aux2=*topoB; //toda vez q for percorrer a lista b, precisa voltar no inicio dela
    }
    
    printf("\n");
    aux= *lista1;
    do
	     {
		 printf("%d->",aux->elemento);
		 aux=aux->prox; //INCREMENTANDO(INDO AO PROXIMO ELEMENTO DA LISTA ENCADEADA)
	    }while (aux != NULL);
}




//B-A
void subtrair2(celula **topoA, celula **topoB,celula **lista2)
	{
	celula *aux,*aux2;
	int var,cont=0,p=0,i;
	
	celula *novo;
    celula *auxiliar;
	
	aux= *topoB;
	aux2 = *topoA;
	printf("\n");
	while (aux != NULL)
	{
		cont=0;
		var = aux->elemento;
	
		while (aux2 != NULL)
		{
			if (aux2->elemento == var)
			    cont++;
			    
			aux2= aux2->prox;
		}
		
		if (cont == 0)
		{
		   
		   p=0;
		   
		  novo= (celula *)malloc(sizeof(celula));
		  //ADICIONANDO O ELEMENTO A LISTA 2 
		   if (*lista2 == NULL) // 1 inserção
		   {
		   novo->elemento=var;
    	   novo->prox=NULL;
    	   *lista2 =novo;
           }else
           {
           	auxiliar= *lista2;
		    
			while(auxiliar->prox != NULL)//2 inserção
		        {
			     auxiliar=auxiliar->prox;
		        }
		
	        novo->elemento=var;
	        novo->prox=NULL;
	        auxiliar->prox=novo;	
		   }
		   
		   auxiliar=*lista2;
		   //VERIFICAR SE O ELEMENTO É REPETIDO OU NÃO
		   
		   while (auxiliar != NULL) //percorrendo a lista
		   {
		   	if (var == auxiliar->elemento)
		   	    p++;
		   	    
		   	auxiliar=auxiliar->prox;
		   }
		
		   
		   if (p == 1)
		     printf("%d ",var);
	       }
	       
	       
	aux=aux->prox;
	aux2=*topoA; //toda vez q for percorrer a lista b, precisa voltar no inicio dela	
	}
	
	printf("\n");
	 aux= *lista2;
    do
	     {
		 printf("%d->",aux->elemento);
		 aux=aux->prox; //INCREMENTANDO(INDO AO PROXIMO ELEMENTO DA LISTA ENCADEADA)
	    }while (aux != NULL);

}


void fundirListas(celula ** lista1,celula ** lista2)
{
	
	celula *aux;
	celula *aux2;
	celula *anterior,*atual;
	int var,p=0;
	
	
	aux=  *lista1;
	aux2= *lista2;
	
	while (aux->prox != NULL)
	{
		aux=aux->prox;
	}
	
	aux->prox=aux2;
	
	aux= *lista1;
	aux2=*lista1;
	anterior= *lista1;
	atual= *lista1;
	
	
	while(aux != NULL)
	{
	     var= aux->elemento;
		 p=0;		   	    
			   	    
	    while (aux2 != NULL)
	    {
		if (var == aux2->elemento)
		  p++;
		
	     aux2=aux2->prox;
	     
	     if (p > 1)
	         break;
	     
	     anterior=atual;
		 atual=atual->prox;
	    }		
	    
	    if (p > 1)
	    {
	    	anterior->prox = atual->prox; 
			free(atual);
		}
		
		anterior= *lista1;
		atual= *lista1;
		aux2= *lista1;
		aux = aux->prox;	
    }
			
					
	aux= *lista1;	   
	printf("\n");
	 do
	     {
		 printf("%d ",aux->elemento);
		 aux=aux->prox; //INCREMENTANDO(INDO AO PROXIMO ELEMENTO DA LISTA ENCADEADA)
	    }while (aux != NULL);
}

int main()
{
	int numA,numB,elemento,cont=0;
	
	celula *topoA= NULL;
	celula *topoB= NULL;
	celula *aux;
	celula *lista1=NULL;
	celula *lista2=NULL;
	
	scanf("%d",&numA);

    do
    {
    scanf("%d",&elemento);
	insereFimA(&topoA,elemento); 
	cont++;
    }while (cont != numA);
    
    
    aux = topoA;
    
	scanf("%d",&numB);
	
	cont=0;
	do
    {
    scanf("%d",&elemento);
	insereFimB(&topoB,elemento);
	cont++; 
    }while (cont != numB);
		
	aux = topoB;
			
    subtrair1(&topoA,&topoB,&lista1);	
	subtrair2(&topoA,&topoB,&lista2);	
	fundirListas(&lista1,&lista2);
}
