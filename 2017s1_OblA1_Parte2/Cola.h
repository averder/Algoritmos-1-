#pragma once

#ifndef COLA_H
#define COLA_H

#include <iostream>
using namespace std;
#include <assert.h>

template <class T>
class Cola;

template <class T>
ostream &operator<< <>(ostream& out, const Cola<T> &c) {
	c.Imprimir(out);
	return out;
}

template <class T>
class Cola abstract {

public:

	// PRE: -
	// POS: Destructor
	virtual ~Cola() { }

	// PRE: -
	// POS: Retorna una nueva coleccion vacia
	virtual Cola<T> *CrearVacia() const abstract;
      
 	// PRE: -
    //POS: retorna una copia de this que no comparte memoria
	virtual Cola<T> *Clon() const abstract;

	
	// PRE: !EsLlena()
	// POS: Inserta un elemento al fondo
	virtual void Encolar(const T &e) abstract;

	// PRE: !EsVacia()
	// POS: Retorna el elemento del principio de la cola
	virtual T& Principio() const abstract;

	// PRE: !EsVacia()
	// POS: Extrae el elemento del principio y lo retorna
	virtual T Desencolar() abstract;

	// PRE: -
	// POS: EsVacia() recuperando la memoria usada
	virtual void Vaciar() abstract;

	// PRE: -
	// POS: Retorna la cantidad de elementos presentes en la cola
	virtual unsigned int CantidadElementos() const abstract;

	// PRE: -
	// POS: Retorna true si y solo si la cola esta vacia
	virtual bool EsVacia() const abstract;
	
	//PRE:--
	//POS: Retorna true si la cola esta llena.
	virtual bool EsLlena() const abstract;

	// PRE: -
	// POS: *this==c y no comparten memoria
	virtual Cola<T> &operator=(const Cola<T> &c) abstract;

	//PRE: -
	//POS: retorna true sii this y c contienen los mismos elementos en el mismo orden
	virtual bool operator==(const Cola<T>& c) const abstract;


	//PRE:-
	//POS: Se llama desde el operator<<. Imprime los elementos de la Cola separados por un espacio en blanco
	//	   El listado debe aparecer ordenado de principio a fin.
	virtual void Imprimir(ostream& o) const abstract;
	
protected:
	Cola() {}
	Cola(const Cola<T> &c) {}

};


#endif