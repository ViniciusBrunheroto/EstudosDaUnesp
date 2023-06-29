
#include<stdbool.h>

volatile short int *MemVideo = (short int *)0x08000000;




void clear_screen(short int color)
{
	int i,j;
	
	//dimensões : 320 x 240
	
	for (i = 0 ; i < 320 ; i++) //linhas
	{	
	   for ( j = 0 ; j < 240 ; j ++) // colunas
	    {
	        MemVideo = (short int *) 0x08000000 + ((i * (2/2)) + (j * (1024/2)));
		   *MemVideo = color;	
	    }
	}
	
}


void draw_pixel(int x, int y, short int color)
{
		
	
   MemVideo = (short int *) 0x08000000 + ((x * (2/2)) + (y * (1024/2)));
										  
   *MemVideo = color;										  
		
}




void draw_line(int x0,int y0,int x1,int y1,short int color)
{
	
	//ALGORITMO DE BRESENHAM 
	
	int deltax,deltay,y_passo,x,y,temp;
	float erro, incl;
	bool eh_ingrime;
	
	eh_ingrime = (abs(y1-y0) > abs(x1-x0));
	
	if (eh_ingrime)
	{
	//swap(x0, y0)
		temp = x0;
		x0= y0;
		y0=temp;
		
	//swap(x1, y1)
		temp = x1;
		x1=y1;
		y1=x1;
		
	}
	
	if (x0 > x1)
	{
	//swap(x0, x1)
		temp = x0;
		x0= x1;
		x1=temp;
		
	//swap(y0, y1)
		temp = y0;
		y0=y1;
		y1=temp;
	}
	
	deltax = (x1- x0);
	deltay = abs(y1-y0);
		
	incl = (float) deltay / deltax;
		
	y=y0;
		
	if(y0 < y1)
		y_passo = 1;
	else y_passo = -1;
		
		
	for (x= x0 ; x <x1;x++)
	{
		if (eh_ingrime)
			draw_pixel(y,x,color);
		else draw_pixel(x,y,color);
		
		erro = erro + incl;
		
		if (erro >= 0.5)
		{
			y= y + y_passo;
			erro = erro-1;
		}
	}
		
		
}	

int main()
{
	
	int x0,y0,x1,y1;
	short int color;
	
	//definir o valor das variáveis
	     
	color= 0xffff;   //pintar o fundo de branco

	clear_screen(color);
	

	color= 0xF81F; // pintar pixel de roxo

	
	x0=1;
    y0=1;
	x1=12;
	y1=5;
	
	// LINHA 1 = roxo
	draw_line(x0,y0,x1,y1,color);
	
	
	x0=20;
    y0=10;
	x1=30;
	y1=18;
	
	
	
	color= 0X0; // pintar pixel de preto
	
	// LINHA 2 = preto
	draw_line(x0,y0,x1,y1,color);
	
	
	
	x0=10;
    y0=10;
	x1=20;
	y1=5;
	
	
	
	color= 0Xf800; // pintar pixel de vermelho
	
	// LINHA 2 = preto
	draw_line(x0,y0,x1,y1,color);
	
	

	
	
    return 0;	
}
	
	