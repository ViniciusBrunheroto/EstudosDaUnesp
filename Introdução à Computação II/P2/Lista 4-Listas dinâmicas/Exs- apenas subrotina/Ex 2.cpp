

//Exercício 2: Faça uma subrotina que delete todos os valores pares de uma lista encadeada.


void removerporValor(celula **topo)
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
        	    while (aux->elemento % 2 != 0)// pular nó
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
