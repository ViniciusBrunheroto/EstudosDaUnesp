
	

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


int main()
{
	
	int x,y;
	short int color;
	
	//definir o valor das variáveis
	
	//1) coordenadas (X,Y)
	x = 0;
	y = 3;
     
	color= 0xffff;   //pintar o fundo de branco

	clear_screen(color);
	
	color= 0xF81F; // pintar pixel de roxo
	
	draw_pixel(x,y,color);
	
    return 0;	
}