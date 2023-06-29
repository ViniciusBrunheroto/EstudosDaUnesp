#include<stdio.h>
#include<locale.h>



int main()

{
	setlocale(LC_ALL,"Portuguese");
	
	
	const int tam = 10;

	int qvendida[tam], pos,i;
	float valor[tam], maior,vgeral,vtotal;
	
	
	for (i = 0; i < tam ; i++)
	{
		
	printf("Digite o valor do objeto: \n");
	scanf("%f",&valor[i]);	
		
	printf("Digite a quantidade vendida do objeto:   \n");
	scanf("%d",&qvendida[i]);
	
	}
	
	vgeral=0;
	vtotal=0;
	
	for ( i = 0; i < tam; i++)
	{
	vtotal= (qvendida[i] * valor[i]);	
	printf("A quantidade vendida do objeto %d foi: %d\n",i+1,qvendida[i]);
	printf("O valor unitário do objeto %d é: %.2f\n",i+1,valor[i]);
	printf("O valor total do objeto é %.2f\n",vtotal);
	vgeral=( vgeral + vtotal);
	}
    
    printf("O valor geral das vendas é: %.2f\n",vgeral);
    
    maior = qvendida[0];
    pos= 0;
    for (i = 1; i < tam; i++)
	{
	if (qvendida[i] > maior)
	  {	
	   maior = qvendida[i];
	   pos= i;
	   }
	
	}
	
	
	printf("A maior quantidade vendida foi: %.2f e sua posição no vetor é:  %d\n\n",maior,pos+1);
	
	
	
	
	
	
	
	
	
	
}
