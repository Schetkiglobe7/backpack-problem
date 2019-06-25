#ifndef ITEM_H
#define ITEM_H

#include"header.h"

class Item{
private:
	std::string nome;
	float valore;
	int peso;
	float priorita;
public:
	Item(){nome="",valore=0;peso=0;} //primo costruttore
	Item(std::string nome, float valore,int peso){this->nome=nome;this->valore=valore;this->peso=peso;this->priorita = 1/(valore/peso);} //secondo costruttore
	~Item(){;} //distruttore
	void setPriorita(float massimo){this->priorita = massimo;}
	float getPriorita(){return priorita;}
	std::string getNome(){return nome;}
	float getValore(){return valore;}
	int getPeso(){return peso;}
};
#endif