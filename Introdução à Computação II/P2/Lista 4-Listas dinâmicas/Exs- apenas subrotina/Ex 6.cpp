


//Exercício 6- Faça uma subrotina que remova valores duplicados de uma lista encadeada ordenada usando recursividade



void removerItem(celula **topo)
{	
	//considerando uma lista ordenada
	
	
    int cont=0,var,p=0;
    celula *auxiliar;
	
	
	
	if (*topo== NULL || (*topo)->prox == NULL) //caso trivial
	    return;
	    
	else
	{
		if ((*topo)->elemento == ((*topo)->prox)->elemento) //verificando se os elementos consecutivos sao iguais
		{
				
    		auxiliar = (*topo);
			(*topo)= (*topo)->prox; 
    		free(auxiliar);
    		removerItem(topo);
    		
		}else removerItem(&((*topo)->prox));    	
   }
}




