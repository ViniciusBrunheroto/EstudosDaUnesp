#include <stdio.h>
#include <locale.h>

int main()
{
	float n1, n2, n3 , p1, p2, p3 , media;
	
	setlocale(LC_ALL,"");
	
	printf("Entre com n1: ");
	scanf("%f",&n1);
	printf("Entre com n2: ");
	scanf("%f",&n2);
	printf("Entre com n3: ");
	scanf("%f",&n3);
	
	printf("Entre com os pesos: ");
	scanf("%f%f%f",&p1,&p2,&p3);
	
	media = ((n1*p1) + (n2*p2) + (n3*p3))/ (p1+p2+p3);
	printf ("A media e: %.2f", media);
}
