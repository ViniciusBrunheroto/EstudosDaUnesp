#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

void digitar_nome(FILE *arq,char nome_total[]);
void ler_conteudo(FILE *arq,char *string,char nome_total[]);



int main()
{
	FILE *arq;
	char nome_total[100];
	char *string;
	
	digitar_nome(arq,nome_total);
	printf("%s",nome_total);	
	
	ler_conteudo(arq,string,nome_total);
	
	exit(1);
	
}


void digitar_nome(FILE *arq,char nome_total[])
{
	int i=0;
	   
      while((nome_total[i] = fgetc(stdin)) != '\n')
	   {  
	      i++;
       }
       
       
      nome_total[i]= '\0'; 
       
}



void ler_conteudo(FILE *arq,char *string,char nome_total[])
{
	int i=0,aux,cont=0,contaux=0;
	
	if((arq= fopen(nome_total,"r")) == NULL) //abrindo o arquivo
	{
		puts("\nNao é possivel abrir o arquivo");
		exit(1);
	}	    
	    
	string = (char *) malloc(1 * sizeof(char)); //iniciando a alocação da string
    
	    
	fseek(arq,-1,2); //apontar para o final do arquivo para iniciar a leitura
	
	
	while ( string[i-1] != EOF)
	{ 	   
	   string[i]= fgetc(arq);
	   
	   i++;	   
	   cont++;
	   string= (char*)realloc(string, i+1 * sizeof(char));
	   
	   fseek(arq,-i-1,2);   
	}
	
	string[i-1]='\0';	
	 //A função  FGETC devolve EOF quando o final do arquivo é alcançado.
	 
   printf("\n%s",string);	
   
   fclose(arq);
}
