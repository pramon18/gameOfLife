#ifndef _GAME_OF_LIFE_H
#define _GAME_OF_LIFE_H

/*Tamanho Default do tabuleiro de simulação*/
const int nLinDefault = 15, nColDefault = 15;
const char _alive_cell = 'k';

class Life{
	/*Parâmetros e Métodos privados*/
	char **tab,**tabStable, alive_cell;
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
		void update(const Life &_tab1);
		void setAlive(const Life _tab1);
		void print(const Life _tab1);
		Life operator =(const Life &_tab1);
		bool operator ==(const Life &_tab1);
		bool stable(const Life _tab1,const Life _tab2);
};

#endif
