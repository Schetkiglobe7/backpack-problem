#ifndef MINHEAP_H
#define MINHEAP_H

#include "header.h"
#include<iostream>
template<typename T>
class MinHeap{
protected:
	T *array;
	int heapSize;
	MinHeap(){this->array=NULL;this->heapSize=0;} 
   ~MinHeap(){delete [] array;}
	 void heapify(int i);
public:
	int getSize(){return this->heapSize;}
	T ElementoInPos(int i){return this->array[i];}
};

template<typename T>
void MinHeap<T>::heapify(int i){
 int massimo=0;
     int sinistro = 2*i;  
     int destro = 2*i+1;  
   	if(sinistro<= this->heapSize && (*(this->array+sinistro)).getPriorita() < (*(this->array+i)).getPriorita())
   	{
   		massimo = sinistro;
   	}
   	else massimo = i;
   	if(destro <= this->heapSize && (*(this->array+destro)).getPriorita()< (*(this->array+massimo)).getPriorita())
   	{
   		massimo = destro;
   	}
    if(massimo != i)
    {
    	Item temp = *(this->array+massimo);
     	*(this->array+massimo)= *(this->array+i);
     	*(this->array+i)= temp;
     	heapify(massimo);
    }
}
#endif