#ifndef SETIMP_H
#define SETIMP_H

#include "Set.h"


template <class T>
class SetImp: public Set<T> {
public:

	// Constructor por defecto
	SetImp();

	// Constructor copia
	SetImp(const Set<T> &s);
	SetImp(const SetImp<T> &s);

	// Operador de asignacion
	Set<T> &operator=(const Set<T> &s);
	Set<T> &operator=(const SetImp<T> &s);


	// Para ver la documentacion del resto de las funciones ver la especificacion
	virtual ~SetImp();

	Set<T>* CrearVacia() const;
	Set<T>* Clon() const;

	void Insertar(const T &e);
	void Borrar(const T &e);
	const T& Elemento() const;
	const T& Recuperar(const T &e) const;
	bool Pertenece(const T &e) const;
	void Vaciar();
	bool EsVacia() const;
	bool EsLlena() const;
	unsigned int Cardinal() const;

	Set<T>* Union(Set<T>& s) const; 
	Set<T>* Interseccion(Set<T>& s) const; 
	Set<T>* Diferencia(Set<T>& s) const; 
	bool ContenidoEn(const Set<T> &s) const;
	
	bool operator==(const Set<T> &s) const;

	void Imprimir(ostream& o) const;
protected:
	// Atributos de la clase
	
	
};

#include "SetImp.cpp"

#endif