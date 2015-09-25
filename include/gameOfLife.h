#ifndef _GAME_OF_LIFE_H
#define _GAME_OF_LIFE_H
#include <iostream>
/*Tamanho Default do tabuleiro de simulação*/
const int nLinDefault = 15, nColDefault = 15;
const char _alive_cell = 'k';

class Life{
	/*Parâmetros e Métodos privados*/
	char **tab,**tabStable, **tabUpdate, alive_cell;
	int nLin, nCol, generation=0;
	

	public:
		/*Construtor*/
		Life(int _nLin = nLinDefault, int _nCol = nColDefault, char _alive = _alive_cell);
		
		/*Destrutor*/
		~Life();
		/*Metodo que informa o tamanho do tabuleiro*/
		void infoTab();
		

		/*Métodos públicos da classe Life*/
		void fillExist(char **_tab1);
		void update();
		void setAlive();
		void print();
		Life operator =(const Life &_tab1);
		bool operator ==(const Life &_tab1);
		bool stable();
		int check(char s);
		
};

#endif
