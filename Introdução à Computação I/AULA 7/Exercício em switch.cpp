#include<stdio.h>
#include<locale.h>
#include<math.h>

int main()

{
	setlocale(LC_ALL,"");
	
	float n1, n2 ,result;
	char opcao;


	printf("Menu de op��es: ");
	printf("\n(+) para somar dois n�meros");
	printf("\n(-) para subtrair dois n�meros");
	printf("\n(*) para multiplicar dois n�meros");
	printf("\n(/) para dividir dois n�meros");
	printf("\n(@) para raiz quadrada de um n�mero");
	
	printf("\nDigite um caractere: ");
	scanf("%c",&opcao);


	switch(opcao)
	
	{
	case '+':
	
	  
	   printf("Digite dois n�meros:  ");
	   scanf ("%f%f",&n1,&n2);
	   result= (n1 +n2);
	   printf("O resultado �: %.2f ",result);
	   break;
    
	case '-':
		
       printf("Digite dois n�meros:  ");
	   scanf("%f%f",&n1,&n2);
	   result= (n1-n2);
	   printf("O resultado �  %.2f ",result);
	   break;
    
    
	case '*':
		
	
	
	   printf("Digite dois n�meros:  ");
	   scanf("%f%f",&n1,&n2);
	   result= (n1*n2);
	   printf("O resultado �  %.2f ",result);
	   break;
	   
    
	case '/':
		
    
	 
	   printf("Digite dois n�meros:  ");
	   scanf("%f%f",&n1,&n2);
	   result= (n1 / n2);
	   printf("O resultado �  %.2f ",result);
	   break;
    
	
	case '@':
		
		
	   printf("Digite um n�mero:  ");
	   scanf("%f",&n1);
	   result= (sqrt(n1));
	   printf("O resultado �  %.2f ",result);
	   break;
    
   
   }
	
	
}
	
	
	
	
	
	
