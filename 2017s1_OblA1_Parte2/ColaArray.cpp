#include "ColaArray.h"

struct colaArray
{
	void ** elementos;
	int fondo;
	int capacidad;
};

ColaArray crearColaArray(int t)
{
	ColaArray c = new colaArray;
	c->elementos = new void*[t];
	c->capacidad = t;
	c->fondo = -1;

	return c;
}

void destruir(ColaArray &c)
{
	delete [] c->elementos;
	delete c;
	c = NULL;
}

void vaciar(ColaArray c)
{
	assert(c!=NULL);
	c->fondo = -1;
}

bool esVacia(ColaArray c)
{
	assert(c!=NULL);
	return c->fondo==-1;
}

bool estaLlena(ColaArray c)
{
	assert(c!=NULL);
	return c->fondo == c->capacidad-1;
}

void *frente(ColaArray c)
{
	assert(c!=NULL);
	assert(!esVacia(c));
	return c->elementos[0];
}

void desencolar(ColaArray c)
{
	assert(c!=NULL);
	assert(!esVacia(c));
	for(int i=0; i<c->fondo; i++)
		c->elementos[i] = c->elementos[i+1];
	c->fondo--;
}

void encolar(ColaArray c, void * dato)
{
	assert(c!=NULL);
	assert(!estaLlena(c));
	c->elementos[++(c->fondo)] = dato;
}


