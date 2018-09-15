#pragma once

#ifndef PILA_H
#define PILA_H

#include <iostream>
using namespace std;
#include <assert.h>

template <class T>
class Pila;

template <class T>
ostream &operator<< <>(ostream& out, const Pila<T> &p) {
	p.Imprimir(out);
	return out;
}

template <class T>
class Pila abstract {

public:
	// PRE: -
	// POS: Destructor
	virtual ~Pila() {}

	// PRE: -
	// POS: Retorna una nueva coleccion vacia
	virtual Pila<T> *CrearVacia() const abstract;
	
	//PRE: -
	//POS: Retorna una nueva pila idéntica a this y sin compartir memoria
	virtual Pila<T> *Clon() const abstract;

	// PRE: !EsLlena()
	// POS: Inserta un elemento en el tope
	virtual void Push(const T &e) abstract;

	// PRE: !EsVacia()
	// POS: Devuelve el elemento del tope de la pila
	virtual T& Top() const abstract;

	// PRE: !EsVacia()
	// POS: Devuelve una copia del elemento del tope de la pila y lo elimina de la pila
	virtual T Pop() abstract;

	// PRE: -
	// POS: Vacia la pila y libera la memoria usada
	virtual void Vaciar() abstract;

	// PRE: -
	// POS: Retorna la cantidad de elementos presentes en la Pila
	virtual unsigned int CantidadElementos() const abstract;

	// PRE: -
	// POS: Retorna true si y solo si la pila esta vacia
	virtual bool EsVacia() const abstract;

	//PRE:--
	//POS: Retorna true si la pila esta llena.
	virtual bool EsLlena() const {
		return false;
	};

	// PRE: -
	// POS: *this==p y no comparten memoria
	virtual Pila<T> &operator=(const Pila<T> &p) abstract;
	
	//PRE: -
	//POS: retorna true sii this y p contienen los mismos elementos en el mismo orden
	virtual bool operator==(const Pila<T> &p) const abstract;
	
	//PRE:-
	//POS: Se llama desde el operator<<. Imprime los elementos de la Pila separados por un espacio en blanco
	//	   El listado debe aparecer ordenado de tope a fondo.
	virtual void Imprimir(ostream& o) const abstract;
	
protected:
	Pila() {}
	Pila(const Pila<T> &p) {}

};

#endif