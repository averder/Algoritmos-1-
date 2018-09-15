#pragma once

#ifndef COLAPRIORIDAD_H
#define COLAPRIORIDAD_H

#include <iostream>
using namespace std;
#include <assert.h>

template <class T, class P>
class ColaPrioridad;

template <class T, class P>
ostream &operator<< <>(ostream& out, const ColaPrioridad<T, P> &cp) {
	cp.Imprimir(out);
	return out;
}

template <class T, class P>
class ColaPrioridad abstract {
public:
	//PRE: -
	//POS: Destructor
	virtual ~ColaPrioridad() { }

	//PRE: - 
	// POS: Retorna una nueva coleccion vacia
	virtual ColaPrioridad<T, P>* CrearVacia() const abstract;

	//PRE: -
	//POS: Retorna una Cola de prioridad que contiene todos los elementos
	//	de la original con la misma prioridad y no comparte memoria
	virtual ColaPrioridad<T, P>* Clon() const abstract;

	//PRE: !EsLlena()
	//POS: Agrega el elemento e con prioridad p a la cola de prioridad. Los elementos con 
	//	igual prioridad se agregan en orden FIFO
	virtual void Encolar(const T &e, const P &p) abstract;

	//PRE: !EsVacia()
	//POS: Retorna el elemento de mayor prioridad
	virtual T& PrincipioElemento() const abstract;

	//PRE: La cola de prioridad no es vacia
	//POS: Retorna la mayor prioridad
	virtual const P& PrincipioPrioridad() const abstract;

	//PRE: !EsVacia()
	//POS: Borra el elemento de mayor prioridad 
	virtual void Desencolar() abstract;

	//PRE: -
	//POS: EsVacia()
	virtual void Vaciar() abstract;

	//PRE: -
	//POS: Retorna el largo de la cola de prioridad
	virtual unsigned int Largo() const abstract;

	//PRE: -
	//POS: Retorna true si y solo si la cola de prioridad esta vacia
	virtual bool EsVacia() const {
		return this->Largo() == 0;
	}

	//PRE: -
	//POS: Retorna true si y solo si la cola de prioridad esta llena
	virtual bool EsLlena() const {
		return false;
	}

	//PRE: -
	//POS: *this==cp y no comparten memoria
	virtual ColaPrioridad<T, P> &operator=(const ColaPrioridad<T, P> &cp) abstract;

	//PRE: -
	//POS: Retorna si las 2 listas tienen los mismos elementos 
	//	   y misma prioridad (compara con el operador ==)
	virtual bool operator==(const ColaPrioridad<T, P> &cp) const abstract;

	//PRE: -
	//POS: Se llama desde el operator<<. Imprime la cola de prioridad con el formato: {T:Dato1|P:Prioridad1} {T:Dato2|P:Prioridad2} {T:Dato3|P:Prioridad3}...
	//	   El listado debe aparecer ordenado por prioridad (de mayor a menor prioridad).
	virtual void Imprimir(ostream& o) const abstract;

protected:

	ColaPrioridad() {}
	ColaPrioridad(const ColaPrioridad<T,P> &cp) {}
};

#endif