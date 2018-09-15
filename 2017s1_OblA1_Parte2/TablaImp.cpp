#include "TablaImp.h"

#ifndef TABLAIMP_CPP
#define TABLAIMP_CPP

template <class D, class R>
ostream &operator<< <>(ostream& out, const TablaImp<D, R> &t) {
	t.Imprimir(out);
	return out;
}

template <class D, class R>
TablaImp<D, R>::TablaImp() {
	// NO IMPLEMENTADA
}

template <class D, class R>
TablaImp<D, R>::TablaImp(const Tabla<D,R> &t) {
	// NO IMPLEMENTADA
}

template <class D, class R>
TablaImp<D, R>::TablaImp(const TablaImp<D,R> &t) {
	// NO IMPLEMENTADA
}

template <class D, class R>
Tabla<D,R>& TablaImp<D,R>::operator=(const Tabla<D,R> &t) {
	if (this != &t) {
		// NO IMPLEMENTADA
	}

	return *this;
}

template <class D, class R>
Tabla<D,R>& TablaImp<D,R>::operator=(const TablaImp<D,R> &t) {
	if (this != &t) {
		// NO IMPLEMENTADA
	}

	return *this;
}

template <class D, class R>
TablaImp<D, R>::~TablaImp() {
	// NO IMPLEMENTADA
}

template <class D, class R>
Tabla<D, R>* TablaImp<D, R>::CrearVacia() const {
	return new TablaImp<D, R>();
}

template <class D, class R>
void TablaImp<D, R>::Vaciar() {
	// NO IMPLEMENTADA
}

template <class D, class R>
void TablaImp<D, R>::Insertar(const D &d, const R &r) {
	// NO IMPLEMENTADA
}

template <class D, class R>
bool TablaImp<D, R>::EstaDefinida(const D &d) const {
	// NO IMPLEMENTADA
	return false;
}

template <class D, class R>
bool TablaImp<D,R>::operator==(const Tabla<D,R> &t) const {
	// NO IMPLEMENTADA
	return false; 
}; 

template <class D, class R>
const R& TablaImp<D, R>::Recuperar(const D &d) const {
	// NO IMPLEMENTADA
	return *new R();
}

template <class D, class R>
const D& TablaImp<D, R>::Elemento() const {
	// NO IMPLEMENTADA
	return *new D();
}

template <class D, class R>
void TablaImp<D, R>::Borrar(const D &d) {
	// NO IMPLEMENTADA
}

template <class D, class R>
bool TablaImp<D, R>::EsVacia() const {
	// NO IMPLEMENTADA
	return true;
}

template <class D, class R>
bool TablaImp<D, R>::EsLlena() const {
	// NO IMPLEMENTADA
	return false;
}

template <class D, class R>
unsigned int TablaImp<D, R>::CantidadElementos() const {
	// NO IMPLEMENTADA
	return 0;
}

template <class D, class R>
Tabla<D,R>* TablaImp<D, R>::Clon() const {
	// NO IMPLEMENTADA
	return new TablaImp<D, R>();
}

template <class D, class R>
void TablaImp<D, R>::Imprimir(ostream & o) const
{
	// NO IMPLEMENTADA
	// Imprimir los elementos con cout con el siguiente formato:
	// {Dominio:Rango} - {Dominio:Rango} - {Dominio:Rango}
	// Se deben imprimir ordenados por dominio
}


#endif