#include "EjerciciosSem5.h"

#ifndef EJERCICIOSSEM5_CPP
#define EJERCICIOSSEM5_CPP

void eliminarNesimoDesdeElFinal(NodoLista*& lista, int &k) 
{	
	if (!esVacia(lista)) {
		eliminarNesimoDesdeElFinal(lista->sig, k);
		if (k == 1) {
			NodoLista* aux = lista;
			lista = lista->sig;
			delete aux;
		}
		k--;
	}
}

bool esVacia(NodoLista *&l) {
	return l == NULL;
}

void insertarInicio(int d, NodoLista* &l) {
	NodoLista* nuevo = new NodoLista(d);
	nuevo->sig = l;
	l = nuevo;
}

void insertarFin(int d, NodoLista*& l) {
	if (esVacia(l))
		insertarInicio(d, l);
	else
		insertarFin(d, l->sig);
}

NodoLista* listaOrdenadaInsertionSort(NodoLista* l) 
{
	int largo = largoLst(l);
	int* vec = new int[largo];
	NodoLista* retorno = NULL;
	for (int i = 0; i < largo; i++)
	{
		vec[i] = l->dato;
		l = l->sig;
	}
	insertionSort(vec, largo);
	for (int i = largo - 1; i>-1; i--)
	{
		insertarInicio(vec[i], retorno);
	}
	delete[] vec;
	return retorno;
	return NULL;
}

int largoLst(NodoLista* l) {
	int largo = 0;
	while (l) {
		l = l->sig;
		largo++;
	}
	return largo;
}

void insertionSort(int* vec, int n) {
	for (int i = 0; i <n; i++)
	{
		for (int j = i; j >0; j--)
		{
			if (vec[j - 1]>vec[j])
			{
				int aux = vec[j - 1];
				vec[j - 1] = vec[j];
				vec[j] = aux;
			}
		}
	}
}

NodoLista* invertirParcial(NodoLista* l)
{
	NodoLista* retorno = NULL;
	if (l)
	{
		while (l->sig)
		{
			insertarInicio(l->dato, retorno);
			l = l->sig;
		}
	}
	return retorno;
}

void listaOrdenadaSelectionSort(NodoLista*& l){
	if(!esVacia(l)){ 
		NodoLista* iter = l;
		NodoLista* aux = l;
		int min = aux->dato;
		while (aux->sig != NULL){
			while (iter) {
				//encuentra el min
				if (iter->dato < min){
					int var = iter->dato;
					iter->dato = aux->dato;
					aux->dato = var;
					min = var;

				}
				iter = iter->sig;
			}
			aux = aux->sig;
			min = aux->dato;
			iter = aux;
		}
	}
}


NodoLista* intercalarIter(NodoLista* l1, NodoLista* l2)
{
	NodoLista* retorno = NULL;
	if (!esVacia(l1) && !esVacia(l2))
	{
		
		while (l1 !=NULL && l2!=NULL){
			if (l1->dato > l2->dato)
			{
				insertarFin(l2->dato, retorno);
				l2 = l2->sig;
			}
			else {
				insertarFin(l1->dato, retorno);
				l1 = l1->sig;
			}
		}
	}
	if (esVacia(l1)) {
		while (l2)
		{
			insertarFin(l2->dato, retorno);
			l2 = l2->sig;
		}
	}
	else{
		while (l1)
		{
			insertarFin(l1->dato, retorno);
			l1 = l1->sig;
		}
	}
	return retorno;

}

NodoLista* intercalarRec(NodoLista* l1, NodoLista* l2)
{
	NodoLista* retorno = NULL;
	if (l1 == NULL && l2 == NULL)
	{
		return retorno;
	}
	if(l1 && l2) {
		if (l1->dato < l2->dato) {
			retorno = new NodoLista(l1->dato);
			retorno->sig = intercalarRec(l1->sig, l2);
		}
		else {
			retorno = new NodoLista(l2->dato);
			retorno->sig = intercalarRec(l1, l2->sig);
		}
	}
	else if (!l1) {
		retorno = new NodoLista(l2->dato);
		retorno->sig = intercalarRec(l1, l2->sig);
	}
	else if (!l2) {
		retorno = new NodoLista(l1->dato);
		retorno->sig = intercalarRec(l1->sig, l2);
	}
	return retorno;
}

NodoLista* insComFin(NodoLista* l, int x)
{
	NodoLista* retorno = NULL;
	while (l)
	{
		insertarInicio(l->dato, retorno);
		l = l->sig;
	}
	insertarInicio(x,retorno);
	insertarFin(x, retorno);
	return retorno;
}

