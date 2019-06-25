#ifndef CODAPRIORITA_H
#define CODAPRIORITA_H

#include"header.h"



template<typename T>
class CodaPriorita : public MinHeap<T>{ 
private:
	void insert(T);
	T minimum();
	void decreasePriority(float key, int ind); //decrementa la chiave dell'elemento(la priorità)
public:
	T estractMin();
	CodaPriorita();
	~CodaPriorita(){;}
};

template<typename T>
CodaPriorita<T>::CodaPriorita(){
	this->heapSize=0;
	int size;
	std::ifstream fileread("MAGAZZINO.txt",std::ios::in);
		std::string nomeObject;
		float valore;
		int peso;
		if(!fileread.is_open()){std::cout<<"file inesistente"<<std::endl<<"nome file: MAGAZZINO"<<std::endl; exit(1);}
			fileread>>size;
			this->array = new T[size+1];
			for(int i=1;i<=size;i++)
				{
					fileread>>nomeObject;
					fileread>>valore;
					fileread>>peso;
					T *oggettoChePrende = new T(nomeObject,valore,peso);
					insert(*oggettoChePrende);
					delete oggettoChePrende;
					
				}
			
			fileread.close();
		std::cout<<std::endl<<" ***LISTA  OGGETTI  IN MAGAZZINO***"<<std::endl<<std::endl;

		for(int i=1;i<=size;++i)
			{
				std::cout<<"--------------------------------------------------------------------------"<<std::endl;
				std::cout<<"|Nome|"<<"\t\t\t\t\t\t"<<"|Valore|"<<"\t"<<"|Peso|"<<std::endl<<std::endl;
				std::cout<<"--------------------------------------------------------------------------"<<std::endl;
				std::cout<<"|"<<(*(this->array+i)).getNome()<<"        "<<(*(this->array+i)).getValore()<<" $"<<"         "<<(*(this->array+i)).getPeso()<<" kg"<<std::endl;
			}
			std::cout<<"--------------------------------------------------------------------------"<<std::endl;
			std::cout<<std::endl<<"       ***FINE LISTA***"<<std::endl<<std::endl;

}
template<typename T>
T CodaPriorita<T>::minimum(){   //restituisce l'elemento più piccolo (ovviamente si trova in prima posizione)
	return *(this->array);
}
template<typename T>
void CodaPriorita<T>::insert(T itemDaIns){ //inserimento in codaPriorità
	this->heapSize++;
	float tempPriority = itemDaIns.getPriorita();
	itemDaIns.setPriorita(FLT_MAX);
	*(this->array+this->heapSize)= itemDaIns;
	decreasePriority(tempPriority,this->heapSize);
}

template<typename T>
void CodaPriorita<T>::decreasePriority(float chiave,int ind){

	if(chiave > (*(this->array+ind)).getPriorita())
		{
			std::cout<<"errore la nuova chiave e' piu' grande di quella corrente"<<std::endl;
			exit(1);
		}
	(*(this->array+ind)).setPriorita(chiave);
	while(ind > 1 && (*(this->array+(ind/2))).getPriorita() > (*(this->array+ind)).getPriorita())
	{
		T temp;
		temp = *(this->array+ind);
		*(this->array+ind) = *(this->array+(ind/2));
		*(this->array+(ind/2)) = temp;
		ind = ind/2;
	} 
}
template<typename T>
T CodaPriorita<T>::estractMin(){   //estrae min(quindi lo elimina ridimensionando il size dell'heap)
	if(this->heapSize < 1)
	{
		std::cout<<"non ci sono elementi"<<std::endl;
		exit(1);
	}
	Item min = *(this->array+1);
	*(this->array+1) = *(this->array+this->heapSize);
	this->heapSize = this->heapSize-1;
	this->heapify(1);
return min;
}
#endif