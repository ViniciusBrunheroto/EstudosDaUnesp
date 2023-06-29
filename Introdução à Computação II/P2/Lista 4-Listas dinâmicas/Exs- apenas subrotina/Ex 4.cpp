

// Exerc�cio 4: Fa�a uma subrotina que delete todas as ocorr�ncias de um dado item em uma lista encadeada



void removerItem(celula **topo)
{
	
    int cont=0,item;
    celula *anterior, *atual,*aux;
	
    if (*topo == NULL) 
	{
		printf("\nN�o h� nenhum elemento na lista! Tente adicion�-los.");
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
           while (aux->elemento != item && aux->prox != NULL) //percorrendo a lista (pular n�)
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
