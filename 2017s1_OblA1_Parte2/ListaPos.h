#pragma once

#ifndef LISTAPOS_H
#define LISTAPOS_H

#include <iostream>
using namespace std;
#include "Iterador.h"
#include "Iterable.h"

template <class T>
class ListaPos;

// Escribe los elementos de la lista en el flujo out
template <class T>
ostream &operator<< <>(ostream& out, const ListaPos<T> &l) {
	l.Imprimir(out);
	return out;
}

template <class T>
class ListaPos abstract : public Iterable<T> {

public:

	// PRE: -
	// POS: Destructor
	virtual ~ListaPos() { }

	// PRE: -
	// POS: Retorna una nueva coleccion vacia
	virtual ListaPos<T> *CrearVacia() const abstract;

	//PRE:-
	//POS: Retorna una nueva lista idéntica a this y sin compartir memoria
	virtual ListaPos<T> *Clon() const abstract;

	// PRE: !EsLlena()
	// POS: Agrega el elemento e al principio de la lista
	virtual void AgregarPpio(const T &e) abstract;

	// PRE: -
	// POS: Agrega el elemento e en la posicion pos de la lista
	//		El primer elemento se encuentra en la posicion 0.
	//		Si pos es mayor o igual al largo de la lista insertal al final
	virtual void AgregarPos(const T &e, unsigned int pos) abstract;

	// PRE: !EsLlena()
	// POS: Agrega el elemento e al final de la lista
	virtual void AgregarFin(const T &e) abstract;

	// PRE: -
	// POS: Borra el primer elemento de la lista. Si no hay elementos no tiene efecto
	virtual void BorrarPpio() abstract;

	// PRE: -
	// POS: Borra el ultimo elemento de la lista. Si no hay elementos no tiene efecto
	virtual void BorrarFin() abstract;

	// PRE: -
	// POS: Borra el elemento en la posicion pos de la lista
	//		El primer elemento se encuentra en la posicion 0.
	//		Si pos es mayor o igual al largo de la lista la operacion no tiene efecto
	virtual void BorrarPos(unsigned int pos) abstract;

	// PRE: -
	// POS: Borra el primer elemento que sea igual a e
	//		Usa el operador == del elemento e para encontrar uno igual.
	//		Si no encuentra no tiene efecto
	virtual void Borrar(const T &e) abstract;

	// PRE: !EsVacia()
	// POS: Retorna el primer elemento 
	virtual T& ElementoPpio() const abstract;

	// PRE: !EsVacia()
	// POS: Retorna el ultimo elemento 	
	virtual T& ElementoFin() const abstract;

	// PRE: 0 <= pos < CantidadElementos()
	// POS: Retorna el elemento en la posicion pos
	//		El primer elemento se encuentra en la posicion 0.
	virtual T& ElementoPos(unsigned int pos) const abstract;

	// PRE: Existe(e) 
	// POS: Retorna la posicion del primer elemento que sea igual a e
	//		Usa el operador == del elemento e para encontrar uno igual
	//		El primer elemento se encuentra en la posicion 0.
	virtual unsigned int Posicion(const T &e) const abstract;

	// PRE: -
	// POS: Busca si existe un elemento que sea igual a e
	//		Usa el operador == del elemento e para encontrar uno igual
	virtual bool Existe(const T &e) const abstract;

	// PRE: -
	// POS: Vacia la lista
	virtual void Vaciar() abstract;

	// PRE: -
	// POS: Retorna true si la lista esta vacia
	virtual bool EsVacia() const abstract;

	// PRE: -
	// POS: Retorna true si la lista esta llena
	virtual bool EsLlena() const abstract;

	// PRE: -
	// POS: Retorna la cantidad de elementos presentes en la lista
	virtual unsigned int CantidadElementos() const abstract;

	//PRE:-
	//POS: Se llama desde el operator<<. Imprime los elementos de la Lista separados por un espacio en blanco
	//	   El listado debe aparecer ordenado de la primera a la ultima posicion.
	virtual void Imprimir(ostream& o) const abstract;

	// PRE: -
	// POS: Retorna si las 2 listas tienen los mismos elementos (comparados con el operador ==) 
	//      y en el mismo orden
	virtual bool operator==(const ListaPos<T> &l) const {
		Iterador<T> &i = l.GetIterador();
		Iterador<T> &i2 = this->GetIterador();
		while (!i.EsFin() && !i2.EsFin()) {
			if (!(i++ == i2++))
				return false;
		}
		if (i.EsFin() != i2.EsFin())
			return false;

		return true;
	}

	// PRE: -
	// POS: *this == l y no comparten memoria
	virtual ListaPos<T> &operator=(const ListaPos<T> &l) {
		if (this != &l) {
			this->Vaciar();

			for (Iterador<T> &i = l.GetIterador(); !i.EsFin();) {
				AgregarFin(i++);
			}
		}
		return *this;
	}

protected:

	ListaPos() { }
	ListaPos(const ListaPos &l) { assert(false); }

};


#endif