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
	
	/*Tranformando a matriz contida no arquivo em matriz de caracteres*/
	char **init;
	init = new char*[size_x];
	for(auto i(0);i<size_x;i++){
		init[i] = new char[size_y];
	}

	for(auto i(0);i<size_x;i++){
		for(auto j(0);j<size_y;j++){
			confInit.get(init[i][j]);
		}
	}
	/*Criando objeto life para a simulação e passando como parâmetro as informações recebidas do arquivo*/
	Life l(size_x,size_y,alive_Cell);
	/*Inicializando objeto Life apartir de matriz de char*/
	l.fillExist(init);
	char user = ' ';//char de controle da simulação

	while((user!='n')&&(user!='N')){
		cout << "Configuração Atual:" <<endl;
		l.print();
		l.infoTab();
		cout << "Deseja continuar a simulação? [y/n]: " << endl;
		cin >> user;
		if(user == 'y'||user == 'Y'){
			l.update();
		}
		if(l.stable()){
			l.print();
			cout << "Configuração Estável. <<<Saindo>>>" << endl;
			break;
		}
	}
	/*Fechando arquivo de configuração inicial*/
	confInit.close();
	/*Deletando matriz de char usada para iniciar o objeto life*/
	for(auto i(0);i<size_x;i++){
		delete [] init[i];
	}
	delete [] init;
	return 0;
}