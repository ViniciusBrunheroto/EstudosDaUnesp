




/* 

1) ORDENAÇÃO POR TROCA:

->Repetição de comparações
->Troca de itens adjacentes

*/


/* 

BUBBLE SORT
complexidade algorítmica: O(n^2)

->Percorrer a lista sucessivas vezes
->Comparar cada item com o seu sucessor
->Fazer a troca, se necessário

*/


void bubbleSort(int i[],int n)
{
   
   int iteracao, k ,aux;
   
   for (iteracao=1; iteracao <= n ; iteracao++)
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
   	}

}
	
	

// RIPPLE SORT


void main(void)
{ 
   char s[80];
   printf("\nDigite uma string:  ");
   gets(s);

   rippleSort(s,strlen(s));
   printf("A string ordenada é: %s\n",s);
}


void rippleSort(char *item,int n)
{
	int iteracao,k;
	char t;
	
	for (iteracao=1; iteracao< n; iteracao++)
	{
		for (k=n-1; k>= i ; k--)
		{
			if (item [k-1] > item [k])
			{
				aux= item[k-1];
				item[k-1]= item[k];
				item[k]= aux;
		    }
		}
	}
	
	
}

	
	
/* 

SHAKER SORT
complexidade algorítmica : O(N^2)

->1º ETAPA: Passar os elementos menores até a parte esquerda do array e guardar a posição do último elemento trocado
->2ª ETAPA: Passar os elementos maiores até a parte direita do array e guardar a posição do último elemento trocado

1: direita->esquerda
2: esquerda->direita

*/	
	
	
void shakerSort(int item[],int cont)
{
	int a;
	int troca;
	int aux;
	
	do
	{
		troca=0;
		for (a= cont-1; a>0; a--) // DIREITA PARA ESQUERDA!
		{
			if (item[a-1] > item[a])
			{
				aux = item [a-1];
				item[a-1]= item[a];
				item[a]= aux;
				troca = 1;
			}
			
		}
		
		for (a = 1; a < cont; a++) //ESQUERDA PARA A DIREITA
        {
        	if (item[a-1] > item [a])
			{
				aux = item[a-1];
				item[a-1]= item[a];
				item[a]=aux;
				troca=1;	
			}
		}
	
    }while (troca);	
}



/* 

QUICK SORT
complexidade algorítmica : O(log(n))

->Divisão para conquista
->Selecionar um valor e partir a sequência em duas seções, com todos os elementos maiores ou iguais ao valor de um lado e os menores do outro
->Repetir o processo até a ordenação completa da matriz

Código para array e para array de string
*/	



void quick(int item[],int cont)
{
	qs(item,0,cont-1)
}


void qs(int *item[],int esq,int dir)
{
	
	int i,j;
	int x,y;
	i= esq;
	j= dir;
	x = item[(esq+dir)/2];
	do
	{
		while ((item[i]< x) && (i < dir)) i++;
		while ((x < item[j]) && (j > esq)) j--;
		
		if (i <= j)
		{
			y= item[i];
			item[i]=item[j];
			item[j]=y;
			i++;
			j--;
		}
	}while (i <= j);
	
	if (esq < j) qs(item, esq, j);
	if (i < dir) qs(item ,i, dir);	
}



// 2) ORDENAÇÃO POR SELEÇÃO


/* 

SELECTION SORT
complexidade algorítmica : O(n^2)

Variante simples = identificação do menor item e seu reposicionamento na porção inicial

versão 2=
V= vetor desordenado
Para cada posição do vetor:
-calcular o i-ésimo menor elemento do vetor
-trocar esse elemento com o de posição i no vetor, se necessário
*/	


void Selecao(int i[],int n)
{
	int k, j;
	int min, aux;
	
	
	for (k=0 ; k < n-1 ; k++)
	{
		min = k;
		{
			for (j= k+1; j < n ; j++)
			{
				if (i[j]< i[min])
				min = j;	
			}
			
			aux= i[k];
			i[k] = i[min];
			i[min]= aux;
		}
		
    }
	
}



/* 

HEAPSORT
complexidade algorítmica : O(log(n))

Parecido com o SELECTION SORT, a diferença é que será usada a estrutura de dados HEAP para selecionar o maior ou menor elemento.
HEAP= vetor que simula árvore binária completa


Construção do HEAP com os elementos a serem ordenados, seguida de sucessivas trocas do primeiro com o último e rearranjos do heap.

*/	




