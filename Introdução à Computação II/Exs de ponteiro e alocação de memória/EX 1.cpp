#include <stdio.h>




int main()
{
	
char *str="IncluiAjuda";
printf("%c\n",*&*str);
return 0;


}

/*A sa�da ser� I,a primeira letra de "IncluiAjuda", portanto letra C.
O programa se baseia em uma var�avel apontando para char, definindo uma string. Com isso, o valor inicial desse ponteiro
ser� o endere�o do primeiro caracter da string, nesse caso "I".
-&*str diz respeito ao endere�o do primeiro caracter
-*&*str faz printar o conte�do desse primeiro endere�o, que no caso � I.

Lembre- se que toda constante string ter� um tipo e valor associado. */

