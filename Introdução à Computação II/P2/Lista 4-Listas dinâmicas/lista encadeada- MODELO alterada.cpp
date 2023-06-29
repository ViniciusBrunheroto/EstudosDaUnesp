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


//SUBROTINA: INSERIR ELEMENTOS EM UMA POSIÇÃO DA LISTA
void insereMeio(celula **topo, int num) // **topo pois é necessario alterar elementos
{
	int n,cont=0,numpos=0,aux2;
	//2 ponteiros necessários
    celula *novo2;
    celula *aux;
	
	novo2= (celula *)malloc(sizeof(celula));	
	
	if (*topo == NULL) // caso a lista esteja no início, fazer uma subrotina para incluir elementos no início
	{
		printf("\nNão há nenhum elemento na lista! Tente adicioná-los.");
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
	 novo2->prox= aux->prox;
	 aux->prox=novo2;
    }
}


//SUBROTINA: REMOVER OS ELEMENTOS DE UMA LISTA POR VALOR
void excluirPorValor(celula **topo)
{
    int valor;
	celula *anterior, *atual;
	
	printf("\nQual é o elemento a ser excluído? ");	
	scanf("%d",&valor);
	
	if (*topo == NULL) 
	{
		printf("\nNão há nenhum elemento na lista! Tente adicioná-los.");
    }else
    {
    	
    	anterior=*topo;
    	atual=*topo;
    	
    	while(atual != NULL)
    	{
    		   if (atual->elemento == valor) // ENCONTREI O ELEMENTO
    		   {
    		   	    if (atual == *topo) // SE O ELEMENTO ESTIVER NO INÍCIO
    		   	    {
						(*topo)= (*topo)->prox; //pega o ponteiro inicio e joga para o próximo elemento
    		   	        free(atual);
    		   	        break;
					}
			         else
			             {
			   	           if (atual == NULL) //	SE O ELEMENTO ESTIVER NO FINAL
			   	           {
			   	            atual= anterior;	
				           }
				
				            //REFAZENDO O ENCADEAMENTO
				
				            anterior->prox = atual->prox; 
				            free(atual);
				            break; 	
		                  }
		     
		        }
		else
		{
			//SE NÃO ENCONTRAR O ELEMENTO, FAZ OS PONTEIROS SE DESLOCAREM
			anterior=atual;
			atual=atual->prox;
		}	   	
	
	}
  }
}

//SUBROTINA: REMOVER OS ELEMENTOS DE UMA LISTA POR POSIÇÃO
void excluirPorPosicao(celula **topo)
{
    int posicao,cont=0;
	celula *anterior, *atual;
	
	printf("\nQual é a posição a ser excluído? ");	
	scanf("%d",&posicao);
	
	if (*topo == NULL) 
	{
		printf("\nNão há nenhum elemento na lista! Tente adicioná-los.");
    }else
    {
    	
    	anterior=*topo;
    	atual=*topo;
    	
    	while(atual != NULL)
    	{
    		if(cont == posicao) //percorrendo a lista
		   {
		   
		     if (cont == 0) // SE O ELEMENTO ESTIVER NO INÍCIO
    		{
			   (*topo)= (*topo)->prox; //pega o ponteiro inicio e joga para o próximo elemento
    		   	free(atual);
    		   	break;
			}
			   else 
			   {
			   	if (atual == NULL) //	SE O ELEMENTO ESTIVER NO FINAL
			   	  {
			   	    atual= anterior;	
				  }
				  
				//REFAZENDO O ENCADEAMENTO
				
				anterior->prox = atual->prox;
				free(atual);
				break;
		      }
		    }else
		    {
			anterior=atual;
		   	atual=atual->prox;
		   	cont++;
		   }
		   	
      }
    }
}


//SUBROTINA: VERIFICAR SE UM ELEMENTO EXISTE NA LISTA
bool verificarElemento(celula *topo)
{
	int elemento;
	celula *aux;	
	int resposta;
	
	printf("\nQual elemento deseja verificar se existe na lista? ");
	scanf("%d",&elemento);
	
	
	if (topo == NULL)
	{
		printf("\nNão há nenhum elemento na lista! Tente adicioná-los.");
	}
	else
	{
		aux=topo;
		
		while(aux != NULL)
		{
			if (aux->elemento == elemento)
			{
				return true;
			}else aux= aux->prox;
			
		}
		return false;
	}
}


