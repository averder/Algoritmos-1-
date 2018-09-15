#include "PruebasAuxSem5.h"

#ifndef PRUEBASAUXSEM5_CPP
#define PRUEBASAUXSEM5_CPP

bool PruebaEliminarNesimoDesdeElFinal(char* inputLista, int n, char* output, int &nroPrueba){
	// PRUEBA ELIMINAR N-ESIMO DEL FINAL
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba Eliminar n-esimo desde el final " << nroPrueba++;
	int largo;
	
	std::ostringstream s;
	s << inputLista << ", " << n;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());


	NodoLista* lista = (NodoLista*)FrameworkA1::parsearColeccion(inputLista, largo);
	eliminarNesimoDesdeElFinal(lista, n);
	largo=0;
	NodoLista* solucion = (NodoLista*)FrameworkA1::parsearColeccion(output, largo);
	
	bool resultadoOK = FrameworkA1::sonIgualesDatosForma(lista, solucion);
	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		char* resultado = FrameworkA1::serializar(lista);
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultado, inputParametersFormated);
		delete[] resultado;
	}else {
		cout << " -> OK" << endl;
	}
	
	delete [] inputParametersFormated;
	FrameworkA1::destruir(lista);
	FrameworkA1::destruir(solucion);
	return resultadoOK;
}

bool PruebaListaOrdenadaInsertionSort(char* inputLista, char* output, int &nroPrueba) {
	cout << "----------------------------------------------" << endl;
	cout << "Prueba Lista Ordenada Insertion Sort " << nroPrueba++;
	int largo;

	std::ostringstream s;
	s << inputLista;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());


	NodoLista* lista = (NodoLista*)FrameworkA1::parsearColeccion(inputLista, largo);
	NodoLista* copiaLista = (NodoLista*)FrameworkA1::parsearColeccion(inputLista, largo);
	NodoLista* resultado = listaOrdenadaInsertionSort(lista);
	largo = 0;
	NodoLista* solucion = (NodoLista*)FrameworkA1::parsearColeccion(output, largo);

	bool resultadoOK = FrameworkA1::sonIgualesDatosForma(resultado, solucion);
	bool parametrosModificados = !FrameworkA1::sonIgualesDatosForma(lista, copiaLista);
	bool compartenMem = FrameworkA1::compartenMemoria(resultado, lista);

	char* resultadoImprimir = FrameworkA1::serializar(resultado);

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultadoImprimir, inputParametersFormated);
	}
	else if (compartenMem) {
		cout << " -> ERROR lista devuelta comparte memoria con parametro" << endl;
		resultadoOK = false;
	}
	else if (parametrosModificados) {
		cout << " -> ERROR se modificaron los parametros" << endl;
		resultadoOK = false;
	}
	else {
		cout << " -> OK" << endl;
	}

	delete [] inputParametersFormated;
	FrameworkA1::destruir(lista);
	FrameworkA1::destruir(copiaLista);
	FrameworkA1::destruir(solucion);
	FrameworkA1::destruir(resultado);
	delete[]resultadoImprimir;
	return resultadoOK;
}

bool PruebaListaOrdenadaSelectionSort(char* inputLista, char* output, int &nroPrueba) {
	cout << "----------------------------------------------" << endl;
	cout << "Prueba Lista Ordenada Selection Sort " << nroPrueba++;
	int largo;

	std::ostringstream s;
	s << inputLista;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());


	NodoLista* lista = (NodoLista*)FrameworkA1::parsearColeccion(inputLista, largo);
	NodoLista* copiaLista = (NodoLista*)FrameworkA1::parsearColeccion(inputLista, largo);
	listaOrdenadaSelectionSort(lista);
	largo = 0;
	NodoLista* solucion = (NodoLista*)FrameworkA1::parsearColeccion(output, largo);

	bool resultadoOK = FrameworkA1::sonIgualesDatosForma(lista, solucion);

	char* resultadoImprimir = FrameworkA1::serializar(lista);

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultadoImprimir, inputParametersFormated);
	}
	else {
		cout << " -> OK" << endl;
	}

	delete [] inputParametersFormated;
	FrameworkA1::destruir(lista);
	FrameworkA1::destruir(copiaLista);
	FrameworkA1::destruir(solucion);
	delete[]resultadoImprimir;
	return resultadoOK;
}

