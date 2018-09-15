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
	void setSalidaArchivo(char* nombreArchivo);
	void setSalidaPantalla();

	static ManejadorSalidaPrueba getInstancia();

	void crearDirectorio(char* nombreDirectorio);
	void cambiarDirectorio(char* nombreDirectorio);

	ManejadorSalidaPrueba(const ManejadorSalidaPrueba &m);
	virtual ~ManejadorSalidaPrueba();

protected:
	ManejadorSalidaPrueba();

private:
	streambuf* pantalla;
	ofstream archivoActual;
};

#endif