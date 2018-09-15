#pragma once

#ifndef COLAPRIORIDADIMP_H
#define COLAPRIORIDADIMP_H

#include "ColaPrioridad.h"

template <class T, class P>
class ColaPrioridadImp : public ColaPrioridad<T, P> {
public:
	//Constructor por defecto
	ColaPrioridadImp();

	//Constructor copia
	ColaPrioridadImp(const ColaPrioridad<T, P> &cp);
	ColaPrioridadImp(const ColaPrioridadImp<T, P> &cp);

	//Operador de asignacion
	ColaPrioridad<T, P> &operator=(const ColaPrioridad<T, P> &cp);
	ColaPrioridad<T, P> &operator=(const ColaPrioridadImp<T, P> &cp);

	//Documentacion en la especificacion
	virtual ~ColaPrioridadImp();

	ColaPrioridad<T, P>* CrearVacia() const;
	ColaPrioridad<T, P>* Clon() const;

	void Encolar(const T &e, const P &p);
	T& PrincipioElemento() const;
	const P& PrincipioPrioridad() const;
	void Desencolar();
	bool EsVacia() const;
	bool EsLlena() const;

	void Vaciar();

	unsigned int Largo() const;
	bool operator==(const ColaPrioridad<T, P> &cp) const;

	void Imprimir(ostream& o) const;
private:
	// Atributos de la clase
	
	
};

#include "ColaPrioridadImp.cpp"

#endif