#include<stdio.h>
#include<locale.h>
#include<math.h>

int main()

{
	setlocale(LC_ALL,"Portuguese");
	
	int n1, n2, n3;
	
	printf("Digite o 1� n�mero inteiro: ");
	scanf("%d",&n1);
	
	printf("Digite o 2� n�mero inteiro: ");
	scanf("%d",&n2);
	
	printf("Digite o 3� n�mero inteiro:");
	scanf("%d",&n3);
	
	if((n3 > n1) && (n3 > n2) && (n1 > n2))
	printf("\nEm ordem crescente seria: %d %d %d,",n2,n1,n3);
	
	if((n3> n1) && (n3 > n2) && (n2 > n1))
	printf("\nEm ordem crescente seria: %d %d %d, ",n1,n2,n3);
	
	if ((n2 > n1) && (n2 > n3) && (n1 > n3))
	printf("\nEm ordem crescente seria: %d %d %d, ",n3,n1,n2);
	
	if ((n2 > n1) && (n2 > n3) && (n1 < n3))
	printf("\nEm ordem crescente seria: %d %d %d, ",n1,n3,n2);
	
	if((n1 > n2) && (n1 > n3) && (n2 > n3))
	printf("\nEm ordem crescente seria: %d %d %d, ",n3,n2,n1);
	
	if((n1 > n2) && (n1 > n3) && (n2 <n3))
	printf("\nEm ordem crescente seria: %d %d %d, ",n2,n3,n1);
}
