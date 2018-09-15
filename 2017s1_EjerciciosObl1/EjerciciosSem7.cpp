#include "EjerciciosSem7.h"

#ifndef EJERCICIOSSEM7_CPP
#define EJERCICIOSSEM7_CPP


int altura(NodoAB* raiz){
	if (esVacia(raiz))
		return 0;
	return 	1+ max(altura(raiz->izq), altura(raiz->der));
}

bool esVacia(NodoAB* r) {
	return r == NULL;
}

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else if (a < b) {
		return b;
	}
	else {
		return a;
	}
}

bool sonIguales(NodoAB* p, NodoAB* q) {
	if (esVacia(p) && esVacia(q))
	{
		return true;
	}
	else if (esVacia(p) && !esVacia(q)) {
		return false;
	}
	else if (!esVacia(p) && esVacia(q)) {
		return false;
	}
	if (p->dato != q->dato) {
		return false;
	}
	return sonIguales(p->izq, q->izq) && sonIguales(p->der, q->der);
}

bool existeCaminoConSuma(NodoAB* raiz, int sum) {
	bool ok = false;
	if (esVacia(raiz))
		return 0 == sum;
	else {
		int dif = sum - raiz->dato;
		if (dif == 0 && esHoja(raiz))
			return true;
		if (dif != 0 && esHoja(raiz))
			return false;
		if (raiz->izq != NULL)
			ok = existeCaminoConSuma(raiz->izq, dif);
		if(raiz->der !=NULL)
			ok = ok ||  existeCaminoConSuma(raiz->der, dif);
		return ok;
	}
}


bool esHoja(NodoAB* r) {
	return r->izq == NULL && r->der == NULL;
}

bool esArbolBalanceado(NodoAB *raiz) {
	if (esVacia(raiz))
		return true;
	int dif = altura(raiz->izq) - altura(raiz->der);
	return -1 <= dif  &&  dif <= 1 && esArbolBalanceado(raiz->izq) && esArbolBalanceado(raiz->der);
}

NodoLista* enNivel(NodoAB *a, int k) {
	NodoLista* iter = NULL;
	NodoLista* ret = NULL;
	if (esVacia(a))
		return ret;
	if (k == 1) {
		ret = new NodoLista(a->dato);
		return ret;
	}
	if (k > 1) {
		ret = enNivel(a->izq, k - 1);
		if (ret) {
			iter = ret;
			while (iter->sig)
				iter = iter->sig;
			iter->sig = enNivel(a->der, k - 1);
		}
		else {
			ret = enNivel(a->der, k - 1);
		}
		return ret;
	}
}

int cantNodosEntreNiveles(NodoAB* a, int desde, int hasta) {
	int retorno = 0;
	if (!esVacia(a) && desde <= hasta && hasta >= 1) {
		if (desde <= 1)
			retorno++;
		retorno = retorno + cantNodosEntreNiveles(a->izq, desde - 1, hasta - 1);
		retorno = retorno + cantNodosEntreNiveles(a->der, desde - 1, hasta - 1);
	}
	return retorno;
}

NodoLista* camino(NodoAB *arbol, int x) {
	NodoLista* ret = NULL;
	if(esVacia(arbol))
		return ret;
	ret = new NodoLista(arbol->dato);
	if (arbol->dato < x) {
		ret->sig = camino(arbol->der, x);
	}
	if (arbol->dato>x) {
		ret->sig = camino(arbol->izq, x);
	}
	return ret;
}

NodoAB* invertirHastak(NodoAB* a, int k){
	NodoAB* ret = NULL;
	if(esVacia(a) || k == 0)
		return ret;
	if (k>=1)
	{
		ret = new NodoAB(a->dato);
		ret->izq = invertirHastak(a->der, k - 1);
		ret->der = invertirHastak(a->izq, k - 1);
	}
	return ret;
}


void borrarNodoRaiz(NodoAB * & A) {
	if (!esVacia(A)) {
		NodoAB* aux = A;
		NodoAB* aux2 = NULL;
		bool insertado = false;
		if (esVacia(A->der)) {
			A = A->izq;
		}
		else if (esVacia(A->izq)) {
			A = A->der;
		}
		else {
			aux2 = A->izq;
			A = A->der;
			insertarSubABB(A, aux2);
		}
		delete aux;
	}
}

void insertarSubABB(NodoAB* &r1, NodoAB* r2) {
	if (esVacia(r1))
		r1 = r2;
	else {
		if (r1->dato > r2->dato)
			insertarSubABB(r1->izq, r2);
		else
			insertarSubABB(r1->der, r2);
	}
}

bool SumaABB(NodoAB* a, int n){
	if (!esVacia(a)) {
		NodoLista* lista = menoresNABB(a, n);
		NodoLista* auxSum1 = lista;
		NodoLista* auxSum2 = NULL;
		bool encontre = false;
		int largo = largoLista2(lista);
		if (largo > 1) {
			auxSum2 = lista->sig;
			for (int i = 1; i < largo; i++){
				for (int j = i+1; j <= largo; j++){
					if (auxSum1->dato + auxSum2->dato == n) {
						deleteLista(lista);
						return true;
					}
					auxSum2 = auxSum2->sig;
				}
				auxSum1 = auxSum1->sig;
				auxSum2 = auxSum1->sig;
			}
			deleteLista(lista);
		}
		return false;
	}
	return false;
}