bool PruebaInvertirParcial(char* inputLista, char* output, int &nroPrueba){
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba Invertir Parcial " << nroPrueba++;
	int largo;
	
	std::ostringstream s;
	s <<inputLista;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());


	NodoLista* lista = (NodoLista*)FrameworkA1::parsearColeccion(inputLista, largo);
	NodoLista* copiaLista = (NodoLista*)FrameworkA1::parsearColeccion(inputLista, largo);
	NodoLista* resultado = invertirParcial(lista);
	largo = 0;
	NodoLista* solucion = (NodoLista*)FrameworkA1::parsearColeccion(output, largo);
	
	bool resultadoOK = FrameworkA1::sonIgualesDatosForma(resultado, solucion);
	bool parametrosModificados = !FrameworkA1::sonIgualesDatosForma(lista, copiaLista);
	bool compartenMem = FrameworkA1::compartenMemoria(resultado, lista);

	char* resultadoImprimir = FrameworkA1::serializar(resultado);

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultadoImprimir, inputParametersFormated);
	} else if(compartenMem){
		cout << " -> ERROR lista devuelta comparte memoria con parametro" << endl;
		resultadoOK = false;
	} else if (parametrosModificados){
		cout << " -> ERROR se modificaron los parametros" << endl;
		resultadoOK = false;
	}else {
		cout << " -> OK" << endl;
	}
	
	delete [] inputParametersFormated;
	FrameworkA1::destruir(lista);
	FrameworkA1::destruir(copiaLista);
	FrameworkA1::destruir(solucion);
	FrameworkA1::destruir(resultado);
	delete[]resultadoImprimir;
	return resultadoOK;
}

bool PruebaIntercalarIter(char* inputLista1, char* inputLista2, char* output, int &nroPrueba){
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba intercalar dos listas " << nroPrueba++;

	std::ostringstream s;
	s << inputLista1 << ", " << inputLista2;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());


	int largoLista1;
	int largoLista2;
	NodoLista* lista1 = (NodoLista*)FrameworkA1::parsearColeccion(inputLista1, largoLista1);
	NodoLista* lista2 = (NodoLista*)FrameworkA1::parsearColeccion(inputLista2, largoLista2);
	largoLista1=0;
	largoLista2=0;
	NodoLista* copiaLista1 = (NodoLista*)FrameworkA1::parsearColeccion(inputLista1, largoLista1);
	NodoLista* copiaLista2 = (NodoLista*)FrameworkA1::parsearColeccion(inputLista2, largoLista2);

	NodoLista* resultado = intercalarIter(lista1, lista2);
	int largoSolucion;
	NodoLista* solucion = (NodoLista*)FrameworkA1::parsearColeccion(output, largoSolucion);

	bool parametrosModificados = !FrameworkA1::sonIgualesDatosForma(lista1, copiaLista1) || !FrameworkA1::sonIgualesDatosForma(lista2, copiaLista2);
	bool compartenMem = FrameworkA1::compartenMemoria(resultado, lista1) || FrameworkA1::compartenMemoria(resultado, lista2);
	bool resultadoOK = FrameworkA1::sonIgualesDatosForma(resultado, solucion);
	
	
	char* resultadoImprimir = FrameworkA1::serializar(resultado);

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultadoImprimir, inputParametersFormated);
	} else if(compartenMem) {
		cout << " -> ERROR lista devuelta comparte memoria con parametro" << endl;
		resultadoOK = false;
	} else if(parametrosModificados) {
		cout << " -> ERROR se modificaron los parametros" << endl;
		resultadoOK = false;
	} else {
		cout << " -> OK" << endl;
	}

	delete [] inputParametersFormated;
	FrameworkA1::destruir(lista1);
	FrameworkA1::destruir(lista2);
	FrameworkA1::destruir(copiaLista1);
	FrameworkA1::destruir(copiaLista2);
	FrameworkA1::destruir(solucion);
	FrameworkA1::destruir(resultado);
	delete[]resultadoImprimir;
	return resultadoOK;

}

