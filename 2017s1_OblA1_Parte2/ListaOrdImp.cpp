#include "ListaOrdImp.h"

#ifndef LISTAORDIMP_CPP
#define LISTAORDIMP_CPP

template <class T>
ostream &operator<< <>(ostream& out, const ListaOrdImp<T> &l) 
{
	l.Imprimir(out);
	return out;
}

template <class T>
ListaOrd<T>* ListaOrdImp<T>::CrearVacia() const 
{
	return new ListaOrdImp<T>();
}

template <class T>
ListaOrdImp<T>::ListaOrdImp()
{
	this->fin = NULL;
	this->ppio = NULL;
	this->largo = 0;
}

template <class T>
ListaOrdImp<T>::ListaOrdImp(const ListaOrd<T> &l) 
{
	this->fin = NULL;
	this->ppio = NULL;
	this->largo = 0;

	*this = l;
}

template <class T>
ListaOrdImp<T>::ListaOrdImp(const ListaOrdImp<T> &l) 
{
	this->fin = NULL;
	this->ppio = NULL;
	this->largo = 0;

	*this = l;
}

template <class T>
ListaOrd<T> &ListaOrdImp<T>::operator=(const ListaOrd<T> &l) 
{ 
	if (this != &l) {
		this->Vaciar();

		for (Iterador<T> &i = l.GetIterador(); !i.EsFin();) {
			AgregarOrd(i++);
		}
	}
	return *this;
}

template <class T>
ListaOrd<T> &ListaOrdImp<T>::operator=(const ListaOrdImp<T> &l) 
{ 
	if (this != &l) {
		this->Vaciar();

		for (Iterador<T> &i = l.GetIterador(); !i.EsFin();) {
			AgregarOrd(i++);
		}
	}
	return *this;
}

template <class T>
ListaOrdImp<T>::~ListaOrdImp()
{
	this->Vaciar();
}

template <class T>
void ListaOrdImp<T>::AgregarOrd(const T &e) 
{
	if(this->EsVacia())AgregarPpio(e); 
	else if (e <= ppio->dato ) 
		AgregarPpio(e);
	else if (fin->dato <= e)
		AgregarFin(e);
	else
		AgregarOrdAux(ppio, e);
}

template <class T>
void ListaOrdImp<T>::AgregarOrdAux(NodoLista<T> *nodo, const T &e)
{
	if (!(nodo->dato < e) || nodo->dato == e) {
		NodoLista<T> *nuevo = new NodoLista<T>(e, nodo->ant, nodo);
		nodo->ant->sig = nuevo;
		nodo->ant = nuevo;
		largo++;
	}
	else {
		AgregarOrdAux(nodo->sig, e);
	}
}

template <class T>
void ListaOrdImp<T>::BorrarMinimo() 
{
	if (ppio == NULL)
		return;

	NodoLista<T> *borrar = ppio;
	ppio = ppio->sig;
	delete borrar;
	largo--;

	if (ppio != NULL)
		ppio->ant = NULL;
	else 
		fin = NULL;
}

template <class T>
void ListaOrdImp<T>::BorrarMaximo() 
{
	if (fin == NULL)
		return;

	NodoLista<T> *borrar = fin;
	fin = fin->ant;
	delete borrar;
	largo--;

	if (fin != NULL)
		fin->sig = NULL;
	else 
		ppio = NULL;
}

template <class T>
void ListaOrdImp<T>::Borrar(const T &e)
{
	if (EsVacia())
		return;
	if (e == ppio->dato) 
		BorrarMinimo();
	else if (e == fin->dato)
		BorrarMaximo();
	else
		BorrarAux(ppio, e);
}

template <class T>
void ListaOrdImp<T>::BorrarAux(NodoLista<T> *nodo, const T &e)
{
	if (nodo == NULL)
		return;

	if (nodo->dato == e) {
		nodo->sig->ant = nodo->ant;
		nodo->ant->sig = nodo->sig;
		delete nodo;
		largo--;
	}
	else
		BorrarAux(nodo->sig, e);
}

template <class T>
const T& ListaOrdImp<T>::Minimo() const 
{
	assert(ppio!=NULL);
	return ppio->dato;
}

template <class T>
const T& ListaOrdImp<T>::Maximo() const 
{
	assert(fin!=NULL);
	return fin->dato;
}

template <class T>
const T& ListaOrdImp<T>::Recuperar(const T &e) const 
{
	assert(ppio != NULL);
	
	NodoLista<T> *aux = ppio;
	while (aux != NULL && !(aux->dato == e)) {
		aux = aux->sig;
	}

	assert(aux != NULL);
	
	return aux->dato;
}

template <class T>
bool ListaOrdImp<T>::Existe(const T &e) const 
{
	if (ppio == NULL)
		return false;
	
	NodoLista<T> *aux = ppio;
	while (aux != NULL && !(aux->dato == e)) {
		aux = aux->sig;
	}

	if (aux == NULL)
		return false;
	
	return true;
}

template <class T>
void ListaOrdImp<T>::Vaciar() 
{
	NodoLista<T> *aux = ppio;
	while (aux != NULL) {
		NodoLista<T> *borrar = aux;
		aux = aux->sig;
		delete borrar;
	}

	this->fin = NULL;
	this->ppio = NULL;
	this->largo = 0;
}

template <class T>
unsigned int ListaOrdImp<T>::CantidadElementos()const 
{ 
	return largo; 
}

template <class T>
bool ListaOrdImp<T>::EsVacia()const 
{
	return largo == 0; 
}

template <class T>
bool ListaOrdImp<T>::EsLlena()const 
{ 
	return false; 
}

template<class T>
ListaOrd<T>* ListaOrdImp<T>::Clon() const
{
	ListaOrd<T>* clon = new ListaOrdImp<T>();
	
	for (Iterador<T>& i = this->GetIterador(); !i.EsFin();)
		clon->AgregarOrd(i++);

	return clon;
}

template <class T>
Iterador<T> ListaOrdImp<T>::GetIterador() const 
{
	return IteradorListaOrdImp<T>(*this);
}

template <class T>
void ListaOrdImp<T>::Imprimir(ostream& o) const
{
	for (Iterador<T> &i = GetIterador(); !i.EsFin();) {
		o << i++ << " ";
	}
}

template <class T>
void ListaOrdImp<T>::AgregarPpio(const T &e){
	NodoLista<T> *nuevo = new NodoLista<T>(e, NULL, ppio);
	if (fin == NULL)
		fin = nuevo;
	else
		ppio->ant = nuevo;
	ppio = nuevo;
	largo++;
}

template <class T>
void ListaOrdImp<T>::AgregarFin(const T &e)
{
	NodoLista<T> *nuevo = new NodoLista<T>(e, fin, NULL);
	if (!ppio)
		ppio = nuevo;
	else
		fin->sig = nuevo;
	fin = nuevo;
	largo++;
}

#endif