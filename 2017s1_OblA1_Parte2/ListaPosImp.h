#ifndef LISTAPOSIMP_H
#define LISTAPOSIMP_H

#include <assert.h>
#include "ListaPos.h"
#include "IteradorListaPosImp.h"
#include "NodoLista.h"

template <class T>
class IteradorListaPosImp;

template <class T>
class ListaPosImp : public ListaPos<T> {
	friend class IteradorListaPosImp<T>;
	friend ostream &operator<< <>(ostream& o, const ListaPosImp<T> & l);
public:
	// Constructor por defecto
	ListaPosImp();

	// Constructor copia
	ListaPosImp(const ListaPos<T> &l);
	ListaPosImp(const ListaPosImp<T> &l);

	// Operador de asignacion
	ListaPos<T> &operator=(const ListaPos<T> &l);
	ListaPos<T> &operator=(const ListaPosImp<T> &l);

	// Para ver la documentacion del resto de las funciones ver la especificacion
	ListaPos<T> *CrearVacia() const;
	virtual ~ListaPosImp();

	void AgregarPpio(const T &e);
	void AgregarFin(const T &e);
	void AgregarPos(const T &e, unsigned int pos);
	
	void BorrarPpio();	
	void BorrarFin();
	void BorrarPos(unsigned int pos);
	void Borrar(const T &e);

	T& ElementoPpio() const;
	T& ElementoFin() const;
	T& ElementoPos(unsigned int pos) const;
	
	unsigned int Posicion(const T &e) const;
	bool Existe(const T &e) const;	

	void Vaciar();

	unsigned int CantidadElementos() const;

	bool EsVacia() const;
	bool EsLlena() const;
	
	ListaPos<T>* Clon() const;

	Iterador<T> GetIterador() const;
	void Imprimir(ostream& o) const;

protected:
	// Atributos de la clase

};

#include "ListaPosImp.cpp"

#endif