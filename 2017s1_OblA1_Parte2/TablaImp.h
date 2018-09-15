#ifndef TABLAIMP_H
#define TABLAIMP_H

#include <iostream>
using namespace std;

#include "Tabla.h"

template <class D, class R>
class TablaImp : public Tabla<D, R> {
public:
	//Constructor por defecto
	TablaImp();

	//Constructor copia
	TablaImp(const Tabla<D, R> &t);
	TablaImp(const TablaImp<D, R> &t);
		
	//Operador de asignacion
	Tabla<D, R> &operator=(const Tabla<D, R> &t);
	Tabla<D, R> &operator=(const TablaImp<D, R> &t);

	//Documentacion en la especificacion
	virtual ~TablaImp();

	Tabla<D, R>* CrearVacia() const;
	Tabla<D, R>* Clon() const;

	void Insertar(const D &d, const R &r);
	void Vaciar();
	unsigned int CantidadElementos() const;
	bool EsVacia() const;
	bool EsLlena() const;
	
	bool EstaDefinida(const D &d) const;
	bool operator==(const Tabla<D, R>& t) const;

	const R& Recuperar (const D &d) const;
	void Borrar (const D &d);
	const D& Elemento() const;
	
	void Imprimir(ostream& o) const;

protected:
	// Atributos de la clase
	
	
};

#include "TablaImp.cpp"

#endif