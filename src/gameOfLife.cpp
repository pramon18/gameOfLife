#include <iostream>
#include "gameOfLife.h"

/*Construtor*/
Life::Life(int _nLinDefault, int _nColDefault, char _alive):nLin(_nLinDefault),nCol(_nColDefault),alive_cell(_alive){
	/*Cria array de ponteiros*/
	tab = new char *[_nLinDefault];

	/*Cria array auxiliar para identificar gerações estáveis imediatas*/
	tabStable = new char *[_nLinDefault];
	/*Cria array para ser utilizado no update*/
	tabUpdate = new char *[_nLinDefault];
	/*Cada posição do array receebe um array de char*/
	for(auto i(0);i<_nLinDefault;i++){
		tab[i] = new char[_nColDefault];
		tabStable[i] = new char[_nColDefault];
		tabUpdate[i] = new char[_nColDefault];
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
		delete tabUpdate[i];
	}
	delete tab;
	delete tabStable;
	delete tabUpdate;
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
			tabStable[i][j] = _tab1[i][j];
		}
	}
	std::cout << "Consegui!!!" << std::endl;
};
void Life::print(){
	for(auto i(0);i<nLin;i++){
		std::cout << "[";
		for(auto j(0);j<nCol;j++){
			std::cout << tab[i][j];
		}
		std::cout << "]" << std::endl;
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
bool Life::stable(){
	for(auto i(0);i<nLin;i++){
		for(auto j(0);j<nCol;j++){
			if(tab[i][j]!=tabStable[i][j]){
				return false;
			}
		}
	}
	return true;
};
void Life::update(){
	int sum = 0;
	for(auto i(0);i<nLin;i++){
		for(auto j(0);j<nCol;j++){
			if(i>0 && j>0 && i<nLin-1 && j<nCol-1){
				sum = ((check(tab[i-1][j-1]))+(check(tab[i-1][j]))+(check(tab[i][j-1]))+(check(tab[i][j+1]))+(check(tab[i+1][j]))+(check(tab[i+1][j+1]))+(check(tab[i-1][j+1]))+(check(tab[i+1][j-1])));
				if(tab[i][j]==alive_cell){
					if(sum<=1||sum>=4){
						tabUpdate[i][j] = '.';
					}else{
						tabUpdate[i][j] = alive_cell;
					}
				}else{
					if(sum==3){
						tabUpdate[i][j] = alive_cell;
					}else{
						tabUpdate[i][j] = '.';
					}
				}
			}
			if(i==0&&j>0&&j<nCol-1){
				sum = ((check(tab[i][j-1]))+(check(tab[i][j+1]))+(check(tab[i+1][j-1]))+(check(tab[i+1][j]))+(check(tab[i+1][j+1])));
				if(tab[i][j]==alive_cell){
					if(sum<=1||sum>=4){
						tabUpdate[i][j] = '.';
					}else{
						tabUpdate[i][j] = alive_cell;
					}
				}else{
					if(sum==3){
						tabUpdate[i][j] = alive_cell;
					}else{
						tabUpdate[i][j] = '.';
					}
				}
			}
			if(j==0&&i>0&&i<nLin-1){
				sum = ((check(tab[i-1][j]))+(check(tab[i-1][j+1]))+(check(tab[i][j+1]))+(check(tab[i+1][j+1]))+(check(tab[i+1][j])));
				if(tab[i][j]==alive_cell){
					if(sum<=1||sum>=4){
						tabUpdate[i][j] = '.';
					}else{
						tabUpdate[i][j] = alive_cell;
					}
				}else{
					if(sum==3){
						tabUpdate[i][j] = alive_cell;
					}else{
						tabUpdate[i][j] = '.';
					}
				}
			}
			if(i==nLin&&j>0&&j<nCol-1){
				sum = ((check(tab[i][j-1]))+(check(tab[i-1][j-1]))+(check(tab[i-1][j]))+(check(tab[i-1][j+1]))+(check(tab[i][j+1])));
				if(tab[i][j]==alive_cell){
					if(sum<=1||sum>=4){
						tabUpdate[i][j] = '.';
					}else{
						tabUpdate[i][j] = alive_cell;
					}
				}else{
					if(sum==3){
						tabUpdate[i][j] = alive_cell;
					}else{
						tabUpdate[i][j] = '.';
					}
				}
			}
			if(j==nCol&&i>0&&i<nLin-1){
				sum = ((check(tab[i-1][j]))+(check(tab[i-1][j+1]))+(check(tab[i][j+1]))+(check(tab[i+1][j+1]))+(check(tab[i+1][j])));
				if(tab[i][j]==alive_cell){
					if(sum<=1||sum>=4){
						tabUpdate[i][j] = '.';
					}else{
						tabUpdate[i][j] = alive_cell;
					}
				}else{
					if(sum==3){
						tabUpdate[i][j] = alive_cell;
					}else{
						tabUpdate[i][j] = '.';
					}
				}
			}
			if(i==0&&j==0){
				sum = ((check(tab[i][j+1]))+(check(tab[i+1][j+1]))+(check(tab[i+1][j])));
				if(tab[i][j]==alive_cell){
					if(sum<=1||sum>=4){
						tabUpdate[i][j] = '.';
					}else{
						tabUpdate[i][j] = alive_cell;
					}
				}else{
					if(sum==3){
						tabUpdate[i][j] = alive_cell;
					}else{
						tabUpdate[i][j] = '.';
					}
				}
			}
			if(i==nLin&&j==0){
				sum = ((check(tab[i-1][j]))+(check(tab[i-1][j+1]))+(check(tab[i][j+1])));
				if(tab[i][j]==alive_cell){
					if(sum<=1||sum>=4){
						tabUpdate[i][j] = '.';
					}else{
						tabUpdate[i][j] = alive_cell;
					}
				}else{
					if(sum==3){
						tabUpdate[i][j] = alive_cell;
					}else{
						tabUpdate[i][j] = '.';
					}
				}
			}
			if(i==0&&j==nCol){
				sum = ((check(tab[i][j-1]))+(check(tab[i+1][j-1]))+(check(tab[i+1][j])));
				if(tab[i][j]==alive_cell){
					if(sum<=1||sum>=4){
						tabUpdate[i][j] = '.';
					}else{
						tabUpdate[i][j] = alive_cell;
					}
				}else{
					if(sum==3){
						tabUpdate[i][j] = alive_cell;
					}else{
						tabUpdate[i][j] = '.';
					}
				}
			}
			if(i==nLin&&j==nCol){
				sum = ((check(tab[i-1][j-1]))+(check(tab[i][j-1]))+(check(tab[i-1][j])));
				if(tab[i][j]==alive_cell){
					if(sum<=1||sum>=4){
						tabUpdate[i][j] = '.';
					}else{
						tabUpdate[i][j] = alive_cell;
					}
				}else{
					if(sum==3){
						tabUpdate[i][j] = alive_cell;
					}else{
						tabUpdate[i][j] = '.';
					}
				}
			}
		}
	}
	for(auto i(0);i<nLin;i++){
		for(auto j(0);j<nCol;j++){
			tabStable[i][j]=tab[i][j];
			tab[i][j]=tabUpdate[i][j];
		}
	}
};
int Life::check(char s){
	if(s==alive_cell){
		return 1;
	}
	return 0;
}