void lerVet( int *p, int t ){

	int i;

	for ( i=0; i 0 ) {

          i--;
          t = a[i];

      }
      else {

          n--;
          if (n == 0)
             return;

          t = a[n];
          a[n] = a[0];

      }
     
      pai = i;
      filho = i*2 + 1;
 
      while (filho < n) {

          if (( filho + 1 < n )  &&  ( a[filho + 1] > a[filho] ))
              filho++;

          if (a[filho] > t) {

             a[pai] = a[filho];
             pai = filho;
             filho = pai*2 + 1;

          }
          else
             break;

      }
      a[pai] = t;

}



int main(){

	int *p, tam;

	printf("Quantidade de elementos do vetor? ");
	scanf("%d",&tam);

	p = (int*) malloc(tam * sizeof(int));
	
	printf("\nDigite o conteudo do vetor:\n");
	lerVet(p, tam);

	printf("\nConteudo digitado para o vetor:\n");
	mostrarVet(p, tam);

	printf("\nOrdenando o vetor...\n");
	heapSort(p, tam);

	printf("\nConteudo do vetor ja ordenado:\n");
	mostrarVet(p, tam);

	free(p);

	return 0;

}





// 2) ORDENAÇÃO POR INSERÇÃO


/* 

INSERTION SORT
complexidade algorítmica : O(n^2)

1-ORDENAR OS DOIS PRIMEIROS ITENS DA SEQUENCIA
2-INSERIR O 3 ITEM NA POSICAO ORDENADA
3-INSERIR O 4 ITEM NA LISTA DOS 3
4-PROSSEGUIR ATE A ORDENACAO DE TODOS OS ELEMENTOS

*/	


void Insercao(int i[],int n)
{
	
	int chave,k,j;
	
	for (k=0 ; k < n ; k++)
	{
		
		chave = i[k];
		j=k;
		
		while ((j > 0) && (i[j-1] > chave))
		{
			i[j]= i[j-1];
			j=j-1;
		}
		
		i[j] = chave;	
	}	
}




/* 

SHELL SORT
complexidade algorítmica : ENTRE N E N^2

1-COMPOSIÇÃO DO VETOR POR VÁRIOS SEGMENTOS, CADA UM REÚNE OS ELEMENTOS QUE SE ENCONTRAM A UMA DISTÂNCIA D ENTRE SI
2- ORDENAÇÃO DE CADA SEGMENTO
*REDUÇÃO DE D E REPETIÇÃO DO PROCESSO
*REPETIÇÕES SUCESSIVAS ATÉ QUE D=1

*/	


void Shell()
{
	int i[n],d,i,j,aux;
	
	for (d= n / 2; d > 0; d= d/2)
	{
		for (i= d; i < n; i++)
		{
			for (j= i -d ; j>=0 && i[j]> i[j+d];j=j-d)
			{
				aux=i[j];
				i[j]=i[j+d];
				i[j+d]=aux;
			}
		}
	}	
}






//ORDENAÇÃO POR INTERCALAÇÃO


/* 

MERGE SORT
complexidade algorítmica : log n

1- Quebrar V em duas metades: V1 e V2 de forma que V1 tenha n/2 elementos e v2 tenha n - n/2 elementos
2- Ordene por merge sort a metade V1
3- Ordene por merge sort a metade V2
4- Intercale os elementos que compõem V1 e V2 de modo a formar um vetor V ordenado
5- Retorne V como resposta

*/	



#define NUMELEM 1000

void MergeSort(int x[],int n)
{
	int aux[NUMELEM], i,j,k,a1,a2,u1,u2,tam;
	tam=1;
	
	while(tam < n)
	{
		a1=k=0;
		
		while ((a1 + tam) < n)
		{
			a2= a1+tam;
			u1 = a2 - 1; 
            u2 = (a2+tam-1 < n) ? a2+tam-1 : n-1;
            
			for(i = a1, j = a2; i <= u1 && j <= u2; k++)
            {
             if (x[i] <= x[j]) aux[k] = x[i++];
             else aux[k] = x[j++];
            }
           for( ; i <= u1; k++) aux[k] = x[i++];
		   for( ; j <= u2; k++) aux[k] = x[j++];
           a1 = u2+1;
        }
        
        
          //copia o restante de x em aux
			for(i = a1; k < n; i++) aux[k++] = x[i];
		  //copia aux em x
			for(i = 0; i < n; i++) x[i] = aux[i];
            tam *= 2;
    }
}
