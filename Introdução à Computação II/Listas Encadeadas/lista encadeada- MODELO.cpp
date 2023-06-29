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


//SUBROTINA: INSERIR ELEMENTOS NO FINAL DA LISTA
void insereFim(celula **topo, int num) // **topo pois é necessario alterar elementos
{
	int n,cont=0;
	//2 ponteiros necessários
    celula *novo1;
    celula *aux;
	
	novo1= (celula *)malloc(sizeof(celula));	
	
	if (*topo == NULL) // caso a lista esteja no início, fazer uma subrotina para incluir elementos no início
	{
		printf("\nNão há nenhum elemento na lista!");
		insereInicio(topo,num); //alterar +pont
		cont++;
	}
		aux=*topo;
		while (aux->prox != NULL) //percorrendo a lista
		   {
		   	aux=aux->prox;
		   }
	
	 novo1->elemento= num;
	 novo1->prox= NULL;
	 aux->prox=novo1;
}


//SUBROTINA: INSERIR ELEMENTOS EM UMA POSIÇÃO DA LISTA
void insereMeio(celula **topo, int num) // **topo pois é necessario alterar elementos
{
	int n,cont=0,numpos=0;
	//2 ponteiros necessários
    celula *novo2;
    celula *aux;
    celula *aux2;
	
	novo2= (celula *)malloc(sizeof(celula));	
	
	if (*topo == NULL) // caso a lista esteja no início, fazer uma subrotina para incluir elementos no início
	{
		printf("\nNão há nenhum elemento na lista!");
		exit(1);
    }else
    {
	printf("\nQual número você deseja acrescentar no meio da lista?");
    scanf("%d",&num);
    printf("Você deseja adicionar em qual posição?");
    scanf("%d",&numpos);
    
    cont=0;
		aux=*topo;
		while (cont != numpos) //percorrendo a lista
		   {
		   	aux=aux->prox;
		   	cont++;
		   }
	
	 novo2->elemento= num;
	 aux->prox=novo2;
    }
}

//SUBROTINA: PRINTAR OS ELEMENTOS DE UMA LISTA
void printar(celula *topo)
{
	celula *aux; //PONTEIRO 3: PRINTAR OS ELEMENTOS DA LISTA
	aux=topo; //PERCORRER A LISTA ENCADEADA
	if (aux == NULL)
	{
		
	}else 
	{
		printf("\nA lista encadeada atual é: \n");
	   do
	     {
		 printf("%d->",aux->elemento);
		 aux=aux->prox; //INCREMENTANDO(INDO AO PROXIMO ELEMENTO DA LISTA ENCADEADA)
	    }while (aux != NULL);
    }
}


int main()
{
	setlocale(LC_ALL,"Portuguese");
	
	int resp,numero,cont=0,num,quant=0;
	celula *topo= NULL;	
	
	do
	{
	printf("\n\n|||||||||MENU DE OPÇÕES|||||||||");
	printf("\n1-Criar lista");
	printf("\n2-Inserir elementos no início");
	printf("\n3-Inserir elementos no fim");
	printf("\n4-Inserir na posição indicada");
	printf("\n5-Printar a lista");
	printf("\n15-Sair do programa");
	printf("\nDIGITE A OPÇÃO:  ");
    scanf("%d",&resp); 
    
    if (resp == 1) 
    {
	   celula *topo= NULL;
	   printf("\nLista encadeada foi criada!\n");
    }
    
	if (resp == 2) 
	{
	   printf("Quantos números?\n");
	   scanf("%d",&quant);
	   
	   while (cont != quant)
	   {
	   	printf("Digite o número: ");
	   	scanf("%d",&num);
	    insereInicio(&topo,num);
	    cont++;
       }
       
       
	}
	
	if(resp == 3) 
	{
	printf("\nQual número você deseja acrescentar no final da lista?");
	scanf("%d",&num);
	insereFim(&topo,num);
    }
    
    if (resp == 4)
    {
        insereMeio(&topo,num);
    }
	if (resp == 5)
	    printar(topo);	// 3-6-9
	 
	 
   }while(resp != 15);
   
   printf("\nFinalizando programa.");
   exit(1);
   
}



