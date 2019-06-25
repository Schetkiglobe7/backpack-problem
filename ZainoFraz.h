#ifndef ZAINOFRAZ_H
#define ZAINOFRAZ_H


#include"header.h"

template<typename T,typename X,typename Y>
class ZainoFraz : public Zaino<X>{          
private:
 void getValoreZaino();
public:
	 ZainoFraz(int pesoZaino);
	 ~ZainoFraz(){;}
};
template<typename T,typename X,typename Y>
ZainoFraz<T,X,Y>::ZainoFraz(int pesoZaino){
	this->setPesoZaino(pesoZaino);
	getValoreZaino();

}
template<typename T,typename X,typename Y>
void ZainoFraz<T,X,Y>::getValoreZaino(){  //Metodo principale: qui viene svolto tutto il lavoro che l'utente deve ignorare     	 						                       
	 	CodaPriorita<T> minCodaPriorita;
	 	int numeroOggetti=minCodaPriorita.getSize();        //il metodo necessita di avere localmente il valore dello 							//del numero degli oggetti
		X capacitaZaino=this->getPesoZaino();			//medesima cosa!!
	int i;     //indice che scorre gli elementi
	Y capacitaCorrente = capacitaZaino;
	Y valoreTotale = 0;
	T tempMinimum;
	while(minCodaPriorita.getSize() >0 && capacitaCorrente >0)
		{
			tempMinimum = minCodaPriorita.estractMin();
			if(tempMinimum.getPeso() < capacitaCorrente)
				{
					valoreTotale  = valoreTotale + tempMinimum.getValore();
					capacitaCorrente = capacitaCorrente - tempMinimum.getPeso();
					std::cout<<std::endl<<" Oggetto Preso"<<" "<<"\t"<<" Peso"<<" "<<" Valore"<<" "<<std::endl;
					std::cout<<"        "<<tempMinimum.getNome()<<" "<<"\t"<<" "<<tempMinimum.getPeso()<<" kg"<<" "<<"\t"<<" "<<tempMinimum.getValore()<<"$"<<" "<<"\t"<<" "<<std::endl;
				}
			else{
					std::cout<<"l'oggetto non puo' essere preso per intero, ne prenderemo solo una frazione"<<std::endl;
					float peso = capacitaCorrente / tempMinimum.getPeso();
					valoreTotale = valoreTotale + (peso * tempMinimum.getValore());
					std::cout<<std::endl<<" Frazione Oggetto Preso"<<" "<<"\t"<<" Peso"<<" "<<"\t"<<" Valore"<<" "<<"\t"<<std::endl;
		 			std::cout<<"        "<<tempMinimum.getNome()<<" "<<"\t\t"<<" "<<capacitaCorrente<<" kg"<<" "<<"\t"<<" "<<peso * tempMinimum.getValore()<<" $"<<" "<<"\t"<<" "<<std::endl;
		 			capacitaCorrente = 0;
			}
		}

	std::cout<<std::endl<<"Peso totale: "<<capacitaZaino - capacitaCorrente<<" kg"<<std::endl; //stampo il peso degli oggetti inseriti nello zaino
	std::cout<<"Spazio Rimasto: "<<capacitaCorrente<<" kg"<<std::endl;
	std::cout<<"valoreTotale: "<<valoreTotale<<" $"<<std::endl;    //stampo il valore degli oggetti inseriti nello zaino
}

#endif