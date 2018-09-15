#pragma once

#ifndef TABLA_H
#define TABLA_H

#include <iostream>
using namespace std;
#include <assert.h>
#include "Iterable.h"
#include "Asociacion.h"

template <class D, class R>
class Tabla;

template <class D, class R>
ostream &operator<< <>(ostream& out, const Tabla<D, R> &t) {
	t.Imprimir(out);
	return out;
}

template <class D, class R>
class Tabla abstract {
public:
	// PRE: -
	// POS: Destructor
	virtual ~Tabla() { }

	// PRE: -
	// POS: Retorna una nueva coleccion vacia
	virtual Tabla<D, R>* CrearVacia() const abstract;

	//PRE: -
	//POS: Retorna una nueva tabla igual a this y sin compartir memoria
	virtual Tabla<D, R>* Clon() const abstract;
	
	// PRE: !EsLlena()
	// POS: Define T(d) = r si la tabla no esta definida en d. 
	//      En caso contrario actualiza el valor T(d) con r.
	virtual void Insertar(const D &d, const R &r) abstract;

	// PRE: -
	// POS: EsVacia()
	virtual void Vaciar() abstract;

	// PRE: -
	// POS: Retorna la cantidad de elementos definidos en la tabla.
	virtual unsigned int CantidadElementos() const abstract;

	// PRE: -
	// POS: Retorna true si y solo si la tabla esta vacia.
	virtual bool EsVacia() const abstract; 

	// PRE: -
	// POS: Retorna true si y solo si la tabla esta llena.
	virtual bool EsLlena() const {
		return false;
	}

	// PRE: -
	// POS: Retorna true si y solo si la tabla esta definida en d.
	virtual bool EstaDefinida(const D &d) const abstract;

	// PRE: -
	// POS: Retorna true si y solo si this y t tienen los mismos elementos definidos 
	//      con el mismo valor asociado
	virtual bool operator==(const Tabla<D, R>& t) const abstract;

	// PRE: EstaDefinida(d)	
	// POS: Retorna el elemento T(d).
	virtual const R& Recuperar (const D &d) const abstract;

	// PRE: -
	// POS: Borra la asociacion ligada a d, siempre que esta exista.
	virtual void Borrar(const D &d) abstract;

	// PRE: !EsVacia()
	// POS: Retorna un dominio cualquiera de la tabla
	virtual const D& Elemento() const abstract;

	// PRE: -
	// POS: *this==t y no comparten memoria
	virtual Tabla<D, R>& operator=(const Tabla<D,R>& t) abstract;

	//PRE: -
	//POS: Se llama desde el operator<<. Imprime la tabla con el formato: {D:Dominio1|R:Rango1} {D:Dominio2|R:Rango2} {D:Dominio3|R:Rango3}...
	//	   El listado debe aparecer ordenado por dominio (de menor a mayor).
	virtual void Imprimir(ostream& o) const abstract;
	
protected:
	Tabla() {}
	Tabla(const Tabla<D, R> &t) {}

};

#endif