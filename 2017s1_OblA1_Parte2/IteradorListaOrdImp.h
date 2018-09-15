#pragma once

#ifndef ITERADORLISTAORDIMP_H
#define ITERADORLISTAORDIMP_H

#include "Iterador.h"
#include "ListaOrdImp.h"

template <class T>
class ListaOrdImp;

template <class T>
class NodoLista;

template <class T>
class IteradorListaOrdImp : public Iterador<T> {
public:
	IteradorListaOrdImp();
	IteradorListaOrdImp(const ListaOrdImp<T> &l);
	IteradorListaOrdImp(const IteradorListaOrdImp<T> &it);
		
	Iterador<T> &operator=(const IteradorListaOrdImp<T> &it);
	Iterador<T> *Clon() const;

	virtual ~IteradorListaOrdImp();

	const T &Elemento() const;
	void Resto();
	bool EsFin() const;
	void Principio();

private:
	NodoLista<T> *actual;
	NodoLista<T> *ppio;
};

#include "IteradorListaOrdImp.cpp"

#endif