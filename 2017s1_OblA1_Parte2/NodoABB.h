#ifndef NODOABB_H
#define NODOABB_H

#include <iostream>
#include <assert.h>

template <class U>
class NodoABB {
	public:
		U dato;
		NodoABB<U> *izq;
		NodoABB<U> *der;
		unsigned int auxiliar;

		NodoABB(const U &e) : dato(e), izq(NULL), der(NULL), auxiliar(0) {}
		NodoABB(const U &e, NodoABB<U> *i, NodoABB<U> *d) : dato(e), izq(i), der(d), auxiliar(0) {}
		virtual ~NodoABB() {}
	private:
		NodoABB(const NodoABB<U> &n) : dato(n.dato), izq(n.izq), der(n.der), auxiliar(n.auxiliar) {}

		NodoABB<U> &operator=(const NodoABB<U> &n) { assert(false); return *this;}
};

#endif