#include<stdio.h>
#include<locale.h>
#include<math.h>

int main()

{
	
	setlocale(LC_ALL,"");
	
	float n1, n2; 
	double n3, raiz;
	char opcao; 
	
	printf("Menu de opções: ");
	printf("\n(+) para somar dois números");
	printf("\n(-) para subtrair dois números");
	printf("\n(*) para multiplicar dois números");
	printf("\n(/) para dividir dois números");
	printf("\n(@) para raiz quadrada de um número");
	
	printf("\nDigite um caractere:  ");
	scanf("%c",&opcao);
	
    if (opcao != '@')
    {
	
    printf("Digite dois números: ");
    scanf("%f%f",&n1,&n2);
    
    }
    
    if(opcao == '@')
    {
    
    printf("Digite um número: ");
    scanf("%lf",&n3);
    
	}
    
   if(opcao == '+')
	  printf("\nA soma é: %.2f", n1 + n2);
   else
   {
     if(opcao == '-')
        printf("\nA subtração é: %.2f", n1 - n2);
     else
       {
         if (opcao == '*')
         printf("\nA multiplicação é %.2f", (n1 * n2));
         else
        {
	        if (opcao == '/')
                printf("\nA divisão é %.2f", (n1 / n2));
            else
             {
			     if (opcao == '@')
                {
    	          raiz= sqrt(n3);
                  printf("A raiz quadrada do número será: %.2f",raiz);  
		        }	
            }
        } 
   }
	 
	 
	 
  }  

}
