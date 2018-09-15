#include "IteradorListaOrdImp2.h"

#ifndef ITERADORLISTAORDIMP2_CPP
#define ITERADORLISTAORDIMP2_CPP

template <class T>
IteradorListaOrdImp2<T>::IteradorListaOrdImp2() {
	lista = new ListaPosImp<T>();
	actual = 0;
}

template <class T>
IteradorListaOrdImp2<T>::IteradorListaOrdImp2(const ListaPosImp<T> &l) {
	lista = new ListaPosImp<T>(l);
	actual = 0;
}

template <class T>
IteradorListaOrdImp2<T>::IteradorListaOrdImp2(const IteradorListaOrdImp2<T> &it) {
	lista = new ListaPosImp<T>(*(it.lista));
	actual = it.actual;
}
	
template <class T>
Iterador<T> &IteradorListaOrdImp2<T>::operator=(const IteradorListaOrdImp2<T> &it) {
	if (this != &it) {
		*lista = *(it.lista);
		actual = it.actual;
	}
	return *this;
}

template <class T>
Iterador<T> *IteradorListaOrdImp2<T>::Clon() const {
	return new IteradorListaOrdImp2<T>(*this);
}

template <class T>
IteradorListaOrdImp2<T>::~IteradorListaOrdImp2() {
	delete lista;
}

template <class T>
const T &IteradorListaOrdImp2<T>::Elemento() const {
	return lista->ElementoPos(actual);
}

template <class T>
void IteradorListaOrdImp2<T>::Resto() {
	actual++;
}

template <class T>
bool IteradorListaOrdImp2<T>::EsFin() const {
	return actual >= lista->CantidadElementos();
}

template <class T>
void IteradorListaOrdImp2<T>::Principio() {
	actual = 0;
}


#endif