#ifndef PRUEBASEJEMPLODEUSOENTREGA2_H
#define PRUEBASEJEMPLODEUSOENTREGA2_H

#include "Prueba.h"
#include "ConductorPrueba.h"
#include "PruebasAuxEntrega1.h"
#include "PruebasAuxEntrega2.h"
#include "PruebasAuxDefensa.h"
#include "Cadena.h"
#include "MultiSetImp.h"
#include "ListaOrdImp.h"
#include "ListaOrdImp2.h"
#include "ListaPosImp.h"
#include "TablaImp.h"

class PruebasEjemploDeUsoEntrega2 : public Prueba  
{

public:
	PruebasEjemploDeUsoEntrega2(ConductorPrueba* conductor);
	virtual ~PruebasEjemploDeUsoEntrega2();
	virtual void correrPruebaConcreta();

protected:
	virtual char* getNombre()const;

private:
	ManejadorImpresionPrueba mImpresion;

};

#endif