bool PruebaIntercalarRec(char* inputLista1, char* inputLista2, char* output, int &nroPrueba){
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba intercalar dos listas " << nroPrueba++;

	std::ostringstream s;
	s << inputLista1 << ", " << inputLista2;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());


	int largoLista1;
	int largoLista2;
	NodoLista* lista1 = (NodoLista*)FrameworkA1::parsearColeccion(inputLista1, largoLista1);
	NodoLista* lista2 = (NodoLista*)FrameworkA1::parsearColeccion(inputLista2, largoLista2);
	largoLista1=0;
	largoLista2=0;
	NodoLista* copiaLista1 = (NodoLista*)FrameworkA1::parsearColeccion(inputLista1, largoLista1);
	NodoLista* copiaLista2 = (NodoLista*)FrameworkA1::parsearColeccion(inputLista2, largoLista2);

	NodoLista* resultado = intercalarRec(lista1, lista2);
	int largoSolucion;
	NodoLista* solucion = (NodoLista*)FrameworkA1::parsearColeccion(output, largoSolucion);

	bool parametrosModificados = !FrameworkA1::sonIgualesDatosForma(lista1, copiaLista1) || !FrameworkA1::sonIgualesDatosForma(lista2, copiaLista2);
	bool compartenMem = FrameworkA1::compartenMemoria(resultado, lista1) || FrameworkA1::compartenMemoria(resultado, lista2);
	bool resultadoOK = FrameworkA1::sonIgualesDatosForma(resultado, solucion);
	
	
	char* resultadoImprimir = FrameworkA1::serializar(resultado);

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultadoImprimir, inputParametersFormated);
	} else if(compartenMem) {
		cout << " -> ERROR lista devuelta comparte memoria con parametro" << endl;
		resultadoOK = false;
	} else if(parametrosModificados) {
		cout << " -> ERROR se modificaron los parametros" << endl;
		resultadoOK = false;
	} else {
		cout << " -> OK" << endl;
	}

	delete [] inputParametersFormated;
	FrameworkA1::destruir(lista1);
	FrameworkA1::destruir(lista2);
	FrameworkA1::destruir(copiaLista1);
	FrameworkA1::destruir(copiaLista2);
	FrameworkA1::destruir(solucion);
	FrameworkA1::destruir(resultado);
	delete[]resultadoImprimir;
	return resultadoOK;

}

bool PruebaInsComFin(char* inputLista, int n, char* output, int &nroPrueba){
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba Insertar Comienzo y Fin " << nroPrueba++;

	std::ostringstream s;
	s << inputLista << ", " << n;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());


	int largo;
	NodoLista* lista = (NodoLista*)FrameworkA1::parsearColeccion(inputLista, largo);
	largo=0;
	NodoLista* copiaLista = (NodoLista*)FrameworkA1::parsearColeccion(inputLista, largo);
	NodoLista* resultado = insComFin(lista, n);
	largo=0;
	NodoLista* solucion = (NodoLista*)FrameworkA1::parsearColeccion(output, largo);

	bool parametrosModificados = !FrameworkA1::sonIgualesDatosForma(lista, copiaLista);
	bool compartenMem = FrameworkA1::compartenMemoria(resultado, lista);
	bool resultadoOK = FrameworkA1::sonIgualesDatosForma(resultado, solucion);
	
	
	char* resultadoImprimir = FrameworkA1::serializar(resultado);

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultadoImprimir, inputParametersFormated);
	} else if(compartenMem) {
		cout << " -> ERROR lista devuelta comparte memoria con parametro" << endl;
		resultadoOK = false;
	} else if(parametrosModificados) {
		cout << " -> ERROR se modificaron los parametros" << endl;
		resultadoOK = false;
	} else {
		cout << " -> OK" << endl;
	}

	delete [] inputParametersFormated;
	FrameworkA1::destruir(lista);
	FrameworkA1::destruir(copiaLista);
	FrameworkA1::destruir(solucion);
	FrameworkA1::destruir(resultado);
	delete[]resultadoImprimir;
	return resultadoOK;
}

