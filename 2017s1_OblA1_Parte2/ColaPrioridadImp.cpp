#include "ColaPrioridadImp.h"

#ifndef COLAPRIORIDADIMP_CPP
#define COLAPRIORIDADIMP_CPP


template<class T, class P>
ColaPrioridadImp<T, P>::ColaPrioridadImp() {
	// NO IMPLEMENTADA
}

template<class T, class P>
ColaPrioridadImp<T, P>::ColaPrioridadImp(const ColaPrioridadImp<T, P>& cp) {
	// NO IMPLEMENTADA
}

template<class T, class P>
ColaPrioridadImp<T, P>::ColaPrioridadImp(const ColaPrioridad<T, P>& cp) {
	// NO IMPLEMENTADA
}

template<class T, class P>
ColaPrioridad<T, P>& ColaPrioridadImp<T, P>::operator=(const ColaPrioridad<T, P>& cp) {
	if (this != &cp) {
		// NO IMPLEMENTADA
	}
	return *this;
}

template<class T, class P>
ColaPrioridad<T, P>& ColaPrioridadImp<T, P>::operator=(const ColaPrioridadImp<T, P>& cp) {
	if (this != &cp)
	{
		// NO IMPLEMENTADA
	}
	return *this;
}

template<class T, class P>
bool ColaPrioridadImp<T, P>::operator==(const ColaPrioridad<T, P> &cp) const {
	// NO IMPLEMENTADA
	return false;
}

template<class T, class P>
ColaPrioridadImp<T, P>::~ColaPrioridadImp() {
	// NO IMPLEMENTADA
}

template<class T, class P>
void ColaPrioridadImp<T, P>::Encolar(const T &e, const P &p) {
	// NO IMPLEMENTADA
}

template<class T, class P>
bool ColaPrioridadImp<T, P>::EsVacia() const {
	// NO IMPLEMENTADA
	return true;
}

template<class T, class P>
bool ColaPrioridadImp<T, P>::EsLlena() const {
	// NO IMPLEMENTADA
	return false;
}

template<class T, class P>
T& ColaPrioridadImp<T, P>::PrincipioElemento() const {
	// NO IMPLEMENTADA
	return *new T();
}

template<class T, class P>
const P& ColaPrioridadImp<T, P>::PrincipioPrioridad() const {
	// NO IMPLEMENTADA
	return *new P();
}

template<class T, class P>
void ColaPrioridadImp<T, P>::Desencolar() {
	// NO IMPLEMENTADA
}

template<class T, class P>
unsigned int ColaPrioridadImp<T, P>::Largo() const {
	// NO IMPLEMENTADA
	return 0;
}

template<class T, class P>
void ColaPrioridadImp<T, P>::Vaciar() {
	// NO IMPLEMENTADA
}

template<class T, class P>
ColaPrioridad<T, P>* ColaPrioridadImp<T, P>::Clon() const {
	// NO IMPLEMENTADA
	return new ColaPrioridadImp<T, P>();
}

template<class T, class P>
ColaPrioridad<T, P>* ColaPrioridadImp<T, P>::CrearVacia() const {
	return new ColaPrioridadImp<T, P>();
}

template<class T, class P>
void ColaPrioridadImp<T, P>::Imprimir(ostream & o) const
{
	// NO IMPLEMENTADA
	// Imprimir los elementos con cout separados por espacio ordenados de mayor a menor prioridad.
}


#endif

