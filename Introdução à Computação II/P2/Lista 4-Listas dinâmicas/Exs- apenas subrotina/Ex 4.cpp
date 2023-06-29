

// Exercício 4: Faça uma subrotina que delete todas as ocorrências de um dado item em uma lista encadeada



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
