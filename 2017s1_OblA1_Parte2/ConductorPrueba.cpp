#include "ConductorPrueba.h"

ConductorPrueba::ConductorPrueba()
{
	nroPrueba = 0;
}

ConductorPrueba::~ConductorPrueba()
{
}

void ConductorPrueba::correrPrueba(bool paraParseo)
{
	ManejadorSalidaPrueba msp = getManejadorSalida();
	msp.crearDirectorio(getNombre());

	correrPruebaConcreta();
	
	//msp.setSalidaArchivo("Resultados Totales.txt");
	//ManejadorImpresionPrueba mip = getManejadorImpresion();
	//mip.imprimirTotalResultados(getEstadisticaGlobal(), paraParseo);
	msp.setSalidaPantalla();
}

void ConductorPrueba::ver(TipoRetorno retorno, TipoRetorno retornoEsperado, char* comentario)
{
	getManejadorImpresion().imprimirResultado(retorno,retornoEsperado,comentario, false);

	getEstadisticaGlobal().actualizarEstadisticas(retorno,retornoEsperado);
}

void ConductorPrueba::ver2(TipoRetorno retorno, TipoRetorno retornoEsperado, char* comentario)
{
	cout << endl << "-!-" << this->nroPrueba++ << "::";
	getManejadorImpresion().imprimirResultado(retorno, retornoEsperado, comentario, true);

	getEstadisticaGlobal().actualizarEstadisticas(retorno,retornoEsperado);
}

void ConductorPrueba::ver3(char* comentario)
{
	cout << endl << "-!-" << this->nroPrueba++ << "::" << 0 << "-";
	getManejadorImpresion().imprimirResultado(comentario, true);
}

void ConductorPrueba::ver3(char* comentario, double puntaje)
{
	cout << endl << "-!-" << this->nroPrueba++ << "::" << puntaje << "-";
	getManejadorImpresion().imprimirResultado(comentario, true);
}

void ConductorPrueba::comenzarNuevaPrueba()
{
	nroPrueba = 0;
}

EstadisticaPrueba& ConductorPrueba::getEstadisticaGlobal()
{
	return estadisticaGlobal;
}

ManejadorImpresionPrueba ConductorPrueba::getManejadorImpresion()
{
	return ManejadorImpresionPrueba::getInstancia();
}

ManejadorSalidaPrueba ConductorPrueba::getManejadorSalida()
{
	return ManejadorSalidaPrueba::getInstancia();
}