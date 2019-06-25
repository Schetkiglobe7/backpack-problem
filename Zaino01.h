#ifndef ZAINO01_H
#define ZAINO01_H

#include"header.h"

template<typename T,typename X,typename Y>
class Zaino01 : public Zaino<X>{
private:
	void getValoreZaino();
	Y getMax(Y x, Y y){return ((x>y) ? x : y);} 
public:
	Zaino01(int pesoZaino);
	~Zaino01(){;}
};
template<typename T,typename X,typename Y>
Zaino01<T,X,Y>::Zaino01(int pesoZaino){
	this->setPesoZaino(pesoZaino);
	getValoreZaino();
} 
template<typename T,typename X,typename Y>
void Zaino01<T,X,Y>::getValoreZaino(){
	 
	//istanziazione dell'oggetto insieme
	 Insieme<T> insiemeOgg;
	 std::cout<<"  "<<std::endl;
	 std::cout<<"  "<<std::endl;
	 std::cout<<" "<<std::endl;
	int i, w; //indici
	int n=insiemeOgg.getSize();
	X W=this->getPesoZaino();
	Y *matriceValori=new Y[(n+1)*(W+1)];
	int PesoOggPresi=0;
		//i due for singoli inizializzano la matrice grande n elementi più uno per W peso più uno 
	for(w = 0; w <=n; w++) 
	{
		(*(matriceValori+i*(W+1))) = 0;
	}

	for(i = 0; i <=W; i++) 
	{
		(*(matriceValori+i)) = 0;
	}
		// i due for innestati scorrono la matrice a partire da 1-1(la prima riga e colonna non viene presa)	
	for(i = 1; i <= n; i++)
	{
		for(w = 1; w <= W; w++) 
		{	//se l'oggetto può entrare nello zaino 
			if(insiemeOgg.getArray(i).getPeso() <= w) 
			{	//controllo il vantaggio di prenderlo o prendere l'elemento precedente
				(*(matriceValori+i*(W+1)+w)) = this->getMax((*(matriceValori+(i-1)*(W+1)+w)),insiemeOgg.getArray(i).getValore() + (*(matriceValori+(i-1)*(W+1)+(w -(insiemeOgg.getArray(i).getPeso())))));	
			} 
			else 
			{	//se l'oggetto non entra nello zaino, vado avanti escludendo l'oggetto
				(*(matriceValori+i*(W+1)+w)) = (*(matriceValori+(i-1)*(W+1)+w));
			}
		}

	    
	}
	//uso F ed E per scorrere la matrice
	int F=n;
	int E=W;
	//partendo dall'ultimo elemento
	for(;F>0 && E>0;F--)
	{	//se l'oggetto è diverso da quello precedente
		if((*(matriceValori+F*(W+1)+E)) != (*(matriceValori+(F-1)*(W+1)+E)))
		{	//lo prendo e aggiorno il peso degli oggetti presi, aggiorno l'indice del peso
			std::cout<<"elemento preso: "<<insiemeOgg.getArray(F).getNome()<<"\t"<<insiemeOgg.getArray(F).getValore()<<" $"<<"\t"<<insiemeOgg.getArray(F).getPeso()<<" kg"<<std::endl;
			PesoOggPresi = PesoOggPresi + insiemeOgg.getArray(F).getPeso();
			E=E-insiemeOgg.getArray(F).getPeso();
		}
	}
	//inizializzo qui il valore dello zaino e gli assegno il valore migliore 
	//ovvero quello che si trova nell'ultima cella della matrice dei valori
	std::cout<<"Valore Zaino: "<<(*(matriceValori+n*(W+1)+W))<<" $"<<std::endl;
	std::cout<<"Capacita' Zaino: "<<this->getPesoZaino()<<" kg"<<std::endl;
	std::cout<<"Spazio occupato: "<<PesoOggPresi<<" kg"<<std::endl;
	std::cout<<"spazio restante: "<<this->getPesoZaino()-PesoOggPresi<<" kg"<<std::endl;
}

#endif