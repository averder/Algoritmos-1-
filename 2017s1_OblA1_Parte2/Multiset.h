#pragma once

#ifndef MULTISET_H
#define MULTISET_H

#include <iostream>
using namespace std;
#include <assert.h>

template <class T>
class MultiSet;

template <class T>
ostream &operator<< <>(ostream& out, const MultiSet<T> &m) {
	m.Imprimir(out);
	return out;
}

template <class T>
class MultiSet abstract {
public:
	// PRE: -
	// POS: Destructor
	virtual ~MultiSet() { }

	// PRE: -
	// POS: Retorna una nueva coleccion vacia
	virtual MultiSet<T>* CrearVacia() const abstract;

	// PRE: -
	// POS: Devuelve un nuevo MultiSet igual al this, que no comparte memoria
	virtual MultiSet<T>* Clon() const abstract;

	// PRE: !EsLlena()
	// POS: Inserta cantidad de e elementos al MultiSet
	virtual void Insertar(const T &e, unsigned int cantidad) abstract;

	// PRE: -
	// POS: Borra hasta cantidad de e elementos del MultiSet
	virtual void Borrar(const T &e, unsigned int cantidad) abstract;
	
	// PRE: !EsVacia() 
	// POS: Devuelve un elemento cualquiera del MultiSet
	virtual const T& Elemento() const abstract;

	// PRE: Existe(e) 
	// POS: Devuelve una ocurrencia cualquiera del elemento e
	//	Utiliza el operador == del elemento e para encontrarlo
	virtual const T& Recuperar(const T &e) const abstract;

	// PRE: -
	// POS: Devuelve la cantidad de ocurrencias del elemento e en el MultiSet
	//	Utiliza el operador == del elemento e
	virtual unsigned int OcurrenciasElemento(const T &e) const abstract;

	// PRE: -
	// POS: Devuelve true si el elemento pertenece al MultiSet
	//		Utiliza el operador == del elemento e para encontrarlo
	virtual bool Pertenece(const T &e) const
	{
		return OcurrenciasElemento(e) > 0;
	}

	// PRE: -
	// POS:	EsVacia() 
	virtual void Vaciar() abstract;

	// PRE: -
	// POS: Devuelve true si y solo si el MultiSet esta vacio
	virtual bool EsVacia() const {
		return Cardinal()==0;
	}

	// PRE: -
	// POS: Devuelve true si y solo si el MultiSet está lleno
	virtual bool EsLlena() const abstract;

	// PRE: -
	// POS: Devuelve la cantidad de elementos distintos del MultiSet
	//	Dados dos elementos e1 y e2 pertenecientes al MultiSet, son distintos si e1 != e2
	//	(utilizando el operador == del elemento)
	virtual unsigned int Cardinal() const abstract;

	// PRE: -
	// POS: Retorna un nuevo MultiSet que es la union de this y s,
	//		o sea, el conjunto que contiene los elementos de this y de s
	//		Ejemplo: {1,1,1,2,3} union {1,1,3,5} == {1,1,1,2,3,5}
	//		No se debe modificar a s (aunque falte el const en el parámetro)
	virtual MultiSet<T>* Union(MultiSet<T>& s) const abstract; 

	// PRE: -
	// POS: Retorna un nuevo MultiSet que es la intersección de this y s,
	//		o sea, el conjunto que contiene solo los elementos comunes a this y s 	
	//		Ejemplo: {1,1,1,2,3} interseccion {1,1,3,5} == {1,1,3}
	//		No se debe modificar a s (aunque falte el const en el parámetro)
	virtual MultiSet<T>* Interseccion(MultiSet<T>& s) const abstract; 

	// PRE: -
	// POS: Retorna un nuevo MultiSet que es la diferencia entre this y s,
	//		o sea, el conjunto que contiene solo los elementos que estan en this pero no en s	
	//		Ejemplo: {1,1,1,2,3} diferencia {1,1,3,5} == {1,2}
	//		No se debe modificar a s (aunque falte el const en el parámetro)
	virtual MultiSet<T>* Diferencia(MultiSet<T>& s) const abstract; 

	//PRE: -
	//POS: Retorna si todos los elementos de this pertenecen a s
	//		Ejemplo: {1,1,2,3} ContenidoEn {1,1,1,2,3,5} == true
	//		Ejemplo: {1,1,1,2,3} ContenidoEn {1,1,2,3,5} == false
	virtual bool ContenidoEn(const MultiSet<T> &s) const abstract;

	// PRE: -
	// POS: Devuelve true si multiSet y this tienen los mismos elementos 
	// 		y además con la misma cantidad de ocurrencias
	//		Utiliza el operador == de T
	virtual bool operator==(const MultiSet<T> &multiSet) const abstract;

	// PRE: -
	// POS: 	*this == multiSet y no comparten memoria
	virtual MultiSet<T> &operator=(const MultiSet<T> &multiSet) abstract;

	//PRE: -
	//POS: Se llama desde el operator<<. Imprime los elementos del MultiSet separados por un espacio en blanco
	//	   El listado debe aparecer ordenado (de menor a mayor).
	virtual void Imprimir(ostream& o) const abstract;
protected:

	MultiSet() { }
	MultiSet(const MultiSet<T> &multiSet) { assert(false); }

};

#endif