#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() 
{
	FILE *pf;
	
	long i;
	
	
	pf=fopen("arquivo.txt","w");
	
	if((pf=fopen("arquivo.txt","w"))==NULL){
	
		printf("ERRO AO ABRIR O ARQUIVO");
		system("pause");
		exit(1);
		
	}
	
	fprintf(pf,"ODKAIDAIUFHDAOUIFHIAUHFAIUHFAUIFHAUIH");
	
	
	
	fclose(pf);
	
	
	pf=fopen("arquivo.txt","r");
	if((pf=fopen("arquivo.txt","r"))==NULL){
	
		printf("ERRO AO ABRIR O ARQUIVO");
		system("pause");
		exit(1);
		
	}

	fseek(pf,0,SEEK_END);
	i=ftell(pf);
	
	
	fclose(pf);
	
	printf("%d",i);
	
}