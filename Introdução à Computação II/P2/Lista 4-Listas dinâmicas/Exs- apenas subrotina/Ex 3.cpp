

//Exercício 3- Faça uma subrotina que delete todos os nós (posições) pares de uma lista encadeada.


void removerporPosicao(celula **topo)
{
	
    int cont=1;
    celula *anterior, *atual, *aux;
	
    if (*topo == NULL) 
	{
		printf("\nNão há nenhum elemento na lista! Tente adicioná-los.");
    }else
    
    {
    anterior = *topo;
	atual= *topo;
	aux= *topo;
    

        while(atual->prox != NULL)
		{
		   cont=1;
		   while (cont % 2 != 0) //percorrendo a lista (pular nó)
		   {
		   	     anterior=aux;
		         aux = aux->prox;
		         cont++;
		         atual=aux;
		    
		   }
				        
			if (aux != NULL) // ENCONTROU UM ELEMENTO NO MEIO DA LISTA
			{	
			    anterior->prox = atual->prox; 
			    aux= atual->prox;
			    free(atual);
	        }else
	        {
	        
	        
	        if (aux == NULL) //	ENCONTROU O ULTIMO ELEMENTO
			{
			   	atual= anterior;
			   	atual->prox=NULL;	 	
		    }
	       }
    }
    
}
}
