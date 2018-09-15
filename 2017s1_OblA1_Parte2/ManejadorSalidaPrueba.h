#ifndef MANEJADORSALIDAPRUEBA_H
#define MANEJADORSALIDAPRUEBA_H

#include <iostream>
#include <fstream>
#include <streambuf>
#include <direct.h>
using namespace std;

class ManejadorSalidaPrueba  
{
public:
	ManejadorSalidaPrueba(const ManejadorSalidaPrueba &m);
	
	void setSalidaArchivo(char* nombreArchivo);
	void setSalidaPantalla();

	static ManejadorSalidaPrueba getInstancia();

	void crearDirectorio(char* nombreDirectorio);
	void cambiarDirectorio(char* nombreDirectorio);

	virtual ~ManejadorSalidaPrueba();

protected:
	ManejadorSalidaPrueba();
	ManejadorSalidaPrueba& operator=(const ManejadorSalidaPrueba &manejador);

private:
	streambuf* pantalla;
	ofstream archivoActual;
};

#endif