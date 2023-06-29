//TAMANHO DO ARQUIVO EM BYTES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

int linhas=0;
int op=1;
char ene;

FILE *pf;

int i,j;
char frase[20];
char arquivototal[1000];



pf=fopen("arquivo.txt","w+b");
if(pf==NULL)
{
	printf("Erro ao abrir o arquivo");
	system("pause");
	exit(1);
}
do{

printf("Escreva a frase para ser gravada no arquivo:\n");
fgets(frase,sizeof(frase),stdin);//FGETS JA ADICIONA UM \N NO FINAL DA FRASE
fflush(stdin);
fprintf(pf,"%s",frase);
printf("Deseja escrever outra linha? 1[S]  0[N]\n");
scanf("%d",&op);
fflush(stdin);

}while(op==1);

fclose(pf);

pf=fopen("arquivo.txt","rb");
if(pf==NULL)
{
	printf("Erro ao abrir o arquivo");
	system("pause");
	exit(1);
}
rewind(pf);
fread (arquivototal, sizeof(char), 1000,pf);

for(i=0;i<strlen(arquivototal);i++)
{
	if(arquivototal[i]=='\n')
		linhas++;
	
}
printf("%d",linhas);

fclose(pf);





}
