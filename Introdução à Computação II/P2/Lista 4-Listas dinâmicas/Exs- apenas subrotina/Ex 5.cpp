

//Exercício 5: Faça uma subrotina que inverta uma lista encadeada usando recursividade



void inverterLista(celula **topo)
{
	
    int cont=1;
    celula *atual, *topoauxiliar;
    
    atual = *topo;
    topoauxiliar= atual->prox;
    
    if (topoauxiliar == NULL) return;    //CASO TRIVIAL
     
    inverterLista(&topoauxiliar);
  
  	    
	atual->prox->prox= atual;

    atual->prox=NULL;
    *topo= topoauxiliar;
	
  
}
