#include <stdio.h>
#include <locale.h>


int main()

{
	
	setlocale(LC_ALL,"Portuguese");
	
	
	const int linhas = 3;
	const int colunas = 3;
	
	float notas[linhas][colunas],menor,pos,prova1=0,prova2=0,prova3=0;
	int i,j,k;
	
	for ( i = 0 ; i < linhas ; i++) //preencher a matriz com as notas dos alunos
	{
		
	     for ( j = 0 ; j < colunas ; j++)
	     {
	      printf("Digite a nota do aluno:  ");	
		  scanf("%f",&notas[i][j]); 
		 } 	
	}
	
	
	
	for ( i = 0 ; i < linhas ; i++) //verificando a menor nota
	{
		menor = notas [0] [0];
	    pos=0;
	     for ( j = 0 ; j < colunas ; j++)
	     {
	      if (notas [i] [j] < menor)
	      {
	      menor = notas [i] [j];
	      pos = j;
	      }
	     }
	     if ( pos == 0)
	      prova1++;
	      else
	          if ( pos == 1)
	          prova2++;
	          else
	              if ( pos == 3)
	              prova3++;
	     
	printf("Aluno %d : a menor nota foi %.2f ",i+1,menor);
	}
		 
	
	printf("%d alunos tiveram menor nota na prova 1",prova1);		
	printf("%d alunos tiveram menor nota na prova 2",prova2);		
	printf("%d alunos tiveram menor nota na prova 3",prova3);		
		 
		 


		 
}
	
	
	
	
	
	

