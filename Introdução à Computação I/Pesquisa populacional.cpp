#include<stdio.h>



int main()

{
	
	
  float s, st = 0, ft = 0 , maior = 0, vez = 1, mediasal, mediafilhos, psmenor;
  int ndefilhos,npessoas = 0, smenor = 0;



  printf("\nInforme o salário:   ");
  scanf("%f",&s);

  while ( s > 0)
  {
	
  printf("\nInforme o número de filhos:    ");
  scanf("%d",&ndefilhos);
  
  st = st +s;
  printf("%f",st);
  
  ft = ft+ ndefilhos;
  
  
  if (vez == 1)
   {
   maior = s;
   vez = 0;	
   }
  else
      {
      if ( s > maior)
      maior = s;
      }
	
  if ( s <= 150)
  smenor++;
  
  
  npessoas++;
  
  
  printf("Informe o salário:     ");
  scanf("%f",&s);
  
}
	
	
mediasal = st / npessoas;

mediafilhos = ft / npessoas;

psmenor = (((float)smenor / npessoas) * 100);


printf(" %f   %f   %f   %f%%",mediasal,mediafilhos,maior,psmenor);	
}
