


void Bubblesort(int v[],int n)
{
	int iteracao,k,aux;
	
	if (n == 1) return; //se tem um elemento nao precisa ordenar
	
	else
	{
   	   for (k=1;k < n; k++)
   	   {
   	 	 if (i[k-1] > i[k])
			{
			    aux= i[k-1];
			    i[k-1]= i[k];
			    i[k]= aux;
			} 	
	   }
	   
	   Bubblesort(v,n-1);
   	 }
}
