#ifndef INSIEME_H
#define INSIEME_H

#include"header.h"

template<typename T>
class Insieme{
private:
	int size;
	T *array;
public:
	Insieme();
	int getSize(){return size;}
	T getArray(int i){return array[i];}
};
template<typename T>
Insieme<T>::Insieme(){
	//setSize(size);
	std::string nomeObject;
		float valore;
		int   peso;
		std::ifstream fileread("MAGAZZINO.txt",std::ios::in);
		if(!fileread.is_open()){std::cout<<"file inesistente"<<std::endl<<"nome file: MAGAZZINO"<<std::endl; exit(1);}
		fileread>>this->size;
		this->array = new T[size+1];
		for(int i=1;i<=getSize();i++)
			{
				fileread>>nomeObject;
				fileread>>valore;
				fileread>>peso;
				T *oggChePrende = new T(nomeObject,valore,peso);
				(*(array+i)) = *oggChePrende;
				delete oggChePrende;
			} 
		fileread.close();
		std::cout<<std::endl<<" ***LISTA  OGGETTI  MAGAZZINO***\n"<<std::endl;

		for(int i=1;i<=size;++i)
			{
				
				std::cout<<"--------------------------------------------------------------------------"<<std::endl;
				std::cout<<"|Nome|"<<"\t\t\t\t\t\t"<<"|Valore|"<<"\t"<<"|Peso|"<<std::endl<<std::endl;
				std::cout<<"--------------------------------------------------------------------------"<<std::endl;
				std::cout<<"|"<<(*(array+i)).getNome()<<"        "<<(*(array+i)).getValore()<<" $"<<"         "<<(*(array+i)).getPeso()<<" kg"<<std::endl<<std::endl;
			}
		std::cout<<"--------------------------------------------------------------------------"<<std::endl;
		std::cout<<std::endl<<"       ***FINE LISTA***"<<std::endl<<std::endl;
}
#endif





