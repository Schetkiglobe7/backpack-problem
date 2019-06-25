#ifndef ZAINO_H_
#define ZAINO_H_

#include"header.h"

template<typename X>
class Zaino{
private:
	X pesoZaino;
protected:   
	Zaino(){this->pesoZaino=0;}  
	~Zaino(){;}   
	void setPesoZaino(X pesoZaino){this->pesoZaino=pesoZaino;}
	X getPesoZaino(){return this->pesoZaino;}
    virtual void getValoreZaino()=0;
};
#endif