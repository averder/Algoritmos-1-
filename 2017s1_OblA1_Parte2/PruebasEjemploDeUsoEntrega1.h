#ifndef PRUEBASEJEMPLODEUSOENTREGA1_H
#define PRUEBASEJEMPLODEUSOENTREGA1_H

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

class PruebasEjemploDeUsoEntrega1 : public Prueba  
{

public:
	PruebasEjemploDeUsoEntrega1(ConductorPrueba* conductor);
	virtual ~PruebasEjemploDeUsoEntrega1();
	virtual void correrPruebaConcreta();

protected:
	virtual char* getNombre()const;

private:
	ManejadorImpresionPrueba mImpresion;

	void PruebasEjerciciosTAD();
	void pruebaListaPos();
	void pruebaPila();
	void pruebaCola();

};

#endif