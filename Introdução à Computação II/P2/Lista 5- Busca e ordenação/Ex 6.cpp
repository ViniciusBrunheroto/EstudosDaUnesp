
void Insercao(int i[],int n, int k)
{	

    int j;
    
	if (n == 2) return;//caso trivial
	
	else
	{
		chave= i[k];
		j=k; 
		
		while ((j > 0) && (i[j-1] > chave))
		{
			i[j]= i[j-1];
			j=j-1;
		}
		
		i[j] = chave;	
		
		k++;
		
		Insercao(i,n-1,k); //chamando a subrotina
	}
	
	
		chave= i[k+1];
		j=k+1; 
		
		while ((j > 0) && (i[j-1] > chave))
		{
			i[j]= i[j-1];
			j=j-1;
		}
		
		i[j] = chave;		
}
