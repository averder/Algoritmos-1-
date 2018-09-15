// Comentar la siguiente linea si es DLL
#define FRAMEWORKA1DLL_API  

// Descomentar las siguiente linea si es DLL
/*
#ifdef FRAMEWORKA1DLL_EXPORTS
#define FRAMEWORKA1DLL_API __declspec(dllexport) 
#else
#define FRAMEWORKA1DLL_API __declspec(dllimport) 
#endif
*/

#ifndef FUNCAUXTAD_H
#define FUNCAUXTAD_H

#include <sstream>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;

#include "Definiciones.h"
#include "ColaArray.h"

#include "ListaOrdImp.h"
#include "ListaPosImp.h"
#include "PilaImp.h"
#include "ColaImp.h"
#include "MultiSetImp.h"
#include "SetImp.h"
#include "DiccionarioImp.h"
#include "ColaPrioridadImp.h"
#include "TablaImp.h"

namespace FrameworkA1
{
	/*
	PRE: 
	POS: devuelve una ListaOrd<int> a partir de NodoListaS.
		 Los elementos quedan ordenados
	*/
	FRAMEWORKA1DLL_API ListaOrd<int>* ConvertirAListaOrd(NodoListaS *l);

	/*
	PRE: 
	POS: devuelve una ListaPos<int> a partir de NodoListaS. 
		 Los elementos quedan en las mismas posiciones
	*/
	FRAMEWORKA1DLL_API ListaPos<int>* ConvertirAListaPos(NodoListaS *l);

	/*
	PRE: 
	POS: devuelve una Pila<int> a partir de NodoListaS. 
		 El ultimo elemento de la lista queda en el tope de la pila.
	*/
	FRAMEWORKA1DLL_API Pila<int>* ConvertirAPila(NodoListaS *l);
	
	/*
	PRE: 
	POS: devuelve una Cola<int> a partir de NodoListaS. 
		 El primer elemento de la lista queda en el pricipio de la cola.
	*/
	FRAMEWORKA1DLL_API Cola<int>* ConvertirACola(NodoListaS *l);

	/*
	PRE: 
	POS: devuelve un MultiSet<int> a partir de NodoListaS. 
	*/
	FRAMEWORKA1DLL_API MultiSet<int>* ConvertirAMultiSet(NodoListaS *l);

	/*
	PRE: 
	POS: devuelve un Diccionario<int> a partir de NodoListaS. 
	*/
	FRAMEWORKA1DLL_API Set<int>* ConvertirASet(NodoListaS *l);

	/*
	PRE: 
	POS: devuelve un Diccionario<int> a partir de NodoListaS. 
	*/
	FRAMEWORKA1DLL_API Diccionario<int>* ConvertirADiccionario(NodoListaS *l);

	/*
	PRE: 
	POS: devuelve un Diccionario<int> a partir de NodoListaS. 
	*/
	FRAMEWORKA1DLL_API Tabla<int, int>* ConvertirATabla(NodoListaS *d, NodoListaS *r);

	/*
	PRE: 
	POS: devuelve un Diccionario<int> a partir de NodoListaS. 
	*/
	FRAMEWORKA1DLL_API ColaPrioridad<int, int>* ConvertirAColaPrioridad(NodoListaS *e, NodoListaS *p);



	///*
	//PRE: 
	//POS: devuelve un ptr a NodoListaS a partir de una ListaOrd<int>. 
	//	 Los elementos quedan ordenados
	//*/
	//FRAMEWORKA1DLL_API NodoListaS* ConvertirANodoLista(ListaOrd<int> *ptr);

	///*
	//PRE: 
	//POS: devuelve un ptr a NodoListaS a partir de una ListaPos<int>. 
	//	 Los elementos quedan en las mismas posiciones
	//*/
	//FRAMEWORKA1DLL_API NodoListaS* ConvertirANodoLista(ListaPos<int> *ptr);

	///*
	//PRE: 
	//POS: devuelve un ptr a NodoListaS a partir de una Pila<int>. 
	//	 El ultimo elemento de la lista queda en el tope de la pila.
	//*/
	//FRAMEWORKA1DLL_API NodoListaS* ConvertirANodoLista(Pila<int> *ptr);

	///*
	//PRE: 
	//POS: devuelve un ptr a NodoListaS a partir de una Cola<int>. 
	//	 El primer elemento de la lista queda en el pricipio de la cola.
	//*/
	//FRAMEWORKA1DLL_API NodoListaS* ConvertirANodoLista(Cola<int> *ptr);

};

#endif