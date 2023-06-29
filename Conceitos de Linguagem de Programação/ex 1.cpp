#include<stdio.h>
#include<stdlib.h>


void aleph(int *x,int *y, int z)
{
	*y= *y+5;
	*y= *x+z+4;
	printf("%d %d %d\n",*x,*y,z);	
}

int main(){
	int j=10;
	int k=15;
	aleph(&j,&j,j+k);
	printf("%d,%d\n",j,k);
	
	
	
}
