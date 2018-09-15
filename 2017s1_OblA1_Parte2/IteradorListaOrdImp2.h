#pragma once

#ifndef ITERADORLISTAORDIMP2_H
#define ITERADORLISTAORDIMP2_H

#include "Iterador.h"
#include "ListaPosImp.h"

template <class T>
class ListaOrdImp;

template <class T>
class IteradorListaOrdImp2 : public Iterador<T> {
public:
	IteradorListaOrdImp2();
	IteradorListaOrdImp2(const ListaPosImp<T> &l);
	IteradorListaOrdImp2(const IteradorListaOrdImp2<T> &it);
		
	Iterador<T> &operator=(const IteradorListaOrdImp2<T> &it);
	Iterador<T> *Clon() const;

	virtual ~IteradorListaOrdImp2();

	const T &Elemento() const;
	void Resto();
	bool EsFin() const;
	void Principio();

private:
	const ListaPos<T> *lista;
	unsigned int actual;
};

#include "IteradorListaOrdImp2.cpp"

#endif