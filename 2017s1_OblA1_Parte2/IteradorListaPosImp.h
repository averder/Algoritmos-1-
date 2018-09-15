#pragma once

#ifndef ITERADORLISTAPOSIMP_H
#define ITERADORLISTAPOSIMP_H

#include "Iterador.h"
#include "ListaPosImp.h"

template <class T>
class ListaPosImp;

template <class T>
class IteradorListaPosImp : public Iterador<T> {

public:
	IteradorListaPosImp();
	IteradorListaPosImp(const ListaPosImp<T> &l);
	IteradorListaPosImp(const IteradorListaPosImp<T> &it);

	Iterador<T> &operator=(const IteradorListaPosImp<T> &it);
	Iterador<T> *Clon() const;

	virtual ~IteradorListaPosImp();

	const T &Elemento() const;
	T &ElementoInseguro() const;
	void Resto();
	bool EsFin() const;
	void Principio();

private:
	const ListaPos<T> *lista;
	unsigned int actual;
};

#include "IteradorListaPosImp.cpp"

#endif