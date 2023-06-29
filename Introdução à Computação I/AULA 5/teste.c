#include<stdio.h>
#include<locale.h>
#include<math.h>


int main()
{
	setlocale(LC_ALL,"");

	const float pi= 3.14;
	double raio, area;

	printf("Informe o valor do raio:  ");
	scanf("%lf",&raio);

	area= (pi *(pow(raio, 2.0)));


    printf("O valor da área é: %.2f \n",area);
}
