#ifndef DEFINICIONES_H
#define DEFINICIONES_H

#include <iostream>
using namespace std;
#include <string.h>
#include <assert.h>


struct NodoListaS {
	int dato;
	NodoListaS *sig;
	NodoListaS(int d) : dato(d), sig(NULL) {}
};

struct NodoAB {
	int dato;
	NodoAB *izq;
	NodoAB *der;
	NodoAB(int d) : dato(d), izq(NULL), der(NULL) {}
};

struct NodoAG {
	int dato;
	NodoAG *ph;
	NodoAG *sh;
	NodoAG(int d) : dato(d), ph(NULL), sh(NULL) {}
};

struct NodoListaDobleDato {
	int dato1;
	int dato2;
	NodoListaDobleDato *sig;
	NodoListaDobleDato(int d1, int d2) : dato1(d1), dato2(d2), sig(NULL) {}
};

struct NodoABDobleDato {
	int dato1;
	int dato2;
	NodoABDobleDato *izq;
	NodoABDobleDato *der;
	NodoABDobleDato(int d1, int d2) : dato1(d1), dato2(d2), izq(NULL), der(NULL) {}
};

#endif