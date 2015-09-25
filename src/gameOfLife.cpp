#include <iostream>
#include "gameOfLife.h"

/*Construtor*/
Life::Life(int _nLinDefault, int _nColDefault, char _alive):nLin(_nLinDefault),nCol(_nColDefault),alive_cell(_alive){
	/*Cria array de ponteiros*/
	tab = new char *[_nLinDefault];

	/*Cria array auxiliar para identificar gerações estáveis imediatas*/
	tabStable = new char *[_nLinDefault];

	/*Cada posição do array receebe um array de char*/
	for(auto i(0);i<_nLinDefault;i++){
		tab[i] = new char[_nColDefault];
		tabStable[i] = new char[_nColDefault];
	}
	nLin = _nLinDefault;
	nCol = _nColDefault;
	alive_cell = _alive;
	std::cout << "Entrei no Construtor yay!!!" << std::endl;

};

/*Destrutor*/
Life::~Life(){
	/*Destroi o array tab*/
	for(auto i(0);i<nLin;i++){
		delete tab[i];
		delete tabStable[i];
	}
	delete tab;
	delete tabStable;
	std::cout << "Entrei no Destrutor yay!!!" << std::endl;
};

/*Metodo que informa o tamanho do tabuleiro*/
void Life::infoTab(){
	std::cout << "O tamanho do tabuleiro usado para a simulação é: [" << nLin << "," << nCol << "];" << std::endl;
	std::cout << "Este tabuleiro está na geração: ["<< generation << "];" << std::endl;	
	std::cout << "Este tabuleiro usa o caracter: ["<< alive_cell << "] , como célula viva;" << std::endl;	
};
void Life::fillExist(char **_tab1){
	for(auto i(0);i<nLin;i++){
		for(auto j(0);j<nCol;j++){
			tab[i][j] = _tab1[i][j];
		}
	}
	std::cout << "Consegui!!!" << std::endl;
};
void Life::print(){
	for(auto i(0);i<nLin;i++){
		for(auto j(0);j<nCol;j++){
			std::cout << tab[i][j];
		}
	}
};

void Life::setAlive(){
	for(auto i(0);i<nLin;i++){
		for(auto j(0);j<nCol;j++){
			if(tab[i][j]==alive_cell){
				std::cout << "Célula na posição [" << i+1 << "," << j+1 << "] está viva!!!" << std::endl;
			}else{
				continue;
			}
		}
	}
};
/*void setAlive(){
	for(auto i(0);i<nLin;i++){
		for(auto j(0);j<nCol;j++){
			std::cout << tab[i][j];
		}
	}
};*/
