

#include <stdio.h>


int main()
{
 int iVal;
 char cVal;
 void *ptr; // void pointer
 

 iVal=50; cVal=65;
 ptr=&iVal; //ponteiro aponta para ival
 
 printf("value =%d,size= %d\n",*(int*)ptr,sizeof(ptr));

 ptr=&cVal; //ponteiro aponta para cval
 printf("value =%d,size= %d\n",*(char*)ptr,sizeof(ptr));

 return 0;

}

/*  RESPOSTA: LETRA B
O tamanho de variáveis do tipo apontador é sempre 4 bytes(32 bits) ou 8 bytes(64 bits), independente do tipo
para o qual apontam. */
