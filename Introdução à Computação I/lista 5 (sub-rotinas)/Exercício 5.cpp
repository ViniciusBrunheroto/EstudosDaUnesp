#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<conio.h>


int main()
{
	
	setlocale(LC_ALL,"Portuguese");
	
  
  char frase[50],novafrase[50],palavra[50];
  int i,j,vez=0,ant=0,cont=0,pos=0;
  
  setlocale(LC_ALL,"Portuguese");
  
  printf("Digite uma frase: \n");
  gets(frase);	
	
	cont=0;
    strcpy(novafrase,"");
    
	for (i = 0; i<=strlen(frase);i++)
	{
		
		if ((frase[i] == ' ' || frase[i] == '\0'))
		{
		  pos = i;
		  cont= 0;
		  for ( j = ant; j < pos ; j++)
		  {
		     palavra[cont] = frase[j];
		     cont++;	
		  }	
		  ant = i+1;
		  
		palavra[cont] = '\0';
    	cont=0;
    	
     strrev(palavra);
     
     strcat(novafrase,palavra);
     
     	if (i < strlen(frase))
		   strcat(novafrase," ");
    
        }
	
    }
	
	printf("resposta: %s",novafrase);

}
