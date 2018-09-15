#pragma once

#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include <iostream>
using namespace std;
#include <assert.h>

template <class T>
class Diccionario;

template <class T>
ostream &operator<< <>(ostream& out, const Diccionario<T> &d) {
	d.Imprimir(out);
	return out;
}

template <class T>
class Diccionario abstract {
public:

	//PRE: -
	//POS: Destructor 
	virtual ~Diccionario(){}

	// PRE: -
	// POS: Retorna una nueva coleccion vacia
	virtual Diccionario<T> *CrearVacia() const abstract;

	// PRE: -
	// POS: Retorna un nuevo diccionario igual a this que no comparte memoria
	virtual Diccionario<T> *Clon() const abstract;

	//PRE:!EsLlena()	
	//POS: Pertenece(e)
	virtual void Insertar(const T& e) abstract;

	//PRE: 
	//POS: !Pertenece(e)
	virtual void Borrar(const T& e) abstract;

	// PRE: !EsVacia()
	// POS: Retorna un elemento cualquiera del Diccionario 
	virtual const T& Elemento() const abstract;
	
	//PRE: -
	//POS: Retorna true si y solo si el elemento pertenece al Diccionario.
	virtual bool Pertenece(const T& e) const abstract;

	//PRE: -
	//POS: EsVacia()
	virtual void Vaciar() abstract;

	//PRE: -
	//POS: Retorna la cantidad de elementos del diccionario.
	virtual unsigned int Cardinal() const abstract;
	
	//PRE: -
	//POS: Retorna true si y solo si no hay elementos en el Diccionario.
	virtual bool EsVacia() const abstract;

	//PRE: -
	//POS: Retorna true si y solo si el Diccionario está lleno.
	virtual bool EsLlena() const {
		return false;
	}

   	//PRE: -
	//POS:*this==l y no comparten memoria
	virtual Diccionario<T> &operator=(const Diccionario<T> &d) abstract;

	//PRE: - 
	//POS: Retorna true sii todos los elementos de this están contenidos en d
	virtual bool ContenidoEn(const Diccionario<T> &d) const abstract;
 
	//PRE: - 
	//POS: retorna true sii this y d tienen los mismos elementos
	virtual bool operator==(const Diccionario<T> &d) const
	{
		return this->ContenidoEn(d) && d.ContenidoEn(*this);
	}

	//PRE:-
	//POS: Se llama desde el operator<<. Imprime los elementos del Diccionario separados por un espacio en blanco
	//	   El listado debe aparecer ordenado de menor a mayor.
	virtual void Imprimir(ostream& o) const abstract;

protected:
	Diccionario(){}
	Diccionario(const Diccionario<T> &d){}
};

#endif