//SUBROTINA: BUSCAR OS ELEMENTOS POR VALOR
void buscarPorValor(celula *topo)
{
	celula *aux;
	int elemento,pos=0,achou=0;
	
	
	printf("\nQual elemento deseja buscar na lista? ");
	scanf("%d",&elemento);
	
	if (topo == NULL)
	{
		printf("\nNão há nenhum elemento na lista! Tente adicioná-los.");
	}
	else
	{
	
	aux = topo;
	
		while(aux != NULL)
		{
			if (aux->elemento == elemento)
			{
			achou=1;
            printf("O elemento %d está presente na lista na posição %d",elemento,pos+1);
            break;
			}else
			{ 
			aux= aux->prox;
	        pos++;
	        }
        }
        
    if (!achou)
        printf("O elemento %d não está presente na lista.",elemento);
     }
     
}

//SUBROTINA: BUSCAR OS ELEMENTOS POR POSIÇÃO
void buscarPorPosicao(celula *topo)
{
	celula *aux,*anterior;
	int posicao=0,cont=0;
	
	
	printf("\nQual posição deseja buscar na lista? ");
	scanf("%d",&posicao);
	
	aux = topo;
	anterior= topo;
	if (topo == NULL)
	{
		printf("\nNão há nenhum elemento na lista! Tente adicioná-los.");
	}
	else
	{
	while (cont != posicao) //percorrendo a lista
	 {
	 	anterior=aux;
		aux=aux->prox;
		cont++;
	 }
	
	
	printf("\nNa posição %d está o elemento %d",cont,anterior->elemento);
	
    } 

}

//SUBROTINA: TESTAR SE UMA LISTA É VAZIA
void testarLista(celula *topo)
{
	
	if (topo == NULL)
	    printf("\nA lista está vazia!");
	else printf("\nA lista não está vazia!");
}


//SUBROTINA: COPIAR UMA LISTA
void copiarLista(celula **topo,celula **topo2)
{
	
	celula *aux,*aux2;
	celula *temp=NULL;
	
	 aux=*topo; //percorrer a 1 lista
	 aux2=*topo2;  //percorrer a 2 lista
	 
	 //se lista a ser copiada estiver vazia, n faz nada 
	 if (*topo == NULL) 
	{
		printf("\nNão há nenhum elemento na lista 1! Tente adicioná-los.");
    }
	else//else, copia
    {
        if (*topo2 == NULL)
        {
        	temp= (celula *)malloc(sizeof(celula));
        	temp->elemento= aux->elemento;
        	temp->prox=NULL;
        	
        	*topo2=temp;
        	aux=aux->prox;
		}
		
		while(aux != NULL) //copiar para uma pilha temporária
		{
			temp= (celula *)malloc(sizeof(celula));
			temp->elemento= aux->elemento;
			temp->prox= *topo2;
			*topo2=temp;
			
			aux=aux->prox;
			
		}

	    aux=NULL;
	    aux2=NULL;
	    
	    while(*topo2 != NULL)//copiando para a lista 2
	    {
	    	if (aux == NULL)
	    	{
	    		aux= *topo2;
	    		*topo2= (*topo2)->prox;
	    		aux->prox=NULL;
			}
			else
			{
				aux2= *topo2;
				*topo2=(*topo2)->prox;
				aux2->prox= aux;
				aux = aux2;
		    }
		    
	    }
    
    	*topo2= aux;
			
			
    }
    	
}

