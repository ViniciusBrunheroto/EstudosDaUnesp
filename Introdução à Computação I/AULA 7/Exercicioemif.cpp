#include<stdio.h>
#include<locale.h>
#include<math.h>

int main()

{
	
	setlocale(LC_ALL,"");
	
	float n1, n2; 
	double n3, raiz;
	char opcao; 
	
	printf("Menu de op��es: ");
	printf("\n(+) para somar dois n�meros");
	printf("\n(-) para subtrair dois n�meros");
	printf("\n(*) para multiplicar dois n�meros");
	printf("\n(/) para dividir dois n�meros");
	printf("\n(@) para raiz quadrada de um n�mero");
	
	printf("\nDigite um caractere:  ");
	scanf("%c",&opcao);
	
    if (opcao != '@')
    {
	
    printf("Digite dois n�meros: ");
    scanf("%f%f",&n1,&n2);
    
    }
    
    if(opcao == '@')
    {
    
    printf("Digite um n�mero: ");
    scanf("%lf",&n3);
    
	}
    
   if(opcao == '+')
	  printf("\nA soma �: %.2f", n1 + n2);
   else
   {
     if(opcao == '-')
        printf("\nA subtra��o �: %.2f", n1 - n2);
     else
       {
         if (opcao == '*')
         printf("\nA multiplica��o � %.2f", (n1 * n2));
         else
        {
	        if (opcao == '/')
                printf("\nA divis�o � %.2f", (n1 / n2));
            else
             {
			     if (opcao == '@')
                {
    	          raiz= sqrt(n3);
                  printf("A raiz quadrada do n�mero ser�: %.2f",raiz);  
		        }	
            }
        } 
   }
	 
	 
	 
  }  

}
