
#include <stdio.h>


int main (int argc, char** argv){
	int inicialX,  inicialY,  finalX,  finalY;
	//printf("Movimentando torre, num args: %d\n", argc);
	
	if(argc<5) return 0;

	inicialX = *(argv[1]) - '0';
	//printf("inicialX: %c -> %d\n", *(argv[1]), inicialX);
	inicialY = *(argv[2]) - '0';
	//printf("inicialY: %c -> %d\n", *(argv[2]), inicialY);
	finalX = *(argv[3]) - '0';
	//printf("finalX: %c -> %d\n", *(argv[3]), finalX);
	finalY = *(argv[4]) - '0';
	//printf("finalY: %c -> %d\n", *(argv[4]), finalY);
	
	if((inicialX != finalX) && (inicialY != finalY)){
		//printf("Resultado: ERRO\n");
		return 1;
	}
	//printf("Resultado: Ok\n");
	return 0;
}