bool PruebaEXOR(char* inputLista1, char* inputLista2, char* output, int &nroPrueba){
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba EXOR " << nroPrueba++;

	std::ostringstream s;
	s << inputLista1 << ", " << inputLista2;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());


	int largoLista1;
	int largoLista2;
	NodoLista* lista1 = (NodoLista*)FrameworkA1::parsearColeccion(inputLista1, largoLista1);
	NodoLista* lista2 = (NodoLista*)FrameworkA1::parsearColeccion(inputLista2, largoLista2);
	largoLista1=0;
	largoLista2=0;
	NodoLista* copiaLista1 = (NodoLista*)FrameworkA1::parsearColeccion(inputLista1, largoLista1);
	NodoLista* copiaLista2 = (NodoLista*)FrameworkA1::parsearColeccion(inputLista2, largoLista2);

	NodoLista* resultado = exor(lista1, lista2);
	int largoSolucion;
	NodoLista* solucion = (NodoLista*)FrameworkA1::parsearColeccion(output, largoSolucion);

	bool parametrosModificados = !FrameworkA1::sonIgualesDatosForma(lista1, copiaLista1) || !FrameworkA1::sonIgualesDatosForma(lista2, copiaLista2);
	bool compartenMem = FrameworkA1::compartenMemoria(resultado, lista1) || FrameworkA1::compartenMemoria(resultado, lista2);
	bool resultadoOK = FrameworkA1::sonIgualesDatosForma(resultado, solucion);
	
	
	char* resultadoImprimir = FrameworkA1::serializar(resultado);

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultadoImprimir, inputParametersFormated);
	} else if(compartenMem) {
		cout << " -> ERROR lista devuelta comparte memoria con parametro" << endl;
		resultadoOK = false;
	} else if(parametrosModificados) {
		cout << " -> ERROR se modificaron los parametros" << endl;
		resultadoOK = false;
	} else {
		cout << " -> OK" << endl;
	}
	
	delete [] inputParametersFormated;
	FrameworkA1::destruir(lista1);
	FrameworkA1::destruir(lista2);
	FrameworkA1::destruir(copiaLista1);
	FrameworkA1::destruir(copiaLista2);
	FrameworkA1::destruir(solucion);
	FrameworkA1::destruir(resultado);
	delete[]resultadoImprimir;
	return resultadoOK;
}

bool PruebaEliminarDuplicadosListaOrdenadaDos(char* inputLista, char* output, int &nroPrueba){
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba Eliminar Duplicados Lista Ordenados 2 " << nroPrueba++;
	
	std::ostringstream s;
	s << inputLista;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());

	int largo;
	NodoLista* lista = (NodoLista*)FrameworkA1::parsearColeccion(inputLista, largo);
	eliminarDuplicadosListaOrdenadaDos(lista);
	largo=0;
	NodoLista* solucion = (NodoLista*)FrameworkA1::parsearColeccion(output, largo);

	bool resultadoOK = FrameworkA1::sonIgualesDatosForma(lista, solucion);
	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		char* resultado = FrameworkA1::serializar(lista);
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultado, inputParametersFormated);
		delete[] resultado;
	}else {
		cout << " -> OK" << endl;
	}
	
	delete [] inputParametersFormated;
	FrameworkA1::destruir(lista);
	FrameworkA1::destruir(solucion);
	return resultadoOK;
}


