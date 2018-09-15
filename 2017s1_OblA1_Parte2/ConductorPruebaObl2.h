#ifndef CONDUCTOR_PRUEBA_OBL2_H
#define CONDUCTOR_PRUEBA_OBL2_H

#include "ConductorPrueba.h"
#include "PruebasEjemploDeUsoEntrega1.h"
#include "PruebasEjemploDeUsoEntrega2.h"
#include "PruebasPropias.h"
#include "PruebasCorreccion.h"

class ConductorPruebaObl2 : public ConductorPrueba 
{
	public:
		ConductorPruebaObl2();
		virtual ~ConductorPruebaObl2();

	protected:
		virtual void correrPruebaConcreta();
		virtual char* getNombre()const;

private:
	// Empezar aqui a agregar los archivos de prueba

	Prueba* pruebasEjemploDeUsoEntrega1;
	Prueba* pruebasEjemploDeUsoEntrega2;
	
	Prueba* pruebasPropias;

	Prueba* pruebasCorreccion;

	/* Ej:
	
	Prueba* miPrueba;

	*/

	// Terminar aqui
};

#endif