#include "ConductorPruebaObl2.h"

ConductorPruebaObl2::ConductorPruebaObl2()
{
	// Empezar aqui a instanciar los archivos de prueba

	pruebasEjemploDeUsoEntrega1 = new PruebasEjemploDeUsoEntrega1(this);

	pruebasEjemploDeUsoEntrega2 = new PruebasEjemploDeUsoEntrega2(this);

	pruebasPropias = new PruebasPropias(this);

	pruebasCorreccion = new PruebasCorreccion(this);

	/* Ej:
	
	miPrueba = new MiPrueba(this);

	Recordar que el constructor de la prueba recibe el Conductor

	*/

	// Terminar aqui
}

ConductorPruebaObl2::~ConductorPruebaObl2()
{
	// Empezar aqui a borrar los archivos de prueba

	delete pruebasEjemploDeUsoEntrega1;

	delete pruebasEjemploDeUsoEntrega2;

	delete pruebasPropias;

	delete pruebasCorreccion;

	/* Ej:
	
	delete miPrueba;

	*/

	// Terminar aqui
}

void ConductorPruebaObl2::correrPruebaConcreta()
{
	// Empezar aqui a llamar los metodos de prueba

	pruebasEjemploDeUsoEntrega1->correrPrueba(true);

	pruebasEjemploDeUsoEntrega2->correrPrueba(true);

	pruebasPropias->correrPrueba();

	pruebasCorreccion->correrPrueba(true);

	/* Ej:
	
	miPrueba->correrPrueba();

	*/

	// Terminar aqui
}

char* ConductorPruebaObl2::getNombre()const
{
	return "SalidaDeLasPruebas";
}
