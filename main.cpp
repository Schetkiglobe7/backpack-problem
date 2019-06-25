#include"header.h"

int main(void)
{
	int pesoZaino;
	float valoreZaino;
	int risposta,risposta2;
	do
	{
		std::cout<<"Avviare Programma?(0 per avviare -/- 1 per terminare)"<<std::endl;
		std::cin>>risposta;
		switch(risposta)
		{
			case 0: 

					std::cout<<"Progetto ASD Antonio Pilato -0124/001307-"<<std::endl;
					std::cout<<"Zaino"<<"\t\t"<<"caso reale : magazzino IKEA"<<std::endl<<std::endl;
					std::cout<<"Inizio simulazione"<<std::endl;
					std::cout<<"premere 1 per avviare  i due algoritmi dello Zaino"<<std::endl;
					std::cin>>risposta2;
					if(risposta2==1)
						{
							std::cout<<"Premere il tasto Invio per avviare l'algoritmo dello zaino-01...";
							std::cin.ignore();
							std::cin.get();
							std::cout<<"Zaino-01"<<std::endl;
							std::cout<<"Se non vuoi inserire gli oggetti nel file MAGAZZINO.txt saranno utilizzati gli elementi precaricati"<<std::endl;	
							std::cout<<"inserire il peso del tuo zaino: "; std::cin>>pesoZaino;
							Zaino01<Item,int,float> * zainetto = new Zaino01<Item,int,float>(pesoZaino);
							delete zainetto;
							std::cout<<"Fine Simulazione"<<std::endl;
							std::cout<<"Premere il tasto Invio per avviare l'algoritmo dello zaino frazionario...";
							std::cin.ignore();
							std::cin.get();
							std::cout<<"Zaino-Frazionario"<<std::endl;
							std::cout<<"Se non vuoi inserire gli oggetti nel file MAGAZZINO.txt saranno utilizzati gli elementi precaricati"<<std::endl;	
							ZainoFraz<Item,int,float> * zainettoFraz = new ZainoFraz<Item,int,float>(pesoZaino);
							delete zainettoFraz;
							std::cout<<"fine simulazione"<<std::endl;
						}
						else std::cout<<"Scelta non valida.."<<std::endl;
						std::cout<<"Premere il tasto Invio per terminare...";
						std::cin.get();
					return(0);
					break;

			case 1: 
					std::cout<<"esco"<<std::endl;	
					exit(1);
					break;

			default: 
					std::cout<<"scelta non valida"<<std::endl;
					break;
		}
	}while((risposta != 0)||(risposta != 1));
	
}