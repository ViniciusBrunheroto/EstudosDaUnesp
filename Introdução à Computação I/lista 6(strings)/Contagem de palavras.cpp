#include<stdio.h>
#include<string.h>
#include<conio.h>


int main()
{


  int i,j,ant,cont=0,contar=0,vez=0;
  char frase[50],aux[50],repete[150];


  printf("Digite uma frase: \n");
  gets(frase);
 
 for (i=0;i<strlen(frase);i++)
 {
 	pos=i;
 	if (frase == ' ' || frase =='\0')
 	{
 		for (j=ant;j < pos;j++)
 		{
 		  aux[cont]=frase[j]	
 		  cont++;	
		}
 		
 		ant=i+1;
 		aux[cont]= '\0';
 		
 		if (vez == 0)
 		{
 		  strcpy(repete,aux);
		  vez=1;
		  repete[cont]= ' ';	
		}else strcat(repete,aux);
 	
	 strlwr(frase);	

      if (strcmp(aux,frase) == 0)
      	contar++;
	}
	printf("%s %d",aux,contar);
 } 
}
