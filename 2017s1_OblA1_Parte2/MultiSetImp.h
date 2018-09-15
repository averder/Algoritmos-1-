#ifndef MULTISET_IMP_H
#define MULTISET_IMP_H

#include "MultiSet.h"

template <class T>
class MultiSetImp: public MultiSet<T> {
public:

	// Constructor por defecto
	MultiSetImp();

	// Constructor copia
	MultiSetImp(const MultiSet<T> &multiSet);
	MultiSetImp(const MultiSetImp<T> &multiSet);

	// Operador de asignacion
	MultiSet<T>& operator=(const MultiSet<T> &multiSet);
	MultiSet<T>& operator=(const MultiSetImp<T> &multiSet);

	// Para ver la documentacion del resto de las funciones ver la especificacion
	virtual ~MultiSetImp();

	MultiSet<T>* CrearVacia() const;
	MultiSet<T>* Clon() const;

	void Insertar(const T &e, unsigned int cantidad);
	void Borrar(const T &e, unsigned int cantidad);
	const T& Elemento() const;
	const T& Recuperar(const T &e) const;
	unsigned int OcurrenciasElemento(const T &e) const;
	bool Pertenece(const T &e) const;
	void Vaciar();
	bool EsVacia() const;
	bool EsLlena() const;
	unsigned int Cardinal() const;

	MultiSet<T>* Union(MultiSet<T>& s) const; 
	MultiSet<T>* Interseccion(MultiSet<T>& s) const; 
	MultiSet<T>* Diferencia(MultiSet<T>& s) const; 
	bool ContenidoEn(const MultiSet<T> &s) const;

	bool operator==(const MultiSet<T> &multiSet) const;

	void Imprimir(ostream& o) const;
private:
	// Atributos de la clase
	
	
};

#include "MultiSetImp.cpp"

#endif