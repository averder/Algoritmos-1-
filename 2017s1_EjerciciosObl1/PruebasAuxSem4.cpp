#include "PruebasAuxSem4.h"

#ifndef PRUEBASAUXSEM4_CPP
#define PRUEBASAUXSEM4_CPP


bool PruebaOrdenarVecIntMergeSort(char* vecStr, char* output, int &nroPrueba) {
	cout << "----------------------------------------------" << endl;
	cout << "Prueba ordenar vector de int Mergesort " << nroPrueba++;

	std::ostringstream s;
	s << vecStr;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());


	int largoResultado;
	int *listaPalabras = (int *)FrameworkA1::parsearColeccion(vecStr, largoResultado);
	int largoSolucion;
	int *solucion = (int *)FrameworkA1::parsearColeccion(output, largoSolucion);

	OrdenarVecIntMergeSort(listaPalabras,largoResultado);

	bool resultadoOK = FrameworkA1::sonIguales(listaPalabras, solucion, largoSolucion);

	char* resultadoImprimir = FrameworkA1::serializar(listaPalabras, largoResultado);

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultadoImprimir, inputParametersFormated);
	}
	else {
		cout << " -> OK" << endl;
	}

	delete [] inputParametersFormated;
	FrameworkA1::destruir(listaPalabras);
	FrameworkA1::destruir(solucion);
	delete[]resultadoImprimir;
	return resultadoOK;
}

#endif