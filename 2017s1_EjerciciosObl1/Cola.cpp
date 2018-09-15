#include "Cola.h"

struct colaArray
{
	void ** elementos;
	int fondo;
	int capacidad;
};

Cola crearCola(int t)
{
	Cola c = new colaArray;
	c->elementos = new void*[t];
	c->capacidad = t;
	c->fondo = -1;

	return c;
}

void destruir(Cola &c)
{
	delete [] c->elementos;
	delete c;
	c = NULL;
}

void vaciar(Cola c)
{
	assert(c!=NULL);
	c->fondo = -1;
}

bool esVacia(Cola c)
{
	assert(c!=NULL);
	return c->fondo==-1;
}

bool estaLlena(Cola c)
{
	assert(c!=NULL);
	return c->fondo == c->capacidad-1;
}

void *frente(Cola c)
{
	assert(c!=NULL);
	assert(!esVacia(c));
	return c->elementos[0];
}

void desencolar(Cola c)
{
	assert(c!=NULL);
	assert(!esVacia(c));
	for(int i=0; i<c->fondo; i++)
		c->elementos[i] = c->elementos[i+1];
	c->fondo--;
}

void encolar(Cola c, void * dato)
{
	assert(c!=NULL);
	assert(!estaLlena(c));
	c->elementos[++(c->fondo)] = dato;
}


