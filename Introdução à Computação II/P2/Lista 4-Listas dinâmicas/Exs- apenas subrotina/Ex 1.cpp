


//Exercício 1: Faça uma subrotina que destrua uma lista encadeada usando recursividade.




void destruirLista(celula **topo)
{
		
	if ((*topo)->prox != NULL)
	{
	destruirLista(  &((*topo)->prox )  );
	free(*topo);
	*topo = NULL;
    }
	else
	{ 
		free(*topo);
		*topo = NULL;
	}
}
