#include "PruebasPropias.h"

PruebasPropias::PruebasPropias(ConductorPrueba* conductor)
:Prueba(conductor)
{
}

PruebasPropias::~PruebasPropias()
{
}

char* PruebasPropias::getNombre()const
{
	return "PruebasPropias";
}

void PruebasPropias::correrPruebaConcreta()
{
	

}
