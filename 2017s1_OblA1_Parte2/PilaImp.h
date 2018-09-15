#ifndef PILAIMP_H
#define PILAIMP_H

#include "Pila.h"

template <class T>
class PilaImp : public Pila<T> {

public:
	//Constructor por defecto
	PilaImp();

	//Constructor copia
	PilaImp(const Pila<T> &p);
	PilaImp(const PilaImp<T> &p);

	//Operador de asignacion
	Pila<T> &operator=(const Pila<T> &p);
	Pila<T> &operator=(const PilaImp<T> &p);
	 

	//Documentacion en la especificacion
	virtual ~PilaImp();
	
	Pila<T> *CrearVacia() const;
	Pila<T> *Clon() const;
	
	void Push(const T &e);
	T& Top() const;
	T Pop();

	void Vaciar();
	unsigned int CantidadElementos() const;
	bool EsVacia() const;
	bool EsLlena() const;

	bool operator==(const Pila<T> &p) const;
	
	void Imprimir(ostream& o) const;

private:
	// Atributos de la clase
	
	
};

#include "PilaImp.cpp"

#endif