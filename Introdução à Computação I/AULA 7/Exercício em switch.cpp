#include<stdio.h>
#include<locale.h>
#include<math.h>

int main()

{
	setlocale(LC_ALL,"");
	
	float n1, n2 ,result;
	char opcao;


	printf("Menu de opções: ");
	printf("\n(+) para somar dois números");
	printf("\n(-) para subtrair dois números");
	printf("\n(*) para multiplicar dois números");
	printf("\n(/) para dividir dois números");
	printf("\n(@) para raiz quadrada de um número");
	
	printf("\nDigite um caractere: ");
	scanf("%c",&opcao);


	switch(opcao)
	
	{
	case '+':
	
	  
	   printf("Digite dois números:  ");
	   scanf ("%f%f",&n1,&n2);
	   result= (n1 +n2);
	   printf("O resultado é: %.2f ",result);
	   break;
    
	case '-':
		
       printf("Digite dois números:  ");
	   scanf("%f%f",&n1,&n2);
	   result= (n1-n2);
	   printf("O resultado é  %.2f ",result);
	   break;
    
    
	case '*':
		
	
	
	   printf("Digite dois números:  ");
	   scanf("%f%f",&n1,&n2);
	   result= (n1*n2);
	   printf("O resultado é  %.2f ",result);
	   break;
	   
    
	case '/':
		
    
	 
	   printf("Digite dois números:  ");
	   scanf("%f%f",&n1,&n2);
	   result= (n1 / n2);
	   printf("O resultado é  %.2f ",result);
	   break;
    
	
	case '@':
		
		
	   printf("Digite um número:  ");
	   scanf("%f",&n1);
	   result= (sqrt(n1));
	   printf("O resultado é  %.2f ",result);
	   break;
    
   
   }
	
	
}
	
	
	
	
	
	
