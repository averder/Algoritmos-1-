#include "IteradorListaPosImp.h"

#ifndef ITERADORLISTAPOSIMP_CPP
#define ITERADORLISTAPOSIMP_CPP

template <class T>
IteradorListaPosImp<T>::IteradorListaPosImp() {
	lista = NULL;
	actual = 0;
}

template <class T>
IteradorListaPosImp<T>::IteradorListaPosImp(const ListaPosImp<T> &l) {
	lista = &l;
	actual = 0;
}

template <class T>
IteradorListaPosImp<T>::IteradorListaPosImp(const IteradorListaPosImp<T> &it) {
	lista = it.lista;
	actual = it.actual;
}

template <class T>
Iterador<T> &IteradorListaPosImp<T>::operator=(const IteradorListaPosImp<T> &it) {
	if (this != &it) {
		lista = it.lista;
		actual = it.actual;
	}
	return *this;
}

template <class T>
Iterador<T> *IteradorListaPosImp<T>::Clon() const {
	IteradorListaPosImp<T> *it = new IteradorListaPosImp<T>(*this);
	return it;
}

template <class T>
IteradorListaPosImp<T>::~IteradorListaPosImp() {
}

template <class T>
const T &IteradorListaPosImp<T>::Elemento() const {
	return lista->ElementoPos(actual);
}

template <class T>
T &IteradorListaPosImp<T>::ElementoInseguro() const {
	return lista->ElementoPos(actual);
}

template <class T>
void IteradorListaPosImp<T>::Resto() {
	actual++;
}

template <class T>
bool IteradorListaPosImp<T>::EsFin() const {
	return actual >= lista->CantidadElementos();
}

template <class T>
void IteradorListaPosImp<T>::Principio() {
	actual = 0;
}


#endif