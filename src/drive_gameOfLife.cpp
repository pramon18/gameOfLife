#include <iostream>
#include <fstream>
#include <string>
#include "gameOfLife.h"

using namespace std;
int main(int argc, char *argv[]){
	/*Recebendo arquivo com configuração inicial da linha de comando*/
	fstream confInit;
	confInit.open(argv[1]);
	

	
	

	Life l(7,28);//((int)nTam[0],(int)nTam[2],(char)aliveCell);

	l.infoTab();

	confInit.close();
	return 0;
}