bool PruebaPalindromo(char* inputLista, bool output, int &nroPrueba)
{
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba palindromo de listas " << nroPrueba++;

	std::ostringstream s;
	s << inputLista;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());

	int largo;
	NodoLista * lista = (NodoLista*)FrameworkA1::parsearColeccion(inputLista, largo);
	NodoLista * copiaLista = (NodoLista*)FrameworkA1::parsearColeccion(inputLista, largo);

	bool resultado = palindromo(lista);

	bool resultadoOK = output == resultado;
	bool parametrosModificados = !FrameworkA1::sonIgualesDatosForma(lista, copiaLista);

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultado, inputParametersFormated);
	} else if(parametrosModificados) {
		cout << " -> ERROR se modificaron los parametros" << endl;
		resultadoOK = false;
	}else {
		cout << " -> OK" << endl;
	}

	delete [] inputParametersFormated;
	FrameworkA1::destruir(lista);
	return resultadoOK;
}

bool PruebaEliminarSecuencia(char* inputListaOriginal, char* inputSecuenciaAEliminar, char* output, int &nroPrueba)
{
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba eliminar secuencia de listas " << nroPrueba++;

	std::ostringstream s;
	s << inputListaOriginal << ", " << inputSecuenciaAEliminar;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());
	
	int largo;
	NodoLista* listaOriginal = (NodoLista*)FrameworkA1::parsearColeccion(inputListaOriginal, largo);
	NodoLista* secuenciaAEliminar = (NodoLista*)FrameworkA1::parsearColeccion(inputSecuenciaAEliminar, largo);
	NodoLista* copiaSecuenciaAEliminar = (NodoLista*)FrameworkA1::parsearColeccion(inputSecuenciaAEliminar, largo);
	NodoLista* listaEsperada = (NodoLista*)FrameworkA1::parsearColeccion(output, largo);

	eliminarSecuencia(listaOriginal, secuenciaAEliminar);

	bool resultadoOK = FrameworkA1::sonIgualesDatosForma(listaOriginal,listaEsperada);
	bool parametrosModificados = !FrameworkA1::sonIgualesDatosForma(secuenciaAEliminar, copiaSecuenciaAEliminar);

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(listaEsperada, listaOriginal, inputParametersFormated);
	} else if(parametrosModificados) {
		cout << " -> ERROR se modifico la secuencia" << endl;
		resultadoOK = false;
	}else {
		cout << " -> OK" << endl;
	}

	delete [] inputParametersFormated;
	FrameworkA1::destruir(listaOriginal);
	FrameworkA1::destruir(secuenciaAEliminar);
	FrameworkA1::destruir(listaEsperada);
	return resultadoOK;

}

bool PruebaMoverNodo(char* inputListaOriginal, unsigned int inicial, unsigned int final, char* output, int &nroPrueba)
{
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba mover nodo de listas " << nroPrueba++;

	std::ostringstream s;
	s << inputListaOriginal << ", " << inicial << ", " << final;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());

	int largo;
	NodoLista* listaOriginal = (NodoLista*)FrameworkA1::parsearColeccion(inputListaOriginal, largo);
	NodoLista* listaEsperada = (NodoLista*)FrameworkA1::parsearColeccion(output, largo);

	moverNodo(listaOriginal,inicial, final);

	bool resultadoOK = FrameworkA1::sonIgualesDatosForma(listaOriginal,listaEsperada);

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(listaEsperada, listaOriginal, inputParametersFormated);
	}else {
		cout << " -> OK" << endl;
	}

	delete [] inputParametersFormated;
	FrameworkA1::destruir(listaOriginal);
	FrameworkA1::destruir(listaEsperada);
	return resultadoOK;

	
}

#endif