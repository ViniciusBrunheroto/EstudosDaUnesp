#include<stdio.h>
#include<stdlib.h>


enum diasdasemana{domingo,segunda,terca,quarta,quinta,sexta,sabado};

char matriz[][20]= {"domingo","segunda","terça","quarta","quinta","sexta","sabado"};

int main()
{
	enum diasdasemana dias;
	
	for (dias=domingo;dias<=sabado;dias++)
	{
		printf("%s\n",matriz[dias]);
	}	
}
