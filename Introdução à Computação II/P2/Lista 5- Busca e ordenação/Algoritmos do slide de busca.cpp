#include<stdio.h>
#include<stdlib.h>




//BUSCAS LINEARES : O(n)

/*
BUSCA SEQUENCIAL EM UM ARRAY
x= elemento a ser procurado
a=vetor
n=numero de posições do vetor
*/


int buscasequencial(int x,int *a, int n)
{
	int achei,i;
	
	achei=0;
	i=-1;
	
	while(i<= n && achei == 0)
	{
		i=i+1;
		if (a[i] == x)
		   achei=1;
    }
    
    if (achei== 1) return i;
    else return -1;
}


/*
BUSCA SEQUENCIAL EM UM ARRAY COM SENTINELA
x= elemento a ser procurado
a=vetor
n=numero de posições preenchidas do vetor
*/


int buscaseqSent(int x,int *a,int n)
{
	int i=0;
	a[n+1]=x; //colocando o sentinela
	
	while(x != a[i])
	{
		i++;
	}
	
	if (i ==n+1) return -1;
	else return i;
}




/*
BUSCA SEQUENCIAL EM UMA LISTA ENCADEADA  - VERSÃO ITERATIVA
 Nulo : elo (lista) nulo
 L: denota primeiro nó da lista L. Definido apenas se L não é
nula
 No.Elemento: denota o elemento armazenado em No
 No.Elo: denota o elo armazenado em No

*/


struct lista
{
	int info;
	struct lista *prox;
};
typedef struct lista Lista;


bool PesquisaLista(Lista *L, int x)
{
	Lista *p;
    bool achou = false;
	p=L; // ponteiro p aponta para o início da lista
	
	while(p != NULL && !achou)
	{
	
	   if (p->info == x)
	       achou == true;
	
	   p=p->prox;	
	}	
	
	return achou;
}


/*
BUSCA SEQUENCIAL EM UMA LISTA ENCADEADA  - VERSÃO RECURSIVA
 Nulo : elo (lista) nulo
 L: denota primeiro nó da lista L. Definido apenas se L não é
nula
 No.Elemento: denota o elemento armazenado em No
 No.Elo: denota o elo armazenado em No
*/


bool BuscaRec(int x, Lista *L)
{
	
     if (L == NULL) 
	     return false; 
     else
     if (L->elemento == x) 
         return true;
    else  
	return BuscaRec(x, L->prox);
    
}




//BUSCAS LOGARÍTMICAS : O(log n)
//ATENÇÃO: É MAIS FACIL FAZER BUSCAS BINÁRIAS QUANDO O ARRAY JÁ ESTÁ ORDENADO ( DE FORMA CRESCENTE OU DECRESCENTE)


/*
BUSCA BINÁRIA EM UM ARRAY  - VERSÃO ITERATIVA

PASSOS:
1- SELECIONAR O ELEMENTO DO MEIO DO ARRAY
MEIO = (1+N)/2

2- 
SE X = A[MEIO], O ELEMENTO PROCURADO FOI ENCONTRADO
SE X > A[MEIO], RESTRINGIR BUSCA À SEGUNDA METADE
SE X < A[MEIO], RESTRINGIR BUSCA À PRIMEIRA METADE

3- APLICAR O MESMO MÉTODO ATÉ ENCONTRAR X

*/

int buscaBin(int x, int *a,int n)
{
	
	int meio;
	int inf=0;
	int sup=n;
	
	bool achei = false;
	
	while ((!achei) && (inf <= sup))
	{
		meio = (inf+ sup) / 2;
		if (x = A[meio])
            achei = true;
		else if (x>A[meio])  inf = meio+1;
		    else sup = meio-1;	
	}


     if (!achei) 
	    meio = -1;
     
     
     return meio;
}


/*
BUSCA BINÁRIA EM UM ARRAY  - VERSÃO RECURSIVA

PASSOS:
1- SELECIONAR O ELEMENTO DO MEIO DO ARRAY
MEIO = (1+N)/2

2- 
SE X = A[MEIO], O ELEMENTO PROCURADO FOI ENCONTRADO
SE X > A[MEIO], RESTRINGIR BUSCA À SEGUNDA METADE
SE X < A[MEIO], RESTRINGIR BUSCA À PRIMEIRA METADE

3- APLICAR O MESMO MÉTODO ATÉ ENCONTRAR X

*/

int buscaBinRec(int x,int *a,int inf,int sup)
{
	int meio;
	
	if (inf > sup) return -1;
	else
    {
    	meio = (inf+sup) / 2;
    	
    	if (x < a[meio])
            return buscaBinRec(x,a,inf,meio-1)   	
    	else if (x > a[meio])
    	    return buscaBinRec(x,a,meio+1,sup);
    	else return meio;
 	
	};
}