NodoLista* menoresNABB(NodoAB* a , int n) {
	NodoLista* retorno = NULL;
	NodoLista* aux = NULL;
	if (!esVacia(a)) {
		if (a->dato >= n)
			retorno = menoresNABB(a->izq, n);
		else {
			retorno = new NodoLista(a->dato);
			retorno->sig = menoresNABB(a->izq, n);
			aux = retorno;
			while (aux->sig)
				aux = aux->sig;
			aux->sig = menoresNABB(a->der, n);
		}
	}
	return retorno;
}

void deleteLista(NodoLista* a) {
	if (a != NULL) {
		NodoLista* aux = a;
		a = a->sig;
		delete aux;
		deleteLista(a);
	}
}

int Sucesor(NodoAB* a, int n)
{
	if (!esVacia(a)) {
		if (a->dato <= n)
			return Sucesor(a->der, n);
		return minSucesor(a->dato, Sucesor(a->izq, n));
	}
	return -1;
}

int minSucesor(int a, int b) {
	if (b == -1 || a < b)
		return a;
	return b;
}


int nivelMasNodos(NodoAB* raiz, int nivelHasta) {
	if (!esVacia(raiz)) {
		int nivelMayor = 1;
		int cantidadMayor = 1;
		int cantidad;
		for (int i = 1; i <= nivelHasta; i++) {
			cantidad = cantNodosNivel(raiz, i);
			if (cantidadMayor < cantidad) {
				nivelMayor = i;
				cantidadMayor = cantidad;
			}
		}
		return nivelMayor;
	}
	return 0;
	return 0;
}

int cantNodosNivel(NodoAB* raiz, int nivel) {
	if (!esVacia(raiz)) {
		if (nivel == 1)
			return 1;
		return cantNodosNivel(raiz->der, nivel - 1) + cantNodosNivel(raiz->izq, nivel - 1);
	}
	return 0;
}

void borrarPares(NodoAB* & a){
	if (!esVacia(a) && a->dato % 2 == 0) {
		borrarNodoRaiz(a);
		borrarPares(a);
	}
	if (!esVacia(a)) {
		borrarPares(a->izq);
		borrarPares(a->der);
	}
}

int alturaAG(NodoAG* raiz)
{
	if (!esVacio(raiz)) {
		return max(1 + alturaAG(raiz->ph), alturaAG(raiz->sh));
	}
	return 0;
}

bool esVacio(NodoAG* raiz) {
	return raiz == NULL;
}

int SumaPorNiveles(NodoAG* raiz){
	if (!esVacio(raiz)) {
		return -1 * raiz->dato + -1 * SumaPorNiveles(raiz->ph) + SumaPorNiveles(raiz->sh);
	}
	return 0;
}

bool EsPrefijo(NodoAG *a, NodoLista *l) {
	if (l != NULL) {
		if (!esVacio(a)) {
			if (a->dato == l->dato)
				return EsPrefijo(a->ph, l->sig) || EsPrefijo(a->sh, l);
			else
				return EsPrefijo(a->sh, l);
		}
		return false;
	}
	return true;
}

NodoLista* CaminoAG(NodoAG *arbolGeneral, int dato) {
	NodoLista* retorno = NULL;
	NodoLista* listaSH = NULL;
	NodoLista* listaPH = NULL;
	if (!esVacio(arbolGeneral)) {
		listaSH = CaminoAG(arbolGeneral->sh, dato);
		listaPH = CaminoAG(arbolGeneral->ph, dato);
		if (arbolGeneral->dato == dato) {
			retorno = new NodoLista(dato);
			listaSH = NULL;
			listaPH = NULL;
		}
		if (listaSH != NULL && listaPH == NULL) {
			retorno = listaSH;
		}
		else if (listaPH != NULL && listaSH == NULL) {
			insertarPrincipio2(listaPH, arbolGeneral->dato);
			retorno = listaPH;
		}
		else if (listaPH != NULL && listaSH != NULL) {
			if (largoLista2(listaPH) > largoLista2(listaSH)) {
				retorno = listaSH;
			}
			else {
				insertarPrincipio2(listaPH, arbolGeneral->dato);
				retorno = listaPH;
			}
		}
	}
	return retorno;
}

void insertarPrincipio2(NodoLista* &l, int valor) {
	NodoLista* nuevo = new NodoLista(valor);
	nuevo->sig = l;
	l = nuevo;
}

int largoLista2(NodoLista* l) {
	int largo = 0;
	while (l) {
		l = l->sig;
		largo++;
	}
	return largo;
}



int NivelConMasNodosAG(NodoAG * arbolGeneral) {
	int altura = alturaAG(arbolGeneral);
	int* vector = new int[altura + 1];
	for (int i = 0; i < altura + 1; i++) {
		vector[i] = 0;
	}
	cargarVector(vector, arbolGeneral, 1);
	int posMax = pMax(vector, altura);
	delete[] vector;
	return posMax;

}

void cargarVector(int* vector, NodoAG* arbolGeneral, int nivel) {
	if (!arbolGeneral)
		return;
	vector[nivel]++;
	cargarVector(vector, arbolGeneral->ph, nivel + 1);
	cargarVector(vector, arbolGeneral->sh, nivel);
}

int pMax(int* vector, int altura) {
	int max = 0;
	int pos = 0;
	for (int i = 0; i <= altura; i++) {
		if (vector[i] > max) {
			max = vector[i];
			pos = i;
		}
	}
	return pos;
}
#endif