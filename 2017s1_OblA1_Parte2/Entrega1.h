#ifndef ENTREGA1_H
#define ENTREGA1_H

#include "Definiciones.h"

#include "ListaOrd.h"
#include "ListaPos.h"
#include "Pila.h"
#include "Cola.h"

#include "ListaOrdImp.h"
#include "ListaPosImp.h"
#include "PilaImp.h"
#include "ColaImp.h"

// Ver Entrega1.txt para la documentación de estas funciones

template <class T>
ListaOrd<T> *UnionListaOrd(const ListaOrd<T> *l1, const ListaOrd<T> *l2)
{
	// NO IMPLEMENTADA
	return new ListaOrdImp<T>();	
}

ListaOrd<int>* Enlistar(NodoAB* a);

template <class T>
bool EstaContenida(const Pila<T> *p1, const Pila<T> *p2)
{
	// NO IMPLEMENTADA
	return false;
}

int CantidadDeHojas(NodoAB* a);

void ImprimirPorNiveles(NodoAB *a);

#endif