//SUBROTINA: PRINTAR A LISTA 2
void printarLista2(celula *topo2)
{
	celula *aux2; 
	aux2=topo2; 
	if (aux2 == NULL)
	{
		
	}else 
	{
		printf("\nA lista encadeada 2,que foi copiada é: \n");
	   do
	     {
		 printf("%d->",aux2->elemento);
		 aux2=aux2->prox; //INCREMENTANDO(INDO AO PROXIMO ELEMENTO DA LISTA ENCADEADA)
	    }while (aux2 != NULL);
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
	


//SUBROTINA: DESTRUIR UMA LISTA
void destruirLista(celula **topo)
{
    celula *aux,*aux2;
    
    aux=*topo;
    
    while(aux != NULL)
    {
    aux2= aux->prox;
	free(aux);
	aux=aux2;	
	}

   *topo= NULL;
}
	
	
	
//SUBROTINA: FUNDIR DUAS LISTAS	
void fundirLista(celula **topo,celula **filho)
{
	
	celula *aux;
	celula *aux2;
	
	aux= *topo;
	aux2= *filho;
	
	while (aux->prox != NULL)
	{
		aux=aux->prox;
	}
	
	aux->prox=aux2;
	
}



void criar2lista(celula **filho,int num)
{
	celula *novo; 
	
	novo= (celula *)malloc(sizeof(celula));
	novo->elemento= num;
	
	if (*filho == NULL)// condição em que não existe elementos na lista, apenas o topo
	{
		novo->prox= NULL; 
		*filho=novo;
	}else
	{ //condição em que já existe elementos na lista
		novo->prox= *filho; 
	*filho=novo;
	}		
}




//SUBROTINA: TIRAR ELEMENTOS DUPLICADOS (UM ATRAS DO OUTRO)
void tirarDuplicados(celula **topo)
{
	
	int cont=0;
    celula *anterior, *atual,*aux;
	
    if (*topo == NULL) 
	{
		printf("\nNão há nenhum elemento na lista! Tente adicioná-los.");
    }else
    
    
    aux=*topo;
    anterior=*topo;
    atual=*topo;
    
    	cont=0;
    	
        while(aux->prox != NULL)
		{
        		atual = aux;
        		while (aux->elemento != aux->prox->elemento)// pular nó
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
			               if (aux->prox == NULL) //SE O ULTIMO ELEMENTO FOR IGUAL
		                 {
			            	atual= anterior;
			          	    atual->prox=NULL;	 	
		                 }
					}
					}		
	    }
}

//SUBROTINA PARA TIRAR ELEMENTOS REPETIDOS
void tirarRepetidos(celula **topo,celula **topo2)
{
    int vez=0,var,p=0;
    
    celula *novo;
    celula *auxiliar;
    celula *aux,*aux2;
        
    aux= *topo;
    aux2= *topo2;
    
    
    while(aux != NULL)
    {
        var=aux->elemento;
		aux2= *topo2;
		
		if (vez != 0)
		{
			p=0;
			auxiliar= *topo2;
			
		   while (auxiliar != NULL) //percorrendo a lista
		   {
		   	if (var == auxiliar->elemento)
		   	    p++;
		   	    
		   	auxiliar=auxiliar->prox;
		   }  
	    }
	    
	    if (vez == 0 || p == 0) 
		{	
		// insereFim (topo2,var);
		  
		   novo= (celula *)malloc(sizeof(celula));
		   
		   //ADICIONANDO O ELEMENTO À NOVA LISTA
		     
		   if (*topo2 == NULL) // 1 inserção
		   {
		   novo->elemento=var;
    	   novo->prox=NULL;
    	   *topo2 =novo;
           }
		   else
           {
           	auxiliar= *topo2;
		    
			while(auxiliar->prox != NULL)//2 inserção
		        {
			     auxiliar=auxiliar->prox;
		        }
		
	        novo->elemento=var;
	        novo->prox=NULL;
	        auxiliar->prox=novo;
			}
			 	
     	  vez++;
     	}

      aux=aux->prox;
    }		
    
    *topo= *topo2;
}
		
		

