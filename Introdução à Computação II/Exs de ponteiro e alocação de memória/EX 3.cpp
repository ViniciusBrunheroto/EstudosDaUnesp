#include <stdio.h>



int main()
{
 char *str []={"AAAAA","BBBBB","CCCCC","DDDDD"};
 char **sptr []={str+3,str+2,str+1,str};
 
*str+3;
*str+2;
*str+1;
*str;
 char ***pp; //pp � ponteiro para ponteiro de char
 
 pp=sptr;
 
 ++pp; // pp soma um entao vai ficar str+2
 
 printf("%s",**++pp+2); //primeiro ele soma mais um ent�o fica str+1, que � onde est� o "BBBBB", somando apenas 2 elementos.
 return 0;
}

/* RESPOSTA: letra C)BBB 

pp aponta para sptr
sptr aponta para str

*/





