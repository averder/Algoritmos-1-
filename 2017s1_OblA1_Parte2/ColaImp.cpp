#include "ColaImp.h"

#ifndef COLAIMP_CPP
#define COLAIMP_CPP

template <class T>
ostream &operator<< <>(ostream& out, const ColaImp<T> &c) {
	c.Imprimir(out);
	return out;
}

template <class T>
ColaImp<T>::ColaImp(){
	// NO IMPLEMENTADA
}

template <class T>
ColaImp<T>::ColaImp(const Cola<T> &c){
	// NO IMPLEMENTADA
	return *this;
}

template <class T>
ColaImp<T>::ColaImp(const ColaImp<T> &c){
	// NO IMPLEMENTADA
	return *this;
}

template <class T>
Cola<T> & ColaImp<T>::operator=(const Cola<T> &c){
	// NO IMPLEMENTADA
	return *this;
}

template <class T>
Cola<T> & ColaImp<T>::operator=(const ColaImp<T> &c){
	// NO IMPLEMENTADA
	return *this;
}

template <class T>
bool ColaImp<T>::operator==(const Cola<T>& c) const{
	// NO IMPLEMENTADA
	return false;
}

template <class T>
ColaImp<T>::~ColaImp(){
	// NO IMPLEMENTADA
}

template<class T>
Cola<T>* ColaImp<T>::CrearVacia() const {
	return new ColaImp<T>();
}

template <class T>
void ColaImp<T>::Encolar(const T &e){
	// NO IMPLEMENTADA
}

template <class T>
T& ColaImp<T>::Principio()const{
	// NO IMPLEMENTADA
	return *new T();
}

template <class T>
T ColaImp<T>::Desencolar(){
	// NO IMPLEMENTADA
	return *new T();
}

template <class T>
void ColaImp<T>::Vaciar(){
	// NO IMPLEMENTADA
}

template <class T>
unsigned int ColaImp<T>::CantidadElementos()const{
	// NO IMPLEMENTADA
	return 0;
}

template <class T>
bool ColaImp<T>::EsVacia() const{
	// NO IMPLEMENTADA
	return true;
}

template <class T>
bool ColaImp<T>::EsLlena() const{
	// NO IMPLEMENTADA
	return false;
}

template <class T>
Cola<T>* ColaImp<T>::Clon()const{
	// NO IMPLEMENTADA
	return new ColaImp<T>();
}

template <class T>
void ColaImp<T>::Imprimir(ostream& o)const{
	Cola<T> *clon = this->Clon();
	
	T elemento;
	while (!clon->EsVacia()) {
		elemento= clon->Desencolar();
		o << elemento << " ";
	}
	delete clon;
}

#endif