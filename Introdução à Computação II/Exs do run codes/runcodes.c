#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void digitar_nome(char nome_total[]);
void ler_conteudo(char nome_total[]);

FILE *arq;
char *string;

int main()
{
	char nome_total[100];
	
	digitar_nome(nome_total);
	//printf("%s",nome_total);	
	
	ler_conteudo(nome_total);
	
}


void digitar_nome(char nome_total[])
{
	int i=0;  
	   
     while(nome_total[i-1] != '\n')
	   {  
          nome_total[i] = fgetc(stdin);
	      i++;
       }
       
       
      nome_total[i-1]= '\0';      
}



void ler_conteudo(char nome_total[])
{
	int i=0,cont=0,pos;
	char aux[50];
	
	if((arq= fopen(nome_total,"r")) == NULL) //abrindo o arquivo
	{
		puts("\nNao é possivel abrir o arquivo");
		exit(1);
	}
	
		    
    fflush(stdin);	
	    
	string = (char *) malloc(1 * sizeof(char)); //iniciando a alocação da string
		
    fseek(arq,-1,2); //apontar para o final do arquivo para iniciar a leitura
	
	
	while (string[i-1] != EOF)
	{
	   fflush(stdin); 	   
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
   
   free(string);
   
   
}
