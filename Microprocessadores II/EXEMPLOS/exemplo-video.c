
volatile short int *MemoriaVideo = (short int *)0x08000000;

int main() {
	
  *MemoriaVideo = 0x0;
  *(MemoriaVideo+1) = 0x0;
  *(MemoriaVideo+2) = 0x0;	
  *(MemoriaVideo+3) = 0x0;	
	
  MemoriaVideo = (short int *) 0x08000000+(1024/2);
 	
  *MemoriaVideo = 0xFFFF;
  *(MemoriaVideo+1) = 0xFFFF;
  *(MemoriaVideo+2) = 0xFFFF;	
  *(MemoriaVideo+3) = 0xFFFF;	
	
  return 0;	
}
	