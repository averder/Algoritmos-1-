#ifndef PRUEBASCORRECCION_H
#define PRUEBASCORRECCION_H

#include "Prueba.h"
#include "ConductorPrueba.h"
#include "Cadena.h"
#include "PilaImp.h"

class PruebasCorreccion : public Prueba  
{

public:
	PruebasCorreccion(ConductorPrueba* conductor);
	virtual ~PruebasCorreccion();
	virtual void correrPruebaConcreta();

	void pruebaPila();
protected:
	virtual char* getNombre()const;

private:
	ManejadorImpresionPrueba mImpresion;

};

#endif