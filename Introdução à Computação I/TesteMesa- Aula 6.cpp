#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
  int a=3, b=6, c=10;
  float x=6.8, y=5.3, media;
  char letra='s', resultado, varlog;
      
  resultado = ((x > 6.0) && (y > 6.0));
  printf("\nResultado: %d",resultado);

  resultado = ((x > 5.0) || (y > 9.0));
  printf("\nResultado: %d",resultado);

  resultado = (!(x > 6.0) && !(y > 6.0));
  printf("\nResultado: %d",resultado);

  resultado = (!(x > 6.0) || (y > 5.0));
  printf("\nResultado: %d",resultado);

  resultado = !((x > 6.0) || (y > 5.0));
  printf("\nResultado: %d",resultado);

  resultado = ( ((a+b+c)/3) > (pow(x,2) + c/3 + c%3) );
  printf("\nResultado: %d",resultado);

  resultado = ((letra == 'S') && (letra == 's'));
  printf("\nResultado: %d",resultado);
  
  resultado = ((letra != 'S') || (letra != 's'));
  printf("\nResultado: %d",resultado);

  resultado = ((letra == 'S') || (letra == 's'));
  printf("\nResultado: %d",resultado);

  resultado = ((letra != 'N') || (letra != 'n'));
  printf("\nResultado: %d",resultado);

  resultado = (!(letra == 'N') || (letra == 'n'));
  printf("\nResultado: %d",resultado);

  resultado = ((letra >= 'A' && letra <='Z') && !(letra >= 'a' && letra <='z'));
  printf("\nResultado: %d",resultado);

  if (letra == 's')
    media = (x+y)/2;
  else media = (a+b)/2;
  printf("\nMedia: %.2f",media);
  
  if ((letra!='N') && (letra!='n'))
    resultado = 1;
  else resultado = 0;  
  printf("\nResultado: %d",resultado);
  
  media = (x+y)/2.0;
  if (!(media <= 6.0))
    resultado = 1;
  else resultado = ((x+y*2)/3) > 6.0;
  printf("\nResultado: %d",resultado);

  varlog = !(0x00);
  varlog = varlog && ((x >= 6.0) || (y >= 6.0));
  if (!varlog)
    resultado = 1;
  else resultado = 0;  
  printf("\nResultado: %d",resultado);

  a = a + 5;
  b = b + c;
  if (a > b)
    a = (int)(x + 0.5);
  else a = (int)y;
  media = (a+b)/2;
  if (a < 6.0)
    a = (int)x;
  b = 6;  
  printf("\nMedia: %.2f",media);
  printf("\na: %d",a);
  printf("\nb: %d",b);
  
  getch();
}    

