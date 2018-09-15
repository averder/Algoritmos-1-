#include "IteradorListaOrdImp.h"

#ifndef ITERADORLISTAORDIMP_CPP
#define ITERADORLISTAORDIMP_CPP

template <class T>
IteradorListaOrdImp<T>::IteradorListaOrdImp() {
	actual = ppio = NULL;
}

template <class T>
IteradorListaOrdImp<T>::IteradorListaOrdImp(const ListaOrdImp<T> &l) {
	ppio = actual = l.ppio;
}

template <class T>
IteradorListaOrdImp<T>::IteradorListaOrdImp(const IteradorListaOrdImp<T> &it) {
	ppio = it.ppio;
	actual = it.actual;
}
	
template <class T>
Iterador<T> &IteradorListaOrdImp<T>::operator=(const IteradorListaOrdImp<T> &it) {
	if (this != &it) {
		ppio = it.ppio;
		actual = it.actual;
	}
	return *this;
}

template <class T>
Iterador<T> *IteradorListaOrdImp<T>::Clon() const {
	IteradorListaOrdImp<T> *it = new IteradorListaOrdImp<T>(*this);
	return it;
}

template <class T>
IteradorListaOrdImp<T>::~IteradorListaOrdImp() {
}

template <class T>
const T &IteradorListaOrdImp<T>::Elemento() const {
	return actual->dato;
}

template <class T>
void IteradorListaOrdImp<T>::Resto() {
	actual = actual->sig;
}

template <class T>
bool IteradorListaOrdImp<T>::EsFin() const {
	return actual == NULL;
}

template <class T>
void IteradorListaOrdImp<T>::Principio() {
	actual = ppio;
}


#endif