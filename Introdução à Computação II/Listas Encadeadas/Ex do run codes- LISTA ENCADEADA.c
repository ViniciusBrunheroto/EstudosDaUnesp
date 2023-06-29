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
	int var,cont=0,p=0;
	celula *novo;
    celula *auxiliar;
	
	
	aux= *topoA;
	aux2 = *topoB;
	
	while (aux != NULL)
	{ 
	
	    cont=0;
		var = aux->elemento;
		aux2= *topoB;
	
		while (aux2 != NULL)
		{
			if (aux2->elemento == var)
			    cont++;
			    
			aux2= aux2->prox;
		}
		
		if (cont == 0)
		{
		   p=0;
		    
		   auxiliar=*lista1;
				 
		   while (auxiliar != NULL) //percorrendo a lista
		   {
		   	if (var == auxiliar->elemento)
		   	    p++;
		   	    
		   	auxiliar=auxiliar->prox;
		   }
		   
		   
		  if (p == 0)
		  {	   
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
      
	  		 if (p == 0)
		     printf("%d ",var);
	       }
        }   
    //toda vez q for percorrer a lista b, precisa voltar no inicio dela
	aux=aux->prox;
   }
   
}




//B-A
void subtrair2(celula **topoA, celula **topoB,celula **lista2)
	{
	celula *aux,*aux2;
	int var,cont=0,p=0;
	
	celula *novo;
    celula *auxiliar;
	
	aux= *topoB;
	aux2 = *topoA;
	printf("\n");
	while (aux != NULL)
	{
		cont=0;
		var = aux->elemento;
	    aux2=*topoA;
	    
		while (aux2 != NULL)
		{
			if (aux2->elemento == var)
			    cont++;
			    
			aux2= aux2->prox;
		}
		
		if (cont == 0)
		{
		   p=0;
		   auxiliar= *lista2;
		   
		   
		   while (auxiliar != NULL) //percorrendo a lista
		   {
		   	if (var == auxiliar->elemento)
		   	    p++;
		   	    
		   	auxiliar=auxiliar->prox;
		   }
		   
		   
		   if (p==0)
		   {
		   
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
	      }
	      
		   if (p == 0)
		     printf("%d ",var);
	       }
	       
	       
	aux=aux->prox;  //toda vez q for percorrer a lista b, precisa voltar no inicio dela	
	}
	 aux= *lista2;

}


void fundirListas(celula ** lista1,celula ** lista2,int numA)
{
	
	celula *aux;
	celula *aux2;
	
	aux=  *lista1;
	aux2= *lista2;
	
	if(numA != 0)
	{
	while (aux->prox != NULL)
	{
		aux=aux->prox;
	}
	
	aux->prox=aux2;
	
	
	aux= *lista1;	   
	printf("\n");

	 do
	     {
		 printf("%d ",aux->elemento);
		 aux=aux->prox; //INCREMENTANDO(INDO AO PROXIMO ELEMENTO DA LISTA ENCADEADA)
	    }while (aux != NULL);
   }else
        {
         printf("\n");
         do
	        {
		     printf("%d ",aux2->elemento);
		     aux2=aux2->prox; //INCREMENTANDO(INDO AO PROXIMO ELEMENTO DA LISTA ENCADEADA)
	         }while (aux2 != NULL);
	    }
}

int main()
{
	int numA,numB,elemento,cont=0;
	
	celula *topoA= NULL;
	celula *topoB= NULL;
	celula *lista1=NULL;
	celula *lista2=NULL;
	
	scanf("%d",&numA);
    
    if (numA != 0)
    {
       do
         {
          scanf("%d",&elemento);
	      insereFimA(&topoA,elemento); 
	      cont++;
         }while (cont != numA);
    }

	scanf("%d",&numB);
	
	cont=0;
	
	if (numB != 0)
	{
	  do
       {
        scanf("%d",&elemento);
	    insereFimB(&topoB,elemento);
	    cont++; 
       }while (cont != numB);
    }
			
    subtrair1(&topoA,&topoB,&lista1);	
	subtrair2(&topoA,&topoB,&lista2);	
	fundirListas(&lista1,&lista2,numA);
}
