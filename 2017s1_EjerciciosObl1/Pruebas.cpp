#include "Pruebas.h"

#ifndef PRUEBAS_CPP
#define PRUEBAS_CPP

void Pruebas() {
	ManejadorSalidaPrueba& manejadorSalidaPrueba = ManejadorSalidaPrueba::getInstancia();
	manejadorSalidaPrueba.crearDirectorio("SalidasDeLasPruebas");
	manejadorSalidaPrueba.setSalidaArchivo("PruebasPropias.txt");
	PruebasPropias();
	manejadorSalidaPrueba.setSalidaArchivo("PruebasDefensa.txt");
	PruebasDefensa();	
	manejadorSalidaPrueba.setSalidaArchivo("PruebasSem1.txt");
	PruebasSem1();
	manejadorSalidaPrueba.setSalidaArchivo("PruebasSem2.txt");
	PruebasSem2();
	manejadorSalidaPrueba.setSalidaArchivo("PruebasSem3.txt");
	PruebasSem3();
	manejadorSalidaPrueba.setSalidaArchivo("PruebasSem4.txt");
	PruebasSem4();
	manejadorSalidaPrueba.setSalidaArchivo("PruebasSem5.txt");
	PruebasSem5();
	manejadorSalidaPrueba.setSalidaArchivo("PruebasSem6.txt");
	PruebasSem6();
	manejadorSalidaPrueba.setSalidaArchivo("PruebasSem7.txt");
	PruebasSem7();
	manejadorSalidaPrueba.setSalidaArchivo("PruebasSem8.txt");
	PruebasSem8();
	manejadorSalidaPrueba.setSalidaArchivo("PruebasSem9.txt");
	PruebasSem9();
	manejadorSalidaPrueba.setSalidaPantalla();
}

#endif