NodoLista* exor(NodoLista* l1, NodoLista* l2)
{	NodoLista* retorno = NULL;
	if (esVacia(l1) && esVacia(l2)) {
		return retorno;
	}
	while (!esVacia(l1) && l1->sig && l1->dato == (l1->sig)->dato) {
		l1 = l1->sig;
	}
	while (!esVacia(l2) &&l2->sig && l2->dato == (l2->sig)->dato) {
		l2 = l2->sig;
	}
	if (!l1) {
		insertarFin(l2->dato, retorno);
		retorno->sig = exor(l1, l2->sig);
	}
	else if (!l2) {
		insertarFin(l1->dato, retorno);
		retorno->sig = exor(l1->sig, l2);
	}

	if(!esVacia(l1)&&!esVacia(l2)) {
		if (l1->dato < l2->dato) {
			insertarFin(l1->dato, retorno);
			retorno->sig = exor(l1->sig, l2);
		}
		else if (l1->dato > l2->dato) {
			insertarFin(l2->dato, retorno);
			retorno->sig = exor(l1, l2->sig);
		}
		else {
			if (l1->sig && l2->sig)
				retorno = exor(l1->sig, l2->sig);
		}
	}
	return retorno;
}

void eliminarDuplicadosListaOrdenadaDos(NodoLista*& l) 
{
	if (esVacia(l)){
		return;
	}
	else {
		
		if (l->sig && l->dato == (l->sig)->dato ){
			elim1(l);
			eliminarDuplicadosListaOrdenadaDos(l);
		}
		else {
			eliminarDuplicadosListaOrdenadaDos(l->sig);
		}
	}
}

void elim1(NodoLista*&l) {
	NodoLista* iter = l;
	int d = l->dato;
	while (iter && iter ->dato == d)
	{
		l = l->sig;
		delete iter;
		iter = l;
	}
}

bool palindromo(NodoLista* l)
{
	NodoLista* invertido = NULL;
	NodoLista* iter = l;
	while (iter){
		 insertarInicio(iter->dato,invertido);
		 iter = iter->sig;
	}
	while (l){
		if (l->dato != invertido->dato){
			return false;
		}
		l = l->sig;
		invertido = invertido->sig;
	}
	return true;
}

//PRE:
//POS: retorna true si existe una secuencia en la lista.
bool esSecuencia(NodoLista* l, NodoLista* secuencia) {
	if (!esVacia(secuencia)) {
		if (!esVacia(l)) {
			return l->dato == secuencia->dato && esSecuencia(l->sig, secuencia->sig);

		}
		if (esVacia(l)) {
			return false;
		}
	}
	return true;
}


void eliminarSecuencia(NodoLista* &l, NodoLista* secuencia)
{
	if (!esVacia(l)) {
		if (!esVacia(secuencia)) {
			if (esSecuencia(l, secuencia)) {
				while (!esVacia(secuencia)) {
					NodoLista* borrar = l;
					l = l->sig;
					delete borrar;
					secuencia = secuencia->sig;
				}
			}
			else {
				eliminarSecuencia(l->sig, secuencia);
			}

		}
	}
}



//PRE: d>0, !esVacia().
//POS: dada una lista y una posicion, retorna el puntero de la lista en dicha posicion.

NodoLista* posicion(NodoLista*l, int d) {
	int cont = 1;
	while (!esVacia(l) && cont != d) {
		l = l->sig;
		cont++;
	}
	NodoLista* aux = l;
	return aux;
}

void moverNodo(NodoLista* &lista, unsigned int inicial, unsigned int final)
{
	if (!esVacia(lista)) {
		if (inicial>0 && final>0 && inicial <= (largoLst(lista)) && final <= (largoLst(lista))) {
			NodoLista* aux1 = lista;
			NodoLista* aux2 = lista;
			if (inicial == 1 && final != 1) {
				aux1 = posicion(lista, final);
				lista = lista->sig;
				aux2->sig = aux1->sig;
				aux1->sig = aux2;
			}
			else if (inicial != 1 && final == 1) {
				aux1 = posicion(lista, inicial - 1);
				aux2 = aux1->sig;
				aux1->sig = aux2->sig;
				aux2->sig = lista;
				lista = aux2;
			}
			else if (inicial != 1 && final != 1) {
				aux1 = posicion(lista, inicial - 1);
				aux2 = aux1->sig;
				aux1->sig = aux2->sig;
				aux1 = posicion(lista, final - 1);
				aux2->sig = aux1->sig;
				aux1->sig = aux2;
			}

		}
	}
}



#endif