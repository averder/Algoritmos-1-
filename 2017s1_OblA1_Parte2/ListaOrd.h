#pragma once

#ifndef LISTAORD_H
#define LISTAORD_H

#include <iostream>
using namespace std;
#include "Iterador.h"
#include "Iterable.h"

template <class T>
class ListaOrd;

// Escribe los elementos de la lista en el flujo out
template <class T>
ostream &operator<< <>(ostream& out, const ListaOrd<T> &l) {
	l.Imprimir(out);
	return out;
}

template <class T>
class ListaOrd abstract : public Iterable<T> {

public:

	// PRE: -
	// POS: Destructor
	virtual ~ListaOrd() { }

	// PRE: -
	// POS: Retorna una nueva coleccion vacia
	virtual ListaOrd<T> *CrearVacia() const abstract;

	//PRE:-
	//POS: Retorna una nueva lista idéntica a this y sin compartir memoria
	virtual ListaOrd<T> *Clon() const abstract;

	// PRE: !EsLlena()
	// POS: Agrega el elemento e en la lista ordenada de menor a mayor
	//      Usa el operador < del elemento e (inserta antes de uno mayor o igual)
	virtual void AgregarOrd(const T &e) abstract;

	// PRE: -
	// POS: Borra el menor elemento de la lista. Si no hay elementos no tiene efecto
	virtual void BorrarMinimo() abstract;

	// PRE: -
	// POS: Borra el mayor elemento de la lista. Si no hay elementos no tiene efecto
	virtual void BorrarMaximo() abstract;

	// PRE: -
	// POS: Borra el primer elemento que sea igual a e
	//		Usa el operador == del elemento e para encontrar uno igual.
	//		Si no encuentra no tiene efecto
	virtual void Borrar(const T &e) abstract;

	// PRE: !EsVacia()
	// POS: Retorna el menor elemento 
	virtual const T& Minimo() const abstract;

	// PRE: !EsVacia()
	// POS: Retorna el mayor elemento 	
	virtual const T& Maximo() const abstract;

	// PRE: Existe el elemento a recuperar
	// POS: Retorna el primer elemento que sea igual a e
	//		Usa el operador == del elemento e para encontrar uno igual
	virtual const T& Recuperar(const T &e) const abstract;

	// PRE: -
	// POS: Retorna true sii existe al menos un elemento que sea igual a e
	//		Usa el operador == del elemento e para encontrar uno igual
	virtual bool Existe(const T &e) const abstract;

	// PRE: -
	// POS: Vacia la lista
	virtual void Vaciar() 
	{
		while(!EsVacia())
			BorrarMinimo();
	}

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
	//	   El listado debe aparecer ordenado de menor a mayor.
	virtual void Imprimir(ostream& o) const abstract;

	// PRE: -
	// POS: Retorna si las 2 listas tienen los mismos elementos (comparados con el operador ==) 
	//      y en el mismo orden
	virtual bool operator==(const ListaOrd<T> &l) const { 
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
	// POS:*this == l y no  comparten memoria
	virtual ListaOrd<T> &operator=(const ListaOrd<T> &l) {
		if (this != &l) {
			this->Vaciar();

			for (Iterador<T> &i = l.GetIterador(); !i.EsFin();) {
				AgregarOrd(i++);
			}
		}
		return *this;
	}

protected:

	ListaOrd() { }
	ListaOrd(const ListaOrd &l) { assert(false); }

};


#endif