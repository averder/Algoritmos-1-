#ifndef PRUEBASPROPIAS_H
#define PRUEBASPROPIAS_H

#include "Prueba.h"
#include "ConductorPrueba.h"
#include "Cadena.h"
#include "ColaImp.h"
#include "ListaOrdImp.h"
#include "ListaPosImp.h"

class PruebasPropias : public Prueba  
{

public:
	PruebasPropias(ConductorPrueba* conductor);
	virtual ~PruebasPropias();
	virtual void correrPruebaConcreta();

protected:
	ManejadorImpresionPrueba mImpresion;
	virtual char* getNombre()const;

private:
	
};

#endif