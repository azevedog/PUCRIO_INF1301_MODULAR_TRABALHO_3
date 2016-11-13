
#include <stdio.h>
#include <math.h>


int main (int argc, char** argv){
	int inicialX,  inicialY,  finalX,  finalY;
	//printf("Movimentando Rei, num args: %d\n", argc);
	
	if(argc<5) return 0;

	inicialX = *(argv[1]) - '0';
	//printf("inicialX: %c -> %d\n", *(argv[1]), inicialX);
	inicialY = *(argv[2]) - '0';
	//printf("inicialY: %c -> %d\n", *(argv[2]), inicialY);
	finalX = *(argv[3]) - '0';
	//printf("finalX: %c -> %d\n", *(argv[3]), finalX);
	finalY = *(argv[4]) - '0';
	//printf("finalY: %c -> %d\n", *(argv[4]), finalY);
	
	if((pow((inicialX-finalX), 2)>1) || (pow((inicialY - finalY),2)>1)){
		//printf("Resultado: ERRO\n");
		return 1;
	}
	//printf("Resultado: Ok\n");
	return 0;
}