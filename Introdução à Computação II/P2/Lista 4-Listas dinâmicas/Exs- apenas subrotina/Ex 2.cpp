

//Exerc�cio 2: Fa�a uma subrotina que delete todos os valores pares de uma lista encadeada.


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