//SUBROTINA: PRINTAR OS ELEMENTOS DE UMA LISTA
void printar(celula *topo)
{
	celula *aux; //PONTEIRO 3: PRINTAR OS ELEMENTOS DA LISTA

		
	aux=topo;
			
	if (aux == NULL)
	{
		printf("\nA lista selecionada não existe!");
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
	
	int resp,numero,num,num2,quant=0,cont;
	celula *topo= NULL;
	celula *topo2=NULL;
    bool resposta;
    char t,resposta2;
    celula *q1,*q2,*q3;
    
	do
	{
	cont=0;
	t=0;
	
	printf("\n\n|||||||||MENU DE OPÇÕES|||||||||");
	printf("\n1-Criar lista");
	printf("\n2-Inserir elementos na lista");
	printf("\n3-Excluir um elemento da lista");
	printf("\n4-Verificar se um elemento existe na lista");
	printf("\n5-Buscar elemento ");
	printf("\n6-Testar se a lista é vazia");
	printf("\n7-Fazer a cópia da lista");
	printf("\n8-Inverter a lista");
	printf("\n9-Fundir duas listas");
	printf("\n10-Destruir a lista");
	printf("\n11-Retirar valores duplicados");
	printf("\n12-Retirar valores repetidos(BETA TEST)");
	printf("\n13-Printar a lista");
	printf("\n15-Sair do programa");
	printf("\nDIGITE A OPÇÃO:  ");
    scanf("%d",&resp); 
    
    if (resp == 1) 
    {
	   printf("\nLista encadeada foi criada!\n");
    }
    
	if (resp == 2) 
	{
	   printf("\nDeseja inserir: ");
       printf("\n(I)-No início");
       printf("\n(M)-No meio");
       printf("\n(F)-No final");
       printf("\n===>Digite a opção:  ");
       scanf(" %c",&t);
		
		
		if (t == 'I')
		{
	    printf("Quantos números?\n");
	    scanf(" %d",&quant);
	   
	    while (cont != quant)
	   {
	   	printf("Digite o número: ");
	   	scanf(" %d",&num);
	    insereInicio(&topo,num);
	    cont++;
       }
       
       }
       
       if (t == 'M')
          insereMeio(&topo,num);
       
       if (t == 'F')
       	{
       		
       		printf("Quantos números?\n");
	        scanf(" %d",&quant);
	        
	        
	     	while (cont != quant)//INSERIR ELEMENTOS NA LISTA
          	{
           	printf("Digite o número: ");
	        scanf(" %d",&num);
	        insereFim(&topo,num);
	         cont++;
            }
        }
       
	}
	
    
    if (resp == 3)
    {
    printf("\nDeseja excluir: ");
    printf("\n(V)-Por valor");
    printf("\n(P)-Por posição");
    printf("\n===>Digite a opção:  ");
    scanf(" %c",&t);
    
    if (t == 'V')
        excluirPorValor(&topo);
    if (t == 'P')  
	    excluirPorPosicao(&topo);  
    }
    
    
    if (resp == 4)
    {
    resposta= verificarElemento(topo);
    
    if(resposta)
       printf("\nO elemento está na lista!");
    else printf("\nO elemento não está na lista!");
	}
	
	if (resp == 5)
	{
	printf("\nDeseja buscar: ");
    printf("\n(V)-Por valor");
    printf("\n(P)-Por posição");
    printf("\n===>Digite a opção:  ");
    scanf(" %c",&t);
    
    if (t == 'V')
       buscarPorValor(topo);
    if (t == 'P')  
	   buscarPorPosicao(topo);
    }
    
    if (resp == 6)
      testarLista(topo);
    
    
    if (resp == 7)
    {
    	celula *topo2 = NULL;
    	copiarLista(&topo,&topo2);
    	printf("\nDeseja verificar como ficou a lista 2? ");
    	printf("\n(S) para SIM");
    	printf("\n(N) para NÃO");
    	printf("\nDigite a opção:  ");
    	scanf(" %c",&resposta2);
    	
    	if (resposta2 == 'S')
    	   printarLista2(topo2);
	}
	
	if (resp == 8)
	   inverterLista(&topo);
	   
	if (resp == 9)
	{
		cont=0;
		//celula *topo= NULL; 1 lista
		
		celula *filho =NULL;  // 2 lista
		
		printf("Quantos elementos? ");
		scanf("%d",&num2);
		do
		{
        printf("Digite o número: ");			
	   	scanf(" %d",&num);
		criar2lista(&filho,num);
		cont++;	
		}while(cont != num2);
	
		fundirLista(&topo,&filho);
	}
	
	if (resp == 10)
	   destruirLista(&topo);
	   
	   
	if (resp == 11)
	    tirarDuplicados(&topo);
	
    if (resp == 12)
       tirarRepetidos(&topo,&topo2);

	if (resp == 13)
	    printar(topo);
	 
	 
   }while(resp != 15);
   
   printf("\nFinalizando programa.");
   exit(1);
   
}

