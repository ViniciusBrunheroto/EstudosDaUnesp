#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

void testar(FILE *pf);

int main()
{

	FILE *pf;
	char frase[30];

	pf=fopen("arquivo.txt","wb");
	if(pf==NULL)
	{
			printf("Não foi possievl abrir o arquivo");
			system("pause");
			exit(1);
	}


	printf("Digite a frase para preencher o arquivo:\n");
	fgets(frase,sizeof(frase),stdin);

	fprintf(pf,"%s",frase);

	fclose(pf);

	testar(pf);

}


void testar(FILE *pf)
{

int i;
	char leitura[1000];

	pf=fopen("arquivo.txt","rb");

	if(pf==NULL)
	{
			printf("Não foi possievl abrir o arquivo");
			system("pause");
			exit(1);
	}

	fread(leitura,sizeof(char),1000,pf);
	for(i=0;i<strlen(leitura);i++)
	{
		leitura[i]=toupper(leitura[i]);
	}

	for(i=0;i<strlen(leitura);i++)
	{
		if(leitura[i]=='S')
		{
			if(leitura[i+1]=='E')
			{
				if(leitura[i+2]=='N')
				{
					if(leitura[i+3]=='H')
					{
						if(leitura[i+4]=='A')
						{
							system("cls");
							printf("\nA palavra SENHA aparece no arquivo\n");
						}
					}
				}
			}
		}


	}



	fclose(pf);





}
