#include "PilaImp.h"

#ifndef PILAIMP_CPP
#define PILAIMP_CPP

template <class T>
ostream &operator<< <>(ostream& out, const PilaImp<T> &c) {
	c.Imprimir(out);
	return out;
}

template <class T>
PilaImp<T>::PilaImp() {
	// NO IMPLEMENTADA
}

template<class T>
PilaImp<T>::PilaImp(const Pila<T>& p) {
	// NO IMPLEMENTADA
}

template<class T>
PilaImp<T>::PilaImp(const PilaImp<T>& p) {
	// NO IMPLEMENTADA
}

template<class T>
Pila<T>& PilaImp<T>::operator=(const Pila<T>& p) {
	// NO IMPLEMENTADA
	return *this;
}

template<class T>
Pila<T>& PilaImp<T>::operator=(const PilaImp<T>& p) {
	// NO IMPLEMENTADA
	return *this;
}

template<class T>
bool PilaImp<T>::operator==(const Pila<T> &p) const{
	//NO IMPLEMENTADA
	return false;
}

template<class T>
PilaImp<T>::~PilaImp() {
	// NO IMPLEMENTADA
}

template<class T>
Pila<T>* PilaImp<T>::CrearVacia() const {
	return new PilaImp<T>();
}

template<class T>
void PilaImp<T>::Push(const T& e) {
	// NO IMPLEMENTADA
}

template<class T>
T& PilaImp<T>::Top() const {
	// NO IMPLEMENTADA
	return *new T();
}

template<class T>
T PilaImp<T>::Pop() {
	// NO IMPLEMENTADA
	return *new T();
}

template<class T>
void PilaImp<T>::Vaciar() {
	// NO IMPLEMENTADA
}

template<class T>
unsigned int PilaImp<T>::CantidadElementos() const {
	// NO IMPLEMENTADA
	return 0;
}

template<class T>
bool PilaImp<T>::EsVacia() const {
	// NO IMPLEMENTADA
	return true;
}

template <class T>
bool PilaImp<T>::EsLlena() const{
	// NO IMPLEMENTADA
	return false;
}

template<class T>
Pila<T>* PilaImp<T>::Clon() const {
	// NO IMPLEMENTADA
	return new PilaImp<T>();
}

template<class T>
void PilaImp<T>::Imprimir(ostream & o) const
{
	Pila<T> *clon = this->Clon();
	while (!clon->EsVacia()) {
		T e = clon->Top();

		o << e << " ";

		clon->Pop();
	}
	delete clon;
}

#endif