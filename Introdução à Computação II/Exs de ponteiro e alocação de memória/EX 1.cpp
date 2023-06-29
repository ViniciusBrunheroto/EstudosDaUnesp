#include <stdio.h>




int main()
{
	
char *str="IncluiAjuda";
printf("%c\n",*&*str);
return 0;


}

/*A saída será I,a primeira letra de "IncluiAjuda", portanto letra C.
O programa se baseia em uma varíavel apontando para char, definindo uma string. Com isso, o valor inicial desse ponteiro
será o endereço do primeiro caracter da string, nesse caso "I".
-&*str diz respeito ao endereço do primeiro caracter
-*&*str faz printar o conteúdo desse primeiro endereço, que no caso é I.

Lembre- se que toda constante string terá um tipo e valor associado. */

