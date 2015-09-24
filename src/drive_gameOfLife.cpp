#include <iostream>
#include <fstream>
#include <string>
#include "gameOfLife.h"

using namespace std;
int main(int argc, char *argv[]){
	/*Recebendo arquivo com configuração inicial da linha de comando*/
	fstream confInit;
	confInit.open(argv[1]);
	/*Pegar tamanho da matriz e o caracter que vai ser usado como célula viva*/
	int size_x,size_y;
	char alive_Cell;
	confInit >> size_x;
	confInit >> size_y;
	confInit >> alive_Cell;

	cout << "Size X: [" << size_x << "] ;" << endl;
	cout << "Size Y: [" << size_y << "] ;" << endl;
	cout << "Alive Cell: [" << alive_Cell << "] ;" << endl;

	
	

	Life l(7,28);//((int)nTam[0],(int)nTam[2],(char)aliveCell);

	l.infoTab();

	confInit.close();
	return 0;
}