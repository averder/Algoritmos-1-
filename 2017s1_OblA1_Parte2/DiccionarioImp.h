#ifndef DICCIONARIOIMP_H
#define DICCIONARIOIMP_H

#include "Diccionario.h"

template <class T>
class DiccionarioImp : public Diccionario<T>{

	friend ostream &operator<< <>(ostream& out, const DiccionarioImp<T> &d);

public:
	//Constructor por defecto
	DiccionarioImp();
	
	//Constructor copia
	DiccionarioImp(const Diccionario<T> &d);
	DiccionarioImp(const DiccionarioImp<T> &d);
	
	//Operador de asignacion
	Diccionario<T> &operator=(const Diccionario<T> &d);
	Diccionario<T> &operator=(const DiccionarioImp<T> &d);
	
	//Documentacion en la especificacion
	virtual ~DiccionarioImp();

	Diccionario<T> *CrearVacia() const;
	Diccionario<T>* Clon()const;

	void Insertar(const T& e);
	void Borrar(const T& e);
	const T& Elemento() const;
	bool Pertenece(const T& e) const;

	void Vaciar() ;
	unsigned int Cardinal() const;
	bool EsVacia() const;
	bool EsLlena() const;

	bool ContenidoEn(const Diccionario<T> &d) const;
	bool operator==(const Diccionario<T> &d);

	void Imprimir(ostream& o) const;

private:
	// Atributos de la clase
	
	
};

#include "DiccionarioImp.cpp"

#endif