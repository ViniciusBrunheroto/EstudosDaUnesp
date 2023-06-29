//SUBROTINA: COPIAR UMA LISTA
//SUBROTINA: COPIAR UMA LISTA
void copiarLista(celula **topo,celula **topo2)
{
	
	celula *novo,*aux,*aux2;
	
	aux=*topo;
	aux2=*topo2;
	
	if (topo == NULL) 
	{
		printf("\nNão há nenhum elemento na lista 1! Tente adicioná-los.");
    }else
    {
	
	while(aux != NULL)
	{
	 novo= (celula *)malloc(sizeof(celula));
	 novo->elemento= aux->elemento;
	 *topo2=novo;
	 aux2->prox=novo;
	 
	 aux=aux->prox;
	}	
   }
}
